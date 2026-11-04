# Legaia 2: Duel Saga (PAL, SLES-50891) matching decompilation

Repo: WeAreTommyBruh/Legaia2-Decomp, branch `main`. A function counts as done only when its C compiles
byte-identical to the original (compiler: ee-gcc 2.9-ee-991111-01, `-O2 -G8`). Every other function is rebuilt
from the original code, so `python3 tools/asm_build.py all` must always print `MATCH`.

## Current progress

- **14.01% of code, 3971 / 6254 functions matched.** `.text` is about 2.0 MB (`total_code` 2,022,408 bytes); the percentages measure only that.
- Reached goals: 13.51% (needed the libvu0 file-scope asm and the syscall wrappers, see Rules). Not reached: 13.81% (about 4,000 bytes short) and a
  request for 100 more functions (11 matched, 89 short). Hand matching yields about one function per 8-10 tool calls once the easy near misses are gone.
- History of the code share: 9.00% (3297 functions) -> 9.81% -> 10.21% -> 10.54% -> 12.30% (3579) -> 12.59% (3613) -> 12.72% -> 13.01% (3647) -> 13.57% (3926) -> 13.67% (3941) -> 13.69% (3944) -> 13.75% (3950) -> 13.80% (3954) -> 13.86% (3960) -> 13.92% (3965) -> 13.99% (3969) -> 14.01% (3971).
- Matched code is written by hand, generated from instruction patterns (`tools/gen_tiny.py` and the other `gen_*` tools), or Ghidra output that already
  matches (`tools/gen_ghidra.py`). Everything counted is C, except the libvu0 routines (file-scope asm in `src/vu0_asm.c`).
- Functions with a source file: 2042 / 6254; with a real name: 263; `.text` words disassembled: 98.3%.
- Biggest source files by matched share: `repetition.cpp` 50%, `pachislot.cpp` 27% (121 functions), `roulette.cpp` 31%,
  `pchsysw.cpp` 37%, `srivus.cpp` 38%. Biggest unmatched: `battle.cpp` (4% of 88 KB), `nori.cpp`, `yue.cpp`, `clas_min.cpp`, `shikimi.cpp`.
- Every push refreshes `report/report.json` and `report/recomp.json` (an identical copy: `cp report/report.json report/recomp.json`), plus `badges/*.svg`.
  `report/report.json` is what the badges and the website read; the numbers only move when it is refreshed and pushed.
- **Where the game's code lives:** the executable's `.text` is all the main-CPU code. All 379 `.lzs` and 310 `.pac` files (815 MB decompressed), every other archive
  file and the root files were scanned for MIPS return/prologue patterns and VU NOP words: no extra EE code or VU microcode exists. The only other code is IOP modules
  (4 `.irx` in the archive, 6 in `IRX.PAC`, 15 in `IOPRP250.IMG`; a separate CPU, not part of this project). `jr $ra` look-alikes in `.pam`/`.tmd`/`.lzs` are polygon
  records (`80595959 03e00008 ...`). The executable's own `.data` holds about 30 MIPS functions at 0x4299d4-0x42ab98 (kernel-patch code copied to 0x80074000 by 2edfe8);
  they are not in the percentage.

## Layout and build

- Steps 1 and 2 are done (compiler identified, executable rebuilt byte-identical). Step 3, matching functions in C, is in progress.
- Not every file was built the same way. A C file picks its build with header lines: `// compiler: 990721-r5900` / `990721` / `991111-01-as210` / `296` / `296-as210`
  and `// cflags: ...` (`-fno-gcse`, `-fexceptions`, `-fno-schedule-insns`, `-fno-schedule-insns2`, `-fno-thread-jumps`, `-fno-omit-frame-pointer`, `-O1`).
  A third compiler exists: ee-gcc 2.96 (`~/tools/ee-gcc2.96`, header `// compiler: 296`); it emits the `nop; nop` short-loop padding by itself.
