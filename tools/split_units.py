"""split_units.py: split src/small_hand*.c and src/tiny_hand*.c into src/units/<unit>[_variant].c (one file per report unit)."""
import re,glob,csv,os,collections,sys
ROOT="/home/tommy/src/Legaia 2 Decomp"
os.chdir(ROOT)
rows={int(r['address'],16):r for r in csv.DictReader(open("decomp/functions.csv"))}
def unit_name(g): return re.sub(r"[^A-Za-z0-9_]","_",g or "none")
files=sorted(glob.glob("src/small_hand*.c"))
os.makedirs("src/units",exist_ok=True)
out=collections.OrderedDict(); tdefs={}   # path -> (header, [blocks])
for p in files:
    stem=os.path.splitext(os.path.basename(p))[0]
    var=stem.replace("small_hand","").replace("tiny_hand","t")
    t=open(p).read()
    for m in re.finditer(r"^typedef [^\n;{]*?\b(\w+)(\[\d+\])?( __attribute__\(\(.*?\)\))?;[ \t]*$",t,re.M): tdefs.setdefault(m.group(1),m.group(0))
    blocks=re.split(r"\n[ \t]*\n",t)
    # header = lines up to and including the include of common.h in the first block
    first=blocks[0].split("\n")
    k=next(i for i,l in enumerate(first) if l.startswith("#include"))
    header="\n".join(first[:k+1])+"\n"
    rest=["\n".join(first[k+1:])]+blocks[1:]
    pend=[]; last=None
    for b in rest:
        if not b.strip(): continue
        ms=re.findall(r"//\s*MATCH\s+func_([0-9A-Fa-f]{8})",b)
        if not ms:
            if last is not None and (b[0] in " \t}{" or not out[last][1][-1].rstrip().endswith((";","}")) or out[last][1][-1].count("{")>out[last][1][-1].count("}")):
                out[last][1][-1]+="\n\n"+b
            else:
                pend.append(b)
            continue
        a=int(ms[0],16)
        u=unit_name(rows[a]['group'])
        path=f"src/units/{u}{var}.c"
        out.setdefault(path,(header,[]))[1].append("\n\n".join(pend+[b])); pend=[]; last=path
    if pend:
        if last is None: raise SystemExit("dangling in "+p)
        out[last][1][-1]+="\n\n"+"\n\n".join(pend)
for path,(h,bl) in out.items():
    txt="\n\n".join(bl)
    if os.path.exists(path):  # later runs append to an existing unit file
        old=open(path).read()
        add=[line for n,line in tdefs.items() if re.search(r"\b"+n+r"\b",txt) and not re.search(r"typedef[^\n]*\b"+n+r"\b",old+txt)]
        open(path,"w").write(old.rstrip("\n")+"\n\n"+("\n".join(add)+"\n" if add else "")+txt+"\n")
        continue
    add=[line for n,line in tdefs.items() if re.search(r"\b"+n+r"\b",txt) and not re.search(r"typedef[^\n]*\b"+n+r"\b",txt)]
    if add: h=h+"\n".join(add)+"\n"
    open(path,"w").write(h.replace('/* Small functions matched by hand. */','/* Functions of this report unit, matched by hand. */',1).replace('#include "common.h"','#include "../common.h"')+"\n"+txt+"\n")
for p in files: os.remove(p)
print(len(out),"files")
