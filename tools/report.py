#!/usr/bin/env python3
"""Writes the objdiff progress report (report/report.json) that ByteMatch
(bytematch.dev) and decomp.dev read.

objdiff compares, unit by unit, a target object (the original code) with a
base object (the code compiled from C) by symbol name. This script makes both
under build/objdiff/ and runs `objdiff-cli report generate`:
  units    one per source group of decomp/functions.csv (the game's .cpp
           files and the runs between them), named after the group, plus
           `data` with the data sections (not matched yet)
  target   the unit's original instructions, assembled with clang; every
           function is a sized symbol named as in the C (or functions.csv).
           In functions that are matched in C, the instructions that carry a
           relocation in the compiled C (calls, %hi/%lo and gp-relative
           accesses) are written with the same symbol, so both sides
           relocate alike.
  base     the unit's C files (src/*.c, src/gen/*.c) compiled with ee-gcc;
           units without C have none (0% matched).
  merge    afterwards the per-file units of a group are folded into one unit
           named after the group (merge_groups), so a group shows a combined figure.
The report holds unit and function names, sizes and match percentages only.

Needs disc/SLES_508.91, decomp/functions.csv, clang, ee-gcc and objdiff-cli
($OBJDIFF, default ~/tools/objdiff/objdiff-cli).

Usage: report.py [OUT.json]      (default report/report.json)
"""

import collections
import csv
import glob
import json
import os
import re
import struct
import subprocess
import sys

import asm_build
import ee_disasm
from match import sections

ROOT = asm_build.ROOT
OUT = os.path.join(ROOT, "build", "objdiff")
OBJDIFF = os.environ.get("OBJDIFF", os.path.expanduser("~/tools/objdiff/objdiff-cli"))
MEM_IMM = re.compile(r"(-?\d+)\((\$\d+)\)$")


def unit_name(group):
    return re.sub(r"[^A-Za-z0-9_]", "_", group or "none")


def c_sources(top="src", mark="MATCH"):
    """{address: (c file, function name)} for every `// <mark>` function in <top>/."""
    out = {}
    for src in sorted(glob.glob(os.path.join(ROOT, top, "**", "*.c"), recursive=True)):
        text = open(src).read()
        for addr, name in re.findall(r"//\s*" + mark + r"\s+func_([0-9A-Fa-f]{8})\s*\n[^\n(]*?(\w+)\s*\(", text):
            out[int(addr, 16)] = (src, name)
    return out


