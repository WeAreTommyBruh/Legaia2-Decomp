/* Functions of this report unit, matched by hand. */
// cflags: -fexceptions
#include "../common.h"

extern int D_004A1A20, D_004A6E24;
extern unsigned *D_003279A0[];
extern char D_00430D40[], D_00430D68[];
int func_0012A938(void);
int func_001118F8(char *, ...);
void func_00124020(int);

// MATCH func_001252A0
void battle_001252a0(int actor)
{
    unsigned *object;
    int entry, debug;

    if (func_0012A938() != 0)
        func_001118F8(D_00430D40);
    object = D_003279A0[actor];
    if (object != 0) {
        object[48] |= 0x24;
        entry = actor * 0x1560 + D_004A1A20;
        debug = D_004A6E24;
        *(unsigned *)(entry + 0x12d0) |= 0x40000;
        if (debug != 0) {
            func_001118F8(D_00430D68, actor, *(int *)(entry + 0x1378));
            func_00124020(actor);
        }
    }
}

typedef struct { char p[16]; long *q; } P_00127BB8_00127BB8;
extern P_00127BB8_00127BB8 D_00342CD0_127BB8 __asm__("D_00342CD0");
void func_00190328_127BB8(P_00127BB8_00127BB8 *) __asm__("func_00190328"); void func_00190420_127BB8(P_00127BB8_00127BB8 *) __asm__("func_00190420");
// MATCH func_00127BB8
void battle_00127bb8(int a, int b, int c, int d, int e, int f, int g, int h, int i) { long *q; long col; int z; z = 0xffffff - i; func_00190328_127BB8(&D_00342CD0_127BB8); q = D_00342CD0_127BB8.q; col = (long)z << 32; q[0] = 0x31001; q[1] = 0x47; q[2] = 4; { float fq = 1.0f; q[4] = (unsigned long)*(unsigned int *)&fq << 32 | (unsigned long)0x80 << 24; } q[5] = 1; q[6] = (long)(a * 0x10 + 0x6c00) | (long)(b * 0x10 + 0x7900) << 16 | col; q[8] = (long)(c * 0x10 + 0x6c00) | (long)(d * 0x10 + 0x7900) << 16 | col; q[10] = (long)(e * 0x10 + 0x6c00) | (long)(f * 0x10 + 0x7900) << 16 | col; q[12] = (long)(g * 0x10 + 0x6c00) | (long)(h * 0x10 + 0x7900) << 16 | col; q[3] = 0; q[7] = 5; q[9] = 5; q[11] = 5; q[13] = 5; D_00342CD0_127BB8.q = q + 14; func_00190420_127BB8(&D_00342CD0_127BB8); }


typedef struct { char p[16]; long *q; } P_00127BB8_00127D50;
extern P_00127BB8_00127D50 D_00342CD0_00127D50 __asm__("D_00342CD0");
void func_00190328_00127D50(P_00127BB8_00127D50 *) __asm__("func_00190328"); void func_00190420_00127D50(P_00127BB8_00127D50 *) __asm__("func_00190420");
// MATCH func_00127D50
void battle_00127d50(int a, int b, int c, int d, int e, int f, int g, int h, int i) { long *q; long col; int z; z = 0xffffff - i; func_00190328_00127D50(&D_00342CD0_00127D50); q = D_00342CD0_00127D50.q; col = (long)z << 32; q[0] = 0x32001; q[1] = 0x47; q[2] = 4; { float fq = 1.0f; q[4] = (unsigned long)*(unsigned int *)&fq << 32 | (unsigned long)0x80 << 24; } q[5] = 1; q[6] = (long)(a * 0x10 + 0x6c00) | (long)(b * 0x10 + 0x7900) << 16 | col; q[8] = (long)(c * 0x10 + 0x6c00) | (long)(d * 0x10 + 0x7900) << 16 | col; q[10] = (long)(e * 0x10 + 0x6c00) | (long)(f * 0x10 + 0x7900) << 16 | col; q[12] = (long)(g * 0x10 + 0x6c00) | (long)(h * 0x10 + 0x7900) << 16 | col; q[3] = 0; q[7] = 5; q[9] = 5; q[11] = 5; q[13] = 5; D_00342CD0_00127D50.q = q + 14; func_00190420_00127D50(&D_00342CD0_00127D50); }

