#!/usr/bin/env python3
"""Third pass of the tiny-function generator: straight-line code that gen_tiny.py
cannot express (64-bit and 128-bit loads/stores, float fields and floats passed
through, any order of independent stores) ending in a return or a tail call.
Every candidate is compiled with each compiler variant of the project and kept
only when it compiles to the original bytes. Writes src/gen3/<source file>.c.

Usage: gen_tiny3.py
"""
import csv
import glob
import itertools
import os
import re
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import asm_build
import ee_disasm
from gen_tiny2 import compile_check
from match import compare

ROOT = asm_build.ROOT
GEN = os.path.join(ROOT, "src", "gen3")
GP = 0x4A7C70
COMPILERS = [("991111-01", []), ("990721-r5900", ["-fno-thread-jumps"]), ("991111-01", ["-fexceptions"]),
             ("991111-01", ["-fno-gcse"])]
ITYPE = {"lw": "int", "lh": "s16", "lhu": "u16", "lb": "s8", "lbu": "u8", "ld": "u64", "lq": "u128", "lwc1": "float"}
STYPE = {"sw": "int", "sh": "s16", "sb": "s8", "sd": "u64", "sq": "u128", "swc1": "float"}
MEM = re.compile(r"\$(f?\d+), (-?\d+)\(\$(\d+)\)$")


def s16(x):
    return x - 0x10000 if x & 0x8000 else x


def decode(w, pc):
    op = w >> 26
    if op in (0x1E, 0x1F):  # lq / sq
        rs, rt, off = (w >> 21) & 31, (w >> 16) & 31, s16(w & 0xFFFF)
        return ("lq" if op == 0x1E else "sq"), f"${rt}, {off}(${rs})"
    d = ee_disasm.decode(w, pc)
    return (d[0], d[1]) if d else None


