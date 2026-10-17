#!/usr/bin/env python3
"""Sets up a decomp-permuter directory for one function.

  perm_setup.py FILE.c NAME ADDRESS [-fexceptions]

Writes build/perm/<address>/ (git-ignored): base.c (FILE.c preprocessed,
other functions stripped), compile.sh (ee-gcc 2.9-ee-991111-01 -O2 -G8 and
the file's `// cflags:`), target.o and target.size (the original function is
read from the executable by tools/perm_objdump.py) and settings.toml. Then:

  $PERMUTER/venv/bin/python $PERMUTER/permuter.py build/perm/<address> -j8

where PERMUTER is a checkout of https://github.com/simonlindholm/decomp-permuter
(default ~/tools/decomp-permuter). Improvements land in
build/perm/<address>/output-*/.
"""

import csv
import os
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import asm_build  # noqa: E402

PERMUTER = os.environ.get("PERMUTER", os.path.expanduser("~/tools/decomp-permuter"))


def main(argv):
    if len(argv) < 4:
        raise SystemExit(__doc__)
    src, name, addr = os.path.abspath(argv[1]), argv[2], int(argv[3], 16)
    flags = asm_build.file_flags(src) + argv[4:]
    out = os.path.join(asm_build.ROOT, "build", "perm", f"{addr:08x}")
    os.makedirs(out, exist_ok=True)
    with open(os.path.join(asm_build.ROOT, "decomp", "functions.csv")) as f:
        size = next(int(r["size_bytes"]) for r in csv.DictReader(f) if int(r["address"], 16) == addr)
    base = os.path.join(out, "base.c")
    with open(base, "w") as f:
        subprocess.run([asm_build.EE_CC, "-E", "-P", src], stdout=f, check=True)
    subprocess.run([os.path.join(PERMUTER, "venv", "bin", "python"),
                    os.path.join(PERMUTER, "strip_other_fns.py"), base, name], check=True)
    compile_sh = os.path.join(out, "compile.sh")
    with open(compile_sh, "w") as f:
        f.write("#!/bin/sh\n"
                f'exec "{asm_build.EE_CC}" -c -O2 -G8 -w {" ".join(flags)} "$1" -o "$3"\n')
    os.chmod(compile_sh, 0o755)
    # any MIPS object will do: perm_objdump.py reads the original from the executable
    subprocess.run([compile_sh, base, "-o", os.path.join(out, "target.o")], check=True)
    with open(os.path.join(out, "target.size"), "w") as f:
        f.write(str(size))
    objdump = f"python3 '{os.path.join(asm_build.ROOT, 'tools', 'perm_objdump.py')}' {name} {addr:x}"
    with open(os.path.join(out, "settings.toml"), "w") as f:
        f.write(f'func_name = "{name}"\ncompiler_type = "gcc"\nobjdump_command = "{objdump}"\n')
    print(out)


if __name__ == "__main__":
    main(sys.argv)
