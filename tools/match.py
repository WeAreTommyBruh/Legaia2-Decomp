#!/usr/bin/env python3
"""Compiles C with the game's compiler and compares one function with the
original executable.

  match.py FILE.c FUNCTION ADDRESS [compiler flags...]
  match.py FILE.c          (every function marked `// MATCH func_XXXXXXXX`)

FILE.c is compiled with $EE_CC (default ~/tools/ee-gcc2.9-991111-01/bin/ee-gcc; the driver
picks cc1plus for .cpp files) using -O2 -G8 plus the file's `// cflags:` line
unless flags are given; a file with a `// compiler: 990721` line is built with
ee-gcc 2.9-ee-990721 instead (see tools/asm_build.py). The
function's bytes are taken from the object file and compared word by word
with the original at ADDRESS (hex). Words the linker would still change
(relocations: jal targets, %hi/%lo halves, gp offsets) are filled in from
the symbols' final addresses (decomp/functions.csv, D_XXXXXXXX, matched C);
a field whose symbol is unknown counts as a difference. Prints a side-by-side listing and MATCH or the number
of differing words; exit status 0 on a match.
"""

import csv
import glob
import os
import re
import struct
import subprocess
import sys
import tempfile

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ee_disasm  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXE = os.path.join(ROOT, "disc", "SLES_508.91")
DEFAULT_CC = os.path.expanduser("~/tools/ee-gcc2.9-991111-01/bin/ee-gcc")
# relocation type -> bits the linker fills in
RELOC_MASK = {4: 0x03FFFFFF, 5: 0xFFFF, 6: 0xFFFF, 7: 0xFFFF, 8: 0xFFFF, 2: 0xFFFFFFFF}


def sections(d):
    shoff = struct.unpack_from("<I", d, 0x20)[0]
    shnum, shstrndx = struct.unpack_from("<HH", d, 0x30)
    hs = [struct.unpack_from("<10I", d, shoff + 40 * i) for i in range(shnum)]
    st = hs[shstrndx][4]
    return [(d[st + h[0]:d.index(b"\0", st + h[0])].decode(), h) for h in hs]


_symbols = None
_dupes = {}


def symbol_addresses(name):
    """Every address of a function name Ghidra gave to more than one function."""
    symbol_address(name)
    return _dupes.get(name, ())


def extra_symbols():
    """{name: address} from src/symbols.txt (names Ghidra's list lacks)."""
    out = {}
    path = os.path.join(ROOT, "src", "symbols.txt")
    if os.path.exists(path):
        for line in open(path):
            f = line.split("#")[0].split()
            if len(f) == 2:
                out[f[0]] = int(f[1], 16)
    return out


def symbol_address(name):
    """Final address of a symbol the C refers to: D_XXXXXXXX / func_XXXXXXXX,
    a function name from decomp/functions.csv, or a matched C function."""
    global _symbols
    m = re.fullmatch(r"(?:D|func)_([0-9A-Fa-f]{8})", name)
    if m:
        return int(m.group(1), 16)
    if _symbols is None:
        _symbols, seen = {}, set()
        with open(os.path.join(ROOT, "decomp", "functions.csv")) as f:
            for r in csv.DictReader(f):
                n = r["name"]
                if n in seen:  # ambiguous (Ghidra repeats some names)
                    if n in _symbols:
                        _dupes[n] = [_symbols.pop(n)]
                    _dupes.setdefault(n, []).append(int(r["address"], 16))
                else:
                    seen.add(n)
                    _symbols[n] = int(r["address"], 16)
        _symbols.update(extra_symbols())
        for src in glob.glob(os.path.join(ROOT, "src", "**", "*.c"), recursive=True):
            for a, n in re.findall(r"//\s*MATCH\s+func_([0-9A-Fa-f]{8})\s*\n[^\n(]*?(\w+)\s*\(", open(src).read()):
                _symbols[n] = int(a, 16)
    return _symbols.get(name)


DATA_SECTIONS = (".rodata", ".data", ".sdata", ".lit4", ".lit8")


