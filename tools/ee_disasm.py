#!/usr/bin/env python3
"""Minimal R5900 (PS2 Emotion Engine) disassembler producing assembly that
clang's MIPS assembler accepts (target mips64el, -mcpu=mips4, -mabi=n32,
.set noreorder / noat).

decode(word, pc) returns (mnemonic, operands, target) or None. target is the
branch or jump destination (or None). None means "emit as .word": every
EE-only instruction (lq/sq, MMI, COP0/COP2, EE FPU extras, 3-operand mult)
plus anything unusual. The build compares every byte with the original, so
a wrong decode shows up immediately; split.py then falls back to .word.

Usage: ee_disasm.py WORD [PC]      decode one hex word
"""

import sys

# registers by number: n32 and o32 name $8-$15 differently
R = tuple(f"${i}" for i in range(32))
F = tuple(f"$f{i}" for i in range(32))

SPECIAL_3 = {0x20: "add", 0x21: "addu", 0x22: "sub", 0x23: "subu", 0x24: "and",
             0x25: "or", 0x26: "xor", 0x27: "nor", 0x2A: "slt", 0x2B: "sltu",
             0x2C: "dadd", 0x2D: "daddu", 0x2E: "dsub", 0x2F: "dsubu",
             0x0A: "movz", 0x0B: "movn"}
SPECIAL_SHIFT = {0x00: "sll", 0x02: "srl", 0x03: "sra", 0x38: "dsll", 0x3A: "dsrl",
                 0x3B: "dsra", 0x3C: "dsll32", 0x3E: "dsrl32", 0x3F: "dsra32"}
SPECIAL_SHIFTV = {0x04: "sllv", 0x06: "srlv", 0x07: "srav", 0x14: "dsllv",
                  0x16: "dsrlv", 0x17: "dsrav"}
IMM = {0x08: "addi", 0x09: "addiu", 0x0A: "slti", 0x0B: "sltiu", 0x18: "daddi",
       0x19: "daddiu"}
IMMU = {0x0C: "andi", 0x0D: "ori", 0x0E: "xori"}
MEM = {0x1A: "ldl", 0x1B: "ldr", 0x20: "lb", 0x21: "lh", 0x22: "lwl", 0x23: "lw",
       0x24: "lbu", 0x25: "lhu", 0x26: "lwr", 0x27: "lwu", 0x28: "sb", 0x29: "sh",
       0x2A: "swl", 0x2B: "sw", 0x2C: "sdl", 0x2D: "sdr", 0x2E: "swr", 0x37: "ld",
       0x3F: "sd"}
FMEM = {0x31: "lwc1", 0x39: "swc1"}
BR2 = {0x04: "beq", 0x05: "bne", 0x14: "beql", 0x15: "bnel"}
BR1 = {0x06: "blez", 0x07: "bgtz", 0x16: "blezl", 0x17: "bgtzl"}
REGIMM = {0x00: "bltz", 0x01: "bgez", 0x02: "bltzl", 0x03: "bgezl",
          0x10: "bltzal", 0x11: "bgezal"}
FPU_S3 = {0x00: "add.s", 0x01: "sub.s", 0x02: "mul.s", 0x03: "div.s"}
FPU_S2 = {0x05: "abs.s", 0x06: "mov.s", 0x07: "neg.s", 0x24: "cvt.w.s"}
# the EE calls these c.lt.s and c.le.s; standard MIPS (and clang) c.olt.s and c.ole.s
FPU_CMP = {0x30: "c.f.s", 0x32: "c.eq.s", 0x34: "c.olt.s", 0x36: "c.ole.s"}


def s16(x):
    return x - 0x10000 if x & 0x8000 else x


