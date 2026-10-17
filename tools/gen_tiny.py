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

Straight-line code up to 8 instructions (moves, constants, loads and stores
of globals and of fields of the arguments) ending in a return or a tail call
(`j func`) is translated too; a tail call passes on every argument register
up to the last one the code sets. The SDK's syscall stubs are left alone:
they are assembly.

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
from match import compare

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


ARGS = range(4, 12)  # $a0-$a7 (EABI)
SIZES = {"w": ("int", 4), "h": ("s16", 2), "hu": ("u16", 2), "b": ("s8", 1), "bu": ("u8", 1)}


def straight_line(name, ins, addr):
    """C for straight-line code (moves, constants, loads and stores of
    globals and of fields of the arguments) that ends in a return or in a
    tail call (`j func`); returns (C source, extern declarations) or None.
    Arguments the code does not touch are passed on as they are, so a tail
    call passes every argument register up to the last one written."""
    if len(ins) < 2 or ins[-2][0] not in ("j", "jr"):
        return None
    jump, body = ins[-2], ins[:-2] + [ins[-1]]  # the delay slot runs before the jump
    if jump[0] == "jr" and jump[1] != "$31":
        return None
    regs = {r: f"a{r - 4}" for r in ARGS}
    regs[0] = "0"
    hi = {}  # registers holding a lui value
    read, written, stmts, externs = set(), set(), [], set()

    def val(r):
        if r in hi:
            return None
        if r in ARGS and r not in written:
            read.add(r)
        return regs.get(r)

    def global_at(a, t):
        sym = f"D_{a:08X}"
        if a >> 16 == 0:
            return None
        externs.add(f"extern {t} {sym}[];")
        return f"{sym}[0]"

    def mem(op, m):
        """C lvalue for `off($base)` of a load or store of type t."""
        r, off, base = int(m.group(1)), int(m.group(2)), int(m.group(3))
        t = op
        if base == 28:
            sym = f"D_{GP + off:08X}"
            externs.add(f"extern {t} {sym};")
            return r, sym
        if base in hi:
            return r, global_at(hi[base] + off, t)
        b = val(base)
        if b is None or b == "0":
            return r, None
        return r, f"FIELD({t}, {b}, {off:#x})"
    for mn, ops in body:
        regs_in = [int(x) for x in re.findall(r"\$(\d+)", ops)]
        if mn == "nop":
            continue
        if mn == "lui":
            d, k = ops.split(", ")
            d = int(d[1:])
            hi[d] = int(k, 16) << 16
            written.add(d)
            continue
        if mn in ("addiu", "ori") and len(regs_in) == 2:
            d, src_r = regs_in
            k = int(ops.split(", ")[2], 0)
            if src_r in hi and d == src_r:
                v = hi.pop(src_r) + (k if mn == "ori" else s16(k & 0xFFFF))
                if mn == "addiu":
                    externs.add(f"extern char D_{v:08X}[];")
                    regs[d] = f"(int)D_{v:08X}"
                else:
                    regs[d] = f"{v:#x}"
                written.add(d)
                continue
            if mn == "ori" or src_r in hi:
                return None
            v = val(src_r)
            if v is None or src_r == 29 or d == 29:
                return None
            hi.pop(d, None)
            regs[d] = str(k) if src_r == 0 else f"({v} + {k})"
            written.add(d)
            continue
        if mn == "daddu" and len(regs_in) == 3 and regs_in[2] == 0:
            d, src_r = regs_in[:2]
            v = val(src_r)
            if v is None:
                return None
            hi.pop(d, None)
            regs[d] = v
            written.add(d)
            continue
        m = MEM.match(ops)
        if m and mn[0] == "l" and mn[1:] in SIZES:
            t = SIZES[mn[1:]][0]
            r, lv = mem(t, m)
            if lv is None or r in (29, 31):
                return None
            hi.pop(r, None)
            regs[r] = lv
            written.add(r)
            continue
        if m and mn[0] == "s" and mn[1:] in ("w", "h", "b"):
            t = SIZES[mn[1:]][0]
            r, lv = mem(t, m)
            v = val(r)
            if lv is None or v is None:
                return None
            stmts.append(f"    {lv} = {v};\n")
            continue
        return None
    if jump[0] == "j":
        m = re.fullmatch(r"func_([0-9A-F]{8})", jump[1])
        if not m:
            return None
        callee = f"func_{m.group(1)}"
        last = max([r for r in ARGS if r in written], default=3)
        args = [val(r) for r in range(4, last + 1)]
        if any(a is None for a in args):
            return None
        stmts.append(f"    {callee}({', '.join(args)});\n")
        externs.add(f"void {callee}();")
        ret = "void"
    else:
        ret = "void"
        if 2 in written:
            v = val(2)
            if v is None:
                return None
            stmts.append(f"    return {v};\n")
            ret = "int"
    if not stmts:
        return None
    nparams = max(read, default=3) - 3
    params = ", ".join(f"int a{i}" for i in range(nparams)) or "void"
    return f"{ret} {name}({params})\n{{\n{''.join(stmts)}}}\n", sorted(externs)


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

    count = {}
    for r in rows:
        count[r["name"]] = count.get(r["name"], 0) + 1
    groups = {}
    for r in rows:
        if count[r["name"]] > 1:  # a name Ghidra gives to several functions
            continue
        addr, size, name = int(r["address"], 16), int(r["size_bytes"]), r["name"]
        if addr % 8 or addr in hand or size > 32 or not re.fullmatch(r"[A-Za-z_]\w*", name):
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
            while len(ins) > 2 and ins[-1] == ("nop", "") and ins[-2][0] not in ("jr", "j"):
                ins.pop()
            c = (translate(name, ins) if size <= 16 else None) or straight_line(name, ins, addr)
            if c:
                groups.setdefault(r["group"] or "none", []).append((addr, name, c))

    os.makedirs(GEN, exist_ok=True)
    total = 0
    for group, funcs in sorted(groups.items()):
        kept = check(funcs)
        # one file per group, more when two functions declare a symbol differently
        files = []
        for fn in kept:
            decl = {re.search(r"(\w+)(\[\])?(\(\))?;$", e).group(1): e for e in fn[2][1]}
            for fl in files:
                if all(fl["decl"].get(k, e) == e for k, e in decl.items()):
                    break
            else:
                fl = {"decl": {}, "funcs": []}
                files.append(fl)
            fl["decl"].update(decl)
            fl["funcs"].append(fn)
        for k, fl in enumerate(files):
            base = re.sub(r"[^A-Za-z0-9_]", "_", group) + (f"_{k}" if k else "")
            with open(os.path.join(GEN, base + ".c"), "w") as f:
                f.write(f"/* {group}: tiny functions generated by tools/gen_tiny.py from their\n"
                        "   instructions; each compiles to the original bytes. */\n"
                        '#include "../common.h"\n\n')
                if fl["decl"]:
                    f.write("\n".join(sorted(fl["decl"].values())) + "\n\n")
                for addr, name, (src, _) in fl["funcs"]:
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
        if r.returncode:  # declarations that clash: one function at a time
            return [f for f in funcs if len(funcs) > 1 and check([f])]
        kept = []
        for addr, name, c in funcs:
            if compare(obj, name, addr)[0] == 0:
                kept.append((addr, name, c))
        return kept


if __name__ == "__main__":
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    main()
