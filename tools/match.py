#!/usr/bin/env python3
"""Compiles C with the game's compiler and compares one function with the
original executable.

  match.py FILE.c FUNCTION ADDRESS [compiler flags...]

FILE.c is compiled with $EE_CC (default ~/tools/ee-gcc2.9-991111-01/bin/ee-gcc; the driver
picks cc1plus for .cpp files) using -O2 -G8 unless flags are given. The
function's bytes are taken from the object file and compared word by word
with the original at ADDRESS (hex). Words the linker would still change
(relocations: jal targets, %hi/%lo halves, gp offsets) are compared with
those bits masked out. Prints a side-by-side listing and MATCH or the number
of differing words; exit status 0 on a match.
"""

import os
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


def function_bytes(obj, name):
    """Returns (words, masks) of function `name` in a relocatable ELF object."""
    d = open(obj, "rb").read()
    secs = sections(d)
    symtab = next(h for n, h in secs if h[1] == 2)
    strtab = secs[symtab[6]][1]
    sym = None
    for i in range(symtab[5] // 16):
        nm, val, size, info, other, shndx = struct.unpack_from("<IIIBBH", d, symtab[4] + 16 * i)
        s = d[strtab[4] + nm:d.index(b"\0", strtab[4] + nm)].decode()
        if s == name or (s.startswith(f"_{name}") or s.startswith(f"{name}__")) and info & 0xF == 2:
            sym = (val, size, shndx)
            break
    if sym is None:
        raise SystemExit(f"{name} not found in the object")
    val, size, shndx = sym
    text = secs[shndx][1]
    words = list(struct.unpack_from(f"<{size // 4}I", d, text[4] + val))
    masks = [0] * len(words)
    for n, h in secs:
        if h[1] == 9 and h[7] == shndx:  # SHT_REL for this section
            for j in range(h[5] // 8):
                off, info = struct.unpack_from("<II", d, h[4] + 8 * j)
                if val <= off < val + size:
                    masks[(off - val) // 4] |= RELOC_MASK.get(info & 0xFF, 0xFFFFFFFF)
    return words, masks


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
        words, masks = function_bytes(obj, name)
    # functions are 8-byte aligned: trailing nops are padding
    while len(words) > 1 and words[-1] == 0 and masks[-1] == 0:
        words.pop(), masks.pop()
    want = original_words(addr, len(words))
    bad = 0
    for i, (w, m, o) in enumerate(zip(words, masks, want)):
        same = (w & ~m) == (o & ~m)
        bad += not same
        pc = addr + 4 * i
        print(f"{pc:08x}  {'  ' if same else '!='} {show(o, pc):<34} {show(w, pc)}")
    print("MATCH" if not bad else f"{bad} of {len(words)} words differ")
    return 0 if not bad else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv))
