#!/usr/bin/env python3
"""Compiles one C file as the build does.

  ee_cc.py [--compiler 991111-01|990721] [flags...] FILE.c -o FILE.o

Without --compiler the file's `// compiler:` line decides (see
tools/asm_build.py). Used by the permuter setup (tools/perm_setup.py).
"""

import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import asm_build  # noqa: E402


def main(argv):
    args = argv[1:]
    compiler = None
    if args[:1] == ["--compiler"]:
        compiler, args = args[1], args[2:]
    out = args[args.index("-o") + 1]
    args = args[:args.index("-o")] + args[args.index("-o") + 2:]
    src = next(a for a in args if a.endswith((".c", ".i")))
    flags = [a for a in args if a != src]
    r = asm_build.compile_c(src, out, flags, compiler, capture=False)
    return r.returncode


if __name__ == "__main__":
    sys.exit(main(sys.argv))