def symbols_and_relocs(obj):
    """Function symbols {name: (offset, size)} and relocations
    {offset: (type, symbol, addend bits)} of the .text of a relocatable ELF."""
    d = open(obj, "rb").read()
    secs = sections(d)
    text_idx = next(i for i, (n, _) in enumerate(secs) if n == ".text")
    symtab = next(h for n, h in secs if h[1] == 2)
    strtab = secs[symtab[6]][1]
    names, funcs = [], {}
    for i in range(symtab[5] // 16):
        nm, val, size, info, other, shndx = struct.unpack_from("<IIIBBH", d, symtab[4] + 16 * i)
        s = d[strtab[4] + nm:d.index(b"\0", strtab[4] + nm)].decode()
        if not s and info & 0xF == 3 and 0 < shndx < len(secs) and secs[shndx][0] in DATA_RELOC:
            s = DATA_RELOC[secs[shndx][0]]  # the file's own data (a switch's jump table)
        names.append(s)
        if shndx == text_idx and info & 0xF == 2:
            funcs[s] = (val, size)
    text = secs[text_idx][1]
    relocs = {}
    for n, h in secs:
        if h[1] == 9 and h[7] == text_idx:
            for j in range(h[5] // 8):
                off, info = struct.unpack_from("<II", d, h[4] + 8 * j)
                word = struct.unpack_from("<I", d, text[4] + off)[0]
                relocs[off] = (info & 0xFF, names[info >> 8], word)
    # calls inside the file are relocated against the section: name the callee
    by_off = {v[0]: n for n, v in funcs.items()}
    for off, (t, sym, word) in list(relocs.items()):
        if not sym and t == 4:
            callee = by_off.get((word & 0x03FFFFFF) << 2)
            if callee is None:
                raise SystemExit(f"{obj}: call at {off:#x} to an unknown local target")
            relocs[off] = (t, callee, word & ~0x03FFFFFF)
        elif not sym and t in (5, 6):
            # the address of a function in this file (lui/addiu pair against the section)
            def lo16(w):
                v = w & 0xFFFF
                return v - 0x10000 if v & 0x8000 else v
            if t == 6:
                target = lo16(word)
            else:  # HI16: take the addend from the next LO16 against a section
                nxt = [r for o2, r in sorted(relocs.items()) if o2 > off and r[0] == 6 and not r[1]]
                target = lo16(nxt[0][2]) if nxt else 0
            callee = by_off.get(target)
            if callee is None:
                raise SystemExit(f"{obj}: address of an unknown local target at {off:#x}")
            relocs[off] = (t, callee, word)
        elif not sym:
            raise SystemExit(f"{obj}: relocation type {t} at {off:#x} against a section")
    return funcs, relocs


# local labels standing for a C file's own data sections in the target
# objects (relocations against them become section relocations, as in the
# base object)
DATA_RELOC = {".rodata": ".Lrodata", ".lit4": ".Llit4"}


def data_sizes(obj):
    """{section: size} of the data sections in DATA_RELOC of an object."""
    return {n: h[5] for n, h in sections(open(obj, "rb").read()) if n in DATA_RELOC and h[5]}


def patch_literals(obj):
    """clang writes a gp-relative reference to .lit4 as R_MIPS_GPREL16; ee-gcc
    writes R_MIPS_LITERAL. Gives the target's references to .lit4 the latter."""
    d = bytearray(open(obj, "rb").read())
    secs = sections(bytes(d))
    symtab = next(h for n, h in secs if h[1] == 2)
    lit = {i for i in range(symtab[5] // 16)
           if (lambda t: t[5] > 0 and secs[t[5]][0] == ".lit4" and t[3] & 0xF == 3)(
               struct.unpack_from("<IIIBBH", d, symtab[4] + 16 * i))}
    for n, h in secs:
        if h[1] == 9 and secs[h[7]][0] == ".text":
            for j in range(h[5] // 8):
                off, info = struct.unpack_from("<II", d, h[4] + 8 * j)
                if info >> 8 in lit and info & 0xFF == 7:
                    struct.pack_into("<I", d, h[4] + 8 * j + 4, (info & ~0xFF) | 8)
    open(obj, "wb").write(d)


def s16(x):
    return x - 0x10000 if x & 0x8000 else x


def symbolize(d, word, reloc):
    """Rewrites a decoded instruction to refer to the relocation's symbol."""
    rtype, sym, inplace = reloc
    mn, ops = d[0], d[1]
    if rtype == 4 and mn in ("j", "jal"):
        return mn, sym
    if rtype == 5:
        if mn != "lui":
            return None
        add = (inplace & 0xFFFF) << 16
        return mn, re.sub(r"0x[0-9a-f]+$", f"%hi({sym}{f'+{add:#x}' if add else ''})", ops)
    if rtype in (6, 7, 8):  # 8: R_MIPS_LITERAL, a float constant in .lit4 (see patch_literals)
        if not re.fullmatch(r"addiu|ori|[ls][bhwdq]u?|[ls][wd][lr]|[ls]wc1", mn):
            return None  # work in progress: the base's relocation sits on a different instruction
        add = s16(inplace & 0xFFFF)
        op = "%lo" if rtype == 6 else "%gp_rel"
        ref = f"{op}({sym}{f'+{add}' if add else ''})"
        if MEM_IMM.search(ops):
            return mn, MEM_IMM.sub(lambda m: f"{ref}({m.group(2)})", ops)
        return mn, re.sub(r"(-?\d+|0x[0-9a-f]+)$", ref, ops)
    return None


JUMPS = ("jr", "j", "jal", "jalr", "beq", "bne", "blez", "bgtz", "bltz", "bgez", "beql", "bnel",
         "blezl", "bgtzl", "bltzl", "bgezl", "bltzal", "bgezal", "bc1f", "bc1t", "bc1fl", "bc1tl")


def padded_end(code, base, start, end):
    """End of the function at start, without the zero words that pad the next
    function to 8 bytes (a nop in a jump's delay slot is kept)."""
    while end - start > 8:
        last = struct.unpack_from("<I", code, end - 4 - base)[0]
        prev = ee_disasm.decode(struct.unpack_from("<I", code, end - 8 - base)[0], end - 8)
        if last != 0 or (prev and prev[0] in JUMPS):
            break
        end -= 4
    return end


def merge_groups(rep):
    """One unit per source group: the group's per-file units (and the leftover
    unit) are folded into one, so a group shows a combined figure. Functions
    keep their own match percentages; the measures are summed."""
    groups = collections.OrderedDict()
    for u in rep["units"]:
        groups.setdefault(u["name"].split("/")[0], []).append(u)
    num = lambda m, k: float(m.get(k, 0))
    units = []
    for name, us in groups.items():
        if len(us) == 1:
            us[0]["name"] = name
            units.append(us[0])
            continue
        funcs, secs, offset = [], collections.OrderedDict(), 0
        for u in us:
            for f in u["functions"]:
                funcs.append({**f, "address": str(offset + int(f.get("address", 0)))})
            for sec in u["sections"]:
                t = secs.setdefault(sec["name"], {"size": 0, "w": 0.0, "n": 0})
                t["size"] += int(sec.get("size", 0))
                t["w"] += float(sec.get("fuzzy_match_percent", 0)) * int(sec.get("size", 0))
                t["n"] += 1
            offset += next((int(x.get("size", 0)) for x in u["sections"] if x["name"] == ".text"), 0)
        ms = [u["measures"] for u in us]
        tc, mc = sum(num(m, "total_code") for m in ms), sum(num(m, "matched_code") for m in ms)
        td, md = sum(num(m, "total_data") for m in ms), sum(num(m, "matched_data") for m in ms)
        tf, mf = sum(num(m, "total_functions") for m in ms), sum(num(m, "matched_functions") for m in ms)
        fz = sum(num(m, "fuzzy_match_percent") * num(m, "total_code") for m in ms)
        out = {"total_code": str(int(tc)), "total_functions": int(tf), "total_units": 1}
        if tc:
            out.update(fuzzy_match_percent=fz / tc, matched_code=str(int(mc)), matched_code_percent=100.0 * mc / tc)
        if tf:
            out.update(matched_functions=int(mf), matched_functions_percent=100.0 * mf / tf)
        if td:
            out.update(total_data=str(int(td)), matched_data=str(int(md)), matched_data_percent=100.0 * md / td)
        else:
            out.update(matched_data_percent=100.0, complete_data_percent=100.0)
        sections = []
        for n, t in secs.items():
            d = {"name": n, "metadata": {}}
            if t["size"]:
                d.update(size=str(t["size"]), fuzzy_match_percent=t["w"] / t["size"])
            else:
                d["fuzzy_match_percent"] = 100.0
            sections.append(d)
        # the first sub-unit may be a leftover or a draft unit without a source file: take the path from the
        # sub-unit that has one and the most matched code
        meta = dict(us[0]["metadata"])
        withsrc = [u for u in us if u["metadata"].get("source_path")]
        if withsrc:
            best = max(withsrc, key=lambda u: num(u["measures"], "matched_code"))
            meta["source_path"] = best["metadata"]["source_path"]
        units.append({"name": name, "measures": out, "sections": sections, "functions": funcs,
                      "metadata": meta})
    rep["units"] = units
    rep["measures"]["total_units"] = len(units)
    for c in rep["categories"]:
        c["measures"]["total_units"] = sum(1 for u in units if c["id"] in u["metadata"]["progress_categories"])


def main(argv):
    out_json = argv[1] if len(argv) > 1 else os.path.join(ROOT, "report", "report.json")
    clang = asm_build.tool("CLANG", "clang")
    elf = asm_build.Elf(open(asm_build.EXE, "rb").read())
    text = elf.section(".text")
    code = elf.data[text["off"]:text["off"] + text["size"]]
    funcs = [f for f in asm_build.functions() if text["addr"] <= f[0] < text["addr"] + text["size"]]
    ends = [f[0] for f in funcs[1:]] + [text["addr"] + text["size"]]
    starts = {a for a, _, _ in funcs}
    with open(os.path.join(ROOT, "decomp", "functions.csv")) as f:
        rows = list(csv.DictReader(f))
    source_file = {int(r["address"], 16): r["source_file"] for r in rows}
    csrc = c_sources()
    # work in progress (wip/*.c, `// WIP func_XXXXXXXX`): compiled as the unit's base so that
    # objdiff reports a partial match; they count as matched only at 100%
    wip = {a: v for a, v in c_sources("wip", "WIP").items() if a not in csrc}
    csrc.update(wip)
    counts = collections.Counter(n for _, n, _ in funcs)
    name_of = {a: (n if counts[n] == 1 and re.fullmatch(r"[A-Za-z_]\w*", n) else f"func_{a:08X}")
               for a, n, _ in funcs}  # Ghidra repeats a few names (thunks)
    name_of.update({a: n for a, (_, n) in csrc.items()})

    # a unit per source group for its unmatched functions, and one per C file
    # for the functions matched there (its base is that file alone)
    units = collections.OrderedDict()
    unit_src = {}
    for (addr, _, group), end in zip(funcs, ends):
        if addr in csrc:
            rel = os.path.relpath(csrc[addr][0], ROOT)[:-2].removeprefix("src/")
            u = f"{unit_name(group)}/{rel}"
            unit_src[u] = csrc[addr][0]
        else:
            u = unit_name(group) + "/unmatched"  # the functions of the group still to do
        units.setdefault(u, []).append((addr, end))

    # base objects: one wrapper per unit that includes the unit's C files
    ee_flags = None
    base_info = {}
    os.makedirs(os.path.join(OUT, "base"), exist_ok=True)
    os.makedirs(os.path.join(OUT, "target"), exist_ok=True)
    for unit, fl in units.items():
        if unit not in unit_src:
            continue
        files = [unit_src[unit]]
        obj = os.path.join(OUT, "base", unit.replace("/", "__") + ".o")
        if asm_build.compile_c(files[0], obj, ["-O2", "-G8", "-w", *asm_build.file_flags(files[0])]).returncode:
            raise SystemExit(f"{files[0]} does not compile")
        if asm_build.file_flags(files[0]):  # -fexceptions frame tables (see asm_build.py)
            subprocess.run([asm_build.tool("OBJCOPY", "llvm-objcopy"), "-w", "--remove-section=.data",
                            "--remove-section=.rel.data", obj], check=True)
        ee_flags = struct.unpack_from("<I", open(obj, "rb").read(), 0x24)[0]
        base_info[unit] = (obj, symbols_and_relocs(obj), files)

    # target objects
    objdiff_units = []
    for unit, fl in units.items():
        relocs = {}
        size_of = {}
        if unit in base_info:
            bfuncs, brel = base_info[unit][1]
            for a, _ in fl:
                if a in csrc:
                    off, size = bfuncs[csrc[a][1]]
                    if a not in wip:  # a draft's size differs from the original's
                        size_of[a] = size
                    for o in range(off, off + size, 4):
                        if o in brel:
                            relocs[a + o - off] = brel[o]
        lines = [asm_build.HEADER, ".text\n"]
        for a, end in fl:
            name = name_of[a]
            labels = set()
            decoded = {}
            for pc in range(a, end, 4):
                w = struct.unpack_from("<I", code, pc - text["addr"])[0]
                d = ee_disasm.decode(w, pc)
                if pc in relocs and d:
                    d = symbolize(d, w, relocs[pc]) or None
                elif d and d[0] in ("j", "jal"):
                    d = (d[0], name_of[d[2]]) if d[2] in starts else None
                elif d and d[2] is not None:
                    if a <= d[2] < end:
                        labels.add(d[2])
                    else:
                        d = None
                decoded[pc] = (d, w)
            # the symbol ends at the function's size; alignment padding stays outside
            fend = a + size_of[a] if a in size_of else padded_end(code, text["addr"], a, end)
            lines.append(f"\n.globl {name}\n.type {name}, @function\n{name}:\n")
            for pc in range(a, end, 4):
                if pc == fend:
                    lines.append(f".size {name}, . - {name}\n")
                if pc in labels:
                    lines.append(f".L{pc:08X}:\n")
                d, w = decoded[pc]
                if d:
                    lines.append(f"    {d[0]:<8} {d[1]}\n" if d[1] else f"    {d[0]}\n")
                else:
                    lines.append(f"    .word    {w:#010x}\n")
            if fend >= end:
                lines.append(f".size {name}, . - {name}\n")
        if unit in base_info and not all(a in wip for a, _ in fl):  # room for the C file's own data, at the same offsets
            for sec, size in data_sizes(base_info[unit][0]).items():
                lines.append(f"\n.section {sec}\n{DATA_RELOC[sec]}:\n    .space {size}\n")
        src = os.path.join(OUT, "target", unit.replace("/", "__") + ".s")
        open(src, "w").writelines(lines)
        obj = src[:-2] + ".o"
        r = subprocess.run([clang] + asm_build.ASFLAGS + [src, "-o", obj], capture_output=True, text=True)
        if r.returncode:
            raise SystemExit(f"{src}:\n{r.stderr[:2000]}")
        patch_literals(obj)
        entry = {"name": unit, "target_path": os.path.relpath(obj, OUT),
                 "metadata": {"progress_categories": ["game" if any(source_file.get(a) for a, _ in fl) else "other"]}}
        if unit in base_info:
            entry["base_path"] = os.path.relpath(base_info[unit][0], OUT)
            entry["metadata"]["source_path"] = os.path.relpath(base_info[unit][2][0], ROOT)
        objdiff_units.append(entry)
    # the data sections, unmatched as yet: one object symbol per section
    lines = []
    for sec_name in asm_build.DATA_SECTIONS[1:]:  # .vutext is VU microcode, not data
        sec = elf.section(sec_name)
        sym = "data" + sec_name.replace(".", "_")
        flags = "a" if sec_name in (".rodata", ".gcc_except_table", ".lit4") else "aw"
        lines.append(f'.section {sec_name},"{flags}"\n.globl {sym}\n.type {sym}, @object\n{sym}:\n'
                     f'.incbin "{asm_build.EXE}", {sec["off"]}, {sec["size"]}\n.size {sym}, . - {sym}\n')
    src = os.path.join(OUT, "target", "data.s")
    open(src, "w").writelines(lines)
    subprocess.run([clang] + asm_build.ASFLAGS + [src, "-o", src[:-2] + ".o"], check=True)
    objdiff_units.append({"name": "data", "target_path": os.path.relpath(src[:-2] + ".o", OUT),
                          "metadata": {"progress_categories": ["other"]}})
    # objdiff decodes by the ELF flags: give the targets the R5900 flags of the C objects
    if ee_flags is not None:
        for e in objdiff_units:
            p = os.path.join(OUT, e["target_path"])
            data = bytearray(open(p, "rb").read())
            struct.pack_into("<I", data, 0x24, ee_flags)
            open(p, "wb").write(data)

    config = {"min_version": "2.0.0", "build_target": False, "build_base": False,
              "units": objdiff_units,
              "progress_categories": [
                  {"id": "game", "name": "Game code (attributed to a .cpp file)"},
                  {"id": "other", "name": "Other code (SDK, libraries, unattributed)"}]}
    json.dump(config, open(os.path.join(OUT, "objdiff.json"), "w"), indent=1)
    os.makedirs(os.path.dirname(out_json), exist_ok=True)
    subprocess.run([OBJDIFF, "report", "generate", "-p", OUT, "-o", out_json, "-f", "json"], check=True)
    rep = json.load(open(out_json))
    merge_groups(rep)
    json.dump(rep, open(out_json, "w"), indent=1)
    m = rep.get("measures", {})
    print(f"wrote {os.path.relpath(out_json, ROOT)}: {m.get('matched_functions', 0)} / "
          f"{m.get('total_functions', 0)} functions, {float(m.get('matched_code_percent', 0)):.2f}% of code")


if __name__ == "__main__":
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    main(sys.argv)
