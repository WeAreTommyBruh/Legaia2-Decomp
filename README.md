# Legaia 2: Duel Saga (PAL, SLES-50891) decompilation 
Legaia 2: Duel Saga (PAL, SLES-50891) is now being decompiled using ghidra and claude code. This is for preserving and educational purposes.

# Setup
Open your terminal and clone the repo.

```bash
git clone https://github.com/WeAreTommyBruh/Legaia2-Decomp.git
```

- For the rebuild and progress tools you also need clang and ld.lld (LLVM, with the MIPS target) and the game's compiler, ee-gcc 2.9-ee-991111-01, from decomp.me's compiler archive. It is a 32-bit Linux program, so on 64-bit Debian/Ubuntu you may need `libc6:i386`.

```bash
git clone https://github.com/WeAreTommyBruh/Legaia2-Decomp.git
mkdir -p ~/tools/ee-gcc2.9-991111-01
curl -L https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.9-991111-01.tar.xz \
  | tar xJ -C ~/tools/ee-gcc2.9-991111-01

# put SLES_50891.ISO in the repository root, then:
python3 tools/asm_build.py all     # rebuild + byte-identical check
python3 tools/progress.py          # PROGRESS.md
python3 tools/report.py            # report/report.json
```
- For windows users you need to install [WSL](https://github.com/microsoft/WSL) with Ubuntu Or Debian.

# AI Usage
This decompilation project is heavily ai assisted. I check everything one by one to make sure there is nothing wrong.

# Contributing
Any help will be welcome. Please read [CONTRIBUTING.md](https://github.com/WeAreTommyBruh/Legaia2-Decomp/blob/main/CONTRIBUTING.md) for more details.

# Legal
This repository contains no game files: no disc image, executable, graphics, audio, text or other assets, and nothing extracted from them. It holds only tools, documentation and C reconstructed from analysing the game's code (written by hand, or generated with Ghidra and checked against the original). You will have to provide your own Legaia 2: Duel Saga (PAL, SLES-50891) disc image.

# How long will this take?
This is take between a few months to years of matching functions and decoding stuff to reach 100%. After 100% decompile it will take between a few weeks to a month to recompile it. I am in no rush to complete this project so it will be finished when its finished.
