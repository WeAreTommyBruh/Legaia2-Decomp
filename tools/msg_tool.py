#!/usr/bin/env python3
"""Lists Legaia 2 event/message containers (the "EV" .dat files, e.g. data/battle/*.dat).

Layout (all little-endian):
  0x00 "EV\\x03\\x00"   magic
  0x04 u32           total size
  0x08 sections, 12 bytes each: char tag[4] ("1st\\x01", "MSG\\x01"), u32 offset, u32 count
       the section list ends where the first section's data offsets begin
  then, for MSG: count u32 offsets to null-terminated strings, "___\\0", u32 end offset

`list` prints the structure only. `extract` writes the strings (escaped, one per
line) to a local file for your own use; it is not meant for publishing.

Usage:
  msg_tool.py list FILE [...]
  msg_tool.py extract FILE OUT.txt
"""

import struct
import sys

MAGIC = b"EV\x03\x00"


def parse(data):
    if data[:4] != MAGIC:
        raise ValueError("not an EV container")
    total = struct.unpack_from("<I", data, 4)[0]
    sections = []
    off = 8
    while off + 12 <= total:
        tag = data[off:off + 4]
        if tag[3:] not in (b"\x01",) or not tag[:3].isalnum():
            break
        start, count = struct.unpack_from("<II", data, off + 4)
        sections.append((tag[:3].decode(), start, count))
        off += 12
    table = off
    messages = []
    for name, start, count in sections:
        if name != "MSG":
            continue
        offs = list(struct.unpack_from(f"<{count}I", data, table))
        for o in offs:
            end = data.index(b"\0", o)
            messages.append(data[o:end])
        table += 4 * count
    return total, sections, messages


def escape(b):
    return "".join(chr(c) if 0x20 <= c < 0x7F and c != 0x5C else f"\\x{c:02x}" for c in b)


def main(argv):
    if len(argv) >= 3 and argv[1] == "list":
        for path in argv[2:]:
            data = open(path, "rb").read()
            try:
                total, sections, messages = parse(data)
            except ValueError as e:
                print(f"{path}: {e}")
                continue
            secs = ", ".join(f"{n}@{s:#x}x{c}" for n, s, c in sections)
            lengths = [len(m) for m in messages]
            print(f"{path}: size {total:#x}, sections [{secs}], {len(messages)} messages,"
                  f" {sum(lengths)} bytes of text")
    elif len(argv) == 4 and argv[1] == "extract":
        _, _, messages = parse(open(argv[2], "rb").read())
        with open(argv[3], "w") as f:
            for i, m in enumerate(messages):
                f.write(f"{i:3d}\t{escape(m)}\n")
        print(f"wrote {len(messages)} messages to {argv[3]}")
    else:
        raise SystemExit(__doc__)


if __name__ == "__main__":
    main(sys.argv)
