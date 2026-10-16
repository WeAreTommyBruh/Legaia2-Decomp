#!/usr/bin/env bash
# Rebuilds the Ghidra project and decompiled C from the disc image.
#   1. extract the executable from the ISO
#   2. import + auto-analyse (PS2 Emotion Engine language, MMIO labels)
#   3. recover code the analyser missed (switch tables, pointer-only functions)
#   4. name functions from __FILE__/__LINE__ evidence and SDK error strings
#   5. export C (combined file, header, one file per function)
#   6. extract and convert the game files (file system, textures, audio, MIDI,
#      models, movie) with the tools in tools/
# Reports land in ghidra/*.txt, logs in ghidra/*.log.
set -euo pipefail

ROOT="$(cd "$(dirname "$0")" && pwd)"
ISO="$ROOT/SLES_50891.ISO"
EXE=SLES_508.91
export JAVA_HOME="${JAVA_HOME:-$HOME/tools/jdk-21.0.12.1+1}"
GHIDRA="${GHIDRA:-$HOME/tools/ghidra_12.1.4_PUBLIC}"
export GHIDRA_HEADLESS_MAXMEM=8G
EE_SCRIPTS="$GHIDRA/Ghidra/Extensions/ghidra-emotionengine-reloaded/ghidra_scripts"

headless() {
	local log="$1"; shift
	echo "== $log"
	"$GHIDRA/support/analyzeHeadless" "$ROOT/ghidra" Legaia2 \
		-scriptPath "$ROOT/ghidra/scripts;$EE_SCRIPTS" -max-cpu "$(nproc)" "$@" \
		> "$ROOT/ghidra/$log.log" 2>&1 &
	local pid=$! start=$SECONDS
	# Ghidra is quiet for long stretches (auto-analysis takes a while):
	# show the elapsed time and its latest log line while it runs
	while kill -0 "$pid" 2>/dev/null; do
		sleep 15
		printf '   %4ds  %s\n' $((SECONDS - start)) \
			"$(tail -n 1 "$ROOT/ghidra/$log.log" | cut -c1-100)"
	done
	wait "$pid"
	if grep -qE "SCRIPT ERROR|ERROR .*\.java" "$ROOT/ghidra/$log.log"; then
		grep -E "ERROR" "$ROOT/ghidra/$log.log" | head -20
		exit 1
	fi
}

mkdir -p "$ROOT/disc" "$ROOT/ghidra"
[ -f "$ROOT/disc/$EXE" ] || 7z e -y -o"$ROOT/disc" "$ISO" "$EXE" SYSTEM.CNF > /dev/null

rm -rf "$ROOT/ghidra/Legaia2.gpr" "$ROOT/ghidra/Legaia2.rep"
headless 1_import -import "$ROOT/disc/$EXE" -processor "r5900:LE:32:default" \
	-preScript ImportMMIORegisterLabels.java
headless 2_recover -process "$EXE" -noanalysis \
	-postScript RecoverCode.java "$ROOT/ghidra/recover_report.txt"
headless 3_name -process "$EXE" -noanalysis \
	-postScript NameFunctions.java apply "$ROOT/ghidra/naming_report.txt"
headless 4_export -process "$EXE" -noanalysis -readOnly \
	-postScript ExportDecomp.java "$ROOT/decomp"

grep -h "ExportDecomp.java>" "$ROOT/ghidra/4_export.log" | sed 's/^INFO  //'

# 6. game files
cd "$ROOT"
step() { echo "== $1"; }
step fs;        python3 tools/fs_tool.py "$ISO" extract fs
                python3 tools/fs_tool.py "$ISO" list > fs_index.csv
step lzss;      python3 tools/lzss.py --all fs fs_unpacked
step docs;      mkdir -p docs && python3 tools/battle_script.py opcodes "disc/$EXE" > docs/battle_script_opcodes.md
step textures;  python3 tools/tex_tool.py all fs png      # ~7,700 textures
step audio;     python3 tools/adpcm.py all fs wav         # ~3 GB of WAV
step midi;      mkdir -p mid
for f in fs/data/aound/*.sq; do
	python3 tools/sq2mid.py "$f" "mid/$(basename "${f%.sq}").mid"
done
step models;    python3 tools/tmd_tool.py all fs obj      # ~280 models
step movie;     7z e -y -odisc "$ISO" PALMOVIE.PSS > /dev/null
                mkdir -p movie && python3 tools/pss_demux.py disc/PALMOVIE.PSS movie/PALMOVIE
