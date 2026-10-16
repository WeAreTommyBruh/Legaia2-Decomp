#!/usr/bin/env python3
"""Writes C for the game's tiny functions from their instruction patterns
and keeps the ones that compile to the original bytes.

Covers empty functions, constant returns, field getters and setters
(`return FIELD(int, p, 0x24);`, `FIELD(u8, p, 0x10) = v;`) and getters and
setters of globals, absolute (`D_XXXXXXXX[]`) or gp-relative
(`D_XXXXXXXX`). Every candidate is compiled with ee-gcc 2.9-ee-991111-01 -O2 -G8 and
compared word by word with the original; only exact matches are written,
marked `// MATCH func_XXXXXXXX`, to src/gen/<source file>.c (one file per
source group of decomp/functions.csv). Functions already written by hand
elsewhere in src/ are skipped. The files are regenerated from scratch each
run; `tools/asm_build.py all` then checks the whole executable.

Tail calls (`j func`) and the SDK's syscall stubs are left alone: a tail call
does not show how many arguments are passed on, and the stubs are assembly.

Usage: gen_tiny.py
"""

import csv
import glob
import os
import re
import struct
import subprocess
import sys
import tempfile

import asm_build
import ee_disasm
from match import function_bytes

ROOT = asm_build.ROOT
GEN = os.path.join(ROOT, "src", "gen")
GP = 0x4A7C70  # from .reginfo
LOADS = {"lw": "int", "lb": "s8", "lbu": "u8", "lh": "s16", "lhu": "u16"}
STORES = {"sw": "int", "sb": "s8", "sh": "s16"}
MEM = re.compile(r"\$(\d+), (-?\d+)\(\$(\d+)\)$")
FMEM = re.compile(r"\$f(\d+), (-?\d+)\(\$(\d+)\)$")


def s16(x):
    return x - 0x10000 if x & 0x8000 else x


def translate(name, ins):
    """Returns (C source, extern declarations) or None."""
    if len(ins) == 2 and ins[0] == ("jr", "$31"):
        mn, ops = ins[1]
        if mn == "nop":
            return f"void {name}(void)\n{{\n}}\n", []
        if mn == "daddu" and ops == "$2, $0, $0":
            return f"int {name}(void)\n{{\n    return 0;\n}}\n", []
        if mn == "addiu" and ops.startswith("$2, $0, "):
            return f"int {name}(void)\n{{\n    return {ops[8:]};\n}}\n", []
        if mn == "daddu" and ops == "$2, $4, $0":
            return f"int {name}(int a)\n{{\n    return a;\n}}\n", []
        if mn == "addiu" and ops.startswith("$2, $4, "):
            return f"int {name}(int a)\n{{\n    return a + {ops[8:]};\n}}\n", []
        m = MEM.match(ops)
        if mn in LOADS and m and m.group(1) == "2":
            off, base = int(m.group(2)), m.group(3)
            t = LOADS[mn]
            if base == "4":
                return f"{t} {name}(void *p)\n{{\n    return FIELD({t}, p, {off:#x});\n}}\n", []
            if base == "28":
                sym = f"D_{GP + off:08X}"
                return (f"{t} {name}(void)\n{{\n    return {sym};\n}}\n", [f"extern {t} {sym};"])
        m = FMEM.match(ops)
        if mn == "lwc1" and m and m.group(1) == "0" and m.group(3) == "4":
            return f"float {name}(void *p)\n{{\n    return FIELD(float, p, {int(m.group(2)):#x});\n}}\n", []
        if mn == "swc1" and m and m.group(1) == "12" and m.group(3) == "4":
            return (f"void {name}(void *p, float v)\n{{\n    FIELD(float, p, {int(m.group(2)):#x}) = v;\n}}\n", [])
        m = MEM.match(ops)
        if mn in STORES and m:
            src, off, base = m.group(1), int(m.group(2)), m.group(3)
            t = STORES[mn]
            if base == "4" and src in ("5", "0"):
                if src == "0":
                    return f"void {name}(void *p)\n{{\n    FIELD({t}, p, {off:#x}) = 0;\n}}\n", []
                return f"void {name}(void *p, {t} v)\n{{\n    FIELD({t}, p, {off:#x}) = v;\n}}\n", []
            if base == "28" and src in ("4", "0"):
                sym = f"D_{GP + off:08X}"
                body = "0" if src == "0" else "v"
                arg = "void" if src == "0" else f"{t} v"
                return (f"void {name}({arg})\n{{\n    {sym} = {body};\n}}\n", [f"extern {t} {sym};"])
    if len(ins) == 3 and ins[1] == ("jr", "$31"):
        (m0, o0), (m2, o2) = ins[0], ins[2]
        m = MEM.match(o2)
        # li $2, K ; jr ; sw $2, off($4 or $28)
        if m0 == "addiu" and o0.startswith("$2, $0, ") and m2 in STORES and m and m.group(1) == "2":
            k, off, base, t = o0[8:], int(m.group(2)), m.group(3), STORES[m2]
            if base == "4":
                return f"void {name}(void *p)\n{{\n    FIELD({t}, p, {off:#x}) = {k};\n}}\n", []
            if base == "28":
                sym = f"D_{GP + off:08X}"
                return f"void {name}(void)\n{{\n    {sym} = {k};\n}}\n", [f"extern {t} {sym};"]
        # lui $3, hi ; jr ; lw $2, lo($3)  (a global that is not small data)
        if m0 == "lui" and o0.startswith("$3, ") and m2 in LOADS and m and m.group(1) == "2" and m.group(3) == "3":
            addr = (int(o0[4:], 16) << 16) + int(m.group(2))
            t = LOADS[m2]
            sym = f"D_{addr:08X}"
            return f"{t} {name}(void)\n{{\n    return {sym}[0];\n}}\n", [f"extern {t} {sym}[];"]
        # lui $2, hi ; jr ; addiu $2, $2, lo  (address of a global)
        if m0 == "lui" and o0.startswith("$2, ") and m2 == "addiu" and o2.startswith("$2, $2, "):
            addr = (int(o0[4:], 16) << 16) + int(o2[8:])
            sym = f"D_{addr:08X}"
            return f"void *{name}(void)\n{{\n    return {sym};\n}}\n", [f"extern char {sym}[];"]
    return None


