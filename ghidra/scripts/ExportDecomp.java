// Headless post-script: decompiles every function (in parallel, long timeout)
// and writes
//   <out>/legaia2.h            data types and function prototypes
//   <out>/legaia2.c            every function in address order
//   <out>/src/<group>/<fn>.c   one file per function, grouped by source file
//   <out>/functions.csv        index of every function
// Functions without a known source file are grouped by the source file that
// precedes them in memory ("_unknown_after_<file>").
// Usage: -postScript ExportDecomp.java <output_dir>
//@category Export

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

import ghidra.app.decompiler.*;
import ghidra.app.decompiler.parallel.*;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.DataTypeWriter;
import ghidra.program.model.listing.*;
import ghidra.util.task.TaskMonitor;

public class ExportDecomp extends GhidraScript {

	private static final int TIMEOUT_SECS = 900;

	private record Result(Function func, String signature, String c, String error) {}

	@Override
	protected void run() throws Exception {
		String[] args = getScriptArgs();
		File outDir = new File(args.length > 0 ? args[0] : "decomp");
		File srcDir = new File(outDir, "src");
		deleteTree(srcDir);
		srcDir.mkdirs();

		List<Function> funcs = new ArrayList<>();
		currentProgram.getFunctionManager().getFunctions(true).forEach(funcs::add);
		println("Decompiling " + funcs.size() + " functions...");

		DecompilerCallback<Result> cb = new DecompilerCallback<>(currentProgram, ifc -> {
			DecompileOptions opts = new DecompileOptions();
			opts.setDefaultTimeout(TIMEOUT_SECS);
			opts.setMaxPayloadMBytes(1024);
			ifc.setOptions(opts);
			ifc.toggleCCode(true);
			ifc.toggleSyntaxTree(true);
			ifc.setSimplificationStyle("decompile");
		}) {
			@Override
			public Result process(DecompileResults res, TaskMonitor m) {
				Function f = res.getFunction();
				DecompiledFunction df = res.getDecompiledFunction();
				if (df == null) {
					String err = res.getErrorMessage() == null ? "unknown error"
							: res.getErrorMessage().trim();
					return new Result(f, null, null, err);
				}
				return new Result(f, df.getSignature(), df.getC(), null);
			}
		};
		cb.setTimeout(TIMEOUT_SECS);
		List<Result> results;
		try {
			results = ParallelDecompiler.decompileFunctions(cb, funcs, monitor);
		}
		finally {
			cb.dispose();
		}
		results.sort(Comparator.comparing(r -> r.func().getEntryPoint()));

		writeHeader(new File(outDir, "legaia2.h"), results);

		int failed = 0;
		String lastGroup = "_unknown_start";
		Set<String> usedNames = new HashSet<>();
		try (Writer all = writer(new File(outDir, "legaia2.c"));
				PrintWriter csv = new PrintWriter(writer(new File(outDir, "functions.csv")))) {
			all.write("#include \"legaia2.h\"\n\n");
			csv.println("address,name,size_bytes,source_file,attribution,group,decompiled");
			for (Result r : results) {
				Function f = r.func();
				String src = sourceFile(f);
				String attribution = f.getTags().stream().anyMatch(t -> t.getName().equals("src-direct"))
						? "direct"
						: src != null ? "inferred" : "none";
				String group;
				if (src != null) {
					group = stem(src);
					lastGroup = "_unknown_after_" + group;
				}
				else {
					group = lastGroup;
				}

				String body = r.c() != null ? r.c().trim() + "\n"
						: "/* Decompilation failed: " + r.error().replace("*/", "* /") + " */\n";
				if (r.c() == null) {
					failed++;
				}
				String header = banner(f, src, attribution);
				all.write(header + body + "\n\n");

				String fileName = f.getName().contains(f.getEntryPoint().toString()) ? f.getName()
						: f.getName() + "_" + f.getEntryPoint();
				fileName = fileName.replaceAll("[^A-Za-z0-9_.@-]", "_");
				if (!usedNames.add(group + "/" + fileName)) {
					fileName += "_" + f.getEntryPoint();
				}
				File dir = new File(srcDir, group);
				dir.mkdirs();
				try (Writer w = writer(new File(dir, fileName + ".c"))) {
					w.write(header + "#include \"../../legaia2.h\"\n\n" + body);
				}

				csv.printf("%s,%s,%d,%s,%s,%s,%s%n", f.getEntryPoint(), f.getName(),
					f.getBody().getNumAddresses(), src == null ? "" : src, attribution, group,
					r.c() != null ? "ok" : "failed");
			}
		}
		println("Wrote " + results.size() + " functions (" + failed + " failed) to " +
			outDir.getAbsolutePath());
	}

	private static String sourceFile(Function f) {
		return f.getTags().stream()
				.map(t -> t.getName())
				.filter(n -> n.startsWith("src:"))
				.map(n -> n.substring(4))
				.findFirst()
				.orElse(null);
	}

	private static String stem(String src) {
		return src.replaceAll("^.*/", "").replaceAll("\\.[a-z]+$", "");
	}

	private static String banner(Function f, String src, String attribution) {
		StringBuilder sb = new StringBuilder();
		sb.append("/*\n * ").append(f.getName()).append(" @ 0x").append(f.getEntryPoint())
				.append(", ").append(f.getBody().getNumAddresses()).append(" bytes\n");
		if (src != null) {
			sb.append(" * Source: ").append(src).append(" (").append(attribution).append(")\n");
		}
		String c = f.getComment();
		if (c != null) {
			for (String line : c.split("\n")) {
				if (!line.startsWith("Source: ")) {
					sb.append(" * ").append(line.replace("*/", "* /")).append("\n");
				}
			}
		}
		return sb.append(" */\n").toString();
	}

	private void writeHeader(File file, List<Result> results) throws Exception {
		try (Writer w = writer(file)) {
			w.write("#ifndef LEGAIA2_H\n#define LEGAIA2_H\n\n");
			new DataTypeWriter(currentProgram.getDataTypeManager(), w)
					.write(currentProgram.getDataTypeManager(), monitor);
			w.write("\n/* Function prototypes */\n\n");
			for (Result r : results) {
				if (r.signature() != null) {
					w.write(r.signature().trim() + "\n");
				}
			}
			w.write("\n#endif\n");
		}
	}

	private static Writer writer(File f) throws IOException {
		return new BufferedWriter(new OutputStreamWriter(new FileOutputStream(f),
			StandardCharsets.UTF_8));
	}

	private static void deleteTree(File f) {
		File[] kids = f.listFiles();
		if (kids != null) {
			for (File k : kids) {
				deleteTree(k);
			}
		}
		f.delete();
	}
}
