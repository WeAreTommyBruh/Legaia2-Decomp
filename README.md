<p align="center">
  ![Alt Text](https://github.com/WeAreTommyBruh/Legaia2-Decomp/blob/29e6bfa6fd988cf3c49323602c1fc3d83d9a5562/logo.png)
</p>


# Legaia 2: Duel Saga (PAL, SLES-50891) decompilation
This project aims to rebuild Legaia 2 code into readable C source code. The goal of this project is a byte-for-byte decomp that can reproduce the games executable.

[![Code](https://bytematch.dev/WeAreTommyBruh/Legaia2-Decomp.svg?mode=shield&label=Code&measure=matched_code_percent)](https://bytematch.dev/WeAreTommyBruh/Legaia2-Decomp)
[![Functions](https://bytematch.dev/WeAreTommyBruh/Legaia2-Decomp.svg?mode=shield&label=Functions&measure=matched_functions)](https://bytematch.dev/WeAreTommyBruh/Legaia2-Decomp)

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

# AI Usage
This project is obviously entirely ai. I check mostly everything to make sure there is nothing wrong.

# Contributing
Any help will be welcome. Please read [CONTRIBUTING.md](https://github.com/WeAreTommyBruh/Legaia2-Decomp/blob/main/CONTRIBUTING.md) for more details.

# Legal
This project contains no game assets of Legaia 2: Duel Saga. I will not provide any copies of the game. 
This project is not affiliated with or endorsed by the game's original developers or publisher.

# How Long Will This Take?
Reverse engineering and matching decompilation are time-consuming processes. Depending on how complex the game is and my use with ai this will take many months to complete, Possibly a year. I am not in a rush to finish this so this project will be finished when it's finished.
