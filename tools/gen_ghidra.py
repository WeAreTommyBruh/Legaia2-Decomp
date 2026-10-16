#!/usr/bin/env python3
"""Keeps Ghidra's decompilation of the functions where it already compiles
to the original bytes.

For every function that is not matched yet and has no globals other than
gp-relative ones, the function from decomp/src/ is compiled with ee-gcc
2.9-ee-991111-01 -O2 -G8 twice: as Ghidra wrote it, and with Ghidra's 64-bit
`long`/`ulong` turned into `int`/`uint` (Ghidra shows register-sized values
as long). Gp-relative globals (`iGpffff9db0`: gp + offset, type from the
prefix) become `D_XXXXXXXX` symbols; called functions get Ghidra's
prototypes. Exact matches are written, marked `// MATCH func_XXXXXXXX`, to
src/ghidra/<source group>.c (more files when two functions declare the
same global differently). The code is Ghidra's, meant to be cleaned up by
hand; the files are regenerated from scratch each run.

Usage: gen_ghidra.py [MAX_SIZE]        (default 1024 bytes)
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
UNSUPPORTED = re.compile(r"\b(_DAT_\w+|PTR_\w+|s_\w+|in_\w+|unaff_\w+|extraout_\w+|"
                         r"CONCAT\d+|SUB\d+|ZEXT\d+|SEXT\d+|_[a-z]+c2\w*|_v\w+|trap|halt_baddata|"
                         r"\w+\._\d+_\d+_|LAB_\w+|switchD_\w+|joined_r0x\w+|caseD_\w+)\b")


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


def prepare(name, body, protos, variant, dat_types=()):
    """Returns (C text, extern declarations {symbol: type}, prototypes) or None.
    Absolute globals DAT_xxxxxxxx get the types in `dat_types` (in order of
    first use); they are declared as arrays (D_XXXXXXXX[]) so that the
    compiler addresses them absolutely, as the original does, and
    `#define DAT_xxxxxxxx (D_XXXXXXXX[0])` keeps Ghidra's expressions."""
    if UNSUPPORTED.search(body):
        return None
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
    dats = list(dict.fromkeys(re.findall(r"\bDAT_([0-9a-f]{8})\b", body)))
    if len(dats) != len(dat_types):
        return None
    defines = []
    for a, t in zip(dats, dat_types):
        externs[f"D_{a.upper()}[]"] = t
        defines.append(f"#define DAT_{a} (D_{a.upper()}[0])")
    if variant == "int":
        body = re.sub(r"\bulong\b", "uint", re.sub(r"\blong\b", "int", body))
    if defines:
        body = "\n".join(defines) + "\n" + body + "\n" + "\n".join(f"#undef DAT_{a}" for a in dats)
    called = sorted({c for c in re.findall(r"\b(\w+)\s*\(", body) if c in protos and c != name})
    decls = []
    for c in called:
        p = protos[c]
        if variant == "int":
            p = re.sub(r"\bulong\b", "uint", re.sub(r"\blong\b", "int", p))
        decls.append(p)
    return body, externs, decls


def dat_type_choices(body):
    n = len(set(re.findall(r"\bDAT_[0-9a-f]{8}\b", body)))
    if n > 2:
        return []
    return list(itertools.product(DAT_TYPES, repeat=n))


def try_one(job):
    addr, name, group, body, protos, hdr = job
    for variant, types in itertools.product(("int", "ghidra"), dat_type_choices(body)):
        prep = prepare(name, body, protos, variant, types)
        if prep is None:
            return None
        text, externs, decls = prep
        with tempfile.TemporaryDirectory() as tmp:
            src = os.path.join(tmp, "f.c")
            with open(src, "w") as f:
                f.write(f'#include "{hdr}"\n')
                f.writelines(f"extern {t} {s};\n" for s, t in externs.items())
                f.writelines(d + "\n" for d in decls)
                f.write(text + "\n")
            obj = os.path.join(tmp, "f.o")
            r = subprocess.run([asm_build.EE_CC, "-c", "-O2", "-G8", "-w", "-o", obj, src],
                               capture_output=True)
            if r.returncode:
                continue
            # constants of its own (.rodata, .lit4, ...) cannot be placed yet
            if any(n in asm_build.C_DATA and h[5] for n, h in sections(open(obj, "rb").read())):
                return None
            try:
                if compare(obj, name, addr)[0] == 0:
                    return addr, name, group, text, externs, decls
            except SystemExit:
                continue
    return None


def main(argv):
    max_size = int(argv[1]) if len(argv) > 1 else 1024
    protos = prototypes()
    taken = set()
    for path in glob.glob(os.path.join(ROOT, "src", "*.c")) + glob.glob(os.path.join(ROOT, "src", "gen", "*.c")):
        taken |= {int(a, 16) for a in re.findall(r"func_([0-9A-Fa-f]{8})", open(path).read())}
    hdr = os.path.join(ROOT, "src", "ghidra.h")
    jobs = []
    with open(os.path.join(ROOT, "decomp", "functions.csv")) as f:
        for r in csv.DictReader(f):
            addr, size = int(r["address"], 16), int(r["size_bytes"])
            if addr in taken or addr % 8 or size > max_size or r["decompiled"] != "ok":
                continue
            paths = glob.glob(os.path.join(ROOT, "decomp", "src", "*", r["name"] + ".c"))
            if len(paths) != 1:
                continue
            jobs.append((addr, r["name"], r["group"] or "none", body_of(paths[0]), protos, hdr))
    print(f"trying {len(jobs)} functions")
    with concurrent.futures.ProcessPoolExecutor(os.cpu_count()) as pool:
        found = [x for x in pool.map(try_one, jobs, chunksize=8) if x]

    for old in glob.glob(os.path.join(OUTDIR, "*.c")):
        os.remove(old)
    os.makedirs(OUTDIR, exist_ok=True)
    files = {}
    for addr, name, group, text, externs, decls in sorted(found):
        base = re.sub(r"[^A-Za-z0-9_]", "_", group)
        n = 0
        while True:  # one file per group unless declarations clash
            key = base if n == 0 else f"{base}_{n}"
            fdat = files.setdefault(key, {"externs": {}, "decls": {}, "funcs": []})
            # the same symbol declared alike (type, and array or not)
            have = {k.replace("[]", ""): (k, t) for k, t in fdat["externs"].items()}
            ok = all(have.get(s.replace("[]", ""), (s, t)) == (s, t) for s, t in externs.items())
            dnames = {re.search(r"\b(\w+)\(", d).group(1): d for d in decls}
            ok = ok and all(fdat["decls"].get(k, d) == d for k, d in dnames.items())
            names_here = {nm for _, nm, _ in fdat["funcs"]}
            ok = ok and name not in fdat["decls"] and not (set(dnames) & names_here and
                                                          any(fdat["decls"].get(k) for k in set(dnames) & names_here))
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
                    "   Still to be cleaned up by hand. */\n"
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