- Hand-matched small functions live in `src/units/<report unit>[_variant].c` (one file per report unit and compile setting; `tiny_hand*.c` stay in `src/`).
  `build/work/emit.py` appends to `src/small_hand*.c`: run `python3 tools/split_units.py` afterwards (it appends the new blocks to the unit files and deletes the
  small_hand files), then `asm_build.py all`. The unit is the `group` column of `decomp/functions.csv`.
- `src/` matched C (`// MATCH func_XXXXXXXX` on its own line above the definition; prototypes never share that line), `src/gen*/` and `src/ghidra/` generated matches,
  `src/vu0_asm.c` the libvu0 routines, `wip/*.c` near-miss drafts (`// WIP func_XXXXXXXX`, compiled only by `tools/report.py` for partial-match figures, not part of
  the build), `tools/` format tools and builders, `site/` project website (GitHub Pages, rebuilt from `report/report.json`).
- Tools: `tools/match.py src/FILE.c NAME ADDRESS` compares one function word by word; `tools/asm_build.py all` rebuilds and checks; `tools/progress.py` and
  `tools/report.py` write the progress figures; `tools/perm_setup.py` sets up decomp-permuter.
- `tools/asm_build.py` sorts the C data placements (`C_DATA_PLACED`) by address: a jump table placed at a lower address than an already placed one made lld write a
  corrupt ELF (`st_name ... is past the end of the string table` from llvm-objcopy).
- Report units carry `metadata.source_path` (the repo file with the most matched code of that group); `merge_groups` in `tools/report.py` picks the sub-unit with a path
  and the most matched code.
- Website (`site/template.html` + `site/build_site.py`, deployed by `.github/workflows/pages.yml`, which checks out 30 commits for the history): badges, cards for code /
  functions / fuzzy match / data, the categories panel and the recent commits, all filled from `report/report.json` and `git log`; no "See the progress" button in the hero.
  README badges are SVG files in `badges/` drawn by `tools/badges.py`; `tools/report.py` regenerates them whenever it writes `report/report.json`.
- csv size quirk: 155738 absorbs the next 8-byte function; a 1-word diff with no `!=` line is the known `jr` delay-slot size quirk.

## Rules

- **Do not use agents, workers or subagents** (no Agent tool, no forks, no background workers) for matching or anything else in this project; do the work directly.
  The permuter and build scripts may run in the background; stop them when told to stop.
- **Every push includes a refreshed `report/report.json`** (run `python3 tools/report.py`). `tools/progress.py` writes `build/PROGRESS.md` (git-ignored) as a local summary only.
  `build/work/commit.sh "msg" files...` checks the build says MATCH, regenerates the reports, commits and pushes. `commit.sh` does not add `src/units` and ignores
  `CLAUDE.md`; add those explicitly (or commit by hand). If a push is rejected: `git pull --rebase origin main`, rebuild, push again.
- **Assembly policy.** A function counts as matched only when its source compiles to its bytes. Allowed assembly, all user-approved:
  - single hardware instructions inside normal C functions (`sync`, `.word 0x42000038` = ei, `.word 0x42000039` = di, `mfc0`, `cfc2/ctc2`, `cache`, `syscall`);
  - the 161 syscall wrappers as `int NAME(void) { register int n __asm__("$3") = N; __asm__ volatile("syscall" : : "r"(n)); }` (the compiler emits the `li`, `jr` and delay slot);
  - the libvu0 routines (0x18eaa0-0x18f..., 89 functions, 3,224 bytes) as file-scope `__asm__` in `src/vu0_asm.c`, generated by `build/work/genvu0.py` from the original words
    (undecodable COP2 words become `.word`). Function-body inline asm cannot reproduce them: gcc appends its own `jr $31; nop` and never puts an asm statement in a delay slot,
    but 89 of them end with a VU0 instruction in the `jr` delay slot.
  Everything else stays C. The old `src/asm_stubs.c` (168 hand-written-assembly functions as file-scope asm) stays removed. Compiled hardware-register functions
  (2ceb50, 111170, 2c90a8, 2c82a8, 2e7a18, 2c8e18, ...) must be written in C; file-scope asm for them has NOT been approved.
  The ~840 `__asm__("func_...")` / `__asm__("D_...")` strings in `src/` are symbol-label aliases, not code. Unmatched functions are only assembled into the git-ignored
  `build/asm` so the link and the `MATCH` check work; they never count as matched. README, CONTRIBUTING and the website say the project is C apart from `src/vu0_asm.c` and
  single inline instructions.
