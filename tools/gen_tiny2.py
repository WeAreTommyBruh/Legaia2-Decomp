#!/usr/bin/env python3
"""Second pass of gen_tiny.py: for the tiny functions gen_tiny.py could translate but
whose C did not compile to the original bytes, tries the statements in every order
(gcc's scheduler often reverses independent stores), and with each compiler the
project uses. Writes the matches to src/gen2/<source file>.c.

Usage: gen_tiny2.py
"""
import csv
import glob
import itertools
import os
import re
import struct
import subprocess
import sys
import tempfile

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import asm_build
import ee_disasm
import gen_tiny
from match import compare

ROOT = asm_build.ROOT
GEN2 = os.path.join(ROOT, "src", "gen2")
COMPILERS = [("991111-01", []), ("990721-r5900", ["-fno-thread-jumps"]), ("991111-01", ["-fexceptions"]),
             ("991111-01", ["-fno-gcse"])]


def variants(src):
    """Alternative orders of the statements of a generated function."""
    lines = src.split("\n")
    head = [l for l in lines if not l.startswith("    ") and l not in ("}", "")]
    body = [l for l in lines if l.startswith("    ")]
    if len(body) < 2 or len(body) > 5:
        return []
    last = body[-1] if body[-1].lstrip().startswith(("return", "func_")) else None
    stmts = body[:-1] if last else body
    if len(stmts) < 2:
        return []
    out = []
    for perm in itertools.permutations(stmts):
        if list(perm) == stmts:
            continue
        b = list(perm) + ([last] if last else [])
        out.append(head[0] + "\n{\n" + "\n".join(b) + "\n}\n")
    return out


def compile_check(cands, compiler, extra):
    """cands: list of (addr, name, src, externs); returns the set of addrs that match."""
    with tempfile.TemporaryDirectory() as tmp:
        srcp = os.path.join(tmp, "t.c")
        externs = sorted({e for *_, ex in cands for e in ex})
        with open(srcp, "w") as f:
            f.write(f'#include "{os.path.join(ROOT, "src", "common.h")}"\ntypedef int u128 __attribute__((mode(TI)));\n' + "\n".join(externs) + "\n")
            for _, _, c, _ in cands:
                f.write(c)
        obj = os.path.join(tmp, "t.o")
        flags = ["-O2", "-G8", "-w", "-I" + os.path.join(ROOT, "src")] + extra
        r = asm_build.compile_c(srcp, obj, flags, compiler)
        if r.returncode:
            if len(cands) == 1:
                return set()
            ok = set()
            for c in cands:
                ok |= compile_check([c], compiler, extra)
            return ok
        return {a for a, n, _, _ in cands if compare(obj, n, a)[0] == 0}


def main():
    elf = asm_build.Elf(open(asm_build.EXE, "rb").read())
    text = elf.section(".text")
    code = elf.data[text["off"]:text["off"] + text["size"]]
    with open(os.path.join(ROOT, "decomp", "functions.csv")) as f:
        rows = list(csv.DictReader(f))
    done = set()
    for path in glob.glob(os.path.join(ROOT, "src", "**", "*.c"), recursive=True):
        if path.startswith(GEN2):
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
        if addr in done or size > 48 or not re.fullmatch(r"[A-Za-z_]\w*", name):
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
            while len(ins) > 2 and ins[-1] == ("nop", "") and ins[-2][0] not in ("jr", "j"):
                ins.pop()
            c = gen_tiny.straight_line(name, ins, addr)
            if c:
                for v in variants(c[0]):
                    cands.append((addr, name, v, c[1], r["group"] or "none"))
    print(len(cands), "variants")
    found = {}
    for compiler, extra in COMPILERS:
        pending = [c for c in cands if c[0] not in found]
        # one variant per function per round (same function name can't repeat in a file)
        rounds = {}
        for c in pending:
            rounds.setdefault(sum(1 for d in pending[:pending.index(c)] if d[0] == c[0]), []).append(c)
        for k, lst in sorted(rounds.items()):
            ok = compile_check([(a, n, v, ex) for a, n, v, ex, g in lst], compiler, extra)
            for a, n, v, ex, g in lst:
                if a in ok and a not in found:
                    found[a] = (n, v, ex, g, compiler, extra)
        print(compiler, extra, len(found))
    os.makedirs(GEN2, exist_ok=True)
    for old in glob.glob(os.path.join(GEN2, "*.c")):
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
        with open(os.path.join(GEN2, tag + ".c"), "w") as f:
            f.write(f"/* {g}: tiny functions (statements in the order gcc wants) generated by tools/gen_tiny2.py. */\n")
            if comp != "991111-01":
                f.write(f"// compiler: {comp}\n")
            if extra:
                f.write(f"// cflags: {' '.join(extra)}\n")
            f.write('#include "../common.h"\n\n' + "\n".join(sorted(decl.values())) + "\n\n")
            for a, n, v, ex in sorted(fl):
                f.write(f"// MATCH func_{a:08X}\n{v}\n")
    print("wrote", len(found), "functions")


if __name__ == "__main__":
    main()
