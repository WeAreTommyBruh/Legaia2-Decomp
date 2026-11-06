/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct { int f0; short s4; short s6; int f8; int f12; } R17_0017FC20;
extern int D_004A5148_17FC20 __asm__("D_004A5148");
int func_0018D800_17FC20(void) __asm__("func_0018D800"); int func_00241C98_17FC20(int, int) __asm__("func_00241C98"); long func_002D73E8_17FC20(unsigned long, unsigned long) __asm__("func_002D73E8"); unsigned short func_0017F650_17FC20(void *, void *) __asm__("func_0017F650"); int func_0017F760_17FC20(void *, void *, void *, int) __asm__("func_0017F760"); void func_0018D8B8_17FC20(int, int, int, int, int, int) __asm__("func_0018D8B8");
// MATCH func_0017FC20
int FUN_0017fc20(char *o, int flag) { R17_0017FC20 *res = 0; int x, h, n, r2; unsigned short *p, *q, r; unsigned u2; unsigned long u7; D_004A5148_17FC20 = 1; h = func_0018D800_17FC20(); p = *(unsigned short **)(o + 12); x = *(int *)(o + 64); while (*(int *)p != 0) { q = p; p += 4; u2 = *(unsigned *)(q + 2); u7 = *q; if ((q[1] >> 1) == 20) { res = (R17_0017FC20 *)func_00241C98_17FC20(x, 0); if (flag == 0) { res->f0 = (int)res + 16; r = func_0017F650_17FC20((char *)res + 16, p); res->s4 = r; res->f8 = res->f0 + ((int)((unsigned)r << 16) >> 12); res->s6 = q[1] & 1; } x = func_0017F760_17FC20(res, o, p, flag); u7 = 0; res->f12 = x; } n = func_002D73E8_17FC20(u2, u7 + 1); p = p + n * 2; } *(int *)(o + 60) = *(int *)(o + 64); r2 = func_00241C98_17FC20(x, 0); *(short *)(o + 68) = (unsigned)(r2 - *(int *)(o + 64)) >> 4; if (res != 0) res->f12 = 0; func_0018D8B8_17FC20(h, 0, 0, 0, -4, 0xf00000); return 1; }

