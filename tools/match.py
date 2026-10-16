#!/usr/bin/env python3
"""Compiles C with the game's compiler and compares one function with the
original executable.

  match.py FILE.c FUNCTION ADDRESS [compiler flags...]

FILE.c is compiled with $EE_CC (default ~/tools/ee-gcc2.9-991111-01/bin/ee-gcc; the driver
picks cc1plus for .cpp files) using -O2 -G8 unless flags are given. The
function's bytes are taken from the object file and compared word by word
with the original at ADDRESS (hex). Words the linker would still change
(relocations: jal targets, %hi/%lo halves, gp offsets) are filled in from
the symbols' final addresses (decomp/functions.csv, D_XXXXXXXX, matched C);
a field whose symbol is unknown counts as a difference. Prints a side-by-side listing and MATCH or the number
of differing words; exit status 0 on a match.
"""

import csv
import glob
import os
import re
import struct
import subprocess
import sys
import tempfile

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ee_disasm  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXE = os.path.join(ROOT, "disc", "SLES_508.91")
DEFAULT_CC = os.path.expanduser("~/tools/ee-gcc2.9-991111-01/bin/ee-gcc")
# relocation type -> bits the linker fills in
RELOC_MASK = {4: 0x03FFFFFF, 5: 0xFFFF, 6: 0xFFFF, 7: 0xFFFF, 2: 0xFFFFFFFF}


def sections(d):
    shoff = struct.unpack_from("<I", d, 0x20)[0]
    shnum, shstrndx = struct.unpack_from("<HH", d, 0x30)
    hs = [struct.unpack_from("<10I", d, shoff + 40 * i) for i in range(shnum)]
    st = hs[shstrndx][4]
    return [(d[st + h[0]:d.index(b"\0", st + h[0])].decode(), h) for h in hs]


_symbols = None


def symbol_address(name):
    """Final address of a symbol the C refers to: D_XXXXXXXX / func_XXXXXXXX,
    a function name from decomp/functions.csv, or a matched C function."""
    global _symbols
    m = re.fullmatch(r"(?:D|func)_([0-9A-Fa-f]{8})", name)
    if m:
        return int(m.group(1), 16)
    if _symbols is None:
        _symbols, seen = {}, set()
        with open(os.path.join(ROOT, "decomp", "functions.csv")) as f:
            for r in csv.DictReader(f):
                n = r["name"]
                if n in seen:
                    _symbols.pop(n, None)  # ambiguous (Ghidra repeats some names)
                else:
                    seen.add(n)
                    _symbols[n] = int(r["address"], 16)
        for src in glob.glob(os.path.join(ROOT, "src", "**", "*.c"), recursive=True):
            for a, n in re.findall(r"//\s*MATCH\s+func_([0-9A-Fa-f]{8})\s*\n[^\n(]*?(\w+)\s*\(", open(src).read()):
                _symbols[n] = int(a, 16)
    return _symbols.get(name)


