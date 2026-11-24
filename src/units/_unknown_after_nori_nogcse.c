/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

extern int D_003FEBA8_00294220[] __asm__("D_003FEBA8");
// MATCH func_00294220
int FUN_00294220(int a) { D_003FEBA8_00294220[1] += a; if (D_003FEBA8_00294220[1] < 0) D_003FEBA8_00294220[1] = 0; if (D_003FEBA8_00294220[1] > 999999) D_003FEBA8_00294220[1] = 999999; return D_003FEBA8_00294220[1]; }

void func_00164A38(void *, int);
// MATCH func_00294560
void FUN_00294560(int *o, int a) { int i; a++; i = ((short *)o)[5] + a; if (i < 0) i += ((int *)o[0])[5]; if (i >= ((int *)o[0])[5]) i -= ((int *)o[0])[5]; func_00164A38(o, i); }

typedef struct { char p[0x12c0]; int a; int b[3]; int f; char q[0x1560-0x12d4]; } E_00291B60;
extern E_00291B60 *D_004A1A20_291B60 __asm__("D_004A1A20"); extern int D_004A2360_291B60 __asm__("D_004A2360"); void func_00290BD8_291B60(int) __asm__("func_00290BD8");
// MATCH func_00291B60
void FUN_00291b60(void) { int i; for (i = 0; i < 8; i++) { if (i != 3) { D_004A1A20_291B60[i].a = D_004A2360_291B60; D_004A1A20_291B60[i].f = (D_004A1A20_291B60[i].f | 1) & ~0x800; if (i < 4) D_004A1A20_291B60[i].f |= 0x40000000; else if (i < 10) D_004A1A20_291B60[i].f |= 0x20000000; func_00290BD8_291B60(i); } } }
