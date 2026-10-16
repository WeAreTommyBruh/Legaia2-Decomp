// Names functions using evidence left in the executable:
//  - __FILE__/__LINE__ arguments passed to the debug allocator and friends give
//    each caller's source file, and functions between two functions of the same
//    file are attributed to it too (object files are linked contiguously).
//  - Sony SDK error strings of the form "sceXxx: ..." name the SDK function
//    that prints them.
//  - A handful of hand-verified helpers get real names and signatures.
// Usage: -postScript NameFunctions.java <report|apply> <report_file>
//@category Analysis

import java.io.File;
import java.io.PrintWriter;
import java.util.*;
import java.util.regex.*;

import ghidra.app.cmd.function.ApplyFunctionSignatureCmd;
import ghidra.app.script.GhidraScript;
import ghidra.app.util.cparser.C.CParserUtils;
import ghidra.program.model.address.*;
import ghidra.program.model.data.FunctionDefinitionDataType;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.scalar.Scalar;
import ghidra.program.model.symbol.*;

public class NameFunctions extends GhidraScript {

	// Hand-verified functions: address, name, C signature (null = rename only).
	// See README.md for the evidence behind each group.
	private static final String[][] KNOWN = {
		// game helpers
		{ "001118f8", "DbgPrintf", "int DbgPrintf(char *fmt, ...)" },
		{ "00162130", "MemAllocDbg", "void * MemAllocDbg(uint size, char *file, int line)" },
		{ "001621f8", "MemFreeDbg", "void MemFreeDbg(void *ptr, char *file, int line)" },
		{ "00162190", "MemAlloc", "void * MemAlloc(uint size)" },
		{ "00162238", "MemFree", "void MemFree(void *ptr)" },
		{ "001618c8", "MemGetFreeSize", "int MemGetFreeSize(void)" },
		{ "0024abe0", "DbgPrintFreeMem", "int DbgPrintFreeMem(char *label)" },
		{ "00220b80", "DbgStub", "int DbgStub(char *msg)" },
		// names printed by the functions' own debug messages
		{ "0018b3a8", "MallocLoadFileNB", "void * MallocLoadFileNB(char *path, int flags)" },
		{ "0018b7c8", "LoadFile", "int LoadFile(char *path, void *dst)" },
		// file formats and scripts (descriptive names)
		{ "0018b2a8", "FileGetSize", "int FileGetSize(char *path)" },
		{ "001897c8", "FsDirLoad", null },
		{ "001908f0", "LzssDecode", "void LzssDecode(void *dst, void *src, int size)" },
		{ "001909f8", "LzssDecodeAlloc", "void * LzssDecodeAlloc(void *src)" },
		{ "00190740", "LzssDecodeStep", null },
		{ "002a3a70", "PacLoadRoom", null },
		{ "002a3278", "PacLoadArea", null },
		{ "002a3950", "PacChunkCopy", "void * PacChunkCopy(void *src, uint size)" },
		{ "00151c60", "BsdLoad", null },
		{ "00151930", "BtlScriptFindFrame", "float * BtlScriptFindFrame(int track, int frame)" },
		{ "00144910", "BtlScriptRun", "void BtlScriptRun(float *cmds)" },
		{ "001984e8", "EfbRun", null },
		{ "001992c8", "EfbSetParam", null },
		{ "00198790", "EfbExec", null },
		{ "0019b260", "EfbLookupCommand", null },
		{ "0019b488", "EfbLookupSection", null },
		{ "0019b6c0", "EfbCommandAllowed", null },
		// motion (.mov) accessors; one path per clip layout (header flag 0x20)
		{ "00212f00", "MotClip", "void * MotClip(void *mov, int clip)" },
		{ "00212f18", "MotClipCount", null },
		{ "00212f20", "MotClipName", null },
		{ "00212f40", "MotHierarchyLength", null },
		{ "00212f60", "MotIndexMapLength", null },
		{ "00212f80", "MotHierarchy", null },
		{ "00212fe0", "MotIndexMap", null },
		{ "00213048", "MotBoneCount", null },
		{ "00213068", "MotFrameCount", null },
		{ "00213088", "MotIsPacked", null },
		{ "002130b0", "MotIsHalfRate", null },
		{ "002130d8", "MotFlag02", null },
		{ "00213100", "MotHasScale", null },
		{ "00213128", "MotFlag40", null },
		{ "00213150", "MotIsFineRotation", null },
		{ "00213178", "MotBoneBase", null },
		{ "00213258", "MotBoneName", null },
		{ "00213410", "MotChannelValue", null },
		{ "00213480", "MotChannelValuePair", null },
		{ "00213548", "MotTranslation", null },
		{ "002138a0", "MotRotation", null },
		{ "002139b8", "MotRotationRaw", null },
		{ "00213eb0", "MotScale", null },
		{ "00213fc8", "MotEnvelopeCount", null },
		{ "00214010", "MotEnvelope", null },
		{ "00214068", "MotAttachmentCount", null },
		{ "002140b0", "MotAttachment", null },
		{ "002d3b98", "SndBankRegister", null },
		{ "002d04c0", "SndVoiceSetParam", null },
		{ "002d1f48", "SndVoiceSetPitch", null },
		// Sony SDK (identified from usage)
		{ "002cb958", "sceCdSearchFile", "int sceCdSearchFile(void *file, char *name)" },
		// newlib C library
		{ "002dc804", "memset", "void * memset(void *dst, int c, uint n)" },
		{ "002dc650", "memcpy", "void * memcpy(void *dst, void *src, uint n)" },
		{ "002dc700", "memmove", "void * memmove(void *dst, void *src, uint n)" },
		{ "002dd4cc", "strcpy", "char * strcpy(char *dst, char *src)" },
		{ "002dd928", "strncpy", "char * strncpy(char *dst, char *src, uint n)" },
		{ "002dd0b0", "strcat", "char * strcat(char *dst, char *src)" },
		{ "002dd5e0", "strlen", "uint strlen(char *s)" },
		{ "002dd36c", "strcmp", "int strcmp(char *a, char *b)" },
		{ "002dd1dc", "strchr", "char * strchr(char *s, int c)" },
		{ "002ddae8", "strstr", "char * strstr(char *haystack, char *needle)" },
		{ "002dd718", "strlwr", "char * strlwr(char *s)" },
		{ "002dce40", "sprintf", "int sprintf(char *dst, char *fmt, ...)" },
		{ "002dc918", "printf", "int printf(char *fmt, ...)" },
		{ "002ddec8", "vfprintf", "int vfprintf(void *fp, char *fmt, void *ap)" },
		{ "002dc978", "rand", "int rand(void)" },
		{ "002dc968", "srand", "void srand(uint seed)" },
		{ "002dbed8", "_malloc_r", "void * _malloc_r(void *reent, uint size)" },
		// libgcc soft-float (fp-bit.c); the EE has no double-precision FPU
		{ "002d9440", "__extendsfdf2", null },
		{ "002d89b0", "__unpack_f", null },
		{ "002d80c0", "__make_dp", null },
		{ "002d7580", "__unpack_d", null },
		{ "002d7450", "__pack_d", null },
		{ "002d7620", "_fpadd_parts", null },
		{ "002d7860", "__adddf3", null },
		{ "002d78b8", "__subdf3", null },
		{ "002d7920", "__muldf3", null },
		{ "002d7d30", "__fpcmp_parts_d", null },
		{ "002d7e98", "__floatsidf", null },
		{ "002d7f50", "__fixdfsi", null },
	};

