// Recovers code that auto-analysis missed in .text:
//  - removes data items that were wrongly placed inside code,
//  - decodes switch tables the analyzer gave up on (it times out on the
//    largest functions) and grows those functions over their case blocks,
//  - disassembles gaps (functions only reached through pointer tables),
//  - creates functions at code runs that start after a return or tail call.
// Usage: -postScript RecoverCode.java <report_file>
//@category Analysis

import java.io.File;
import java.io.PrintWriter;
import java.util.*;

import ghidra.app.cmd.function.CreateFunctionCmd;
import ghidra.app.decompiler.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.pcode.HighFunction;
import ghidra.program.model.pcode.JumpTable;
import ghidra.program.model.symbol.*;

public class RecoverCode extends GhidraScript {

	private PrintWriter out;
	private final Set<Address> triedSwitches = new HashSet<>();

	@Override
	protected void run() throws Exception {
		String[] args = getScriptArgs();
		out = new PrintWriter(new File(args.length > 0 ? args[0] : "recover_report.txt"));
		try {
			report("Before");
			clearDataInCode();
			for (int pass = 1; pass <= 100; pass++) {
				int gaps = disassembleGaps();
				int cases = recoverSwitches();
				int funcs = createOrphanFunctions();
				analyzeChanges(currentProgram);
				out.printf("Pass %d: disassembled %d gaps, added %d switch cases, created %d functions%n",
					pass, gaps, cases, funcs);
				out.flush();
				if (gaps + cases + funcs == 0) {
					break;
				}
			}
			report("After");
		}
		finally {
			out.close();
		}
	}

	private AddressSetView textSet() {
		MemoryBlock b = currentProgram.getMemory().getBlock(".text");
		return new AddressSet(b.getStart(), b.getEnd());
	}

	private void report(String label) throws Exception {
		long orphanBytes = 0;
		List<AddressRange> runs = orphanRuns();
		for (AddressRange r : runs) {
			orphanBytes += r.getLength();
		}
		long undefined = 0;
		for (AddressRange r : currentProgram.getListing().getUndefinedRanges(textSet(), false,
			monitor)) {
			undefined += r.getLength();
		}
		out.printf("%s: %d functions, %d orphan runs (%d bytes), %d undisassembled bytes%n", label,
			currentProgram.getFunctionManager().getFunctionCount(), runs.size(), orphanBytes,
			undefined);
		if (label.equals("After")) {
			out.println("\nRemaining orphan runs over 256 bytes:");
			for (AddressRange r : runs) {
				if (r.getLength() > 256) {
					out.printf("  %s len=%d after: %s%n", r.getMinAddress(), r.getLength(),
						getInstructionBefore(r.getMinAddress()));
				}
			}
		}
		out.flush();
	}

	private void clearDataInCode() throws Exception {
		List<Data> bad = new ArrayList<>();
		DataIterator it = currentProgram.getListing().getDefinedData(textSet(), true);
		while (it.hasNext()) {
			bad.add(it.next());
		}
		for (Data d : bad) {
			out.println("Cleared " + d.getDataType().getName() + " at " + d.getAddress());
			removeData(d);
			Address aligned = toAddr(d.getAddress().getOffset() & ~3L);
			while (getInstructionContaining(aligned) == null && aligned.compareTo(textSet().getMinAddress()) > 0 &&
				getInstructionContaining(aligned.subtract(4)) == null) {
				aligned = aligned.subtract(4);
			}
			disassemble(aligned);
		}
	}

	private List<AddressRange> orphanRuns() {
		AddressSet orphans = new AddressSet();
		for (Instruction i : currentProgram.getListing().getInstructions(textSet(), true)) {
			if (getFunctionContaining(i.getAddress()) == null) {
				orphans.add(i.getMinAddress(), i.getMaxAddress());
			}
		}
		List<AddressRange> runs = new ArrayList<>();
		orphans.getAddressRanges().forEach(runs::add);
		return runs;
	}

	private int disassembleGaps() throws Exception {
		int n = 0;
		List<AddressRange> gaps = new ArrayList<>();
		currentProgram.getListing().getUndefinedRanges(textSet(), false, monitor).forEach(gaps::add);
		for (AddressRange r : gaps) {
			Address a = r.getMinAddress();
			if (a.getOffset() % 4 != 0) {
				continue;
			}
			while (a.compareTo(r.getMaxAddress()) < 0 && currentProgram.getMemory().getInt(a) == 0) {
				a = a.add(4);
			}
			if (a.compareTo(r.getMaxAddress()) < 0 && getInstructionAt(a) == null && disassemble(a)) {
				n++;
			}
		}
		return n;
	}

	private static boolean isSwitchJump(Instruction i) {
		return i.getMnemonicString().equals("jr") && !i.toString().equals("jr ra");
	}

