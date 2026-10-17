# Legaia 2: Duel Saga (PAL, SLES-50891) decompilation
Legaia 2: Duel Saga (PAL) is now being decompiled using ghidra and claude code. This is for preserving and educational purposes.

[![Code](https://bytematch.dev/WeAreTommyBruh/Legaia2Decomp.svg?mode=shield&label=Code&measure=matched_code_percent)](https://bytematch.dev/WeAreTommyBruh/Legaia2Decomp)
[![Functions](https://bytematch.dev/WeAreTommyBruh/Legaia2Decomp.svg?mode=shield&label=Functions&measure=matched_functions)](https://bytematch.dev/WeAreTommyBruh/Legaia2Decomp)

# Setup
Open your terminal and clone the repo.

```bash
git clone https://github.com/WeAreTommyBruh/Legaia2Decomp.git
```

- You will be needing JDK 21 and Ghidra 12.1.4 with the
[ghidra-emotionengine-reloaded](https://github.com/chaoticgd/ghidra-emotionengine-reloaded)
extension (expected in `~/tools`, override with `JAVA_HOME` / `GHIDRA`).

- For the rebuild and progress tools you also need clang and ld.lld (LLVM, with the MIPS target) and the game's compiler, ee-gcc 2.9-ee-991111-01, from decomp.me's compiler archive. It is a 32-bit Linux program, so on 64-bit Debian/Ubuntu you may need `libc6:i386`.

```bash
mkdir -p ~/tools/ee-gcc2.9-991111-01 && curl -L https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.9-991111-01.tar.xz | tar xJ -C ~/tools/ee-gcc2.9-991111-01
```

- Then Put your Legaia 2 (PAL) disc image in the root as "SLES_50891.ISO" And in your terminal run these.


```bash
export JAVA_HOME=~/tools/jdk-21.0.12.1+1
export GHIDRA=~/tools/ghidra_12.1.4_PUBLIC
export GHIDRA_HEADLESS_MAXMEM=8G
export EE="$GHIDRA/Ghidra/Extensions/ghidra-emotionengine-reloaded/ghidra_scripts"
mkdir -p disc
7z e -odisc SLES_50891.ISO SLES_508.91 SYSTEM.CNF
rm -rf ghidra/Legaia2.gpr ghidra/Legaia2.rep
"$GHIDRA/support/analyzeHeadless" "$PWD/ghidra" Legaia2 -scriptPath "$PWD/ghidra/scripts;$EE" -import "$PWD/disc/SLES_508.91" -processor r5900:LE:32:default -preScript ImportMMIORegisterLabels.java
"$GHIDRA/support/analyzeHeadless" "$PWD/ghidra" Legaia2 -scriptPath "$PWD/ghidra/scripts;$EE" -process SLES_508.91 -noanalysis -postScript RecoverCode.java "$PWD/ghidra/recover_report.txt"
"$GHIDRA/support/analyzeHeadless" "$PWD/ghidra" Legaia2 -scriptPath "$PWD/ghidra/scripts;$EE" -process SLES_508.91 -noanalysis -postScript NameFunctions.java apply "$PWD/ghidra/naming_report.txt"
"$GHIDRA/support/analyzeHeadless" "$PWD/ghidra" Legaia2 -scriptPath "$PWD/ghidra/scripts;$EE" -process SLES_508.91 -noanalysis -readOnly -postScript ExportDecomp.java "$PWD/decomp"
python3 tools/fs_tool.py SLES_50891.ISO extract fs
python3 tools/fs_tool.py SLES_50891.ISO list > fs_index.csv
python3 tools/lzss.py --all fs fs_unpacked
mkdir -p docs && python3 tools/battle_script.py opcodes disc/SLES_508.91 > docs/battle_script_opcodes.md
python3 tools/tex_tool.py all fs png
python3 tools/adpcm.py all fs wav
mkdir -p mid && for f in fs/data/aound/*.sq; do python3 tools/sq2mid.py "$f" "mid/$(basename "${f%.sq}").mid"; done
python3 tools/tmd_tool.py all fs obj
7z e -odisc SLES_50891.ISO PALMOVIE.PSS && mkdir -p movie && python3 tools/pss_demux.py disc/PALMOVIE.PSS movie/PALMOVIE
python3 tools/asm_build.py all
python3 tools/progress.py
python3 tools/report.py
```
- For windows users you need to install [WSL](https://github.com/microsoft/WSL) with Ubuntu.

# AI Usage
This decompilation project is heavily ai assisted. I check everything one by one to make sure there is nothing wrong.

# Contributing
I will not be accepting pull requests,external code contributions, or issue reports at this time. You can fork this repo if you want. If you want to extract textures, audio or models you can do so.

# Legal
This repository contains no game files: no disc image, executable, graphics, audio, text or other assets, and nothing extracted from them. It holds only tools, documentation and C reconstructed from analysing the game's code (written by hand, or generated with Ghidra and checked against the original). You will have to provide your own Legaia 2: Duel Saga (PAL, SLES-50891) disc image.

# How long will this take?
This is take between a few months to years of matching functions and decoding stuff to reach 100%. After 100% decompile it will take between a few weeks to a month to recompile it. I am in no rush to complete this project so it will be finished when its finished.