def function_bytes(obj, name, addr=None, original=None, placements=None):
    """Returns (words, masks) of function `name` in a relocatable ELF object.

    Without `addr`, relocated fields are masked (masks has their bits set).
    With `addr` (the function's final address), they are filled in from the
    symbols' final addresses as the linker would; only fields whose symbol
    is unknown stay masked. References to the object's own data (a switch's
    jump table in .rodata, constants) are placed where the original
    instruction (`original`) points; `placements` ({section: address}) gets
    those addresses, and compare() checks the data there."""
    d = open(obj, "rb").read()
    secs = sections(d)
    symtab = next(h for n, h in secs if h[1] == 2)
    strtab = secs[symtab[6]][1]
    syms, sym = [], None
    for i in range(symtab[5] // 16):
        nm, val, size, info, other, shndx = struct.unpack_from("<IIIBBH", d, symtab[4] + 16 * i)
        s = d[strtab[4] + nm:d.index(b"\0", strtab[4] + nm)].decode()
        syms.append((s, val, size, info, shndx))
        if sym is None and (s == name or (s.startswith(f"_{name}") or s.startswith(f"{name}__")) and info & 0xF == 2):
            sym = (val, size, shndx)
    if sym is None:
        raise SystemExit(f"{name} not found in the object")
    val, size, shndx = sym
    text = secs[shndx][1]
    words = list(struct.unpack_from(f"<{size // 4}I", d, text[4] + val))
    masks = [0] * len(words)
    relocs = []
    for n, h in secs:
        if h[1] == 9 and h[7] == shndx:  # SHT_REL for this section
            for j in range(h[5] // 8):
                off, info = struct.unpack_from("<II", d, h[4] + 8 * j)
                if val <= off < val + size:
                    relocs.append((off, info & 0xFF, info >> 8))
    funcs_at = {v: s for s, v, sz, inf, sh in syms if sh == shndx and inf & 0xF == 2}
    gp = 0x4A7C70
    # the object's own gp: %gp_rel addends against its local sections are relative to it
    gp0 = next((struct.unpack_from("<I", d, h[4] + 20)[0] for n, h in secs if n == ".reginfo"), 0)

    def inplace(off):
        return struct.unpack_from("<I", d, text[4] + off)[0]

    def lo_after(k, si):
        return next((inplace(o) for o, t, s2 in relocs[k + 1:] if t == 6 and s2 == si), 0) & 0xFFFF

    def own_data(si):
        """Name of the object's data section a section symbol stands for."""
        s, v, sz, inf, sh = syms[si]
        if inf & 0xF == 3 and 0 < sh < len(secs) and secs[sh][0] in DATA_SECTIONS:
            return secs[sh][0]
        return None
    placed, refs = {}, {}
    if addr is not None and original is not None:
        # where the original puts each of the object's data sections
        for k, (off, rtype, si) in enumerate(relocs):
            sec = own_data(si)
            if not sec:
                continue
            i = (off - val) // 4
            if rtype == 5:
                j = next(((o - val) // 4 for o, t, s2 in relocs[k + 1:] if t == 6 and s2 == si), None)
                if j is None:
                    continue
                want = ((original[i] & 0xFFFF) << 16) + s16(original[j] & 0xFFFF)
                ours = ((inplace(off) & 0xFFFF) << 16) + s16(inplace(val + 4 * j) & 0xFFFF)
            elif rtype in (7, 8):  # %gp_rel, and a literal (li.s) in .lit4
                want = gp + s16(original[i] & 0xFFFF)
                ours = s16(inplace(off) & 0xFFFF) + gp0
            else:
                continue
            base = (want - ours) & 0xFFFFFFFF
            if placed.setdefault(sec, base) != base:
                placed[sec] = None  # the references disagree
            refs.setdefault(sec, set()).add(ours)
        if placements is not None:
            placements.update({sec: (b, refs[sec]) for sec, b in placed.items()})
    for k, (off, rtype, si) in enumerate(relocs):
        i = (off - val) // 4
        mask = RELOC_MASK.get(rtype, 0xFFFFFFFF)
        target = None
        if addr is not None:
            sname = syms[si][0]
            if own_data(si):
                target, sname = placed.get(own_data(si)), ""
                if target is not None and rtype in (7, 8):
                    target += gp0
            elif not sname and rtype == 4:  # call inside the file: by section offset
                sname = funcs_at.get((words[i] & 0x03FFFFFF) << 2, "")
            if sname:
                target = symbol_address(sname)
            if target is None and sname and rtype == 4 and original is not None:
                # a name Ghidra repeats: fine if the original calls one of them
                o = ((addr + off - val) & 0xF0000000) | ((original[i] & 0x03FFFFFF) << 2)
                if o in symbol_addresses(sname):
                    target = o
        w = words[i]
        if target is None:
            masks[i] |= mask
        elif rtype == 4:
            words[i] = (w & ~0x03FFFFFF) | ((target >> 2) & 0x03FFFFFF)
        elif rtype == 5:  # %hi: the addend continues in the next %lo of the symbol
            lo = lo_after(k, si)
            v = target + ((w & 0xFFFF) << 16) + (lo - 0x10000 if lo & 0x8000 else lo)
            words[i] = (w & ~0xFFFF) | (((v + 0x8000) >> 16) & 0xFFFF)
        elif rtype in (6, 7, 8):
            a = w & 0xFFFF
            v = target + (a - 0x10000 if a & 0x8000 else a) - (gp if rtype in (7, 8) else 0)
            words[i] = (w & ~0xFFFF) | (v & 0xFFFF)
        else:
            masks[i] |= mask
    return words, masks


def s16(x):
    return x - 0x10000 if x & 0x8000 else x


def check_data(obj, name, addr, placements):
    """Number of words of the object's data, placed at `placements`, that
    differ from the original: the words the function's relocations refer
    to, and every word relocated against the function (jump table entries,
    whose addresses must be the original's)."""
    d = open(obj, "rb").read()
    secs = sections(d)
    symtab = next(h for n, h in secs if h[1] == 2)
    strtab = secs[symtab[6]][1]
    syms = []
    for i in range(symtab[5] // 16):
        nm, v, size, info, other, shndx = struct.unpack_from("<IIIBBH", d, symtab[4] + 16 * i)
        syms.append((d[strtab[4] + nm:d.index(b"\0", strtab[4] + nm)].decode(), v, size, info, shndx))
    fn = next(x for x in syms if x[0] == name and x[3] & 0xF == 2)
    fval, fsize, fsec = fn[1], fn[2], fn[4]
    exe = open(EXE, "rb").read()
    osecs = [h for n, h in sections(exe) if h[1] == 1]

    def original_at(a):
        for h in osecs:
            if h[3] <= a < h[3] + h[5]:
                return struct.unpack_from("<I", exe, h[4] + a - h[3])[0]
        return None
    bad = 0
    for sname, (base, refs) in placements.items():
        if base is None:
            bad += 1
            continue
        si = next(i for i, (n, h) in enumerate(secs) if n == sname)
        h = secs[si][1]
        data = bytearray(d[h[4]:h[4] + h[5]])
        relocs = {}
        for n, rh in secs:
            if rh[1] == 9 and rh[7] == si:
                for j in range(rh[5] // 8):
                    off, info = struct.unpack_from("<II", d, rh[4] + 8 * j)
                    relocs[off] = (info & 0xFF, info >> 8)
        for off, (rtype, symi) in relocs.items():
            s, v, size, info, shndx = syms[symi]
            if rtype != 2 or shndx != fsec:
                continue  # another function's table: checked with that function
            w = struct.unpack_from("<I", data, off)[0]
            target = addr - fval + v + w  # REL: the addend is in place
            if not fval <= target - addr + fval < fval + fsize:
                continue  # into another function of the same section: checked with that one
            if original_at(base + off) != target:
                bad += 1
        # constants the code refers to (a jump table's first word is
        # relocated, and checked above)
        for off in refs:
            if off not in relocs and (off + 4 > len(data) or
                                      original_at(base + off) != struct.unpack_from("<I", data, off)[0]):
                bad += 1
    return bad


def compare(obj, name, addr):
    """Number of words of `name` in `obj` that differ from the original at
    `addr`, with relocations resolved; unknown symbols count as differences,
    and so do words of the object's own data that differ from the original
    where the original keeps them."""
    n = len(function_bytes(obj, name)[0])
    placements = {}
    words, masks = function_bytes(obj, name, addr, original_words(addr, n), placements)
    # trailing zero words are alignment padding, unless one is a delay slot
    while len(words) > 1 and words[-1] == 0 and masks[-1] == 0:
        prev = ee_disasm.decode(words[-2], addr + 4 * (len(words) - 2))
        if prev and (prev[0] in ("jr", "jalr") or prev[2] is not None):
            break
        words.pop(), masks.pop()
    want = original_words(addr, len(words))
    bad = sum(1 for w, m, o in zip(words, masks, want) if m or w != o)
    if placements:
        bad += check_data(obj, name, addr, placements)
    return bad, words, masks, want


def original_words(addr, count):
    d = open(EXE, "rb").read()
    text = next(h for n, h in sections(d) if n == ".text")
    off = text[4] + addr - text[3]
    return list(struct.unpack_from(f"<{count}I", d, off))


def show(w, pc):
    dec = ee_disasm.decode(w, pc)
    return f"{dec[0]} {dec[1]}" if dec else f".word {w:#010x}"


def file_flags(src):
    """Flags from a `// cflags: ...` line in the file (see asm_build.py)."""
    m = re.search(r"^//\s*cflags:(.*)$", open(src).read(), re.M)
    return m.group(1).split() if m else []


def check_file(src):
    """Compiles FILE.c and compares every function marked `// MATCH func_X`."""
    cc = os.environ.get("EE_CC", DEFAULT_CC)
    marks = re.findall(r"//\s*MATCH\s+func_([0-9A-Fa-f]{8})\s*\n[^\n(]*?(\w+)\s*\(", open(src).read())
    with tempfile.TemporaryDirectory() as tmp:
        obj = os.path.join(tmp, "out.o")
        import asm_build
        r = asm_build.compile_c(src, obj, ["-O2", "-G8", *file_flags(src)])
        if r.returncode:
            raise SystemExit(r.stderr.strip() or "compile failed")
        bad_funcs = 0
        for a, name in marks:
            bad, words, _, _ = compare(obj, name, int(a, 16))
            print(f"{a.lower()} {name}: " + ("MATCH" if not bad else f"{bad} of {len(words)} words differ"))
            bad_funcs += bool(bad)
    print(f"{len(marks) - bad_funcs} of {len(marks)} marked functions match")
    return 1 if bad_funcs else 0


def main(argv):
    if len(argv) == 2:
        return check_file(argv[1])
    if len(argv) < 4:
        raise SystemExit(__doc__)
    src, name, addr = argv[1], argv[2], int(argv[3], 16)
    flags = argv[4:] or ["-O2", "-G8"] + file_flags(src)
    cc = os.environ.get("EE_CC", DEFAULT_CC)
    with tempfile.TemporaryDirectory() as tmp:
        obj = os.path.join(tmp, "out.o")
        import asm_build
        r = (asm_build.compile_c(src, obj, flags) if "EE_CC" not in os.environ else
             subprocess.run([cc, "-c", *flags, "-o", obj, src], capture_output=True, text=True))
        if r.returncode:
            raise SystemExit(r.stderr.strip() or "compile failed")
        bad, words, masks, want = compare(obj, name, addr)
    for i, (w, m, o) in enumerate(zip(words, masks, want)):
        same = not m and w == o
        pc = addr + 4 * i
        print(f"{pc:08x}  {'  ' if same else '!='} {show(o, pc):<34} {show(w, pc)}")
    print("MATCH" if not bad else f"{bad} of {len(words)} words differ")
    return 0 if not bad else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv))
