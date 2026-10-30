"""build_site.py: fills template.html with the numbers of ../report/report.json and writes index.html (local only)."""
import json, datetime, os
here = os.path.dirname(os.path.abspath(__file__))
m = json.load(open(os.path.join(here, "..", "report", "report.json")))["measures"]
t = open(os.path.join(here, "template.html")).read()
code_pct = float(m["matched_code_percent"]); fn_pct = float(m["matched_functions_percent"])
vals = {
    "DATE": datetime.date.today().isoformat(),
    "CODE_PCT": f"{code_pct:.2f}", "CODE_PCT_W": f"{code_pct:.2f}",
    "CODE_MATCHED": f"{int(m['matched_code']):,}", "CODE_TOTAL": f"{int(m['total_code']):,}",
    "FN_MATCHED": f"{int(m['matched_functions']):,}", "FN_TOTAL": f"{int(m['total_functions']):,}",
    "FN_PCT": f"{fn_pct:.1f}", "FN_PCT_W": f"{fn_pct:.1f}",
}

import re, glob
def match_counts():
    """Matched functions by origin, counted from the // MATCH markers in src/ (CI has the checkout)."""
    root = os.path.join(here, "..", "src")
    c = {"hand": 0, "gen": 0, "ghidra": 0}
    for path in glob.glob(os.path.join(root, "**", "*.c"), recursive=True):
        rel = os.path.relpath(path, root).replace(os.sep, "/")
        n = len(set(re.findall(r"MATCH\s+func_([0-9A-Fa-f]{8})", open(path).read())))
        if rel.startswith("ghidra/"): c["ghidra"] += n
        elif rel.startswith("gen"): c["gen"] += n
        else: c["hand"] += n
    return c
mc = match_counts()
tot = sum(mc.values()) or 1
for i, k in enumerate(("hand", "gen", "ghidra")):
    vals[f"K{i}_N"] = f"{mc[k]:,}"; vals[f"K{i}_W"] = f"{100*mc[k]/tot:.2f}"
units = []
for u in json.load(open(os.path.join(here, "..", "report", "report.json")))["units"]:
    um = u["measures"]
    units.append({"name": u["name"], "fn": int(um.get("total_functions", 0)), "mfn": int(um.get("matched_functions", 0)),
                  "total": int(um.get("total_code", 0)), "bytes": int(um.get("matched_code", 0)), "pct": round(float(um.get("matched_code_percent", 0)), 3)})
units = [u for u in units if u["total"] > 0]
touched = sum(1 for u in units if u["mfn"] > 0)
vals["UNITS_JSON"] = json.dumps(units, separators=(",", ":"))
vals["UNITS_TOUCHED"] = str(touched); vals["UNITS_TOTAL"] = str(len(units)); vals["UNITS_W"] = f"{100*touched/len(units):.1f}"
import base64
vals["LANG"] = "data:image/png;base64," + base64.b64encode(open(os.path.join(here, "assets", "lang.png"), "rb").read()).decode()
for k, v in vals.items():
    t = t.replace("{{" + k + "}}", v)
assert "{{" not in t
open(os.path.join(here, "index.html"), "w").write(t)
print("wrote site/index.html")