	// Data labels: address, name.
	private static final String[][] KNOWN_DATA = {
		{ "0032ef48", "BtlScriptOpTable" },
		{ "0055fc80", "BtlScriptTracks" },
		{ "0058b280", "FsDirBuffer" },
		{ "00443cc8", "EfbParamArgCounts" },
		{ "0036cc10", "EfbSectionNames" },
		{ "0036cc50", "EfbCommandNames" },
		{ "0036ce50", "EfbCommandKinds" },
	};

	private static final String[] ARG_REGS = { "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3" };
	private static final Pattern SRC = Pattern.compile("^[A-Za-z0-9_./]+\\.(cpp|c|cc)$");
	private static final Pattern SDK_MSG = Pattern.compile("^\\s*(sce[A-Z][A-Za-z0-9_]+)\\s*:");

	private boolean apply;
	private PrintWriter out;

	@Override
	protected void run() throws Exception {
		String[] args = getScriptArgs();
		apply = args.length > 0 && args[0].equals("apply");
		out = new PrintWriter(new File(args.length > 1 ? args[1] : "naming_report.txt"));
		try {
			if (apply) {
				applyKnown();
			}
			Map<Function, String> sdk = sdkNames();
			attributeSources(sdk.keySet());
			if (apply) {
				for (Map.Entry<Function, String> e : sdk.entrySet()) {
					e.getKey().setName(e.getValue(), SourceType.ANALYSIS);
					e.getKey().addTag("sdk");
				}
			}
			debugNames();
		}
		finally {
			out.close();
		}
	}

