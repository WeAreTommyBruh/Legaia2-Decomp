#!/usr/bin/env python3
"""Writes C for the game's `new T` wrappers: MemAllocDbg(size, __FILE__, line) followed by a
constructor call, built with exceptions on (no tail call). Keeps the exact matches in
src/gen_new/<group>.c (cflags -fexceptions).

Usage: gen_new.py
"""
import csv, glob, os, re, struct, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import asm_build, ee_disasm
from gen_tiny2 import compile_check

ROOT = asm_build.ROOT
OUT = os.path.join(ROOT, "src", "gen_new")


def main():
    elf = asm_build.Elf(open(asm_build.EXE, "rb").read())
    text = elf.section(".text")
    code = elf.data[text["off"]:text["off"] + text["size"]]
    rows = list(csv.DictReader(open(os.path.join(ROOT, "decomp", "functions.csv"))))
    done = set()
    for path in glob.glob(os.path.join(ROOT, "src", "**", "*.c"), recursive=True):
        if path.startswith(OUT):
            continue
        done |= {int(a, 16) for a in re.findall(r"func_([0-9A-Fa-f]{8})", open(path).read())}
    count = {}
    for r in rows:
        count[r["name"]] = count.get(r["name"], 0) + 1
    cands = []
    for r in rows:
        addr, size, name = int(r["address"], 16), int(r["size_bytes"]), r["name"]
        if count[name] > 1:
            name = f"dup_{addr:08x}"
        if addr in done or size != 48 or not re.fullmatch(r"[A-Za-z_]\w*", name):
            continue
        ws = struct.unpack_from("<12I", code, addr - text["addr"])
        ins = [ee_disasm.decode(w, addr + 4 * i) for i, w in enumerate(ws)]
        if any(i is None for i in ins):
            continue
        t = [(i[0], i[1]) for i in ins]
        m = (t[0][0] == "addiu" and t[0][1].startswith("$29, $29, -16") and t[1][0] == "lui" and t[1][1].startswith("$5, ")
             and t[2] == ("sd", "$31, 0($29)") and t[3][0] == "addiu" and t[3][1].startswith("$4, $0, ")
             and t[4][0] == "addiu" and t[4][1].startswith("$5, $5, ") and t[5][0] == "jal" and t[5][1] == "func_00162130"
             and t[6][0] == "addiu" and t[6][1].startswith("$6, $0, ") and t[7][0] == "jal" and t[8] == ("daddu", "$4, $2, $0"))
        if not m:
            continue
        sz = int(t[3][1].split(", ")[2])
        line = int(t[6][1].split(", ")[2])
        s = (int(t[1][1].split(", ")[1], 16) << 16) + int(t[4][1].split(", ")[2])
        ctor = t[7][1]
        cands.append((addr, name, sz, line, s, ctor, r["group"] or "none"))
    cands2 = []

    # shape 2: one argument passed on to the constructor (64 bytes)
    for r in rows:
        addr, size, name = int(r["address"], 16), int(r["size_bytes"]), r["name"]
        if addr in done or size != 64 or not re.fullmatch(r"[A-Za-z_]\w*", name):
            continue
        if count[name] > 1:
            name = f"dup_{addr:08x}"
        ws = struct.unpack_from("<16I", code, addr - text["addr"])
        ins = [ee_disasm.decode(w, addr + 4 * i) for i, w in enumerate(ws)]
        if any(i is None for i in ins):
            continue
        t = [f"{i[0]} {i[1]}".strip() for i in ins]
        pats = [r"addiu \$29, \$29, -32", r"lui \$5, (0x[0-9a-f]+)", r"sd \$16, 0\(\$29\)", r"addiu \$5, \$5, (-?\d+)", r"daddu \$16, \$4, \$0", r"sd \$31, 16\(\$29\)",
                r"addiu \$4, \$0, (\d+)", r"jal func_00162130", r"addiu \$6, \$0, (\d+)", r"daddu \$5, \$16, \$0", r"jal (func_\w+)", r"daddu \$4, \$2, \$0",
                r"ld \$31, 16\(\$29\)", r"ld \$16, 0\(\$29\)", r"jr \$31", r"addiu \$29, \$29, 32"]
        g = []
        for p_, x in zip(pats, t):
            m = re.fullmatch(p_, x)
            if not m:
                break
            g += list(m.groups())
        else:
            s_ = (int(g[0], 16) << 16) + int(g[1])
            cands2.append((addr, name, int(g[2]), int(g[3]), s_, g[4], r["group"] or "none"))
    found = {}
    for addr, name, sz, line, s, ctor, g in cands:
        for rt, tail in (("int", "return "), ("void *", "return ")):
            src = (f"extern char D_{s:08X}[];\nvoid *MemAllocDbg(int, char *, int);\n"
                   f"{rt} {ctor}();\n{rt} {name}(void)\n{{\n    {tail}{ctor}(MemAllocDbg({sz}, D_{s:08X}, {line}));\n}}\n")
            ok = compile_check([(addr, name, src, [])], "991111-01", ["-fexceptions"])
            if ok:
                found[addr] = (name, src, g, ctor, s, sz, line, rt)
                break
    for addr, name, sz, line, s_, ctor, g in cands2:
        for extra in (["-fexceptions"], []):
            src = (f"extern char D_{s_:08X}[];\nvoid *MemAllocDbg(int, char *, int);\n"
                   f"void *{ctor}();\nvoid *{name}(int a)\n{{\n    return {ctor}(MemAllocDbg({sz}, D_{s_:08X}, {line}), a);\n}}\n")
            if compile_check([(addr, name, src, [])], "991111-01", extra):
                found[addr] = (name, src, g, ctor, s_, sz, line, "void *", tuple(extra), True)
                break
    os.makedirs(OUT, exist_ok=True)
    for old in glob.glob(os.path.join(OUT, "*.c")):
        os.remove(old)
    groups = {}
    for a, v in found.items():
        extra = v[8] if len(v) > 8 else ("-fexceptions",)
        groups.setdefault((v[2], extra), []).append((a, v))
    for (g, extra), fl in groups.items():
        tag = re.sub(r"[^A-Za-z0-9_]", "_", g) + ("_eh" if extra else "")
        with open(os.path.join(OUT, tag + ".c"), "w") as f:
            f.write(f"/* {g}: `new` wrappers (allocate, then construct), generated by tools/gen_new.py. */\n")
            if extra:
                f.write("// cflags: -fexceptions\n")
            f.write("#include \"../common.h\"\n\nvoid *MemAllocDbg(int, char *, int);\n")
            for a, v in sorted(fl):
                name, src, g_, ctor, s_, sz, line, rt = v[:8]
                one = len(v) > 9
                f.write(f"\nextern char D_{s_:08X}[];\n{'void *' if one else rt} {ctor}();\n// MATCH func_{a:08X}\n")
                if one:
                    f.write(f"void *{name}(int a)\n{{\n    return {ctor}(MemAllocDbg({sz}, D_{s_:08X}, {line}), a);\n}}\n")
                else:
                    f.write(f"{rt} {name}(void)\n{{\n    return {ctor}(MemAllocDbg({sz}, D_{s_:08X}, {line}));\n}}\n")
    print(len(cands), "candidates,", len(found), "matched")


if __name__ == "__main__":
    main()
