#!/usr/bin/env python3
"""Lists and unpacks Legaia 2 effect packs (.efp), which bundle .efb effects.

Layout (parser eftpack_00202f88 @ 0x00202f88):
  u32 version 0x3e9 (1001; the game prints it as "1.001"), u32 ?, u32 count
  (packs without the version word start directly with the count)
  count entries of 24 bytes: u32 size, u32 offset, char name[16]
  offsets are relative to the end of the entry table.
58 of the 59 packs on the disc use this layout; bpack1.efp uses an older one
without names and is reported as unsupported. Packs hold .efb effects and
texture sets (.dat, readable with tex_tool.py).

.efb effects are command streams of 4-byte words, run by FUN_001984e8
(0x001984e8), which hands parameters to the setter ikumi_001992c8:
  01/02/03 xx xx xx, u32 parameter id (0-95), then N argument words, where N
           comes from the game's table at 0x00443cc8 (ARG_COUNTS below)
  05, u32 value          sets a target (stored at +0x124)
  06, s8 value           selects a slot 0-63 (stored at +0x330)
  08, u32                ignored
  ff ff 00 00            end
Every effect on the disc parses exactly to its end.

The opcode picks the kind of object the slot holds (parameter 0 creates it):
  01 particle emitter (nayuki.cpp)  02 water-surface effect (mizuki.cpp)
  03 ring effect (yue.cpp)
Parameter names below come from what the game does with each value: the
emitter's spawn (nayuki_001da5f0) and update (nayuki_001db5a0) code, and the
editor's own range warnings for kinds 2 and 3. Emitter vector parameters take
(value, random spread, mode); x/y/z are separate parameters. A trailing "?"
marks a meaning that is likely but not proven; unlisted ids are unknown.
Ring parameters 0x11-0x17 are per-circle tweens (start, end, duration, delay,
circle index, mode); the ring builder yue_001ec090 places each vertex at
(radius_x * cos, height, radius_z * sin).

Usage:
  efp_tool.py list FILE.efp [...]
  efp_tool.py extract FILE.efp OUT_DIR
  efp_tool.py efb FILE.efb               print an effect's commands
"""

import os
import struct
import sys


ARG_COUNTS = (
    1, 3, 3, 2, 1, 1, 4, 4, 1, 5, 1, 1, 5, 5, 5, 1, 1, 6, 6, 6, 6, 6, 6, 6,
    5, 5, 5, 5, 5, 5, 5, 5, 1, 1, 1, 1, 3, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 1, 1, 3, 4, 4, 8, 4, 4, 4, 3, 3, 3)


_XYZ = "xyz"
PARAM_NAMES = {
    1: {0x00: "create", 0x01: "reset", 0x0A: "particle_timer?", 0x20: "render_mode",
        0x22: "texture?", 0x24: "max_particles", 0x25: "spawn_value", 0x53: "spawn_flags",
        0x54: "motion_flags", 0x41: "size_a", 0x42: "size_b", 0x43: "size_a_growth",
        0x44: "size_b_growth", 0x45: "size_a_growth_accel", 0x46: "size_b_growth_accel",
        0x47: "alpha?", 0x48: "alpha_rate?", 0x49: "alpha_accel?"},
    2: {0x00: "create", 0x03: "transparency"},
    3: {0x00: "create", 0x0F: "subdivisions", 0x10: "circle_count", 0x11: "height?",
        0x12: "radius_x", 0x13: "radius_z", 0x14: "transparency",
        0x15: "red", 0x16: "green", 0x17: "blue"},
}
for i, a in enumerate(_XYZ):
    PARAM_NAMES[1].update({
        0x26 + i: "spawn_offset_" + a, 0x29 + i: "velocity_" + a, 0x2C + i: "acceleration_" + a,
        0x2F + i: "rotation_" + a, 0x32 + i: "rotation_speed_" + a,
        0x38 + i: "vector4_" + a + "?", 0x3B + i: "vector4_rate_" + a + "?"})
for i, c in enumerate(("red", "green", "blue")):
    PARAM_NAMES[1].update({0x4A + i: c, 0x4D + i: c + "_rate", 0x50 + i: c + "_accel"})


def param_name(kind, pid):
    return PARAM_NAMES.get(kind, {}).get(pid, f"param_{pid:#04x}")


def effect_commands(data):
    """Yields (opcode, parameter id or None, [argument words])."""
    pos = 0
    while pos + 4 <= len(data):
        op = data[pos]
        pos += 4
        if op in (1, 2, 3):
            pid = struct.unpack_from("<i", data, pos)[0]
            if not 0 <= pid < len(ARG_COUNTS):
                raise ValueError(f"bad parameter id {pid} at {pos:#x}")
            n = ARG_COUNTS[pid]
            yield op, pid, list(struct.unpack_from(f"<{n}I", data, pos + 4))
            pos += 4 + 4 * n
        elif op in (5, 6, 8):
            yield op, None, [struct.unpack_from("<I", data, pos)[0]]
            pos += 4
        elif op == 0xFF:
            return
        else:
            raise ValueError(f"unknown opcode {op:#x} at {pos - 4:#x}")


def show_word(w):
    exp = (w >> 23) & 0xFF
    if w and 0x60 <= exp <= 0x9F:
        return f"{struct.unpack('<f', struct.pack('<I', w))[0]:g}"
    return str(w - (1 << 32) if w & 0x80000000 else w)


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
    elif len(argv) == 3 and argv[1] == "efb":
        kinds = {1: "emitter", 2: "water", 3: "ring"}
        names = {5: "target", 6: "slot", 8: "nop"}
        for op, pid, args in effect_commands(open(argv[2], "rb").read()):
            label = (f"{kinds[op]}.{param_name(op, pid)}" if pid is not None else names[op]).ljust(28)
            if op == 6:
                args = [args[0] & 0xFF if args[0] & 0xFF < 0x80 else (args[0] & 0xFF) - 256]
                print(f"{label} {args[0]}")
            else:
                print(f"{label} " + " ".join(show_word(w) for w in args))
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
