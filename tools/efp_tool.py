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

Effects are written as text and compiled to .efb; EfbExec (0x00198790) runs
either form. The text is a list of "section:" lines and "command args" lines
(";" starts a comment). The game's own names, from EfbSectionNames
(0x0036cc10) and EfbCommandNames (0x0036cc50), are used below. A binary .efb
is the same thing as a stream of 4-byte words, run by EfbRun (0x001984e8):
  01/02/03 xx xx xx, u32 command id (0-95), then N argument words, where N
           comes from EfbParamArgCounts (0x00443cc8, ARG_COUNTS below):
           a command for a particle / aqua / model object
  05, u32 value          time: start frame of the objects created after it
  06, s8 value           effect_number: the object slot (0-63) commands go to
  08, u32                id (ignored)
  ff ff 00 00            end
The other section names (ver 0, end 4, name 7) only appear in the text form.
Every effect on the disc parses exactly to its end. The game passes each
command to EfbSetParam (0x001992c8); EfbCommandKinds (0x0036ce50) says which
object kinds accept it (COMMAND_KINDS below), and every command on the disc is
sent to a kind that accepts it.

Object kinds (command init creates one in the current slot):
  particle  particle emitter (nayuki.cpp)
  aqua      water surface (mizuki.cpp)
  model     procedural model built from circles, e.g. rings and cylinders
            (yue.cpp; the "wa_" commands are per-circle, wa = ring)
What the commands do, from the code each one reaches:
  particle  drawtime: particle lifetime in frames (copied into each particle
            and counted down). apptime: frames the emitter keeps spawning
            (0 = forever). drper: chance a particle spawns, out of 1000.
            ptnum: particle count. texanipt: texture animation pattern count
            (the game rejects 0). pt_pos* / pt_sp* / pt_ap*: spawn offset,
            speed and acceleration (speed is added to position and
            acceleration to speed each frame); pt_ang*, pt_rot*, pt_size*,
            pt_alpha*, pt_cl_* (colour) follow the same value / sp (speed) /
            ap (acceleration) pattern. Each takes (value, random spread, mode).
            center_x/y/z: a tweened point (start, end, duration, delay)
            rotated by the angles center_mx/my/mz (value, speed, acceleration);
            with option bits 0x1800000000 particles are pulled towards it
            (option bit 0x8 flips the direction). texdraw: 1 = textured
            (0 frees the texture). texpattarn: texture number.
            rolltx/rollty: integer tweens (start, end, duration, delay, mode)
            the emitter stores but never reads.
  aqua      see: transparency (0-255, the game warns above 255).
  model     division: subdivisions; circlenum: circle count; wa_height,
            wa_radiusx, wa_radiusy, wa_see (transparency), wa_colorr/g/b:
            per-circle tweens (start, end, duration, delay, circle, mode); the
            builder yue_001ec090 places each vertex at
            (radius_x * cos, height, radius_y * sin).
Commands not described above are known by name only.

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

SECTIONS = ("ver", "particle", "aqua", "model", "end", "time", "effect_number", "name", "id")

# EfbCommandNames, indexed by command id
COMMANDS = (
    "init", "pos", "angle", "see", "motion_ht", "motion_pt", "texroll", "wavemt",
    "strain", "scale", "drawtime", "apptime", "angle_x", "angle_y", "angle_z", "division",
    "circlenum", "wa_height", "wa_radiusx", "wa_radiusy", "wa_see", "wa_colorr", "wa_colorg",
    "wa_colorb", "rolltx", "rollty", "pos_x", "pos_y", "pos_z", "rot_x", "rot_y", "rot_z",
    "form", "texdraw", "texpattarn", "screen", "ptnum", "texanipt", "pt_posx", "pt_posy",
    "pt_posz", "pt_spx", "pt_spy", "pt_spz", "pt_apx", "pt_apy", "pt_apz", "pt_angx",
    "pt_angy", "pt_angz", "pt_angspx", "pt_angspy", "pt_angspz", "pt_angapx", "pt_angapy",
    "pt_angapz", "pt_rotx", "pt_roty", "pt_rotz", "pt_rotspx", "pt_rotspy", "pt_rotspz",
    "pt_rotapx", "pt_rotapy", "pt_rotapz", "pt_sizex", "pt_sizey", "pt_sizespx", "pt_sizespy",
    "pt_sizeapx", "pt_sizeapy", "pt_alpha", "pt_alphasp", "pt_alphaap", "pt_cl_r", "pt_cl_g",
    "pt_cl_b", "pt_clsp_r", "pt_clsp_g", "pt_clsp_b", "pt_clap_r", "pt_clap_g", "pt_clap_b",
    "animeflag", "option", "drawnum", "formcoe", "range", "drper", "spread", "center_x",
    "center_y", "center_z", "center_mx", "center_my", "center_mz")

# EfbCommandKinds: which of particle / aqua / model accept each command
COMMAND_KINDS = (
    "111", "111", "011", "010", "010", "010", "010", "010", "010", "001", "100", "100",
    "001", "001", "001", "001", "001", "001", "001", "001", "001", "001", "001", "001",
    "101", "101", "001", "001", "001", "001", "001", "001", "101", "101", "101", "001")
COMMAND_KINDS += ("100",) * 48 + ("101", "001", "001", "010", "100", "001") + ("100",) * 6


def accepts(kind, cid):
    return COMMAND_KINDS[cid][kind - 1] == "1"


def effect_commands(data):
    """Yields (opcode, command id or None, [argument words])."""
    pos = 0
    while pos + 4 <= len(data):
        op = data[pos]
        pos += 4
        if op in (1, 2, 3):
            cid = struct.unpack_from("<i", data, pos)[0]
            if not 0 <= cid < len(ARG_COUNTS):
                raise ValueError(f"bad command id {cid} at {pos:#x}")
            n = ARG_COUNTS[cid]
            yield op, cid, list(struct.unpack_from(f"<{n}I", data, pos + 4))
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
        for op, cid, args in effect_commands(open(argv[2], "rb").read()):
            label = (f"{SECTIONS[op]}.{COMMANDS[cid]}" if cid is not None else SECTIONS[op]).ljust(24)
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
