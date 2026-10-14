#!/usr/bin/env python3
"""Converts Legaia 2 texture sets (.tms, many .dat, .pac texture chunks) to PNG.

Container (init_0024bd78 @ 0x0024bd78): u32 count, then count u32 offsets in
4-byte words from the container start, one per texture.

Texture (init_0024bf60 @ 0x0024bf60), offsets in bytes:
  0x00 u16  header kind: 0x41 = 0x20-byte header, 0x42 = 0x80-byte header
  0x02 u8   flags: bit 0 = has a CLUT, which follows the header
  0x03 u8   pixel format: 0 = 4-bit indexed, 1 = 8-bit indexed, 2 = 16-bit, 3 = 32-bit
  0x04 u32  pixel data offset in words from the texture start
  0x12 u16  CLUT position in VRAM
  0x14 u16  CLUT width, 0x16 u16 CLUT height (32-bit RGBA entries)
  0x18 u16  VRAM x, 0x1a u16 VRAM y
  0x1c u16  width in 16-bit units (4-bit: x4 pixels, 8-bit: x2), 0x1e u16 height
The game uploads pixels and CLUT as GS image transfers (FUN_00241d00), so both
are stored row-major. 8-bit CLUTs are in the GS CSM1 order (index bits 3 and 4
swapped). GS alpha is 0..0x80.

Usage:
  tex_tool.py info FILE [...]                list textures
  tex_tool.py png FILE OUT_DIR [--pac]       write OUT_DIR/<name>_NN.png
     --pac: FILE is a .pac; converts its texture chunks (types 0x01, 0x05)
  tex_tool.py all FS_DIR OUT_DIR             every .tms/.pac/.dat texture set under FS_DIR
"""

import os
import struct
import sys
import zlib

FORMATS = {0: ("4-bit", 4), 1: ("8-bit", 8), 2: ("16-bit", 16), 3: ("32-bit", 32)}


def write_png(path, width, height, rgba):
    def chunk(tag, data):
        c = tag + data
        return struct.pack(">I", len(data)) + c + struct.pack(">I", zlib.crc32(c) & 0xFFFFFFFF)

    stride = width * 4
    raw = b"".join(b"\0" + rgba[y * stride:(y + 1) * stride] for y in range(height))
    with open(path, "wb") as f:
        f.write(b"\x89PNG\r\n\x1a\n")
        f.write(chunk(b"IHDR", struct.pack(">IIBBBBB", width, height, 8, 6, 0, 0, 0)))
        f.write(chunk(b"IDAT", zlib.compress(raw, 6)))
        f.write(chunk(b"IEND", b""))


def gs_alpha(a):
    return min(255, a * 2)


def rgba32(word):
    r, g, b, a = word & 0xFF, (word >> 8) & 0xFF, (word >> 16) & 0xFF, word >> 24
    return bytes((r, g, b, gs_alpha(a)))


def rgba16(v):
    r, g, b = (v & 0x1F) << 3, ((v >> 5) & 0x1F) << 3, ((v >> 10) & 0x1F) << 3
    return bytes((r, g, b, 255 if v & 0x8000 else 0 if v == 0 else 255))


def csm1(i):
    return (i & ~0x18) | ((i & 0x08) << 1) | ((i & 0x10) >> 1)