	/** Decompile functions holding unresolved register jumps and apply the tables found. */
	private int recoverSwitches() throws Exception {
		Map<Function, List<Address>> todo = new LinkedHashMap<>();
		for (Function f : currentProgram.getFunctionManager().getFunctions(textSet(), true)) {
			for (Instruction i : currentProgram.getListing().getInstructions(f.getBody(), true)) {
				if (isSwitchJump(i) && !triedSwitches.contains(i.getAddress()) &&
					!hasComputedJumpRefs(i)) {
					todo.computeIfAbsent(f, k -> new ArrayList<>()).add(i.getAddress());
				}
			}
		}
		int added = 0;
		DecompInterface ifc = new DecompInterface();
		DecompileOptions opts = new DecompileOptions();
		opts.setDefaultTimeout(900);
		opts.setMaxPayloadMBytes(1024);
		ifc.setOptions(opts);
		ifc.openProgram(currentProgram);
		try {
			for (Map.Entry<Function, List<Address>> e : todo.entrySet()) {
				Function f = e.getKey();
				triedSwitches.addAll(e.getValue());
				long t0 = System.currentTimeMillis();
				DecompileResults res = ifc.decompileFunction(f, 900, monitor);
				HighFunction hf = res.getHighFunction();
				if (hf == null) {
					out.printf("  switch: %s failed to decompile (%s)%n", f.getName(),
						res.getErrorMessage().trim());
					continue;
				}
				int before = added;
				for (JumpTable jt : hf.getJumpTables()) {
					Address sw = jt.getSwitchAddress();
					for (Address c : jt.getCases()) {
						if (!textSet().contains(c)) {
							continue;
						}
						if (currentProgram.getReferenceManager().getReference(sw, c, 0) == null) {
							currentProgram.getReferenceManager().addMemoryReference(sw, c,
								RefType.COMPUTED_JUMP, SourceType.ANALYSIS, 0);
							added++;
						}
						Function other = getFunctionAt(c);
						if (other != null && !other.equals(f) && !isCalled(other)) {
							out.printf("  switch: removed bogus function %s (case of %s)%n",
								other.getName(), f.getName());
							removeFunction(other);
						}
						if (getInstructionAt(c) == null) {
							disassemble(c);
						}
					}
				}
				CreateFunctionCmd.fixupFunctionBody(currentProgram, f, monitor);
				out.printf("  switch: %s %d tables, %d new case refs, body now %d bytes (%ds)%n",
					f.getName(), hf.getJumpTables().length, added - before,
					f.getBody().getNumAddresses(), (System.currentTimeMillis() - t0) / 1000);
				out.flush();
			}
		}
		finally {
			ifc.dispose();
		}
		return added;
	}

	private boolean hasComputedJumpRefs(Instruction i) {
		for (Reference r : i.getReferencesFrom()) {
			if (r.getReferenceType().isComputed() && r.getReferenceType().isJump()) {
				return true;
			}
		}
		return false;
	}

	private boolean isCalled(Function f) {
		for (Reference r : getReferencesTo(f.getEntryPoint())) {
			if (r.getReferenceType().isCall() || r.getReferenceType().isData()) {
				return true;
			}
		}
		return false;
	}

	/** Creates functions at orphan runs that begin after a return, tail call or
	 *  exception return, or that begin with a stack-frame prologue. */
	private int createOrphanFunctions() throws Exception {
		int created = 0;
		for (AddressRange r : orphanRuns()) {
			Address start = r.getMinAddress();
			Instruction first = getInstructionAt(start);
			if (first == null) {
				continue;
			}
			// step over nop padding
			while (first != null && first.getMnemonicString().equals("nop") &&
				first.getMaxAddress().compareTo(r.getMaxAddress()) < 0) {
				first = getInstructionAfter(first.getAddress());
			}
			if (first == null || first.getMnemonicString().equals("nop")) {
				continue;
			}
			start = first.getAddress();
			boolean prologue = first.toString().startsWith("addiu sp,sp,-");
			if (!prologue && !followsFunctionEnd(start) && !isPointedTo(start)) {
				continue;
			}
			if (getFunctionContaining(start) == null && createFunction(start, null) != null) {
				created++;
			}
		}
		return created;
	}

	/** Referenced from a pointer outside .text (a function-pointer table). */
	private boolean isPointedTo(Address start) {
		for (Reference r : getReferencesTo(start)) {
			if (r.getReferenceType().isData() && !textSet().contains(r.getFromAddress())) {
				return true;
			}
		}
		return false;
	}

	private boolean followsFunctionEnd(Address start) {
		Instruction slot = getInstructionBefore(start);
		while (slot != null && slot.getMnemonicString().equals("nop") &&
			getFunctionContaining(slot.getAddress()) == null) {
			slot = getInstructionBefore(slot.getAddress());
		}
		if (slot == null) {
			return true;
		}
		if (slot.getMnemonicString().equals("eret")) {
			return true;
		}
		Instruction branch = getInstructionBefore(slot.getAddress());
		if (branch == null) {
			return false;
		}
		String b = branch.toString();
		if (b.equals("jr ra") || branch.getMnemonicString().equals("eret")) {
			return true;
		}
		if (branch.getMnemonicString().equals("j")) {
			// tail call: unconditional jump out of the function it ends
			Function owner = getFunctionContaining(branch.getAddress());
			Address target = branch.getAddress(0);
			return target != null && (owner == null || !owner.getBody().contains(target));
		}
		return false;
	}
}
