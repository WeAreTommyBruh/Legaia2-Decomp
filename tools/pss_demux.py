#!/usr/bin/env python3
"""Splits a PS2 .pss movie (PALMOVIE.PSS) into MPEG-2 video and WAV audio.

PSS is an MPEG-2 program stream. Video is PES stream 0xE0 (written out as an
.m2v elementary stream, playable by most video players). Audio is in private
stream 1 (0xBD): each packet's payload starts with a 4-byte sub-header
(ff a0 00 00), and the audio stream begins with
  "SShd" u32 24, u32 format (1 = 16-bit PCM), u32 rate, u32 channels,
         u32 interleave, u32 loop start, u32 loop end
  "SSbd" u32 data size
followed by PCM interleaved per channel in `interleave`-byte blocks.

Usage: pss_demux.py FILE.pss OUT_PREFIX     -> OUT_PREFIX.m2v, OUT_PREFIX.wav
"""

import struct
import sys


def demux(path):
    with open(path, "rb") as f:
        d = f.read()
    video, audio, pts = bytearray(), bytearray(), []
    pos = 0
    while pos + 6 <= len(d):
        if d[pos:pos + 3] != b"\0\0\1":
            pos += 1
            continue
        sid = d[pos + 3]
        if sid == 0xBA:  # MPEG-2 pack header
            pos += 14 + (d[pos + 13] & 7)
            continue
        if sid == 0xB9:  # program end
            break
        length = int.from_bytes(d[pos + 4:pos + 6], "big")
        if sid in (0xE0, 0xBD):
            flags, hlen = d[pos + 7], d[pos + 8]
            payload = d[pos + 9 + hlen:pos + 6 + length]
            if sid == 0xE0:
                video += payload
                if flags & 0x80:
                    p = d[pos + 9:pos + 14]
                    pts.append(((p[0] >> 1) & 7) << 30 | p[1] << 22 | (p[2] >> 1) << 15 | p[3] << 7 | p[4] >> 1)
            else:
                audio += payload[4:]
        pos += 6 + length
    return bytes(video), bytes(audio), pts


def write_wav(path, audio):
    if audio[:4] != b"SShd":
        raise ValueError("audio stream has no SShd header")
    hsize = struct.unpack_from("<I", audio, 4)[0]
    fmt, rate, channels, interleave = struct.unpack_from("<4I", audio, 8)
    if fmt != 1:
        raise ValueError(f"unsupported audio format {fmt}")
    body = 8 + hsize
    if audio[body:body + 4] != b"SSbd":
        raise ValueError("no SSbd header")
    size = struct.unpack_from("<I", audio, body + 4)[0]
    pcm = audio[body + 8:body + 8 + size]
    block = interleave * channels
    pcm = pcm[:len(pcm) // block * block]
    chans = [bytearray() for _ in range(channels)]
    for off in range(0, len(pcm), block):
        for c in range(channels):
            chans[c] += pcm[off + c * interleave:off + (c + 1) * interleave]
    frames = len(chans[0]) // 2
    out = bytearray(frames * 2 * channels)
    for c in range(channels):
        out[2 * c::2 * channels] = chans[c][0:frames * 2:2]
        out[2 * c + 1::2 * channels] = chans[c][1:frames * 2:2]
    with open(path, "wb") as f:
        f.write(b"RIFF" + struct.pack("<I", 36 + len(out)) + b"WAVE")
        f.write(b"fmt " + struct.pack("<IHHIIHH", 16, 1, channels, rate, rate * channels * 2, channels * 2, 16))
        f.write(b"data" + struct.pack("<I", len(out)) + out)
    return frames / rate, rate, channels


def main(argv):
    if len(argv) != 3:
        raise SystemExit(__doc__)
    video, audio, pts = demux(argv[1])
    with open(argv[2] + ".m2v", "wb") as f:
        f.write(video)
    seconds, rate, channels = write_wav(argv[2] + ".wav", audio)
    span = (max(pts) - min(pts)) / 90000 if pts else 0
    print(f"video {len(video)} bytes (timestamps span {span:.1f}s); "
          f"audio {seconds:.1f}s, {rate} Hz, {channels} channels")


if __name__ == "__main__":
    main(sys.argv)
