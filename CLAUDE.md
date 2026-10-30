# Legaia 2: Duel Saga (PAL, SLES-50891) matching decompilation

Repo: WeAreTommyBruh/Legaia2-Decomp, branch `main`. A function counts as done only when its C compiles
byte-identical to the original (compiler: ee-gcc 2.9-ee-991111-01, `-O2 -G8`). Every other function is rebuilt
from the original assembly, so `python3 tools/asm_build.py all` must always print `MATCH`.

## Current progress (session 14 in progress, last push below)

- 3670 / 6254 functions matched (58.7%); 240,376 / 2,022,408 code bytes = **11.89%** (user goal for session 14: 12.01%; 11.54% was reached first).
  - 1752 written by hand, 758 generated from instruction patterns (`tools/gen_tiny.py`), 820 Ghidra output that
    already matches (`tools/gen_ghidra.py`), 168 hand-written assembly reproduced as file-scope asm in `src/asm_stubs.c`.
- History: 3297 / 9.00% (session 8) -> 3421 / 9.81% (sessions 9-11) -> 3462 / 10.21% (session 12) -> 3498 / 10.54% (session 13) -> 3670 / 11.89% (session 14, in progress).
- Functions with a source file: 2042 / 6254 (32.7%); with a real name: 263 (4.2%); `.text` words disassembled: 98.3%.
- Biggest source files by matched share: `repetition.cpp` 50%, `pachislot.cpp` 27% (121 functions), `roulette.cpp` 31%,
  `pchsysw.cpp` 37%, `srivus.cpp` 38%. Biggest unmatched: `battle.cpp` (4% of 88 KB), `nori.cpp`, `yue.cpp`, `clas_min.cpp`, `shikimi.cpp`.
- Every push refreshes `report/report.json` and `report/recomp.json` (an identical copy: `cp report/report.json report/recomp.json`) and the numbers above.
- `report/report.json` is what the live ByteMatch badges and the website read; the numbers only move when it is refreshed and pushed.

## Where the project stands

- Steps 1 and 2 are done (compiler identified, executable rebuilt byte-identical). Step 3, matching functions in C, is in progress.
- Not every file was built the same way. A C file picks its build with header lines: `// compiler: 990721-r5900` /
  `990721` / `991111-01-as210` and `// cflags: ...` (`-fno-gcse`, `-fexceptions`, `-fno-schedule-insns`,
  `-fno-schedule-insns2`, `-fno-thread-jumps`, `-fno-omit-frame-pointer`, `-O1`). `src/small_hand*.c` is one file per setting.
- Layout: `src/` matched C (`// MATCH func_XXXXXXXX` on its own line above the definition; prototypes never share that line),
  `src/gen*/` and `src/ghidra/` generated matches, `src/asm_stubs.c`, `wip/*.c` near-miss drafts (`// WIP func_XXXXXXXX`,
  compiled only by `tools/report.py` for partial-match figures, not part of the build), `tools/` format tools and builders,
  `site/` project website (GitHub Pages, rebuilt from `report/report.json`).
- Tools: `tools/match.py src/FILE.c NAME ADDRESS` compares one function word by word; `tools/asm_build.py all` rebuilds and
  checks; `tools/progress.py` and `tools/report.py` write the progress figures; `tools/perm_setup.py` sets up decomp-permuter.
- Techniques that paid off (details were in the old handoff and are in the memory notes):
  - Callee return types are the biggest cheap knob: declare a callee `int` instead of `void`, or copy its matched definition's type.
  - Typed vtable structs (`o->vt->fn60((char *)o + o->vt->adj56, 1)`) instead of raw casts.
  - `volatile` for flag words and output pointers (stops hoisting and CSE; fixes most scheduler-order near misses).
  - Separate loop counter (`i = n`), typed struct pointer for a callee-saved base, hidden pass-through parameters when an argument is copied into `$8`.
  - Sibling-shape search: copy matched C onto unmatched functions with the same mnemonic sequence.
  - Statement-order search (`perm.py`, hill climbing) and decomp-permuter (~7% of near misses solve).
  - `991111-01-as210` (newer assembler) explains the `sdr` in the `jr` delay slot functions and `lui/ori/sw` hardware-register code.
  - Hardware-register code is mechanical: `*(volatile unsigned *)0x1000b010 = ...` in asm order.

## Session 14 workflow and new tricks

- Session 14 first used parallel forked workers (address windows, then technique-based) that wrote `build/work/spec_wK_NN.txt` and
  `bo_wK_NN.json`; the main session merged the `bo_*.json` files into `batch_out.json` and ran `dedupe.py`, `emit.py`, `fixemit.py`, then
  `asm_build.py all` (must print MATCH), `tools/report.py`, commit and push. **The user has since ruled out agents, workers and subagents:
  do the matching yourself in this session** (the same spec/batch/emit flow works single-handed).