def translate(name, ins):
    """Returns (return type, params, statements, tail line, externs) or None."""
    if len(ins) < 2 or ins[-2][0] not in ("j", "jr"):
        return None
    jump, body = ins[-2], ins[:-2] + [ins[-1]]
    if jump[0] == "jr" and jump[1] != "$31":
        return None
    iregs = {r: f"a{r - 4}" for r in range(4, 12)}
    fregs = {r: f"f{r - 12}" for r in range(12, 20)}
    iregs[0] = "0"
    hi = {}
    iread, fread, iw, fw = set(), set(), set(), set()
    stmts, externs = [], set()

    def ival(r):
        if r in hi:
            return None
        if 4 <= r < 12 and r not in iw:
            iread.add(r)
        return iregs.get(r)

    def fval(r):
        if 12 <= r < 20 and r not in fw:
            fread.add(r)
        return fregs.get(r)

    def lval(t, m):
        r, off, base = m.group(1), int(m.group(2)), int(m.group(3))
        if base == 28:
            sym = f"D_{GP + off:08X}"
            externs.add(f"extern {t} {sym};")
            return sym
        if base in hi:
            a = hi[base] + off
            if a >> 16 == 0:
                return None
            sym = f"D_{a:08X}"
            externs.add(f"extern {t} {sym}[];")
            return f"{sym}[0]"
        b = ival(base)
        if b is None or b == "0":
            return None
        return f"FIELD({t}, {b}, {off:#x})"

    for mn, ops in body:
        regs = re.findall(r"\$(\d+)", ops)
        if mn == "nop":
            continue
        if mn == "lui":
            d, k = ops.split(", ")
            hi[int(d[1:])] = int(k, 16) << 16
            iw.add(int(d[1:]))
            continue
        if mn in ("addiu", "ori", "daddiu") and len(regs) == 2:
            d, sr = int(regs[0]), int(regs[1])
            k = int(ops.split(", ")[2], 0)
            if sr in hi and d == sr:
                v = hi.pop(sr) + (k if mn == "ori" else s16(k & 0xFFFF))
                if mn == "ori":
                    iregs[d] = f"{v:#x}"
                else:
                    externs.add(f"extern char D_{v:08X}[];")
                    iregs[d] = f"(int)D_{v:08X}"
                iw.add(d)
                continue
            if sr in hi or mn == "ori" and sr != 0:
                return None
            v = ival(sr)
            if v is None or d in (29,) or sr == 29:
                return None
            hi.pop(d, None)
            iregs[d] = str(k) if sr == 0 else f"({v} + {k})"
            iw.add(d)
            continue
        if mn == "daddu" and len(regs) == 3 and regs[2] == "0":
            d, sr = int(regs[0]), int(regs[1])
            v = ival(sr)
            if v is None:
                return None
            hi.pop(d, None)
            iregs[d] = v
            iw.add(d)
            continue
        m = MEM.match(ops)
        if m and mn in ITYPE:
            t = ITYPE[mn]
            lv = lval(t, m)
            if lv is None:
                return None
            if mn == "lwc1":
                fregs[int(m.group(1)[1:])] = lv
                fw.add(int(m.group(1)[1:]))
            else:
                r = int(m.group(1))
                if r in (29, 31):
                    return None
                hi.pop(r, None)
                iregs[r] = lv
                iw.add(r)
            continue
        if m and mn in STYPE:
            t = STYPE[mn]
            lv = lval(t, m)
            if lv is None:
                return None
            if mn == "swc1":
                v = fval(int(m.group(1)[1:]))
            else:
                v = ival(int(m.group(1)))
            if v is None:
                return None
            stmts.append(f"    {lv} = {v};")
            continue
        return None
    tail = None
    tailcall = None
    ret = "void"
    if jump[0] == "j":
        m = re.fullmatch(r"func_([0-9A-F]{8})", jump[1])
        if not m:
            return None
        callee = f"func_{m.group(1)}"
        li = max([r for r in range(4, 12) if r in iw or r in iread], default=3)
        lf = max([r for r in range(12, 20) if r in fw or r in fread], default=11)
        args = []
        for r in range(4, li + 1):
            v = ival(r)
            if v is None:
                return None
            args.append(v)
        for r in range(12, lf + 1):
            v = fval(r)
            if v is None:
                return None
            args.append(v)
        tail = f"    {callee}({', '.join(args)});"
        tailcall = (callee, args)
        externs.add(f"void {callee}();")
    else:
        if 2 in iw:
            v = ival(2)
            if v is None:
                return None
            tail = f"    return {v};"
            ret = "int"
        elif 0 in fw:
            tail = f"    return {fval(0)};"
            ret = "float"
    if not stmts and not tail:
        return None
    ni = max(iread, default=3) - 3
    nf = max(fread, default=11) - 11
    params = [f"int a{i}" for i in range(ni)] + [f"float f{i}" for i in range(nf)]
    return ret, name, ", ".join(params) or "void", stmts, tail, sorted(externs), tailcall


def variants(t):
    ret, name, params, stmts, tail, ex, tailcall = t
    out = []
    tails = [(tail, ex)]
    if tailcall:
        callee, args = tailcall
        for k in range(len(args) - 1, -1, -1):
            tails.append((f"    {callee}({', '.join(args[:k])});", ex))
    n = len(stmts)
    perms = itertools.permutations(stmts) if n <= 5 else [tuple(stmts[k:] + stmts[:k]) for k in range(n)] + [tuple(stmts[::-1])]
    for p in perms:
        for tail, ex in tails:
            body = list(p) + ([tail] if tail else [])
            out.append((f"{ret} {name}({params})\n{{\n" + "\n".join(body) + "\n}\n", ex))
            if tail and tail.lstrip().startswith("return") and p:
                out.append((f"void {name}({params})\n{{\n" + "\n".join(p) + "\n}\n", ex))
            if tail and re.match(r"\s+func_[0-9A-F]{8}\(", tail):
                rt = "    return " + tail.lstrip()
                ex2 = [e.replace("void func_", "int func_") if e.startswith("void func_") else e for e in ex]
                out.append((f"int {name}({params})\n{{\n" + "\n".join(list(p) + [rt]) + "\n}\n", ex2))
    return out