def function_bytes(obj, name, addr=None):
    """Returns (words, masks) of function `name` in a relocatable ELF object.

    Without `addr`, relocated fields are masked (masks has their bits set).
    With `addr` (the function's final address), they are filled in from the
    symbols' final addresses as the linker would; only fields whose symbol
    is unknown stay masked."""
    d = open(obj, "rb").read()
    secs = sections(d)
    symtab = next(h for n, h in secs if h[1] == 2)
    strtab = secs[symtab[6]][1]
    syms, sym = [], None
    for i in range(symtab[5] // 16):
        nm, val, size, info, other, shndx = struct.unpack_from("<IIIBBH", d, symtab[4] + 16 * i)
        s = d[strtab[4] + nm:d.index(b"\0", strtab[4] + nm)].decode()
        syms.append((s, val, size, info, shndx))
        if sym is None and (s == name or (s.startswith(f"_{name}") or s.startswith(f"{name}__")) and info & 0xF == 2):
            sym = (val, size, shndx)
    if sym is None:
        raise SystemExit(f"{name} not found in the object")
    val, size, shndx = sym
    text = secs[shndx][1]
    words = list(struct.unpack_from(f"<{size // 4}I", d, text[4] + val))
    masks = [0] * len(words)
    relocs = []
    for n, h in secs:
        if h[1] == 9 and h[7] == shndx:  # SHT_REL for this section
            for j in range(h[5] // 8):
                off, info = struct.unpack_from("<II", d, h[4] + 8 * j)
                if val <= off < val + size:
                    relocs.append((off, info & 0xFF, info >> 8))
    funcs_at = {v: s for s, v, sz, inf, sh in syms if sh == shndx and inf & 0xF == 2}
    gp = 0x4A7C70
    for k, (off, rtype, si) in enumerate(relocs):
        i = (off - val) // 4
        mask = RELOC_MASK.get(rtype, 0xFFFFFFFF)
        target = None
        if addr is not None:
            sname = syms[si][0]
            if not sname and rtype == 4:  # call inside the file: by section offset
                sname = funcs_at.get((words[i] & 0x03FFFFFF) << 2, "")
            target = symbol_address(sname) if sname else None
        w = words[i]
        if target is None:
            masks[i] |= mask
        elif rtype == 4:
            words[i] = (w & ~0x03FFFFFF) | ((target >> 2) & 0x03FFFFFF)
        elif rtype == 5:  # %hi: the addend continues in the next %lo of the symbol
            lo = next((struct.unpack_from("<I", d, text[4] + o)[0] for o, t, s2 in relocs[k + 1:]
                       if t == 6 and s2 == si), 0) & 0xFFFF
            v = target + ((w & 0xFFFF) << 16) + (lo - 0x10000 if lo & 0x8000 else lo)
            words[i] = (w & ~0xFFFF) | (((v + 0x8000) >> 16) & 0xFFFF)
        elif rtype in (6, 7):
            a = w & 0xFFFF
            v = target + (a - 0x10000 if a & 0x8000 else a) - (gp if rtype == 7 else 0)
            words[i] = (w & ~0xFFFF) | (v & 0xFFFF)
        else:
            masks[i] |= mask
    return words, masks


def compare(obj, name, addr):
    """Number of words of `name` in `obj` that differ from the original at
    `addr`, with relocations resolved; unknown symbols count as differences."""
    words, masks = function_bytes(obj, name, addr)
    while len(words) > 1 and words[-1] == 0 and masks[-1] == 0:
        words.pop(), masks.pop()
    want = original_words(addr, len(words))
    return sum(1 for w, m, o in zip(words, masks, want) if m or w != o), words, masks, want


def original_words(addr, count):
    d = open(EXE, "rb").read()
    text = next(h for n, h in sections(d) if n == ".text")
    off = text[4] + addr - text[3]
    return list(struct.unpack_from(f"<{count}I", d, off))


def show(w, pc):
    dec = ee_disasm.decode(w, pc)
    return f"{dec[0]} {dec[1]}" if dec else f".word {w:#010x}"


def main(argv):
    if len(argv) < 4:
        raise SystemExit(__doc__)
    src, name, addr = argv[1], argv[2], int(argv[3], 16)
    flags = argv[4:] or ["-O2", "-G8"]
    cc = os.environ.get("EE_CC", DEFAULT_CC)
    with tempfile.TemporaryDirectory() as tmp:
        obj = os.path.join(tmp, "out.o")
        r = subprocess.run([cc, "-c", *flags, "-o", obj, src], capture_output=True, text=True)
        if r.returncode:
            raise SystemExit(r.stderr.strip() or "compile failed")
        bad, words, masks, want = compare(obj, name, addr)
    for i, (w, m, o) in enumerate(zip(words, masks, want)):
        same = not m and w == o
        pc = addr + 4 * i
        print(f"{pc:08x}  {'  ' if same else '!='} {show(o, pc):<34} {show(w, pc)}")
    print("MATCH" if not bad else f"{bad} of {len(words)} words differ")
    return 0 if not bad else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv))
