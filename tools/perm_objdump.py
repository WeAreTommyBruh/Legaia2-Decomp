#!/usr/bin/env python3
"""objdump stand-in for decomp-permuter (no MIPS binutils needed).

  perm_objdump.py NAME ADDRESS [objdump flags...] FILE.o

Prints function NAME of FILE.o in `objdump -drz` layout, with relocations
already resolved to the final addresses (as tools/match.py compares), so the
permuter scores a candidate against the original instruction for
instruction. A FILE named target.o stands for the original: the function is
read from the executable at ADDRESS instead. Used by tools/perm_setup.py.
"""

import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ee_disasm  # noqa: E402
import match  # noqa: E402

NAMES = ["zero", "at", "v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5",
         "t6", "t7", "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "t8", "t9", "k0", "k1",
         "gp", "sp", "fp", "ra"]


def text(w, pc):
    d = ee_disasm.decode(w, pc)
    if not d:
        return ".word", f"0x{w:08x}"
    ops = re.sub(r"\$f(\d+)", r"f\1", d[1])
    ops = re.sub(r"\$(\d+)", lambda m: NAMES[int(m.group(1))], ops)
    return d[0], ops.replace(", ", ",")


def main(argv):
    name, addr, path = argv[1], int(argv[2], 16), argv[-1]
    size = None
    if os.path.basename(path) == "target.o":
        with open(os.path.join(os.path.dirname(path), "target.size")) as f:
            size = int(f.read())
        words, masks = match.original_words(addr, size // 4), [0] * (size // 4)
    else:
        n = len(match.function_bytes(path, name)[0])
        words, masks = match.function_bytes(path, name, addr, match.original_words(addr, n))
    print(f"\n{path}:     file format elf32-tradlittlemips\n")
    print(f"{0:08x} <{name}>:")
    for i, (w, m) in enumerate(zip(words, masks)):
        mn, ops = text(w, addr + 4 * i)
        if m:  # a symbol whose address is not known: never equal to the original
            ops += ",<unknown>"
        print(f"  {4 * i:x}:\t{w:08x} \t{mn}\t{ops}")


if __name__ == "__main__":
    main(sys.argv)