class Texture:
    def __init__(self, data, off):
        kind, self.flags, self.fmt = struct.unpack_from("<HBB", data, off)
        if kind not in (0x41, 0x42) or self.fmt not in FORMATS:
            raise ValueError(f"not a texture header at {off:#x}")
        self.header = 0x20 if kind == 0x41 else 0x80
        pix_words = struct.unpack_from("<I", data, off + 4)[0]
        self.clut_w, self.clut_h, self.x, self.y, w16, self.height = struct.unpack_from("<6H", data, off + 0x14)
        self.width = w16 * {0: 4, 1: 2}.get(self.fmt, 1)
        self.pix_off = off + pix_words * 4
        self.clut_off = off + self.header if self.flags & 1 else None
        self.data = data
        bpp = FORMATS[self.fmt][1]
        self.pix_size = self.width * self.height * bpp // 8
        if self.pix_off + self.pix_size > len(data):
            raise ValueError(f"pixel data runs past the end ({self.pix_off:#x}+{self.pix_size:#x})")

    def palette(self):
        n = self.clut_w * self.clut_h
        raw = [rgba32(w) for w in struct.unpack_from(f"<{n}I", self.data, self.clut_off)]
        if self.fmt == 1 and n == 256:
            return [raw[csm1(i)] for i in range(256)]
        return raw

    def rgba(self):
        d, p, n = self.data, self.pix_off, self.width * self.height
        if self.fmt in (0, 1):
            pal = self.palette() if self.clut_off is not None else [bytes((i, i, i, 255)) for i in range(256)]
            if self.fmt == 1:
                idx = d[p:p + n]
            else:
                idx = bytearray()
                for b in d[p:p + n // 2]:
                    idx += bytes((b & 0xF, b >> 4))
            black = b"\0\0\0\0"
            return b"".join(pal[i] if i < len(pal) else black for i in idx)
        if self.fmt == 2:
            return b"".join(rgba16(v) for v in struct.unpack_from(f"<{n}H", d, p))
        return b"".join(rgba32(w) for w in struct.unpack_from(f"<{n}I", d, p))


def textures(data, base=0):
    count = struct.unpack_from("<I", data, base)[0]
    if not 0 < count < 4096:
        raise ValueError(f"implausible texture count {count}")
    for i in range(count):
        words = struct.unpack_from("<I", data, base + 4 + 4 * i)[0]
        yield Texture(data, base + words * 4)


def pac_texture_sets(data):
    """Yields the data offset of each texture chunk in a .pac."""
    off = 0
    while off + 4 <= len(data):
        word = struct.unpack_from("<I", data, off)[0]
        size = word & 0xFFFFFF
        if size == 0:
            return
        header = 0x80 if word & 0x80000000 else 0x10
        if (word >> 24) & 0x7F in (0x01, 0x05):
            yield off + header
        off += header + size


def convert(path, out):
    """Writes every texture in path under out/; returns the count (0 if not a texture set)."""
    data = open(path, "rb").read()
    try:
        bases = list(pac_texture_sets(data)) if path.endswith(".pac") else [0]
        texs = [(s, i, t) for s, base in enumerate(bases) for i, t in enumerate(textures(data, base))]
    except (ValueError, struct.error):
        return 0
    os.makedirs(out, exist_ok=True)
    stem = os.path.splitext(os.path.basename(path))[0]
    for s, i, t in texs:
        name = f"{stem}_{s}_{i:02d}.png" if len(bases) > 1 else f"{stem}_{i:02d}.png"
        write_png(os.path.join(out, name), t.width, t.height, t.rgba())
    return len(texs)


def _convert_job(job):
    return job[0], convert(*job)


def main(argv):
    if len(argv) == 4 and argv[1] == "all":
        from multiprocessing import Pool
        fs_dir, out_dir = argv[2], argv[3]
        jobs = []
        for root, _, names in os.walk(fs_dir):
            for name in sorted(names):
                if name.endswith((".tms", ".pac", ".dat")):
                    src = os.path.join(root, name)
                    rel = os.path.relpath(root, fs_dir)
                    jobs.append((src, os.path.join(out_dir, rel)))
        total = files = 0
        with Pool() as pool:
            for _, n in pool.imap_unordered(_convert_job, jobs):
                total += n
                files += n > 0
        print(f"wrote {total} textures from {files} files to {out_dir}")
    elif len(argv) >= 3 and argv[1] == "info":
        for path in argv[2:]:
            data = open(path, "rb").read()
            bases = list(pac_texture_sets(data)) if path.endswith(".pac") else [0]
            for base in bases:
                for i, t in enumerate(textures(data, base)):
                    print(f"{path} [{base:#x}] {i:3d}: {FORMATS[t.fmt][0]:6} {t.width}x{t.height}"
                          f" clut={t.clut_w}x{t.clut_h if t.clut_off is not None else 0} vram=({t.x},{t.y})")
    elif len(argv) >= 4 and argv[1] == "png":
        path, out = argv[2], argv[3]
        data = open(path, "rb").read()
        bases = list(pac_texture_sets(data)) if "--pac" in argv or path.endswith(".pac") else [0]
        os.makedirs(out, exist_ok=True)
        stem = os.path.splitext(os.path.basename(path))[0]
        n = 0
        for s, base in enumerate(bases):
            for i, t in enumerate(textures(data, base)):
                name = f"{stem}_{s}_{i:02d}.png" if len(bases) > 1 else f"{stem}_{i:02d}.png"
                write_png(os.path.join(out, name), t.width, t.height, t.rgba())
                n += 1
        print(f"{path}: wrote {n} textures")
    else:
        raise SystemExit(__doc__)


if __name__ == "__main__":
    main(sys.argv)