- **Never force-push.**
- Commit to `main`. Ask before downloads or any visibility change.
- No copyrighted assets: only tools, docs and C in the repo; game data stays git-ignored. Do not print game text in chat. No game string literals in C (use `D_<addr>` symbols).
- Keep CPU jobs modest (the user has killed background jobs before; four permuter workers gave a load average of 14, two niced workers are fine). `commit.sh` and
  `asm_build.py all` take two minutes or more: do not edit `src/` while they run, and do not run `asm_build.py all` while `commit.sh` runs.
- Never `pkill -f` / `pgrep -f` with a pattern that appears in your own command line (it kills the shell). Use
  `ps -eo pid,cmd | grep '[p]ermuter.py' | awk '{print $1}' | xargs kill`.
- Commit trailer: `Co-Authored-By: Claude Sonnet 5.5 <noreply@anthropic.com>`.
- Website decisions: no ByteMatch mentions on the site; the Maya image is still missing and must not be fetched by bypassing the fandom bot block.
- A compile that is shorter or longer than the original is not a match; trailing `nop` padding is ignored.
- Pitfalls:
  - `emit.py` mangles identifiers: never put `__asm__("D_xxxx")` in a spec, a duplicate `typedef char *va_list;` breaks the file, and `T *` prototypes become `void *`.
    It renames `typedef struct {..} T;` names but not plain typedefs (a second `typedef int u128 ...` in the same unit file must be deleted by hand). Run `asm_build.py all` right
    after every emit and read the last lines of the output.
  - Functions that share a csv name (`AddIntcHandler`, `RFU116_SetSyscall`, ...) need a `_ADDR` suffix in C so the `.text.NAME` sections do not clash.
  - Callee prototypes that clash inside a shared `src/units/*.c` file need `name_ADDR(...) __asm__("name")` aliases (`fixblocks.py FILE ADDR` does it).
  - A stale `// OFF func_X` entry in an old small_hand file causes a duplicate-symbol link error once the function is matched elsewhere.
  - `gen_ghidra.py` without `GG_NEW=1` regenerates `src/ghidra` and drops old matches (`git checkout src/ghidra` restores them).
  - A global the original reaches with `lui+lw` is an array; with `$28` (gp) it is a scalar (`D_<0x4A7C70 + offset>`). 8-byte unaligned globals need `V8 D[3]`.
  - `git pull --rebase` fails while any tracked file is modified; pass tool changes as extra arguments to `commit.sh`.
  - Never run two processes that write the same `w/<addr>.c` (`rs.score` always overwrites it, so copy drafts before looping).
  - Write callee names in specs with UPPERCASE hex (`func_00254F48`): lowercase hex is an undefined symbol at link time.
  - Write spec functions on ONE line (or `{` on the signature line and no line starting with a letter inside): `emit.py` puts `// MATCH` before the first line that starts with
    a letter after the prototype. After an emit whose body spans lines run `build/work/fixblocks.py`.
- Local helpers live in `build/work/` (git-ignored, listed under Workflow). If they are gone, the loop is: write C, compile with `tools/match.py`, compare, add
  `// MATCH func_XXXXXXXX` above the function, rebuild, commit.

## Workflow

- Hand-match loop: `build/work/show.sh ADDR...` (raw Ghidra from `decomp/src/` plus the asm) or `show2.py ADDR...` (Ghidra with gp names turned into `D_` symbols and `FUN_` into
  `func_`) -> write the draft with `mk.sh ADDR` (stdin; `@gp(off)` expands to `D_<0x4A7C70+off>`) into `w/<addr>.c` -> `t.sh ADDR [cc xf]` (diff one draft) and `cfgs.py ADDR`
  (all compiler variants) -> `autofix.py ADDR [secs]` (best config, then `stperm2.py` and `stmove.py` statement search) -> `permw.py` via the permuter queue for what is left ->
  `finish.py ADDR...` (tospec -> batch -> emit -> split_units -> fixblocks) -> `asm_build.py all` (must print MATCH) -> `tools/progress.py`, `tools/report.py`,
  `cp report/report.json report/recomp.json` -> commit, push.
