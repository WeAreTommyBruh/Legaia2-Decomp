#!/usr/bin/env python3
"""Exact-shape families of small functions (found by looking at which instruction shapes
repeat among the unmatched functions) with one C template each; every candidate is
compiled and only exact matches are kept, in src/gen_fam/<group>.c.

Usage: gen_fam.py
"""
import csv, glob, os, re, struct, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import asm_build, ee_disasm
from gen_tiny2 import compile_check

ROOT = asm_build.ROOT
OUT = os.path.join(ROOT, "src", "gen_fam")


def fam_flagcall(t, name):
    """if (m & s->flags) callee(s->h, m & flags, -x): lw/and/beq/nop/neg.s/j/lw/jr/nop"""
    pat = [r"lw \$2, (\d+)\(\$4\)", r"and \$5, \$5, \$2", r"beq \$5, \$0, \.L\w+", r"nop", r"neg\.s \$f12, \$f12", r"j (func_\w+)", r"lw \$4, (\d+)\(\$4\)", r"jr \$31", r"nop"]
    if len(t) != 9:
        return None
    g = []
    for p, x in zip(pat, t):
        m = re.fullmatch(p, x)
        if not m:
            return None
        g += list(m.groups())
    fo, callee, ho = int(g[0]), g[1], int(g[2])
    pad1 = ho + 4
    src = (f"typedef struct {{ int h; char pad[{fo - 4}]; int flags; }} S;\n" if ho == 0 else
           f"typedef struct {{ char p0[{ho}]; int h; char pad[{fo - ho - 4}]; int flags; }} S;\n")
    if fo < ho + 4:
        return None
    ex = [f"void {callee}(int, int, float);"]
    body = f"void {name}(S *s, int m, float x)\n{{\n    int r = m & s->flags;\n\n    if (r != 0)\n        {callee}(s->h, r, -x);\n}}\n"
    return src, ex, body



def match(pats, t):
    if len(t) != len(pats):
        return None
    g = []
    for p, x in zip(pats, t):
        m = re.fullmatch(p, x)
        if not m:
            return None
        g += list(m.groups())
    return g


TOP = [r"lw \$2, 0\(\$4\)", r"blez \$2, \.L\w+", r"addiu \$2, \$2, -1", r"sll \$2, \$2, 2", r"addu \$2, \$4, \$2"]


def fam_top_call(t, name):
    """if (s->n > 0) callee(s->a[s->n - 1]);   (a tail call)"""
    g = match(TOP + [r"j (func_\w+)", r"lw \$4, 4\(\$2\)", r"jr \$31", r"nop"], t)
    if not g:
        return None
    ex = [f"void {g[0]}(int);"]
    src = "typedef struct { int n; int a[8]; } S;\n"
    body = f"void {name}(S *s)\n{{\n    int n = s->n;\n\n    if (n > 0)\n        {g[0]}(s->a[n - 1]);\n}}\n"
    return src, ex, body


def fam_top_setbit(t, name):
    """the top element's flag word gets a bit set"""
    g = match(TOP + [r"lw \$4, 4\(\$2\)", r"lw \$3, (\d+)\(\$4\)", r"ori \$3, \$3, 0x([0-9a-f]+)", r"sw \$3, (\d+)\(\$4\)", r"jr \$31", r"nop"], t)
    if not g or g[0] != g[2]:
        return None
    off = int(g[0])
    src = f"typedef struct {{ char pad[{off}]; int flags; }} Item;\ntypedef struct {{ int n; Item *a[8]; }} S;\n"
    body = f"void {name}(S *s)\n{{\n    int n = s->n;\n\n    if (n > 0)\n        s->a[n - 1]->flags |= 0x{g[1]};\n}}\n"
    return src, [], body


def fam_top_cond(t, name):
    """if (s->a[n - 1]->f < K) callee(s->a[n - 1]) (tail call)"""
    g = match(TOP + [r"lw \$4, 4\(\$2\)", r"lw \$3, (\d+)\(\$4\)", r"slti \$3, \$3, (\d+)", r"beq \$3, \$0, \.L\w+", r"nop", r"j (func_\w+)", r"nop", r"jr \$31", r"nop"], t)
    if not g:
        return None
    off = int(g[0])
    src = f"typedef struct {{ char pad[{off}]; int v; }} Item;\ntypedef struct {{ int n; Item *a[8]; }} S;\n"
    ex = [f"void {g[2]}(void *);"]
    body = f"void {name}(S *s)\n{{\n    Item *t;\n    int n = s->n;\n\n    if (n > 0) {{\n        t = s->a[n - 1];\n        if (t->v < {g[1]})\n            {g[2]}(t);\n    }}\n}}\n"
    return src, ex, body


