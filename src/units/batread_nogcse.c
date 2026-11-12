/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct { int a0, a4, a8; } E_0021EAB0;
typedef struct { char pad[7240]; E_0021EAB0 e[32]; int n; } S_0021EAB0;
void func_0021EB20(void *, int, int, int);
// MATCH func_0021EAB0
void batread_0021eab0(S_0021EAB0 *s) { int i; for (i = 0; i < s->n; i++) func_0021EB20(s, s->e[i].a4, s->e[i].a8, s->e[i].a0); }

extern unsigned D_004A6FC4;
// MATCH func_0021EFE0
void batread_0021efe0(char *o) { int i; int *q; char *p; *(int *)(o + 0x1bf0) = 0; *(int *)(o + 0x1bec) = 0; *(int *)(o + 0x1bf4) = 0; q = (int *)(o + 0x1ba8); for (i = 15; i >= 0; i--) { *q = 0; q--; } p = o + 0x1200; do { if (*p == 8) *p = 0; p++; } while ((int)p < (int)(o + 0x1240)); D_004A6FC4 = 0; }



extern int D_004A6FDC_21F100 __asm__("D_004A6FDC"); extern int D_004A6FE4_21F100 __asm__("D_004A6FE4"); extern int D_004A6FE0_21F100 __asm__("D_004A6FE0"); extern int D_004A12B0_21F100 __asm__("D_004A12B0"); extern int D_004A6FC4_21F100 __asm__("D_004A6FC4"); extern int D_004A6FCC_21F100 __asm__("D_004A6FCC"); extern int D_004A6FD0_21F100 __asm__("D_004A6FD0"); extern int D_004A6FD4_21F100 __asm__("D_004A6FD4"); extern int D_004A6FD8_21F100 __asm__("D_004A6FD8"); extern char D_00343028_21F100[] __asm__("D_00343028"); extern char D_00457170_21F100[] __asm__("D_00457170"); extern char D_00457198_21F100[] __asm__("D_00457198"); extern char D_004571E8_21F100[] __asm__("D_004571E8"); extern char D_00457228_21F100[] __asm__("D_00457228"); extern char D_00457268_21F100[] __asm__("D_00457268"); extern char D_004572A8_21F100[] __asm__("D_004572A8");
int func_0010ABC0_21F100(char *, int, int, int) __asm__("func_0010ABC0"); void func_001118F8_21F100(char *, ...) __asm__("func_001118F8"); void func_00239568_21F100(char *, int, int) __asm__("func_00239568"); void func_002395A0_21F100() __asm__("func_002395A0");
// MATCH func_0021F100
int batread_0021f100(void) { int r; int lv; int n; if (D_004A6FDC_21F100 == 0) return 0; r = 1; if (D_004A6FE4_21F100 != 0) { if (D_004A6FE0_21F100 != D_004A12B0_21F100) { D_004A6FE0_21F100 = D_004A12B0_21F100; D_004A6FE4_21F100--; if (D_004A6FE4_21F100 == 0) D_004A6FDC_21F100 = 0; } if (D_004A6FC4_21F100 >= 301) func_00239568_21F100(D_00457170_21F100, D_004A6FD0_21F100, *(int *)(D_004A6FCC_21F100 + 4964)); return 1;  } lv = func_0010ABC0_21F100(D_00343028_21F100, 0, D_004A6FD4_21F100, D_004A6FD0_21F100); if (lv > 0) { func_001118F8_21F100(D_00457198_21F100, D_004A6FD8_21F100); { register int cmp __asm__("$3") = 0x179c00; if (D_004A6FD0_21F100 == cmp) { *(int *)(D_004A6FCC_21F100 + 5368) = lv; func_001118F8_21F100(D_004571E8_21F100, lv); } } if (0x1c4c00 == D_004A6FD0_21F100) { *(int *)(D_004A6FCC_21F100 + 5412) = lv; func_001118F8_21F100(D_00457228_21F100, lv); } r = 0; func_001118F8_21F100(D_00457268_21F100); { register int one __asm__("$3") = 1; D_004A6FE4_21F100 = one; } } if (lv < 0) { func_001118F8_21F100(D_00457198_21F100, D_004A6FD8_21F100); func_002395A0_21F100(D_004572A8_21F100, lv, D_004A6FD0_21F100); } if (D_004A6FE0_21F100 != D_004A12B0_21F100) { D_004A6FE0_21F100 = D_004A12B0_21F100; D_004A6FC4_21F100 = D_004A6FC4_21F100 + 1; } return r; }