- Other helpers: `var.py ADDR tpl.c` (`{{a|||b}}` choice groups), `knob.py`/`knob_all.py` (pass-through params), `retype.py` / `retype2.py` (flip callee void/int), `argperm.py` and
  `argp2.py ADDR CALLEE` (permute where float and int arguments sit in a callee prototype), `scan_cc2.py CCS` (rescore all drafts under other compilers), `ggnear.py K N MAXSIZE`
  + `ggshow.py ADDR` (best Ghidra variant per unmatched function; hand-fix the small diffs), `ggscan.py`, `blockperm.py`, `ggbig.py`, `wipscan.py` / `prepwip.py ADDR...` (score
  and install `wip/*.c`), `hit.py ADDR` (install a permuter `output-0-1/source.c` as the draft), `genvu0.py` (writes `src/vu0_asm.c`), `mkchunks.py ADDRHEX` (candidate lists).
- decomp-permuter: write the current best source to `build/work/w/<addr>.c`, run `python3 permw.py SECS ADDR...` from `build/work` (it reads the draft's own `// compiler:` /
  `// cflags:` lines). `pqA.sh` and `pqB.sh` are two niced workers over `pq.txt` / `pqB.txt` (done lists `pq.done` / `pqB.done`, logs `pq.log` / `pqB.log`, `PSECS=110`).
  Drafts 1-14 words off solve about one time in four (4 hits in the first 19 runs); drafts 15-30 words off almost never (0 in 22). A "HIT" is not always real
  (20d248 was a false positive: the permuter's objdump hid a `lw`/`li` order swap): re-score it with `batch.py`. About 110 drafts are still queued.
- RTL dumps explain scheduling and register diffs. Compile with `-dr -dj -dg -dl -dc -dG -dS -dR -dL` (files `f.c.rtl/.gcse/.greg/.sched2...`). `.sched2` shows each block's
  `Ready list` (best insn is LAST; ties go to the lower LUID); `.greg` lists refs and live_length per pseudo (priority ~ floor_log2(refs)*refs/live_length; ties: higher regno
  allocated first and gets the LOWER hard reg). Example: 167940's `r7` (8 refs, live 118) outranks `n` (3 refs, live 24), the original has the reverse; 2b8ee8's two hoisted
  `lui`s are created in first-use order and the allocator then reverses them.
- `gen_ghidra.py` has passes for 991111-01, 990721, 990721-r5900, 296 and 296-as210 variants; run `GG_NEW=1 GG_JOBS=6 python3 tools/gen_ghidra.py 160` (small functions first; it is slow).
  Raw Ghidra drafts of 400-700 byte functions are 70-150 words off.

## Techniques that paid off

- Callee return types are the biggest cheap knob: declare a callee `int` instead of `void`, or copy its matched definition's type (122710 needed `int func_0012ACB0`;
  2e8b58 needed a void callee declared `volatile short`).
- Callee argument order: pointer before float, and INTEGER ARGUMENTS FIRST, floats after (`func_0029D010(char *, float, int, int)`; `func_0018E438(int, float x9)` fixed the
  rsound family 10ff28/10ff88/110008). For mixed lists the interleaving matters: `func_00155D40(char *, float, int, int, float, float, float, float, float)` matched 155a68
  only with the first float second (`argp2.py` finds such orders).
- Callee prototypes from Ghidra often hide arguments: pass the caller's own parameters through (`f(a,b,c,d)` where Ghidra said `f(void)`) to fix argument copies and prologue
  order (1925f8, 2132e0, 213368, 2c2be0, 235680 needs 11 int params, 165ca0 needs `f(D, b)`).
