# Contributing

Thanks so much for your interest in the Legaia 2: Duel Saga (PAL, SLES-50891) decompilation.

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

## Submitting a pull request

Once you have the maintainer's go-ahead and your change builds:

1. **Fork and branch.** Fork the repository on GitHub, then create a branch in your fork for your work (one topic per branch, for example one file or one family of functions).
2. **Push to your fork.** Push that new branch to your own GitHub fork, not to the original repository.
3. **Open the pull request.** Open the original project's repository on GitHub. After a push, GitHub usually shows a yellow banner offering **Compare & pull request**; click it. (If the banner is gone, use the Pull requests tab and choose *New pull request*, then pick your fork and branch.)
4. **Explain what you did.** In the description, say which functions you matched and which files they are in. If you used an outside tool such as decomp.me to work something out, mention it and link the scratch if that helps. Confirm that `python3 tools/asm_build.py all` prints `MATCH` on your machine, and that you regenerated `PROGRESS.md` and `report/report.json`.
5. **Wait for review.** The maintainer will read your pull request and may ask you to change names, structure or types before it is merged into `main`. Reply on the PR and push follow-up commits to the same branch; they are added to the pull request automatically.

## Git etiquette

- Contributors work on a branch in their own fork (see above). The maintainer works on `main`; if a push is rejected, `git pull --rebase origin main`, rebuild, and push again.
- **Never force-push.**
- Ask before anything large or outward-facing: downloading tools or data, changing repository visibility, renaming the repository.
- Keep CPU-heavy jobs (compiler sweeps, permuter runs) modest so shared machines stay usable.

## AI assistance

This project is heavily AI-assisted and every result is checked by the maintainer. If you use AI tools, you remain responsible for what you submit: verify it matches, contains no game assets or text, and follows the rules above.

## Questions

Ask on Discord (see above) or open an issue.
