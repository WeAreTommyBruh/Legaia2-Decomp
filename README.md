<p align="center">
  <img src="https://github.com/WeAreTommyBruh/Legaia2-Decomp/blob/29e6bfa6fd988cf3c49323602c1fc3d83d9a5562/logo.png" alt="Alt Text" width="500">
</p>

# Legaia 2: Duel Saga (PAL, SLES-50891) decompilation
This project aims to rebuild Legaia 2 code into readable C source code. The goal of this project is a byte-for-byte decomp that can reproduce the games executable.

Almost everything is C. The exceptions are the libvu0 routines (VU0 coprocessor code), which are written as file-scope assembly in `src/vu0_asm.c` (plus 25 other VU0/COP2 routines in `src/vu0_asm2.c`), and a few single hardware instructions (`syscall`, `sync`, `ei`, `mfc0`, ...) inline in otherwise normal C functions.

[![Code](badges/code.svg?v=350664)](https://wearetommybruh.github.io/Legaia2-Decomp/#progress)
[![Functions](badges/functions.svg?v=4200)](https://wearetommybruh.github.io/Legaia2-Decomp/#progress)
[![Fuzzy](badges/fuzzy.svg?v=17.533838)](https://wearetommybruh.github.io/Legaia2-Decomp/#progress)
[![Data](badges/data.svg)](https://wearetommybruh.github.io/Legaia2-Decomp/#progress)
[![Units](badges/units.svg)](https://wearetommybruh.github.io/Legaia2-Decomp/#progress)

# Setup

Required Tools
- Python 3
- Clang
- LLD (ld.lld)
- EE-GCC 2.9-ee-991111-01
- Legaia 2: Duel Saga (PAL) disc image

You can get EE-GCC 2.9-ee-991111-01 through decomp.me

```bash
mkdir -p ~/tools/ee-gcc2.9-991111-01
```
```bash
curl -L https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.9-991111-01.tar.xz \
  | tar xJ -C ~/tools/ee-gcc2.9-991111-01
```
The compiler is a 32-bit linux executable. On 64-bit systems you need to install the 32-bit runtime libraries.
```bash
sudo dpkg --add-architecture i386
sudo [package manager] update
sudo [package manager] libc6:i386
```

```bash
git clone https://github.com/WeAreTommyBruh/Legaia2-Decomp.git
```

- Put your disc image in the root as "SLES_50891.ISO"
```bash
python3 tools/asm_build.py all
```
- For windows users you need to install [WSL](https://github.com/microsoft/WSL).
```bash
wsl --install
```

# Asset Viewer
There is an [asset viewer](https://wearetommybruh.github.io/Legaia2-Decomp/viewer.html) on the website.

You open your own disc image and you can look at the models, textures, audio, motions and effects. There is also a button to extract everything to a folder. It all runs in your browser. Nothing gets uploaded and there are no game files in this repo.

It is not perfect so expect bugs. If there are any report it in [issues](https://github.com/WeAreTommyBruh/Legaia2-Decomp/issues). Effects are only a rough preview. The viewer is JavaScript, it lives in `site/viewer`.

# AI Usage
This project is obviously entirely ai.

# Contributors

- [WeAreTommyBruh](https://github.com/WeAreTommyBruh) — project owner.
- [Claude Code](https://github.com/anthropics/claude-code) - AI-assisted function matching and tooling.
- [Codex](https://github.com/codex) — AI-assisted function matching and tooling.

# Legal
The code in this repository is released under the [MIT License](LICENSE). This project contains no game assets of Legaia 2: Duel Saga. I will not provide any copies of the game. 
This project is not affiliated with or endorsed by the game's original developers or publisher.

# How Long Is This Gonna Take?
Reverse engineering and matching decompilation are time-consuming processes. Depending on how complex the game is and my use with ai this will take many months to complete, Possibly a year. I am not in a rush to finish this so this project will be finished when it's finished.
