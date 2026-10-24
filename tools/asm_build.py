#!/usr/bin/env python3
"""Rebuilds the game executable (SLES_508.91) from disassembly and checks that
it is byte-identical to the original.

split   disassembles .text into asm/NNN_<source>.s, one file per contiguous
        run of functions attributed to the same source file (from
        decomp/functions.csv), and writes asm/data.s (the other sections,
        included from the original executable) and build/link.ld.
        Functions marked `// MATCH func_XXXXXXXX` in src/*.c are left out of
        the assembly and taken from the compiled C instead.
build   assembles everything with clang, compiles src/*.c with the game's
        compiler (ee-gcc 2.9-ee-991111-01 -O2 -G8), links with ld.lld at
        the original addresses, writes build/SLES_508.91 and compares it with
        disc/SLES_508.91 section by section and as a whole file.

Every instruction is written as clang-compatible assembly where ee_disasm.py
can decode it and as a .word otherwise; if a decoded instruction assembles to
different bytes, split remembers its address (build/word_overrides.txt) and
writes it as a .word next time. Branch targets get local labels and jal/j
targets global func_XXXXXXXX labels, so calls are real relocations.
The ELF headers are generated from the original's layout; only the section
contents are rebuilt.

C: each matched function is compiled into its own section
(-ffunction-sections) and placed at its original address; ee-gcc's objects
get the clang objects' ELF ABI flags (only the header changes) so ld.lld
accepts them. Every function also gets its readable name as a symbol, so C
can call any function by the name in decomp/functions.csv.

Needs clang and ld.lld with the MIPS target ($CLANG, $LLD; found on PATH or
in the retcomm toolchain otherwise). Generated files (asm/, build/) contain
game code and are git-ignored.

Usage: asm_build.py split | build | all
"""

import collections
import concurrent.futures
import csv
import glob
import hashlib
import os
import re
import shutil
import struct
import subprocess
import sys

import ee_disasm

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXE = os.path.join(ROOT, "disc", "SLES_508.91")
ASM = os.path.join(ROOT, "asm")
BUILD = os.path.join(ROOT, "build")
OVERRIDES = os.path.join(BUILD, "word_overrides.txt")
TOOLCHAIN = os.path.expanduser("~/.local/share/retcomm/toolchains/cmake-clang-v1/latest/bin")
ASFLAGS = ["-target", "mipsel-unknown-none", "-mcpu=mips4", "-mabi=32", "-modd-spreg",
           "-mno-abicalls", "-fno-pic", "-c"]
HEADER = ".set noreorder\n.set noat\n.set nomacro\n"
EE_CC = os.environ.get("EE_CC", os.path.expanduser("~/tools/ee-gcc2.9-991111-01/bin/ee-gcc"))
CFLAGS = ["-O2", "-G8", "-ffunction-sections", "-DFUNCSEC"]
C_DATA = (".data", ".rodata", ".bss", ".sdata", ".sbss", ".lit4", ".lit8")
# a C file can ask for more flags with a `// cflags: ...` line; only
# -fexceptions is used: the game's C++ files were built with exceptions on,
# which keeps calls at the end of a function from becoming tail calls
# (object, section, address) of the C files' own data, placed where the
# original has it (a switch's jump table must be at the address the code uses)
C_DATA_PLACED = []
FILE_FLAGS = re.compile(r"^//\s*cflags:(.*)$", re.M)


def file_flags(src):
    """The extra compiler flags a C file asks for."""
    m = FILE_FLAGS.search(open(src).read())
    return m.group(1).split() if m else []


# Some of the game's files were built with an older EE GCC: its compiler is
# 2.9-ee-990721's (no global CSE, and other small differences), its
# assembler the one of 991111-01 (which pads short loops for the R5900);
# such a C file has a `// compiler: 990721` line. The game's build may have
# been a version in between: 990721 calls a library routine to convert a
# float to an int, where the game uses cvt.w.s, and it fills the delay slot
# of short loops, which the game does not: `// compiler: 990721-r5900`
# undoes that (tools/r5900_short_loops.py) before assembling.
FILE_COMPILER = re.compile(r"^//\s*compiler:\s*(\S+)", re.M)
EE_CC_990721 = os.environ.get("EE_CC_990721", os.path.expanduser("~/tools/ee-gcc2.9-990721/bin/ee-gcc"))
COMPILERS = {
    "991111-01": [EE_CC],
    "990721": [EE_CC_990721, "-B" + os.path.join(os.path.dirname(os.path.dirname(EE_CC)), "ee", "bin") + "/"],
}
COMPILERS["990721-r5900"] = COMPILERS["990721"]
SHORT_LOOP_FIX = {"990721-r5900"}


