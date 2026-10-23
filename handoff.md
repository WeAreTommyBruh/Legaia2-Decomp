# Legaia 2 decomp handoff (2026-10-23, end of session 4)

## 1. STATUS
- Repo: WeAreTommyBruh/Legaia2-Decomp, branch `main`. PAL SLES-50891. Progress **~2420/6254** matched (see PROGRESS.md); `python3 tools/asm_build.py all` prints `MATCH`.
- **EVERY push must include a refreshed `report/report.json` and `PROGRESS.md`.** Run `python3 tools/progress.py` and `python3 tools/report.py` (or `build/work/commit.sh "msg" files...`, which checks the build says MATCH, runs both, commits and pushes) before pushing, and commit both files with the match. If a push is rejected: `git pull --rebase origin main`, rebuild, push again. Never force-push.
- Session 4 (2026-10-23) added ~250 matches, nearly all small functions in `src/small_hand*.c` (one file per compiler setting: plain, `_eh` = -fexceptions, `_nogcse`, `_nosched` = -fno-schedule-insns, `_O1`), plus the generated families in `src/gen_fam`, `src/gen_new`, `src/gen_static`.
- Local helpers (git-ignored, in `build/work/`): `lst.py LO HI SKIP N` lists unmatched small functions' asm (only `// MATCH func_X` counts as done); `batch.py specN.txt` scores guesses under 8 compiler settings (entries separated by `###`, first line = hex address, the function name must be the one in functions.csv); `dedupe.py` then `emit.py` append score-0 entries to the right `src/small_hand*.c`; `wk.py diff ADDR` shows a word diff of the last scored draft; `sweep.py`/`wipsweep.py` retry old specs/wip drafts under new flags; `commit.sh`. If they are gone, the loop is: write C, compile with tools/match.py, compare, add `// MATCH func_XXXXXXXX` above the function (prototypes on their own line), rebuild, commit.

## Report layout and WIP drafts
- tools/report.py builds per-file objdiff units, then `merge_groups` folds each source group into ONE unit named after the group (combined figure on bytematch.dev; sums equal the top-level totals). The per-file/`gen`/`ghidra`/`wip` split only exists inside build/objdiff.
- `wip/<addr>.c` holds near-miss drafts (`// WIP func_XXXXXXXX` instead of `// MATCH`; include `../src/common.h`). tools/report.py compiles them as a unit `<group>/wip/<addr>` so bytematch.dev shows a partial match (in progress); the function row keeps its own %. Draft data (.rodata) is left out of the data totals. How the site colours 'In progress' is undocumented (unconfirmed). Not built by asm_build. When one matches: move it to src/ with `// MATCH`, delete the wip file.

## Rules (user)
- No copyrighted assets: only tools/docs/C in repo; game data git-ignored. Don't print game text in chat. No game string literals in C (use `D_<addr>` symbols).
- Commit to main. Ask before downloads / visibility change. **Never force-push** (denied before). Keep CPU jobs modest (user killed background jobs).
- Commit trailer: `Co-Authored-By: Claude Sonnet 5.5 <noreply@anthropic.com>` (commit.sh already set).

