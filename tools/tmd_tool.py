#!/usr/bin/env python3
"""Converts Legaia 2 .tmd models to Wavefront OBJ.

Container: u32 count, then count u32 offsets in 4-byte words, one per model.

A model is a run of parts, each with a 0xa0-byte header; part k's header is at
model + k * 0xa0, and part 0's first word doubles as the model header:
(part count << 24) | 0x8003 (low half varies per file). Part header (offsets
stored in it are from the model start, not the part):
  0x10 u32  flags: 0x80 skinned (has a weight table), 0x01 takes no bone slot
            (see below); 0x400, 0x800 not known
  0x14 u32  vertex section offset     0x18 u32 normal section offset
  0x1c u32  primitive section offset  0x24 u32 edge section offset (optional)
  0x28 f32[6] bounding box: x min/max, y min/max, z min/max
  0x40 u16  vertex count, u16 normal count, u16 primitive (triangle) count
  0x60 u32  second primitive list (skinned parts; not decoded)
  0x64 u32  weight table offset
  0x6c f32  0.0005 in almost every part
  0x70 char name[16]
Vertices and normals are 4 floats each (x, y, z, w).

Skinning: a skinned part's weight table is u32 slot count, then one 4-byte
entry per vertex: u8 slot a, u8 weight a, u8 slot b, u8 weight b, weights in
percent (they add up to 100 for 99.5% of the 250,193 skinned vertices on the
disc; the rest are authoring slips like 50 + 55). Slots are local to
the part. A motion clip's index map (mov_tool.py) gives the bone for every slot
of every part in order: a skinned part uses its slot count, a part with flag
0x01 uses none, any other part uses one (rigid: the whole part follows that
bone). Parts with flag 0x800 carry a table of the same shape without the count
word; what drives it is not known.

Primitives: one or more sections, back to back, until their triangle counts add
up to the part's total. Section: u16 triangle count, u16 kind (0x28/0x29),
u32 size in words (section = 8 + size * 4 bytes, last 4 may be padding), then
groups. Group: u32 ?, u16 record count, u16 flags, then 16-byte records:
  u32 flags, u8 r, g, b, a, u16 u, u16 v, u16 vertex offset, u16 normal offset
(offsets in bytes into the vertex/normal arrays, i.e. index * 16). Each group is
a triangle strip; a record with flag bit 0 set does not complete a triangle (GS
ADC bit). This reproduces the header triangle count for 98.6% of the 5,234
parts on the disc; the rest (a few files such as mon2.tmd) use another group
layout and are skipped.
Texture coordinates are written as u/1024, v/1024 (scale not confirmed).

Usage:
  tmd_tool.py info FILE.tmd [...]       models, parts, flags, bone slots
  tmd_tool.py obj FILE.tmd OUT.obj      one OBJ object per part
  tmd_tool.py all FS_DIR OUT_DIR
"""

import os
import struct
import sys

PART_SIZE = 0xA0


