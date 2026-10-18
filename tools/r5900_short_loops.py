#!/usr/bin/env python3
"""Undoes delay-slot filling that would make a short loop, in assembly from
ee-gcc 2.9-ee-990721.

The R5900 can run a short loop the wrong number of times (a loop of six
instructions or fewer, the branch included, with no other jump inside),
so compilers that know about it leave such a loop's delay slot empty.
990721 does not: it moves the instruction before the branch into the slot.
This puts that instruction back in front of the branch (in `.set reorder`,
so 991111-01's assembler, which knows the rule, emits the nop); when the
slot was filled from the loop's top instead (the instruction copied there
and the label moved past it), the label goes back in front of it. Used for
the `// compiler: 990721-r5900` files (see tools/asm_build.py).

The same files also get the R5900 divide fix: 991111-01 puts two nops in
front of every div.s (in `.set noreorder`), 990721 does not.

  r5900_short_loops.py IN.s OUT.s
"""

import re
import sys

BRANCH = re.compile(r"^\s+(b\w*)\s+.*?(\$L\d+)\s*$")
LABEL = re.compile(r"^(\$L\d+):")


def is_insn(line):
    s = line.strip()
    return bool(s) and not s.startswith((".", "#")) and not s.endswith(":")


def find_labels(lines):
    labels = {}
    for i, line in enumerate(lines):
        m = LABEL.match(line.strip())
        if m:
            labels[m.group(1)] = i
    return labels


def fix(lines):
    out = list(lines)
    labels = find_labels(out)
    i = 0
    while i < len(out):
        # gcc writes a filled delay slot as: .set noreorder / .set nomacro /
        # branch / slot / .set macro / .set reorder
        blk = out[i:i + 6]
        m = BRANCH.match(blk[2]) if len(blk) == 6 and blk[0].strip() == ".set\tnoreorder" else None
        if (m and blk[1].strip() == ".set\tnomacro" and blk[4].strip() == ".set\tmacro"
                and labels.get(m.group(2), i) < i and blk[3].strip() != "nop"):
            lab = labels[m.group(2)]
            body = [line.split()[0] for line in out[lab:i] if is_insn(line)]
            # the slot was filled from the loop's top: the instruction was
            # copied there and the label moved past it
            prev = lab - 1
            while prev >= 0 and not is_insn(out[prev]) and out[prev].strip().startswith(".p2align"):
                prev -= 1
            if (prev >= 0 and out[prev].strip() == blk[3].strip() and len(body) + 2 <= 6
                    and not any(op[0] in "bj" for op in body)):
                op = m.group(1)
                branch = blk[2]
                if op.endswith("l") and op not in ("bal",):  # a likely branch made for the fill
                    branch = branch.replace("\t" + op, "\t" + op[:-1], 1)
                out[i:i + 6] = [branch]
                out.insert(lab, out.pop(prev))
                labels = find_labels(out)
                i += 1
                continue
            if len(body) + 1 <= 6 and not any(op[0] in "bj" for op in body):
                out[i:i + 6] = [blk[3], blk[2]]
                labels = find_labels(out)
                i += 2
                continue
        i += 1
    return fix_div_s(out)


def fix_div_s(lines):
    """Two nops in front of every div.s, as 991111-01 writes them."""
    out = []
    for line in lines:
        if line.split()[:1] == ["div.s"]:
            out += ["\t.set\tnoreorder\n", "\tnop\n", "\tnop\n", line, "\t.set\treorder\n"]
        else:
            out.append(line)
    return out


if __name__ == "__main__":
    lines = open(sys.argv[1]).read().splitlines(True)
    open(sys.argv[2], "w").writelines(fix(lines))