def fam_countdown(t, name):
    """if (s->n-- <= 0) { s->n = 0; s->a = s->b; } return 0;  (8-byte values)"""
    g = match([r"lw \$2, (\d+)\(\$4\)", r"daddu \$3, \$2, \$0", r"addiu \$2, \$2, -1", r"bgtz \$3, \.L\w+", r"sw \$2, (\d+)\(\$4\)",
               r"sw \$0, (\d+)\(\$4\)", r"ldl \$2, (\d+)\(\$4\)", r"ldr \$2, (\d+)\(\$4\)", r"sdl \$2, (\d+)\(\$4\)", r"sdr \$2, (\d+)\(\$4\)",
               r"jr \$31", r"daddu \$2, \$0, \$0"], t)
    if not g or not (g[0] == g[1] == g[2]):
        return None
    n, src_off, dst_off = int(g[0]), int(g[4]), int(g[6])
    if int(g[3]) != src_off + 7 or int(g[5]) != dst_off + 7 or n + 4 > dst_off:
        return None
    gap = src_off - dst_off - 8
    if gap < 0:
        return None
    src = f"typedef struct {{ char c[8]; }} V8;\ntypedef struct {{ char pad[{n}]; int n; char pad2[{dst_off - n - 4}]; V8 a; V8 b; }} S;\n"
    if gap:
        src = f"typedef struct {{ char c[8]; }} V8;\ntypedef struct {{ char pad[{n}]; int n; char pad2[{dst_off - n - 4}]; V8 a; char pad3[{gap}]; V8 b; }} S;\n"
    body = f"int {name}(S *s)\n{{\n    if (s->n-- <= 0) {{\n        s->n = 0;\n        s->a = s->b;\n    }}\n    return 0;\n}}\n"
    return src, [], body


def fam_ptr_call(t, name):
    """if (s->p) callee(s->p) as a tail call"""
    g = match([r"lw \$4, (\d+)\(\$4\)", r"beq \$4, \$0, \.L\w+", r"nop", r"j (func_\w+)", r"nop", r"jr \$31", r"nop"], t)
    if not g:
        return None
    off = int(g[0])
    ex = [f"void {g[1]}(int);"]
    body = f"void {name}(int *s)\n{{\n    int p = s[{off // 4}];\n\n    if (p != 0)\n        {g[1]}(p);\n}}\n"
    return "", ex, body


def fam_zero_arg(t, name):
    """callee(a0..a(k-1), 0) not as a tail call (exceptions on)"""
    g = match([r"addiu \$29, \$29, -16", r"sd \$31, 0\(\$29\)", r"jal (func_\w+)", r"daddu \$(\d+), \$0, \$0", r"ld \$31, 0\(\$29\)", r"jr \$31", r"addiu \$29, \$29, 16"], t)
    if not g:
        return None
    r = int(g[1])
    if not 4 <= r <= 11:
        return None
    ps = ", ".join(f"int a{i}" for i in range(r - 4)) or "void"
    args = ", ".join([f"a{i}" for i in range(r - 4)] + ["0"])
    ex = [f"void {g[0]}();"]
    body = f"void {name}({ps})\n{{\n    {g[0]}({args});\n}}\n"
    return "", ex, body


def fam_call_and(t, name):
    """return (callee() & mask) != 0, not as a tail call"""
    g = match([r"addiu \$29, \$29, -16", r"sd \$31, 0\(\$29\)", r"jal (func_\w+)", r"nop", r"andi \$2, \$2, (0x[0-9a-f]+)", r"ld \$31, 0\(\$29\)", r"sltu \$2, \$0, \$2", r"jr \$31", r"addiu \$29, \$29, 16"], t)
    if not g:
        return None
    ex = [f"int {g[0]}(void);"]
    body = f"int {name}(void)\n{{\n    return ({g[0]}() & {g[1]}) > 0;\n}}\n"
    return "", ex, body


