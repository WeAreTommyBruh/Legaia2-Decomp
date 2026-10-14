#!/usr/bin/env python3
"""Lists and extracts the Legaia 2 (PAL, SLES-50891) file system archive.

The game keeps its data in one virtual volume split across FS.BIN, FS1.BIN and
FS2.BIN (each file continues where the previous one ends), indexed by FS.DIR.
Everything is read straight from the disc image.

FS.DIR layout (all little-endian):
  0x00  u32  version (2)
  0x04  u16  number of extensions (61)
  0x06  u16  offset of the entry table (0x110)
  0x10  extensions, 4 bytes each, characters stored last-to-first
  ...   entries, 16 bytes each:
          0x0  name, 8 bytes, characters stored last-to-first
          0x8  directory: u16 subdir count, u16 file count, u32 entries below it
               file:      u16 extension index, u16 size in sectors, u32 start sector
        Entries are depth-first: a directory, then its files, then its subdirectories.

Bytes from 0x10 onward are encrypted. The game decrypts them in FUN_001897c8
(0x001897c8): key = 0x6E6B7270 * (u16@4 ^ u16@6); each u32 is XORed with key,
then key = key * 5 + 1.

Files are stored in whole 2048-byte sectors; their exact byte size is not in
FS.DIR, so extracted files keep the sector padding.

Usage:
  fs_tool.py ISO list
  fs_tool.py ISO extract OUTDIR [GLOB ...]
  fs_tool.py ISO dir OUTFILE         (write the decrypted FS.DIR)
"""

import fnmatch
import os
import struct
import sys

SECTOR = 2048
KEY_MULT = 0x6E6B7270
VOLUME_PARTS = ("FS.BIN", "FS1.BIN", "FS2.BIN")


class Iso:
    """Minimal ISO 9660 reader for files in the root directory."""

    def __init__(self, path):
        self.f = open(path, "rb")
        pvd = self.read(16 * SECTOR, SECTOR)
        if pvd[1:6] != b"CD001":
            raise SystemExit(f"{path}: not an ISO 9660 image")
        root = pvd[156:156 + 34]
        lba, size = struct.unpack_from("<I", root, 2)[0], struct.unpack_from("<I", root, 10)[0]
        self.files = {}
        data = self.read(lba * SECTOR, size)
        pos = 0
        while pos < len(data):
            rec_len = data[pos]
            if rec_len == 0:  # records never span sectors
                pos = (pos // SECTOR + 1) * SECTOR
                continue
            ext_lba, ext_size = struct.unpack_from("<I", data, pos + 2)[0], struct.unpack_from("<I", data, pos + 10)[0]
            name_len = data[pos + 32]
            name = data[pos + 33:pos + 33 + name_len].decode("latin1").split(";")[0]
            self.files[name.upper()] = (ext_lba, ext_size)
            pos += rec_len

    def read(self, offset, size):
        self.f.seek(offset)
        return self.f.read(size)

    def read_file(self, name):
        lba, size = self.files[name]
        return self.read(lba * SECTOR, size)


def decrypt_dir(raw):
    d = bytearray(raw)
    if struct.unpack_from("<I", d, 0)[0] != 2:
        raise SystemExit("FS.DIR: unexpected version")
    a, b = struct.unpack_from("<HH", d, 4)
    key = (KEY_MULT * (a ^ b)) & 0xFFFFFFFF
    for off in range(16, len(d) - 3, 4):
        struct.pack_into("<I", d, off, struct.unpack_from("<I", d, off)[0] ^ key)
        key = (key * 5 + 1) & 0xFFFFFFFF
    return bytes(d)


def parse_dir(d):
    """Returns [(path, start_sector, sector_count)]."""
    n_ext, table = struct.unpack_from("<HH", d, 4)
    exts = [d[16 + 4 * i:20 + 4 * i][::-1].rstrip(b"\0").decode("latin1") for i in range(n_ext)]
    entries = []
    for off in range(table, len(d) - 15, 16):
        name = d[off:off + 8][::-1].rstrip(b"\0").decode("latin1")
        entries.append((name,) + struct.unpack_from("<HHI", d, off + 8))

    files = []

    def walk(i, path):
        _, n_sub, n_files, below = entries[i]
        j = i + 1
        for _ in range(n_files):
            name, ext, sectors, start = entries[j]
            files.append(("/".join(path + [name]) + ("." + exts[ext] if exts[ext] else ""), start, sectors))
            j += 1
        for _ in range(n_sub):
            j = walk(j, path + [entries[j][0]])
        if j - i - 1 != below:
            raise SystemExit(f"FS.DIR: bad subtree size at entry {i}")
        return j

    walk(0, [])  # entry 0 is ROOT; its children carry the real path names
    return files


class Volume:
    """The FS.BIN + FS1.BIN + FS2.BIN volume, addressed by sector."""

    def __init__(self, iso):
        self.iso = iso
        self.parts = []  # (first_sector, sector_count, iso_lba)
        first = 0
        for name in VOLUME_PARTS:
            lba, size = iso.files[name]
            self.parts.append((first, size // SECTOR, lba))
            first += size // SECTOR
        self.sectors = first

    def read(self, start, count):
        out = bytearray()
        while count > 0:
            for first, n, lba in self.parts:
                if first <= start < first + n:
                    take = min(count, first + n - start)
                    out += self.iso.read((lba + start - first) * SECTOR, take * SECTOR)
                    start += take
                    count -= take
                    break
            else:
                raise SystemExit(f"sector {start} is outside the volume")
        return bytes(out)


def main(argv):
    if len(argv) < 3 or argv[2] not in ("list", "extract", "dir"):
        raise SystemExit(__doc__)
    iso = Iso(argv[1])
    d = decrypt_dir(iso.read_file("FS.DIR"))
    cmd = argv[2]
    if cmd == "dir":
        with open(argv[3], "wb") as f:
            f.write(d)
        return
    files = parse_dir(d)
    if cmd == "list":
        print("path,start_sector,sectors,bytes")
        for path, start, sectors in files:
            print(f"{path},{start},{sectors},{sectors * SECTOR}")
        return
    out_dir, patterns = argv[3], argv[4:]
    vol = Volume(iso)
    done = 0
    for path, start, sectors in files:
        if patterns and not any(fnmatch.fnmatch(path, p) for p in patterns):
            continue
        dest = os.path.join(out_dir, path)
        os.makedirs(os.path.dirname(dest), exist_ok=True)
        with open(dest, "wb") as f:
            f.write(vol.read(start, sectors))
        done += 1
    print(f"extracted {done} files to {out_dir}")


if __name__ == "__main__":
    main(sys.argv)
