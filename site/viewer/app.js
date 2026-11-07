// app.js: the asset viewer page. Reads the disc through legaia.js; everything stays in the browser.
(function () {
"use strict";
const L = window.Legaia;
const $ = id => document.getElementById(id);
const ROW = 30;

const state = { disc: null, files: [], tab: "all", query: "", list: [], sel: -1, asset: null, token: 0, skelCache: new Map() };

// ---------------------------------------------------------------- small helpers

function fmtSize(n) {
  if (n < 1024) return n + " B";
  if (n < 1048576) return (n / 1024).toFixed(1) + " KB";
  if (n < 1073741824) return (n / 1048576).toFixed(1) + " MB";
  return (n / 1073741824).toFixed(2) + " GB";
}
function esc(s) { return String(s).replace(/[&<>"]/g, c => ({ "&": "&amp;", "<": "&lt;", ">": "&gt;", '"': "&quot;" }[c])); }
function setStatus(text, isErr) { const s = $("status"); s.textContent = text; s.classList.toggle("err", !!isErr); }
function baseName(p) { return p.slice(p.lastIndexOf("/") + 1); }
function stripExt(p) { return p.replace(/\.[^./]+$/, ""); }
function safeParts(path) {
  return path.split(/[\\/]/).filter(p => p && p !== "." && p !== "..").map(p => p.replace(/[<>:"|?*\x00-\x1f]/g, "_"));
}

function download(name, bytes, type) {
  const url = URL.createObjectURL(new Blob([bytes], { type: type || "application/octet-stream" }));
  const a = document.createElement("a");
  a.href = url; a.download = name;
  document.body.appendChild(a); a.click(); a.remove();
  setTimeout(() => URL.revokeObjectURL(url), 10000);
}

// Store-only ZIP for small bundles (a few PNGs, the members of one archive)
function makeZip(entries) {
  const enc = new TextEncoder(), chunks = [], central = [];
  let offset = 0;
  for (const e of entries) {
    const name = enc.encode(e.name), crc = L.crc32(e.data), size = e.data.length;
    const lh = new Uint8Array(30 + name.length), dv = new DataView(lh.buffer);
    dv.setUint32(0, 0x04034b50, true); dv.setUint16(4, 20, true); dv.setUint16(6, 0x0800, true);
    dv.setUint32(14, crc, true); dv.setUint32(18, size, true); dv.setUint32(22, size, true); dv.setUint16(26, name.length, true);
    lh.set(name, 30);
    chunks.push(lh, e.data);
    const ch = new Uint8Array(46 + name.length), cv = new DataView(ch.buffer);
    cv.setUint32(0, 0x02014b50, true); cv.setUint16(4, 20, true); cv.setUint16(6, 20, true); cv.setUint16(8, 0x0800, true);
    cv.setUint32(16, crc, true); cv.setUint32(20, size, true); cv.setUint32(24, size, true); cv.setUint16(28, name.length, true);
    cv.setUint32(42, offset, true);
    ch.set(name, 46);
    central.push(ch);
    offset += lh.length + size;
  }
  const cdSize = central.reduce((a, c) => a + c.length, 0);
  const end = new Uint8Array(22), ev = new DataView(end.buffer);
  ev.setUint32(0, 0x06054b50, true); ev.setUint16(8, entries.length, true); ev.setUint16(10, entries.length, true);
  ev.setUint32(12, cdSize, true); ev.setUint32(16, offset, true);
  return new Blob([...chunks, ...central, end], { type: "application/zip" });
}

function hexDump(d, max) {
  const n = Math.min(d.length, max), lines = [];
  for (let o = 0; o < n; o += 16) {
    let hx = "", as = "";
    for (let i = 0; i < 16; i++) {
      if (o + i < n) { const b = d[o + i]; hx += b.toString(16).padStart(2, "0") + " "; as += b >= 32 && b < 127 ? String.fromCharCode(b) : "."; }
      else hx += "   ";
    }
    lines.push(o.toString(16).padStart(8, "0") + "  " + hx + " " + as);
  }
  return lines.join("\n") + (d.length > n ? "\n... " + (d.length - n) + " more bytes" : "");
}

// ---------------------------------------------------------------- views

const views = { gl: $("vGl"), tex: $("vTex"), list: $("vList"), audio: $("vAudio"), hex: $("vHex"), fx: $("vFx") };
function showView(name, msg) {
  for (const k in views) views[k].classList.toggle("on", k === name);
  $("msg").style.display = name ? "none" : "";
  if (!name) { $("msgTitle").textContent = (msg && msg.title) || "NO ASSET SELECTED"; $("msgText").textContent = (msg && msg.text) || ""; }
  if (name !== "audio") stopAudio();
  if (name !== "gl") stopAnim();
  if (name !== "fx") stopFx();
}
function setMeta(rows) {
  $("meta").innerHTML = rows.map(([k, v]) => "<dt>" + esc(k) + "</dt><dd>" + esc(v) + "</dd>").join("");
}
function setToolbar(nodes) { const t = $("toolbar"); t.replaceChildren(...nodes); }
function btn(label, fn, cls) { const b = document.createElement("button"); b.className = "btn" + (cls ? " " + cls : ""); b.textContent = label; b.onclick = fn; return b; }
function setSave(asset) {
  state.asset = asset;
  $("saveRaw").disabled = !asset || !asset.raw;
  $("saveConv").disabled = !asset || !asset.converted;
  $("saveConv").textContent = asset && asset.convLabel ? asset.convLabel : "Save converted";
  $("modelOpts").hidden = !(asset && asset.model);
}

// ---------------------------------------------------------------- file list (virtual)

const filesEl = $("files");
const tabMatch = {
  all: () => true,
  model: f => f.kind === "model",
  texture: f => f.ext === "tms" || (f.ext === "dat" && f.kind !== "model") || f.ext === "pac",
  audio: f => f.kind === "audio",
  motion: f => f.kind === "motion",
  effect: f => f.kind === "effect",
  archive: f => f.ext === "lzs" || f.ext === "pac",
};

function currentFilter() {
  const q = state.query.trim().toLowerCase(), m = tabMatch[state.tab];
  return state.files.filter(f => m(f) && (!q || f.lower.includes(q)));
}
function refilter(keepPath) {
  state.list = currentFilter();
  state.sel = keepPath ? state.list.findIndex(f => f.path === keepPath) : -1;
  $("count").textContent = state.list.length.toLocaleString() + " of " + state.files.length.toLocaleString() + " files";
  renderList(true);
}
function renderList(reset) {
  const n = state.list.length;
  if (!n) { filesEl.innerHTML = '<div class="empty">' + (state.files.length ? "No files match." : "No disc loaded.") + "</div>"; return; }
  let pad = filesEl.querySelector(".pad");
  if (!pad || reset) { filesEl.innerHTML = '<div class="pad"></div>'; pad = filesEl.querySelector(".pad"); if (reset) filesEl.scrollTop = 0; }
  pad.style.height = n * ROW + "px";
  const top = filesEl.scrollTop, h = filesEl.clientHeight;
  const a = Math.max(0, Math.floor(top / ROW) - 6), b = Math.min(n, Math.ceil((top + h) / ROW) + 6);
  let html = "";
  for (let i = a; i < b; i++) {
    const f = state.list[i], slash = f.path.lastIndexOf("/");
    html += '<div class="row" role="option" data-i="' + i + '" aria-selected="' + (i === state.sel) + '" style="top:' + i * ROW + 'px" title="' + esc(f.path) + '">'
      + '<span class="n"><i>' + esc(f.path.slice(0, slash + 1)) + "</i>" + esc(f.path.slice(slash + 1)) + '</span><span class="s">' + fmtSize(f.bytes) + "</span></div>";
  }
  pad.innerHTML = html;
}
filesEl.addEventListener("scroll", () => renderList(false));
filesEl.addEventListener("click", e => { const r = e.target.closest(".row"); if (r) select(+r.dataset.i); });
filesEl.addEventListener("keydown", e => {
  const keys = { ArrowDown: 1, ArrowUp: -1, PageDown: 12, PageUp: -12 };
  if (!state.list.length) return;
  let i = state.sel;
  if (e.key in keys) i = Math.max(0, Math.min(state.list.length - 1, (i < 0 ? 0 : i + keys[e.key])));
  else if (e.key === "Home") i = 0; else if (e.key === "End") i = state.list.length - 1; else return;
  e.preventDefault(); select(i);
});
function select(i) {
  state.sel = i;
  const top = filesEl.scrollTop, h = filesEl.clientHeight;
  if (i * ROW < top) filesEl.scrollTop = i * ROW; else if ((i + 1) * ROW > top + h) filesEl.scrollTop = (i + 1) * ROW - h;
  renderList(false);
  openEntry(state.list[i]);
}

$("tabs").addEventListener("click", e => {
  const b = e.target.closest("button[data-tab]");
  if (!b || !state.disc) return;
  const keep = state.list[state.sel] && state.list[state.sel].path;
  state.tab = b.dataset.tab;
  for (const x of $("tabs").querySelectorAll("button")) { const on = x === b; x.classList.toggle("selected", on); x.setAttribute("aria-selected", on); }
  refilter(keep);
});
$("search").addEventListener("input", e => { state.query = e.target.value; refilter(state.list[state.sel] && state.list[state.sel].path); });

// ---------------------------------------------------------------- opening a file

// Reads only what a preview needs: whole file for types we decode, the first sectors otherwise.
const WHOLE = new Set(["tmd", "tms", "dat", "pac", "lzs", "int", "mov", "moz", "efp", "efb"]);

async function openEntry(entry) {
  const token = ++state.token;
  setSave(null); setToolbar([]);
  showView(null, { title: "LOADING", text: entry.path });
  try {
    const whole = WHOLE.has(entry.ext) || entry.kind === "model";
    const data = whole ? await state.disc.readFile(entry) : await state.disc.readHead(entry, 4096);
    if (token !== state.token) return;
    const raw = () => state.disc.readFile(entry);
    // The .tms of a model: its own, else one of the same family in the folder (mon011e.tmd shares mon011.tms; mon41.tmd's is
    // mon041.tms, the zero left out of its name).
    const findTextures = async name => {
      const dir = name.slice(0, name.lastIndexOf("/") + 1), stem = stripExt(baseName(name));
      const norm = x => x.toLowerCase().replace(/(^|[^0-9])0+(?=[0-9])/g, "$1");
      let sib = state.byPath.get(dir + stem + ".tms");
      if (!sib) {
        const fam = state.files.filter(f => f.ext === "tms" && f.path.startsWith(dir) && f.path.indexOf("/", dir.length) < 0).map(f => ({ f, b: stripExt(baseName(f.path)) }))
          .filter(x => norm(x.b) === norm(stem) || stem.startsWith(x.b)).sort((a, b) => b.b.length - a.b.length);
        sib = fam.length ? fam[0].f : null;
      }
      if (!sib) return null;
      const sets = L.findTextureSets(await state.disc.readFile(sib), false);
      return sets.length ? sets[0].textures : null;
    };
    // Clips for a model: its own .mov/.moz (same name) when they fit, else a family file next to it
    // (ply03a.tmd uses ply03.mov, mon012a.tmd uses mon012.mov, ...). A fit means the clips' bone-slot map has the
    // model's slot count.
    const readClips = async f => {
      let d = await state.disc.readFile(f);
      if (f.ext === "moz") d = L.lzsDecompress(d).data;   // the same clips, compressed
      return L.parseMotions(d);
    };
    const findMotions = async (name, models) => {
      const dir = name.slice(0, name.lastIndexOf("/") + 1), stem = stripExt(baseName(name));
      const fits = clips => !(models || []).length ? 2 : Math.max(0, ...clips.filter(Boolean).map(c => Math.max(...models.map(m => L.slotsFit(m, c)))));
      const common = b => { let n = 0; while (n < b.length && n < stem.length && b[n] === stem[n]) n++; return n; };
      const cands = state.files.filter(f => (f.ext === "mov" || f.ext === "moz") && f.path.startsWith(dir) && f.path.indexOf("/", dir.length) < 0)
        .map(f => ({ f, b: stripExt(baseName(f.path)) }))
        .filter(x => x.b === stem || x.b.startsWith(stem) || stem.startsWith(x.b))   // a wider rule would pair unrelated monsters that happen to have the same slot count
        .sort((a, b) => (b.b === stem) - (a.b === stem) || common(b.b) - common(a.b) || a.b.length - b.b.length);
      let loose = null;   // a file with a few parts more or fewer than the model (see slotsFit) is the second choice
      for (const { f } of cands.slice(0, 8)) {
        try { const clips = await readClips(f), fit = fits(clips); if (fit === 2) return clips; if (fit && !loose) loose = clips; } catch (e) { /* try the next one */ }
      }
      if (loose) return loose;
      // No file of the model's own family fits: take the file in the folder whose bones are named like the model's parts
      // (mon013 -> mon012.mov, ply06a -> ply00.mov, mon41 -> mon041.mov), the slot counts agreeing.
      if (!(models || []).length) return null;
      const tried = new Set(cands.slice(0, 8).map(x => x.f.path));
      let best = null;
      for (const f of state.files) {
        if (!(f.ext === "mov" || f.ext === "moz") || !f.path.startsWith(dir) || f.path.indexOf("/", dir.length) >= 0 || tried.has(f.path)) continue;
        let clip = state.skelCache.get(f.path);
        if (clip === undefined) {
          try { let d = await state.disc.readFile(f); if (f.ext === "moz") d = L.lzsDecompress(d).data; clip = L.firstClip(d); } catch (e) { clip = null; }
          state.skelCache.set(f.path, clip);
        }
        if (!clip) continue;
        for (const m of models) {
          const fit = L.slotsFit(m, clip), aff = L.nameAffinity(m, clip);
          if (fit && aff >= 0.7 && (!best || (aff > best.aff || aff === best.aff && fit > best.fit))) best = { f, aff, fit };
        }
      }
      return best ? readClips(best.f) : null;
    };
    // the model a motion file drives: same name, else a model next to it with that name as a prefix (or the reverse) and the right slot count
    const findModelFor = async (name, clips) => {
      const dir = name.slice(0, name.lastIndexOf("/") + 1), stem = stripExt(baseName(name));
      const clip = clips.find(Boolean);
      const cands = [dir + stem + ".tmd"];
      for (const f of state.files) if (f.ext === "tmd" && f.path.startsWith(dir) && f.path !== cands[0]) {
        const s2 = stripExt(baseName(f.path));
        if (s2.startsWith(stem) || stem.startsWith(s2)) cands.push(f.path);
      }
      let loose = null;
      for (const p of cands.slice(0, 8)) {
        const f = state.byPath.get(p);
        if (!f) continue;
        try {
          const models = L.parseModels(await state.disc.readFile(f)), fit = Math.max(...models.map(m => L.slotsFit(m, clip)));
          if (fit === 2) return { name: p, models, textures: await findTextures(p) };
          if (fit && !loose) loose = { name: p, models, textures: await findTextures(p) };
        } catch (e) { /* not a match */ }
      }
      return loose;
    };
    await showData(entry.path, data, { entry, raw, whole, token, findTextures, findMotions, findModelFor, base: [["Name", baseName(entry.path)], ["Folder", entry.path.slice(0, entry.path.lastIndexOf("/")) || "/"], ["Size", fmtSize(entry.bytes)]] });
  } catch (err) {
    if (token !== state.token) return;
    console.error(err);
    showView(null, { title: "CANNOT SHOW THIS FILE", text: err.message });
    setMeta([["Name", baseName(entry.path)], ["Error", err.message]]);
    setSave({ raw: () => state.disc.readFile(entry), name: baseName(entry.path) });
  }
}

// Decides how to show `data` by name and content. ctx.base: meta rows; ctx.raw: loader for the original bytes.
async function showData(name, data, ctx) {
  const ext = L.extOf(name), isModel = ext === "tmd" || /tmd\.dat$/i.test(name);
  const stem = stripExt(baseName(name));
  const rawAsset = ctx.raw ? { raw: ctx.raw, name: baseName(name) } : {};
  if (isModel) {
    const ms = L.parseModels(data);
    let textures = null;
    try { textures = ctx.findTextures ? await ctx.findTextures(name) : null; } catch (e) { console.warn("no textures for " + name, e); }
    let motions = null;
    try { motions = ctx.findMotions ? await ctx.findMotions(name, ms) : null; } catch (e) { console.warn("no motions for " + name, e); }
    if (ctx.token !== undefined && ctx.token !== state.token) return;
    showModel(name, ms, ctx, rawAsset, textures, motions, true);
    return;
  }
  if (ext === "int") { await showAudio(name, data, ctx, rawAsset); return; }
  if (ext === "efp") { showEffectPack(name, data, ctx, rawAsset); return; }
  if (ext === "efb") { showEffect(name, data, ctx, rawAsset, null); return; }
  if (ext === "mov" || ext === "moz") { await showMotion(name, ext === "moz" ? L.lzsDecompress(data).data : data, ctx, rawAsset); return; }
  if (ext === "lzs") { await showLzs(name, data, ctx, rawAsset); return; }
  if (ext === "pac") { showPac(name, data, ctx, rawAsset); return; }
  if (ext === "tms" || ext === "dat") {
    const sets = L.findTextureSets(data, false);
    if (sets.length) { showTextures(name, sets, ctx, rawAsset, [[ "Textures", sets[0].textures.length ]]); return; }
  }
  showHex(name, data, ctx, rawAsset);
}

function showHex(name, data, ctx, rawAsset) {
  $("hexBox").textContent = hexDump(data, 4096);
  showView("hex");
  setMeta([...ctx.base, ["Type", L.extOf(name) ? "." + L.extOf(name) + " file" : "file"], ["Preview", "hex dump"]]);
  setSave(rawAsset);
}

// ---------------------------------------------------------------- textures

function textureCard(t, label, scale) {
  const wrap = document.createElement("div"); wrap.className = "tex";
  const c = document.createElement("canvas"); c.width = t.width; c.height = t.height;
  c.getContext("2d").putImageData(new ImageData(L.textureRGBA(t), t.width, t.height), 0, 0);
  c.style.width = t.width * scale + "px";
  const cap = document.createElement("div"); cap.className = "cap"; cap.textContent = label + ": " + t.width + "x" + t.height + ", " + t.formatName;
  wrap.append(c, cap);
  return wrap;
}

function fillTextureGrid(grid, sets, scaleFn) {
  grid.replaceChildren();
  sets.forEach((s, si) => s.textures.forEach((t, i) =>
    grid.appendChild(textureCard(t, (sets.length > 1 ? "set " + si + " #" : "#") + i, scaleFn(t)))));
}

async function texturesToPngs(sets) {
  const out = [];
  for (let si = 0; si < sets.length; si++)
    for (let i = 0; i < sets[si].textures.length; i++) {
      const t = sets[si].textures[i];
      out.push({ name: (sets.length > 1 ? si + "_" : "") + String(i).padStart(2, "0") + ".png", data: await L.encodePng(t.width, t.height, L.textureRGBA(t)) });
    }
  return out;
}

function showTextures(name, sets, ctx, rawAsset, extraMeta) {
  const total = sets.reduce((a, s) => a + s.textures.length, 0);
  let zoom = 2;
  const grid = $("texGrid");
  const redraw = () => fillTextureGrid(grid, sets, t => (t.width >= 512 ? 1 : zoom));
  redraw();
  showView("tex");
  const slider = document.createElement("input"); slider.type = "range"; slider.min = 1; slider.max = 8; slider.value = zoom;
  slider.oninput = () => { zoom = +slider.value; redraw(); };
  const lab = document.createElement("label"); lab.append("Zoom ", slider);
  setToolbar([lab]);
  setMeta([...ctx.base, ["Type", "texture set"], ["Textures", total], ...(extraMeta || []).filter(r => r[0] !== "Textures")]);
  const stem = stripExt(baseName(name));
  setSave({
    ...rawAsset,
    convLabel: total === 1 ? "Save as PNG" : "Save " + total + " PNGs (zip)",
    converted: async () => {
      const pngs = await texturesToPngs(sets);
      return pngs.length === 1 ? { name: stem + ".png", bytes: pngs[0].data, type: "image/png" }
        : { name: stem + "_textures.zip", bytes: makeZip(pngs.map(p => ({ name: stem + "_" + p.name, data: p.data }))), type: "application/zip" };
    },
  });
}

// ---------------------------------------------------------------- archives

function table(headers, rows, onPick) {
  const t = document.createElement("table"); t.className = "listing";
  const thead = t.createTHead().insertRow();
  headers.forEach(h => { const th = document.createElement("th"); th.textContent = h; thead.appendChild(th); });
  const tb = t.createTBody();
  rows.forEach((r, i) => {
    const tr = tb.insertRow();
    r.forEach(c => { tr.insertCell().textContent = c; });
    if (onPick && onPick(i, null)) { tr.className = "pick"; tr.onclick = () => onPick(i, tr); }
  });
  return t;
}

async function showLzs(name, data, ctx, rawAsset) {
  const stem = stripExt(baseName(name));
  const box = $("listBox");
  box.replaceChildren();
  if (!L.lzsIsArchive(data)) {
    const out = L.lzsDecompress(data).data;
    setMeta([...ctx.base, ["Type", "compressed file"], ["Unpacked", fmtSize(out.length)]]);
    // The usual content is the matching .pac: show it like one.
    return showData(stem + ".pac", out, { ...ctx, base: ctx.base.concat([["Unpacked", fmtSize(out.length)]]), raw: ctx.raw });
  }
  const members = L.lzsMembers(data);
  box.appendChild(table(["#", "Member"], members.map((m, i) => [i, m.path]), (i, tr) => {
    if (tr) {
      const token = ++state.token;
      try {
        const body = members[i].read();
        const memberName = members[i].path;
        const findTextures = async mname => {
          const stemM = stripExt(mname), sib = members.find(x => stripExt(x.path) === stemM && L.extOf(x.path) === "tms");
          if (!sib) return null;
          const sets = L.findTextureSets(sib.read(), false);
          return sets.length ? sets[0].textures : null;
        };
        const findMotions = async mname => {
          const stemM = stripExt(mname), sib = members.find(x => stripExt(x.path) === stemM && (L.extOf(x.path) === "mov" || L.extOf(x.path) === "moz"));
          if (!sib) return null;
          const d = sib.read();
          return L.parseMotions(L.extOf(sib.path) === "moz" ? L.lzsDecompress(d).data : d);
        };
        // a motion inside an archive drives a model from the same archive
        const findModelFor = async (mname, clips) => {
          const stemM = stripExt(baseName(mname)), clip = clips.find(Boolean);
          const cands = members.filter(x => L.extOf(x.path) === "tmd").sort((a, b) => (stripExt(baseName(b.path)) === stemM) - (stripExt(baseName(a.path)) === stemM));
          let loose = null;
          for (const m of cands.slice(0, 8)) {
            try {
              const models = L.parseModels(m.read()), fit = Math.max(...models.map(md => L.slotsFit(md, clip)));
              if (fit === 2) return { name: m.path, models, textures: await findTextures(m.path) };
              if (fit && !loose) loose = { name: m.path, models, textures: await findTextures(m.path) };
            } catch (e) { /* not a match */ }
          }
          return loose;
        };
        showData(memberName, body, { ...ctx, token, findTextures, findMotions, findModelFor, base: [["Name", baseName(memberName)], ["In archive", baseName(name)], ["Size", fmtSize(body.length)]], raw: null })
          .then(() => {
            if (token !== state.token) return;
            setToolbar([btn("Back to archive", () => showLzs(name, data, ctx, rawAsset)), ...$("toolbar").children]);
            const prev = state.asset;
            if (prev) setSave({ ...prev, raw: async () => body, name: baseName(memberName) });
          })
          .catch(e => setStatus("Cannot open member: " + e.message, true));
      } catch (e) { setStatus("Cannot open member: " + e.message, true); }
    }
    return true;
  }));
  showView("list");
  setMeta([...ctx.base, ["Type", "archive"], ["Members", members.length]]);
  setToolbar([]);
  setSave({
    ...rawAsset,
    convLabel: "Save unpacked members (zip)",
    converted: () => ({ name: stem + "_unpacked.zip", type: "application/zip",
      bytes: makeZip(members.map(m => ({ name: safeParts(m.path).join("/"), data: m.read() }))) }),
  });
}

function showPac(name, data, ctx, rawAsset) {
  const chunks = L.pacChunks(data), stem = stripExt(baseName(name));
  if (!chunks.length) { showHex(name, data, ctx, rawAsset); return; }   // not a chunked package (system.pac uses another layout)
  const box = $("listBox");
  box.replaceChildren();
  box.appendChild(table(["#", "Type", "Kind", "Bytes"], chunks.map((c, i) => [i, "0x" + c.type.toString(16).padStart(2, "0"), c.name, c.size.toLocaleString()])));
  const sets = L.findTextureSets(data, true);
  if (sets.length) {
    const h = document.createElement("h3"); h.style.margin = "18px 0 8px"; h.textContent = "Textures";
    const grid = document.createElement("div"); grid.className = "texgrid";
    fillTextureGrid(grid, sets, t => (t.width >= 512 ? 1 : 2));
    box.append(h, grid);
  }
  showView("list");
  const total = sets.reduce((a, s) => a + s.textures.length, 0);
  setMeta([...ctx.base, ["Type", "package (.pac)"], ["Chunks", chunks.length], ["Textures", total]]);
  setToolbar([]);
  setSave({
    ...rawAsset,
    convLabel: total ? "Save " + total + " PNGs (zip)" : null,
    converted: total ? async () => {
      const pngs = await texturesToPngs(sets);
      return { name: stem + "_textures.zip", type: "application/zip", bytes: makeZip(pngs.map(p => ({ name: stem + "_" + p.name, data: p.data }))) };
    } : null,
  });
}

// ---------------------------------------------------------------- audio

let audio = { ctx: null, src: null, buf: null, playing: false };
function stopAudio() {
  if (audio.src) { try { audio.src.onended = null; audio.src.stop(); } catch (e) { /* already stopped */ } audio.src = null; }
  audio.playing = false;
  const b = $("playBtn"); if (b) b.textContent = "Play";
}
$("playBtn").onclick = () => {
  if (!audio.buf) return;
  if (audio.playing) { stopAudio(); return; }
  audio.ctx = audio.ctx || new (window.AudioContext || window.webkitAudioContext)();
  const src = audio.ctx.createBufferSource();
  src.buffer = audio.buf; src.connect(audio.ctx.destination);
  src.onended = () => { audio.playing = false; audio.src = null; $("playBtn").textContent = "Play"; };
  src.start(); audio.src = src; audio.playing = true; $("playBtn").textContent = "Stop";
};

function drawWave(ch) {
  const c = $("wave"), g = c.getContext("2d"), w = c.width, h = c.height;
  g.clearRect(0, 0, w, h);
  g.fillStyle = "#F2C40E";
  const step = Math.max(1, Math.floor(ch.length / w));
  for (let x = 0; x < w; x++) {
    let lo = 32767, hi = -32768;
    const a = x * step, b = Math.min(ch.length, a + step);
    for (let i = a; i < b; i += Math.max(1, step >> 6)) { const v = ch[i]; if (v < lo) lo = v; if (v > hi) hi = v; }
    if (lo > hi) continue;
    const y1 = h / 2 - hi / 32768 * h / 2, y2 = h / 2 - lo / 32768 * h / 2;
    g.fillRect(x, y1, 1, Math.max(1, y2 - y1));
  }
}

async function showAudio(name, data, ctx, rawAsset) {
  setStatus("Decoding audio…");
  await new Promise(r => setTimeout(r, 0));
  const { rate, channels } = L.decodeInt(data);
  setStatus("");
  if (ctx.token !== undefined && ctx.token !== state.token) return;
  const n = channels[0].length;
  const ab = new (window.AudioBuffer || window.webkitAudioBuffer)({ length: n, numberOfChannels: 2, sampleRate: rate });
  channels.forEach((c, k) => { const f = ab.getChannelData(k); for (let i = 0; i < n; i++) f[i] = c[i] / 32768; });
  stopAudio();
  audio.buf = ab;
  drawWave(channels[0]);
  const secs = n / rate;
  $("audioInfo").textContent = Math.floor(secs / 60) + ":" + String(Math.floor(secs % 60)).padStart(2, "0") + " · " + rate + " Hz stereo";
  showView("audio");
  setToolbar([]);
  setMeta([...ctx.base, ["Type", "audio stream"], ["Length", Math.floor(secs / 60) + ":" + String(Math.floor(secs % 60)).padStart(2, "0")], ["Rate", rate + " Hz stereo"]]);
  const stem = stripExt(baseName(name));
  setSave({ ...rawAsset, convLabel: "Save as WAV", converted: () => ({ name: stem + ".wav", bytes: L.encodeWav(channels, rate), type: "audio/wav" }) });
}

// ---------------------------------------------------------------- models (WebGL2)

const gl3 = { skel: null, glTex: [], hasTex: false, gl: null, prog: null, loc: null, parts: [], cam: null, dirty: false, models: null, mi: 0, bounds: null };
const canvas = $("gl");

const VS = `#version 300 es
in vec3 aPos; in vec3 aNrm; in vec3 aCol; in vec2 aUV;
uniform mat4 uMVP; uniform mat3 uNM;
out vec3 vN; out vec3 vC; out vec2 vUV;
void main(){ vN = uNM * aNrm; vC = aCol; vUV = aUV; gl_Position = uMVP * vec4(aPos, 1.0); }`;
const FS = `#version 300 es
precision mediump float;
in vec3 vN; in vec3 vC; in vec2 vUV;
uniform int uMode; uniform bool uColor; uniform bool uTwo; uniform bool uTex; uniform sampler2D uSampler;
out vec4 o;
void main(){
  if (uMode == 1) { o = vec4(0.95, 0.77, 0.05, 1.0); return; }
  float len = length(vN);
  float l = 0.85;
  if (len > 0.01) {
    vec3 n = vN / len;
    if (uTwo && n.z < 0.0) n = -n;   // double-sided pieces (feathers, cloth) have normals on either side: light the side that faces the viewer
    l = 0.35 + 0.65 * max(dot(n, normalize(vec3(0.3, 0.5, 1.0))), 0.0);
  }
  vec3 base = uColor ? min(vC * 1.9921875, vec3(1.0)) : vec3(0.78);
  if (uTex) {
    vec4 t = texture(uSampler, vUV);
    if (t.a < 0.5) discard;
    base = uColor ? min(vC * 1.9921875, vec3(1.0)) * t.rgb : t.rgb;
  }
  o = vec4(base * l, 1.0);
}`;

function compile(gl, type, src) {
  const s = gl.createShader(type); gl.shaderSource(s, src); gl.compileShader(s);
  if (!gl.getShaderParameter(s, gl.COMPILE_STATUS)) throw new Error(gl.getShaderInfoLog(s));
  return s;
}
function initGl() {
  if (gl3.gl) return true;
  const gl = canvas.getContext("webgl2", { antialias: true });
  if (!gl) return false;
  const p = gl.createProgram();
  gl.attachShader(p, compile(gl, gl.VERTEX_SHADER, VS)); gl.attachShader(p, compile(gl, gl.FRAGMENT_SHADER, FS));
  gl.bindAttribLocation(p, 0, "aPos"); gl.bindAttribLocation(p, 1, "aNrm"); gl.bindAttribLocation(p, 2, "aCol"); gl.bindAttribLocation(p, 3, "aUV");
  gl.linkProgram(p);
  if (!gl.getProgramParameter(p, gl.LINK_STATUS)) throw new Error(gl.getProgramInfoLog(p));
  gl3.gl = gl; gl3.prog = p;
  gl3.loc = { mvp: gl.getUniformLocation(p, "uMVP"), nm: gl.getUniformLocation(p, "uNM"), mode: gl.getUniformLocation(p, "uMode"), color: gl.getUniformLocation(p, "uColor"), two: gl.getUniformLocation(p, "uTwo"), tex: gl.getUniformLocation(p, "uTex"), sampler: gl.getUniformLocation(p, "uSampler") };
  gl.enable(gl.DEPTH_TEST);
  new ResizeObserver(() => requestDraw()).observe(views.gl);
  return true;
}

function mul(a, b) {
  const o = new Float32Array(16);
  for (let c = 0; c < 4; c++) for (let r = 0; r < 4; r++) { let s = 0; for (let k = 0; k < 4; k++) s += a[k * 4 + r] * b[c * 4 + k]; o[c * 4 + r] = s; }
  return o;
}
const translate = (x, y, z) => new Float32Array([1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, x, y, z, 1]);
const rotX = a => { const c = Math.cos(a), s = Math.sin(a); return new Float32Array([1, 0, 0, 0, 0, c, s, 0, 0, -s, c, 0, 0, 0, 0, 1]); };
const rotY = a => { const c = Math.cos(a), s = Math.sin(a); return new Float32Array([c, 0, -s, 0, 0, 1, 0, 0, s, 0, c, 0, 0, 0, 0, 1]); };
function perspective(fovy, asp, n, f) {
  const t = 1 / Math.tan(fovy / 2), o = new Float32Array(16);
  o[0] = t / asp; o[5] = t; o[10] = (f + n) / (n - f); o[11] = -1; o[14] = 2 * f * n / (n - f);
  return o;
}

function resetCamera(keepAngles) {
  const b = gl3.bounds;
  if (!b) return;
  const old = gl3.cam;
  const cx = (b.min[0] + b.max[0]) / 2, cy = (b.min[1] + b.max[1]) / 2, cz = (b.min[2] + b.max[2]) / 2;
  const r = Math.max(1e-3, Math.hypot(b.max[0] - b.min[0], b.max[1] - b.min[1], b.max[2] - b.min[2]) / 2);
  gl3.cam = { yaw: 0.5, pitch: 0.25, center: [cx, cy, cz], radius: r, dist: r * 2.6, panX: 0, panY: 0 };
  if (keepAngles === true && old) { gl3.cam.yaw = old.yaw; gl3.cam.pitch = old.pitch; }
  const z = $("zoomSlider"); if (z) z.value = 100;
  requestDraw();
}

function disposeTextures() {
  for (const t of gl3.glTex) if (t) gl3.gl.deleteTexture(t);
  gl3.glTex = []; gl3.hasTex = false;
}
function uploadTextures(textures) {
  const gl = gl3.gl;
  disposeTextures();
  if (!textures) return;
  gl3.glTex = textures.map(t => {
    try {
      const tex = gl.createTexture();
      gl.bindTexture(gl.TEXTURE_2D, tex);
      gl.pixelStorei(gl.UNPACK_FLIP_Y_WEBGL, false);
      gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, t.width, t.height, 0, gl.RGBA, gl.UNSIGNED_BYTE, new Uint8Array(L.textureRGBA(t).buffer));
      gl.generateMipmap(gl.TEXTURE_2D);
      gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.LINEAR_MIPMAP_LINEAR);
      gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.LINEAR);
      gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.REPEAT);
      gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.REPEAT);
      return tex;
    } catch (e) { return null; }
  });
  gl3.hasTex = gl3.glTex.some(Boolean);
}

function disposeParts() {
  const gl = gl3.gl;
  for (const p of gl3.parts) { gl.deleteVertexArray(p.vao); p.bufs.forEach(b => gl.deleteBuffer(b)); if (p.lineBuf) gl.deleteBuffer(p.lineBuf); }
  gl3.parts = [];
}

function uploadModel(model, textures, posed) {
  const gl = gl3.gl;
  disposeParts();
  const min = [Infinity, Infinity, Infinity], max = [-Infinity, -Infinity, -Infinity];
  model.parts.forEach((part, idx) => {
    if (!part.positions.length) return;
    const vao = gl.createVertexArray(); gl.bindVertexArray(vao);
    const bufs = [];
    const src = posed ? posed[idx] : part;
    [[src.positions, 0, 3], [src.normals, 1, 3], [part.colors, 2, 3], [L.modelUVs(part, textures), 3, 2]].forEach(([arr, loc, size]) => {
      const b = gl.createBuffer(); gl.bindBuffer(gl.ARRAY_BUFFER, b); gl.bufferData(gl.ARRAY_BUFFER, arr, posed && loc < 2 ? gl.DYNAMIC_DRAW : gl.STATIC_DRAW);
      gl.enableVertexAttribArray(loc); gl.vertexAttribPointer(loc, size, gl.FLOAT, false, 0, 0); bufs.push(b);
    });
    gl.bindVertexArray(null);
    const detached = !!(part.flags & 1);   // no bone slot: debris fragments for death/burst effects, hidden until ticked
    gl3.parts.push({ idx, vao, bufs, count: part.positions.length / 3, show: !detached, lineBuf: null, part });
    if (!detached) for (let i = 0; i < src.positions.length; i += 3) for (let c = 0; c < 3; c++) { const v = src.positions[i + c]; if (v < min[c]) min[c] = v; if (v > max[c]) max[c] = v; }
  });
  gl3.bounds = isFinite(min[0]) ? { min, max } : null;
  resetCamera();
}

function ensureLines(p) {
  if (p.lineBuf) return;
  const gl = gl3.gl, tris = p.count / 3, idx = new Uint32Array(tris * 6);
  for (let t = 0; t < tris; t++) { const a = t * 3; idx.set([a, a + 1, a + 1, a + 2, a + 2, a], t * 6); }
  p.lineBuf = gl.createBuffer();
  gl.bindVertexArray(p.vao); gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, p.lineBuf); gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, idx, gl.STATIC_DRAW); gl.bindVertexArray(null);
}

// Skeleton: one line per bone from its parent's joint to its own, in the same flipped space as the model
function setSkeleton(clip, W) {
  const gl = gl3.gl;
  if (!clip) { if (gl3.skel) { gl.deleteBuffer(gl3.skel.buf); gl.deleteVertexArray(gl3.skel.vao); gl3.skel = null; } return; }
  const pts = [];
  clip.bones.forEach((b, i) => {
    const t = W[i].t, p = b.parent === null ? W[i].t : W[b.parent].t;
    pts.push(p[0], -p[1], -p[2], t[0], -t[1], -t[2]);
  });
  const arr = new Float32Array(pts);
  if (!gl3.skel) {
    const vao = gl.createVertexArray(), buf = gl.createBuffer();
    gl.bindVertexArray(vao); gl.bindBuffer(gl.ARRAY_BUFFER, buf);
    gl.enableVertexAttribArray(0); gl.vertexAttribPointer(0, 3, gl.FLOAT, false, 0, 0);
    gl.bindVertexArray(null);
    gl3.skel = { vao, buf, count: 0 };
  }
  gl.bindBuffer(gl.ARRAY_BUFFER, gl3.skel.buf); gl.bufferData(gl.ARRAY_BUFFER, arr, gl.DYNAMIC_DRAW);
  gl3.skel.count = arr.length / 3;
  gl3.skel.points = arr;
}

function requestDraw() { if (gl3.dirty) return; gl3.dirty = true; requestAnimationFrame(draw); }
function draw() {
  gl3.dirty = false;
  const gl = gl3.gl;
  if (!gl || !gl3.cam || !views.gl.classList.contains("on")) return;
  const dpr = window.devicePixelRatio || 1, w = Math.max(1, Math.floor(canvas.clientWidth * dpr)), h = Math.max(1, Math.floor(canvas.clientHeight * dpr));
  if (canvas.width !== w || canvas.height !== h) { canvas.width = w; canvas.height = h; }
  gl.viewport(0, 0, w, h);
  gl.clearColor(0, 0, 0, 0); gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
  const c = gl3.cam, near = Math.max(c.radius * 0.01, c.dist - c.radius * 4), far = c.dist + c.radius * 4;
  const rot = mul(rotX(c.pitch), rotY(c.yaw));
  const view = mul(translate(c.panX, c.panY, -c.dist), mul(rot, translate(-c.center[0], -c.center[1], -c.center[2])));
  const mvp = mul(perspective(Math.PI / 4, w / h, Math.max(near, c.radius * 0.01), far), view);
  const nm = new Float32Array([rot[0], rot[1], rot[2], rot[4], rot[5], rot[6], rot[8], rot[9], rot[10]]);
  gl.useProgram(gl3.prog);
  gl.uniformMatrix4fv(gl3.loc.mvp, false, mvp); gl.uniformMatrix3fv(gl3.loc.nm, false, nm);
  gl.uniform1i(gl3.loc.color, $("optColor").checked ? 1 : 0); gl.uniform1i(gl3.loc.two, $("optTwo").checked ? 1 : 0);
  const wire = $("optWire").checked;
  gl.disable(gl.CULL_FACE);
  if (!$("optTwo").checked) gl.enable(gl.CULL_FACE);
  for (const p of gl3.parts) {
    if (!p.show) continue;
    gl.bindVertexArray(p.vao);
    if (wire) { ensureLines(p); gl.uniform1i(gl3.loc.mode, 1); gl.drawElements(gl.LINES, p.count * 2, gl.UNSIGNED_INT, 0); }
    else {
      gl.uniform1i(gl3.loc.mode, 0);
      const useTex = gl3.hasTex && $("optTex").checked;
      for (const r of p.part.ranges) {
        const tex = useTex ? gl3.glTex[r.tex] : null;
        gl.uniform1i(gl3.loc.tex, tex ? 1 : 0);
        if (tex) { gl.activeTexture(gl.TEXTURE0); gl.bindTexture(gl.TEXTURE_2D, tex); gl.uniform1i(gl3.loc.sampler, 0); }
        gl.drawArrays(gl.TRIANGLES, r.start, r.count);
      }
    }
  }
  gl.bindVertexArray(null);
  if (gl3.skel && $("optSkel").checked) {
    gl.disable(gl.DEPTH_TEST);
    gl.bindVertexArray(gl3.skel.vao);
    gl.uniform1i(gl3.loc.mode, 1);
    gl.drawArrays(gl.LINES, 0, gl3.skel.count);
    gl.bindVertexArray(null);
    gl.enable(gl.DEPTH_TEST);
  }
}

(function bindCamera() {
  let mode = null, lx = 0, ly = 0;
  canvas.addEventListener("pointerdown", e => { mode = e.button === 2 || e.shiftKey ? "pan" : "rot"; lx = e.clientX; ly = e.clientY; canvas.setPointerCapture(e.pointerId); canvas.classList.add("drag"); });
  canvas.addEventListener("pointermove", e => {
    if (!mode || !gl3.cam) return;
    const dx = e.clientX - lx, dy = e.clientY - ly; lx = e.clientX; ly = e.clientY;
    const c = gl3.cam;
    if (mode === "rot") { c.yaw += dx * 0.01; c.pitch = Math.max(-1.5, Math.min(1.5, c.pitch + dy * 0.01)); }
    else { const k = c.dist / canvas.clientHeight * 0.9; c.panX += dx * k; c.panY -= dy * k; }
    requestDraw();
  });
  const end = () => { mode = null; canvas.classList.remove("drag"); };
  canvas.addEventListener("pointerup", end); canvas.addEventListener("pointercancel", end);
  canvas.addEventListener("contextmenu", e => e.preventDefault());
  canvas.addEventListener("wheel", e => {
    if (!gl3.cam) return; e.preventDefault();
    gl3.cam.dist = Math.max(gl3.cam.radius * 0.2, Math.min(gl3.cam.radius * 20, gl3.cam.dist * Math.exp(e.deltaY * 0.001)));
    const z = $("zoomSlider"); if (z) z.value = Math.round(100 * gl3.cam.radius * 2.6 / gl3.cam.dist);
    requestDraw();
  }, { passive: false });
  for (const id of ["optWire", "optColor", "optTwo", "optTex", "optSkel"]) $(id).addEventListener("change", requestDraw);
})();

// ---- posing: a clip of the model's own .mov drives the skeleton; frame 0 of the first clip is the default pose
const anim = { raf: 0, last: 0 };

// Clip picker, Play button and frame slider, filled into `box`. getModel() may return null (skeleton only).
function buildPoseControls(box, pose, getModel, enabled) {
  box.replaceChildren();
  if (!enabled()) return;
  const sel = document.createElement("select"); sel.id = "clipSel"; sel.setAttribute("aria-label", "Animation");
  pose.clips.forEach((c, i) => { const o = document.createElement("option"); o.value = i; o.textContent = c.name || "clip " + i; sel.appendChild(o); });
  sel.value = pose.ci;
  sel.onchange = () => { stopAnim(); pose.ci = +sel.value; fitClip(pose, getModel(), true); applyPose(pose, getModel(), 0); };
  const play = btn("Play", () => {
    if (anim.raf) { stopAnim(); return; }
    play.textContent = "Pause"; anim.last = 0;
    const step = t => {
      if (t - anim.last >= 33) { anim.last = t; const clip = pose.clips[pose.ci]; applyPose(pose, getModel(), (pose.frame + 1) % clip.frames); }
      anim.raf = requestAnimationFrame(step);
    };
    anim.raf = requestAnimationFrame(step);
  });
  play.id = "playAnim";
  const fs = document.createElement("input"); fs.type = "range"; fs.id = "frameSlider"; fs.min = 0; fs.max = pose.clips[pose.ci].frames - 1; fs.value = 0; fs.setAttribute("aria-label", "Frame");
  fs.oninput = () => { stopAnim(); applyPose(pose, getModel(), +fs.value); };
  const fl = document.createElement("span"); fl.id = "frameLabel"; fl.className = "label"; fl.textContent = "0 / " + (pose.clips[pose.ci].frames - 1);
  box.append(sel, play, fs, fl);
}
function stopAnim() { if (anim.raf) cancelAnimationFrame(anim.raf); anim.raf = 0; const b = $("playAnim"); if (b) b.textContent = "Play"; }

// Frames the camera on everything a clip does (sampled), so a model that moves during an animation stays in view
function fitClip(pose, model, keepAngles) {
  const clip = pose.clips[pose.ci], n = clip.frames, steps = Math.min(12, n);
  const min = [Infinity, Infinity, Infinity], max = [-Infinity, -Infinity, -Infinity];
  const add = (x, y, z) => { if (x < min[0]) min[0] = x; if (x > max[0]) max[0] = x; if (y < min[1]) min[1] = y; if (y > max[1]) max[1] = y; if (z < min[2]) min[2] = z; if (z > max[2]) max[2] = z; };
  for (let i = 0; i < steps; i++) {
    const W = L.poseWorld(clip, Math.floor(i * (n - 1) / Math.max(1, steps - 1)), pose.conv);
    for (const w of W) add(w.t[0], -w.t[1], -w.t[2]);
    if (model) L.skinModel(model, clip, W, pose.J, pose.slotBones).forEach((p, pi) => { if (model.parts[pi].flags & 1) return; for (let k = 0; k < p.positions.length; k += 3) add(p.positions[k], p.positions[k + 1], p.positions[k + 2]); });
  }
  if (!isFinite(min[0])) return;
  gl3.bounds = { min, max };
  resetCamera(keepAngles);
}

function applyPose(pose, model, frame) {
  const clip = pose.clips[pose.ci];
  frame = Math.max(0, Math.min(clip.frames - 1, frame));
  pose.frame = frame;
  const W = L.poseWorld(clip, frame, pose.conv);
  setSkeleton(clip, W);
  const skinned = model ? L.skinModel(model, clip, W, pose.J, pose.slotBones) : null;
  const gl = gl3.gl;
  for (const p of skinned ? gl3.parts : []) {
    gl.bindBuffer(gl.ARRAY_BUFFER, p.bufs[0]); gl.bufferData(gl.ARRAY_BUFFER, skinned[p.idx].positions, gl.DYNAMIC_DRAW);
    gl.bindBuffer(gl.ARRAY_BUFFER, p.bufs[1]); gl.bufferData(gl.ARRAY_BUFFER, skinned[p.idx].normals, gl.DYNAMIC_DRAW);
  }
  const fs = $("frameSlider"); if (fs) { fs.max = clip.frames - 1; fs.value = frame; }
  const fl = $("frameLabel"); if (fl) fl.textContent = frame + " / " + (clip.frames - 1);
  requestDraw();
  return skinned;
}

// poseOn: start with "Pose with animation" ticked (on by default whenever the model has clips)
function showModel(name, models, ctx, rawAsset, textures, motions, poseOn) {
  if (!initGl()) throw new Error("This browser has no WebGL2, which the 3D preview needs.");
  gl3.models = models;
  const usable = models.map((m, i) => i).filter(i => models[i].parts.length);
  if (!usable.length) throw new Error("No part of this model could be decoded.");
  const stem = stripExt(baseName(name));
  stopAnim();
  L.bindTextures(models, textures);
  uploadTextures(textures);
  // clips whose bone-slot map fits this model; the first one gives the bind pose
  const total = models.map(L.modelSlots);
  const clipsFor = i => { const fits = (motions || []).filter(c => c && L.slotsFit(models[i], c)); return fits.some(c => c.slotBones.length === total[i]) ? fits.filter(c => c.slotBones.length === total[i]) : fits; };
  const pose = { clips: [], ci: 0, frame: 0, J: null, conv: L.POSE_CONVENTION, on: true };
  window.LegaiaViewer.pose = pose;
  const optPose = $("optPose");
  const optTex = $("optTex");
  optTex.disabled = !gl3.hasTex; optTex.checked = gl3.hasTex;
  const info = () => {
    const m = models[gl3.mi];
    const verts = m.parts.reduce((a, p) => a + p.vertexCount, 0), tris = m.parts.reduce((a, p) => a + p.triangleCount, 0);
    setMeta([...ctx.base, ["Type", "model (.tmd)"], ["Models", models.length], ["Parts", m.parts.length + (m.bad.length ? " (+" + m.bad.length + " unsupported)" : "")], ["Vertices", verts.toLocaleString()], ["Triangles", tris.toLocaleString()], ["Textures", textures ? textures.length + " (matching .tms)" : "none found"], ["Animations", pose.clips.length ? pose.clips.length + " clips" : "none found"]]);
    const box = $("parts"); box.replaceChildren();
    gl3.parts.forEach(p => {
      const l = document.createElement("label"); l.className = "opt";
      const cb = document.createElement("input"); cb.type = "checkbox"; cb.checked = p.show;
      cb.onchange = () => { p.show = cb.checked; requestDraw(); };
      l.append(cb, p.part.name + (p.part.skinned ? " (skinned)" : "") + (p.part.flags & 1 ? " (detached piece)" : ""));
      box.appendChild(l);
    });
  };
  let renderPoseControls = null;
  const load = i => {
    gl3.mi = i;
    pose.clips = clipsFor(i); pose.ci = 0;
    // part-to-bone map and skeleton calibration for this model (see alignSlots and fitSkeleton)
    pose.slotBones = pose.clips.length ? L.alignSlots(models[i], pose.clips[0]) : null;
    const fitted = pose.clips.length ? L.fitSkeleton(models[i], pose.clips[0], pose.slotBones) : null;
    // a skeleton that is nowhere near the model's skinned geometry belongs to another mesh (mon011_ on mon011.mov): no animation then
    if (fitted && fitted.ratio !== null && fitted.ratio > 0.8) { pose.clips = []; pose.slotBones = null; }
    const cal = pose.clips.length ? fitted.cal : null;
    pose.conv = cal ? { ...L.POSE_CONVENTION, cal } : L.POSE_CONVENTION;
    pose.J = pose.clips.length ? L.bindJoints(pose.clips[0], cal) : null;
    // "Pose with animation" shows as off while the model has no animation, and comes back when one with clips is picked
    if (!pose.clips.length) { if (optPose.checked) { optPose.checked = false; pose.autoOff = true; } }
    else if (pose.autoOff) { optPose.checked = true; pose.autoOff = false; }
    const usePose = pose.clips.length > 0 && optPose.checked;
    optPose.disabled = !pose.clips.length;
    let first = null;
    if (usePose) { const clip = pose.clips[0]; first = L.skinModel(models[i], clip, L.poseWorld(clip, 0, pose.conv), pose.J, pose.slotBones); }
    uploadModel(models[i], textures, first);
    if (usePose) { setSkeleton(pose.clips[0], L.poseWorld(pose.clips[0], 0, pose.conv)); fitClip(pose, models[i], false); } else setSkeleton(null);
    info();
    if (renderPoseControls) renderPoseControls();
  };
  optPose.checked = !!poseOn;
  $("optSkel").checked = false;
  optPose.onchange = () => { stopAnim(); load(gl3.mi); };
  gl3.mi = usable[0];
  showView("gl");
  load(gl3.mi);
  const poseBox = document.createElement("span"); poseBox.className = "toolbar"; poseBox.style.display = "contents";
  renderPoseControls = () => buildPoseControls(poseBox, pose, () => models[gl3.mi], () => pose.clips.length && optPose.checked);
  renderPoseControls();
  const tools = [btn("Reset view", () => resetCamera()), poseBox];
  if (usable.length > 1) {
    const sel = document.createElement("select"); sel.setAttribute("aria-label", "Model");
    usable.forEach(i => { const o = document.createElement("option"); o.value = i; o.textContent = "Model " + i; sel.appendChild(o); });
    sel.onchange = () => load(+sel.value);
    tools.push(sel);
  }
  const g = document.createElement("span"); g.className = "grow"; tools.push(g);
  const z = document.createElement("input"); z.type = "range"; z.id = "zoomSlider"; z.min = 20; z.max = 500; z.value = 100;
  z.oninput = () => { if (gl3.cam) { gl3.cam.dist = gl3.cam.radius * 2.6 * 100 / +z.value; requestDraw(); } };
  const lab = document.createElement("label"); lab.append("Zoom ", z); tools.push(lab);
  setToolbar(tools);
  const hint = document.createElement("span"); hint.className = "label"; hint.textContent = "Drag to rotate, shift-drag to pan, wheel to zoom";
  $("toolbar").prepend(hint);
  setSave({
    ...rawAsset, model: true,
    convLabel: textures ? "Save OBJ + textures (zip)" : "Save as OBJ",
    converted: async () => {
      const enc = new TextEncoder();
      if (!textures) return { name: stem + ".obj", bytes: enc.encode(L.modelsToObj(models, "model")), type: "text/plain" };
      const pngs = await texturesToPngs([{ textures }]), names = pngs.map(p => stem + "_tex_" + p.name);
      return { name: stem + "_model.zip", type: "application/zip", bytes: makeZip([
        { name: stem + ".obj", data: enc.encode(L.modelsToObj(models, "model", textures, stem + ".mtl")) },
        { name: stem + ".mtl", data: enc.encode(L.modelMtl(names)) },
        ...pngs.map((p, i) => ({ name: names[i], data: p.data })),
      ]) };
    },
  });
}

function clipsToJson(clips) {
  const r = a => Array.from(a, v => Math.round(v * 1000) / 1000);
  return JSON.stringify(clips.filter(Boolean).map(c => ({
    name: c.name, frames: c.frames, keyStep: c.keyStep, slotBones: c.slotBones,
    bones: c.bones.map(b => ({ name: b.name, parent: b.parent, tx: r(b.t[0]), ty: r(b.t[1]), tz: r(b.t[2]), rxDeg: r(b.r[0]), ryDeg: r(b.r[1]), rzDeg: r(b.r[2]) })),
  })));
}

// A .mov / .moz file: shown on the model it drives when there is one, else as a bare skeleton
async function showMotion(name, data, ctx, rawAsset) {
  const clips = L.parseMotions(data).filter(Boolean);
  if (!clips.length) throw new Error("This file has no animation clips with bones (the clips are empty, or use a layout that cannot be read).");
  const stem = stripExt(baseName(name));
  const save = { ...rawAsset, model: true, convLabel: "Save animations (JSON)", converted: () => ({ name: stem + "_motions.json", type: "application/json", bytes: new TextEncoder().encode(clipsToJson(clips)) }) };
  const found = ctx.findModelFor ? await ctx.findModelFor(name, clips) : null;
  if (ctx.token !== undefined && ctx.token !== state.token) return;
  if (found) {
    showModel(found.name, found.models, ctx, rawAsset, found.textures, clips, true);
    setMeta([...ctx.base, ["Type", "animation set"], ["Clips", clips.length], ["Bones", clips[0].bones.length], ["Model", baseName(found.name)]]);
    setSave(save);
    return;
  }
  showSkeleton(clips, ctx, save);
}

function showSkeleton(clips, ctx, save) {
  if (!initGl()) throw new Error("This browser has no WebGL2, which the 3D preview needs.");
  stopAnim(); disposeParts(); uploadTextures(null);
  const pose = { clips, ci: 0, frame: 0, J: null, conv: L.POSE_CONVENTION, on: true };
  window.LegaiaViewer.pose = pose;
  $("optPose").disabled = true; $("optTex").disabled = true; $("optSkel").checked = true; $("parts").replaceChildren();
  const W = L.poseWorld(clips[0], 0, pose.conv);
  setSkeleton(clips[0], W);
  const min = [Infinity, Infinity, Infinity], max = [-Infinity, -Infinity, -Infinity], pts = gl3.skel.points;
  for (let i = 0; i < pts.length; i += 3) for (let c = 0; c < 3; c++) { min[c] = Math.min(min[c], pts[i + c]); max[c] = Math.max(max[c], pts[i + c]); }
  gl3.bounds = { min, max };
  showView("gl");
  fitClip(pose, null, false);
  const box = document.createElement("span"); box.className = "toolbar"; box.style.display = "contents";
  buildPoseControls(box, pose, () => null, () => true);
  const g = document.createElement("span"); g.className = "grow";
  const z = document.createElement("input"); z.type = "range"; z.id = "zoomSlider"; z.min = 20; z.max = 500; z.value = 100;
  z.oninput = () => { if (gl3.cam) { gl3.cam.dist = gl3.cam.radius * 2.6 * 100 / +z.value; requestDraw(); } };
  const lab = document.createElement("label"); lab.append("Zoom ", z);
  setToolbar([btn("Reset view", () => resetCamera()), box, g, lab]);
  const hint = document.createElement("span"); hint.className = "label"; hint.textContent = "No matching model on the disc: showing the skeleton";
  $("toolbar").prepend(hint);
  setMeta([...ctx.base, ["Type", "animation set"], ["Clips", clips.length], ["Bones", clips[0].bones.length], ["Model", "none found"]]);
  setSave(save);
}


// ---------------------------------------------------------------- effects (.efp / .efb)

// An effect is a list of particle emitters and ring/cylinder "models". The game's own simulation is large (nayuki.cpp,
// yue.cpp), so this is an approximate preview from the documented fields: each emitter's spawn rate, life, start
// position, speed, acceleration, size, alpha and colour, and each ring's radius, height, colour and fade tweens.
// What is not read: angles and rotation, texture animation, the "spread" columns beyond a small relative jitter.
const fx = { raf: 0, last: 0, sim: null, t: 0, cam: { yaw: 0.6, pitch: 0.35, dist: 6000, cx: 0, cy: 0, cz: 0 }, dirty: false };
function stopFx() { if (fx.raf) cancelAnimationFrame(fx.raf); fx.raf = 0; const b = $("fxPlay"); if (b) b.textContent = "Play"; }

function mulberry(seed) { let a = seed >>> 0; return () => { a = (a + 0x6D2B79F5) >>> 0; let t = Math.imul(a ^ a >>> 15, 1 | a); t = t + Math.imul(t ^ t >>> 7, 61 | t) ^ t; return ((t ^ t >>> 14) >>> 0) / 4294967296; }; }
const clamp = (v, a, b) => Math.max(a, Math.min(b, v));

function buildEffectSim(objs) {
  const out = [];
  let length = 30;
  objs.forEach((o, oi) => {
    const rng = mulberry(oi * 7919 + 17), P = o.params, get = (n, i, d) => (P[n] && P[n][i] !== undefined ? P[n][i] : d);
    if (o.kind === "particle") {
      const count = clamp(Math.round(get("ptnum", 0, 0)), 0, 600), life = Math.max(1, get("drawtime", 0, 30)), app = get("apptime", 0, 0);
      if (!count) return;
      const spawnWin = clamp(app > 0 ? app : life, 1, 150), hasRate = P.drper && get("drper", 0, 0) > 0;
      const jit = (n, i) => { const v = get(n, 0, i), sp = get(n, 1, 0); return v + (rng() * 2 - 1) * (sp / 1000) * Math.max(Math.abs(v), 1); };
      const spawns = [];
      if (hasRate) {
        const per = count * get("drper", 0, 0) / 1000;
        for (let f = 0; f < spawnWin && spawns.length < count * 4; f++) { let n = Math.floor(per) + (rng() < per % 1 ? 1 : 0); while (n-- > 0) spawns.push(f); }
      } else for (let i = 0; i < count; i++) spawns.push(Math.floor(rng() * spawnWin));
      const parts = spawns.slice(0, 1500).map(f => ({
        f, life,
        p: [jit("pt_posx", 0), jit("pt_posy", 0), jit("pt_posz", 0)], v: [jit("pt_spx", 0), jit("pt_spy", 0), jit("pt_spz", 0)], a: [jit("pt_apx", 0), jit("pt_apy", 0), jit("pt_apz", 0)],
        size: [jit("pt_sizex", 8), jit("pt_sizey", 8)], dsize: [get("pt_sizespx", 0, 0), get("pt_sizespy", 0, 0)], asize: [get("pt_sizeapx", 0, 0), get("pt_sizeapy", 0, 0)],
        alpha: [jit("pt_alpha", 128), get("pt_alphasp", 0, 0), get("pt_alphaap", 0, 0)],
        col: [jit("pt_cl_r", 255), jit("pt_cl_g", 255), jit("pt_cl_b", 255)], dcol: [get("pt_clsp_r", 0, 0), get("pt_clsp_g", 0, 0), get("pt_clsp_b", 0, 0)], acol: [get("pt_clap_r", 0, 0), get("pt_clap_g", 0, 0), get("pt_clap_b", 0, 0)],
      }));
      out.push({ kind: "particle", start: o.start, parts });
      length = Math.max(length, o.start + spawnWin + life);
    } else if (o.kind === "model") {
      const cn = clamp(Math.round(get("circlenum", 0, 0)), 0, 64), div = clamp(Math.round(get("division", 0, 8)), 3, 64);
      if (cn < 1) return;
      const circles = [];
      for (let c = 0; c < cn; c++) {
        const cc = o.circles[c] || {};
        circles.push(cc);
        for (const k in cc) { const a = cc[k]; length = Math.max(length, o.start + (a[2] || 0) + (a[3] || 0) + 20); }
      }
      out.push({ kind: "model", start: o.start, cn, div, circles });
    }
  });
  return { length: clamp(Math.round(length), 30, 600), objects: out };
}

function tween(a, t, d) { if (!a) return d; const [s0, e0, dur, delay] = a; if (!(dur > 0)) return s0; return s0 + (e0 - s0) * clamp((t - delay) / dur, 0, 1); }

// World-space draw items at frame t: particles {x,y,z,r,g,b,a,size} and ring polygons
function effectFrame(sim, t) {
  const items = [], rings = [];
  for (const o of sim.objects) {
    const lt = t - o.start;
    if (lt < 0) continue;
    if (o.kind === "particle") {
      for (const p of o.parts) {
        const age = lt - p.f;
        if (age < 0 || age >= p.life) continue;
        const k = age * (age - 1) / 2, at = (s, v, a) => s + v * age + a * k;
        const alpha = clamp(at(p.alpha[0], p.alpha[1], p.alpha[2]), 0, 128) / 128;
        if (alpha <= 0.01) continue;
        items.push({ x: at(p.p[0], p.v[0], p.a[0]), y: -at(p.p[1], p.v[1], p.a[1]), z: -at(p.p[2], p.v[2], p.a[2]),
          r: clamp(at(p.col[0], p.dcol[0], p.acol[0]), 0, 255), g: clamp(at(p.col[1], p.dcol[1], p.acol[1]), 0, 255), b: clamp(at(p.col[2], p.dcol[2], p.acol[2]), 0, 255),
          a: alpha, size: Math.max(1, (at(p.size[0], p.dsize[0], p.asize[0]) + at(p.size[1], p.dsize[1], p.asize[1])) / 2) });
      }
    } else {
      const rows = [];
      for (let c = 0; c < o.cn; c++) {
        const cc = o.circles[c];
        const rx = tween(cc.wa_radiusx, lt, 0), ry = tween(cc.wa_radiusy, lt, 0), h = tween(cc.wa_height, lt, 0);
        rows.push({ rx, ry, h, r: tween(cc.wa_colorr, lt, 128), g: tween(cc.wa_colorg, lt, 128), b: tween(cc.wa_colorb, lt, 128), a: clamp(tween(cc.wa_see, lt, 128), 0, 128) / 128 });
      }
      rings.push({ div: o.div, rows });
    }
  }
  return { items, rings };
}

function fxBounds(sim) {
  const xs = [], ys = [], zs = [];
  for (let t = 0; t < sim.length; t += Math.max(1, Math.floor(sim.length / 24))) {
    const fr = effectFrame(sim, t);
    for (const i of fr.items) { xs.push(i.x); ys.push(i.y); zs.push(i.z); }
    for (const r of fr.rings) for (const row of r.rows) { xs.push(row.rx, -row.rx); zs.push(row.ry, -row.ry); ys.push(-row.h); }
  }
  const pct = (a, p) => { if (!a.length) return 0; a.sort((x, y) => x - y); return a[Math.floor(clamp(p, 0, 1) * (a.length - 1))]; };
  const lo = [pct(xs, .02), pct(ys, .02), pct(zs, .02)], hi = [pct(xs, .98), pct(ys, .98), pct(zs, .98)];
  const c = lo.map((v, i) => (v + hi[i]) / 2), r = Math.max(400, Math.hypot(hi[0] - lo[0], hi[1] - lo[1], hi[2] - lo[2]) / 2);
  return { c, r };
}

function drawEffect() {
  fx.dirty = false;
  const cv = $("fxCanvas");
  if (!fx.sim || !views.fx.classList.contains("on")) return;
  const dpr = window.devicePixelRatio || 1, w = Math.max(1, Math.floor(cv.clientWidth * dpr)), h = Math.max(1, Math.floor(cv.clientHeight * dpr));
  if (cv.width !== w || cv.height !== h) { cv.width = w; cv.height = h; }
  const g = cv.getContext("2d");
  g.setTransform(1, 0, 0, 1, 0, 0); g.clearRect(0, 0, w, h);
  const cam = fx.cam, cy = Math.cos(cam.yaw), sy = Math.sin(cam.yaw), cp = Math.cos(cam.pitch), sp = Math.sin(cam.pitch), focal = h * 0.9;
  const proj = (x, y, z) => {
    x -= cam.cx; y -= cam.cy; z -= cam.cz;
    const x1 = x * cy + z * sy, z1 = -x * sy + z * cy, y2 = y * cp - z1 * sp, z2 = y * sp + z1 * cp, d = cam.dist + z2;
    return d > 10 ? { x: w / 2 + x1 * focal / d, y: h / 2 - y2 * focal / d, d } : null;
  };
  // ground circle and axes for orientation
  g.lineWidth = 1; g.strokeStyle = "rgba(255,255,255,0.12)";
  g.beginPath();
  for (let i = 0; i <= 48; i++) { const a = i / 48 * Math.PI * 2, p = proj(Math.cos(a) * cam.r, 0, Math.sin(a) * cam.r); if (p) i ? g.lineTo(p.x, p.y) : g.moveTo(p.x, p.y); }
  g.stroke();
  const fr = effectFrame(fx.sim, fx.t);
  g.globalCompositeOperation = "lighter";
  for (const ring of fr.rings) {
    for (let c = 0; c < ring.rows.length; c++) {
      const row = ring.rows[c];
      if (row.a <= 0.01) continue;
      g.strokeStyle = `rgba(${row.r | 0},${row.g | 0},${row.b | 0},${Math.min(1, row.a)})`; g.lineWidth = 1.5 * dpr;
      g.beginPath();
      for (let i = 0; i <= ring.div; i++) { const a = i / ring.div * Math.PI * 2, p = proj(row.rx * Math.cos(a), -row.h, row.ry * Math.sin(a)); if (p) i ? g.lineTo(p.x, p.y) : g.moveTo(p.x, p.y); }
      g.stroke();
      if (c + 1 < ring.rows.length) {
        const nx = ring.rows[c + 1];
        g.fillStyle = `rgba(${row.r | 0},${row.g | 0},${row.b | 0},${Math.min(1, row.a) * 0.18})`;
        for (let i = 0; i < ring.div; i++) {
          const a0 = i / ring.div * Math.PI * 2, a1 = (i + 1) / ring.div * Math.PI * 2;
          const q = [proj(row.rx * Math.cos(a0), -row.h, row.ry * Math.sin(a0)), proj(row.rx * Math.cos(a1), -row.h, row.ry * Math.sin(a1)), proj(nx.rx * Math.cos(a1), -nx.h, nx.ry * Math.sin(a1)), proj(nx.rx * Math.cos(a0), -nx.h, nx.ry * Math.sin(a0))];
          if (q.some(p => !p)) continue;
          g.beginPath(); g.moveTo(q[0].x, q[0].y); g.lineTo(q[1].x, q[1].y); g.lineTo(q[2].x, q[2].y); g.lineTo(q[3].x, q[3].y); g.closePath(); g.fill();
        }
      }
    }
  }
  const pr = fr.items.map(i => ({ i, p: proj(i.x, i.y, i.z) })).filter(e => e.p).sort((a, b) => b.p.d - a.p.d);
  for (const { i, p } of pr) {
    const rad = Math.max(1.5 * dpr, i.size * 40 * focal / p.d * 0.5);
    const grad = g.createRadialGradient(p.x, p.y, 0, p.x, p.y, rad);
    grad.addColorStop(0, `rgba(${i.r | 0},${i.g | 0},${i.b | 0},${i.a})`); grad.addColorStop(1, `rgba(${i.r | 0},${i.g | 0},${i.b | 0},0)`);
    g.fillStyle = grad; g.beginPath(); g.arc(p.x, p.y, rad, 0, Math.PI * 2); g.fill();
  }
  g.globalCompositeOperation = "source-over";
}
function requestFx() { if (fx.dirty) return; fx.dirty = true; requestAnimationFrame(drawEffect); }

(function bindFxCamera() {
  const cv = $("fxCanvas");
  let down = false, lx = 0, ly = 0;
  cv.addEventListener("pointerdown", e => { down = true; lx = e.clientX; ly = e.clientY; cv.setPointerCapture(e.pointerId); });
  cv.addEventListener("pointermove", e => { if (!down) return; fx.cam.yaw += (e.clientX - lx) * 0.01; fx.cam.pitch = clamp(fx.cam.pitch + (e.clientY - ly) * 0.01, -1.5, 1.5); lx = e.clientX; ly = e.clientY; requestFx(); });
  cv.addEventListener("pointerup", () => { down = false; }); cv.addEventListener("pointercancel", () => { down = false; });
  cv.addEventListener("wheel", e => { e.preventDefault(); fx.cam.dist = clamp(fx.cam.dist * Math.exp(e.deltaY * 0.001), fx.cam.r * 0.5, fx.cam.r * 20); requestFx(); }, { passive: false });
  new ResizeObserver(requestFx).observe(cv);
})();

function setFxTime(t) {
  fx.t = clamp(Math.round(t), 0, fx.sim.length);
  const s = $("fxSlider"); if (s) s.value = fx.t;
  const l = $("fxLabel"); if (l) l.textContent = fx.t + " / " + fx.sim.length;
  requestFx();
}

// One effect (.efb): preview plus its script
function showEffect(name, data, ctx, rawAsset, packInfo) {
  const cmds = L.efbCommands(data), objs = L.efbObjects(cmds), sim = buildEffectSim(objs);
  fx.sim = sim;
  const b = fxBounds(sim);
  Object.assign(fx.cam, { cx: b.c[0], cy: b.c[1], cz: b.c[2], r: b.r, dist: b.r * 3, yaw: 0.6, pitch: 0.35 });
  $("fxScript").textContent = L.efbListing(cmds);
  showView("fx");
  stopFx();
  const play = btn("Play", () => {
    if (fx.raf) { stopFx(); return; }
    play.textContent = "Pause"; fx.last = 0;
    const step = t => {
      if (t - fx.last >= 33) { fx.last = t; setFxTime(fx.t + 1 > fx.sim.length ? 0 : fx.t + 1); }
      fx.raf = requestAnimationFrame(step);
    };
    fx.raf = requestAnimationFrame(step);
  });
  play.id = "fxPlay";
  const slider = document.createElement("input"); slider.type = "range"; slider.id = "fxSlider"; slider.min = 0; slider.max = sim.length; slider.value = 0; slider.setAttribute("aria-label", "Frame");
  slider.oninput = () => { stopFx(); setFxTime(+slider.value); };
  const label = document.createElement("span"); label.id = "fxLabel"; label.className = "label";
  const hint = document.createElement("span"); hint.className = "label"; hint.textContent = "Approximate preview. Drag to rotate, wheel to zoom";
  const tools = [hint, play, slider, label];
  if (packInfo) tools.unshift(btn("Back to pack", () => showEffectPack(packInfo.name, packInfo.data, packInfo.ctx, packInfo.rawAsset)));
  setToolbar(tools);
  const counts = { particle: 0, model: 0, aqua: 0 }; for (const o of objs) counts[o.kind]++;
  const base = packInfo ? [["Name", baseName(name)], ["In pack", baseName(packInfo.name)], ["Size", fmtSize(data.length)]] : ctx.base;
  setMeta([...base, ["Type", "effect"], ["Objects", objs.length], ["Particle emitters", counts.particle], ["Ring models", counts.model], ["Length", sim.length + " frames"]]);
  const stem = stripExt(baseName(name));
  setSave({ ...(packInfo ? { raw: async () => data, name: baseName(name) } : rawAsset), convLabel: "Save script (text)", converted: () => ({ name: stem + ".txt", type: "text/plain", bytes: new TextEncoder().encode(L.efbListing(cmds)) }) });
  // open on the busiest frame so something is visible straight away
  let best = 0, bestScore = -1;
  for (let t = 0; t <= sim.length; t += 2) {
    const f = effectFrame(sim, t);
    const score = f.items.length + 10 * f.rings.reduce((a, r) => a + r.rows.filter(w => w.a > 0.05 && (w.rx > 1 || w.ry > 1)).length, 0);
    if (score > bestScore) { bestScore = score; best = t; }
  }
  setFxTime(best);
}

// A pack (.efp): its effects and texture sets
function showEffectPack(name, data, ctx, rawAsset) {
  const ents = L.efpEntries(data), stem = stripExt(baseName(name));
  const info = ents.map(e => {
    const d = data.subarray(e.off, e.off + e.size);
    if (!e.name.toLowerCase().endsWith(".efb")) return { e, d, type: "texture set", note: "" };
    try { const objs = L.efbObjects(L.efbCommands(d)); return { e, d, type: "effect", note: objs.filter(o => o.kind === "particle").length + " particle, " + objs.filter(o => o.kind === "model").length + " ring" }; }
    catch (err) { return { e, d, type: "effect", note: "unreadable" }; }
  });
  const box = $("listBox");
  box.replaceChildren();
  box.appendChild(table(["#", "Name", "Type", "Bytes", "Objects"], info.map((x, i) => [i, x.e.name, x.type, x.e.size.toLocaleString(), x.note]), (i, tr) => {
    if (tr) {
      const x = info[i];
      const packInfo = { name, data, ctx, rawAsset };
      try {
        if (x.type === "effect") showEffect(x.e.name, x.d, ctx, rawAsset, packInfo);
        else {
          const sets = L.findTextureSets(x.d, false);
          if (!sets.length) throw new Error("not a texture set");
          showTextures(x.e.name, sets, { ...ctx, base: [["Name", x.e.name], ["In pack", baseName(name)], ["Size", fmtSize(x.d.length)]] }, { raw: async () => x.d, name: x.e.name });
          setToolbar([btn("Back to pack", () => showEffectPack(name, data, ctx, rawAsset)), ...$("toolbar").children]);
        }
      } catch (err) { setStatus("Cannot open " + x.e.name + ": " + err.message, true); }
    }
    return true;
  }));
  showView("list");
  setToolbar([]);
  setMeta([...ctx.base, ["Type", "effect pack"], ["Entries", ents.length], ["Effects", info.filter(x => x.type === "effect").length], ["Texture sets", info.filter(x => x.type !== "effect").length]]);
  setSave({
    ...rawAsset, convLabel: "Save unpacked entries (zip)",
    converted: () => {
      const enc = new TextEncoder(), files = [];
      for (const x of info) {
        files.push({ name: x.e.name, data: x.d });
        if (x.type === "effect") { try { files.push({ name: stripExt(x.e.name) + ".txt", data: enc.encode(L.efbListing(L.efbCommands(x.d))) }); } catch (err) { /* unreadable */ } }
      }
      return { name: stem + "_unpacked.zip", type: "application/zip", bytes: makeZip(files) };
    },
  });
}

// ---------------------------------------------------------------- save buttons

async function runSave(kind, button) {
  const a = state.asset;
  if (!a) return;
  const label = button.textContent;
  button.disabled = true; button.textContent = "Working…";
  try {
    if (kind === "raw") download(a.name, await a.raw());
    else { const r = await a.converted(); download(r.name, r.bytes, r.type); }
  } catch (e) { setStatus("Save failed: " + e.message, true); }
  button.disabled = false; button.textContent = label;
}
$("saveRaw").onclick = e => runSave("raw", e.currentTarget);
$("saveConv").onclick = e => runSave("conv", e.currentTarget);

// ---------------------------------------------------------------- extract everything

const dlg = $("extractDlg");
let extractRun = null;

function openExtract() {
  $("exFilterN").textContent = "(" + state.list.length.toLocaleString() + " files)";
  $("exProg").hidden = true; $("exWarn").hidden = true; $("exGo").disabled = false;
  $("exCancel").textContent = "Close";
  if (!window.showDirectoryPicker) {
    $("exWarn").hidden = false;
    $("exWarn").textContent = "Writing a whole folder needs a Chromium browser (Chrome, Edge, Brave). You can still save single files with the buttons next to the preview.";
    $("exGo").disabled = true;
  }
  dlg.showModal();
}

async function getDir(root, parts, cache) {
  let h = root, key = "";
  for (const p of parts) {
    key += "/" + p;
    if (!cache.has(key)) cache.set(key, await h.getDirectoryHandle(p, { create: true }));
    h = cache.get(key);
  }
  return h;
}
async function writeOut(root, cache, parts, data) {
  const dir = await getDir(root, parts.slice(0, -1), cache);
  const fh = await dir.getFileHandle(parts[parts.length - 1], { create: true });
  const w = await fh.createWritable();
  await w.write(data);
  await w.close();
}
async function streamRaw(root, cache, parts, entry) {
  const dir = await getDir(root, parts.slice(0, -1), cache);
  const fh = await dir.getFileHandle(parts[parts.length - 1], { create: true });
  const w = await fh.createWritable();
  const CH = 4096;
  for (let s = 0; s < entry.sectors; s += CH) await w.write(await state.disc.readSectors(entry.start + s, Math.min(CH, entry.sectors - s)));
  await w.close();
}

async function extractAll() {
  const opts = { raw: $("exRaw").checked, conv: $("exConv").checked, lzs: $("exLzs").checked, filter: $("exFilter").checked };
  if (!opts.raw && !opts.conv && !opts.lzs) { $("exWarn").hidden = false; $("exWarn").textContent = "Tick at least one thing to extract."; return; }
  let root;
  try { root = await window.showDirectoryPicker({ mode: "readwrite" }); }
  catch (e) { return; }   // cancelled
  const list = opts.filter ? state.list.slice() : state.files.slice();
  const totalBytes = list.reduce((a, f) => a + f.bytes, 0) || 1;
  const run = { cancel: false };
  extractRun = run;
  $("exWarn").hidden = true; $("exProg").hidden = false; $("exGo").disabled = true; $("exCancel").textContent = "Cancel";
  const cache = new Map(), log = [];
  let done = 0, doneBytes = 0, converted = 0;
  const tick = (name) => {
    $("exBar").style.width = (100 * doneBytes / totalBytes).toFixed(1) + "%";
    $("exText").textContent = done.toLocaleString() + " of " + list.length.toLocaleString() + " files, " + fmtSize(doneBytes) + " of " + fmtSize(totalBytes) + (name ? " · " + name : "");
  };
  tick("");
  for (const f of list) {
    if (run.cancel) break;
    const parts = safeParts(f.path), noExt = safeParts(stripExt(f.path));
    try {
      const wantsData = (opts.conv && (f.kind === "model" || f.kind === "audio" || f.kind === "effect" || f.ext === "tms" || f.ext === "dat" || f.ext === "pac")) || (opts.lzs && f.ext === "lzs");
      let data = null;
      if (wantsData) data = await state.disc.readFile(f);
      if (opts.raw) { if (data) await writeOut(root, cache, ["raw", ...parts], data); else await streamRaw(root, cache, ["raw", ...parts], f); }
      if (data) {
        if (opts.conv && f.kind === "model") {
          const enc = new TextEncoder(), stemP = noExt[noExt.length - 1], dirP = ["converted", ...noExt.slice(0, -1)];
          const models = L.parseModels(data);
          let textures = null;
          const sib = state.byPath.get(stripExt(f.path) + ".tms");
          if (sib) { try { const sets = L.findTextureSets(await state.disc.readFile(sib), false); if (sets.length) textures = sets[0].textures; } catch (e) { /* untextured */ } }
          if (textures) {
            L.bindTextures(models, textures);
            // the PNGs are written next to it by the texture pass: <stem>_textures/NN.png
            const names = textures.map((t, i) => stemP + "_textures/" + String(i).padStart(2, "0") + ".png");
            await writeOut(root, cache, [...dirP, stemP + ".obj"], enc.encode(L.modelsToObj(models, "model", textures, stemP + ".mtl")));
            await writeOut(root, cache, [...dirP, stemP + ".mtl"], enc.encode(L.modelMtl(names)));
          } else await writeOut(root, cache, [...dirP, stemP + ".obj"], enc.encode(L.modelsToObj(models, "model")));
          converted++;
        } else if (opts.conv && f.ext === "efp") {
          // every entry of the pack, plus a text listing next to each effect
          const enc = new TextEncoder(), dirE = ["converted", ...noExt];
          for (const e of L.efpEntries(data)) {
            const d = data.subarray(e.off, e.off + e.size);
            await writeOut(root, cache, [...dirE, ...safeParts(e.name)], d);
            if (e.name.toLowerCase().endsWith(".efb")) { try { await writeOut(root, cache, [...dirE, ...safeParts(stripExt(e.name) + ".txt")], enc.encode(L.efbListing(L.efbCommands(d)))); } catch (err) { log.push(f.path + "/" + e.name + ": " + err.message); } }
          }
          converted++;
        } else if (opts.conv && f.ext === "efb") {
          await writeOut(root, cache, ["converted", ...noExt.slice(0, -1), noExt[noExt.length - 1] + ".txt"], new TextEncoder().encode(L.efbListing(L.efbCommands(data)))); converted++;
        } else if (opts.conv && f.kind === "audio") {
          const { rate, channels } = L.decodeInt(data);
          await writeOut(root, cache, ["converted", ...noExt.slice(0, -1), noExt[noExt.length - 1] + ".wav"], L.encodeWav(channels, rate)); converted++;
        } else if (opts.conv && (f.ext === "tms" || f.ext === "dat" || f.ext === "pac")) {
          const sets = L.findTextureSets(data, f.ext === "pac");
          if (sets.length) {
            const pngs = await texturesToPngs(sets);
            for (const p of pngs) await writeOut(root, cache, ["converted", ...noExt.slice(0, -1), noExt[noExt.length - 1] + "_textures", p.name], p.data);
            converted++;
          }
        }
        if (opts.lzs && f.ext === "lzs") {
          if (L.lzsIsArchive(data)) for (const m of L.lzsMembers(data)) await writeOut(root, cache, ["unpacked", ...noExt, ...safeParts(m.path)], m.read());
          else await writeOut(root, cache, ["unpacked", ...noExt.slice(0, -1), noExt[noExt.length - 1] + ".pac"], L.lzsDecompress(data).data);
        }
      }
    } catch (e) { log.push(f.path + ": " + e.message); }
    done++; doneBytes += f.bytes;
    if (done % 8 === 0 || f.bytes > 4e6) { tick(baseName(f.path)); await new Promise(r => setTimeout(r)); }
  }
  tick("");
  if (log.length) { try { await writeOut(root, cache, ["extract-log.txt"], new TextEncoder().encode(log.join("\n") + "\n")); } catch (e) { /* ignore */ } }
  extractRun = null;
  $("exGo").disabled = false; $("exCancel").textContent = "Close";
  $("exText").textContent = (run.cancel ? "Cancelled after " : "Done: ") + done.toLocaleString() + " files" + (opts.conv ? ", " + converted.toLocaleString() + " converted" : "") + (log.length ? ", " + log.length + " could not be converted (see extract-log.txt)" : "") + ".";
}
// Esc must not hide the dialog (and its Cancel button) while a run is going
dlg.addEventListener("cancel", e => { if (extractRun) e.preventDefault(); });
$("extractBtn").onclick = openExtract;
$("exGo").onclick = extractAll;
$("exCancel").onclick = () => { if (extractRun) { extractRun.cancel = true; $("exText").textContent = "Stopping…"; } else dlg.close(); };

// ---------------------------------------------------------------- loading a disc

async function loadSource(source, label) {
  state.token++;
  setStatus("Reading the file table…");
  try {
    const disc = await L.openDisc(source);
    state.disc = disc; state.skelCache = new Map();
    state.files = disc.files.map(f => { const ext = L.extOf(f.path); return { ...f, ext, kind: L.kindOf(f.path), lower: f.path.toLowerCase() }; });
    state.byPath = new Map(state.files.map(f => [f.path, f]));
    state.tab = "all"; state.query = "";
    $("search").value = ""; $("search").disabled = false; $("extractBtn").disabled = false;
    for (const x of $("tabs").querySelectorAll("button[data-tab]")) { const on = x.dataset.tab === "all"; x.classList.toggle("selected", on); x.setAttribute("aria-selected", on); }
    for (const t in tabMatch) { const el = $("c-" + t); if (el) el.textContent = state.files.filter(tabMatch[t]).length.toLocaleString(); }
    refilter(null);
    setSave(null); setToolbar([]); setMeta([["Name", "-"], ["Type", "-"], ["Size", "-"]]);
    showView(null, { title: "NO ASSET SELECTED", text: "Pick a file from the list." });
    setStatus((label || "Disc") + ": " + state.files.length.toLocaleString() + " files found.");
  } catch (err) {
    console.error(err);
    state.disc = null;
    setStatus(err.message, true);
  }
}

$("openBtn").onclick = () => $("fileInput").click();
$("fileInput").onchange = e => { const f = e.target.files[0]; if (f) loadSource(f, f.name); e.target.value = ""; };
addEventListener("dragover", e => { e.preventDefault(); document.body.classList.add("dragover"); });
addEventListener("dragleave", e => { if (e.target === document.documentElement || !e.relatedTarget) document.body.classList.remove("dragover"); });
addEventListener("drop", e => { e.preventDefault(); document.body.classList.remove("dragover"); const f = e.dataTransfer.files[0]; if (f) loadSource(f, f.name); });

window.LegaiaViewer = { load: loadSource, state, snapshot() { draw(); return canvas; } };
})();
