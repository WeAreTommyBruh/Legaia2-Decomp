#!/usr/bin/env python3
"""Keeps Ghidra's decompilation of the functions where it already compiles
to the original bytes.

Every unmatched function in decomp/src/ is compiled with ee-gcc
2.9-ee-991111-01 -O2 -G8, as Ghidra wrote it and with Ghidra's 64-bit
`long`/`ulong` turned into `int`/`uint` (Ghidra shows register-sized values
as long), after these adjustments:
  - globals named by address become D_XXXXXXXX symbols: gp-relative ones
    (iGpffff9db0, typed by the prefix) as variables, absolute ones (DAT_,
    PTR_, s_) as arrays so that they are addressed absolutely; DAT_ types are
    unknown, so likely ones are tried
  - Ghidra's spelled-out division checks (`trap(7)`) are dropped, since the
    compiler adds them itself; float constants get their `f`
  - called functions get Ghidra's prototypes, fitted to the number of
    arguments the body passes, and int instead of void when a result is used
  - float constants the compiler would place in its own .lit4/.rodata are
    replaced by the original copies (checked against the original data)
  - when that does not match: numbers that are addresses become references
    to the address, unsigned bytes/shorts signed, untyped 4-byte parameters
    float, if/else branches swapped (see rewrite())
  - functions that make calls are also tried with -fexceptions (the game's
    C++ files were built with it: no tail calls); matches go to *_eh.c
    files with a `// cflags: -fexceptions` line
  - what does not match with ee-gcc 2.9-ee-991111-01 is tried again with
    ee-gcc 2.9-ee-990721, which built some of the game's files; such matches
    go to *_990721.c files with a `// compiler: 990721` line
  - a stack frame smaller than the original's gets an unused local array
    (Ghidra does not show unused locals, which still take stack space)
Exact matches (relocations resolved to the real addresses) are written,
marked `// MATCH func_XXXXXXXX`, to src/ghidra/<source group>.c, split into
more files when declarations clash. The code is Ghidra's, meant to be
cleaned up by hand; the files are regenerated from scratch each run (after
tools/gen_tiny.py).

Results are cached in build/gen_ghidra_cache.json, keyed by each function's
Ghidra text and a hash of the tools, headers, function list, executable and
compiler; a rerun only compiles functions whose inputs changed.

Usage: gen_ghidra.py [MAX_SIZE]        (default 1024 bytes)
       gen_ghidra.py --from-cache     (only rewrite src/ghidra from the cache, leaving
                                       out functions now matched elsewhere in src/)
"""

import concurrent.futures
import itertools
import csv
import glob
import os
import re
import struct
import subprocess
import sys
import tempfile

import asm_build
from match import compare, sections

ROOT = asm_build.ROOT
OUTDIR = os.path.join(ROOT, "src", "ghidra")
GP = 0x4A7C70
GP_TYPES = {"i": "int", "u": "uint", "f": "float", "c": "char", "b": "byte", "s": "short",
            "us": "ushort", "uc": "byte", "l": "long", "ul": "ulong", "pu": "uint *",
            "pi": "int *", "pc": "char *", "pv": "void *", "pf": "float *", "pb": "byte *",
            "ps": "short *", "pus": "ushort *", "puc": "byte *", "pp": "void **"}
DAT_TYPES = ("int", "uint", "byte", "char", "short", "ushort", "float")
UNSUPPORTED = re.compile(r"\b(_DAT_\w+|_PTR_\w+|in_\w+|unaff_\w+|extraout_\w+|"
                         r"CONCAT\d+|SUB\d+|ZEXT\d+|SEXT\d+|_[a-z]+c2\w*|_v\w+|halt_baddata|"
                         r"\w+\._\d+_\d+_|switchD_\w+|joined_r0x\w+|caseD_\w+|REG_\w+|gp0x\w+|"
                         r"[a-z]+Ram[0-9a-f]{8})\b")
# globals Ghidra names by address: DAT_ (type unknown), PTR_ (a pointer), s_ (a string)
ADDR_NAME = re.compile(r"\b(DAT|PTR_\w+?|s_\w*?)_([0-9a-f]{8})\b")
TRAP = re.compile(r"\n[ \t]*if \([^\n]*\) \{\s*\n[ \t]*trap\(\w+\);\s*\n[ \t]*\}|"
                  r"\n[ \t]*if \([^\n]*\) trap\(\w+\);|\n[ \t]*trap\(\w+\);")


