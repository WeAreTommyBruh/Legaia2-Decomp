#!/usr/bin/env python3
"""Rebuilds the game executable (SLES_508.91) from disassembly and checks that
it is byte-identical to the original.

split   disassembles .text into asm/NNN_<source>.s, one file per contiguous
        run of functions attributed to the same source file (from
        decomp/functions.csv), and writes asm/data.s (the other sections,
        included from the original executable) and build/link.ld.
build   assembles everything with clang, links with ld.lld at
        the original addresses, writes build/SLES_508.91 and compares it with
        disc/SLES_508.91 section by section and as a whole file.

Every instruction is written as clang-compatible assembly where ee_disasm.py
can decode it and as a .word otherwise; if a decoded instruction assembles to
different bytes, split remembers its address (build/word_overrides.txt) and
writes it as a .word next time. Branch targets get local labels and jal/j
targets global func_XXXXXXXX labels, so calls are real relocations.
The ELF headers are generated from the original's layout; only the section
contents are rebuilt.

Needs clang and ld.lld with the MIPS target ($CLANG, $LLD; found on PATH or
in the retcomm toolchain otherwise). Generated files (asm/, build/) contain
game code and are git-ignored.

Usage: asm_build.py split | build | all
"""

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
ASFLAGS = ["-target", "mips64el-unknown-none", "-mcpu=mips4", "-mabi=n32",
           "-mno-abicalls", "-fno-pic", "-c"]
HEADER = ".set noreorder\n.set noat\n.set nomacro\n"


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
    for i, r in enumerate(runs):
        name = f"{i:03d}_{re.sub(r'[^A-Za-z0-9_]', '_', r['group'] or 'none')}.s"
        lines = [HEADER, ".text\n"]
        names = {a: n for a, _, n in r["funcs"]}
        for a in range(r["start"], r["end"], 4):
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
        with open(os.path.join(ASM, name), "w") as f:
            f.writelines(lines)
        order.append(os.path.join("asm", name))
    write_data(elf)
    write_link(elf, order)
    print(f"split .text into {len(runs)} runs, {sum(1 for d in decoded.values() if d)} "
          f"of {len(decoded)} words as instructions")


DATA_SECTIONS = (".vutext", ".data", ".rodata", ".gcc_except_table", ".lit4", ".sdata")


def write_data(elf):
    with open(os.path.join(ASM, "data.s"), "w") as f:
        for s in DATA_SECTIONS:
            sec = elf.section(s)
            f.write(f'.section .bin{s},"aw"\n'
                    f'.incbin "{EXE}", {sec["off"]}, {sec["size"]}\n')


def write_link(elf, order):
    os.makedirs(BUILD, exist_ok=True)
    text = elf.section(".text")
    lines = ["ENTRY(func_00100008)\nSECTIONS\n{\n",
             f"  .text {text['addr']:#x} : SUBALIGN(4) {{\n"]
    lines.append("    *(.text)\n  }\n")  # objects are given to ld.lld in address order
    for s in DATA_SECTIONS:
        sec = elf.section(s)
        lines.append(f"  {s}_out {sec['addr']:#x} : {{ *(.bin{s}) }}\n")
    lines.append("  /DISCARD/ : { *(.MIPS.abiflags) *(.reginfo) *(.pdr) *(.comment) }\n}\n")
    with open(os.path.join(BUILD, "link.ld"), "w") as f:
        f.writelines(lines)
    with open(os.path.join(BUILD, "objects.txt"), "w") as f:
        f.write("\n".join(order) + "\n")


def build():
    clang, lld = tool("CLANG", "clang"), tool("LLD", "ld.lld")
    objcopy = tool("OBJCOPY", "llvm-objcopy")
    order = open(os.path.join(BUILD, "objects.txt")).read().split()

    def assemble(rel):
        out = os.path.join(BUILD, rel[:-2] + ".o")
        os.makedirs(os.path.dirname(out), exist_ok=True)
        r = subprocess.run([clang] + ASFLAGS + [os.path.join(ROOT, rel), "-o", out],
                           capture_output=True, text=True)
        return rel, r.returncode, r.stderr

    jobs = order + [os.path.join("asm", "data.s")]
    with concurrent.futures.ThreadPoolExecutor(os.cpu_count()) as pool:
        for rel, rc, err in pool.map(assemble, jobs):
            if rc:
                raise SystemExit(f"{rel}:\n{err[:2000]}")
    linked = os.path.join(BUILD, "linked.elf")
    objs = [os.path.join(BUILD, o[:-2] + ".o") for o in jobs]
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
                record_mismatches(got, want, sec["addr"])
        new[sec["off"]:sec["off"] + len(got)] = got[:sec["size"]]
    out = os.path.join(BUILD, "SLES_508.91")
    open(out, "wb").write(new)
    h1, h2 = hashlib.sha1(new).hexdigest(), hashlib.sha1(orig.data).hexdigest()
    print(f"build/SLES_508.91 sha1 {h1}\noriginal          sha1 {h2}")
    print("MATCH" if ok and h1 == h2 else "DIFFERS")
    return ok and h1 == h2


def record_mismatches(got, want, base):
    """Remembers mis-assembled words so the next split writes them as .word."""
    bad = set()
    if os.path.exists(OVERRIDES):
        bad = {int(x, 16) for x in open(OVERRIDES).read().split()}
    if len(got) == len(want):
        for i in range(0, len(want), 4):
            if got[i:i + 4] != want[i:i + 4]:
                bad.add(base + i)
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
