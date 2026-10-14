#!/usr/bin/env bash
# Rebuilds the Ghidra project and decompiled C from the disc image.
#   1. extract the executable from the ISO
#   2. import + auto-analyse (PS2 Emotion Engine language, MMIO labels)
#   3. recover code the analyser missed (switch tables, pointer-only functions)
#   4. name functions from __FILE__/__LINE__ evidence and SDK error strings
#   5. export C (combined file, header, one file per function)
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
		> "$ROOT/ghidra/$log.log" 2>&1
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