- Typed vtable structs (`o->vt->fn60((char *)o + o->vt->adj56, 1)`) instead of raw casts.
- `volatile` for flag words and output pointers (stops hoisting and CSE; fixes most scheduler-order near misses). Volatile accesses cannot go into a branch or call delay slot,
  so a store that the original has in a delay slot must be NON-volatile (2cafb8) and a store that must stay in order must be volatile (2bf848 is 4 words off for this reason).
- Separate loop counter (`i = n`), typed struct pointer for a callee-saved base, hidden pass-through parameters when an argument is copied into `$8`/`$7` (unused extra params
  passed through: 2c31b8 needs -fexceptions), pointer parameter plus an `int` copy (`int p = (int)o; ... g(o);`) for the `daddu` copy at entry (215858, 2153c8, 215420).
- Early returns instead of a result variable fix `daddu $2,$0,$0` delay slots; per-failure `if (bad) { DbgPrintf(str, buf); return 0; }` instead of one shared tail lets gcc
  cross-jump the `jal` tail itself (18a918, 18af40); `size = x + 2047; size &= -2048; call(fd);` puts the `and` in the call's delay slot (18a918); `if (c != 0) c = c + 1; else c = name;`
  (same variable in both arms) avoids the `movz` (18af40).
- A switch with one call per case plus `break` (not a shared call after the switch) reproduces per-case constant loads (16ccd0).
- Struct by value: `V3 t; t = v; f(t)` gives the second 12-byte copy on the stack (24cc58); a returned struct needs `V3 t, v; t = f(); v = t;` (24ccd8). Vector copies need an
  8-byte aligned type (`typedef union { long long l[2]; float f[4]; } V4;`), otherwise gcc uses `ldl/ldr` (162520 is still open, 20 words).
- Member-function-pointer calls (`ld -8` + `dsra32`) match with a hand-expanded ptmf: two separate `idx > 0` tests, one for the function and one for the delta
  (`fn = (void (*)(void *))(e >> 32); d = idx > 0 ? (short)e + dl : dl; fn(o + d);`). Untried: 171ae8 1723e8 173980 175f58 176ac8 176e10 17fc20 204a78 214fa8.
- Overlapping `lw`/`lh` fields reloaded after a store need a union. A pointer in a callee-saved reg may need a `static inline` helper taking `float *v`.
- Separate base variable (`q = SYM; p = q + 8`) stops `-25104 + 8` folding into one `addiu`; one unsigned counter `for (i = 63; (int)i >= 0; i--)` for two loops;
  `p != 0 && n != 0` plus one post-loop `if (p == 0) return 0` for a shared fail block; copy newlib's variable names for newlib code; `x = base; ... q + 6676` needs the base
  in a separate local assigned inside the branch (2533e8, 25d4b0).
- Statement order matters: `v = *p; p++; f(v); i--;` fixed delay-slot order (18d4a8, 990721-r5900 `-fno-thread-jumps`); list unlink `for (; p != 0; p = p[5]) { if (p[5] == n) {...; break;} }`;
  a `key == -1` early return then one loop (2a1df8); `while (p != 0) { if (cond) break; p = p->next; } return p;` for find loops (2175e0); natural source order beats a
  permuter-shuffled one (1f7970); an `if (x) return 1; return 0;` with the compared global copied into a local first fixed the shuffle_ family.
- Bound-checked table getters (`if (a >= 10 || b < 0 || (unsigned)b >= 94) return DEFAULT; return T[b].f;`) need the three tests as one `||` chain with the third unsigned;
  list pops like `t = L.v[L.n--]` and pointer-reusing `a = (char *)*(int *)(...)` fixed register naming (24a190, 223500).
