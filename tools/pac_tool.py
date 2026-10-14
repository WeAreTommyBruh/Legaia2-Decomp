#!/usr/bin/env python3
"""Lists and splits Legaia 2 .pac files (field/battle map packages).

Format, from the game's loader clas_min_002a3a70 (0x002a3a70): a sequence of
chunks, each starting with a u32 header word
    bits 0-23   data size in bytes
    bits 24-30  chunk type
    bit  31     header size: set = 0x80 bytes, clear = 0x10 bytes
followed by the data. The next chunk starts after header + data; a header with
size 0 ends the file. The rest of each header is unused (it holds leftover
memory from the conversion tool).

There are two loaders. Room/battle maps (the .pac files on the disc) go through
clas_min_002a3a70; area maps (world.pac, volcano.pac, ... which exist only as
.lzs) go through clas_min_002a3278 (0x002a3278).

    type  room loader                         area loader
    0x01  pointer kept; texture data for the  pointer kept (texture data)
          model packet (8-bit pixels + CLUTs)
    0x02  copied; model packet input       ignored
    0x03  copied; model packet built       copied; model packet built
          (modelpkt_00180070)                 (modelpkt_001801d0)
    0x04  copied; map data                 copied; map data
          (mapdata_0015a1f8)                  (mapdata_0015a1f8)
    0x05  -                                   same as 0x01
    0x07  -                                   map objects (object_00242f40 + model packet)
    0x08  -                                   name table; looked up and handed
                                              to shikimi_002b3f10
    0x09  -                                   map data (FUN_0015a570)
    0x0a  copied; map object (+0x14)       copied; map object
    0x0b  -                                   debug print only
    0x0d  copied; table queried by name    ignored
          (FUN_00160568)
    0x15  -                                   pointer kept
    0x1e, 0x1f  -                             textures (FUN_001e4120)
    0x20  -                                   effect pack (eftpack.cpp)
    0x28  textures (FUN_001e4120)             -
    0x46, 0x47  ignored                       copied; extra model packets
"copied" = clas_min_002a3950 (PacChunkCopy) copies the chunk into its own
allocation so it outlives the file buffer.

Usage:
  pac_tool.py list FILE.pac [...]
  pac_tool.py split FILE.pac OUT_DIR    writes OUT_DIR/NN_typeXX.bin per chunk
"""

import os
import struct
import sys

TYPE_NAMES = {
    0x01: "texture",
    0x02: "model_info",
    0x03: "model_packet",
    0x04: "map_data",
    0x05: "texture",
    0x07: "objects",
    0x08: "name_table",
    0x09: "map_data2",
    0x0A: "map_object",
    0x0D: "name_table",
    0x1E: "textures",
    0x1F: "textures",
    0x20: "effects",
    0x28: "textures",
    0x46: "model_extra",
    0x47: "model_extra",
}


def chunks(data):
    """Yields (type, header_offset, header_size, data_size)."""
    off = 0
    while off + 4 <= len(data):
        word = struct.unpack_from("<I", data, off)[0]
        size = word & 0xFFFFFF
        if size == 0:
            return
        header = 0x80 if word & 0x80000000 else 0x10
        yield (word >> 24) & 0x7F, off, header, size
        off += header + size
    raise ValueError("ran past the end of the file without an end marker")


def main(argv):
    if len(argv) >= 3 and argv[1] == "list":
        for path in argv[2:]:
            with open(path, "rb") as f:
                data = f.read()
            print(path)
            for t, off, header, size in chunks(data):
                print(f"  {off:#09x}  type {t:#04x} {TYPE_NAMES.get(t, '?'):<13} {size:#9x} bytes")
    elif len(argv) == 4 and argv[1] == "split":
        with open(argv[2], "rb") as f:
            data = f.read()
        os.makedirs(argv[3], exist_ok=True)
        for i, (t, off, header, size) in enumerate(chunks(data)):
            name = f"{i:02d}_type{t:02x}_{TYPE_NAMES.get(t, 'unknown')}.bin"
            with open(os.path.join(argv[3], name), "wb") as f:
                f.write(data[off + header:off + header + size])
            print(name)
    else:
        raise SystemExit(__doc__)


if __name__ == "__main__":
    main(sys.argv)
