# Contributing

Thanks for your interest in the Legaia 2: Duel Saga (PAL, SLES-50891) decompilation.

**Please ask permission before contributing.** Contact the maintainer on Discord ([@wearetommybruh](https://discord.com/users/1560770063240405115)) before you start work or open a pull request. This keeps people from matching the same functions twice.

## What this project is

A *matching* decompilation: the goal is C that compiles to exactly the original bytes with the game's compiler (ee-gcc 2.9-ee-991111-01, `-O2 -G8`). A function counts as done only when its C compiles byte-identical. Everything else is still built from the original assembly, so the rebuilt executable is always byte-identical.

## Legal rules (non-negotiable)

- **No game data in the repository.** No disc image, executable, textures, audio, models or anything extracted from them. Only tools, documentation and C written by you.
- **No game text.** Do not copy game string literals into C or docs. Refer to strings through their `D_<address>` symbols.
- You must supply your own copy of the PAL disc (`SLES_50891.ISO`). Generated folders (`disc/`, `decomp/`, `fs/`, `png/`, ...) are git-ignored; keep it that way.

## Getting set up

Follow [README.md](README.md) (Ghidra, JDK, ee-gcc 2.9-ee-991111-01, clang + ld.lld). Then check that the baseline works:

```bash
python3 tools/asm_build.py all    # last line must print MATCH
python3 tools/progress.py
python3 tools/report.py
```

More background on the pipeline, formats and file layout is in [FORMATS.md](FORMATS.md); current numbers are in [PROGRESS.md](PROGRESS.md); tips, techniques and open problems are in [handoff.md](handoff.md).

## Matching a function

1. Pick an unmatched function (see `decomp/functions.csv`, `PROGRESS.md`, or the near-misses in `wip/`).
2. Read its assembly and Ghidra output, write C, and compare:

   ```bash
   python3 tools/match.py src/FILE.c NAME ADDRESS
   ```

   It compiles with the game's compiler and shows the word-by-word difference.
3. When it matches, put `// MATCH func_XXXXXXXX` on its own line directly above the definition. The first identifier before `(` on the next line is taken as the function name, so prototypes must **not** share that line.
4. Pick the right source file. Files declare their build with header lines:
   - `// compiler: 990721-r5900` for the older compiler with the R5900 short-loop fix,
   - `// cflags: ...` for extra flags such as `-fexceptions`, `-fno-gcse`, `-fno-schedule-insns`, `-fno-schedule-insns2`, `-fno-thread-jumps`, `-O1`.

   Small hand-matched functions live in `src/small_hand*.c`, one file per setting. Try every setting for each draft; a function often matches under just one.
5. Rebuild and confirm the whole executable is still identical:

   ```bash
   python3 tools/asm_build.py all    # must print MATCH
   ```

A too-short or too-long compile is not a match: the word count must equal the original function size.

### Near misses

If a draft is close but not exact, add it as `wip/<address>.c` with `// WIP func_XXXXXXXX` (include `../src/common.h`). `tools/report.py` compiles these for partial-match figures; they are not part of the build. When one matches, move it to `src/` with `// MATCH` and delete the wip file.

Useful techniques (struct-pointer parameters, `volatile` flag words, `int`-returning callee declarations, `noreturn` tails, statement-order permutations, compiler flag sweeps) are collected in `handoff.md`.

## Before every commit / push

- `python3 tools/asm_build.py all` prints `MATCH`.
- Regenerate and commit **both** progress files together with your change:

  ```bash
  python3 tools/progress.py    # PROGRESS.md
  python3 tools/report.py      # report/report.json (read by ByteMatch)
  ```

  Every push needs a refreshed `PROGRESS.md` and `report/report.json`; the live ByteMatch badges in the README only move when `report.json` is pushed.
- Watch for duplicate symbols: a stale `// OFF func_X` or an already-matched function in another file causes a link error.
- Keep commits focused and describe what matched (for example "Match 12 more pchevent debug-print functions").

## Git etiquette

- Work from `main`; if a push is rejected, `git pull --rebase origin main`, rebuild, and push again.
- **Never force-push.**
- Ask before anything large or outward-facing: downloading tools or data, changing repository visibility, renaming the repository.
- Keep CPU-heavy jobs (compiler sweeps, permuter runs) modest so shared machines stay usable.

## AI assistance

This project is heavily AI-assisted and every result is checked by the maintainer. If you use AI tools, you remain responsible for what you submit: verify it matches, contains no game assets or text, and follows the rules above.

## Questions

Ask on Discord (see above) or open an issue.