def file_compiler(src):
    """The compiler a C file asks for: "991111-01" (the default), "990721" or
    "990721-r5900"."""
    m = FILE_COMPILER.search(open(src).read())
    return m.group(1) if m else "991111-01"


def compile_c(src, obj, flags, compiler=None, capture=True, timeout=None):
    """Compiles `src` to `obj` with the file's compiler (or `compiler`);
    returns the CompletedProcess."""
    compiler = compiler or file_compiler(src)
    if compiler not in COMPILERS:
        raise SystemExit(f"{src}: unknown compiler {compiler}")
    if compiler not in SHORT_LOOP_FIX:
        return subprocess.run([*COMPILERS[compiler], "-c", *flags, "-o", obj, src], capture_output=capture,
                              text=True, timeout=timeout)
    import tempfile
    from r5900_short_loops import fix
    with tempfile.TemporaryDirectory() as tmp:
        asm = os.path.join(tmp, "a.s")
        r = subprocess.run([*COMPILERS[compiler], "-S", *flags, "-o", asm, src], capture_output=capture,
                           text=True, timeout=timeout)
        if r.returncode:
            return r
        with open(asm) as f:
            lines = fix(f.read().splitlines(True))
        with open(asm, "w") as f:
            f.writelines(lines)
        return subprocess.run([*COMPILERS[compiler], "-c", *flags, "-o", obj, asm], capture_output=capture,
                              text=True, timeout=timeout)


def tool(env, name):
    path = os.environ.get(env) or shutil.which(name) or os.path.join(TOOLCHAIN, name)
    if not os.path.exists(path):
        raise SystemExit(f"{name} not found; set {env}")
    return path


class Elf:
    def __init__(self, data):
        self.data = data
        self.shoff = struct.unpack_from("<I", data, 0x20)[0]
        shnum, shstrndx = struct.unpack_from("<HH", data, 0x30)
        hdrs = [struct.unpack_from("<10I", data, self.shoff + 40 * i) for i in range(shnum)]
        strtab = hdrs[shstrndx][4]
        self.sections = []
        for h in hdrs:
            name = data[strtab + h[0]:data.index(b"\0", strtab + h[0])].decode()
            self.sections.append({"name": name, "type": h[1], "addr": h[3], "off": h[4], "size": h[5]})

    def section(self, name):
        return next(s for s in self.sections if s["name"] == name)


def functions():
    with open(os.path.join(ROOT, "decomp", "functions.csv")) as f:
        rows = list(csv.DictReader(f))
    return sorted((int(r["address"], 16), r["name"], r["group"]) for r in rows)


def c_functions():
    """Compiles src/*.c; returns {address: (object, name, size)} for MATCH functions."""
    from match import function_bytes, original_words, sections
    objcopy = tool("OBJCOPY", "llvm-objcopy")
    del C_DATA_PLACED[:]
    flags = abi_flags()
    out = {}
    for src in sorted(glob.glob(os.path.join(ROOT, "src", "**", "*.c"), recursive=True)):
        text = open(src).read()
        marks = re.findall(r"//\s*MATCH\s+func_([0-9A-Fa-f]{8})\s*\n[^\n(]*?(\w+)\s*\(", text)
        if not marks:
            continue
        rel = os.path.relpath(src, os.path.join(ROOT, "src"))[:-2]
        obj = os.path.join(BUILD, "src", "c_" + re.sub(r"[^A-Za-z0-9_]", "_", rel) + ".o")
        os.makedirs(os.path.dirname(obj), exist_ok=True)
        r = compile_c(src, obj, CFLAGS)
        if r.returncode:
            raise SystemExit(f"{src}:\n{r.stderr}")
        own = {name for name, h in sections(open(obj, "rb").read()) if name in C_DATA and h[5]}
        extra = file_flags(src)
        if extra:
            # -fexceptions adds frame tables to .data, which the build does not
            # use (there is no data of the file's own, checked just above)
            if compile_c(src, obj, CFLAGS + extra).returncode:
                raise SystemExit(f"{src}: does not compile with {' '.join(extra)}")
            subprocess.run([objcopy, "-w", "--remove-section=.data", "--remove-section=.rel.data", obj],
                           check=True)
        subprocess.run([objcopy, "-w", "--remove-section=.rela*", obj], check=True)
        data = bytearray(open(obj, "rb").read())
        struct.pack_into("<I", data, 0x24, flags)
        # lld does not know R_MIPS_LITERAL (a li.s constant in .lit4); it is
        # R_MIPS_GPREL16 against the literal's section
        for _, h in sections(bytes(data)):
            if h[1] == 9:  # SHT_REL
                for off in range(h[4], h[4] + h[5], 8):
                    info = struct.unpack_from("<I", data, off + 4)[0]
                    if info & 0xFF == 8:
                        struct.pack_into("<I", data, off + 4, info & ~0xFF | 7)
        open(obj, "wb").write(data)
        placed = {}
        for addr, name in marks:
            words, _ = function_bytes(obj, name)
            out[int(addr, 16)] = (os.path.basename(obj), name, 4 * len(words))
            # the file's own data (switch tables) goes where the original has it
            p = {}
            function_bytes(obj, name, int(addr, 16), original_words(int(addr, 16), len(words)), p)
            for sec, (base, _) in p.items():
                if base is None or placed.setdefault(sec, base) != base:
                    raise SystemExit(f"{src}: {sec} would have to be in two places; "
                                     "put the functions that use it in separate files")
        for sec in own:
            if sec not in placed:
                raise SystemExit(f"{src}: has {sec} data that no matched function places")
            C_DATA_PLACED.append((os.path.basename(obj), sec, placed[sec]))
    return out


