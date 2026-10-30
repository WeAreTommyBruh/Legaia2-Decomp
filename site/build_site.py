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

import html, subprocess
full = json.load(open(os.path.join(here, "..", "report", "report.json")))
fz = float(m.get("fuzzy_match_percent", 0))
vals["FUZZY_PCT"] = f"{fz:.2f}"
td, md = int(m.get("total_data", 0)), int(m.get("matched_data", 0))
dp = 100 * md / td if td else 0
vals["DATA_PCT"] = "<0.01" if 0 < dp < 0.01 else f"{dp:.2f}"
vals["DATA_PCT_NUM"] = f"{dp:.4f}"; vals["DATA_W"] = f"{max(dp, 0.4):.2f}"
vals["DATA_DONE"] = f"{md:,}"; vals["DATA_TODO"] = f"{td - md:,}"; vals["DATA_TOTAL"] = f"{td:,}"
cats = []
for c in full.get("categories", []):
    cm = c["measures"]; p = float(cm.get("matched_code_percent", 0))
    cats.append(f'<div class="cat"><div class="top"><span>{html.escape(c["name"])}</span><span class="pct">{p:.2f}%</span></div>'
                f'<div class="bar" role="progressbar" aria-valuenow="{p:.2f}" aria-valuemin="0" aria-valuemax="100" aria-label="{html.escape(c["name"])}"><i style="width:{p:.2f}%"></i></div>'
                f'<div class="label">{int(cm.get("matched_functions", 0)):,} of {int(cm.get("total_functions", 0)):,} functions, '
                f'{int(cm.get("matched_code", 0)):,} of {int(cm.get("total_code", 0)):,} bytes</div></div>')
vals["CATS_HTML"] = "".join(cats); vals["CAT_COUNT"] = str(len(cats))
def commits(n=6):
    try:
        out = subprocess.run(["git", "-C", os.path.join(here, ".."), "log", f"-n{n}", "--format=%H%x1f%cs%x1f%s"], capture_output=True, text=True, check=True).stdout
    except Exception:
        return '<li><span class="m">History is not available in this build.</span></li>'
    rows = []
    for line in out.strip().split("\n"):
        h, d, subj = line.split("\x1f", 2)
        rows.append(f'<li><a class="h" href="https://github.com/WeAreTommyBruh/Legaia2-Decomp/commit/{h}">{h[:7]}</a>'
                    f'<span class="m">{html.escape(subj)}</span><span class="d">{d}</span></li>')
    return "".join(rows)
vals["COMMITS_HTML"] = commits()
def badge(k, v, cls=""):
    return f'<li class="badge {cls}"><span class="k">{k}</span><span class="v">{v}</span></li>'
vals["BADGES_HTML"] = "".join([
    badge("CODE", f'{code_pct:.2f}%'), badge("FUNCTIONS", f'{fn_pct:.1f}%'),
    badge("FUZZY", f'{fz:.2f}%', "blue"), badge("DATA", f'{vals["DATA_PCT"]}%', "blue"),
    badge("UNITS", f'{touched} / {len(units)}', "blue")])
for k, v in vals.items():
    t = t.replace("{{" + k + "}}", v)
assert "{{" not in t
open(os.path.join(here, "index.html"), "w").write(t)
print("wrote site/index.html")
