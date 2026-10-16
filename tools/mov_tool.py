#!/usr/bin/env python3
"""Lists and decodes Legaia 2 animation clips (.mov, .moz after lzss.py, mon*move.dat).

Container: u32 clip count, then one u32 byte offset per clip.
The game reads clips through the accessors at 0x00212f00-0x00214150 (MotClip,
MotHierarchy, MotTranslation, ...), which take one path or the other on flag
0x20 below.

Clip header:
  0x00 u8  bone count
  0x01 u8  flags: 0x01 half rate (new layout), 0x08 has bone records,
           0x10 has scale channels, 0x20 packed (new) layout, 0x80 rotations
           in 1/16384 turns instead of 1/4096; 0x02, 0x04, 0x40 not known
  0x02 u16 frame count
  0x04 u8  translation shift: translations are value << shift (new layout)
  0x05 u8  index map length       0x06 u8 root bone (0-based)
  0x07 u8  hierarchy length, including its 0xff end marker
  0x08 char name[16]

New (packed) layout, 99.4% of clips:
  0x28 f32 (varies per clip; meaning unknown)
  0x2c s32[7] section offsets from the clip start:
       0 hierarchy   1 index map   2 bone records (24 bytes each)
       3 bone names (null-terminated)  4 base vectors (16 bytes each; all
       zero on the disc)  5 segments (8 bytes each)  6 values (s16)
       285 short clips have negative offsets: they reuse the sections of an
       earlier clip in the same file.
  0x48 u32 extra tables (0 or 0xffffffff = none); the sections start after them
       bit 2: +0x50 offset of blend envelopes: u32 count, 16-byte entries
              (u16 ?, u16 target[2], s16 frames[4]); the weight rises 0->1
              from frames[0] to frames[1], stays 1 until frames[2] and falls
              back to 0 at frames[3]
       bit 4: +0x54 offset of attachments: u32 count, 32-byte entries
              (u32 attachment point, ..., char clip[12] at +0x10); the named
              clip (e.g. a hand pose) plays on the attached object in sync
       bit 1: +0x4c, not read by the accessors (not decoded)
  Bone record: u16 name offset (into section 3), u16 base vector index,
  u16 channel mask, u16 first segment of each channel: tx, ty, tz, rx, ry, rz,
  sx, sy, sz (scale only with flag 0x10; scale = value / 256).
  Segment: u32 value offset (in s16 units), u16 key count, u8 mode, u8 flag.
    mode 1: one value held for all its keys; mode 0: one value per key.
  A channel's segments are consecutive and their key counts add up to the
  clip's key count: the frame count, or frame count / 2 + 1 for clips with the
  half-rate flag (every second frame plus the last).

Old (uncompressed) layout, flag 0x20 clear (239 clips in 28 files, mostly
test and early versions):
  with flag 0x08: 0x68 header, then hierarchy-length records of 0x30 bytes
  (char name[16]; f32[4] base vector at +0x20), then the hierarchy;
  without it the hierarchy follows an 8-byte header (these files size up
  only that way; the game's accessors expect 0x68).
  Then the index map, then for every frame 6 s16 per bone (tx, ty, tz, rx, ry,
  rz). Some files carry extra data after the last frame, which the game does
  not read. 15 clips in three test files (mon01x, skl_test, test) do not fit
  this and are reported as unsupported.

Both layouts: rotations use 4096 = 360 degrees unless flag 0x80 is set;
translations are in model units.
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
38,527 of the 38,542 clips on the disc decode.

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


def _extras(data, start):
    """Optional new-layout tables, selected by the u32 at +0x48."""
    flags = struct.unpack_from("<I", data, start + 0x48)[0]
    out = {}
    if flags == 0xFFFFFFFF:
        return out
    if flags & 2:
        t = start + struct.unpack_from("<I", data, start + 0x50)[0]
        out["envelopes"] = []
        for i in range(struct.unpack_from("<I", data, t)[0]):
            e = struct.unpack_from("<HHH4h", data, t + 4 + 16 * i)
            out["envelopes"].append({"target": [e[1], e[2]], "frames": list(e[3:7])})
    if flags & 4:
        t = start + struct.unpack_from("<I", data, start + 0x54)[0]
        out["attachments"] = []
        for i in range(struct.unpack_from("<I", data, t)[0]):
            e = t + 4 + 32 * i
            out["attachments"].append({
                "point": struct.unpack_from("<I", data, e)[0],
                "clip": data[e + 16:e + 28].split(b"\0")[0].decode("latin1")})
    return out


def decode_clip(data, start=0, end=None):
    """Decodes the clip at data[start:end] (both layouts)."""
    end = len(data) if end is None else end
    c = data[start:end]
    if len(c) < 8:
        raise ValueError("clip too small")
    nbones, flags, frames = c[0], c[1], struct.unpack_from("<H", c, 2)[0]
    if flags & 0x20:
        return _decode_new(data, start, end)
    # old, uncompressed layout: every frame stores 6 s16 per bone
    if flags & 8:
        base = 0x68 + 0x30 * c[7]
        names = [c[0x68 + 0x30 * b:0x78 + 0x30 * b].split(b"\0")[0] for b in range(nbones)]
        name = c[8:24].split(b"\0")[0].decode("latin1")
    else:
        base, names, name = 8, [b""] * nbones, ""
    vstart = base + c[7] + c[5]
    if vstart + frames * nbones * 12 > len(c):
        raise ValueError("old-layout clip shorter than its frames")
    # a few test clips have no hierarchy at all (length 0)
    parent = hierarchy(c, base, base + c[7], nbones) if c[7] else {b: 0 for b in range(1, nbones + 1)}
    vals = struct.unpack_from(f"<{frames * nbones * 6}h", c, vstart)
    bones = []
    for b in range(nbones):
        bone = {"name": names[b].decode("latin1"), "parent": parent[b + 1] - 1 if parent[b + 1] else None}
        for k, ch in enumerate(CHANNELS):
            v = [vals[(f * nbones + b) * 6 + k] for f in range(frames)]
            bone[ch] = [round(x * 360 / 4096, 3) for x in v] if k >= 3 else v
        bones.append(bone)
    slot_bones = list(c[base + c[7]:vstart])
    if any(b >= nbones for b in slot_bones):
        raise ValueError("index map names a missing bone")
    return {"name": name, "layout": "old", "frames": frames, "key_step": 1,
            "root": c[6], "slot_bones": slot_bones, "bones": bones}


def _decode_new(data, start, end):
    c = data[start:end]
    if len(c) < 0x4C:
        raise ValueError("clip too small")
    nbones, flags, frames = c[0], c[1], struct.unpack_from("<H", c, 2)[0]
    name = c[8:24].split(b"\0")[0].decode("latin1")
    # offsets are relative to the clip and may be negative: short clips reuse
    # the sections of an earlier clip in the same file
    so = [start + x for x in struct.unpack_from("<7i", c, 0x2C)]
    if not all(0 <= x <= len(data) for x in so) or (so[3] - so[2]) // 24 != nbones:
        raise ValueError("unsupported clip layout")
    nseg = (so[6] - so[5]) // 8
    segs = [struct.unpack_from("<IHBB", data, so[5] + 8 * i) for i in range(nseg)]
    nvals = max((off + (1 if mode == 1 else cnt) for off, cnt, mode, _ in segs), default=0)
    values = struct.unpack_from(f"<{nvals}h", data, so[6])
    recs = [struct.unpack_from("<HHH9H", data, so[2] + 24 * b) for b in range(nbones)]

    def channel(first, keys):
        out, i = [], first
        while len(out) < keys:
            off, cnt, mode, _ = segs[i]
            out += [values[off]] * cnt if mode == 1 else list(values[off:off + cnt])
            i += 1
        if len(out) != keys:
            raise ValueError("segments overrun the key count")
        return out

    half = flags & 1
    keys = frames // 2 + 1 if half else frames
    turn = 16384 if flags & 0x80 else 4096
    parent = hierarchy(data, so[0], so[1], nbones)
    bones = []
    for b, rec in enumerate(recs):
        raw = data[so[3] + rec[0]:so[4]].split(b"\0")[0]
        bone = {"name": raw.decode("latin1"), "parent": parent[b + 1] - 1 if parent[b + 1] else None}
        for k, ch in enumerate(CHANNELS + ("sx", "sy", "sz")):
            if rec[2] >> k & 1 and (k < 6 or flags & 0x10):
                v = channel(rec[3 + k], keys)
                if k < 3:
                    v = [x << c[4] for x in v]
                elif k < 6:
                    v = [round(x * 360 / turn, 3) for x in v]
                else:
                    v = [x / 256 for x in v]
                bone[ch] = v
        bones.append(bone)
    slot_bones = list(data[so[1]:so[1] + c[5]])
    if any(b >= nbones for b in slot_bones):
        raise ValueError("index map names a missing bone")
    out = {"name": name, "layout": "new", "frames": frames, "key_step": 2 if half else 1,
           "root": c[6], "slot_bones": slot_bones, "bones": bones}
    out.update(_extras(data, start))
    return out


def main(argv):
    if len(argv) == 4 and argv[1] == "dump":
        data = open(argv[2], "rb").read()
        offsets = clip_offsets(data)
        out, bad = [], 0
        for i in range(len(offsets) - 1):
            try:
                out.append(decode_clip(data, offsets[i], offsets[i + 1]))
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
        clip = decode_clip(data, offsets[0], offsets[1])
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
