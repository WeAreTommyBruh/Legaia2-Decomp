#!/usr/bin/env python3
"""Writes C for the accessors of function-local statics, `T *get() { static T t; if (!t) init(&t, ...); return &t; }`
as compiled by the game's compiler: the first word of the object is the guard, the object is
registered through the SDK's atexit-style helper. Three instruction shapes are recognised;
the exact matches go to src/gen_static/<group>.c.

Usage: gen_static.py
"""
import csv, glob, os, re, struct, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import asm_build, ee_disasm
from gen_tiny2 import compile_check

ROOT = asm_build.ROOT
OUT = os.path.join(ROOT, "src", "gen_static")
GP = 0x4A7C70


def s16(x):
    return x - 0x10000 if x & 0x8000 else x


def hl(h, l):
    return (int(h, 16) << 16) + s16(int(l) & 0xFFFF) if int(l) >= 0 else (int(h, 16) << 16) + int(l)


def shape(ins):
    """Returns (kind, params) or None."""
    t = [f"{m} {o}".strip() for m, o in ins]
    n = len(t)
    pat1 = [r"addiu \$29, \$29, -32", r"lw \$2, (-?\d+)\(\$28\)", r"sd \$16, 0\(\$29\)", r"addiu \$16, \$28, (-?\d+)",
            r"bne \$2, \$0, \.L\w+", r"sd \$31, 16\(\$29\)", r"lui \$5, (0x[0-9a-f]+)", r"daddu \$4, \$16, \$0", r"jal (func_\w+)",
            r"addiu \$5, \$5, (-?\d+)", r"daddu \$2, \$16, \$0", r"ld \$31, 16\(\$29\)", r"ld \$16, 0\(\$29\)", r"jr \$31", r"addiu \$29, \$29, 32"]
    if n == 15:
        g = []
        for p, x in zip(pat1, t):
            m = re.fullmatch(p, x)
            if not m:
                break
            g += list(m.groups())
        else:
            if g[0] == g[1]:
                return "S1", dict(off=int(g[0]), hi=g[2], f=g[3], lo=g[4])
    pat2 = [r"addiu \$29, \$29, -32", r"lui \$3, (0x[0-9a-f]+)", r"sd \$16, 0\(\$29\)", r"lw \$2, (-?\d+)\(\$3\)", r"addiu \$16, \$3, (-?\d+)",
            r"bne \$2, \$0, \.L\w+", r"sd \$31, 16\(\$29\)", r"jal (func_\w+)", r"nop"]
    if n in (19, 20) and all(re.fullmatch(p, x) for p, x in zip(pat2, t[:9])):
        g = [re.fullmatch(p, x).groups() for p, x in zip(pat2, t[:9])]
        h, l1, l2, g1 = g[1][0], g[3][0], g[4][0], g[7][0]
        if l1 == l2:
            rest = t[9:]
            if n == 19:
                p3 = [r"lui \$5, (0x[0-9a-f]+)", r"daddu \$4, \$16, \$0", r"addiu \$6, \$28, (-?\d+)", r"jal (func_\w+)", r"addiu \$5, \$5, (-?\d+)"]
                gg = []
                for p, x in zip(p3, rest):
                    m = re.fullmatch(p, x)
                    if not m:
                        break
                    gg += list(m.groups())
                else:
                    return "S2", dict(hi=h, lo=int(l1), g=g1, shi=gg[0], goff=int(gg[1]), f=gg[2], slo=int(gg[3]))
            else:
                p3 = [r"lui \$5, (0x[0-9a-f]+)", r"lui \$6, (0x[0-9a-f]+)", r"addiu \$5, \$5, (-?\d+)", r"addiu \$6, \$6, (-?\d+)", r"jal (func_\w+)", r"daddu \$4, \$16, \$0"]
                gg = []
                for p, x in zip(p3, rest):
                    m = re.fullmatch(p, x)
                    if not m:
                        break
                    gg += list(m.groups())
                else:
                    return "S3", dict(hi=h, lo=int(l1), g=g1, shi=gg[0], bhi=gg[1], slo=int(gg[2]), blo=int(gg[3]), f=gg[4])
    return None


def abs_(h, l):
    return (int(h, 16) << 16) + int(l)


