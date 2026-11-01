# Legaia 2: Duel Saga (PAL, SLES-50891) matching decompilation

Repo: WeAreTommyBruh/Legaia2-Decomp, branch `main`. A function counts as done only when its C compiles
byte-identical to the original (compiler: ee-gcc 2.9-ee-991111-01, `-O2 -G8`). Every other function is rebuilt
from the original assembly, so `python3 tools/asm_build.py all` must always print `MATCH`.

## Current progress (session 16: 12.71%; goal 12.70% reached; 12.75%, 13.00%, 13.30% not reached)

- Session 16: 3613 -> 3628 functions, 12.59% -> 12.71% (15 functions, +2,408 bytes). Tricks that paid: (1) callee prototype with the real ARGUMENT ORDER (`func_0029D010(char *, float, int, int)`, pointer before float, instead of Ghidra's `(float, ptr, ..)`) fixed the arg-setup scheduling for ~12 callers (2becb0 family, 2a8228/2a8358/2a8488/2a8600, 29ff50, 2a0d88); (2) `int` return on one callee (1749e0: `int func_001AB8F0`); (3) natural source order instead of a permuter-shuffled one (1f7970 style); (4) hidden extra pass-through args to give a frame (235680 needs 11 int params); (5) `while (p != 0) { if (cond) break; p = p->next; } return p;` for the find loop (2175e0); (6) 165ca0 needed `f(D, b)` pass-through of `b`. decomp-permuter hit 0 of 9 near misses this session. Callee prototypes that clash inside a shared `src/units/*.c` file need `name_ADDR(...) __asm__("name")` aliases.
- 3613 / 6254 functions matched (57.8%) at session 15 end; **12.59%** of code. Session 15 went 3579 -> 3613 (12.30% -> 12.59%); each higher goal the user set afterwards (12.70, 12.75, 13.00, 13.30) was out of reach: hand-matching yielded about one function per ten tool calls once the easy near misses were gone. Next session: spend time on long permuter runs for the 2-13 word near misses below before drafting new functions.
  - Written by hand, generated from instruction patterns (`tools/gen_tiny.py` and the other `gen_*` tools), and Ghidra output that already
    matches (`tools/gen_ghidra.py`). Everything counted is C.
- History: 3297 / 9.00% (session 8) -> 3421 / 9.81% (sessions 9-11) -> 3462 / 10.21% (session 12) -> 3498 / 10.54% (session 13) -> 3579 / 12.30% (session 14, in progress).
- Functions with a source file: 2042 / 6254 (32.7%); with a real name: 263 (4.2%); `.text` words disassembled: 98.3%.
- Biggest source files by matched share: `repetition.cpp` 50%, `pachislot.cpp` 27% (121 functions), `roulette.cpp` 31%,
  `pchsysw.cpp` 37%, `srivus.cpp` 38%. Biggest unmatched: `battle.cpp` (4% of 88 KB), `nori.cpp`, `yue.cpp`, `clas_min.cpp`, `shikimi.cpp`.
- Every push refreshes `report/report.json` and `report/recomp.json` (an identical copy: `cp report/report.json report/recomp.json`) and the numbers above.
- `report/report.json` is what the live ByteMatch badges and the website read; the numbers only move when it is refreshed and pushed.

## Where the project stands

- Steps 1 and 2 are done (compiler identified, executable rebuilt byte-identical). Step 3, matching functions in C, is in progress.
- Not every file was built the same way. A C file picks its build with header lines: `// compiler: 990721-r5900` /
  `990721` / `991111-01-as210` and `// cflags: ...` (`-fno-gcse`, `-fexceptions`, `-fno-schedule-insns`,
  `-fno-schedule-insns2`, `-fno-thread-jumps`, `-fno-omit-frame-pointer`, `-O1`). Hand-matched small functions live in `src/units/<report unit>[_variant].c` (one file per report unit and compile setting, so every report unit has its own source file; `tiny_hand*.c` stay in `src/`). `tools/emit.py`-style tools (`build/work/emit.py`) still append to `src/small_hand*.c`: run `python3 tools/split_units.py` afterwards (it appends the new blocks to the unit files and deletes the small_hand files), then `asm_build.py all`.
- Layout: `src/` matched C (`// MATCH func_XXXXXXXX` on its own line above the definition; prototypes never share that line),
  `src/gen*/` and `src/ghidra/` generated matches, `wip/*.c` near-miss drafts (`// WIP func_XXXXXXXX`,
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
- decomp-permuter is the best tool for 2-10 word near misses (about 1 in 3 solved in 90-100 s): write the current best source to `build/work/w/<addr>.c`
  (`ggshow.py ADDR` does it for ggnear candidates), run `python3 permw.py SECS ADDR...` from `build/work` (detached with `setsid nohup`, one at a
  time), copy `build/perm/<addr>/output-0-1/source.c` into a spec as ONE line and re-score it with `batch.py`: a "HIT" is not always real (20d248 was a
  false positive: the permuter's objdump hid a `lw`/`li` order swap).
- `build/work/ggscan.py MAXBAD LO HI` re-scores every ggnear candidate with the real checker; ignore candidates whose real score differs a lot from `bad`
  (the 0x1364c8..0x137a18 family: ggnear said 3, real diff 37-94). `blockperm.py ADDR...` permutes runs of simple statements in a ggnear text.
- Report units carry `metadata.source_path` (the repo file with the most matched code of that group). `merge_groups` in `tools/report.py` used to take
  the metadata of the group's first sub-unit, which lost the path for ~36% of matched functions (battle, nori, rsound, ...); it now picks the sub-unit
  with a path and the most matched code, so every unit with matched code links to an existing file.
- Bound-checked table getters (`if (a >= 10 || b < 0 || (unsigned)b >= 94) return DEFAULT; return T[b].f;`) need the three tests as one `||` chain with
  the third unsigned; list pops like `t = L.v[L.n--]` and pointer-reusing `a = (char *)*(int *)(...)` fixed register naming (24a190, 223500).
  Hardware/kernel code: `__asm__ volatile("sync")`, `".word 0x42000038"` (ei), `"mfc0 %0, $12"`, `"cache 0x10, 0(%0)"` inside normal C matched whole
  functions (2e60f0, 2e5d30, 1096c0); volatile on the gp scalars they touch stops delay-slot hoisting (10f268).
- Website (`site/template.html` + `site/build_site.py`, deployed by `.github/workflows/pages.yml`, which checks out 30 commits for the history): the progress
  section shows badges, cards for code / functions / fuzzy match / data, the categories panel and the recent commits, all filled from `report/report.json`
  and `git log`; no "See the progress" button in the hero (the user asked to remove it). Matching resumed afterwards for the 12.30% goal (reached at 3579 functions); stop again unless the user sets a new target.
- README badges are SVG files in `badges/` drawn by `tools/badges.py` in the website's style; `tools/report.py` regenerates them whenever it writes
  `report/report.json`, so commit `badges/*.svg` together with the report.
- csv size quirk: 155738 absorbs the next 8-byte function; a 1-word diff with no `!=` line is the known `jr` delay-slot size quirk.

## Rules

- **Do not use agents, workers or subagents** (no Agent tool, no forks, no background workers) for matching or anything else in this
  project; work directly in the main session. (User instruction, session 14.)
- **Every push includes a refreshed `report/report.json`** (run `python3 tools/report.py`). `tools/progress.py` now writes
  `build/PROGRESS.md` (git-ignored) as a local summary only; `PROGRESS.md` is no longer committed.
  `build/work/commit.sh "msg" files...` checks the build says MATCH, regenerates the reports, commits and pushes.
  If a push is rejected: `git pull --rebase origin main`, rebuild, push again.
- **No assembly stubs.** A function counts as matched only when C compiles to its bytes. `src/asm_stubs.c` (168 hand-written-assembly functions
  reproduced as file-scope asm) was removed at the user's request (session 14); those functions are built from the original assembly again. The libvu0
  routines (0x18eaa0-0x18f..., ~124 functions) must not be added either.
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

Hardware-register functions not yet tried: 2c3620 (sync + 64-bit packing), 2c8bb0, 192168, 2bf6a8, 2bfec0, 2c0978. Drafted but not matched (IPU/DMA, compiler `991111-01-as210`): 2c6fa8 (~50 words, register numbering), 2c7120, 2c7228, 2c7318, 191ef0 (46).

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

- 136650 family (session 14): `[A][B][C][D]` multi-dim arrays of `volatile` structs (`extern E36 D_056C48E0[][256][8][32]`, gp ints as indexes, `e = &D[A][B][C][D]`) matched 136650, 1366e8, 136768 with the permuter's `int z = 0; e->s0 = z; ... n = e; n->s36 = 0` idiom; 1364c8 (three loops over the same table), 137298/137330/1367c8 (4-short entries with two address forms) are still open (see `fam_gp.txt` in build/work for the 19-function list). 2c6cd0 needed `if (x != 0 && y != 0) v = f(); else v = 0;` (true case first).
- Same-shape families (session 14 end): `yue_001e9c18` + 6 siblings (`-fno-gcse`, second pointer `q = p`, int `k`), the nayuwin2 slot loaders 1aa160/1aa270/1aa420/1a19b8/1aa050/1a9f20 (array-of-struct bases `B164 D_..[]`/`B232 D_..[]`, madd), found by grouping unmatched functions by opcode signature (`sigs` snippet in the session notes: group by mnemonic tuple, sort by total bytes). Remaining identical-shape pairs: 167940/167b88, 2ece08/2ed010, 1e43d0/1e4568, 127bb8/127d50, 20cb90/20cd08, 2cb978/2cbc90, 276b50/276dd4, 137dc8/137ed8 (slot finder: do-while loops get closest, ~65 words off).
- `src/ghidra/ggint_*.c` (session 14 end): Ghidra bodies from the ggnear search with every `undefined8` (and sometimes `ulong`/`long`) narrowed to `int`, callee prototypes included; this alone fixed 2e86a8, 2a3ed8, 2c7ec0 (`build/work/ggint.py` rescoring all ggnear entries, `emit_ggint.py ADDR` writes the file, `w2gg.py ADDR` converts a hand-fixed `w/<addr>.c`). Also: data addresses passed as call arguments need `D_` arrays and code addresses `func_XXXXXXXX` symbols (188c70, 2a2ba0); an `if (x) return 1; return 0;` with the compared global copied into a local first fixed the shuffle_ family; `float` locals reused for the product (`g = g * 128.0f * k`) fixed 12a140; explicit per-field load temporaries (`u1 = e->a0; u2 = e->a4; ...`) fixed 218738/218978; a `void` function whose early exit returns the zero it just tested (batread_) must not be declared `int`.

## Session 15 tricks (3579 -> 3612 functions, 12.30% -> 12.57%)

- `build/work/` helpers added: `t.sh ADDR [cc xf]` (diff one draft in `w/`), `cfgs.py ADDR` (all compiler variants), `var.py ADDR tpl.c` (`{{a|||b}}` choice groups; `VCC="cc|xf;..."`; it leaves the template in `w/` on a miss, `rs.score` always overwrites `w/ADDR.c`, so copy drafts before looping), `tospec.py`, `knob.py`/`knob_all.py` (pass-through params), `stperm.py`/`stperm2.py`/`stmove.py` (statement permutation/move search; stperm solved 2988a0), `prepwip.py`, `wipscan.py`, `commit2.sh` (also commits recomp.json + badges). `batch.py` and `emit.py` now know plain `990721-r5900`.
- Callee prototypes from Ghidra often hide arguments: pass the caller's own parameters through (`f(a,b,c,d)` where Ghidra said `f(void)`) to fix argument copies/prologue order (1925f8, 2132e0, 213368, 2c2be0).
- Pointer parameter plus an `int` copy (`void f(int *o) { int p = (int)o; ... g(o); }`) reproduces the `daddu` copy at entry (215858, 2153c8, 215420).
- Multi-index tables: `extern E28 D_0062B3D0[][4]` with `D[a][b].f` (stride 112/28) instead of `*0x1c + *7` arithmetic (2c9bb8..2ca610 family). Data addresses are `D_` arrays (`lui+addiu`), or an adjacent base array with a large index when `lw` offsets are big (29b1a0).
- Early returns (`if (...) return 0;`) instead of a result variable fix `daddu $2,$0,$0` delay slots; `x = base; ... q + 6676` needs the base in a separate local assigned inside the branch (2533e8, 25d4b0).
- `volatile unsigned *` for MMIO read-modify-write; IPU/DMA code (2c7850, 2c6ef8) matches with compiler `991111-01-as210`; `if (c++ > 5000)` gives the `daddu` copy of the counter.
- Floats: callees taking floats need real `float` prototypes (21b468); GS packets with `long *q` stores (see clas_min_002a53b0).
- Near misses left (all in `build/work/w/`, 1-6 words off): 2cf1b0/2cf2c0 (2, wip draft), 1d8250/20ddf8/20fd88/177348/247a48/165ca0/2d37c0/2cf4b0/2cf610 (2), 2b32a8 (2, 536 bytes), 2b8ee8 (2, 872 bytes, two swapped `lui`), 1949e0 (2), 2d3628 (3), 215ac8 (4), 213258 (5), 2c7318/2c7228/2c7120 (IPU, as210), 113ec8 (2, 990721-r5900), 167940/167b88 (18 each, 580 bytes, 990721-r5900, final `movn` vs branch), 137dc8/127bb8 (far). WIP files in `wip/` may already be matched: check before spending time.

## Session 15 end: workflow notes and open drafts

- Hand-match loop that worked: `build/work/show.sh ADDR...` (raw Ghidra from `decomp/src/` plus the asm) -> write `w/<addr>.c` (D_ symbols for data, gp offsets: symbol = 0x4A7C70 + offset, struct arrays, pass-through args) -> `python3 autofix.py ADDR [secs]` (best compiler config, then `stperm2.py` and `stmove.py` statement search) -> `permw.py` via `pq.sh` for what is left -> `tospec.py`, `batch.py`, `emit.py` -> `python3 tools/split_units.py` -> `asm_build.py all` -> `tools/progress.py`, `tools/report.py`, `cp report/report.json report/recomp.json`, commit, push.
- `wip/*.c` can already be matched; `wipscan.py` scores them under every compiler config, `prepwip.py ADDR...` copies the best config into `w/`.
- Rebuild rule after a split: `tools/split_units.py` appends to `src/units/<unit>[_variant].c`; the unit is the `group` column of `decomp/functions.csv`.
- Drafts left in `build/work/w/` with their distance (words): 2cea70 (4, as210), 1266f8 (10, `-fno-gcse`, permuter was stopped), 23b7c0 (13), 2499c0/249a30/249aa0 (2-4, float matrix writers, only the `ld $31` slot differs), 2d3628 (3), 2b8ee8 (2, 872 bytes), 2b32a8 (2, 536 bytes), 167940/167b88 (18, `movn` vs branch), 203f40 (42, wants hoisted array bases), 129a38 (42, original uses `movz`/`movn` for `a != 0 && f() != 0`), 2a4840 (29, `-fno-gcse`), 2a4020 (45).
- Ghidra-variant searches over never-examined functions (`ggone2.py`, `ggone3.py`) and over the sibling-shape list (`sigs7.py`) gave nothing new: best candidates were 39-45 words off.
