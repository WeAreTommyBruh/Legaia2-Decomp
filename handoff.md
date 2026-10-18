# Legaia 2 decomp handoff (2026-10-18)

## 1. STATUS
- Repo: WeAreTommyBruh/Legaia2Decomp (redirects to Legaia2-Decomp.git), branch `main`, HEAD 6c309a2. Tree clean except this file (untracked, don't commit).
- PAL SLES-50891. Progress **1722/6254** matched. Build `python3 tools/asm_build.py all` prints `MATCH` (byte-identical ELF).
- Group counts: nori 26/64 (target 32), _unknown_after_abeshi 36/54 (target all), cam_min 2/5 (target all), _unknown_after_disp 53/106 (target met).
- Last match: FUN_0026a2b8 in `src/after_abeshi_990721_b.c` (with FUN_002695e0; separate file because .rodata placement is contiguous per file).
- Other files this session: src/after_abeshi.c (991111-01), src/after_abeshi_990721.c (990721-r5900), src/nori.c, nori_nogcse.c, nori_eh.c (-fexceptions), tools/asm_build.py (COMPILERS["990721-r5900"], SHORT_LOOP_FIX), tools/r5900_short_loops.py, tools/match.py (reloc type 8 = R_MIPS_LITERAL, gp0 from .reginfo+20).
- Drafts/tools (git-ignored) in `build/work/`: `wk.py diff ADDR [-q]` (compile w/<addr>.c with file's `// compiler:`/`// cflags:`, show diff, ops~ = opcode edit distance), `vtry.py ADDR BASE.c SPEC.json` (apply [old,new] variants, restores base), `all3.py`, `flags2.py`, `commit.sh "msg" files...` (refuses unless build says MATCH; commits, pushes), drafts in `w/`. Permuter dirs in `build/perm/` (none running).

## Rules (user)
- No copyrighted assets: only tools/docs/C in repo; game data git-ignored. Don't print game text in chat. No game string literals in C (use `D_<addr>` symbols).
- Commit to main. Ask before downloads / visibility change. **Never force-push** (denied before). Keep CPU jobs modest (user killed background jobs).
- Commit trailer: `Co-Authored-By: Claude Sonnet 5.5 <noreply@anthropic.com>` (commit.sh already set).
- User mostly says "keep going"; last instruction was "do only one" per turn.

## 2. CURRENT BLOCKER
No compile error. Open unmatched drafts:
- **FUN_00269fc8** (`build/work/w/00269fc8.c`, wk ops~10): needs its own C file (jump table at 0x496BA0). Original keeps `lui 0x40` (hi of D_003FEBA8) live in $21 across the switch and recomputes `a >> 1` inside the loop; mine doesn't.
- Others blocked: nori 275a30 big switch (27 fragment entries); cam_min 2aa360/2aa588 (fptosi issue); 2a9ee0 and 265c30 (original keeps extra loop pointers); 2650d0 (12 diffs, reg swaps); 260428 (7 diffs, reg choice); 26c8a0 (5 ops, reg reuse; needs `-malign-loops=2`).

## 3. NEXT STEPS
- `cd "/home/tommy/src/Legaia 2 Decomp"; git pull --rebase origin main` (user edits README on remote), confirm `python3 tools/asm_build.py all | tail -1` = MATCH.
- Pick next abeshi target: finish 269fc8 (try keeping D_003FEBA8 address in a local pointer assigned before the switch; try `a>>1` as separate expression in loop), else draft 26ac80 or 269240.
- Workflow per function: write `build/work/w/<addr>.c` with header `// compiler: 990721-r5900` + `// cflags: -fno-thread-jumps` (abeshi), loop `python3 build/work/wk.py diff <addr>`, use vtry.py for source variants; also sweep 991111-01, 991111-01 -fno-gcse via all3.py.
- When 0 diffs: move into the correct src file (check .rodata contiguity; separate file if jump table is far), add `// MATCH func_<ADDR>`, run build, then `build/work/commit.sh "Match <group> <addr> by hand (N / 6254)" <files>`.
- Then toward targets: ~6 more nori, rest of abeshi, cam_min (2 left unmatched + 1).

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
