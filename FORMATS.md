# Technical notes

How the decompilation pipeline and the format tools work, and what is known about the
game's file formats. See `README.md` for setup.

## Tools and layout

Only tools and scripts. **No game data is included**: no disc image, executable, extracted
files or decompiled output. You need your own copy of the PAL disc (SLES-50891) and generate
everything locally; `.gitignore` keeps generated files out of git.

| Path | What |
| --- | --- |
| `decompile.sh` | Builds the Ghidra project and decompiled C from your disc image |
| `ghidra/scripts/` | Headless Ghidra scripts used by `decompile.sh` |
| `tools/fs_tool.py` | Lists / extracts the game's FS archive straight from the ISO |
| `tools/lzss.py` | Decompresses `.lzs` files (single files and multi-file archives) |
| `tools/pac_tool.py` | Lists / splits `.pac` map packages into their chunks |
| `tools/battle_script.py` | Battle script opcode reference and `.bsd` disassembler |
| `tools/tex_tool.py` | Converts texture sets (`.tms`, `.dat`, `.pac` texture chunks) to PNG |
| `tools/adpcm.py` | Converts `.int` audio streams to WAV; splits `.snd` sound banks into samples |
| `tools/sq2mid.py` | Converts `.sq` music sequences to standard MIDI |
| `tools/msg_tool.py` | Lists event/message containers (`EV` `.dat` files) |
| `tools/tmd_tool.py` | Converts `.tmd` models (and `mon*tmd.dat`) to Wavefront OBJ |
| `tools/mov_tool.py` | Lists animation clips in `.mov` motion files (and unpacked `.moz`) |
| `tools/efp_tool.py` | Lists / unpacks `.efp` effect packs into their `.efb` effects |
| `tools/pss_demux.py` | Splits `PALMOVIE.PSS` into MPEG-2 video (`.m2v`) and WAV audio |

Generated locally (ignored by git): `disc/`, `ghidra/Legaia2.gpr`, `decomp/` (C output,
one file per function under `decomp/src/<source file>/`, `functions.csv`), `fs/`,
`fs_unpacked/`, `fs_index.csv`, `docs/`, `png/`, `wav/`, `mid/`, `obj/`, `movie/`.

## Rebuilding

