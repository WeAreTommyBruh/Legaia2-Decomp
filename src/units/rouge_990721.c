/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
#include "../common.h"

typedef struct { char p0[16]; long *q; } Pk_133108_00133108;
extern Pk_133108_00133108 D_00342CD0_133108 __asm__("D_00342CD0");
extern int D_004A12B0_133108 __asm__("D_004A12B0");
void func_00190328_133108(Pk_133108_00133108 *) __asm__("func_00190328"); void func_00190420_133108(Pk_133108_00133108 *) __asm__("func_00190420");
// MATCH func_00133108
void rouge_00133108(int mode, unsigned long r, int g, int b) { long *q; func_00190328_133108(&D_00342CD0_133108); switch (mode) { case 0: if (D_004A12B0_133108 & 1) { D_00342CD0_133108.q[0] = 0xa0000; D_00342CD0_133108.q[1] = 76; D_00342CD0_133108.q += 2; } else { D_00342CD0_133108.q[0] = 0xa0046; D_00342CD0_133108.q[1] = 76; D_00342CD0_133108.q += 2; } break; case 1: { D_00342CD0_133108.q[0] = 0xa0000; D_00342CD0_133108.q[1] = 76; D_00342CD0_133108.q += 2; } break; case 2: { D_00342CD0_133108.q[0] = 0xa0046; D_00342CD0_133108.q[1] = 76; D_00342CD0_133108.q += 2; } break; case 3: { D_00342CD0_133108.q[0] = 0xa018a; D_00342CD0_133108.q[1] = 76; D_00342CD0_133108.q += 2; } break; case 4: { D_00342CD0_133108.q[0] = 0xa008c; D_00342CD0_133108.q[1] = 76; D_00342CD0_133108.q += 2; } break; default: return; } q = D_00342CD0_133108.q; q[0] = 100; q[1] = 66; q[2] = 0x5000d; q[3] = 71; q[4] = 0; q[5] = 74; q[6] = 6; q[7] = 0; q[8] = r | (unsigned long)g << 8 | (unsigned long)b << 16 | 0x3f80000000000000L; q[9] = 1; q[10] = 0; q[11] = 4; q[12] = 0xffffffffL; q[13] = 4; D_00342CD0_133108.q = q + 14; func_00190420_133108(&D_00342CD0_133108); }


typedef struct { char p0[16]; long *q; } Pk_1332C0_001332C0;
extern Pk_1332C0_001332C0 D_00342CD0_001332C0 __asm__("D_00342CD0");
extern int D_004A12B0_001332C0 __asm__("D_004A12B0");
void func_00190328_001332C0(Pk_1332C0_001332C0 *) __asm__("func_00190328"); void func_00190420_001332C0(Pk_1332C0_001332C0 *) __asm__("func_00190420");
// MATCH func_001332C0
void rouge_001332c0(int mode, int a) { long *q; unsigned long pk; func_00190328_001332C0(&D_00342CD0_001332C0); switch (mode) { case 0: if (D_004A12B0_001332C0 & 1) { D_00342CD0_001332C0.q[0] = 0xffffff000a0000L; D_00342CD0_001332C0.q[1] = 76; D_00342CD0_001332C0.q += 2; } else { D_00342CD0_001332C0.q[0] = 0xffffff000a0046L; D_00342CD0_001332C0.q[1] = 76; D_00342CD0_001332C0.q += 2; } break; case 1: { D_00342CD0_001332C0.q[0] = 0xffffff000a0000L; D_00342CD0_001332C0.q[1] = 76; D_00342CD0_001332C0.q += 2; } break; case 2: { D_00342CD0_001332C0.q[0] = 0xffffff000a0046L; D_00342CD0_001332C0.q[1] = 76; D_00342CD0_001332C0.q += 2; } break; case 3: { D_00342CD0_001332C0.q[0] = 0xffffff000a018aL; D_00342CD0_001332C0.q[1] = 76; D_00342CD0_001332C0.q += 2; } break; case 4: { D_00342CD0_001332C0.q[0] = 0xffffff000a008cL; D_00342CD0_001332C0.q[1] = 76; D_00342CD0_001332C0.q += 2; } break; default: return; } q = D_00342CD0_001332C0.q; pk = (unsigned long)a << 24 | 0x3f80000000000000L; q[0] = 68; q[1] = 66; q[2] = 0x31001; q[3] = 71; q[4] = 6; q[5] = 0; q[6] = 0; q[7] = 3; q[8] = pk; q[9] = 1; q[10] = 0x79006c00; q[11] = 4; q[12] = 0xe002800; q[13] = 3; q[14] = pk; q[15] = 1; q[16] = 0x87009400L; q[17] = 4; D_00342CD0_001332C0.q = q + 18; func_00190420_001332C0(&D_00342CD0_001332C0); }