def decode(w, pc):
    op, rs, rt = w >> 26, (w >> 21) & 31, (w >> 16) & 31
    rd, sa, fn = (w >> 11) & 31, (w >> 6) & 31, w & 63
    imm = w & 0xFFFF
    btarget = pc + 4 + (s16(imm) << 2)
    if w == 0:
        return "nop", "", None
    if op == 0:
        if fn in SPECIAL_SHIFT and rs == 0:
            return SPECIAL_SHIFT[fn], f"{R[rd]}, {R[rt]}, {sa}", None
        if fn in SPECIAL_SHIFTV and sa == 0:
            return SPECIAL_SHIFTV[fn], f"{R[rd]}, {R[rt]}, {R[rs]}", None
        if fn in SPECIAL_3 and sa == 0:
            return SPECIAL_3[fn], f"{R[rd]}, {R[rs]}, {R[rt]}", None
        if fn == 0x08 and rt == rd == sa == 0:
            return "jr", R[rs], None
        if fn == 0x09 and rt == sa == 0:
            return "jalr", f"{R[rd]}, {R[rs]}", None
        if fn in (0x10, 0x12) and rs == rt == sa == 0:
            return ("mfhi", "mflo")[fn == 0x12], R[rd], None
        if fn in (0x11, 0x13) and rt == rd == sa == 0:
            return ("mthi", "mtlo")[fn == 0x13], R[rs], None
        if fn in (0x18, 0x19) and rd == sa == 0:
            return ("mult", "multu")[fn & 1], f"{R[rs]}, {R[rt]}", None
        if fn in (0x1A, 0x1B) and rd == sa == 0:
            return ("div", "divu")[fn & 1], f"$zero, {R[rs]}, {R[rt]}", None
        if fn == 0x0F and w == 0x0F:
            return "sync", "", None
        return None
    if op == 1 and rt in REGIMM:
        return REGIMM[rt], f"{R[rs]}, .L{btarget:08X}", btarget
    if op in (2, 3):
        target = (pc & 0xF0000000) | ((w & 0x03FFFFFF) << 2)
        return ("j", "jal")[op == 3], f"func_{target:08X}", target
    if op in BR2:
        return BR2[op], f"{R[rs]}, {R[rt]}, .L{btarget:08X}", btarget
    if op in BR1 and rt == 0:
        return BR1[op], f"{R[rs]}, .L{btarget:08X}", btarget
    if op in IMM:
        return IMM[op], f"{R[rt]}, {R[rs]}, {s16(imm)}", None
    if op in IMMU:
        return IMMU[op], f"{R[rt]}, {R[rs]}, {imm:#x}", None
    if op == 0x0F and rs == 0:
        return "lui", f"{R[rt]}, {imm:#x}", None
    if op in MEM:
        return MEM[op], f"{R[rt]}, {s16(imm)}({R[rs]})", None
    if op in FMEM:
        return FMEM[op], f"{F[rt]}, {s16(imm)}({R[rs]})", None
    if op == 0x11:
        if rs in (0, 4) and sa == 0 and fn == 0:
            return ("mfc1", "mtc1")[rs == 4], f"{R[rt]}, {F[rd]}", None
        if rs in (2, 6) and sa == 0 and fn == 0:
            return ("cfc1", "ctc1")[rs == 6], f"{R[rt]}, ${rd}", None
        if rs == 8 and rt in (0, 1, 2, 3):
            name = ("bc1f", "bc1t", "bc1fl", "bc1tl")[rt]
            return name, f".L{btarget:08X}", btarget
        if rs == 0x10:
            fs, fd = rd, sa
            if fn in FPU_S3:
                return FPU_S3[fn], f"{F[fd]}, {F[fs]}, {F[rt]}", None
            if fn in FPU_S2 and rt == 0:
                return FPU_S2[fn], f"{F[fd]}, {F[fs]}", None
            if fn in FPU_CMP and fd == 0:
                return FPU_CMP[fn], f"{F[fs]}, {F[rt]}", None
        if rs == 0x14 and fn == 0x20 and rt == 0:
            return "cvt.s.w", f"{F[sa]}, {F[rd]}", None
    return None


if __name__ == "__main__":
    if len(sys.argv) < 2:
        raise SystemExit(__doc__)
    w = int(sys.argv[1], 16)
    pc = int(sys.argv[2], 16) if len(sys.argv) > 2 else 0
    print(decode(w, pc) or f".word {w:#010x}")