Needs JDK 21 and Ghidra 12.1.4 with the
[ghidra-emotionengine-reloaded](https://github.com/chaoticgd/ghidra-emotionengine-reloaded)
extension (expected in `~/tools`, override with `JAVA_HOME` / `GHIDRA`).

Put your disc image in the repo root as `SLES_50891.ISO`, then:

```bash
./decompile.sh
python3 tools/fs_tool.py SLES_50891.ISO extract fs
python3 tools/fs_tool.py SLES_50891.ISO list > fs_index.csv
python3 tools/lzss.py --all fs fs_unpacked
mkdir -p docs && python3 tools/battle_script.py opcodes disc/SLES_508.91 > docs/battle_script_opcodes.md
python3 tools/tex_tool.py all fs png      # ~7,700 textures
python3 tools/adpcm.py all fs wav         # ~3 GB of WAV
mkdir -p mid && for f in fs/data/aound/*.sq; do python3 tools/sq2mid.py $f mid/$(basename ${f%.sq}).mid; done
python3 tools/tmd_tool.py all fs obj      # ~280 models
7z e -odisc SLES_50891.ISO PALMOVIE.PSS && mkdir -p movie && python3 tools/pss_demux.py disc/PALMOVIE.PSS movie/PALMOVIE
```

## Pipeline

1. **Import** with the R5900 language; `ImportMMIORegisterLabels` labels PS2 hardware registers.
2. **RecoverCode** fills in what auto-analysis missed: decodes switch tables in functions the
   analyser timed out on (the 49 KB interpreter at `0x00144910`), disassembles functions only
   reached through pointer tables, and creates functions at code that starts after a return.
3. **NameFunctions**
   - The game's debug allocator is called as `MemAllocDbg(size, __FILE__, __LINE__)`, so every
     caller reveals its `.cpp` file and line. Functions sitting between two functions of the same
     file are attributed to that file too (object files link contiguously). Recovered line numbers
     rise with address inside every file, which backs this up.
   - Renames `FUN_xxxxxxxx` to `<file>_xxxxxxxx`, tags functions `src:<file>` plus
     `src-direct` / `src-inferred`, and puts the source file and lines in the function comment.
   - Sony SDK functions that print `"sceXxx: ..."` errors get their real names.
   - A hand-checked list (`KNOWN` in `NameFunctions.java`) names and types:
     - game helpers (`DbgPrintf`, `MemAllocDbg`, ...) and functions whose own debug messages
       give their name (`LoadFile`, `MallocLoadFileNB`);
     - the format and script code below (`LzssDecode`, `PacLoadRoom`, `BtlScriptRun`, ...);
       these names are descriptive, not original;
     - newlib C library functions, identified by behaviour (`memset` fills and returns `dst`,
       `rand` uses newlib's LCG `0x41c64e6d`/`0x3039`, `sprintf` builds newlib's string `FILE`, ...);
     - libgcc soft-float routines (`__extendsfdf2` etc.; every `%f` in a debug print goes
       through them because the EE has no double-precision FPU);
     - `sceCdSearchFile`, from how it is used on `\FS.BIN;1`.
   - Functions that print their own name as their first debug message (`"SyncCheck 0"`,
     `"SetDrawNowLoading"`, `sceCdStRead`, ...) are renamed after it, when exactly one function
     prints the name, within its first 0x60 bytes, and prints no other such name. Names printed
     deeper inside a function usually describe something it calls and are skipped.
4. **ExportDecomp** decompiles everything in parallel with a 15 minute per-function limit.

Functions with no known source file are grouped as `_unknown_after_<file>`: they sit in memory
after `<file>`, so they belong to it or to a file that never calls the debug allocator. The
Sony SDK, C library and kernel stubs are after `shikimi.cpp` (roughly `0x002b9000` onward).

## Disc file system

Game data lives in one volume split over `FS.BIN`, `FS1.BIN` and `FS2.BIN` (each continues where
the previous ends; sector numbers count from the start of `FS.BIN`), indexed by `FS.DIR`.

`FS.DIR` is encrypted from byte 0x10 onward. The game decrypts it in `FUN_001897c8`:
`key = 0x6E6B7270 * (u16@4 ^ u16@6)`; each u32 is XORed with `key`, then `key = key * 5 + 1`.
Decrypted, it holds a 16-byte header, a table of 61 file extensions and 7,367 16-byte entries
(42 directories, 7,325 files) laid out depth-first. See the docstring in `tools/fs_tool.py`.
`FS.DIR` stores sizes in whole sectors only, so extracted files keep their sector padding.

## Data formats

**`.lzs`** (`LzssDecode` @ `0x001908f0`): Okumura-style LZSS: 4 KB zero-filled window starting at
`0xFEE`, flag bytes LSB first (1 = literal), references `b0 | (b1 & 0xF0) << 4`, length
`(b1 & 0xF) + 3`. A file is either one compressed file (u32 size first) or, when the first two
words are 0, an archive: u32 count, u32 total size, then `{u32 offset; char path[32]}` per member,
each member compressed separately. `.moz` files are single compressed files too (motion data in
the `.mov` layout, not copies of the same-named `.mov`). 308 of the single-file `.lzs` are compressed copies of a `.pac`
that is also on the disc; the rest (area maps like `world`, battle models, system data) only exist
compressed and are unpacked into `fs_unpacked/`.

**`.pac`** (map packages): chunks with a u32 header word, bits 0-23 size, bits 24-30 type, bit 31
selects a 0x80-byte header (else 0x10); size 0 ends the file. Room/battle maps are loaded by
`PacLoadRoom` (`0x002a3a70`), area maps by `PacLoadArea` (`0x002a3278`). Chunk types and what each
loader does with them are listed in `tools/pac_tool.py`.

**Battle scripts** (`data/battle/*.bsd`, run by `BtlScriptRun` @ `0x00144910`): lists of float
commands, an opcode followed by its parameters. The executable carries the game's own script
editor table at `0x0032ef48` with every opcode's name, parameter count, types, ranges and value
names; `tools/battle_script.py opcodes` generates a reference from it. A `.bsd` holds up to 32 tracks; within
a track, `FRAME COUNT n` marks the frame on which the following commands run.

**Textures** (`.tms`, most `.dat`, `.pac` chunk types 0x01/0x05; uploaded by `init_0024bd78` and
`init_0024bf60`): u32 count, then one offset per texture in 4-byte words. Each texture has a
0x20- or 0x80-byte header (kind 0x41/0x42), a pixel format (4/8-bit indexed, 16/32-bit), width in
16-bit units as on the PS1, VRAM position, then an optional 32-bit RGBA CLUT and row-major pixels.
8-bit CLUTs are in the GS CSM1 order (index bits 3 and 4 swapped); GS alpha runs 0..0x80. Details
in `tools/tex_tool.py`. 29 battle `.dat` files are a different, event/message format.

**Audio** (`.int`): stereo PS2 SPU ADPCM interleaved in 0x400-byte blocks, 44,100 Hz (the stream
player `FUN_0010d8a0` sets two SPU voices to `0xac44` Hz, panned hard left and right). Voice
lines are mono duplicated into both channels. **Sound banks** (`.snd`): a 0x80-byte header, the
ADPCM samples, then an `SShd` table with program/tone records and sound-effect sequences; the
tone records are not decoded yet, so extracted samples use an assumed rate.

**Music sequences** (`.sq`, "SSsq"): ticks per quarter note and BPM in the header, 16 channel
records, then MIDI-style events where each event is followed by its delta time. Pitch bend has one
data byte and tempo is `ff 51` + u16 BPM; otherwise it is MIDI. Programs refer to the game's own
sound banks, so converted MIDI plays with General MIDI instruments.

**Event/message containers** (23 `data/battle/*.dat` files starting `EV\x03\x00`): a section
table (`1st`, `MSG`) followed by message offsets and null-terminated strings. `msg_tool.py list`
shows structure only.

**Models** (`.tmd`): u32 count + word offsets, one model each. A model header holds offsets to
float vertex and normal arrays (4 floats each), a bounding box and counts; primitives are sections
of triangle strips, each record carrying an RGBA colour, texture coordinates (0..1024) and
vertex/normal offsets, with flag bit 0 marking strip restarts (GS ADC). Decoding reproduces the
header's triangle count for every model on the disc. Details in `tools/tmd_tool.py`.

**Motion** (`.mov`, `.moz` after decompression, `mon*move.dat`): u32 clip count + byte offsets;
each clip has a name and a likely frame count. Keyframe data is not decoded yet.

**Effect packs** (`.efp`, parser `eftpack_00202f88`): version 1001, a count, then
`{u32 size, u32 offset, char name[16]}` entries naming `.efb` effects. 1,306 of the 1,551
packed effects exist only inside packs.

**Movie** (`PALMOVIE.PSS`): MPEG-2 program stream; video in stream 0xE0, audio in private
stream 1 with an `SShd`/`SSbd` header (16-bit PCM, 48 kHz stereo, 0x200-byte interleave).

**Other files**: `light.dat` is a table of four-float rows in 0..1 (purpose unknown);
`sys_tmd.dat` is all zeros.

**Not decoded yet**: motion keyframes, the `.efb` effect format (and the older `bpack1.efp`
layout), and the sound-bank tone tables (the `SShd` table in `.snd` does not store sample
positions as plain offsets, so the tone-to-sample mapping and real sample rates are unknown).