def main():
    elf = asm_build.Elf(open(asm_build.EXE, "rb").read())
    text = elf.section(".text")
    code = elf.data[text["off"]:text["off"] + text["size"]]
    rows = list(csv.DictReader(open(os.path.join(ROOT, "decomp", "functions.csv"))))
    done = set()
    for path in glob.glob(os.path.join(ROOT, "src", "**", "*.c"), recursive=True):
        if path.startswith(GEN):
            continue
        done |= {int(a, 16) for a in re.findall(r"func_([0-9A-Fa-f]{8})", open(path).read())}
    count = {}
    for r in rows:
        count[r["name"]] = count.get(r["name"], 0) + 1
    cands = []
    for r in rows:
        if count[r["name"]] > 1:
            continue
        addr, size, name = int(r["address"], 16), int(r["size_bytes"]), r["name"]
        if addr in done or size > 96 or not re.fullmatch(r"[A-Za-z_]\w*", name):
            continue
        if not text["addr"] <= addr < text["addr"] + text["size"]:
            continue
        ins = []
        words = struct.unpack_from(f"<{size // 4}I", code, addr - text["addr"])
        for i, w in enumerate(words):
            d = decode(w, addr + 4 * i)
            if d is None:
                break
            ins.append(d)
        else:
            while len(ins) > 2 and ins[-1] == ("nop", "") and ins[-2][0] not in ("jr", "j"):
                ins.pop()
            t = translate(name, ins)
            if t:
                for v, ex in variants(t):
                    cands.append((addr, name, v, ex, r["group"] or "none"))
    print(len(cands), "variants")
    found = {}
    for compiler, extra in COMPILERS:
        pending = [c for c in cands if c[0] not in found]
        rounds = {}
        seen = {}
        for c in pending:
            k = seen.get(c[0], 0)
            seen[c[0]] = k + 1
            rounds.setdefault(k, []).append(c)
        for k, lst in sorted(rounds.items()):
            ok = compile_check([(a, n, v, ex) for a, n, v, ex, g in lst], compiler, extra)
            for a, n, v, ex, g in lst:
                if a in ok and a not in found:
                    found[a] = (n, v, ex, g, compiler, extra)
        print(compiler, extra, len(found), flush=True)
    os.makedirs(GEN, exist_ok=True)
    for old in glob.glob(os.path.join(GEN, "*.c")):
        os.remove(old)
    groups = {}
    for a, (n, v, ex, g, comp, extra) in found.items():
        groups.setdefault((g, comp, tuple(extra)), []).append((a, n, v, ex))
    for (g, comp, extra), fl in sorted(groups.items()):
        tag = re.sub(r"[^A-Za-z0-9_]", "_", g) + ("_" + comp.replace("-", "") if comp != "991111-01" else "") + "".join("_" + e.strip("-").replace("-", "") for e in extra)
        decl = {}
        for a, n, v, ex in fl:
            for e in ex:
                decl.setdefault(re.search(r"(\w+)(\[\])?(\(\))?;$", e).group(1), e)
        with open(os.path.join(GEN, tag + ".c"), "w") as f:
            f.write(f"/* {g}: tiny functions generated by tools/gen_tiny3.py from their instructions. */\n")
            if comp != "991111-01":
                f.write(f"// compiler: {comp}\n")
            if extra:
                f.write(f"// cflags: {' '.join(extra)}\n")
            f.write('#include "../common.h"\n\ntypedef int u128 __attribute__((mode(TI)));\n\n' + "\n".join(sorted(decl.values())) + "\n\n")
            for a, n, v, ex in sorted(fl):
                f.write(f"// MATCH func_{a:08X}\n{v}\n")
    print("wrote", len(found), "functions")


if __name__ == "__main__":
    main()