- Array-of-struct getters/setters match with `E *e = &D[idx]; return e->f;` (a plain `D[idx].f` gives a different `mult` operand order); struct stride 472 with a field beyond it:
  `((E *)(D + i * 472))->f`; when the original keeps the symbol separate from a big displacement use a base array with a pointer variable and a large constant index
  (`int *p = D + a * 118; p[1632] = v;`, 29b1a0, 25d7b0). Multi-index tables: `extern E28 D_0062B3D0[][4]` with `D[a][b].f` (2c9bb8..2ca610 family);
  `[A][B][C][D]` arrays of `volatile` structs with gp ints as indexes matched 136650, 1366e8, 136768 (`int z = 0; e->s0 = z; ... n = e; n->s36 = 0`).
- Hardware-register code is mechanical: `#define R(a) (*(volatile unsigned *)(a))`, in asm order. IPU/DMA code matches with `991111-01-as210`. A memory-test loop is
  `while ((R(0x1000a000) & 0x100) != 0) { if (0x1000000 < i++) {...} }` (condition inside `while`, not a read before the loop); `do { v = R(x); } while (v < 0);` gives the
  4-nop wait loop; a store whose address constant is computed per branch needs the store INSIDE each branch of the `if/else` (2bfec0, 2c0978); quadword FIFO writes use
  `typedef int u128 __attribute__((mode(TI)))` (non-volatile source arrays are CSE'd, so a repeated quad source needs `volatile u128` arrays, 2cfcd0). COP2 `cfc2/ctc2` and
  `sync.p` work as `__asm__ volatile("cfc2 %0, $28" : "+r"(t))`; `__asm__ volatile("cache 0x18, 64(%0)" : : "r"(p))` for cache ops.
- Kernel code: `if (s) { do { di; sync.p; mfc0 } while (v & 0x10000); }` and `ei` inline matched 2e60f0, 2e5d30, 1096c0, 2e5fa0, 2edc98, 2e6370; volatile on the gp scalars they touch
  stops delay-slot hoisting (10f268); in a heap-growth routine the store belongs only on the success path (2e5fa0).
- Floats: callees taking floats need real `float` prototypes (21b468); `__builtin_sqrtf` gives `sqrt.s` + NaN check + `sqrtf` call; `(float)(int)(u & 0xffff)` needs a signed int
  (an unsigned one gives the unsigned-convert sequence); float `locals` reused for the product (`g = g * 128.0f * k`) fixed 12a140; 3-operand `mult` (`.word 0x02032818`) is
  what gcc emits for `x * 40` and `a * b * c`.
- GS-packet functions (`sd` constants + `func_00190328`/`func_00190420` calls) are tractable (2975b8, 2a53b0 matched); `long *q` stores; a stack triple `int e[3]` read back
  (247ef8, 22 words off). More at 24bd78 247970 2436f8.
- Ghidra-derived hints: `0x3f000000` float constants -> `0.5f`; offsets in `lb`/`lhu` mean the field types; `ld`/`lq` mean `long long`/`u128`; a 2-word diff with `addiu` vs `ori`
  constants means the number is an address (use a `D_` array); `divu` means unsigned operands; data addresses passed as call arguments need `D_` arrays and code addresses
  `func_XXXXXXXX` symbols (188c70, 2a2ba0); `src/ghidra/ggint_*.c` holds Ghidra bodies with `undefined8` narrowed to `int` (fixed 2e86a8, 2a3ed8, 2c7ec0); explicit per-field load
  temporaries (`u1 = e->a0; u2 = e->a4; ...`) fixed 218738/218978; a `void` function whose early exit returns the zero it just tested (batread_) must not be declared `int`.
- `-fexceptions` (no tail call) fixes calls at the end of rsound/pchevent-style functions (10d748 is 3 words off with it). The permuter's wins were callee/statement
  transformations: `do { ... } while (0);` around a loop or a call (2ec6f0, 2ee3a0), `k = 3; f(b[2], b[k])` (index through a variable, 2ee3a0).
- CD-library family (0x2e9xxx-0x2ec5xx, sceCd-style wrappers: CreateSema + `func_002E8928` request + WaitSema): matched 2ea9f0, 2eabb8, 2eb4c0, 2ebab0, 2eaff8, 2eb368.
  Recipe: `T *t = D_00634280` request block, `S s; s.a[2]=0; s.a[1]=1; s.a[5]=0; sem = CreateSema(&s)`, `r = func_002E8928(...9 args...)`, early `return -11`/`-1`/`-9`
  constants, then `return res`. Name copy: `if ((t->name[0] = name[0]) != 0) { while (++i < 1024) { if ((t->name[i] = name[i]) == 0) break; } }` gives `lbu`+`sll 24`; a
  `c = t->name[0] = name[0]` with `unsigned char c` gives the `daddu` copy instead (2eb4c0). Per function try `func_002E95B0` as `void` vs `int`.
- Same-shape families: `yue_001e9c18` + 6 siblings (`-fno-gcse`, second pointer `q = p`, int `k`), the nayuwin2 slot loaders 1aa160/1aa270/1aa420/1a19b8/1aa050/1a9f20
  (array-of-struct bases `B164 D_..[]`/`B232 D_..[]`, madd), found by grouping unmatched functions by opcode signature. No unmatched function shares an exact
  mnemonic sequence with a matched one any more.

## Open work

Near misses (words off; drafts are in `build/work/w/`):

- 1 word: 249ef0, 25d7b0, 2cf338, 12e2a8 (needs a volatile next-pointer plus a reload of `first`); 2: 2b8ee8 (872 bytes, 990721-r5900, two swapped `lui`), 2b32a8 (536 bytes),
  2ce5a8, 2ca968, 2cf1b0, 2cf2c0, 160df8, 165ca0, 113ec8, 1949e0, 1d8250, 20ddf8, 20fd88, 177348, 247a48, 2d37c0, 2cf4b0, 2cf610; 3: 10d748 (`-fexceptions`), 2121a8, 1e3f88,
  2d3628; 4: 247b40, 196340, 2bf848, 2cea70 (store order of the zeroing stores), 1e2b40, 2a4338; 5: 213258; 6-10: 1a4180, 2edc50, 2d6168, 218f40, 20b910, 247468, 12cf48, 2d33d8,
  1266f8, 23b7c0.
- Found by earlier passes: the GS packet builders 1632d0..163780 (64-bit field packing) and 247b68 / 2493d0 / 247ef8; member-function-pointer calls (173980 is structurally right
  with a PMF struct but 9 words off); the `work` group GS packets 247e40, 24bd78.
- Find-by-tag tails: 160778 (25), 1608a8 (9), 1609c8 (19), 160b48 (10), 160c70 (18), callers 160490 (24) and 160568. Pairs with identical shape: 167940/167b88 (580 bytes each,
  18 words, 990721-r5900, final `movn` vs branch), 2ece08/2ed010 (CD request with an inlined 252-byte struct copy and a runtime alignment test), 1e43d0/1e4568, 127bb8/127d50,
  20cb90/20cd08, 2cb978/2cbc90, 276b50/276dd4, 137dc8/137ed8.
- CD family: 2eb200/2e9bd8 (clamp `m = -1; return m < res ? 0 : res;` is right, the `lui`/`lw` register swap in the head is not), 2eb138, 2ea810, 2eb8a0, 2ec348, 2ec528, 2e96b8,
  2e9d58, 2eb660, 2ebed8, 2ec110, 2e9950, 2e9f90, 2ea200, 2ead88, 2ebc48, 2ea4c0, 2e8bf0, 2edb40.
- Hardware/kernel: 2c5c60 (38: do-while after an explicit entry test; register swap), 2e8038 (49: the original keeps the 0xffffffc0 mask in a register), 2c3620 (32: `movz/movn`
  selects match with ternaries, register numbering does not), 2ceb50 (115: dead volatile reads), 111170 (115: a `sw` that must sit in a jal delay slot), 2c8cd8 (IPU handler; the original
  reloads `*o`), 2c89b8, 2c6fa8, 2c7120, 2c7228, 2c7318, 191ef0, 2e7120/2e32a0 (soft-float helpers: the original uses `(p << 1) >> 53`), 2e5480 (`RFU000_FullReset`, 1 word off).
- Other drafts: 20b760 and 20b660 (growable array, 990721-r5900, register numbering of the loop), 2d4818, 2da0c8, 2d98c8 (lists), 1252a0 (22), 130ba0 (43: code point must be a signed
  int), 2c9aa0 (37), 237ae0 and 24a058 (register allocation), 291b60, 21aa60, 249f98 (r5900 short-loop padding).
- Older ones still open: 10af88 (480 bytes), 109d18 (64 KB stack array), 10a120, 10ec40, 154d20 / 154db8, 1545a8, 112a28, 213410, 161868, 2128c8, 130ad8, 2682e0, 260428,
  269fc8, 265c30, 2d8438, the 2cf* packet builders, 1707d8 (38), 173630 (11), 178038 (16), 1694d0 (13), 163d88 (12), 137ca8 family, 1704e8 (9), 204c58 (23), 203d58 (16),
  1e7cb0 / 1d7f00 (10), 2cb340 (27), 2a8c80 (struct array init with per-element base pointers), 1364c8 (three loops over one table), 137298/137330/1367c8 (4-short entries with two
  address forms; see `fam_gp.txt` in build/work for the 19-function list), 2a4840 (29, `-fno-gcse`), 2a4020 (45), 203f40 (42, wants hoisted array bases), 129a38 (42, the original uses
  `movz`/`movn` for `a != 0 && f() != 0`).
- Script-track scanners 1524d0, 13e3c0, 13e488, 151930 (8-11 words off, only register numbering of four hoisted pseudos differs; matched structure is
  `T140 D_0032EF50[]` with a `for (i = 0; i < D[e].n; i++)` loop over `.ops[i].code == 8`, track base `bt = D_0055FC80 + tr * 0x1000` hoisted; the permuter found nothing in 700 s).
  Other near misses: 2cdac8 (3 words, the `r = 0` lands in the wrong delay slot), 237bc8 (register swap; the permuter hit leaves `p1` unset on one path, so it is not valid),
  112b28 (10), 219240 (7), 2cbb80, 21db30, 249108 (one register), 245078, 29d010, 246e18, 224c70, 2971d0.
- Tricks that worked this round: early `return` per branch so gcc does not cross-jump the call tails (24a3c8); a `for` loop over struct arrays gives the loop pass's double multiply and
  base copies (1524d0); `volatile short` / `volatile int` callee return types (2a1d28, from the permuter); a magic constant held in a local keeps its hoist order (10a848, with
  `.word 0x0000000d` = `break 0` inline); `!(a < b)` instead of `a >= b` fixes operand load order (2c8208); pass the tested pointer on to the callee (29fa18).
- Shikimi: the user said not to do the big functions (2afa58, 2b0100, 2b12c8, 2b1e68, 2b2900, 2b34d8, 2b3f10, 2b8650).
- Pools: about 4,000 bytes to 13.81%; candidate chunk lists come from `build/work/mkchunks.py ADDRHEX` (`build/work/ch/c###.txt`, unmatched 60-450 byte functions; chunks up to
  address 0x187068 were read). Other ideas: rerun `ggnear.py` with a larger MAXSIZE, rerun `permq.py` / `permw.py` on new near misses, rerun `sweep4.py` after adding compiler settings,
  and a posed model export in `tmd_tool.py` (apply the first frame of a motion clip) for character pictures.

## Housekeeping

- `git status` shows three untracked files that are meant to stay uncommitted: `site/index.html` (generated by `site/build_site.py`), `site/template_red_old.html` and
  `site/assets/lang.jpg` (original render with the red background).
- `FORMATS.md`, `PROGRESS.md` and `handoff.md` were removed from the repo (still in git history). Format details live in the docstrings of the `tools/` scripts.
- The scratch Python venv with Pillow/numpy used for image work is `/tmp/claude-1000/imgvenv` (not part of the repo).
- README badges and the clone URL point at WeAreTommyBruh/Legaia2-Decomp; update them if the repo is renamed.
- Memory notes for this project live in `~/.claude/projects/-home-tommy-src-Legaia-2-Decomp/memory/`.