- Member-function-pointer calls (`ld -8` + `dsra32`) match with a hand-expanded ptmf: two separate `idx > 0` tests, one for the function and
  one for the delta (`fn = (void (*)(void *))(e >> 32); d = idx > 0 ? (short)e + dl : dl; fn(o + d);`). Untried: 171ae8 1723e8 173980 175f58 176ac8 176e10 17fc20 204a78 214fa8.
- Overlapping `lw`/`lh` fields reloaded after a store need a union. A pointer in a callee-saved reg may need a `static inline` helper taking `float *v`.
- GS-packet functions (`sd` constants + `func_00190328`/`func_00190420` calls) are tractable (2975b8, 2a53b0 matched); more at 24bd78 247970 2436f8.
- Separate base variable (`q = SYM; p = q + 8`) stops `-25104 + 8` folding into one `addiu`; one unsigned counter `for (i = 63; (int)i >= 0; i--)`
  for two loops; `p != 0 && n != 0` plus one post-loop `if (p == 0) return 0` for a shared fail block; copy newlib's variable names for newlib code.
- Write spec functions on ONE line (or `{` on the signature line and no line starting with a letter inside): `emit.py` puts `// MATCH` before the
  first line that starts with a letter after the prototype, which broke 2e8d58 once.
- Sibling tricks that worked (session 14, solo): callee `int` instead of `void` on one of 3 callees (1714a0, 2e8d58); unused extra params that are
  passed through (`f(char *o, int b, int c)` calling `g(o, b, c)`) put `o` in `$7` (2c31b8, needs -fexceptions); a constant held in a local before a
  call goes to a callee-saved reg (2c3458); statement order `v = *p; p++; f(v); i--;` fixed delay-slot order (18d4a8, 990721-r5900 -fno-thread-jumps);
  list unlink `for (; p != 0; p = p[5]) { if (p[5] == n) {...; break;} }`; a `key == -1` early return then one loop (2a1df8).
- `build/work/ggnear.py K N MAXSIZE` (best Ghidra variant per unmatched function, `ggnear_K.json`) + `ggshow.py ADDR` (score it and write `w_<addr>.txt`)
  finds near misses whose diff is small; hand-fix them: Ghidra's `0x3f000000` float constants -> `0.5f`; offsets in `lb`/`lhu` mean the field types (signed vs
  unsigned); `ld`/`lq` mean `long long`/`u128` (`typedef int u128 __attribute__((mode(TI)))`); a 2-word diff with `addiu` vs `ori` constants means the
  number is an address (use a `D_` array); `divu` means unsigned operands; array-of-struct getters/setters match with `E *e = &D[idx]; return e->f;`
  (a plain `D[idx].f` gives a different `mult` operand order); struct stride 472 with a field beyond it: `((E *)(D + i * 472))->f`. Write callee names in
  specs with UPPERCASE hex (`func_00254F48`): lowercase hex is an undefined symbol at link time.
- csv size quirk: 155738 absorbs the next 8-byte function; a 1-word diff with no `!=` line is the known `jr` delay-slot size quirk.

## Rules

- **Do not use agents, workers or subagents** (no Agent tool, no forks, no background workers) for matching or anything else in this
  project; work directly in the main session. (User instruction, session 14.)
- **Every push includes a refreshed `report/report.json`** (run `python3 tools/report.py`). `tools/progress.py` now writes
  `build/PROGRESS.md` (git-ignored) as a local summary only; `PROGRESS.md` is no longer committed.
  `build/work/commit.sh "msg" files...` checks the build says MATCH, regenerates the reports, commits and pushes.
  If a push is rejected: `git pull --rebase origin main`, rebuild, push again.
- **Keep C only for new matches**: the user declined adding the libvu0 vector routines (0x18eaa0-0x18f..., ~124 functions, ~6,300 bytes of SDK hand
  assembly) to `src/asm_stubs.c`; the existing 168 stubs stay, but do not add more.
- **Never force-push.** (Session 12 and 13: the user allowed one only if unavoidable; it was not needed.)
- Commit to `main`. Ask before downloads or any visibility change.
- No copyrighted assets: only tools, docs and C in the repo; game data stays git-ignored. Do not print game text in chat.
  No game string literals in C (use `D_<addr>` symbols).
- Keep CPU jobs modest (the user has killed background jobs before). `commit.sh` and `asm_build.py all` take over two minutes:
  run them in the background, do not edit `src/` while they run, and do not run `asm_build.py all` while `commit.sh` runs.
- Never `pkill -f` / `pgrep -f` with a pattern that appears in your own command line (it kills the shell). Use
  `ps -eo pid,cmd | grep '[p]ermuter.py' | awk '{print $1}' | xargs kill`.
- Commit trailer: `Co-Authored-By: Claude Sonnet 5.5 <noreply@anthropic.com>`.
- Website decisions: no ByteMatch mentions on the site; the Maya image is still missing and must not be fetched by bypassing
  the fandom bot block.
