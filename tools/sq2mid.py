#!/usr/bin/env python3
"""Converts Legaia 2 .sq music sequences ("SSsq") to standard MIDI files.

Layout:
  0x00 u16 ?, u16 ticks per quarter note (480), u16 tempo in BPM; 0x0c "SSsq"
  0x10 16 channel records of 16 bytes: u8 ?, u8 channel, u8 program (0xff = unused),
       u8 volume, u8 pan, ...
  0x110 events: MIDI-style messages, each followed by its delta time (variable
       length, 7 bits per byte). Running status is allowed. Differences from MIDI:
       pitch bend (0xEn) has one data byte (0x40 = centre); tempo is ff 51 followed
       by a u16 BPM; ff 2f 00 ends the sequence. Controllers 0x60-0x63 are the
       driver's loop markers (see libsndno.h on the disc).
Programs refer to the game's own sound banks, so the MIDI plays with General
MIDI instruments rather than the game's.

Usage:
  sq2mid.py FILE.sq OUT.mid
  sq2mid.py check FILE.sq [...]
"""

import struct
import sys

DATA_LEN = {0x80: 2, 0x90: 2, 0xA0: 2, 0xB0: 2, 0xC0: 1, 0xD0: 1, 0xE0: 1}


def read_varlen(d, pos):
    value = 0
    while True:
        b = d[pos]
        pos += 1
        value = (value << 7) | (b & 0x7F)
        if not b & 0x80:
            return value, pos


def varlen(v):
    out = bytearray([v & 0x7F])
    v >>= 7
    while v:
        out.insert(0, 0x80 | (v & 0x7F))
        v >>= 7
    return bytes(out)


def parse(d):
    """Returns (ppqn, bpm, programs, events); events are (delta_before, raw bytes)."""
    if d[0x0C:0x10] != b"SSsq":
        raise ValueError("no SSsq magic")
    _, ppqn, bpm = struct.unpack_from("<3H", d, 0)
    programs = {}
    for ch in range(16):
        rec = d[0x10 + 16 * ch:0x20 + 16 * ch]
        if rec[2] != 0xFF:
            programs[rec[1]] = (rec[2], rec[3], rec[4])
    pos, status, delta, events = 0x110, None, 0, []
    while pos < len(d):
        b = d[pos]
        if b == 0xFF:
            kind = d[pos + 1]
            if kind == 0x2F:
                events.append((delta, b"\xff\x2f\x00"))
                return ppqn, bpm, programs, events
            if kind != 0x51:
                raise ValueError(f"unknown meta event {kind:#x} at {pos:#x}")
            events.append((delta, d[pos:pos + 4]))
            pos += 4
        else:
            if b & 0x80:
                status = b
                pos += 1
            elif status is None:
                raise ValueError(f"data byte without status at {pos:#x}")
            n = DATA_LEN[status & 0xF0]
            raw = bytes([status]) + d[pos:pos + n]
            if any(x & 0x80 for x in raw[1:]):
                raise ValueError(f"bad data byte at {pos:#x}")
            pos += n
            events.append((delta, raw))
        delta, pos = read_varlen(d, pos)
    raise ValueError("no end-of-track event")


def to_midi(ppqn, bpm, programs, events):
    track = bytearray()
    track += varlen(0) + b"\xff\x51\x03" + struct.pack(">I", 60_000_000 // max(bpm, 1))[1:]
    for ch, (prog, vol, pan) in sorted(programs.items()):
        track += varlen(0) + bytes([0xC0 | ch, prog & 0x7F])
        track += varlen(0) + bytes([0xB0 | ch, 7, vol & 0x7F])
        track += varlen(0) + bytes([0xB0 | ch, 10, pan & 0x7F])
    for delta, raw in events:
        if raw[:2] == b"\xff\x51":
            tempo = struct.unpack_from("<H", raw, 2)[0]
            raw = b"\xff\x51\x03" + struct.pack(">I", 60_000_000 // max(tempo, 1))[1:]
        elif raw[0] & 0xF0 == 0xE0:
            raw = bytes([raw[0], 0, raw[1]])
        track += varlen(delta) + raw
    header = b"MThd" + struct.pack(">IHHH", 6, 0, 1, ppqn)
    return header + b"MTrk" + struct.pack(">I", len(track)) + bytes(track)


def main(argv):
    if len(argv) >= 3 and argv[1] == "check":
        for path in argv[2:]:
            try:
                ppqn, bpm, programs, events = parse(open(path, "rb").read())
                notes = sum(1 for _, r in events if r[0] & 0xF0 == 0x90 and len(r) == 3 and r[2])
                print(f"{path}: ok, {ppqn} ppqn, {bpm} bpm, {len(programs)} channels,"
                      f" {len(events)} events, {notes} notes")
            except (ValueError, IndexError, KeyError) as e:
                print(f"{path}: FAILED ({e})")
    elif len(argv) == 3:
        with open(argv[2], "wb") as f:
            f.write(to_midi(*parse(open(argv[1], "rb").read())))
        print(argv[2])
    else:
        raise SystemExit(__doc__)


if __name__ == "__main__":
    main(sys.argv)