def build(name, kind, p):
    ex = [] ; body = ""
    if kind == "S1":
        obj = f"D_{GP + p['off']:08X}"; s = abs_(p["hi"], p["lo"]); st = f"D_{s:08X}"
        ex = [f"extern int {obj};", f"extern char {st}[];", f"void {p['f']}();"]
        body = f"    int *p = &{obj};\n\n    if ({obj} == 0)\n        {p['f']}(p, {st});\n    return p;"
    elif kind == "S2":
        a = abs_(p["hi"], p["lo"]); obj = f"D_{a:08X}"; s = abs_(p["shi"], p["slo"]); st = f"D_{s:08X}"; gp = f"D_{GP + p['goff']:08X}"
        ex = [f"extern int {obj}[4];", f"extern char {st}[];", f"extern int {gp};", f"void {p['g']}();", f"void {p['f']}();"]
        body = f"    int *p = {obj};\n\n    if (p[0] == 0) {{\n        {p['g']}();\n        {p['f']}(p, {st}, &{gp});\n    }}\n    return p;"
    else:
        a = abs_(p["hi"], p["lo"]); obj = f"D_{a:08X}"; s = abs_(p["shi"], p["slo"]); st = f"D_{s:08X}"; b = abs_(p["bhi"], p["blo"]); ob = f"D_{b:08X}"
        ex = [f"extern int {obj}[4];", f"extern char {st}[];", f"extern int {ob}[4];", f"void {p['g']}();", f"void {p['f']}();"]
        body = f"    int *p = {obj};\n\n    if (p[0] == 0) {{\n        {p['g']}();\n        {p['f']}(p, {st}, {ob});\n    }}\n    return p;"
    return ex, body


def main():
    elf = asm_build.Elf(open(asm_build.EXE, "rb").read())
    text = elf.section(".text")
    code = elf.data[text["off"]:text["off"] + text["size"]]
    rows = list(csv.DictReader(open(os.path.join(ROOT, "decomp", "functions.csv"))))
    done = set()
    for path in glob.glob(os.path.join(ROOT, "src", "**", "*.c"), recursive=True):
        if path.startswith(OUT):
            continue
        done |= {int(a, 16) for a in re.findall(r"MATCH\s+func_([0-9A-Fa-f]{8})", open(path).read())}
    count = {}
    for r in rows:
        count[r["name"]] = count.get(r["name"], 0) + 1
    found = {}
    tried = 0
    for r in rows:
        addr, size, name = int(r["address"], 16), int(r["size_bytes"]), r["name"]
        if count[name] > 1:
            name = f"dup_{addr:08x}"
        if addr in done or size not in (60, 76, 80) or not re.fullmatch(r"[A-Za-z_]\w*", name):
            continue
        ws = struct.unpack_from(f"<{size // 4}I", code, addr - text["addr"])
        ins = [ee_disasm.decode(w, addr + 4 * i) for i, w in enumerate(ws)]
        if any(i is None for i in ins):
            continue
        ins = [(i[0], i[1]) for i in ins]
        sh = shape(ins)
        if not sh:
            continue
        tried += 1
        kind, p = sh
        ex, body = build(name, kind, p)
        for extra in ([], ["-fexceptions"]):
            for rt in ("void *", "int *"):
                src = "\n".join(ex) + f"\n{rt} {name}(void)\n{{\n{body}\n}}\n"
                if compile_check([(addr, name, src, [])], "991111-01", extra):
                    found[addr] = (name, ex, rt, body, r["group"] or "none", tuple(extra))
                    break
            if addr in found:
                break
    os.makedirs(OUT, exist_ok=True)
    for old in glob.glob(os.path.join(OUT, "*.c")):
        os.remove(old)
    groups = {}
    for a, v in found.items():
        groups.setdefault((v[4], v[5]), []).append((a, v))
    for (g, extra), fl in groups.items():
        tag = re.sub(r"[^A-Za-z0-9_]", "_", g) + ("_eh" if extra else "")
        with open(os.path.join(OUT, tag + ".c"), "w") as f:
            f.write(f"/* {g}: accessors of function-local statics, generated by tools/gen_static.py. */\n")
            if extra:
                f.write("// cflags: -fexceptions\n")
            f.write('#include "../common.h"\n')
            decl = {}
            for a, (name, ex, rt, body, g_, e) in fl:
                for line in ex:
                    decl.setdefault(re.sub(r"\[\d+\]", "[4]", line), line)
            f.write("\n" + "\n".join(sorted(decl.values())) + "\n")
            for a, (name, ex, rt, body, g_, e) in sorted(fl):
                f.write(f"\n// MATCH func_{a:08X}\n{rt} {name}(void)\n{{\n{body}\n}}\n")
    print(tried, "candidates,", len(found), "matched")


if __name__ == "__main__":
    main()
