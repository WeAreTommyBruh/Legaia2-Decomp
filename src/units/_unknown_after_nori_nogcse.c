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


typedef struct { char pad0[4812]; int link; char pad12d0[20]; int mode; char pad12e8[632]; } U_285760_00285760;
extern U_285760_00285760 *D_004A1A20_00285760 __asm__("D_004A1A20");
extern int D_004A65C4_285760 __asm__("D_004A65C4"), D_004A5E50_285760 __asm__("D_004A5E50"), D_004A5E54_285760 __asm__("D_004A5E54");
extern int D_00314D08_285760[] __asm__("D_00314D08"), D_00314CC8_285760[] __asm__("D_00314CC8");
void func_00284648_285760(int) __asm__("func_00284648"); void func_00285140_285760(int) __asm__("func_00285140");
void func_00285A68_285760(U_285760_00285760 *, int) __asm__("func_00285A68"); void func_0028AC18_285760(U_285760_00285760 *, int) __asm__("func_0028AC18");
// MATCH func_00285760
void FUN_00285760(int a) { U_285760_00285760 *s = &D_004A1A20_00285760[a]; int t = s->link; U_285760_00285760 *o = &D_004A1A20_00285760[t]; int v; if (t < 4) func_00284648_285760(t); else func_00285140_285760(t); s->link = a; o->link = a; D_004A5E54_285760 = a; D_004A65C4_285760 = 2; D_004A5E50_285760 = t; if (t < 4) { v = D_00314D08_285760[t]; if (v != 1 && v != 8) { o->mode = 0; func_00285A68_285760(o, t); return; } o->mode = 4; func_0028AC18_285760(o, t); return; } v = D_00314CC8_285760[t - 4]; if (v != 58 && v != 251 && v != 161 && v != 162 && v != 163 && v != 282 && v != 151 && v != 176) { o->mode = 0; func_00285A68_285760(o, t); return; } o->mode = 4; func_0028AC18_285760(o, t); }
