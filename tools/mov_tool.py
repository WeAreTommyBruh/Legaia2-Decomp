#!/usr/bin/env python3
"""Lists and decodes Legaia 2 animation clips (.mov, .moz after lzss.py, mon*move.dat).

Container: u32 clip count, then one u32 byte offset per clip.

Clip header:
  0x00 u8 (varies; spread like a bone count), u8 ?
  0x02 u16 frame count
  0x08 char name[16]
  0x28 f32 (varies per clip; meaning unknown)
  0x2c u32[7] section offsets from the clip start:
       0 hierarchy   1 index map   2 bone records (24 bytes each)
       3 bone names (null-terminated, packed)  4 ?  5 segments (8 bytes each)
       6 values (s16)
Hierarchy: bones are numbered from 1 (bone k = bone record k-1); 0 is the
model root. The list is a run of chains ended by 0xff: a value not seen
before is a new bone whose parent is the previous value; a value already seen
starts a new chain from that bone. E.g. a hand reads root->4 (the hand), then
4->1->2->3, 4->5->6->7, ... one chain per finger.
Bone record: u32 ?, u16 channel mask (0x3f = all six), u16 first segment of each
channel: tx, ty, tz, rx, ry, rz.
Segment: u32 value offset (in s16 units), u16 key count, u8 mode, u8 flag.
  mode 1: one value held for all its keys; mode 0: one value per key.
A channel's segments are consecutive and their key counts add up to the
clip's key count: either the frame count, or frame count / 2 + 1 for clips
stored at half rate (every second frame plus the last). Rotations use 4096 =
360 degrees (all values stay within +-8192, almost all within +-2048);
translations are in model units.
About 95% of clips use this layout; the rest (no sections, or offsets outside
the clip) are other variants and are reported as unsupported.

Usage:
  mov_tool.py FILE [...]                list clips
  mov_tool.py dump FILE OUT.json        decode every supported clip
"""

import json
import struct
import sys

CHANNELS = ("tx", "ty", "tz", "rx", "ry", "rz")


def clip_offsets(data):
    count = struct.unpack_from("<I", data, 0)[0]
    offsets = list(struct.unpack_from(f"<{count}I", data, 4)) + [len(data)]
    if offsets[0] != 4 + 4 * count:
        raise ValueError("not a motion file")
    return offsets


def clips(data):
    offsets = clip_offsets(data)
    for i in range(len(offsets) - 1):
        o = offsets[i]
        frames = struct.unpack_from("<H", data, o + 2)[0]
        name = data[o + 8:o + 24].split(b"\0")[0].decode("latin1")
        yield i, name, frames, offsets[i + 1] - o


def hierarchy(c, start, end, nbones):
    """Returns parent[bone] for bones 1..nbones (0 = model root)."""
    parent, prev = {}, None
    for v in c[start:end]:
        if v == 0xFF:
            break
        if v != 0 and v not in parent:
            if prev is None:
                raise ValueError("hierarchy starts with a new bone")
            parent[v] = prev
        prev = v
    if sorted(parent) != list(range(1, nbones + 1)):
        raise ValueError("hierarchy does not cover every bone")
    return parent


def decode_clip(c):
    if len(c) < 0x48:
        raise ValueError("clip too small")
    frames = struct.unpack_from("<H", c, 2)[0]
    name = c[8:24].split(b"\0")[0].decode("latin1")
    so = list(struct.unpack_from("<7I", c, 0x2C)) + [len(c)]
    if so[5] == 0 or any(x > len(c) for x in so):
        raise ValueError("unsupported clip layout")
    nseg = (so[6] - so[5]) // 8
    segs = [struct.unpack_from("<IHBB", c, so[5] + 8 * i) for i in range(nseg)]
    nvals = (len(c) - so[6]) // 2
    values = struct.unpack_from(f"<{nvals}h", c, so[6])
    nbones = (so[3] - so[2]) // 24
    recs = [struct.unpack_from("<IH6H", c, so[2] + 24 * b) for b in range(nbones)]

    def channel(first, keys):
        out, i = [], first
        while len(out) < keys:
            off, cnt, mode, _ = segs[i]
            out += [values[off]] * cnt if mode == 1 else list(values[off:off + cnt])
            i += 1
        if len(out) != keys:
            raise ValueError("segments overrun the key count")
        return out

    # key count: the first channel's segments, up to where the next channel starts
    first, nxt = recs[0][2], recs[0][3] if recs[0][1] & 2 else nseg
    keys = sum(segs[i][1] for i in range(first, min(nxt, nseg))) if nxt > first else 0
    if keys not in (frames, frames // 2 + 1):
        # channels not laid out in order: accumulate until a valid count is hit
        keys, i = 0, first
        while i < nseg and keys < frames:
            keys += segs[i][1]
            i += 1
            if keys == frames // 2 + 1 and frames > 2:
                break
    if keys not in (frames, frames // 2 + 1):
        raise ValueError(f"key count {keys} does not match {frames} frames")
    step = 1 if keys == frames else 2

    names = c[so[3]:so[4]].split(b"\0")
    parent = hierarchy(c, so[0], so[1], nbones)
    bones = []
    for b, rec in enumerate(recs):
        raw = names[b] if b < len(names) else b""
        bone = {"name": raw.decode("latin1"), "parent": parent[b + 1] - 1 if parent[b + 1] else None}
        for k, ch in enumerate(CHANNELS):
            if rec[1] >> k & 1:
                v = channel(rec[2 + k], keys)
                bone[ch] = [round(x * 360 / 4096, 3) for x in v] if k >= 3 else v
        bones.append(bone)
    return {"name": name, "frames": frames, "key_step": step, "bones": bones}


def main(argv):
    if len(argv) == 4 and argv[1] == "dump":
        data = open(argv[2], "rb").read()
        offsets = clip_offsets(data)
        out, bad = [], 0
        for i in range(len(offsets) - 1):
            try:
                out.append(decode_clip(data[offsets[i]:offsets[i + 1]]))
            except (ValueError, IndexError, struct.error) as e:
                out.append({"index": i, "unsupported": str(e)})
                bad += 1
        with open(argv[3], "w") as f:
            json.dump(out, f)
        print(f"{argv[3]}: {len(out) - bad} clips decoded, {bad} unsupported")
    elif len(argv) >= 2:
        for path in argv[1:]:
            for i, name, frames, size in clips(open(path, "rb").read()):
                print(f"{path} {i:3d} {name:<16} frames {frames:5d}  {size:7d} bytes")
    else:
        raise SystemExit(__doc__)


if __name__ == "__main__":
    main(sys.argv)