def main():
    elf = asm_build.Elf(open(asm_build.EXE, "rb").read())
    text = elf.section(".text")
    code = elf.data[text["off"]:text["off"] + text["size"]]
    with open(os.path.join(ROOT, "decomp", "functions.csv")) as f:
        rows = list(csv.DictReader(f))
    for old in glob.glob(os.path.join(GEN, "*.c")):
        os.remove(old)
    hand = set()
    for path in glob.glob(os.path.join(ROOT, "src", "*.c")):
        hand |= {int(a, 16) for a in re.findall(r"func_([0-9A-Fa-f]{8})", open(path).read())}

    groups = {}
    for r in rows:
        addr, size, name = int(r["address"], 16), int(r["size_bytes"]), r["name"]
        if addr % 8 or addr in hand or size > 16 or not re.fullmatch(r"[A-Za-z_]\w*", name):
            continue
        if not text["addr"] <= addr < text["addr"] + text["size"]:
            continue
        words = struct.unpack_from(f"<{size // 4}I", code, addr - text["addr"])
        ins = []
        for i, w in enumerate(words):
            d = ee_disasm.decode(w, addr + 4 * i)
            if d is None:
                break
            ins.append((d[0], d[1]))
        else:
            # trailing alignment nops after a 3-instruction body
            while len(ins) > 2 and ins[-1] == ("nop", "") and ins[-2] != ("jr", "$31"):
                ins.pop()
            c = translate(name, ins)
            if c:
                groups.setdefault(r["group"] or "none", []).append((addr, name, c))

    os.makedirs(GEN, exist_ok=True)
    total = 0
    for group, funcs in sorted(groups.items()):
        kept = check(funcs)
        if not kept:
            continue
        externs = sorted({e for _, _, (_, ex) in kept for e in ex})
        path = os.path.join(GEN, re.sub(r"[^A-Za-z0-9_]", "_", group) + ".c")
        with open(path, "w") as f:
            f.write(f"/* {group}: tiny functions generated by tools/gen_tiny.py from their\n"
                    "   instructions; each compiles to the original bytes. */\n"
                    '#include "../common.h"\n\n')
            if externs:
                f.write("\n".join(externs) + "\n\n")
            for addr, name, (src, _) in kept:
                f.write(f"// MATCH func_{addr:08X}\n{src}\n")
        total += len(kept)
    print(f"wrote {total} matching functions to {len(os.listdir(GEN))} files in src/gen")


def check(funcs):
    """Compiles the candidates together and keeps the exact matches."""
    with tempfile.TemporaryDirectory() as tmp:
        src = os.path.join(tmp, "t.c")
        externs = sorted({e for _, _, (_, ex) in funcs for e in ex})
        with open(src, "w") as f:
            f.write(f'#include "{os.path.join(ROOT, "src", "common.h")}"\n' + "\n".join(externs) + "\n")
            for _, _, (c, _) in funcs:
                f.write(c)
        obj = os.path.join(tmp, "t.o")
        r = subprocess.run([asm_build.EE_CC, "-c", *asm_build.CFLAGS, "-o", obj, src],
                           capture_output=True, text=True)
        if r.returncode:
            print(r.stderr[:1500])
            return []
        orig = open(asm_build.EXE, "rb").read()
        text = asm_build.Elf(orig).section(".text")
        kept = []
        for addr, name, c in funcs:
            words, masks = function_bytes(obj, name)
            while len(words) > 1 and words[-1] == 0 and masks[-1] == 0:
                words.pop(), masks.pop()
            want = struct.unpack_from(f"<{len(words)}I", orig, text["off"] + addr - text["addr"])
            if all((w & ~m) == (o & ~m) for w, m, o in zip(words, masks, want)):
                kept.append((addr, name, c))
        return kept


if __name__ == "__main__":
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    main()
