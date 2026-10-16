#!/usr/bin/env python3
"""Lists and decodes Legaia 2 animation clips (.mov, .moz after lzss.py, mon*move.dat).

Container: u32 clip count, then one u32 byte offset per clip.

Clip header:
  0x00 u8  bone count
  0x01 u8  flags: bit 0 = stored at half rate (see below); 0x04, 0x80 not known
  0x02 u16 frame count
  0x04 u8  ? (0 in 99.6% of clips)
  0x05 u8  index map length       0x06 u8 root bone (0-based)
  0x07 u8  hierarchy length, including its 0xff end marker
  0x08 char name[16]
  0x28 f32 (varies per clip; meaning unknown)
  0x2c u32[7] section offsets from the clip start:
       0 hierarchy   1 index map   2 bone records (24 bytes each)
       3 bone names (null-terminated, packed)  4 reserved (16 zero bytes in
       every clip)  5 segments (8 bytes each)  6 values (s16)
Hierarchy: bones are numbered from 1 (bone k = bone record k-1); 0 is the
model root. The list is a run of chains ended by 0xff: a value not seen
before is a new bone whose parent is the previous value; a value already seen
starts a new chain from that bone. E.g. a hand reads root->4 (the hand), then
4->1->2->3, 4->5->6->7, ... one chain per finger.
Index map: one u8 bone index (0-based) per bone slot of the model the clip
drives, in part order (see tmd_tool.py): a skinned part has as many slots as
its weight table says, a part with flag 0x01 has none, any other part has one.
E.g. a monster's helmet and mask parts map to its head bone and its sword to
the right-hand bone. Its length matches the model's slot total for all 4,769
clips stored next to their model, except three files shared with a sibling
model (mon012.mov fits mon012a, mon034.mov mon034c, ply02b.mov ply02).
Bone record: u32 ?, u16 channel mask (0x3f = all six), u16 first segment of each
channel: tx, ty, tz, rx, ry, rz.
Segment: u32 value offset (in s16 units), u16 key count, u8 mode, u8 flag.
  mode 1: one value held for all its keys; mode 0: one value per key.
A channel's segments are consecutive and their key counts add up to the
clip's key count: the frame count, or frame count / 2 + 1 for clips with the
half-rate flag (every second frame plus the last). Rotations use 4096 =
360 degrees (all values stay within +-8192, almost all within +-2048);
translations are in model units.
98.6% of the 38,542 clips on the disc use this layout; the rest (no sections,
or offsets outside the clip) are other variants and are reported as unsupported.

Usage:
  mov_tool.py FILE [...]                list clips
  mov_tool.py dump FILE OUT.json        decode every supported clip
  mov_tool.py bind FILE.mov FILE.tmd    show which bone drives each model part
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

    half = c[1] & 1
    keys = frames // 2 + 1 if half else frames

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
    slot_bones = list(c[so[1]:so[1] + c[5]])
    if any(b >= nbones for b in slot_bones):
        raise ValueError("index map names a missing bone")
    return {"name": name, "frames": frames, "key_step": 2 if half else 1,
            "root": c[6], "slot_bones": slot_bones, "bones": bones}


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
    elif len(argv) == 4 and argv[1] == "bind":
        import tmd_tool
        data = open(argv[2], "rb").read()
        offsets = clip_offsets(data)
        clip = decode_clip(data[offsets[0]:offsets[1]])
        names = [b["name"] or f"bone_{i}" for i, b in enumerate(clip["bones"])]
        model = tmd_tool.models(open(argv[3], "rb").read())[0]
        if model.bad:
            raise SystemExit(f"{argv[3]}: {len(model.bad)} parts not supported")
        if model.slots != len(clip["slot_bones"]):
            raise SystemExit(f"model has {model.slots} bone slots, clip maps {len(clip['slot_bones'])}")
        slot = 0
        for p in model.parts:
            bones = [names[b] for b in clip["slot_bones"][slot:slot + p.slots]]
            print(f"{p.name:<16} " + (" ".join(bones) if bones else "(no bone)"))
            slot += p.slots
    elif len(argv) >= 2:
        for path in argv[1:]:
            for i, name, frames, size in clips(open(path, "rb").read()):
                print(f"{path} {i:3d} {name:<16} frames {frames:5d}  {size:7d} bytes")
    else:
        raise SystemExit(__doc__)


if __name__ == "__main__":
    main(sys.argv)
