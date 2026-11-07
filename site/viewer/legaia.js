// legaia.js: reads Legaia 2 (PAL, SLES-50891) data from a disc image the user supplies.
// A JavaScript port of the format tools in tools/ (fs_tool, lzss, pac_tool, tex_tool, tmd_tool, adpcm).
// Works in the browser and in Node. Nothing is uploaded: the disc is only read through `source`,
// any object with `size` and `slice(a, b).arrayBuffer()` (a File, a Blob, or a test double).
(function (root) {
"use strict";

const SECTOR = 2048;
const VOLUME_PARTS = ["FS.BIN", "FS1.BIN", "FS2.BIN"];

const u32 = (d, o) => (d[o] | d[o + 1] << 8 | d[o + 2] << 16 | d[o + 3] << 24) >>> 0;
const u16 = (d, o) => d[o] | d[o + 1] << 8;
const f32 = (() => { const b = new DataView(new ArrayBuffer(4)); return (d, o) => { b.setUint8(0, d[o]); b.setUint8(1, d[o + 1]); b.setUint8(2, d[o + 2]); b.setUint8(3, d[o + 3]); return b.getFloat32(0, true); }; })();
const text = (d, a, b) => { let s = ""; for (let i = a; i < b; i++) s += String.fromCharCode(d[i]); return s; };

// ---------------------------------------------------------------- disc

async function readBytes(source, offset, size) {
  return new Uint8Array(await source.slice(offset, offset + size).arrayBuffer());
}

function decryptDir(raw) {
  const d = new Uint8Array(raw);
  if (u32(d, 0) !== 2) throw new Error("FS.DIR: unexpected version");
  let key = Math.imul(0x6E6B7270, u16(d, 4) ^ u16(d, 6)) >>> 0;
  for (let off = 16; off + 4 <= d.length; off += 4) {
    const v = (u32(d, off) ^ key) >>> 0;
    d[off] = v & 255; d[off + 1] = v >>> 8 & 255; d[off + 2] = v >>> 16 & 255; d[off + 3] = v >>> 24;
    key = (Math.imul(key, 5) + 1) >>> 0;
  }
  return d;
}

// Returns [{path, start, sectors, bytes}]
function parseDir(d) {
  const nExt = u16(d, 4), table = u16(d, 6);
  const rev = (a, n) => { let s = ""; for (let i = n - 1; i >= 0; i--) if (d[a + i]) s += String.fromCharCode(d[a + i]); return s; };
  const exts = [];
  for (let i = 0; i < nExt; i++) exts.push(rev(16 + 4 * i, 4));
  const entries = [];
  for (let off = table; off + 16 <= d.length; off += 16)
    entries.push({ name: rev(off, 8), a: u16(d, off + 8), b: u16(d, off + 10), c: u32(d, off + 12) });
  const files = [];
  const walk = (i, path) => {
    const nSub = entries[i].a, nFiles = entries[i].b, below = entries[i].c;
    let j = i + 1;
    for (let k = 0; k < nFiles; k++, j++) {
      const e = entries[j], ext = exts[e.a];
      files.push({ path: path.concat(e.name).join("/") + (ext ? "." + ext : ""), start: e.c, sectors: e.b, bytes: e.b * SECTOR });
    }
    for (let k = 0; k < nSub; k++) j = walk(j, path.concat(entries[j].name));
    if (j - i - 1 !== below) throw new Error("FS.DIR: bad subtree size at entry " + i);
    return j;
  };
  walk(0, []);
  return files;
}

async function openDisc(source) {
  const pvd = await readBytes(source, 16 * SECTOR, SECTOR);
  if (text(pvd, 1, 6) !== "CD001") throw new Error("This is not an ISO 9660 disc image (2048-byte sectors).");
  const lba = u32(pvd, 156 + 2), size = u32(pvd, 156 + 10);
  const dir = await readBytes(source, lba * SECTOR, size);
  const root = {};
  for (let pos = 0; pos < dir.length;) {
    const len = dir[pos];
    if (!len) { pos = (Math.floor(pos / SECTOR) + 1) * SECTOR; continue; }
    const nameLen = dir[pos + 32];
    const name = text(dir, pos + 33, pos + 33 + nameLen).split(";")[0].toUpperCase();
    root[name] = { lba: u32(dir, pos + 2), size: u32(dir, pos + 10) };
    pos += len;
  }
  for (const n of ["FS.DIR", ...VOLUME_PARTS])
    if (!root[n]) throw new Error("Not a Legaia 2 disc: " + n + " is missing.");
  const files = parseDir(decryptDir(await readBytes(source, root["FS.DIR"].lba * SECTOR, root["FS.DIR"].size)));
  const parts = [];
  let first = 0;
  for (const n of VOLUME_PARTS) {
    const sectors = Math.floor(root[n].size / SECTOR);
    parts.push({ first, sectors, lba: root[n].lba });
    first += sectors;
  }
  const disc = {
    files,
    volumeSectors: first,
    async readSectors(start, count) {
      const out = new Uint8Array(count * SECTOR);
      let at = 0;
      while (count > 0) {
        const p = parts.find(q => q.first <= start && start < q.first + q.sectors);
        if (!p) throw new Error("sector " + start + " is outside the volume");
        const take = Math.min(count, p.first + p.sectors - start);
        out.set(await readBytes(source, (p.lba + start - p.first) * SECTOR, take * SECTOR), at);
        at += take * SECTOR; start += take; count -= take;
      }
      return out;
    },
    readFile(entry) { return disc.readSectors(entry.start, entry.sectors); },
    // First `bytes` bytes only (for peeking at headers of huge files)
    readHead(entry, bytes) { return disc.readSectors(entry.start, Math.min(entry.sectors, Math.ceil(bytes / SECTOR))); },
  };
  return disc;
}

// ---------------------------------------------------------------- lzs / pac

// Returns {data, end}
function lzsDecompress(data, start = 0) {
  const size = u32(data, start);
  if (size > 0x20000000) throw new Error("not a compressed file (size field " + size + ")");
  const out = new Uint8Array(size);
  let pos = start + 4, o = 0, r = 0xFEE, flags = 0;
  while (o < size) {
    flags >>= 1;
    if (!(flags & 0x100)) flags = data[pos++] | 0xFF00;
    if (flags & 1) {
      out[o++] = data[pos++];
      r = (r + 1) & 0xFFF;
    } else {
      const b0 = data[pos], b1 = data[pos + 1];
      pos += 2;
      const n = (b1 & 0xF) + 3;
      let src = o + ((((b0 | (b1 & 0xF0) << 4) - r) & 0xFFF)) - 0x1000;
      r = (r + n) & 0xFFF;
      const stop = Math.min(n, size - o);
      for (let k = 0; k < stop; k++) { out[o++] = src >= 0 ? out[src] : 0; src++; }
    }
  }
  return { data: out, end: pos };
}

const lzsIsArchive = d => u32(d, 0) === 0 && u32(d, 4) === 0;

// Members of an archive .lzs, decompressed lazily: [{path, read()}]
function lzsMembers(data) {
  const count = u32(data, 8), out = [];
  for (let i = 0; i < count; i++) {
    const off = u32(data, 16 + 36 * i);
    let path = text(data, 20 + 36 * i, 52 + 36 * i);
    path = path.split("\0")[0];
    out.push({ path, read: () => lzsDecompress(data, off).data });
  }
  return out;
}

const PAC_TYPES = { 0x01: "texture", 0x02: "model_info", 0x03: "model_packet", 0x04: "map_data", 0x05: "texture", 0x07: "objects", 0x08: "name_table", 0x09: "map_data2", 0x0A: "map_object", 0x0D: "name_table", 0x1E: "textures", 0x1F: "textures", 0x20: "effects", 0x28: "textures", 0x46: "model_extra", 0x47: "model_extra" };

// [{type, name, offset (data start), size}]
function pacChunks(data) {
  const out = [];
  let off = 0;
  while (off + 4 <= data.length) {
    const word = u32(data, off), size = word & 0xFFFFFF;
    if (size === 0) return out;
    const header = word & 0x80000000 ? 0x80 : 0x10, type = word >>> 24 & 0x7F;
    if (off + header + size > data.length) return out;
    out.push({ type, name: PAC_TYPES[type] || "unknown", offset: off + header, size });
    off += header + size;
  }
  return out;
}

// ---------------------------------------------------------------- textures

const TEX_FORMATS = { 0: ["4-bit", 4], 1: ["8-bit", 8], 2: ["16-bit", 16], 3: ["32-bit", 32] };
const gsAlpha = a => Math.min(255, a * 2);
const csm1 = i => (i & ~0x18) | ((i & 0x08) << 1) | ((i & 0x10) >> 1);

function parseTexture(data, off) {
  if (off + 0x20 > data.length) throw new Error("texture header out of range");
  const kind = u16(data, off), flags = data[off + 2], fmt = data[off + 3];
  if ((kind !== 0x41 && kind !== 0x42) || !(fmt in TEX_FORMATS)) throw new Error("not a texture header at " + off);
  const header = kind === 0x41 ? 0x20 : 0x80;
  const t = { off, flags, fmt, formatName: TEX_FORMATS[fmt][0], header };
  t.clutW = u16(data, off + 0x14); t.clutH = u16(data, off + 0x16);
  t.x = u16(data, off + 0x18); t.y = u16(data, off + 0x1A);
  t.clutPos = u16(data, off + 0x12);
  t.height = u16(data, off + 0x1E);
  t.width = u16(data, off + 0x1C) * (fmt === 0 ? 4 : fmt === 1 ? 2 : 1);
  t.pixOff = off + u32(data, off + 4) * 4;
  t.clutOff = flags & 1 ? off + header : null;
  const bytes = t.width * t.height * TEX_FORMATS[fmt][1] / 8;
  if (t.pixOff + bytes > data.length) throw new Error("pixel data runs past the end");
  t.data = data;
  return t;
}

// RGBA bytes (Uint8ClampedArray) for a parsed texture
function textureRGBA(t) {
  const d = t.data, n = t.width * t.height, out = new Uint8ClampedArray(n * 4);
  const rgba32 = (o, dst) => { out[dst] = d[o]; out[dst + 1] = d[o + 1]; out[dst + 2] = d[o + 2]; out[dst + 3] = gsAlpha(d[o + 3]); };
  if (t.fmt <= 1) {
    const pal = new Uint8ClampedArray(256 * 4);
    if (t.clutOff !== null) {
      const cnt = Math.min(256, t.clutW * t.clutH);
      for (let i = 0; i < cnt; i++) {
        const slot = t.fmt === 1 && cnt === 256 ? csm1(i) : i;
        const o = t.clutOff + slot * 4;
        pal[i * 4] = d[o]; pal[i * 4 + 1] = d[o + 1]; pal[i * 4 + 2] = d[o + 2]; pal[i * 4 + 3] = gsAlpha(d[o + 3]);
      }
      // entries past the palette stay transparent black, as in tex_tool.py
    } else {
      for (let i = 0; i < 256; i++) { pal[i * 4] = pal[i * 4 + 1] = pal[i * 4 + 2] = i; pal[i * 4 + 3] = 255; }
    }
    for (let i = 0; i < n; i++) {
      const idx = t.fmt === 1 ? d[t.pixOff + i] : (d[t.pixOff + (i >> 1)] >> (i & 1 ? 4 : 0)) & 15;
      out[i * 4] = pal[idx * 4]; out[i * 4 + 1] = pal[idx * 4 + 1]; out[i * 4 + 2] = pal[idx * 4 + 2]; out[i * 4 + 3] = pal[idx * 4 + 3];
    }
  } else if (t.fmt === 2) {
    for (let i = 0; i < n; i++) {
      const v = u16(d, t.pixOff + i * 2);
      out[i * 4] = (v & 0x1F) << 3; out[i * 4 + 1] = (v >> 5 & 0x1F) << 3; out[i * 4 + 2] = (v >> 10 & 0x1F) << 3;
      out[i * 4 + 3] = v === 0 ? 0 : 255;
    }
  } else {
    for (let i = 0; i < n; i++) rgba32(t.pixOff + i * 4, i * 4);
  }
  return out;
}

// All textures of a container at `base` (u32 count, then offsets in words)
function parseTextureSet(data, base = 0) {
  const count = u32(data, base);
  if (!(count > 0 && count < 4096)) throw new Error("implausible texture count " + count);
  const out = [];
  for (let i = 0; i < count; i++) out.push(parseTexture(data, base + u32(data, base + 4 + 4 * i) * 4));
  return out;
}

// Texture sets in a file: .pac -> one per texture chunk (types 1 and 5), else one at offset 0.
// Returns [{label, textures}]; [] when the file is not a texture set.
function findTextureSets(data, isPac) {
  const sets = [];
  try {
    if (isPac) {
      pacChunks(data).filter(c => c.type === 1 || c.type === 5).forEach((c, k) => {
        try { sets.push({ label: "chunk " + k, textures: parseTextureSet(data, c.offset) }); } catch (e) { /* skip */ }
      });
    } else {
      sets.push({ label: "", textures: parseTextureSet(data, 0) });
    }
  } catch (e) { return []; }
  return sets;
}

// ---------------------------------------------------------------- models

const PART_SIZE = 0xA0;

function parsePart(d, base, k) {
  const h = base + PART_SIZE * k;
  const flags = u32(d, h + 0x10);
  const ov = u32(d, h + 0x14), on = u32(d, h + 0x18), op = u32(d, h + 0x1C);
  let name = "";
  { let ok = d[h + 0x70] !== 0; for (let i = 0; i < 16 && d[h + 0x70 + i]; i++) { if (d[h + 0x70 + i] < 32 || d[h + 0x70 + i] > 126) ok = false; name += String.fromCharCode(d[h + 0x70 + i]); } if (!ok) name = "part_" + k; }
  const nv = u16(d, h + 0x40), nn = u16(d, h + 0x42), ntri = u16(d, h + 0x44);
  if (base + ov + 16 * nv > d.length || base + on + 16 * nn > d.length) throw new Error("part " + k + ": arrays out of range");
  const pos = new Float32Array(nv * 3), nrm = new Float32Array(Math.max(nn, 1) * 3);
  for (let i = 0; i < nv; i++) for (let c = 0; c < 3; c++) pos[i * 3 + c] = f32(d, base + ov + 16 * i + 4 * c);
  for (let i = 0; i < nn; i++) for (let c = 0; c < 3; c++) nrm[i * 3 + c] = f32(d, base + on + 16 * i + 4 * c);
  // Skinning: a skinned part (flag 0x80) has a weight table, u32 slot count then per vertex
  // u8 slot a, u8 weight a, u8 slot b, u8 weight b (percent). Other parts use one slot, or none with flag 0x01.
  let slots = flags & 1 ? 0 : 1, weights = null;
  if (flags & 0x80) {
    const wt = base + u32(d, h + 0x64);
    if (wt + 4 + 4 * nv > d.length) throw new Error("part " + k + ": weight table out of range");
    slots = u32(d, wt);
    weights = new Uint8Array(nv * 4);
    for (let i = 0; i < nv; i++) {
      for (let c = 0; c < 4; c++) weights[i * 4 + c] = d[wt + 4 + 4 * i + c];
      if (Math.max(weights[i * 4], weights[i * 4 + 2]) >= slots) throw new Error("part " + k + ": bad weight entry " + i);
    }
  }
  const tris = []; // flat: per corner vertex, normal, u, v, rgba
  let sec = base + op, total = 0;
  while (total < ntri) {
    if (sec + 8 > d.length) throw new Error("part " + k + ": primitives out of range");
    const count = u16(d, sec), words = u32(d, sec + 4), end = sec + 8 + words * 4;
    let p = sec + 8, found = 0;
    while (p + 8 <= end) {
      const n = u32(d, p + 4) & 0xFFFF;
      p += 8;
      if (n === 0 || p + 16 * n > end) break;
      const strip = [], gtex = d[p + 3], gfl = u32(d, p);   // the flags of a group's first record name its texture (see bindTextures)
      for (let i = 0; i < n; i++) {
        const o = p + 16 * i, vo = u16(d, o + 12), no = u16(d, o + 14);
        if (vo % 16 || (vo / 16) >= nv) throw new Error("part " + k + ": vertex offset out of range");
        strip.push({ tex: gtex, fl: gfl, flag: u32(d, o) & 1, v: vo / 16, n: nn ? no / 16 : 0, u: u16(d, o + 8), w: u16(d, o + 10), c: [d[o + 4], d[o + 5], d[o + 6], d[o + 7]] });
      }
      p += 16 * n;
      // The GS ADC bit that suppresses the triangle ending at record i is stored on record i + 1, so a restart
      // inside a group (two flagged records) does not leave a triangle joining the end of one strip to the next.
      for (let i = 2; i < n; i++) {
        if (!(i + 1 < n && strip[i + 1].flag)) {
          const a = strip[i - 2], b = strip[i - 1], c = strip[i];
          tris.push(...(i % 2 === 0 ? [a, b, c] : [b, a, c]));
          found++;
        }
      }
    }
    if (found !== count) throw new Error("part " + k + ": " + found + " triangles, header says " + count);
    total += count;
    sec = end;
  }
  // flatten into non-indexed buffers (y and z flipped: PS2 data is y-down). Triangles are grouped by
  // texture so each texture is one draw call; `corners` keeps the file order for OBJ export.
  const order = [];
  for (let t = 0; t < tris.length / 3; t++) order.push(t);
  order.sort((a, b) => tris[a * 3].fl - tris[b * 3].fl || a - b);
  const VI = new Int32Array(tris.length), NI = new Int32Array(tris.length);
  const m = tris.length, P = new Float32Array(m * 3), N = new Float32Array(m * 3), C = new Float32Array(m * 3), UVPX = new Float32Array(m * 2), ranges = [];
  order.forEach((ti, slot) => {
    for (let c = 0; c < 3; c++) {
      const t = tris[ti * 3 + c], i = slot * 3 + c;
      P[i * 3] = pos[t.v * 3]; P[i * 3 + 1] = -pos[t.v * 3 + 1]; P[i * 3 + 2] = -pos[t.v * 3 + 2];
      N[i * 3] = nrm[t.n * 3]; N[i * 3 + 1] = -nrm[t.n * 3 + 1]; N[i * 3 + 2] = -nrm[t.n * 3 + 2];
      C[i * 3] = t.c[0] / 255; C[i * 3 + 1] = t.c[1] / 255; C[i * 3 + 2] = t.c[2] / 255;
      VI[i] = t.v; NI[i] = t.n;
      UVPX[i * 2] = t.u / 4; UVPX[i * 2 + 1] = t.w / 4;   // quarter texels, in the texture's VRAM page space
    }
    const fl = tris[ti * 3].fl, last = ranges[ranges.length - 1];
    if (last && last.fl === fl) last.count += 3; else ranges.push({ tex: fl >>> 24, fl, start: slot * 3, count: 3 });
  });
  return {
    name, flags, skinned: !!(flags & 0x80), vertexCount: nv, triangleCount: ntri,
    positions: P, normals: N, colors: C, uvPx: UVPX, ranges,
    slots, weights, vertexIndex: VI, normalIndex: NI,
    // unique vertex data, for OBJ export
    vertices: pos, normalsRaw: nrm, nn, corners: tris.map(t => [t.v, t.n, t.u, t.w, t.tex, t.fl]),
  };
}

// Which texture of `textures` a group's flags name. The flags' low 14 bits hold the texture's palette slot (its
// CLUT position, header +0x12, times 64), which is unique in nearly every set; the top byte is the texture's
// index and is the fallback (and breaks ties). Checked on every .tmd with a same-named .tms.
function textureForFlags(textures, fl) {
  const slot = (fl & 0x3FFF) >> 6, A = fl >>> 24, xpage = (fl >>> 16) & 0x7F;
  const cands = [];
  textures.forEach((t, i) => { if (t.clutOff !== null && t.clutPos === slot) cands.push(i); });
  if (cands.length === 1) return cands[0];
  if (cands.length > 1) return cands.includes(A) ? A : (cands.find(i => (textures[i].x >> 6) === xpage) ?? cands[0]);
  return A;
}

// Points every range and corner of the models at its texture (call once the .tms is known)
function bindTextures(models, textures) {
  if (!textures) return;
  for (const m of models) for (const p of m.parts) {
    const cache = new Map(), idx = fl => { if (!cache.has(fl)) cache.set(fl, textureForFlags(textures, fl)); return cache.get(fl); };
    for (const r of p.ranges) r.tex = idx(r.fl);
    for (const c of p.corners) c[4] = idx(c[5]);
  }
}

// UV of a texel position (quarter-texel units / 4) inside texture t: U is relative to the texture's
// column within its 64-unit VRAM page, V to its row.
function mapUV(t, uPx, vPx) {
  const ppu = t.fmt === 0 ? 4 : t.fmt === 1 ? 2 : 1;
  return [(uPx - (t.x & 63) * ppu) / t.width, (vPx - t.y) / t.height];
}

// Normalised texture coordinates for a part's render buffers; zero where the texture is missing
function modelUVs(part, textures) {
  const out = new Float32Array(part.uvPx.length);
  for (const r of part.ranges) {
    const t = textures && textures[r.tex];
    if (!t) continue;
    for (let i = r.start; i < r.start + r.count; i++) {
      const uv = mapUV(t, part.uvPx[i * 2], part.uvPx[i * 2 + 1]);
      out[i * 2] = uv[0]; out[i * 2 + 1] = uv[1];
    }
  }
  return out;
}

function parseModels(d) {
  const count = u32(d, 0);
  if (count === 0) throw new Error("This file contains no models.");
  if (!(count > 0 && count < 256)) throw new Error("implausible model count " + count);
  const models = [];
  for (let i = 0; i < count; i++) {
    const base = u32(d, 4 + 4 * i) * 4;
    if (base + 4 > d.length) throw new Error("model offset out of range");
    const m = { parts: [], bad: [] };
    const nParts = d[base + 3];
    for (let k = 0; k < nParts; k++) {
      try { m.parts.push(parsePart(d, base, k)); } catch (e) { m.bad.push({ part: k, error: e.message }); }
    }
    models.push(m);
  }
  return models;
}

// Wavefront OBJ. Without `textures` this matches tools/tmd_tool.py. With textures (and the .mtl name)
// it writes the mapped UVs and one `usemtl tex_N` per texture; see modelMtl.
function modelsToObj(models, label = "model", textures = null, mtlName = null) {
  const lines = ["# converted by legaia.js (port of tools/tmd_tool.py)"];
  if (textures && mtlName) lines.push("mtllib " + mtlName);
  let vb = 0, nb = 0, tb = 0;
  models.forEach((m, i) => m.parts.forEach(p => {
    lines.push("o " + label + "_" + i + "_" + p.name);
    for (let v = 0; v < p.vertexCount; v++) lines.push("v " + p.vertices[v * 3].toFixed(4) + " " + (-p.vertices[v * 3 + 1]).toFixed(4) + " " + (-p.vertices[v * 3 + 2]).toFixed(4));
    for (let v = 0; v < p.nn; v++) lines.push("vn " + p.normalsRaw[v * 3].toFixed(4) + " " + (-p.normalsRaw[v * 3 + 1]).toFixed(4) + " " + (-p.normalsRaw[v * 3 + 2]).toFixed(4));
    const uvs = new Map();
    const uvOf = ([, , u, w, tex]) => {
      const t = textures && textures[tex];
      if (!t) return [u / 1024, 1 - w / 1024];
      const m2 = mapUV(t, u / 4, w / 4);
      return [m2[0], 1 - m2[1]];
    };
    for (const c of p.corners) {
      const key = c[2] + "," + c[3] + "," + (textures ? c[4] : 0);
      if (!uvs.has(key)) { uvs.set(key, uvs.size); const uv = uvOf(c); lines.push("vt " + uv[0].toFixed(5) + " " + uv[1].toFixed(5)); }
    }
    let mat = -1;
    for (let t = 0; t < p.corners.length; t += 3) {
      if (textures && p.corners[t][4] !== mat) { mat = p.corners[t][4]; lines.push("usemtl tex_" + mat); }
      const refs = [0, 1, 2].map(c => { const [v, n, u, w, tex] = p.corners[t + c]; return (vb + v + 1) + "/" + (tb + uvs.get(u + "," + w + "," + (textures ? tex : 0)) + 1) + "/" + (nb + n + 1); });
      lines.push("f " + refs.join(" "));
    }
    vb += p.vertexCount; nb += p.nn; tb += uvs.size;
  }));
  return lines.join("\n") + "\n";
}

// .mtl for modelsToObj(..., textures): tex_N -> pngNames[N]
function modelMtl(pngNames) {
  return pngNames.map((n, i) => "newmtl tex_" + i + "\nKd 1 1 1\nmap_Kd " + n + "\nmap_d " + n + "\n").join("\n");
}

// ---------------------------------------------------------------- motions (.mov) and posing

const i32 = (d, o) => u32(d, o) | 0;
const s16 = (d, o) => (d[o] | d[o + 1] << 8) << 16 >> 16;

// One clip, packed layout (99.4% of the clips) or the old uncompressed one; null when it cannot be read.
// A port of tools/mov_tool.py, except that every channel is decoded: the bone record's mask word is not a
// channel mask (it is 1 on every bone seen) and ty, tz, rx, ry, rz are always present.
// Old uncompressed layout (flag 0x20 clear): 6 s16 per bone per frame, after the hierarchy and the index map
function decodeOldClip(data, start, end) {
  const c = data.subarray(start, end), nbones = c[0], flags = c[1], frames = u16(c, 2);
  if (!nbones || !frames || c.length < 8) return null;
  let base = 8, cname = "";
  const names = new Array(nbones).fill("");
  if (flags & 8) {
    base = 0x68 + 0x30 * c[7];
    for (let i = 8; i < 24 && c[i]; i++) cname += String.fromCharCode(c[i]);
    for (let b = 0; b < nbones; b++) { let n = ""; for (let i = 0; i < 16 && c[0x68 + 0x30 * b + i]; i++) n += String.fromCharCode(c[0x68 + 0x30 * b + i]); names[b] = n; }
  }
  const vstart = base + c[7] + c[5];
  if (vstart + frames * nbones * 12 > c.length) return null;
  const parent = new Map();
  if (c[7]) {
    let prev = null;
    for (let o = base; o < base + c[7]; o++) {
      const v = c[o];
      if (v === 0xFF) break;
      if (v !== 0 && !parent.has(v)) { if (prev === null) return null; parent.set(v, prev); }
      prev = v;
    }
    for (let b = 1; b <= nbones; b++) if (!parent.has(b)) return null;
  } else for (let b = 1; b <= nbones; b++) parent.set(b, 0);   // a few test clips have no hierarchy
  const bones = [];
  for (let b = 0; b < nbones; b++) {
    const t = [0, 1, 2].map(() => new Float32Array(frames)), r = [0, 1, 2].map(() => new Float32Array(frames));
    for (let f = 0; f < frames; f++) for (let k = 0; k < 6; k++) {
      const v = s16(c, vstart + 2 * ((f * nbones + b) * 6 + k));
      if (k < 3) t[k][f] = v; else r[k - 3][f] = v * 360 / 4096;
    }
    bones.push({ name: names[b], parent: parent.get(b + 1) ? parent.get(b + 1) - 1 : null, t, r });
  }
  const slotBones = Array.from(c.subarray(base + c[7], vstart));
  if (slotBones.some(b => b >= nbones)) return null;
  return { name: cname, frames, keyStep: 1, keys: frames, bones, slotBones };
}

function decodeClip(data, start, end) {
  if (end - start < 0x4C) return end - start >= 8 ? decodeOldClip(data, start, end) : null;
  const nbones = data[start], flags = data[start + 1], frames = u16(data, start + 2), shift = data[start + 4];
  if (!(flags & 0x20)) return decodeOldClip(data, start, end);
  if (!nbones) return null;
  const so = [];
  for (let i = 0; i < 7; i++) so.push(start + i32(data, start + 0x2C + 4 * i));
  if (so.some(x => x < 0 || x > data.length) || (so[3] - so[2]) / 24 !== nbones) return null;
  const nseg = (so[6] - so[5]) / 8, segs = [];
  let nvals = 0;
  for (let i = 0; i < nseg; i++) {
    const seg = { off: u32(data, so[5] + 8 * i), cnt: u16(data, so[5] + 8 * i + 4), mode: data[so[5] + 8 * i + 6] };
    segs.push(seg);
    nvals = Math.max(nvals, seg.off + (seg.mode === 1 ? 1 : seg.cnt));
  }
  if (so[6] + nvals * 2 > data.length) return null;
  const half = flags & 1, keys = half ? (frames >> 1) + 1 : frames, turn = flags & 0x80 ? 16384 : 4096;
  const channel = (first, scale) => {
    const out = new Float32Array(keys);
    let n = 0, i = first;
    while (n < keys) {
      const g = segs[i++];
      if (!g) throw new Error("segments overrun");
      for (let k = 0; k < g.cnt && n < keys; k++) out[n++] = s16(data, so[6] + 2 * (g.mode === 1 ? g.off : g.off + k)) * scale;
    }
    return out;
  };
  // hierarchy: bones numbered from 1; a value not seen before is a new bone whose parent is the previous value
  const parent = new Map();
  let prev = null;
  for (let o = so[0]; o < so[1]; o++) {
    const v = data[o];
    if (v === 0xFF) break;
    if (v !== 0 && !parent.has(v)) { if (prev === null) return null; parent.set(v, prev); }
    prev = v;
  }
  for (let b = 1; b <= nbones; b++) if (!parent.has(b)) return null;
  const bones = [], tScale = Math.pow(2, shift);
  for (let b = 0; b < nbones; b++) {
    const r = so[2] + 24 * b, first = k => u16(data, r + 6 + 2 * k);
    let name = "";
    for (let o = so[3] + u16(data, r); o < so[4] && data[o]; o++) name += String.fromCharCode(data[o]);
    bones.push({
      name, parent: parent.get(b + 1) ? parent.get(b + 1) - 1 : null,
      t: [0, 1, 2].map(k => channel(first(k), tScale)),
      r: [3, 4, 5].map(k => channel(first(k), 360 / turn)),   // degrees
    });
  }
  const slotBones = Array.from(data.subarray(so[1], so[1] + data[start + 5]));
  if (slotBones.some(b => b >= nbones)) return null;
  let cname = "";
  for (let i = 8; i < 24 && data[start + i]; i++) cname += String.fromCharCode(data[start + i]);
  return { name: cname, frames, keyStep: half ? 2 : 1, keys, bones, slotBones };
}

// All clips of a .mov file (or a decompressed .moz): [{name, frames, ...}] with null for clips that cannot be read
function parseMotions(data) {
  const count = u32(data, 0);
  if (!(count > 0 && count < 4096) || u32(data, 4) !== 4 + 4 * count) throw new Error("not a motion file");
  const offs = [];
  for (let i = 0; i < count; i++) offs.push(u32(data, 4 + 4 * i));
  offs.push(data.length);
  return offs.slice(0, count).map((o, i) => { try { return decodeClip(data, o, offs[i + 1]); } catch (e) { return null; } });
}

// The first clip of a motion file only (bones, slot map), for finding which file belongs to a model
function firstClip(data) {
  const count = u32(data, 0);
  if (!(count > 0 && count < 4096) || u32(data, 4) !== 4 + 4 * count) return null;
  for (let i = 0; i < count; i++) {
    const o = u32(data, 4 + 4 * i), e = i + 1 < count ? u32(data, 8 + 4 * i) : data.length;
    try { const c = decodeClip(data, o, e); if (c) return c; } catch (err) { /* next clip */ }
  }
  return null;
}

const modelSlots = model => model.parts.reduce((a, p) => a + p.slots, 0);

// Channel value at `frame`; half-rate clips store every second frame, so odd frames are averaged.
function clipValue(clip, arr, frame) {
  if (clip.keyStep === 1) return arr[Math.min(frame, arr.length - 1)];
  const k = frame >> 1, a = arr[Math.min(k, arr.length - 1)];
  return frame & 1 ? (a + arr[Math.min(k + 1, arr.length - 1)]) / 2 : a;
}

const matMul = (a, b) => {
  const o = new Float64Array(9);
  for (let i = 0; i < 3; i++) for (let j = 0; j < 3; j++) o[i * 3 + j] = a[i * 3] * b[j] + a[i * 3 + 1] * b[3 + j] + a[i * 3 + 2] * b[6 + j];
  return o;
};
function axisRot(axis, deg) {
  const a = deg * Math.PI / 180, c = Math.cos(a), s = Math.sin(a);
  return axis === "x" ? [1, 0, 0, 0, c, -s, 0, s, c] : axis === "y" ? [c, 0, s, 0, 1, 0, -s, 0, c] : [c, -s, 0, s, c, 0, 0, 0, 1];
}

// Rotation order and signs. The game builds each bone as parent * translate(t) * Rz(rz) * Ry(ry) * Rx(rx), with
// angles in turns of 4096 (the bone code at 0x00230cb0 and the matrix routine at 0x0018e860).
const POSE_CONVENTION = { order: "zyx", signs: [1, 1, 1] };

// World transform of every bone at `frame`: [{R: 9 numbers (row major), t: [x, y, z]}]
// conv.cal ({s, o}, see fitSkeleton) scales every bone translation and moves the roots, so the skeleton
// lines up with the model it drives.
function poseWorld(clip, frame, conv = POSE_CONVENTION) {
  const W = new Array(clip.bones.length), cal = conv.cal;
  const build = b => {
    if (W[b]) return W[b];
    const bone = clip.bones[b];
    const ang = { x: clipValue(clip, bone.r[0], frame) * conv.signs[0], y: clipValue(clip, bone.r[1], frame) * conv.signs[1], z: clipValue(clip, bone.r[2], frame) * conv.signs[2] };
    let M = [1, 0, 0, 0, 1, 0, 0, 0, 1];
    for (const ax of conv.order) M = matMul(M, axisRot(ax, ang[ax]));
    const t = [0, 1, 2].map(k => clipValue(clip, bone.t[k], frame) * (cal ? cal.s : 1) + (cal && bone.parent === null ? cal.o[k] : 0));
    if (bone.parent === null) return (W[b] = { R: M, t });
    const P = build(bone.parent), R = P.R;
    return (W[b] = { R: matMul(R, M), t: [R[0] * t[0] + R[1] * t[1] + R[2] * t[2] + P.t[0], R[3] * t[0] + R[4] * t[1] + R[5] * t[2] + P.t[1], R[6] * t[0] + R[7] * t[1] + R[8] * t[2] + P.t[2]] });
  };
  for (let b = 0; b < clip.bones.length; b++) build(b);
  return W;
}

// Bind pose: every joint's model-space position with all rotations zero, from the translations of frame 0
function bindJoints(clip, cal) {
  const J = new Array(clip.bones.length);
  const f = b => {
    if (J[b]) return J[b];
    const bone = clip.bones[b], t = [0, 1, 2].map(k => clipValue(clip, bone.t[k], 0) * (cal ? cal.s : 1) + (cal && bone.parent === null ? cal.o[k] : 0));
    if (bone.parent === null) return (J[b] = t);
    const p = f(bone.parent);
    return (J[b] = [p[0] + t[0], p[1] + t[1], p[2] + t[2]]);
  };
  for (let b = 0; b < clip.bones.length; b++) f(b);
  return J;
}

// Poses a model: returns, for every part, {positions, normals} in the part's render-buffer layout (y and z flipped
// like part.positions). Skinned parts hold bind-pose model-space vertices blended between two bones; the other
// parts are in the local space of their one bone. Parts with no bone slot stay as they are.
function skinModel(model, clip, W, J, slotBones = clip.slotBones) {
  const out = [];
  let slot = 0;
  for (const p of model.parts) {
    const m = p.vertexIndex.length, pos = new Float32Array(m * 3), nrm = new Float32Array(m * 3);
    const bones = p.slots ? slotBones.slice(slot, slot + p.slots) : [];
    slot += p.slots;
    if (!p.slots || bones.some(b => b === undefined)) { out.push({ positions: p.positions, normals: p.normals }); continue; }
    const xf = (b, v, n, w, o) => {
      const T = W[b], R = T.R, j = p.weights ? J[b] : [0, 0, 0];
      const x = v[0] - j[0], y = v[1] - j[1], z = v[2] - j[2];
      pos[o.p] += w * (R[0] * x + R[1] * y + R[2] * z + T.t[0]); pos[o.p + 1] += w * (R[3] * x + R[4] * y + R[5] * z + T.t[1]); pos[o.p + 2] += w * (R[6] * x + R[7] * y + R[8] * z + T.t[2]);
      nrm[o.p] += w * (R[0] * n[0] + R[1] * n[1] + R[2] * n[2]); nrm[o.p + 1] += w * (R[3] * n[0] + R[4] * n[1] + R[5] * n[2]); nrm[o.p + 2] += w * (R[6] * n[0] + R[7] * n[1] + R[8] * n[2]);
    };
    for (let c = 0; c < m; c++) {
      const vi = p.vertexIndex[c], ni = p.normalIndex[c];
      const v = [p.vertices[vi * 3], p.vertices[vi * 3 + 1], p.vertices[vi * 3 + 2]], n = [p.normalsRaw[ni * 3], p.normalsRaw[ni * 3 + 1], p.normalsRaw[ni * 3 + 2]], o = { p: c * 3 };
      if (p.weights) {
        const a = p.weights[vi * 4], wa = p.weights[vi * 4 + 1], b = p.weights[vi * 4 + 2], wb = p.weights[vi * 4 + 3], tot = wa + wb || 1;
        xf(bones[a], v, n, wa / tot, o);
        if (wb) xf(bones[b], v, n, wb / tot, o);
      } else xf(bones[0], v, n, 1, o);
    }
    for (let i = 0; i < m; i++) { pos[i * 3 + 1] = -pos[i * 3 + 1]; pos[i * 3 + 2] = -pos[i * 3 + 2]; nrm[i * 3 + 1] = -nrm[i * 3 + 1]; nrm[i * 3 + 2] = -nrm[i * 3 + 2]; }
    out.push({ positions: pos, normals: nrm });
  }
  return out;
}

// ---- fitting a model to a clip's skeleton

// Letters at the start of a part or bone name: "ajira05_1" and "ajira03" are both "ajira"
const namePrefix = name => { const m = /^[a-z]+/i.exec(name || ""); return m ? m[0].toLowerCase() : ""; };

// Does the model's part list fit the clip's bone-slot map? Exactly, or with a few parts more or fewer than the
// clip (variants of one monster share a motion file: mon005i has a held weapon the clip does not know,
// mon00x leaves seven of the clip's slots unused). Returns 2 for an exact fit, 1 for a loose one, 0 for none.
function slotsFit(model, clip) {
  const total = modelSlots(model), n = clip.slotBones.length;
  return total === n ? 2 : total > 0 && total <= n + 4 ? 1 : 0;
}

// The bone of every slot of `model` (the clip's slotBones when the counts agree). When the model has parts the clip
// does not, those parts are found by name: walking the parts in order, a part whose name starts like the bone
// the next clip slot belongs to takes that slot; any other named part is an extra and hangs on the last bone of
// its name group (mon005i's ajila03 on the end of the ajila chain). Unnamed parts take the next slot.
function alignSlots(model, clip) {
  const sb = clip.slotBones;
  if (modelSlots(model) === sb.length) return sb;
  const known = new Set(clip.bones.map(b => namePrefix(b.name)).filter(Boolean));
  const out = [];
  let j = 0;
  for (const p of model.parts) for (let k = 0; k < p.slots; k++) {
    const pre = namePrefix(p.name), at = j < sb.length ? namePrefix(clip.bones[sb[j]].name) : null;
    if (j < sb.length && (!known.has(pre) || !at || at === pre)) out.push(sb[j++]);
    else { let b = 0; clip.bones.forEach((bn, i) => { if (namePrefix(bn.name) === pre) b = i; }); out.push(b); }
  }
  return out;
}

// How much of a model's part naming a clip's bone naming shares, 0..1: the part names start with the three
// letters the monster's bones do (kzn, lng, pri, ...). Used to find the motion file of a model whose file name
// does not say (mon013 uses mon012.mov, ply06a uses ply00.mov, mon41 is a typo for mon041). Parts with generic
// names (part_N, Skin Object) are ignored; 0 when fewer than two parts are named.
function nameAffinity(model, clip) {
  const tag = n => namePrefix(n).slice(0, 3);
  const bones = new Set(clip.bones.map(b => tag(b.name)).filter(Boolean));
  const named = model.parts.filter(p => tag(p.name) && !/^(par|ski)/i.test(tag(p.name)));
  if (named.length < 2) return 0;
  return named.filter(p => bones.has(tag(p.name))).length / named.length;
}

// Calibration of a clip's skeleton against the skinned vertices of a model: {cal, ratio}. The skinned vertices
// are in the model's own space, the joints in the clip's, and the two do not always agree: mon011 is shifted
// by about its root height, and mon012a is mon012 at half size on the same motion file. For every bone the mean
// of the vertices that depend mostly on it is compared with its joint, and v = s * joint + o is fitted (a size
// of 1 unless a free one fits much better). `cal` is {s, o}, only when the fit is clearly better, so models that
// already line up stay as they are. `ratio` is what is left over, as a fraction of the model's height: a few
// percent when the skeleton belongs to the model, above 0.8 when it does not (mon011_ on mon011.mov), and null
// when there are too few skinned vertices to tell.
function fitSkeleton(model, clip, slotBones = clip.slotBones) {
  const J = bindJoints(clip), sum = new Map();
  let slot = 0, ymin = Infinity, ymax = -Infinity;
  for (const p of model.parts) {
    if (p.weights) for (let i = 0; i < p.vertexCount; i++) {
      const y = p.vertices[i * 3 + 1];
      if (y < ymin) ymin = y;
      if (y > ymax) ymax = y;
      const w = p.weights[i * 4 + 1], b = slotBones[slot + p.weights[i * 4]];
      if (w < 60 || b === undefined || !J[b]) continue;
      let e = sum.get(b);
      if (!e) sum.set(b, e = { n: 0, v: [0, 0, 0] });
      e.n++;
      for (let k = 0; k < 3; k++) e.v[k] += p.vertices[i * 3 + k];
    }
    slot += p.slots;
  }
  const pts = [...sum].filter(([, e]) => e.n >= 3).map(([b, e]) => ({ j: J[b], v: e.v.map(x => x / e.n), n: e.n }));
  if (pts.length < 2) return { cal: null, ratio: null };
  const height = Math.max(ymax - ymin, 1);
  let wt = 0;
  const mj = [0, 0, 0], mv = [0, 0, 0];
  for (const q of pts) { wt += q.n; for (let k = 0; k < 3; k++) { mj[k] += q.j[k] * q.n; mv[k] += q.v[k] * q.n; } }
  for (let k = 0; k < 3; k++) { mj[k] /= wt; mv[k] /= wt; }
  const rms = (s, o) => { let r = 0; for (const q of pts) for (let k = 0; k < 3; k++) r += q.n * (q.v[k] - (s * q.j[k] + o[k])) ** 2; return Math.sqrt(r / wt / 3); };
  const base = rms(1, [0, 0, 0]);
  const shifted = { s: 1, o: [0, 1, 2].map(k => mv[k] - mj[k]) };
  let best = { ...shifted, r: rms(1, shifted.o) };
  if (pts.length >= 4) {
    let num = 0, den = 0;
    for (const q of pts) for (let k = 0; k < 3; k++) { num += q.n * (q.j[k] - mj[k]) * (q.v[k] - mv[k]); den += q.n * (q.j[k] - mj[k]) ** 2; }
    const sf = den > 0 ? num / den : 1;
    const free = { s: sf, o: [0, 1, 2].map(k => mv[k] - sf * mj[k]) }, rf = rms(free.s, free.o);
    if (Math.abs(sf - 1) > 0.25 && sf > 0.3 && sf < 3.5 && rf < 0.7 * best.r) best = { ...free, r: rf };
  }
  const use = base > 1200 && best.r < 0.6 * base;
  return { cal: use ? { s: best.s, o: best.o } : null, ratio: (use ? best.r : base) / height };
}

// ---------------------------------------------------------------- effects (.efp packs of .efb)

// Port of tools/efp_tool.py. An .efb is a stream of 4-byte words: 01/02/03 = a command for a particle / aqua /
// model object (u32 command id, then ARG_COUNTS[id] argument words), 05 = start frame of the objects that
// follow, 06 = object slot, 08 = id, ff ff 00 00 = end.
const EFB_ARG_COUNTS = [
  1, 3, 3, 2, 1, 1, 4, 4, 1, 5, 1, 1, 5, 5, 5, 1, 1, 6, 6, 6, 6, 6, 6, 6,
  5, 5, 5, 5, 5, 5, 5, 5, 1, 1, 1, 1, 3, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
  5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
  5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 1, 1, 3, 4, 4, 8, 4, 4, 4, 3, 3, 3];
const EFB_SECTIONS = ["ver", "particle", "aqua", "model", "end", "time", "effect_number", "name", "id"];
const EFB_COMMANDS = ("init pos angle see motion_ht motion_pt texroll wavemt strain scale drawtime apptime angle_x angle_y angle_z division " +
  "circlenum wa_height wa_radiusx wa_radiusy wa_see wa_colorr wa_colorg wa_colorb rolltx rollty pos_x pos_y pos_z rot_x rot_y rot_z " +
  "form texdraw texpattarn screen ptnum texanipt pt_posx pt_posy pt_posz pt_spx pt_spy pt_spz pt_apx pt_apy pt_apz pt_angx " +
  "pt_angy pt_angz pt_angspx pt_angspy pt_angspz pt_angapx pt_angapy pt_angapz pt_rotx pt_roty pt_rotz pt_rotspx pt_rotspy pt_rotspz " +
  "pt_rotapx pt_rotapy pt_rotapz pt_sizex pt_sizey pt_sizespx pt_sizespy pt_sizeapx pt_sizeapy pt_alpha pt_alphasp pt_alphaap pt_cl_r pt_cl_g " +
  "pt_cl_b pt_clsp_r pt_clsp_g pt_clsp_b pt_clap_r pt_clap_g pt_clap_b animeflag option drawnum formcoe range drper spread center_x " +
  "center_y center_z center_mx center_my center_mz").split(" ");

const f32Bits = (() => { const b = new DataView(new ArrayBuffer(4)); return w => { b.setUint32(0, w >>> 0); return b.getFloat32(0); }; })();
// A word is a float when its exponent is in a plausible range, as in efp_tool.show_word
function efbNumber(w) {
  const exp = (w >>> 23) & 0xFF;
  if (w && exp >= 0x60 && exp <= 0x9F) return f32Bits(w);
  return w | 0;
}

// [{op, cid, name, args: [words]}]; throws on a bad stream
function efbCommands(d) {
  const out = [];
  for (let pos = 0; pos + 4 <= d.length;) {
    const op = d[pos];
    pos += 4;
    if (op >= 1 && op <= 3) {
      const cid = i32(d, pos);
      if (cid < 0 || cid >= EFB_ARG_COUNTS.length) throw new Error("bad command id " + cid);
      const n = EFB_ARG_COUNTS[cid], args = [];
      for (let i = 0; i < n; i++) args.push(u32(d, pos + 4 + 4 * i));
      out.push({ op, cid, name: EFB_COMMANDS[cid], args });
      pos += 4 + 4 * n;
    } else if (op === 5 || op === 6 || op === 8) {
      out.push({ op, cid: null, name: EFB_SECTIONS[op], args: [u32(d, pos)] });
      pos += 4;
    } else if (op === 0xFF) return out;
    else throw new Error("unknown opcode " + op);
  }
  return out;
}

// Text form of an effect, like `efp_tool.py efb`
function efbListing(cmds) {
  return cmds.map(c => {
    if (c.op === 6) { let s = c.args[0] & 0xFF; if (s >= 0x80) s -= 256; return "effect_number".padEnd(24) + " " + s; }
    const label = (c.cid === null ? c.name : EFB_SECTIONS[c.op] + "." + c.name).padEnd(24);
    return label + " " + c.args.map(w => { const v = efbNumber(w); return Number.isInteger(v) ? String(v) : String(+v.toPrecision(6)); }).join(" ");
  }).join("\n") + "\n";
}

// Objects of an effect: [{slot, kind: "particle" | "aqua" | "model", start, params: {name: [numbers]}, circles: {circle: {name: [numbers]}}}]
function efbObjects(cmds) {
  const kinds = [null, "particle", "aqua", "model"], objs = [], bySlot = new Map();
  let slot = 0, time = 0;
  for (const c of cmds) {
    if (c.op === 6) { slot = c.args[0] & 0xFF; if (slot >= 0x80) slot -= 256; continue; }
    if (c.op === 5) { time = c.args[0]; continue; }
    if (c.cid === null) continue;
    if (c.name === "init") { const o = { slot, kind: kinds[c.op], start: time, params: {}, circles: {} }; objs.push(o); bySlot.set(slot, o); continue; }
    const o = bySlot.get(slot);
    if (!o) continue;
    const nums = c.args.map(efbNumber);
    if (c.name.startsWith("wa_")) { (o.circles[nums[0]] = o.circles[nums[0]] || {})[c.name] = nums.slice(2); }   // circle, mode, start, end, duration, delay
    else o.params[c.name] = nums;
  }
  return objs;
}

// Entries of a pack: [{name, off, size}]
function efpEntries(d) {
  const first = u32(d, 0);
  const named = (count, table) => {
    const base = table + count * 0x18, out = [];
    for (let i = 0; i < count; i++) {
      const size = u32(d, table + i * 0x18), off = u32(d, table + i * 0x18 + 4);
      let name = "";
      for (let k = 0; k < 16 && d[table + i * 0x18 + 8 + k]; k++) name += String.fromCharCode(d[table + i * 0x18 + 8 + k]);
      if (!name || /[^\x20-\x7e]/.test(name) || base + off + size > d.length) throw new Error("unsupported pack layout");
      out.push({ name, off: base + off, size });
    }
    return out;
  };
  try {
    if (first === 0x3E9) return named(u32(d, 8), 12);
    return named(first, 4);
  } catch (e) {
    if (first === 0x3E9) throw e;
  }
  // older layout (bpack1.efp): u32 count, count u32 sizes, entries back to back
  if (!(first > 0 && first < 0x10000) || 4 + 4 * first > d.length) throw new Error("unsupported pack layout");
  let pos = 4 + 4 * first;
  const out = [];
  for (let i = 0; i < first; i++) {
    const size = u32(d, 4 + 4 * i);
    if (pos + size > d.length) throw new Error("unsupported pack layout");
    out.push({ name: String(i).padStart(3, "0") + ".efb", off: pos, size });
    pos += size;
  }
  return out;
}

// ---------------------------------------------------------------- audio (.int streams)

const ADPCM_F0 = [0, 60, 115, 98, 122], ADPCM_F1 = [0, 0, -52, -55, -60];

// Decodes consecutive 16-byte ADPCM frames in `data` (the bytes of `frames` listed as [offset...]) to Int16
function adpcmDecodeFrames(data, offsets) {
  const out = new Int16Array(offsets.length * 28);
  let s1 = 0, s2 = 0, k = 0;
  for (const off of offsets) {
    const shift = data[off] & 15;
    let filt = data[off] >> 4;
    if (filt > 4) filt = 0;
    const a = ADPCM_F0[filt], b = ADPCM_F1[filt];
    for (let i = 2; i < 16; i++) {
      for (let h = 0; h < 2; h++) {
        const nib = h ? data[off + i] >> 4 : data[off + i] & 15;
        let v = ((nib > 7 ? nib - 16 : nib) << 12) >> shift;
        v += (s1 * a + s2 * b + 32) >> 6;
        v = v > 32767 ? 32767 : v < -32768 ? -32768 : v;
        s2 = s1; s1 = v;
        out[k++] = v;
      }
    }
  }
  return out;
}

// .int: stereo, interleaved in 0x400-byte blocks. Returns {rate, channels: [Int16Array, Int16Array]}
function decodeInt(data, block = 0x400) {
  const n = Math.floor(data.length / (block * 2)) * block * 2;
  const frames = [[], []];
  for (let off = 0; off < n; off += block) {
    const ch = (off / block) % 2;
    for (let i = 0; i < block; i += 16) frames[ch].push(off + i);
  }
  return { rate: 44100, channels: frames.map(f => adpcmDecodeFrames(data, f)) };
}

function encodeWav(channels, rate) {
  const n = Math.min(...channels.map(c => c.length)), nch = channels.length;
  const out = new Uint8Array(44 + n * nch * 2), dv = new DataView(out.buffer);
  const tag = (o, s) => { for (let i = 0; i < 4; i++) out[o + i] = s.charCodeAt(i); };
  tag(0, "RIFF"); dv.setUint32(4, 36 + n * nch * 2, true); tag(8, "WAVE"); tag(12, "fmt ");
  dv.setUint32(16, 16, true); dv.setUint16(20, 1, true); dv.setUint16(22, nch, true); dv.setUint32(24, rate, true);
  dv.setUint32(28, rate * nch * 2, true); dv.setUint16(32, nch * 2, true); dv.setUint16(34, 16, true);
  tag(36, "data"); dv.setUint32(40, n * nch * 2, true);
  for (let i = 0; i < n; i++) for (let c = 0; c < nch; c++) dv.setInt16(44 + (i * nch + c) * 2, channels[c][i], true);
  return out;
}

// ---------------------------------------------------------------- PNG

const CRC_TABLE = (() => { const t = new Uint32Array(256); for (let n = 0; n < 256; n++) { let c = n; for (let k = 0; k < 8; k++) c = c & 1 ? 0xEDB88320 ^ c >>> 1 : c >>> 1; t[n] = c >>> 0; } return t; })();
function crc32(buf) { let c = 0xFFFFFFFF; for (let i = 0; i < buf.length; i++) c = CRC_TABLE[(c ^ buf[i]) & 255] ^ c >>> 8; return (c ^ 0xFFFFFFFF) >>> 0; }

async function deflate(bytes) {
  const cs = new CompressionStream("deflate");
  const w = cs.writable.getWriter();
  w.write(bytes); w.close();
  return new Uint8Array(await new Response(cs.readable).arrayBuffer());
}

async function encodePng(width, height, rgba) {
  const raw = new Uint8Array(height * (width * 4 + 1));
  for (let y = 0; y < height; y++) raw.set(rgba.subarray(y * width * 4, (y + 1) * width * 4), y * (width * 4 + 1) + 1);
  const idat = await deflate(raw);
  const chunk = (type, body) => {
    const o = new Uint8Array(12 + body.length), dv = new DataView(o.buffer);
    dv.setUint32(0, body.length); for (let i = 0; i < 4; i++) o[4 + i] = type.charCodeAt(i);
    o.set(body, 8); dv.setUint32(8 + body.length, crc32(o.subarray(4, 8 + body.length)));
    return o;
  };
  const ihdr = new Uint8Array(13), dv = new DataView(ihdr.buffer);
  dv.setUint32(0, width); dv.setUint32(4, height); ihdr[8] = 8; ihdr[9] = 6;
  const parts = [new Uint8Array([137, 80, 78, 71, 13, 10, 26, 10]), chunk("IHDR", ihdr), chunk("IDAT", idat), chunk("IEND", new Uint8Array(0))];
  const out = new Uint8Array(parts.reduce((a, p) => a + p.length, 0));
  let at = 0; for (const p of parts) { out.set(p, at); at += p.length; }
  return out;
}

// ---------------------------------------------------------------- file kinds

const extOf = path => { const m = /\.([^./]+)$/.exec(path); return m ? m[1].toLowerCase() : ""; };

// What the viewer can show for a file path
function kindOf(path) {
  const e = extOf(path);
  if (e === "tmd" || /tmd\.dat$/i.test(path)) return "model";
  if (e === "tms" || e === "dat" || e === "pac") return "texture?";   // probed on open
  if (e === "lzs") return "archive";
  if (e === "int") return "audio";
  if (e === "mov" || e === "moz") return "motion";
  if (e === "efp" || e === "efb") return "effect";
  return "file";
}

const api = {
  SECTOR, openDisc, decryptDir, parseDir, readBytes,
  lzsDecompress, lzsIsArchive, lzsMembers, pacChunks, PAC_TYPES,
  parseTexture, parseTextureSet, textureRGBA, findTextureSets,
  parseModels, modelsToObj, modelMtl, modelUVs, mapUV, bindTextures, textureForFlags,
  efbCommands, efbListing, efbObjects, efbNumber, efpEntries,
  parseMotions, decodeClip, firstClip, modelSlots, slotsFit, nameAffinity, alignSlots, fitSkeleton, poseWorld, bindJoints, skinModel, POSE_CONVENTION,
  decodeInt, adpcmDecodeFrames, encodeWav, encodePng, crc32,
  extOf, kindOf,
};
if (typeof module !== "undefined" && module.exports) module.exports = api;
else root.Legaia = api;
})(typeof self !== "undefined" ? self : this);