def prototypes():
    out = {}
    for line in open(os.path.join(ROOT, "decomp", "legaia2.h")):
        m = re.match(r"^([\w\s\*]+?)\b(\w+)\((.*)\);$", line.strip())
        if m and "typedef" not in line:
            out[m.group(2)] = line.strip()
    return out


def body_of(path):
    s = open(path).read()
    i = s.find("*/", s.find("Source:", s.find("*/") + 2))
    s = s[i + 2:] if i >= 0 else s
    return s[s.index("\n", s.index("#include") if "#include" in s else 0):].strip()


def split_args(text, start):
    """Arguments of the call whose '(' is at text[start]; None if unbalanced."""
    depth, args, cur = 0, [], ""
    for k in range(start, len(text)):
        ch = text[k]
        if ch == "(":
            depth += 1
            if depth == 1:
                continue
        elif ch == ")":
            depth -= 1
            if depth == 0:
                if cur.strip():
                    args.append(cur)
                return args
        elif ch == "," and depth == 1:
            args.append(cur)
            cur = ""
            continue
        cur += ch
    return None


def adapt_prototype(proto, callee, body, variant):
    """Ghidra's prototype of `callee`, fitted to how this body calls it:
    the number of arguments used (extra ones as int), and int instead of
    void when the result is used."""
    m = re.match(r"^(.*?)\b" + re.escape(callee) + r"\((.*)\);$", proto)
    ret, params = m.group(1).strip(), m.group(2).strip()
    params = [] if params in ("", "void") else [x.strip() for x in params.split(",")]
    counts, used = set(), False
    for c in re.finditer(r"\b" + re.escape(callee) + r"\s*\(", body):
        a = split_args(body, c.end() - 1)
        if a is None:
            return None
        counts.add(len(a))
        before = body[:c.start()].rstrip()
        if before.endswith(("return",)) or (before and before[-1] in "=(,!&|+-*/<>?:"):
            used = True
    if len(counts) > 1:
        return None
    if counts:
        n = counts.pop()
        params = params[:n] + ["int"] * (n - len(params))
    if (used or variant == "intret") and ret == "void":
        ret = "int"
    p = f"{ret} {callee}({', '.join(params) or 'void'});"
    if variant in ("int", "intret"):
        p = re.sub(r"\bulong\b", "uint", re.sub(r"\blong\b", "int", p))
    return p


def prepare(name, body, protos, variant, dat_types=()):
    """Returns (C text, extern declarations {symbol: type}, prototypes) or None.
    Globals named by address get `D_XXXXXXXX` symbols: gp-relative ones
    (iGpffff9db0) as plain variables typed by their prefix; absolute ones
    (DAT_, PTR_, s_) as arrays, so that the compiler addresses them
    absolutely as the original does, with a #define keeping Ghidra's name.
    DAT_ globals take the types in `dat_types`, in order of first use."""
    if UNSUPPORTED.search(body) or '"' in body:  # no text from the game in the source
        return None
    body = TRAP.sub("", body)  # Ghidra spells out the compiler's division checks
    # Ghidra prints float constants without the f, which in C makes them double
    body = FLOAT_TOKEN.sub(lambda m: m.group(1) + "f", body)
    externs = {}

    def gp(m):
        prefix, off = m.group(1), int(m.group(2), 16)
        t = GP_TYPES.get(prefix)
        if t is None:
            raise KeyError(prefix)
        sym = f"D_{(GP + off - (1 << 32)) & 0xFFFFFFFF:08X}"
        if externs.setdefault(sym, t) != t:
            raise KeyError(sym)
        return sym
    try:
        body = re.sub(r"\b([a-z]+)Gp([0-9a-f]{8})\b", gp, body)
    except KeyError:
        return None
    # names that quote a string (s_..., PTR_s_...) are replaced by the address
    # symbol outright, so no text from the game stays in the source
    def by_address(m):
        kind, addr = m.groups()
        sym = f"D_{addr.upper()}"
        if kind.startswith("s_"):
            if externs.setdefault(sym + "[]", "char") != "char":
                raise KeyError(sym)
            return sym
        if externs.setdefault(sym + "[]", "undefined *") != "undefined *":
            raise KeyError(sym)
        return f"({sym}[0])"
    try:
        body = re.sub(r"\b(s_\w*?|PTR_s_\w*?)_([0-9a-f]{8})\b", by_address, body)
    except KeyError:
        return None
    names = list(dict.fromkeys(m.group(0) for m in ADDR_NAME.finditer(body)))
    dats = [n for n in names if n.startswith("DAT_")]
    if len(dats) != len(dat_types):
        return None
    types = dict(zip(dats, dat_types))
    defines = []
    for n in names:
        kind, addr = ADDR_NAME.match(n).groups()
        sym = f"D_{addr.upper()}"
        if kind.startswith("s_"):
            t, d = "char", f"#define {n} {sym}"
        else:
            t = types[n] if kind == "DAT" else "undefined *"
            d = f"#define {n} ({sym}[0])"
        if externs.setdefault(sym + "[]", t) != t:
            return None
        defines.append(d)
    if variant in ("int", "intret"):
        body = re.sub(r"\bulong\b", "uint", re.sub(r"\blong\b", "int", body))
    if defines:
        body = ("\n".join(defines) + "\n" + body + "\n" +
                "\n".join(f"#undef {n}" for n in names))
    decls = []
    for c in sorted({c for c in re.findall(r"\b(\w+)\b", body) if c in protos and c != name}):
        p = adapt_prototype(protos[c], c, body, variant)
        if p is None:
            return None
        decls.append(p)
    return body, externs, decls