- A compile that is shorter or longer than the original is not a match; trailing `nop` padding is ignored.
- Pitfalls:
  - `emit.py` mangles identifiers: never put `__asm__("D_xxxx")` in a spec, a duplicate `typedef char *va_list;` breaks the
    file, and `T *` prototypes become `void *`. Run `asm_build.py all` right after every emit and read the last lines of the output.
  - A stale `// OFF func_X` entry in an old small_hand file causes a duplicate-symbol link error once the function is matched elsewhere.
  - `gen_ghidra.py` without `GG_NEW=1` regenerates `src/ghidra` and drops old matches (`git checkout src/ghidra` restores them).
  - A global the original reaches with `lui+lw` is an array; with `$28` (gp) it is a scalar. 8-byte unaligned globals need `V8 D[3]`.
  - `git pull --rebase` fails while any tracked file is modified; pass tool changes as extra arguments to `commit.sh`.
  - Never run two processes that write the same `w/<addr>.c`.
- Local helpers live in `build/work/` (git-ignored: `commit.sh`, `batch.py`, `emit.py`, `wk.py`, `perm.py`, `hill2.py`, `permw.py`,
  `mkchunks.py`, `pair.py`, `untried.py`, ...). If they are gone, the loop is: write C, compile with `tools/match.py`, compare, add
  `// MATCH func_XXXXXXXX` above the function, rebuild, commit.

## Current open work

Near misses (words off), from sessions 12 and 13:

- Find-by-tag tails: 160778 (25), 1608a8 (9), 1609c8 (19), 160b48 (10), 160c70 (18), 160df8 (2), callers 160490 (24) and 160568.
- 2ce5a8 (2, store order of `sw $16,16($17)`), 2cf338 (1, `addu` operand order), 2ca968 (2), 1e2b40 (4), 1e3f88 (3),
  203d58 (16), 1e7cb0 / 1d7f00 (10), 2cb340 (27).
- 2ea9f0 / 2eabb8 / 2eb4c0 / 2ebab0: frame matches with `S_ { int a[8]; }` + `T *t`; the string-copy loop compares via `sll 24` and loads with `lbu`.
- 2a8c80 (struct array init with per-element base pointers), 1707d8 (38), 173630 (11), 178038 (16), 230188 (12), 1694d0 (13), 163d88 (12),
  137ca8 family, 1704e8 (9), 204c58 (23), 2a4338 (5), 165ca0 (2).
- GS packet builders 1632d0..163780 (64-bit field packing); member-function-pointer calls (`ld -8` + `dsra32`: 173980 is
  structurally right with a PMF struct but 9 words off; 171ae8, 164c10, 1723e8, 16e388 not tried).
- Older ones still open: 10af88 (480 bytes), 109d18 (64 KB stack array), 10a120, 10ec40, 154d20 / 154db8, 1545a8, 112a28,
  213410, 161868, 2128c8, 130ad8, 2682e0, 260428, 269fc8, 265c30, 2d8438, the 2cf* packet builders.
- Shikimi: 29 / 42 matched; user said "don't do the big functions" (2afa58, 2b0100, 2b12c8, 2b1e68, 2b2900, 2b34d8, 2b3f10, 2b8650).

Hardware-register functions not yet tried: 2c3620 (sync + 64-bit packing), 2c8bb0, 2c6ef8, 2c6fa8, 2c7120, 2c7228, 2c7318,
191ef0, 192168, 2bf6a8, 2bfec0, 2c0978.

Candidate chunk lists: `build/work/mkchunks.py ADDRHEX` regenerates `build/work/ch/c###.txt` (unmatched 60-450 byte functions).
Chunks 000-020 (addresses up to 0x187068) were read in session 12; continue from `ch021`.

Other ideas: rerun `ggnear.py` with a larger MAXSIZE, rerun `permq.py` / `permw.py` on new near misses, rerun `sweep4.py` after
adding compiler settings, and a posed model export in `tmd_tool.py` (apply the first frame of a motion clip) for character pictures.

## Housekeeping

- `git status` shows three untracked files that are meant to stay uncommitted: `site/index.html` (generated by
  `site/build_site.py`), `site/template_red_old.html` and `site/assets/lang.jpg` (original render with the red background).
- `FORMATS.md`, `PROGRESS.md` and `handoff.md` were removed from the repo (still in git history). Format details live in the
  docstrings of the `tools/` scripts; references in `CONTRIBUTING.md`, `README.md`, `site/template.html`, `tools/progress.py` and
  `build/work/commit.sh` were updated.
- The scratch Python venv with Pillow/numpy used for image work is `/tmp/claude-1000/imgvenv` (not part of the repo).
- README badges and the clone URL point at WeAreTommyBruh/Legaia2-Decomp; update them if the repo is renamed.
- Memory notes for this project live in `~/.claude/projects/-home-tommy-src-Legaia-2-Decomp/memory/`.