	private static final int ENTRY_WINDOW = 0x60;
	private static final Pattern SELF_NAME = Pattern.compile(
		"^\\s*-*\\s*([A-Z][a-z0-9]+(?:[A-Z][A-Za-z0-9]*)+|[a-z]+[A-Z][A-Za-z0-9]+)(?=$|[\\s:(\\[%,.!])");

	/**
	 * Functions that print their own name at entry ("SyncCheck 0\n"). A name is
	 * used only when one function prints it, within its first ENTRY_WINDOW bytes,
	 * and that function prints no other such name; names printed deeper inside a
	 * function usually describe something it calls.
	 */
	private void debugNames() throws Exception {
		Map<Function, Set<String>> byFunc = new HashMap<>();
		Map<String, Set<Function>> byName = new TreeMap<>();
		Map<String, Long> distance = new HashMap<>();
		for (Data d : strings()) {
			Matcher m = SELF_NAME.matcher(String.valueOf(d.getValue()));
			if (!m.find()) {
				continue;
			}
			String name = m.group(1);
			for (Reference r : getReferencesTo(d.getAddress())) {
				Function f = getFunctionContaining(r.getFromAddress());
				if (f == null) {
					continue;
				}
				byFunc.computeIfAbsent(f, k -> new TreeSet<>()).add(name);
				byName.computeIfAbsent(name, k -> new LinkedHashSet<>()).add(f);
				distance.merge(name + "@" + f.getEntryPoint(),
					r.getFromAddress().subtract(f.getEntryPoint()), Math::min);
			}
		}
		out.println("== Names from debug messages printed at function entry ==");
		int accepted = 0;
		for (Map.Entry<String, Set<Function>> e : byName.entrySet()) {
			String name = e.getKey();
			Function f = e.getValue().iterator().next();
			String verdict;
			if (e.getValue().size() != 1) {
				verdict = "SKIP printed by " + e.getValue().size() + " functions";
			}
			else if (byFunc.get(f).size() != 1) {
				verdict = "SKIP function also prints " + byFunc.get(f);
			}
			else if (distance.get(name + "@" + f.getEntryPoint()) > ENTRY_WINDOW) {
				verdict = "SKIP not printed at entry";
			}
			else if (getFunction(name) != null) {
				verdict = "SKIP name already used";
			}
			else if (f.getSymbol().getSource() == SourceType.USER_DEFINED || !f.getName().matches(
				"(FUN_|[a-z0-9_]+_)[0-9a-f]{8}")) {
				verdict = "SKIP function already named " + f.getName();
			}
			else {
				verdict = "ACCEPT " + f.getName();
				accepted++;
				if (apply) {
					f.setName(name, SourceType.ANALYSIS);
					f.addTag("debug-name");
				}
			}
			out.printf("  %-30s %s%n", name, verdict);
		}
		out.printf("  accepted %d of %d%n%n", accepted, byName.size());
	}