def abi_flags():
    """ELF e_flags of a clang object (copied into ee-gcc objects)."""
    clang = tool("CLANG", "clang")
    probe = os.path.join(BUILD, "probe.o")
    os.makedirs(BUILD, exist_ok=True)
    subprocess.run([clang] + ASFLAGS + ["-x", "assembler", "-", "-o", probe],
                   input=b".text\n", check=True)
    return struct.unpack_from("<I", open(probe, "rb").read(), 0x24)[0]


def split():
    elf = Elf(open(EXE, "rb").read())
    text = elf.section(".text")
    start, end = text["addr"], text["addr"] + text["size"]
    code = elf.data[text["off"]:text["off"] + text["size"]]
    funcs = [f for f in functions() if start <= f[0] < end]
    ends = [f[0] for f in funcs[1:]] + [end]
    overrides = set()
    if os.path.exists(OVERRIDES):
        overrides = {int(x, 16) for x in open(OVERRIDES).read().split()}
    cfuncs = c_functions()

    # runs of functions from the same source group, in address order
    runs = []
    for (addr, name, group), fend in zip(funcs, ends):
        if not runs or runs[-1]["group"] != group:
            runs.append({"group": group, "start": addr, "funcs": []})
        runs[-1]["funcs"].append((addr, fend, name))
    runs[0]["start"] = start
    for a, b in zip(runs, runs[1:]):
        a["end"] = b["start"]
    runs[-1]["end"] = end

    def word(a):
        return struct.unpack_from("<I", code, a - start)[0]

    # global labels: function starts and every jal/j target inside .text
    globals_ = {a for a, _, _ in funcs}
    decoded = {}
    for a in range(start, end, 4):
        d = None if a in overrides else ee_disasm.decode(word(a), a)
        decoded[a] = d
        if d and d[0] in ("j", "jal"):
            if start <= d[2] < end:
                globals_.add(d[2])
            else:
                decoded[a] = None
    # branches must stay inside their run (local labels)
    run_index = []
    for i, r in enumerate(runs):
        run_index += [i] * ((r["end"] - r["start"]) // 4)
    locals_ = set()
    for a, d in decoded.items():
        if d and d[2] is not None and d[0] not in ("j", "jal"):
            t = d[2]
            if start <= t < end and run_index[(t - start) // 4] == run_index[(a - start) // 4]:
                locals_.add(t)
            else:
                decoded[a] = None
    os.makedirs(ASM, exist_ok=True)
    for old in glob.glob(os.path.join(ASM, "*.s")):
        os.remove(old)
    order = []

    def flush(name, lines, first):
        if first is None:
            return
        with open(os.path.join(ASM, name), "w") as f:
            f.writelines(lines)
        order.append(("asm", os.path.join("asm", name), 8 if first % 8 == 0 else 4))

    for i, r in enumerate(runs):
        base = f"{i:03d}_{re.sub(r'[^A-Za-z0-9_]', '_', r['group'] or 'none')}"
        name, lines, first = base + ".s", [HEADER, ".text\n"], None
        names = {a: n for a, _, n in r["funcs"]}
        skip = 0
        for a in range(r["start"], r["end"], 4):
            if a < skip:
                continue
            if a in cfuncs:
                flush(name, lines, first)
                obj, cname, size = cfuncs[a]
                order.append(("c", obj, cname, f"{a:08X}", size))
                skip = a + size
                name, lines, first = f"{base}_{a:08X}.s", [HEADER, ".text\n"], None
                continue
            if first is None:
                first = a
            if a in names:
                lines.append(f"\n# {names[a]}\n")
            if a in globals_:
                lines.append(f".globl func_{a:08X}\nfunc_{a:08X}:\n")
            if a in locals_:
                lines.append(f".L{a:08X}:\n")
            d = decoded[a]
            if d:
                lines.append(f"    {d[0]:<8} {d[1]}\n" if d[1] else f"    {d[0]}\n")
            else:
                lines.append(f"    .word    {word(a):#010x}\n")
        flush(name, lines, first)
    write_data(elf)
    write_link(elf, order, funcs, cfuncs)
    print(f"split .text into {len(runs)} runs, {sum(1 for d in decoded.values() if d)} "
          f"of {len(decoded)} words as instructions; {len(cfuncs)} functions from C")


DATA_SECTIONS = (".vutext", ".data", ".rodata", ".gcc_except_table", ".lit4", ".sdata")


def write_data(elf):
    with open(os.path.join(ASM, "data.s"), "w") as f:
        for s in DATA_SECTIONS:
            sec = elf.section(s)
            f.write(f'.section .bin{s},"aw"\n'
                    f'.incbin "{EXE}", {sec["off"]}, {sec["size"]}\n')


def write_link(elf, order, funcs, cfuncs):
    os.makedirs(BUILD, exist_ok=True)
    text = elf.section(".text")
    lines = ["ENTRY(func_00100008)\nSECTIONS\n{\n", f"  .text {text['addr']:#x} : {{\n"]
    for o in order:
        if o[0] == "asm":
            lines.append(f"    */{os.path.basename(o[1])[:-2]}.o(.text)\n")
        else:
            lines.append(f"    */{o[1]}(.text.{o[2]})\n")
    lines.append("  } =0\n")
    for s in DATA_SECTIONS:
        sec = elf.section(s)
        lines.append(f"  {s}_out {sec['addr']:#x} : {{ *(.bin{s}) }}\n")
    for k, (obj, sec, addr) in enumerate(C_DATA_PLACED):
        lines.append(f"  .c_data{k} {addr:#x} : {{ */{obj}({sec}) }}\n")
    lines.append("  /DISCARD/ : { *(.MIPS.abiflags) *(.reginfo) *(.pdr) *(.comment) *(.mdebug*)"
                 " *(.data) *(.bss)"
                 " *(.text) *(.text.*) }\n}\n")  # C's own empty .text, unmarked functions
    # readable names for every function, func_XXXXXXXX for the ones now in C
    c_names = {n for _, n, _ in cfuncs.values()}
    counts = collections.Counter(n for _, n, _ in funcs)
    for addr, name, _ in funcs:  # names Ghidra repeats are left out: C uses func_XXXXXXXX
        if re.fullmatch(r"[A-Za-z_]\w*", name) and name not in c_names and counts[name] == 1:
            lines.append(f"PROVIDE({name} = {addr:#x});\n")
    for addr, (_, name, _) in sorted(cfuncs.items()):
        lines.append(f"func_{addr:08X} = {name};\n")
    from match import extra_symbols
    for name, addr in sorted(extra_symbols().items()):  # src/symbols.txt
        if name not in c_names:
            lines.append(f"PROVIDE({name} = {addr:#x});\n")
    # globals the C refers to as D_XXXXXXXX, and the original $gp (from .reginfo)
    used = set()
    for src in glob.glob(os.path.join(ROOT, "src", "**", "*.[ch]"), recursive=True):
        used |= set(re.findall(r"\bD_([0-9A-F]{8})\b", open(src).read()))
    for a in sorted(used):
        lines.append(f"PROVIDE(D_{a} = 0x{a});\n")
    gp = struct.unpack_from("<I", elf.data, elf.section(".reginfo")["off"] + 20)[0]
    lines.append(f"_gp = {gp:#x};\n")
    with open(os.path.join(BUILD, "link.ld"), "w") as f:
        f.writelines(lines)
    with open(os.path.join(BUILD, "objects.txt"), "w") as f:
        f.writelines(" ".join(map(str, o)) + "\n" for o in order)


def build():
    clang, lld = tool("CLANG", "clang"), tool("LLD", "ld.lld")
    objcopy = tool("OBJCOPY", "llvm-objcopy")
    order = [line.split() for line in open(os.path.join(BUILD, "objects.txt"))]
    align = {o[1]: o[2] for o in order if o[0] == "asm"}

    def assemble(rel):
        out = os.path.join(BUILD, rel[:-2] + ".o")
        os.makedirs(os.path.dirname(out), exist_ok=True)
        r = subprocess.run([clang] + ASFLAGS + [os.path.join(ROOT, rel), "-o", out],
                           capture_output=True, text=True)
        if not r.returncode and rel in align:
            # clang aligns .text to 16; the original only to 4 or 8
            r = subprocess.run([objcopy, f"--set-section-alignment=.text={align[rel]}", out],
                               capture_output=True, text=True)
        return rel, r.returncode, r.stderr

    c_functions()  # recompile src/*.c
    jobs = [o[1] for o in order if o[0] == "asm"] + [os.path.join("asm", "data.s")]
    with concurrent.futures.ThreadPoolExecutor(os.cpu_count()) as pool:
        for rel, rc, err in pool.map(assemble, jobs):
            if rc:
                raise SystemExit(f"{rel}:\n{err[:2000]}")
    linked = os.path.join(BUILD, "linked.elf")
    objs = [os.path.join(BUILD, o[:-2] + ".o") for o in jobs]
    objs += sorted({os.path.join(BUILD, "src", o[1]) for o in order if o[0] == "c"})
    subprocess.run([lld, "-T", os.path.join(BUILD, "link.ld"), "-o", linked,
                    "--no-check-sections", "-z", "norelro"] + objs, check=True)
    orig = Elf(open(EXE, "rb").read())
    new = bytearray(orig.data)
    ok = True
    for s in (".text",) + DATA_SECTIONS:
        sec = orig.section(s)
        name = ".text" if s == ".text" else s + "_out"
        dump = os.path.join(BUILD, "sec.bin")
        subprocess.run([objcopy, "-O", "binary", f"--only-section={name}", linked, dump], check=True)
        got = open(dump, "rb").read()
        want = orig.data[sec["off"]:sec["off"] + sec["size"]]
        if got != want:
            ok = False
            bad = next((i for i in range(min(len(got), len(want))) if got[i] != want[i]), min(len(got), len(want)))
            print(f"{s}: differs at {sec['addr'] + bad:#x} ({len(got)} vs {len(want)} bytes)")
            if s == ".text":
                c_ranges = [(int(o[3], 16), int(o[3], 16) + int(o[4])) for o in order if o[0] == "c"]
                record_mismatches(got, want, sec["addr"], c_ranges)
        new[sec["off"]:sec["off"] + len(got)] = got[:sec["size"]]
    # the C files' own data overlays the original's at the same address
    for k, (obj, sec, addr) in enumerate(C_DATA_PLACED):
        dump = os.path.join(BUILD, "sec.bin")
        subprocess.run([objcopy, "-O", "binary", f"--only-section=.c_data{k}", linked, dump], check=True)
        got = open(dump, "rb").read()
        host = next(orig.section(s) for s in DATA_SECTIONS
                    if orig.section(s)["addr"] <= addr < orig.section(s)["addr"] + orig.section(s)["size"])
        off = host["off"] + addr - host["addr"]
        if got != orig.data[off:off + len(got)]:
            ok = False
            print(f"{obj} {sec} at {addr:#x} differs from the original data")
        new[off:off + len(got)] = got
    out = os.path.join(BUILD, "SLES_508.91")
    open(out, "wb").write(new)
    h1, h2 = hashlib.sha1(new).hexdigest(), hashlib.sha1(orig.data).hexdigest()
    print(f"build/SLES_508.91 sha1 {h1}\noriginal          sha1 {h2}")
    print("MATCH" if ok and h1 == h2 else "DIFFERS")
    return ok and h1 == h2


def record_mismatches(got, want, base, c_ranges):
    """Remembers mis-assembled words so the next split writes them as .word.
    Words inside C functions are reported instead: the C has to be fixed."""
    bad = set()
    if os.path.exists(OVERRIDES):
        bad = {int(x, 16) for x in open(OVERRIDES).read().split()}
    if len(got) == len(want):
        for i in range(0, len(want), 4):
            a = base + i
            if got[i:i + 4] != want[i:i + 4]:
                c = next((r for r in c_ranges if r[0] <= a < r[1]), None)
                if c:
                    print(f"C function at {c[0]:#x} does not match (word {a:#x})")
                else:
                    bad.add(a)
    with open(OVERRIDES, "w") as f:
        f.write("\n".join(f"{a:08X}" for a in sorted(bad)) + "\n")
    print(f"recorded {len(bad)} words to write as .word; run split again")


def main(argv):
    if len(argv) != 2 or argv[1] not in ("split", "build", "all"):
        raise SystemExit(__doc__)
    if argv[1] in ("split", "all"):
        split()
    if argv[1] in ("build", "all"):
        sys.exit(0 if build() else 1)


if __name__ == "__main__":
    main(sys.argv)
