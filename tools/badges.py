#!/usr/bin/env python3
"""Writes the README badges (badges/*.svg) from report/report.json, in the style of the website's badges
(dark brown label, gold or blue value). tools/report.py runs this after writing the report.

Usage: badges.py [REPORT.json]"""
import json, os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, "badges")
INK, BROWN1, BROWN2 = "#2A130B", "#2A130B", "#372B1D"


def svg(label, value, blue):
    lw = round(14 + len(label) * 8.2)
    vw = round(14 + len(value) * 7.4)
    w, h = lw + vw, 24
    v1, v2, vt = ("#3C8FCD", "#2E4C88", "#FFFFFF") if blue else ("#F2C40E", "#EDB202", INK)
    return f'''<svg xmlns="http://www.w3.org/2000/svg" width="{w}" height="{h}" viewBox="0 0 {w} {h}" role="img" aria-label="{label}: {value}">
<title>{label}: {value}</title>
<defs>
<linearGradient id="l" x1="0" y1="0" x2="0" y2="1"><stop offset="0" stop-color="{BROWN2}"/><stop offset="1" stop-color="{BROWN1}"/></linearGradient>
<linearGradient id="v" x1="0" y1="0" x2="0" y2="1"><stop offset="0" stop-color="{v1}"/><stop offset="1" stop-color="{v2}"/></linearGradient>
<clipPath id="r"><rect x="0.5" y="0.5" width="{w - 1}" height="{h - 1}" rx="5"/></clipPath>
</defs>
<g clip-path="url(#r)">
<rect width="{lw}" height="{h}" fill="url(#l)"/>
<rect x="{lw}" width="{vw}" height="{h}" fill="url(#v)"/>
</g>
<rect x="0.5" y="0.5" width="{w - 1}" height="{h - 1}" rx="5" fill="none" stroke="{BROWN1}"/>
<g font-family="Georgia,'Times New Roman',serif" font-size="11" letter-spacing="0.7" fill="#FFFFFF" text-anchor="middle">
<text x="{lw / 2}" y="16">{label}</text>
</g>
<g font-family="Verdana,'DejaVu Sans',sans-serif" font-size="12" font-weight="bold" fill="{vt}" text-anchor="middle">
<text x="{lw + vw / 2}" y="16">{value}</text>
</g>
</svg>
'''


def main(argv):
    path = argv[1] if len(argv) > 1 else os.path.join(ROOT, "report", "report.json")
    rep = json.load(open(path))
    m = rep["measures"]
    td, md = int(m.get("total_data", 0)), int(m.get("matched_data", 0))
    dp = 100 * md / td if td else 0
    touched = sum(1 for u in rep["units"] if int(u["measures"].get("matched_functions", 0)) > 0)
    total = sum(1 for u in rep["units"] if int(u["measures"].get("total_code", 0)) > 0)
    items = [
        ("code", "CODE", f'{float(m["matched_code_percent"]):.2f}%', False),
        ("functions", "FUNCTIONS", f'{float(m["matched_functions_percent"]):.1f}%', False),
        ("fuzzy", "FUZZY", f'{float(m["fuzzy_match_percent"]):.2f}%', True),
        ("data", "DATA", ("<0.01" if 0 < dp < 0.01 else f"{dp:.2f}") + "%", True),
        ("units", "UNITS", f"{touched} / {total}", True),
    ]
    os.makedirs(OUT, exist_ok=True)
    for name, label, value, blue in items:
        text = svg(label, value.replace("<", "&lt;"), blue)
        with open(os.path.join(OUT, name + ".svg"), "w") as f:
            f.write(text)
    print("wrote badges/*.svg: " + ", ".join(f"{l} {v}" for _, l, v, _ in items))


if __name__ == "__main__":
    main(sys.argv)
