# Legaia 2: Duel Saga (PAL, SLES-50891) decompilation
Legaia 2:Duel Saga (PAL) is now being decompiled using ghidra and claude code.

# AI Usage
I check mostly everything to make sure there are no copyrighted stuff or any errors. This project is heavily assisted using mostly claude opus 5.5.

# Rebuilding
Put your Legaia 2 (PAL) disc image in the root as "SLES_50891.ISO" 

```bash
./decompile.sh
python3 tools/fs_tool.py SLES_50891.ISO extract fs
python3 tools/fs_tool.py SLES_50891.ISO list > fs_index.csv
python3 tools/lzss.py --all fs fs_unpacked
mkdir -p docs && python3 tools/battle_script.py opcodes disc/SLES_508.91 > docs/battle_script_opcodes.md
```

