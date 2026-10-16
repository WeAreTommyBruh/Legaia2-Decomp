#!/usr/bin/env python3
"""Converts Legaia 2 .tmd models to Wavefront OBJ.

Container: u32 count, then count u32 offsets in 4-byte words, one per model.

Model (offsets from the model start):
  0x00 u32  (part count << 24) | 0x8003 (low half varies per file)
  0x10 u32  flags
  0x14 u32  vertex section offset     0x18 u32 normal section offset
  0x1c u32  primitive section offset  0x24 u32 edge section offset (optional)
  0x28 f32[6] bounding box: x min/max, y min/max, z min/max
  0x40 u16  vertex count, u16 normal count, u16 primitive (triangle) count
Vertices and normals are 4 floats each (x, y, z, w).

Primitives: one or more sections, back to back, until their triangle counts add
up to the model's total. Section: u16 triangle count, u16 kind (0x28/0x29),
u32 size in words (section = 8 + size * 4 bytes, last 4 may be padding), then
groups. Group: u32 ?, u16 record count, u16 flags, then 16-byte records:
  u32 flags, u8 r, g, b, a, u16 u, u16 v, u16 vertex offset, u16 normal offset
(offsets in bytes into the vertex/normal arrays, i.e. index * 16). Each group is
a triangle strip; a record with flag bit 0 set does not complete a triangle (GS
ADC bit). This reproduces the header triangle count for every model on the disc.
Texture coordinates are written as u/1024, v/1024 (scale not confirmed).

Usage:
  tmd_tool.py info FILE.tmd [...]
  tmd_tool.py obj FILE.tmd OUT.obj
  tmd_tool.py all FS_DIR OUT_DIR
"""

import os
import struct
import sys


class Model:
    def __init__(self, d, base):
        self.base = base
        ov, on, op = struct.unpack_from("<3I", d, base + 0x14)
        self.bbox = struct.unpack_from("<6f", d, base + 0x28)
        nv, nn, ntri = struct.unpack_from("<3H", d, base + 0x40)
        self.vertices = [struct.unpack_from("<3f", d, base + ov + 16 * i) for i in range(nv)]
        self.normals = [struct.unpack_from("<3f", d, base + on + 16 * i) for i in range(nn)]
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
                for k in range(n):
                    flags, rgba, u, v, vo, no = struct.unpack_from("<IIHHHH", d, pos + 16 * k)
                    if vo % 16 or vo // 16 >= nv:
                        raise ValueError(f"vertex offset {vo:#x} out of range")
                    strip.append((flags, (vo // 16, no // 16 if nn else 0, u, v, rgba)))
                pos += 16 * n
                for k in range(2, n):
                    if not strip[k][0] & 1:
                        a, b, c = strip[k - 2][1], strip[k - 1][1], strip[k][1]
                        # alternate winding along the strip
                        self.triangles.append((a, b, c) if k % 2 == 0 else (b, a, c))
                        found += 1
            if found != count:
                raise ValueError(f"section at {sec - base:#x}: {found} triangles, header says {count}")
            total += count
            sec = end


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
            f.write(f"o model_{i}\n")
            for x, y, z in m.vertices:
                f.write(f"v {x:.4f} {-y:.4f} {-z:.4f}\n")  # PS2 data is y-down
            for x, y, z in m.normals:
                f.write(f"vn {x:.4f} {-y:.4f} {-z:.4f}\n")
            uvs = {}
            for tri in m.triangles:
                for _, _, u, v, _ in tri:
                    if (u, v) not in uvs:
                        uvs[(u, v)] = len(uvs)
                        f.write(f"vt {u / 1024:.5f} {1 - v / 1024:.5f}\n")
            for tri in m.triangles:
                refs = " ".join(f"{vbase + vi + 1}/{tbase + uvs[(u, v)] + 1}/{nbase + ni + 1}"
                                for vi, ni, u, v, _ in tri)
                f.write(f"f {refs}\n")
            vbase += len(m.vertices)
            nbase += len(m.normals)
            tbase += len(uvs)


def main(argv):
    if len(argv) >= 3 and argv[1] == "info":
        for path in argv[2:]:
            for i, m in enumerate(models(open(path, "rb").read())):
                print(f"{path} model {i}: {len(m.vertices)} vertices, {len(m.normals)} normals,"
                      f" {len(m.triangles)} triangles")
    elif len(argv) == 4 and argv[1] == "obj":
        write_obj(argv[3], models(open(argv[2], "rb").read()))
        print(argv[3])
    elif len(argv) == 4 and argv[1] == "all":
        ok = bad = 0
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
                os.makedirs(os.path.dirname(dst), exist_ok=True)
                write_obj(dst, ms)
                ok += 1
        print(f"converted {ok} models, {bad} failed")
    else:
        raise SystemExit(__doc__)


if __name__ == "__main__":
    main(sys.argv)