## 1b. SHIKIMI (29/42 matched, 13 left; 8 matched in session 3: 2b11f8 2b1b30 2b1b98 2b8de0 2b1d88 2b0bc8 2b0dd8 2b3198)
- Group `shikimi` is 27/42. Hand-matched: `src/shikimi.c` (14, 991111-01 default) and `src/shikimi_r5900.c` (6: 2b1b30, 2b1b98, 2b8de0, 2b11f8, 2b1d88, 2b0bc8; header `// compiler: 990721-r5900`). **The group is a mix of compilers**: 14 small ones match with either, the six above only with 990721-r5900, and 2b10a0 / 2b2778 look like 991111-01 (a tail call `j` and a nop before the loop branch). Always score a draft under both (`CCV=990721-r5900` and `CCV=991111-01` with `build/work/wk.py diff ADDR -q`).
- Tools in build/work (git-ignored): `mkbig.py ADDR [STRADDRS]` (Ghidra text -> draft), `vt.py ADDR variants.txt` (variants split by `=====`), `hc.py ADDR` (annealing over the order of lines between `// PERM-BEGIN/END`), `toggle.py`, `mkfile.py OUT.c ADDR...` (draft files -> source, dedupes headers; each draft needs `// MATCH func_XXXXXXXX`), `perm.sh ADDR SECONDS` (decomp-permuter), `constcount.py`.
- What worked: floats/ints through typed arrays (`float *d` with `((int *)d)[1]`) so loads are not hoisted over stores (the fields really are one type); a single shared `return 1` block; initialising `float fr = 1.0f` first (1.0f hoisted to the prologue, shape `if (a != b) fr = (fr/..)*.. else fr = 0`); `switch` with case bodies in the **jump-table address order** (read the table from the exe: `match.original_words(table_addr, n)`) because layout = source order and register priority follows live ranges; `(unsigned short)` temporaries to get `lhu`; `int lo = a - 1; r = b - lo;` stops gcc turning `b - (a - 1)` into `(b + 1) - a`; nested call `f(g(x), ...)` instead of a temp (changed which values live across a call); a fall-off-the-end `DbgPrintf(x);` (no `return`) gives the tail `j`; cross-jumping merges identical case tails into the LAST body that has them (can't be switched off).
- User said "dont do the big functions": skip 2afa58, 2b0100, 2b12c8, 2b1e68, 2b2900, 2b34d8, 2b3f10, 2b8650. Near-miss small ones have drafts in wip/ (2b32a8 2 words, 2b8ee8 2 words (swapped lui $19/$20), 2b10a0 regs only (991111-01), 2b2778, 2b0978). The permuter queues for them were stopped without results.
- Older notes (2b0dd8 and 2b3198 are now MATCHED; 2b8ee8 draft exists) - left: 2b32a8 (2 words: in the 0x2000 case body `$5=16`/`$6=104` come out swapped; the 0x8000 and 0x2000 bodies would be merged by cross-jumping if both were `id,x,y`; draft w/002b32a8.near), 2b0dd8 (16 words: loop counter/entry/pointer registers $16-$18 in a different order; switch form matches otherwise), 2b3198 (3 ops: i/0x1000 registers swapped and an `addiu` placed earlier), 2b10a0 (991111-01; same code, registers only), 2b2778 (switch, return in each case; needs the exact store order, e in $7 not $5), 2b0978 (bit clears: original keeps 12 redundant `and`s before an `andi 0xffff`, mine lets gcc drop them; needs unsigned-mask statements in the original order, constants li/ori), 2b8650 (VM op switch; case bodies in table order now match up to case 5; `o`/`r` registers swapped), 2b8ee8 (needs a 9-byte string copy; no game string literals allowed -> not attempted), and the big ones (2afa58, 2b1e68, 2b12c8, 2b0100, 2b2900, 2b34d8, 2b3f10).
- global alloc priority = floor_log2(refs)*refs/live_length: find it with `-dg` (cc1 dump `x.c.greg`, lists "Register N, refs, live_length" and the dispositions).

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

## 6. NEW IN SESSION 4 (matching techniques)
- `-fno-schedule-insns` (first scheduling pass off) is needed by some functions (stores stay in source order). Try it and `-fexceptions` / `-fno-gcse` for every guess.
- A load that is not hoisted or reused (`blez; nop` with a reload in the body, a store stuck before `jr; nop`) means the object is `volatile` (struct member, or `volatile float` global).
- MMIO / constants kept in a register: `int *p = (int *)0x10000800; __asm__("" : "+r"(p)); *p = v;` (plain deref, the asm only pins the constant). Float zeros stored from an FPR (`mtc1 $0,$f0; swc1 $f0,..`): `float z = 0.0f; __asm__("" : "+f"(z));` then store `z`. Zero float call arguments work without tricks.
- Write stores in the struct's field order; if the compiler reverses or rotates independent stores, try the other rotation (search permutations when a draft is within ~10 words).
- Inline `static inline` helpers (`set(V4 *v, x, y, z)`) reproduce the "first field via $4, rest via a derived pointer" addressing.
- Branch layout: `if (v != 0 && v != 10) return 0; return 1;` gives the `beq ... li 1 in delay` shape that `return v==0||v==10` does not; add `(v ^ 0x65) != 0` to stop gcc merging 100/101 into a range test; `(x & 0x10000000) > 0` gives `sltu`; `while (f() == a);` is a busy-wait loop.
- Declare a first callee with fewer arguments (`f1(a); f2(a, b)`) to change prologue / delay-slot order; a symbol the original loads with `lui` (not gp-relative) must be declared as an array (`extern int D_x[]`).
- Two symbols with conflicting types in one file: rename with an asm label, `extern T D_x_sfx __asm__("D_x");` (data) / `void func_X_sfx(...) __asm__("func_X");` (functions).
- Group `_unknown_after_*` objects are not all the same compiler: 990721-r5900 for the abeshi group, 991111-01 elsewhere.
- Unsolved: (a) the last `sdr` of an 8/16-byte unaligned struct copy sits in the `jr` delay slot in the original (~10 functions, e.g. 1649e0, 12af88, 16e4e0, 25f778). cc1 only splits the block move (`movstrsi_internal2/3`, the last store then fills the slot) when both addresses are bare registers; a destination with a displacement or a symbolic source keeps it in one insn. No compiler (all of ~/tools tried), flag or source shape found yet. (b) the 17 static-singleton accessors from 2db238: only the order of two lui/addiu pairs differs (permuter best: 4 words). (c) 265c30, 23de38, 23e518, 23f2d0, 25ea38, 25eca8, 25f388 (see wip/). (d) floats initialised in three interleaved blocks (1e9468 family, 21 of 30 words).
