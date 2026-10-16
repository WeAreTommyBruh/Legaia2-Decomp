#!/usr/bin/env python3
"""Lists and unpacks Legaia 2 effect packs (.efp), which bundle .efb effects.

Layout (parser eftpack_00202f88 @ 0x00202f88):
  u32 version 0x3e9 (1001; the game prints it as "1.001"), u32 ?, u32 count
  (packs without the version word start directly with the count)
  count entries of 24 bytes: u32 size, u32 offset, char name[16]
  offsets are relative to the end of the entry table.
58 of the 59 packs on the disc use this layout; bpack1.efp uses an older one
without names and is reported as unsupported. The .efb effect format itself is
not decoded yet.

Usage:
  efp_tool.py list FILE.efp [...]
  efp_tool.py extract FILE.efp OUT_DIR
"""

import os
import struct
import sys


def entries(data):
    first = struct.unpack_from("<I", data, 0)[0]
    if first == 0x3E9:
        count, table = struct.unpack_from("<I", data, 8)[0], 12
    else:
        count, table = first, 4
    base = table + count * 0x18
    out = []
    for i in range(count):
        size, off = struct.unpack_from("<II", data, table + i * 0x18)
        raw = data[table + i * 0x18 + 8:table + i * 0x18 + 24].split(b"\0")[0]
        if not raw or not all(0x20 <= c < 0x7F for c in raw) or base + off + size > len(data):
            raise ValueError("unsupported pack layout")
        out.append((raw.decode("ascii"), base + off, size))
    return out


def main(argv):
    if len(argv) >= 3 and argv[1] == "list":
        for path in argv[2:]:
            try:
                for name, off, size in entries(open(path, "rb").read()):
                    print(f"{path} {name:<16} {off:#8x} {size:7d}")
            except ValueError as e:
                print(f"{path}: {e}")
    elif len(argv) == 4 and argv[1] == "extract":
        data = open(argv[2], "rb").read()
        os.makedirs(argv[3], exist_ok=True)
        ents = entries(data)
        for name, off, size in ents:
            with open(os.path.join(argv[3], name), "wb") as f:
                f.write(data[off:off + size])
        print(f"extracted {len(ents)} effects to {argv[3]}")
    else:
        raise SystemExit(__doc__)


if __name__ == "__main__":
    main(sys.argv)
