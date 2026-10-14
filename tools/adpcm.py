#!/usr/bin/env python3
"""Converts Legaia 2 .int audio streams (music, voice, event audio) to WAV.

.int files are raw PS2 SPU ADPCM: 16-byte frames of 28 samples (byte 0 = shift
| filter << 4, byte 1 = flags, 14 bytes of 4-bit samples, low nibble first).
They are stereo, interleaved in 0x400-byte blocks (left, right, left, ...),
played at 44100 Hz: the stream player FUN_0010d8a0 (0x0010d8a0) sets SPU voices
1 and 2 to 0xac44 Hz and pans them hard left and right. The block size comes
from the data: songs start their audio at the same offset into the first left
and right blocks.

.snd files are sound banks:
  0x00 u32 version (2), 0x04 u32 body size, 0x08 u32 table size; filler to 0x80
  0x80 body: ADPCM samples back to back, each ending in a frame with flag bit 0
  0x80 + body size: "SShd" table block (program/tone records, ADSR, and
       sound-effect sequences in MIDI-like events: 0xa0 note-on, ff 2f 00 end).
The tone records (pitch per sample) are not decoded yet, so `snd` writes each
sample as mono WAV at an assumed rate (default 22050 Hz; pass --rate).

Usage:
  adpcm.py FILE.int OUT.wav
  adpcm.py all FS_DIR OUT_DIR             every .int under FS_DIR
  adpcm.py snd FILE.snd OUT_DIR [--rate N] one WAV per sample in a sound bank
"""

import os
import struct
import sys

BLOCK = 0x400
RATE = 44100
F0 = (0, 60, 115, 98, 122)
F1 = (0, 0, -52, -55, -60)


def decode(frames):
    """Decodes an iterable of 16-byte ADPCM frames to a list of int16 samples."""
    out = []
    append = out.append
    s1 = s2 = 0
    for fr in frames:
        shift = fr[0] & 0xF
        filt = fr[0] >> 4
        if filt > 4:
            filt = 0
        a, b = F0[filt], F1[filt]
        for byte in fr[2:16]:
            for nib in (byte & 0xF, byte >> 4):
                v = ((nib - 16 if nib > 7 else nib) << 12) >> shift
                v += (s1 * a + s2 * b + 32) >> 6
                if v > 32767:
                    v = 32767
                elif v < -32768:
                    v = -32768
                s2, s1 = s1, v
                append(v)
    return out


def split_channels(data, block=BLOCK, channels=2):
    chans = [[] for _ in range(channels)]
    n = len(data) // (block * channels) * (block * channels)
    for off in range(0, n, block):
        ch = (off // block) % channels
        blk = data[off:off + block]
        chans[ch].extend(blk[i:i + 16] for i in range(0, block, 16))
    return chans


def write_wav(path, channels, rate=RATE):
    n = min(len(c) for c in channels)
    nch = len(channels)
    inter = [0] * (n * nch)
    for c, samples in enumerate(channels):
        inter[c::nch] = samples[:n]
    pcm = struct.pack(f"<{len(inter)}h", *inter)
    with open(path, "wb") as f:
        f.write(b"RIFF" + struct.pack("<I", 36 + len(pcm)) + b"WAVE")
        f.write(b"fmt " + struct.pack("<IHHIIHH", 16, 1, nch, rate, rate * nch * 2, nch * 2, 16))
        f.write(b"data" + struct.pack("<I", len(pcm)) + pcm)


def convert(src, dst):
    with open(src, "rb") as f:
        data = f.read()
    left, right = split_channels(data)
    os.makedirs(os.path.dirname(dst) or ".", exist_ok=True)
    write_wav(dst, [decode(left), decode(right)])
    return dst


def _job(job):
    return convert(*job)


def snd_samples(data):
    """Yields the 16-byte frames of each sample in a .snd bank body."""
    body_size = struct.unpack_from("<I", data, 4)[0]
    body = data[0x80:0x80 + body_size]
    frames = []
    for off in range(0, len(body) - 15, 16):
        fr = body[off:off + 16]
        frames.append(fr)
        if fr[1] & 1:
            if any(any(f[2:]) for f in frames):
                yield frames
            frames = []


def convert_snd(src, out_dir, rate):
    with open(src, "rb") as f:
        data = f.read()
    os.makedirs(out_dir, exist_ok=True)
    stem = os.path.splitext(os.path.basename(src))[0]
    n = 0
    for i, frames in enumerate(snd_samples(data)):
        write_wav(os.path.join(out_dir, f"{stem}_{i:03d}.wav"), [decode(frames)], rate)
        n += 1
    return n


def main(argv):
    if len(argv) >= 4 and argv[1] == "snd":
        rate = int(argv[argv.index("--rate") + 1]) if "--rate" in argv else 22050
        print(convert_snd(argv[2], argv[3], rate), "samples")
    elif len(argv) == 4 and argv[1] == "all":
        from multiprocessing import Pool
        fs_dir, out_dir = argv[2], argv[3]
        jobs = []
        for root, _, names in os.walk(fs_dir):
            for name in sorted(names):
                if name.endswith(".int"):
                    rel = os.path.relpath(os.path.join(root, name), fs_dir)
                    jobs.append((os.path.join(fs_dir, rel), os.path.join(out_dir, rel[:-4] + ".wav")))
        with Pool() as pool:
            done = sum(1 for _ in pool.imap_unordered(_job, jobs, chunksize=4))
        print(f"wrote {done} files to {out_dir}")
    elif len(argv) == 3:
        print(convert(argv[1], argv[2]))
    else:
        raise SystemExit(__doc__)


if __name__ == "__main__":
    main(sys.argv)