def dat_type_choices(body):
    """All types for up to two DAT_ globals; for three to six, int for all and
    then each one changed alone."""
    n = len(set(re.findall(r"\bDAT_[0-9a-f]{8}\b", body)))
    if n <= 2:
        return list(itertools.product(DAT_TYPES, repeat=n))
    if n > 6:
        return []
    out = [("int",) * n]
    for k in range(n):
        out += [tuple(t if j == k else "int" for j in range(n)) for t in DAT_TYPES[1:]]
    return out


FLOAT_TOKEN = re.compile(r"(?<![\w.])(-?\d+\.\d*(?:e[+-]?\d+)?)f?(?![\w.])")


def literal_addresses(obj, name, addr):
    """{float bits: original address} for the 4-byte constants the compiled
    function loads from its own .lit4/.rodata, found by reading where the
    original instruction at the same place loads from; None if any constant
    cannot be placed or the original data there differs."""
    d = open(obj, "rb").read()
    secs = sections(d)
    symtab = next(h for n, h in secs if h[1] == 2)
    strtab = secs[symtab[6]][1]
    syms = []
    for i in range(symtab[5] // 16):
        nm, val, size, info, other, shndx = struct.unpack_from("<IIIBBH", d, symtab[4] + 16 * i)
        syms.append((d[strtab[4] + nm:d.index(b"\0", strtab[4] + nm)].decode(), val, size, info, shndx))
    fn = next((x for x in syms if x[0] == name and x[3] & 0xF == 2), None)
    if fn is None:
        return None
    _, val, size, _, shndx = fn
    text = secs[shndx][1]
    orig = asm_build.Elf(open(asm_build.EXE, "rb").read())
    otext = orig.section(".text")

    def oword(off):
        return struct.unpack_from("<I", orig.data, otext["off"] + addr + off - val - otext["addr"])[0]

    def odata(a, n):
        for sec in orig.sections:
            if sec["type"] == 1 and sec["addr"] <= a < sec["addr"] + sec["size"]:
                return orig.data[sec["off"] + a - sec["addr"]:sec["off"] + a - sec["addr"] + n]
        return None
    relocs = []
    for n, h in secs:
        if h[1] == 9 and h[7] == shndx:
            for j in range(h[5] // 8):
                off, info = struct.unpack_from("<II", d, h[4] + 8 * j)
                if val <= off < val + size:
                    relocs.append((off, info & 0xFF, syms[info >> 8]))
    out = {}
    for k, (off, rtype, (sname, sval, _, sinfo, sshndx)) in enumerate(relocs):
        if sinfo & 0xF != 3 or secs[sshndx][0] not in asm_build.C_DATA:
            continue  # not a reference to the file's own data
        lit_sec = secs[sshndx][1]
        w = struct.unpack_from("<I", d, text[4] + off)[0]
        if rtype == 7:  # gp-relative
            lit_off = s16(w & 0xFFFF)
            target = (GP + s16(oword(off) & 0xFFFF)) & 0xFFFFFFFF
        elif rtype == 6:  # %lo, paired with the %hi before it
            hi = next((o for o, t, sy in reversed(relocs[:k]) if t == 5 and sy[4] == sshndx), None)
            if hi is None:
                return None
            hw = struct.unpack_from("<I", d, text[4] + hi)[0]
            lit_off = ((hw & 0xFFFF) << 16) + s16(w & 0xFFFF)
            target = ((oword(hi) & 0xFFFF) << 16) + s16(oword(off) & 0xFFFF)
        elif rtype == 5:
            continue
        else:
            return None
        value = d[lit_sec[4] + lit_off:lit_sec[4] + lit_off + 4]
        if len(value) != 4 or odata(target, 4) != value:
            return None
        bits = struct.unpack("<I", value)[0]
        if out.setdefault(bits, (target, rtype == 7)) != (target, rtype == 7):
            return None
    return out


def s16(x):
    return x - 0x10000 if x & 0x8000 else x


def use_literals(text, lits):
    """Replaces the float constants in `text` by the globals at their
    original addresses; returns (text, externs) or None."""
    externs = {}

    def sub(m):
        bits = struct.unpack("<I", struct.pack("<f", float(m.group(1))))[0]
        if bits not in lits:
            return m.group(0)
        a, gp_relative = lits[bits]
        sym = f"D_{a:08X}"
        if gp_relative:  # small data (.lit4): a plain variable
            externs[sym] = "float"
            return sym
        externs[sym + "[]"] = "float"
        return f"{sym}[0]"
    new = FLOAT_TOKEN.sub(sub, text)
    if new == text:
        return None
    return new, externs


# further rewrites tried when Ghidra's text does not match as it is
OPTIONS = ((), ("addr",), ("signed",), ("float",), ("addr", "signed"), ("addr", "float"),
           ("signed", "float"), ("sint",), ("wide",), ("s64",), ("addr", "sint"),
           ("swap",), ("swap", "addr"), ("swap", "signed"))


def closing(text, i, open_ch, close_ch):
    """Index of the bracket closing the one at text[i]."""
    depth = 0
    for k in range(i, len(text)):
        if text[k] == open_ch:
            depth += 1
        elif text[k] == close_ch:
            depth -= 1
            if depth == 0:
                return k
    return None


def swap_branches(body):
    """`if (c) {A} else {B}` -> `if (!(c)) {B} else {A}`, for every if/else
    whose else is a plain block (Ghidra picks its own order of the two)."""
    out, pos = [], 0
    for m in re.finditer(r"\bif \(", body):
        if m.start() < pos:
            continue
        c_end = closing(body, m.end() - 1, "(", ")")
        if c_end is None or body[c_end + 1:c_end + 3] != " {":
            continue
        a_end = closing(body, c_end + 2, "{", "}")
        e = re.match(r"\s*else \{", body[a_end + 1:]) if a_end is not None else None
        if not e:
            continue
        b_start = a_end + e.end()
        b_end = closing(body, b_start, "{", "}")
        if b_end is None:
            continue
        a, b = swap_branches(body[c_end + 3:a_end]), swap_branches(body[b_start + 1:b_end])
        out.append(body[pos:m.start()])
        out.append(f"if (!({body[m.end():c_end]})) {{{b}}}{body[a_end + 1:b_start]}{{{a}}}")
        pos = b_end + 1
    out.append(body[pos:])
    return "".join(out)


def rewrite(body, opts):
    """Returns (body, extra externs) with the rewrites in `opts`:
    addr    numbers that are addresses in the executable become references to
            that address (the compiler builds a symbol's address with
            lui/addiu, a number with lui/ori)
    signed  Ghidra's unsigned bytes and shorts become signed
    float   4-byte parameters Ghidra left untyped become float
    sint    unsigned / untyped 4-byte values become int
    s64     unsigned 64-bit values become signed
    wide    byte and short parameters become int
    swap    the two branches of each if/else change places, the condition
            negated"""
    extra = {}
    if "swap" in opts:
        body = swap_branches(body)
    if "addr" in opts:
        def sub(m):
            v = int(m.group(1), 16)
            if not 0x100000 <= v < 0x640000:
                return m.group(0)
            extra[f"D_{v:08X}[]"] = "char"
            return f"((int)D_{v:08X})"
        body = re.sub(r"\b0x([0-9a-f]{6,8})\b", sub, body)
    if "signed" in opts:
        for a, b in (("byte", "char"), ("undefined1", "char"), ("ushort", "short"), ("undefined2", "short")):
            body = re.sub(rf"\b{a}\b", b, body)
    if "sint" in opts:
        for a in ("uint", "undefined4"):
            body = re.sub(rf"\b{a}\b", "int", body)
    if "s64" in opts:
        body = re.sub(r"\b(undefined8|ulong)\b", "long", body)
    if "wide" in opts:
        head, brace, rest = body.partition("{")
        head = re.sub(r"\b(undefined1|undefined2|byte|char|short|ushort) param_", "int param_", head)
        body = head + brace + rest
    if "float" in opts:
        head, brace, rest = body.partition("{")
        body = re.sub(r"\bundefined4 param_", "float param_", head) + brace + rest
    return body, extra


def pin_repeated_names(text, decls, addr, nwords):
    """Calls to a name Ghidra gives to several functions become calls to
    func_XXXXXXXX of the one the original calls."""
    from match import original_words, symbol_addresses
    words = None
    for d in list(decls):
        callee = re.search(r"\b(\w+)\(", d).group(1)
        options = symbol_addresses(callee)
        if not options:
            continue
        if words is None:
            words = original_words(addr, nwords)
        targets = {((addr + 4 * i) & 0xF0000000) | ((w & 0x03FFFFFF) << 2)
                   for i, w in enumerate(words) if w >> 26 in (2, 3)}
        hit = [a for a in options if a in targets]
        if len(hit) == 1:
            new = f"func_{hit[0]:08X}"
            text = re.sub(rf"\b{callee}\b", new, text)
            decls = [x if x != d else re.sub(rf"\b{callee}\b", new, d) for x in decls]
    return text, decls


def frame_size(words):
    """Stack frame size from a function's first instruction (0 for none)."""
    w = words[0] if words else 0
    return 0x10000 - (w & 0xFFFF) if w >> 16 == 0x27BD and w & 0x8000 else 0


def flag_choices(addr, size):
    """Compiler flags to try. The game's C++ files were built with
    exceptions on, which keeps a call at the end of a function from becoming
    a tail call (`j`); only functions that make calls can tell."""
    from match import original_words
    words = original_words(addr, size // 4)
    calls = any(w >> 26 == 3 for w in words)
    tail = any(w >> 26 == 2 for w in words)
    if not calls:
        return ((),)
    return ((), ("-fexceptions",)) if tail else (("-fexceptions",), ())


def compile_and_compare(text, externs, decls, hdr, name, addr, flags, tmp):
    """Compiles one candidate; returns (differing words, words, text, externs)
    or None if it does not compile or keeps constants of its own."""
    src = os.path.join(tmp, "f.c")
    obj = os.path.join(tmp, "f.o")
    # flags may name the compiler ("compiler=990721"); the rest go to it
    compiler = next((f[9:] for f in flags if f.startswith("compiler=")), "991111-01")
    real_flags = [f for f in flags if not f.startswith("compiler=")]

    def build():
        with open(src, "w") as f:
            f.write(f'#include "{hdr}"\n')
            f.writelines(f"extern {t} {s};\n" for s, t in externs.items())
            f.writelines(d + "\n" for d in decls)
            f.write(text + "\n")
        try:  # cc1 loops forever on a few inputs
            r = asm_build.compile_c(src, obj, ["-O2", "-G8", "-w", *real_flags], compiler, timeout=60)
        except subprocess.TimeoutExpired:
            global timed_out
            timed_out = True
            subprocess.run(["pkill", "-f", src])
            return False
        return r.returncode == 0

    def own_data():
        # with -fexceptions, .data holds the frame tables (dropped by the build)
        return any(n in asm_build.C_DATA and h[5] and not (real_flags and n == ".data")
                   for n, h in sections(open(obj, "rb").read()))
    if not build():
        return None
    # constants of its own (.lit4, .rodata): use the original copies
    if own_data():
        lits = literal_addresses(obj, name, addr)
        fixed = use_literals(text, lits) if lits else None
        if not fixed:
            return None
        text, more = fixed
        externs = dict(externs, **more)
        if not build() or own_data():
            return None
    try:
        bad, words, _, want = compare(obj, name, addr)
    except SystemExit:
        return None
    return bad, words, want, text, externs


timed_out = False


# the searches, in order: (name, compiler, extra flags). A function is
# tried with the next only when the ones before found nothing; results are
# cached per search, so adding one only runs the new search.
PASSES = (
    ("991111-01", "991111-01", ()),
    ("990721", "990721", ()),
    ("991111-01-nogcse", "991111-01", ("-fno-gcse",)),
    ("991111-01-nosched", "991111-01", ("-fno-schedule-insns",)),
    ("990721-r5900", "990721-r5900", ("-fno-thread-jumps",)),
    ("991111-01-nosched-nogcse", "991111-01", ("-fno-schedule-insns", "-fno-gcse")),
    ("991111-01-nosched2", "991111-01", ("-fno-schedule-insns2",)),
    ("991111-01-nosched-nosched2", "991111-01", ("-fno-schedule-insns", "-fno-schedule-insns2")),
    ("991111-01-nosched2-nogcse", "991111-01", ("-fno-schedule-insns2", "-fno-gcse")),
    ("990721-r5900-nosched2", "990721-r5900", ("-fno-thread-jumps", "-fno-schedule-insns2")),
)


def try_one(job_passes):
    """Returns (job key, {pass name: match or None}) for the passes asked."""
    global timed_out
    job, passes = job_passes
    out = {}
    for name, compiler, extra in PASSES:
        if name not in passes:
            continue
        timed_out = False
        found = search_with(job, compiler, extra)
        out[name] = found
        if found or timed_out:
            break
    return job[-1], out


def search_with(job, compiler, extra=()):
    addr, name, group, body0, protos, hdr, size, _ = job
    flag_sets = [tuple(extra) + f + ((f"compiler={compiler}",) if compiler != "991111-01" else ())
                 for f in flag_choices(addr, size)]
    tried = set()  # options often give the same text (no long to change, no byte to sign)
    for opts, variant, types in itertools.product(OPTIONS, VARIANTS, dat_type_choices(body0)):
        body, extra = rewrite(body0, opts)
        if opts and body == body0:
            continue
        prep = prepare(name, body, protos, variant, types)
        if prep is None:
            return None
        text, externs, decls = prep
        if any(externs.get(k, t) != t for k, t in extra.items()):
            continue
        externs = dict(externs, **extra)
        for flags in flag_sets:
            key = (text, tuple(sorted(externs.items())), tuple(decls), flags)
            if key in tried:
                continue
            tried.add(key)
            with tempfile.TemporaryDirectory() as tmp:
                res = compile_and_compare(text, externs, decls, hdr, name, addr, flags, tmp)
                if timed_out:  # cc1 loops on this function; its variants would too
                    return None
                if res and res[0]:
                    # unused local arrays still take stack space, and Ghidra
                    # does not show them: pad the frame to the original's size
                    bad, words, want, t2, e2 = res
                    pad = frame_size(want) - frame_size(words)
                    if pad > 0 and pad % 16 == 0 and "{\n" in t2:
                        i = t2.index("{\n") + 2
                        t3 = t2[:i] + f"  undefined1 auStack_pad[{pad}];\n" + t2[i:]
                        res = compile_and_compare(t3, e2, decls, hdr, name, addr, flags, tmp)
                if res and res[0] == 0:
                    _, words, _, text2, externs2 = res
                    text2, decls2 = pin_repeated_names(text2, decls, addr, len(words))
                    return addr, name, group, text2, externs2, decls2, flags
    return None


# GG_INTRET=1: every void callee is declared int, whether or not the result is used (the callee's
# return value register then stays live, which changes register choice); separate cache
INTRET = bool(os.environ.get("GG_INTRET"))
VARIANTS = ("intret",) if INTRET else ("int", "ghidra")
CACHE = os.path.join(ROOT, "build", "gen_ghidra_intret_cache.json" if INTRET else "gen_ghidra_cache.json")


# bump when a change to the search (rewrites, flags, compilers) can change
# results; the cache in build/ is then rebuilt from scratch
CACHE_VERSION = 3  # the passes are cached apart (PASSES)


def inputs_key():
    """Hash of everything besides a function's own text that decides whether
    it matches: CACHE_VERSION, the header, Ghidra's prototypes and function
    list, the original executable and the compilers."""
    import hashlib
    h = hashlib.sha1(f"{CACHE_VERSION}".encode())
    for path in (os.path.join(ROOT, "src", "ghidra.h"), os.path.join(ROOT, "decomp", "legaia2.h"),
                 os.path.join(ROOT, "decomp", "functions.csv"), asm_build.EXE,
                 asm_build.EE_CC, asm_build.EE_CC_990721):
        h.update(open(path, "rb").read())
    return h.hexdigest()


def job_key(job, tools_key):
    import hashlib
    addr, name, group, body, _, _, size = job
    return hashlib.sha1(f"{tools_key}\0{addr:x}\0{name}\0{group}\0{size}\0{body}".encode()).hexdigest()


def load_cache():
    """{job key: {pass name: match or None}} from earlier runs (build/, so not
    in git). An older cache ({job key: match or None}, from the first two
    passes) is read as such."""
    import json
    try:
        with open(CACHE) as f:
            cache = json.load(f)
    except (OSError, ValueError):
        return {}
    return {k: (v if isinstance(v, dict) else {"991111-01": v, "990721": v} if v is None else
                {"991111-01": v}) for k, v in cache.items()}


def save_cache(cache, keep):
    import json
    os.makedirs(os.path.dirname(CACHE), exist_ok=True)
    with open(CACHE + ".tmp", "w") as f:
        json.dump({k: v for k, v in cache.items() if k in keep}, f)
    os.replace(CACHE + ".tmp", CACHE)


def main(argv):
    max_size = int(argv[1]) if len(argv) > 1 and argv[1].isdigit() else 1024
    protos = prototypes()
    taken = set()
    for path in glob.glob(os.path.join(ROOT, "src", "*.c")) + glob.glob(os.path.join(ROOT, "src", "gen", "*.c")):
        taken |= {int(a, 16) for a in re.findall(r"MATCH\s+func_([0-9A-Fa-f]{8})", open(path).read())}
    hdr = os.path.join(ROOT, "src", "ghidra.h")
    tools_key = inputs_key()
    jobs = []
    with open(os.path.join(ROOT, "decomp", "functions.csv")) as f:
        rows = list(csv.DictReader(f))
    for r in rows:
        addr, size = int(r["address"], 16), int(r["size_bytes"])
        if addr in taken or addr % 8 or size > max_size or r["decompiled"] != "ok":
            continue
        paths = (glob.glob(os.path.join(ROOT, "decomp", "src", "*", r["name"] + ".c")) +
                 glob.glob(os.path.join(ROOT, "decomp", "src", "*", f"{r['name']}_{addr:08x}.c")))
        paths = [p for p in paths if f"@ 0x{addr:08x}," in open(p).read(200)]
        if len(paths) != 1:
            continue
        job = (addr, r["name"], r["group"] or "none", body_of(paths[0]), protos, hdr, size)
        jobs.append(job + (job_key(job, tools_key),))
    cache = load_cache()

    def match_of(entry):
        return next((v for v in entry.values() if v), None)
    if "--from-cache" in argv:
        # only rewrite src/ghidra: every match in the cache that is not taken now
        by_addr = {}
        for entry in cache.values():
            m = match_of(entry)
            if m and m[0] not in taken:
                by_addr[m[0]] = tuple(m[:-1]) + (tuple(m[-1]),)
        return write_files([by_addr[a] for a in sorted(by_addr)])
    todo = []
    for j in jobs:
        entry = cache.get(j[-1], {})
        if match_of(entry):
            continue
        missing = [n for n, _, _ in PASSES if n not in entry]
        if missing:
            todo.append((j, missing))
    print(f"trying {len(todo)} of {len(jobs)} functions (the rest known from {CACHE})")
    with concurrent.futures.ProcessPoolExecutor(int(os.environ.get("GG_JOBS", os.cpu_count()))) as pool:
        keep = {j[-1] for j in jobs}
        for n, (key, results) in enumerate(pool.map(try_one, todo, chunksize=8)):
            cache.setdefault(key, {}).update(results)
            if n % 40 == 39:  # a long run survives being killed
                save_cache(cache, keep)
    save_cache(cache, {j[-1] for j in jobs})
    found = []
    for j in jobs:
        m = match_of(cache.get(j[-1], {}))
        if m:
            found.append(tuple(m[:-1]) + (tuple(m[-1]),))
    if os.environ.get("GG_NEW"):
        have = set()
        for path in glob.glob(os.path.join(ROOT, "src", "**", "*.c"), recursive=True):
            have |= {int(a, 16) for a in re.findall(r"MATCH\s+func_([0-9A-Fa-f]{8})", open(path).read())}
        found = [f for f in found if f[0] not in have and f[0] not in taken]
        print(f"{len(found)} new matches")
    write_files(found)


def write_files(found):
    """Writes src/ghidra/ from the matches (addr, name, group, text, externs, decls, flags)."""

    if not os.environ.get("GG_NEW"):  # GG_NEW: only add files (matches not in src/ghidra yet)
        for old in glob.glob(os.path.join(OUTDIR, "*.c")):
            os.remove(old)
    os.makedirs(OUTDIR, exist_ok=True)
    files = {}
    for addr, name, group, text, externs, decls, flags in sorted(found):
        # files built with -fexceptions (`// cflags:` line) or with 990721
        # (`// compiler:` line) are kept apart
        compiler = next((f[9:] for f in flags if f.startswith("compiler=")), None)
        cflags = tuple(f for f in flags if not f.startswith("compiler="))
        base = (("n_" if os.environ.get("GG_NEW") else "") + re.sub(r"[^A-Za-z0-9_]", "_", group) +
                (("_eh" if cflags == ("-fexceptions",) else "_" + "_".join(c.lstrip("-").replace("-", "") for c in cflags)) if cflags else "") +
                (f"_{compiler}" if compiler else ""))
        n = 0
        while True:  # one file per group unless declarations clash
            key = base if n == 0 else f"{base}_{n}"
            fdat = files.setdefault(key, {"externs": {}, "decls": {}, "funcs": [], "flags": cflags,
                                          "compiler": compiler})
            # the same symbol declared alike (type, and array or not)
            have = {k.replace("[]", ""): (k, t) for k, t in fdat["externs"].items()}
            ok = all(have.get(s.replace("[]", ""), (s, t)) == (s, t) for s, t in externs.items())
            dnames = {re.search(r"\b(\w+)\(", d).group(1): d for d in decls}
            ok = ok and all(fdat["decls"].get(k, d) == d for k, d in dnames.items())
            # a function defined in the file is its own prototype there: keep
            # callers and callees apart (Ghidra's call sites disagree at times)
            names_here = {nm for _, nm, _ in fdat["funcs"]}
            ok = ok and name not in fdat["decls"] and not (set(dnames) & names_here)
            if ok:
                break
            n += 1
        fdat["externs"].update(externs)
        fdat["decls"].update(dnames)
        fdat["funcs"].append((addr, name, text))
    total = 0
    for key, fdat in sorted(files.items()):
        defined = {nm for _, nm, _ in fdat["funcs"]}
        with open(os.path.join(OUTDIR, key + ".c"), "w") as f:
            f.write(f"/* {key}: Ghidra's decompilation of these functions, with only types and global\n"
                    "   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.\n"
                    "   Still to be cleaned up by hand. */\n" +
                    (f"// cflags: {' '.join(fdat['flags'])}\n" if fdat["flags"] else "") +
                    (f"// compiler: {fdat['compiler']}\n" if fdat["compiler"] else "") +
                    '#include "../ghidra.h"\n\n')
            f.writelines(f"extern {t} {s};\n" for s, t in sorted(fdat["externs"].items()))
            f.writelines(d + "\n" for k, d in sorted(fdat["decls"].items()) if k not in defined)
            for addr, name, text in fdat["funcs"]:
                # Ghidra's comments and the DAT_ defines go above the marker, which must
                # come right before the definition
                lead = re.match(r"(\s*(?:/\*.*?\*/|#define [^\n]*\n))*\s*", text, re.S).group(0)
                f.write(f"\n{lead.strip()}\n" if lead.strip() else "\n")
                # the return type and name on one line, for the MATCH marker
                definition = re.sub(r"^(\w[\w \*]*?)\s*\n\s*(\w+\s*\()", r"\1 \2", text[len(lead):])
                f.write(f"// MATCH func_{addr:08X}\n{definition}\n")
        total += len(fdat["funcs"])
    print(f"wrote {total} matching functions to {len(files)} files in src/ghidra")


if __name__ == "__main__":
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    main(sys.argv)