	private void applyKnown() throws Exception {
		for (String[] k : KNOWN) {
			Address a = toAddr(k[0]);
			Function f = getFunctionAt(a);
			if (f == null) {
				printerr("No function at " + a);
				continue;
			}
			f.setName(k[1], SourceType.USER_DEFINED);
			if (k[2] != null) {
				FunctionDefinitionDataType sig = CParserUtils.parseSignature(
					(ghidra.app.services.DataTypeManagerService) null, currentProgram, k[2], true);
				new ApplyFunctionSignatureCmd(a, sig, SourceType.USER_DEFINED).applyTo(currentProgram);
			}
		}
		for (String[] k : KNOWN_DATA) {
			createLabel(toAddr(k[0]), k[1], true, SourceType.USER_DEFINED);
		}
	}

	private AddressSetView textSet() {
		MemoryBlock b = currentProgram.getMemory().getBlock(".text");
		return new AddressSet(b.getStart(), b.getEnd());
	}

	private List<Data> strings() {
		List<Data> list = new ArrayList<>();
		DataIterator it = currentProgram.getListing().getDefinedData(true);
		while (it.hasNext()) {
			Data d = it.next();
			if (d.hasStringValue()) {
				list.add(d);
			}
		}
		return list;
	}

	private Set<Function> referencingFunctions(Address a) {
		Set<Function> fs = new LinkedHashSet<>();
		for (Reference r : getReferencesTo(a)) {
			Function f = getFunctionContaining(r.getFromAddress());
			if (f != null) {
				fs.add(f);
			}
		}
		return fs;
	}

	private Map<Function, String> sdkNames() {
		Map<String, Set<Function>> byName = new TreeMap<>();
		for (Data d : strings()) {
			Matcher m = SDK_MSG.matcher(String.valueOf(d.getValue()));
			if (m.find()) {
				byName.computeIfAbsent(m.group(1), k -> new LinkedHashSet<>())
						.addAll(referencingFunctions(d.getAddress()));
			}
		}
		// A name is only trusted when exactly one function prints it and that
		// function prints no other SDK name.
		Map<Function, Set<String>> byFunc = new HashMap<>();
		byName.forEach((n, fs) -> fs.forEach(f -> byFunc.computeIfAbsent(f, k -> new TreeSet<>()).add(n)));
		Map<Function, String> result = new LinkedHashMap<>();
		out.println("== SDK names from error strings ==");
		for (Map.Entry<String, Set<Function>> e : byName.entrySet()) {
			String verdict;
			if (e.getValue().size() != 1) {
				verdict = "SKIP (" + e.getValue().size() + " functions)";
			}
			else {
				Function f = e.getValue().iterator().next();
				if (byFunc.get(f).size() > 1) {
					verdict = "SKIP (function also prints " + byFunc.get(f) + ")";
				}
				else if (!f.getName().startsWith("FUN_")) {
					verdict = "SKIP (already named " + f.getName() + ")";
				}
				else {
					verdict = "-> " + f.getEntryPoint();
					result.put(f, e.getKey());
				}
			}
			out.printf("  %-28s %s%n", e.getKey(), verdict);
		}
		out.println();
		return result;
	}