class Part:
    def __init__(self, d, base, k):
        h = base + PART_SIZE * k
        self.flags = struct.unpack_from("<I", d, h + 0x10)[0]
        ov, on, op = struct.unpack_from("<3I", d, h + 0x14)
        self.bbox = struct.unpack_from("<6f", d, h + 0x28)
        raw = d[h + 0x70:h + 0x80].split(b"\0")[0]
        self.name = raw.decode("latin1") if raw and all(32 <= c < 127 for c in raw) else f"part_{k}"
        nv, nn, ntri = struct.unpack_from("<3H", d, h + 0x40)
        self.vertices = [struct.unpack_from("<3f", d, base + ov + 16 * i) for i in range(nv)]
        self.normals = [struct.unpack_from("<3f", d, base + on + 16 * i) for i in range(nn)]
        self.weights = None  # per vertex: ((slot, weight %), (slot, weight %))
        self.slots = 0 if self.flags & 1 else 1
        if self.flags & 0x80:
            wt = base + struct.unpack_from("<I", d, h + 0x64)[0]
            self.slots = struct.unpack_from("<I", d, wt)[0]
            self.weights = []
            for i in range(nv):
                a, wa, b, wb = d[wt + 4 + 4 * i:wt + 8 + 4 * i]
                if max(a, b) >= self.slots:
                    raise ValueError(f"part {k}: bad weight entry {i}")
                self.weights.append(((a, wa), (b, wb)))
        self.triangles = []  # each: 3 x (vertex, normal, u, v, rgba)
        sec, total = base + op, 0
        while total < ntri:
            count, _kind, words = struct.unpack_from("<HHI", d, sec)
            end = sec + 8 + words * 4
            pos, found = sec + 8, 0
            while pos + 8 <= end:
                n = struct.unpack_from("<I", d, pos + 4)[0] & 0xFFFF
                pos += 8
                if n == 0 or pos + 16 * n > end:
                    break
                strip = []
                for i in range(n):
                    flags, rgba, u, v, vo, no = struct.unpack_from("<IIHHHH", d, pos + 16 * i)
                    if vo % 16 or vo // 16 >= nv:
                        raise ValueError(f"part {k}: vertex offset {vo:#x} out of range")
                    strip.append((flags, (vo // 16, no // 16 if nn else 0, u, v, rgba)))
                pos += 16 * n
                for i in range(2, n):
                    if not strip[i][0] & 1:
                        a, b, c = strip[i - 2][1], strip[i - 1][1], strip[i][1]
                        # alternate winding along the strip
                        self.triangles.append((a, b, c) if i % 2 == 0 else (b, a, c))
                        found += 1
            if found != count:
                raise ValueError(f"part {k}: section at {sec - base:#x}: {found} triangles, header says {count}")
            total += count
            sec = end


class Model:
    def __init__(self, d, base):
        self.parts, self.bad = [], []
        for k in range(d[base + 3]):
            try:
                self.parts.append(Part(d, base, k))
            except (ValueError, struct.error) as e:
                self.bad.append((k, str(e)))
        self.slots = sum(p.slots for p in self.parts)


def models(d):
    count = struct.unpack_from("<I", d, 0)[0]
    if not 0 < count < 256:
        raise ValueError(f"implausible model count {count}")
    return [Model(d, struct.unpack_from("<I", d, 4 + 4 * i)[0] * 4) for i in range(count)]


def write_obj(path, ms):
    with open(path, "w") as f:
        f.write("# converted by tmd_tool.py\n")
        vbase = nbase = tbase = 0
        for i, m in enumerate(ms):
            for p in m.parts:
                f.write(f"o model_{i}_{p.name}\n")
                for x, y, z in p.vertices:
                    f.write(f"v {x:.4f} {-y:.4f} {-z:.4f}\n")  # PS2 data is y-down
                for x, y, z in p.normals:
                    f.write(f"vn {x:.4f} {-y:.4f} {-z:.4f}\n")
                uvs = {}
                for tri in p.triangles:
                    for _, _, u, v, _ in tri:
                        if (u, v) not in uvs:
                            uvs[(u, v)] = len(uvs)
                            f.write(f"vt {u / 1024:.5f} {1 - v / 1024:.5f}\n")
                for tri in p.triangles:
                    refs = " ".join(f"{vbase + vi + 1}/{tbase + uvs[(u, v)] + 1}/{nbase + ni + 1}"
                                    for vi, ni, u, v, _ in tri)
                    f.write(f"f {refs}\n")
                vbase += len(p.vertices)
                nbase += len(p.normals)
                tbase += len(uvs)


def main(argv):
    if len(argv) >= 3 and argv[1] == "info":
        for path in argv[2:]:
            for i, m in enumerate(models(open(path, "rb").read())):
                print(f"{path} model {i}: {len(m.parts)} parts, {m.slots} bone slots"
                      + (f", {len(m.bad)} unsupported" if m.bad else ""))
                for p in m.parts:
                    print(f"  {p.name:<16} flags {p.flags:#06x} {len(p.vertices):5d} vertices"
                          f" {len(p.triangles):5d} triangles {p.slots:3d} slots")
    elif len(argv) == 4 and argv[1] == "obj":
        write_obj(argv[3], models(open(argv[2], "rb").read()))
        print(argv[3])
    elif len(argv) == 4 and argv[1] == "all":
        ok = bad = parts = skipped = 0
        for root, _, names in os.walk(argv[2]):
            for name in sorted(names):
                if not name.endswith((".tmd", "tmd.dat")):
                    continue
                src = os.path.join(root, name)
                rel = os.path.relpath(src, argv[2])
                dst = os.path.join(argv[3], os.path.splitext(rel)[0] + ".obj")
                try:
                    ms = models(open(src, "rb").read())
                except (ValueError, struct.error) as e:
                    print(f"{src}: {e}")
                    bad += 1
                    continue
                parts += sum(len(m.parts) for m in ms)
                skipped += sum(len(m.bad) for m in ms)
                os.makedirs(os.path.dirname(dst), exist_ok=True)
                write_obj(dst, ms)
                ok += 1
        print(f"converted {ok} models ({parts} parts, {skipped} unsupported parts skipped), {bad} failed")
    else:
        raise SystemExit(__doc__)


if __name__ == "__main__":
    main(sys.argv)
