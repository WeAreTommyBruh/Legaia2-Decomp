#!/usr/bin/env python3
"""Lists the animation clips in Legaia 2 motion files (.mov, and .moz after lzss.py).

Container: u32 clip count, then one u32 byte offset per clip (holds for every
.mov on the disc). Clip header, as far as known:
  0x00 u8 0x10, u8 0x2a
  0x02 u16 grows with the clip's size; most likely the frame count
  0x08 char name[16]   (e.g. "..._std" for a standing pose)
  0x2c u32[7] offsets of the clip's sections, from the clip start
The keyframe data is not decoded yet.

Usage: mov_tool.py FILE.mov [...]
"""

import struct
import sys


def clips(data):
    count = struct.unpack_from("<I", data, 0)[0]
    offsets = list(struct.unpack_from(f"<{count}I", data, 4)) + [len(data)]
    if offsets[0] != 4 + 4 * count:
        raise ValueError("not a motion file")
    for i in range(count):
        o = offsets[i]
        frames = struct.unpack_from("<H", data, o + 2)[0]
        name = data[o + 8:o + 24].split(b"\0")[0].decode("latin1")
        yield i, name, frames, offsets[i + 1] - o


def main(argv):
    if len(argv) < 2:
        raise SystemExit(__doc__)
    for path in argv[1:]:
        data = open(path, "rb").read()
        for i, name, frames, size in clips(data):
            print(f"{path} {i:3d} {name:<16} frames? {frames:5d}  {size:7d} bytes")


if __name__ == "__main__":
    main(sys.argv)