	private void attributeSources(Set<Function> sdkFuncs) throws Exception {
		// function -> file -> line numbers
		Map<Function, Map<String, SortedSet<Long>>> direct = new HashMap<>();
		Map<Long, String> srcAddrs = new HashMap<>();
		for (Data d : strings()) {
			String s = String.valueOf(d.getValue());
			if (!SRC.matcher(s).matches()) {
				continue;
			}
			srcAddrs.put(d.getAddress().getOffset(), s);
			for (Function f : referencingFunctions(d.getAddress())) {
				direct.computeIfAbsent(f, k -> new TreeMap<>()).computeIfAbsent(s, k -> new TreeSet<>());
			}
		}
		for (Map.Entry<Function, Map<String, SortedSet<Long>>> e : direct.entrySet()) {
			collectLines(e.getKey(), srcAddrs, e.getValue());
		}
		int withLines = 0;
		for (Map<String, SortedSet<Long>> m : direct.values()) {
			for (SortedSet<Long> lines : m.values()) {
				withLines += lines.isEmpty() ? 0 : 1;
			}
		}
		out.printf("Line numbers recovered for %d of %d directly attributed functions%n%n",
			withLines, direct.size());

		List<Function> funcs = new ArrayList<>();
		for (Function f : currentProgram.getFunctionManager().getFunctions(textSet(), true)) {
			funcs.add(f);
		}

		Map<Function, String> file = new HashMap<>();
		out.println("== Functions referencing more than one source file ==");
		for (Function f : funcs) {
			Map<String, SortedSet<Long>> m = direct.get(f);
			if (m == null) {
				continue;
			}
			if (m.size() == 1) {
				file.put(f, m.keySet().iterator().next());
			}
			else {
				out.println("  " + f.getEntryPoint() + " " + m.keySet() + " (left unattributed)");
			}
		}
		out.println();

		// Fill gaps between two functions of the same file.
		Map<Function, String> inferred = new HashMap<>();
		int lastIdx = -1;
		for (int i = 0; i < funcs.size(); i++) {
			String fl = file.get(funcs.get(i));
			if (fl == null) {
				continue;
			}
			if (lastIdx >= 0 && fl.equals(file.get(funcs.get(lastIdx)))) {
				for (int j = lastIdx + 1; j < i; j++) {
					inferred.put(funcs.get(j), fl);
				}
			}
			lastIdx = i;
		}

		// Per-file summary and contiguity check.
		Map<String, long[]> stats = new TreeMap<>(); // direct, inferred, min, max
		for (Function f : funcs) {
			String fl = file.containsKey(f) ? file.get(f) : inferred.get(f);
			if (fl == null) {
				continue;
			}
			long a = f.getEntryPoint().getOffset();
			long[] s = stats.computeIfAbsent(fl, k -> new long[] { 0, 0, Long.MAX_VALUE, 0 });
			s[file.containsKey(f) ? 0 : 1]++;
			s[2] = Math.min(s[2], a);
			s[3] = Math.max(s[3], a);
		}
		out.println("== Source files (by address) ==");
		List<Map.Entry<String, long[]>> ordered = new ArrayList<>(stats.entrySet());
		ordered.sort(Comparator.comparingLong(e -> e.getValue()[2]));
		long prevMax = -1;
		String prevName = null;
		for (Map.Entry<String, long[]> e : ordered) {
			long[] s = e.getValue();
			String overlap = s[2] < prevMax ? "  OVERLAPS " + prevName : "";
			out.printf("  %08x-%08x %-22s direct=%-4d inferred=%-4d%s%n", s[2], s[3], e.getKey(),
				s[0], s[1], overlap);
			if (s[3] > prevMax) {
				prevMax = s[3];
				prevName = e.getKey();
			}
		}
		out.printf("%nAttributed %d of %d functions (%d direct, %d inferred)%n%n",
			file.size() + inferred.size(), funcs.size(), file.size(), inferred.size());

		// Line numbers should rise with address inside a file.
		out.println("== Line-order violations (line numbers falling as address rises) ==");
		Map<String, Long> lastLine = new HashMap<>();
		int violations = 0;
		for (Function f : funcs) {
			String fl = file.get(f);
			if (fl == null || direct.get(f).get(fl).isEmpty()) {
				continue;
			}
			SortedSet<Long> lines = direct.get(f).get(fl);
			Long prev = lastLine.get(fl);
			if (prev != null && lines.first() < prev) {
				out.printf("  %s %s line %d after line %d%n", f.getEntryPoint(), fl, lines.first(),
					prev);
				violations++;
			}
			lastLine.put(fl, lines.last());
		}
		out.println("  total: " + violations);
		out.println();

		if (!apply) {
			return;
		}
		for (Function f : funcs) {
			if (sdkFuncs.contains(f)) {
				continue;
			}
			boolean isDirect = file.containsKey(f);
			String fl = isDirect ? file.get(f) : inferred.get(f);
			if (fl == null) {
				continue;
			}
			String stem = fl.replaceAll("^.*/", "").replaceAll("\\.[a-z]+$", "");
			f.addTag("src:" + fl);
			f.addTag(isDirect ? "src-direct" : "src-inferred");
			String comment = "Source: " + fl + (isDirect ? "" : " (inferred from neighbours)");
			if (isDirect && !direct.get(f).get(fl).isEmpty()) {
				comment += "\nSource lines referenced: " + direct.get(f).get(fl);
			}
			f.setComment(comment);
			if (f.getName().startsWith("FUN_")) {
				f.setName(stem + "_" + f.getEntryPoint(), SourceType.ANALYSIS);
			}
		}
	}

