#!/usr/bin/env python3
"""Decompresses Legaia 2 .lzs files.

Codec (decode.cpp, decode_001908f0 @ 0x001908f0): u32 decompressed size, then a
stream of flag bytes, each governing 8 items (lowest bit first): 1 = literal
byte; 0 = two bytes b0 b1 giving a 12-bit window position (b0 | (b1 & 0xF0) << 4)
and length (b1 & 0xF) + 3. The 4 KB window starts zero-filled with the write
position at 0xFEE (classic Okumura LZSS).

An .lzs file is either
  - one compressed file: u32 size != 0 (usually the matching .pac), or
  - an archive of compressed files: u32 0, u32 0, u32 count, u32 total size, then
    count entries {u32 offset, char path[32]}; each member is compressed as above.

.moz files are single compressed files too: motion data in the .mov layout
(they differ from the same-named .mov files).

Usage:
  lzss.py FILE.lzs OUT          single file -> OUT; archive -> members under OUT/
  lzss.py --all FS_DIR OUT_DIR  every .lzs (-> .pac) and .moz (-> .mov) under FS_DIR
"""

import os
import struct
import sys


def decompress(data, start=0):
    """Returns (decompressed bytes, offset just past the compressed stream)."""
    size = struct.unpack_from("<I", data, start)[0]
    out = bytearray(size)
    pos, o, r, flags = start + 4, 0, 0xFEE, 0
    while o < size:
        flags >>= 1
        if not flags & 0x100:
            flags = data[pos] | 0xFF00
            pos += 1
        if flags & 1:
            out[o] = data[pos]
            pos += 1
            o += 1
            r = (r + 1) & 0xFFF
        else:
            b0, b1 = data[pos], data[pos + 1]
            pos += 2
            n = (b1 & 0xF) + 3
            src = o + (((b0 | (b1 & 0xF0) << 4) - r) & 0xFFF) - 0x1000
            r = (r + n) & 0xFFF
            for _ in range(min(n, size - o)):
                out[o] = out[src] if src >= 0 else 0
                o += 1
                src += 1
    return bytes(out), pos


def is_archive(data):
    return struct.unpack_from("<II", data, 0) == (0, 0)


def archive_members(data):
    """Yields (path, decompressed bytes) for each member of an archive .lzs."""
    count = struct.unpack_from("<I", data, 8)[0]
    for i in range(count):
        off = struct.unpack_from("<I", data, 16 + 36 * i)[0]
        path = data[20 + 36 * i:52 + 36 * i].split(b"\0")[0].decode("latin1")
        yield path, decompress(data, off)[0]


def unpack(src, dst):
    """Writes a single .lzs to dst, or an archive's members under dst/.
    Returns the list of files written."""
    with open(src, "rb") as f:
        data = f.read()
    written = []
    if is_archive(data):
        for path, body in archive_members(data):
            out = os.path.join(dst, path)
            os.makedirs(os.path.dirname(out), exist_ok=True)
            with open(out, "wb") as f:
                f.write(body)
            written.append(out)
    else:
        os.makedirs(os.path.dirname(dst) or ".", exist_ok=True)
        with open(dst, "wb") as f:
            f.write(decompress(data)[0])
        written.append(dst)
    return written


def main(argv):
    if len(argv) == 4 and argv[1] == "--all":
        fs_dir, out_dir = argv[2], argv[3]
        n = 0
        for root, _, names in os.walk(fs_dir):
            for name in sorted(names):
                if not name.endswith((".lzs", ".moz")):
                    continue
                src = os.path.join(root, name)
                rel = os.path.relpath(src, fs_dir)
                dst = os.path.join(out_dir, rel[:-4] + (".pac" if name.endswith(".lzs") else ".mov"))
                with open(src, "rb") as f:
                    archive = is_archive(f.read(8))
                n += len(unpack(src, os.path.join(out_dir, rel[:-4]) if archive else dst))
        print(f"wrote {n} files to {out_dir}")
    elif len(argv) == 3:
        for path in unpack(argv[1], argv[2]):
            print(path)
    else:
        raise SystemExit(__doc__)


if __name__ == "__main__":
    main(sys.argv)
