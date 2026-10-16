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


def c_sources():
    """{address: (c file, function name)} for every MATCH function in src/."""
    out = {}
    for src in sorted(glob.glob(os.path.join(ROOT, "src", "**", "*.c"), recursive=True)):
        text = open(src).read()
        for addr, name in re.findall(r"//\s*MATCH\s+func_([0-9A-Fa-f]{8})\s*\n[^\n(]*?(\w+)\s*\(", text):
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
        elif not sym:
            raise SystemExit(f"{obj}: relocation type {t} at {off:#x} against a section")
    return funcs, relocs


def s16(x):
    return x - 0x10000 if x & 0x8000 else x


def symbolize(d, word, reloc):
    """Rewrites a decoded instruction to refer to the relocation's symbol."""
    rtype, sym, inplace = reloc
    mn, ops = d[0], d[1]
    if rtype == 4 and mn in ("j", "jal"):
        return mn, sym
    if rtype == 5 and mn == "lui":
        add = (inplace & 0xFFFF) << 16
        return mn, re.sub(r"0x[0-9a-f]+$", f"%hi({sym}{f'+{add:#x}' if add else ''})", ops)
    if rtype in (6, 7):
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
            rel = os.path.relpath(csrc[addr][0], os.path.join(ROOT, "src"))[:-2]
            u = f"{unit_name(group)}/{rel}"
            unit_src[u] = csrc[addr][0]
        else:
            u = unit_name(group)
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
        subprocess.run([asm_build.EE_CC, "-c", "-O2", "-G8", "-w", "-o", obj, files[0]], check=True)
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
        src = os.path.join(OUT, "target", unit.replace("/", "__") + ".s")
        open(src, "w").writelines(lines)
        obj = src[:-2] + ".o"
        r = subprocess.run([clang] + asm_build.ASFLAGS + [src, "-o", obj], capture_output=True, text=True)
        if r.returncode:
            raise SystemExit(f"{src}:\n{r.stderr[:2000]}")
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
    m = rep.get("measures", {})
    print(f"wrote {os.path.relpath(out_json, ROOT)}: {m.get('matched_functions', 0)} / "
          f"{m.get('total_functions', 0)} functions, {float(m.get('matched_code_percent', 0)):.2f}% of code")


if __name__ == "__main__":
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    main(sys.argv)
