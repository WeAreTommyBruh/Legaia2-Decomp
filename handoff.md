# Legaia 2 decomp handoff (2026-10-18, end of session 2)

## 1. STATUS
- Repo: WeAreTommyBruh/Legaia2Decomp, branch `main`. PAL SLES-50891. Progress **1727/6254** matched; `python3 tools/asm_build.py all` prints `MATCH`.
- This session matched (all in `_unknown_after_abeshi`, now 41/54): 26ac80, 269240 (src/after_abeshi_990721_c.c), 2650d0 (same file), 265230 (src/after_abeshi_990721_d.c), 2656b0 (src/after_abeshi_990721_e.c; needs the div.s nops, see below). report/report.json and PROGRESS.md are refreshed by `build/work/commit.sh` (user asked for both on every commit); tools/report.py now handles R_MIPS_LITERAL (.lit4).
- Drafts/tools (git-ignored) in `build/work/`: `wk.py diff ADDR [-q]`, `vtry.py`, `all3.py`, `flags2.py`, `commit.sh "msg" files...` (build must say MATCH; runs progress.py + report.py, commits, pushes), drafts in `w/`. Permuter: `python3 tools/perm_setup.py build/work/w/<addr>.c FUN_<addr> <addr>` then `~/tools/decomp-permuter/venv/bin/python permuter.py build/perm/<addr> -j2 --stop-on-zero` under `timeout`; wait on its PID with `kill -0` (not pgrep -f).

## Rules (user)
- No copyrighted assets: only tools/docs/C in repo; game data git-ignored. Don't print game text in chat. No game string literals in C (use `D_<addr>` symbols).
- Commit to main. Ask before downloads / visibility change. **Never force-push** (denied before). Keep CPU jobs modest (user killed background jobs).
- Commit trailer: `Co-Authored-By: Claude Sonnet 5.5 <noreply@anthropic.com>` (commit.sh already set).
- User mostly says "keep going"; last instruction was "do only one" per turn.

## 1b. SHIKIMI (done: half)
- Group `shikimi` is 21/42 matched (src/shikimi.c has 14 by hand; 7 were already in src/gen and src/ghidra). The mostly-constructor-like functions (build a stack object, pass &obj to a worker) match from the Ghidra text turned into a struct with the stores in asm order; `build/work/permstmt.py ADDR` brute-forces the order of the lines between `// PERM-BEGIN` and `// PERM-END` (a draft with 8 lines is 40k compiles, keep blocks <= 8).
- Left in the group: 2b1b30 (needs the loop top aligned with a nop and a `daddu $7,$3,$0` hi copy; plain `for` over a 96-byte record array gets within 2 ops), 2b1b98 (negative-index branch: hi kept in $5 across the loop), 2b8de0 (quote-stripping copy: original loads lb for compares and lbu for the store separately), 2b11f8, 2b1d88, 2b3198, 2b0bc8, 2b10a0, 2b2778, 2b32a8, 2b0dd8, 2b0978, 2b8ee8 and the big ones (2afa58, 2b8650, 2b1e68, 2b12c8, 2b0100, 2b2900, 2b34d8, 2b3f10).

## 2. CLOSE BUT UNMATCHED (drafts in build/work/w/)
- **2682e0** (15 of 99 words, ~6 ops): `w/002682e0.c`; the loop/px-py/unfolded-table parts match; left: lbu-y goes in the beq delay slot in the original (nv3/new_var trick got closest), store `addu` operand order, a `bnel` vs `bne` at the first loop's end.
- **260428** (7 words): sll goes in the bltz delay slot in the original (scheduler order: sll before lui), r in $6.
- **269fc8** (22 words with `// cflags: -fno-thread-jumps -fno-cse-skip-blocks`): original reuses $4 (= &D_003FEBA8) after the b1ab if in cases 5/6; mine recomputes from $21.
- **265c30**: original keeps separate pointers for D_00419D50 (+0, +44) and base+4 with an offset giv; a mini harness (below) was not tried on it yet.
- Others (big/switch): 260658, 261288, 261bd8, 264868, 265db0, 268580, 269838, 26a658, 26af38; nori's remaining ones are fragments of the 275a30 switch; cam_min 2aa360/2aa588/2a9ee0 (fptosi).

## 4. TECHNIQUES THAT MATCHED
- 990721-r5900 = 990721 cc1 -S, then `r5900_short_loops.py` (un-fill delay slot for backward-branch loops <=6 insns with no other b/j, incl. fills taken from loop top), then 991111-01 assembler.
- Struct-pointer params instead of int+FIELD (no aliasing between struct fields and scalars); chained assigns `q->a = o->a = o->a0`; `(u8)L[i]` on s8 list; read to locals before stores; `i = k` loop increments; `int saved[7]` arrays; `p + 12 + i*936` as int arithmetic.
- madd/mtlo (`.word 0x72231800`) for `base + i*72`: copy the table address to a local pointer declared **before** the loop and assign it right before the loop (not at the top, not in the initializer):
```c
Slot *tbl; int i;
...
tbl = D_003FDFA0;
for (i = 0; i < 5; i++) {
    { Slot *s = tbl + i; s->b43 = s->b42; }
}
```
  Placement of that assignment also changed register numbering of earlier `saved[]` loads ($6 skipped otherwise).

## 5. NEW THIS SESSION (details also in the compiler-variants memory)
- Mini harness: compile a small C file with `asm_build.COMPILERS['990721-r5900']` and `-S` (plus `-dr -ds -dj -dg` for RTL dumps) to see how one construct compiles before touching the big function.
- Compare inside each branch (`if (i<4) { if (A[i]==a) cnt++; } else { if (B[i-4]==a) cnt++; }`) changes the if-converted insn order; giving each switch case its own temp pointers (`e`, `e0`, `s`, `s0`; sharing only `q`) fixes register assignment; `e = SYM; e -= 5; q = e + a;` stops SYM-2360 being folded into one %lo; `cur > mx * -c / 100` operand order changes load order; pointer `py = row + 4` (same symbol) gives the unreduced loop without -fno-strength-reduce; reusing a dead local as a loop variable (2650d0) changes register priority.
- 990721-r5900 now puts two nops before every div.s (tools/r5900_short_loops.py fix_div_s), as 991111-01 does.