def fam_setf_call2(t, name):
    """o->f = x; A(o); B(o);   (A and B take o; x stays in $f12 for A)"""
    g = match([r"addiu \$29, \$29, -32", r"sd \$16, 0\(\$29\)", r"daddu \$16, \$4, \$0", r"sd \$31, 16\(\$29\)", r"jal (func_\w+)", r"swc1 \$f12, (\d+)\(\$16\)",
               r"daddu \$4, \$16, \$0", r"ld \$31, 16\(\$29\)", r"ld \$16, 0\(\$29\)", r"j (func_\w+)", r"addiu \$29, \$29, 32"], t)
    if not g:
        return None
    off = int(g[1])
    src = f"typedef struct {{ char pad[{off}]; float v; }} S;\n"
    ex = [f"void {g[0]}(void *);", f"void {g[2]}(void *);"]
    body = f"void {name}(S *s, float x)\n{{\n    s->v = x;\n    {g[0]}(s);\n    {g[2]}(s);\n}}\n"
    return src, ex, body

FAMILIES = [fam_setf_call2, fam_call_and, fam_ptr_call, fam_zero_arg, fam_countdown, fam_flagcall, fam_top_call, fam_top_setbit, fam_top_cond]


def main():
    elf = asm_build.Elf(open(asm_build.EXE, "rb").read())
    text = elf.section(".text")
    code = elf.data[text["off"]:text["off"] + text["size"]]
    rows = list(csv.DictReader(open(os.path.join(ROOT, "decomp", "functions.csv"))))
    done = set()
    for path in glob.glob(os.path.join(ROOT, "src", "**", "*.c"), recursive=True):
        if path.startswith(OUT):
            continue
        done |= {int(a, 16) for a in re.findall(r"func_([0-9A-Fa-f]{8})", open(path).read())}
    count = {}
    for r in rows:
        count[r["name"]] = count.get(r["name"], 0) + 1
    found = {}
    tried = 0
    for r in rows:
        addr, size, name = int(r["address"], 16), int(r["size_bytes"]), r["name"]
        if count[name] > 1:
            name = f"dup_{addr:08x}"
        if addr in done or size > 128 or not re.fullmatch(r"[A-Za-z_]\w*", name):
            continue
        ws = struct.unpack_from(f"<{size // 4}I", code, addr - text["addr"])
        ins = [ee_disasm.decode(w, addr + 4 * i) for i, w in enumerate(ws)]
        if any(i is None for i in ins):
            continue
        t = [f"{i[0]} {i[1]}".strip() for i in ins]
        for fam in FAMILIES:
            res = fam(t, name)
            if not res:
                continue
            tried += 1
            typedefs, ex, body = res
            src = typedefs + "\n".join(ex) + "\n" + body
            for extra in ([], ["-fexceptions"], ["-fno-gcse"]):
                if compile_check([(addr, name, src, [])], "991111-01", extra):
                    found[addr] = (name, typedefs, ex, body, r["group"] or "none", tuple(extra))
                    break
    os.makedirs(OUT, exist_ok=True)
    for old in glob.glob(os.path.join(OUT, "*.c")):
        os.remove(old)
    groups = {}
    for a, v in found.items():
        groups.setdefault((v[4], v[5]), []).append((a, v))
    for (g, extra), fl in groups.items():
        tag = re.sub(r"[^A-Za-z0-9_]", "_", g) + ("_" + "".join(e.strip("-").replace("-", "") for e in extra) if extra else "")
        with open(os.path.join(OUT, tag + ".c"), "w") as f:
            f.write(f"/* {g}: small functions found by instruction shape, generated by tools/gen_fam.py. */\n")
            if extra:
                f.write(f"// cflags: {' '.join(extra)}\n")
            f.write('#include "../common.h"\n')
            for a, (name, typedefs, ex, body, g_, e) in sorted(fl):
                sfx = f"{a:08X}"
                text_ = typedefs + "\n".join(ex) + f"\n// MATCH func_{a:08X}\n" + body
                text_ = re.sub(r"\bS\b", "S_" + sfx, text_)
                text_ = re.sub(r"\bItem\b", "Item_" + sfx, text_)
                text_ = re.sub(r"\bV8\b", "V8_" + sfx, text_)
                f.write("\n" + text_)
    print(tried, "candidates,", len(found), "matched")


if __name__ == "__main__":
    main()
