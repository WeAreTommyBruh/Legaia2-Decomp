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
  0x80 + body size: the "SShd" table, read by FUN_002d3b98 (0x002d3b98):
       0x0c "SShd"; 0x10, 0x18, 0x1c, 0x20, 0x24 section offsets (-1 = none)
       0x24 programs: u16 last index, u16 offset per program (0xffff = none)
            program: 8-byte header; byte 0 = tone count - 1, or 0xff for a
            "drum" program with one tone per key from byte 6 to byte 7 (every
            bank on the disc uses drum programs); a tone whose byte 0x0d is
            0xff ends the list early
            tone (16 bytes): 0x02 root note, 0x03 s8 fine tune (1/16 semitone),
            0x04 u16 sample address in 8-byte units (from the body start),
            0x06/0x08 SPU ADSR1/ADSR2, 0x0a/0x0b key range, 0x0c pan,
            0x0d pitch-bend range, 0x0e volume
       0x20 per-program bend/volume state; 0x1c sound-effect sequences
Pitch (sound driver sndn2drv.irx, function at 0x0a90): the driver looks up its
own 16-steps-per-semitone table, shifts by octaves and scales by 441/480, so a
tone played at its root note with no fine tune runs at exactly 44,100 Hz. Each
sample is therefore written at 44100 * table[0xd0 + fine] / 4096 Hz, using the
fine tune of the tones that play it.

Usage:
  adpcm.py FILE.int OUT.wav
  adpcm.py all FS_DIR OUT_DIR             every .int under FS_DIR
  adpcm.py snd FILE.snd OUT_DIR [--rate N] one WAV per sample in a sound bank
  adpcm.py tones FILE.snd                 list the bank's programs and tones
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
    """Yields (body offset, frames) for each sample in a .snd bank body."""
    body_size = struct.unpack_from("<I", data, 4)[0]
    body = data[0x80:0x80 + body_size]
    frames, start = [], 0
    for off in range(0, len(body) - 15, 16):
        fr = body[off:off + 16]
        frames.append(fr)
        if fr[1] & 1:
            # a lone end frame after a sample is a terminator, not a sample
            if len(frames) > 1 and any(any(f[2:]) for f in frames):
                yield start, frames
            frames, start = [], off + 16


# The driver's pitch table: 16 steps per semitone, 0x1000 at index 0xd0.
PITCH = [round(4096 * 2 ** ((i - 0xD0) / (12 * 16))) for i in range(400)]


def tones(data):
    """Yields (program, tone index, root note, fine, sample offset) from the SShd table."""
    body_size = struct.unpack_from("<I", data, 4)[0]
    t = data[0x80 + body_size:]
    if t[12:16] != b"SShd":
        return
    sec = struct.unpack_from("<i", t, 0x24)[0]
    if sec < 0:
        return
    last = struct.unpack_from("<H", t, sec)[0]
    for prog in range(last + 1):
        po = struct.unpack_from("<H", t, sec + 2 + 2 * prog)[0]
        if po == 0xFFFF:
            continue
        hdr = t[sec + po:sec + po + 8]
        count = hdr[7] - hdr[6] + 1 if hdr[0] == 0xFF else (hdr[0] & 0x7F) + 1
        for i in range(count):
            r = sec + po + 8 + 16 * i
            if r + 16 > len(t) or t[r + 0x0D] == 0xFF:
                break
            root, fine, addr = t[r + 2], struct.unpack_from("<b", t, r + 3)[0], struct.unpack_from("<H", t, r + 4)[0]
            yield prog, i, root, fine, addr * 8


def sample_rates(data):
    """Maps sample body offset -> playback rate at its root note."""
    fines = {}
    for _, _, _, fine, off in tones(data):
        fines.setdefault(off, []).append(fine)
    return {off: round(RATE * PITCH[0xD0 + max(set(f), key=f.count)] / 4096) for off, f in fines.items()}


def convert_snd(src, out_dir, rate=None):
    with open(src, "rb") as f:
        data = f.read()
    os.makedirs(out_dir, exist_ok=True)
    stem = os.path.splitext(os.path.basename(src))[0]
    rates = sample_rates(data)
    n = 0
    for i, (off, frames) in enumerate(snd_samples(data)):
        r = rate or rates.get(off, RATE)
        write_wav(os.path.join(out_dir, f"{stem}_{i:03d}.wav"), [decode(frames)], r)
        n += 1
    return n


def main(argv):
    if len(argv) >= 4 and argv[1] == "snd":
        rate = int(argv[argv.index("--rate") + 1]) if "--rate" in argv else None
        print(convert_snd(argv[2], argv[3], rate), "samples")
    elif len(argv) == 3 and argv[1] == "tones":
        for prog, i, root, fine, off in tones(open(argv[2], "rb").read()):
            print(f"program {prog:3d} tone {i:3d}: root {root:3d} fine {fine:+4d} sample @{off:#x}")
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