	/**
	 * Walks the function tracking constant register values (lui/addiu/li/ori/move)
	 * and, at each call, records the __LINE__ argument that follows a __FILE__
	 * argument. Values are forgotten at branch targets and after calls.
	 */
	private void collectLines(Function f, Map<Long, String> srcAddrs,
			Map<String, SortedSet<Long>> lines) {
		Map<String, Long> val = new HashMap<>();
		Instruction pendingCall = null;
		for (Instruction i : currentProgram.getListing().getInstructions(f.getBody(), true)) {
			if (pendingCall == null && isBranchTarget(i)) {
				val.clear();
			}
			track(i, val);
			if (pendingCall != null) { // delay slot done: arguments are final
				for (int k = 0; k < ARG_REGS.length - 1; k++) {
					Long v = val.get(ARG_REGS[k]);
					String fl = v == null ? null : srcAddrs.get(v);
					Long line = val.get(ARG_REGS[k + 1]);
					if (fl != null && line != null && lines.containsKey(fl)) {
						lines.get(fl).add(line);
					}
				}
				val.clear();
				pendingCall = null;
			}
			String m = mnemonic(i);
			if (m.equals("jal") || m.equals("jalr")) {
				pendingCall = i;
			}
		}
	}

	private boolean isBranchTarget(Instruction i) {
		for (Reference r : getReferencesTo(i.getAddress())) {
			if (r.getReferenceType().isFlow()) {
				return true;
			}
		}
		return false;
	}

	private static String mnemonic(Instruction i) {
		String m = i.getMnemonicString();
		return m.startsWith("_") ? m.substring(1) : m;
	}

	private static String reg(Object o) {
		return o instanceof Register r ? r.getName().replaceAll("_lo$", "") : null;
	}

	private static void track(Instruction i, Map<String, Long> val) {
		String m = mnemonic(i);
		Object[] dst = i.getNumOperands() > 0 ? i.getOpObjects(0) : new Object[0];
		String d = dst.length == 1 ? reg(dst[0]) : null;
		Long result = null;
		boolean handled = d != null;
		if (handled) {
			switch (m) {
				case "lui" -> result = scalar(i, 1) == null ? null : (scalar(i, 1) << 16) & 0xffffffffL;
				case "li" -> result = scalar(i, 1);
				case "move" -> result = val.get(srcReg(i, 1));
				case "addiu", "daddiu", "ori" -> {
					String s = srcReg(i, 1);
					Long base = "zero".equals(s) ? Long.valueOf(0) : val.get(s);
					Long imm = scalar(i, 2);
					if (base != null && imm != null) {
						result = m.equals("ori") ? base | (imm & 0xffff) : (base + imm) & 0xffffffffL;
					}
				}
				default -> handled = false;
			}
		}
		if (handled) {
			if (result == null) {
				val.remove(d);
			}
			else {
				val.put(d, result);
			}
			return;
		}
		for (Object o : i.getResultObjects()) {
			String r = reg(o);
			if (r != null) {
				val.remove(r);
			}
		}
	}

	private static String srcReg(Instruction i, int op) {
		if (i.getNumOperands() <= op) {
			return null;
		}
		Object[] objs = i.getOpObjects(op);
		return objs.length == 1 ? reg(objs[0]) : null;
	}

	private static Long scalar(Instruction i, int op) {
		if (i.getNumOperands() <= op) {
			return null;
		}
		Scalar s = i.getScalar(op);
		return s == null ? null : s.getSignedValue();
	}
}
