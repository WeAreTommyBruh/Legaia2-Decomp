#!/usr/bin/env python3
"""Undoes delay-slot filling that would make a short loop, in assembly from
ee-gcc 2.9-ee-990721.

The R5900 can run a short loop the wrong number of times (a loop of six
instructions or fewer, the branch included, with no other jump inside),
so compilers that know about it leave such a loop's delay slot empty.
990721 does not: it moves the instruction before the branch into the slot.
This puts that instruction back in front of the branch (in `.set reorder`,
so 991111-01's assembler, which knows the rule, emits the nop). Used for
the `// compiler: 990721-r5900` files (see tools/asm_build.py).

  r5900_short_loops.py IN.s OUT.s
"""

import re
import sys

BRANCH = re.compile(r"^\s+(b\w*)\s+.*?(\$L\d+)\s*$")
LABEL = re.compile(r"^(\$L\d+):")


def is_insn(line):
    s = line.strip()
    return bool(s) and not s.startswith((".", "#")) and not s.endswith(":")


def fix(lines):
    out = list(lines)
    labels = {}
    for i, line in enumerate(out):
        m = LABEL.match(line.strip())
        if m:
            labels[m.group(1)] = i
    i = 0
    while i < len(out):
        # gcc writes a filled delay slot as: .set noreorder / .set nomacro /
        # branch / slot / .set macro / .set reorder
        blk = out[i:i + 6]
        m = BRANCH.match(blk[2]) if len(blk) == 6 and blk[0].strip() == ".set\tnoreorder" else None
        if (m and blk[1].strip() == ".set\tnomacro" and blk[4].strip() == ".set\tmacro"
                and labels.get(m.group(2), i) < i and blk[3].strip() != "nop"):
            body = [line.split()[0] for line in out[labels[m.group(2)]:i] if is_insn(line)]
            if len(body) + 1 <= 6 and not any(op[0] in "bj" for op in body):
                out[i:i + 6] = [blk[3], blk[2]]
                i += 2
                continue
        i += 1
    return out


if __name__ == "__main__":
    lines = open(sys.argv[1]).read().splitlines(True)
    open(sys.argv[2], "w").writelines(fix(lines))
