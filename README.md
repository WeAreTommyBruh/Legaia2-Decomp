# Legaia 2 Duel Saga (PAL SLES 50891) decompilation

## Whats in this repo

tools and scripts. No game data is included. No disc image, executable extracted files or decompiled output. You need your copy of the PAL disc (SLES 50891) and generate everything locally;.gitignore keeps generated files out of git.

| Path | What |

| --- | --- |

| decompile.sh | Builds the Ghidra project. Decompiled C from your disc image |

| ghidra/scripts/ | Headless Ghidra scripts used by decompile.sh |

| tools/fs_tool.py | Lists or extracts the games FS archive straight from the ISO |

| tools/lzss.py | Decompresses.lzs files ( files and multi-file archives) |

| tools/pac_tool.py | Lists or splits.pac map packages into their chunks |

tools/battle_script.py | Battle script opcode reference and.bsd disassembler |

Generated locally (ignored by git): disc, ghidra/Legaia2.gpr decomp (C output, one file per function under decomp/src/<source file> functions.csv) fs, fs_unpacked, fs_index.csv docs.

## Rebuilding

Needs JDK 21 and Ghidra 12.1.4 with the ghidra-emotionengine-reloaded extension (expected in ~/tools override with JAVA_HOME / GHIDRA).

Put your disc image in the repo root as SLES 50891.ISO then:

```bash

./decompile.sh

python3 tools/fs_tool.py SLES 50891.ISO extract fs

python3 tools/fs_tool.py SLES 50891.ISO list > fs_index.csv

python3 tools/lzss.py --all fs

mkdir -p docs && python3 tools/battle_script.py opcodes disc/SLES 508.91 > docs/battle_script_opcodes.md

```

## Pipeline

1. Import with the language; ImportMMIORegisterLabels labels PS2 hardware registers.

2. RecoverCode fills in what auto-analysis missed: decodes switch tables in functions the analyser timed out on (the 49 KB interpreter at 0x00144910) disassembles functions only reached through pointer tables. Creates functions at code that starts after a return.

3. NameFunctions

The games debug allocator is called as MemAllocDbg(size __FILE__, __LINE__). Every caller reveals its.cpp file and line. Functions sitting between two functions of the file are attributed to that file too (object files link contiguously). Recovered line numbers rise with address inside every file, which backs this up.

Renames FUN_xxxxxxxx to <file>_xxxxxxxx tags functions src:<file> plus src-direct / src-inferred and puts the source file and lines in the function comment.

Sony SDK functions that print "sceXxx:..." errors get their names.

A hand-checked list (KNOWN in NameFunctions.java) names and types:

. Game helpers (DbgPrintf, MemAllocDbg...) and functions whose own debug messages give their name (LoadFile, MallocLoadFileNB);

. The format and script code below (LzssDecode, PacLoadRoom, BtlScriptRun...);

. Newlib C library functions, identified by behaviour (memset fills and returns dst rand uses newlibs LCG 0x41c64e6d/0x3039 sprintf builds newlibs string FILE...);

. Libgcc soft-float routines (__extendsfdf2 etc.; every %f in a debug print goes through them because the EE has no double-precision FPU);

. SceCdSearchFile, from how it's used on \FS.BIN;1.

4. ExportDecomp decompiles everything in parallel with a 15 minute per-function limit.

Functions with no known source file are grouped as _unknown_after_<file>: they sit in memory after <file> so they belong to it or to a file that never calls the debug allocator. The Sony SDK, C library and kernel stubs are after shikimi.cpp ( 0x002b9000 onward).

## Disc file system

Game data lives in one volume split over FS.BIN, FS1.BIN and FS2.BIN (each continues where the previous ends; sector numbers count from the start of FS.BIN) indexed by FS.DIR.

FS.DIR is encrypted from byte 0x10 onward. The game decrypts it in FUN_001897c8:

= 0x6E6B7270 * (u16@4 ^ u16@6); each u32 is XORed with key then key = key * 5 + 1. Decrypted it holds a 16-byte header, a table of 61 file extensions and 7,367 16-byte entries (42 directories, 7,325 files) laid out depth-first. See the docstring in tools/fs_tool.py. FS.DIR stores sizes in sectors only so extracted files keep their sector padding.

## Data formats

.lzs (LzssDecode @ 0x001908f0): Okumura-style LZSS: 4 KB zero-filled window starting at 0xFEE flag bytes LSB 1 = literal) references b0 | (b1 & 0xF0) << 4, length (b1 & 0xF) + 3. A file is either one compressed file (u32 size or when the first two words are 0 an archive: u32 count, u32 total size then {u32 offset; char path[32]} per member each member compressed separately. 308 Of the file.lzs are compressed copies of a.pac that is also on the disc; the rest (area maps like world, battle models, system data) only exist compressed and are unpacked into fs_unpacked/.

.pac (map packages): chunks with a u32 header word bits 0-23 size, bits 24-30 type, bit 31 selects a 0x80-byte header ( 0x10); size 0 ends the file. Room/battle maps are loaded by PacLoadRoom (0x002a3a70) area maps by PacLoadArea (0x002a3278). Chunk types and what each loader does with them are listed in tools/pac_tool.py.

Battle scripts (data/battle/*.bsd, run by BtlScriptRun @ 0x00144910): lists of commands an opcode followed by its parameters. The executable carries the games script editor table at 0x0032ef48 with every opcodes name, parameter count, types, ranges and value names; tools/battle_script.py opcodes generates a reference from it. A.bsd holds up to 32 tracks;, within a track FRAME COUNT n marks the frame on which the following commands run.
