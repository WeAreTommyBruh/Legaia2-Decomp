/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

extern char D_0043CD28[]; int func_00165A40(char *, int); void func_001118F8_001686A0(char *, int, int, int) __asm__("func_001118F8");
// MATCH func_001686A0
void pachislot_001686a0(char *o) { int i; for (i = 7; i >= 0; i--) { int a = func_00165A40(o + 44, i); int b = func_00165A40(o + 124, i); int c = func_00165A40(o + 204, i); func_001118F8_001686A0(D_0043CD28, a, b, c); } }

typedef struct { char p[360]; int w360, w364; } O_00168B58;
void func_00168AC0(O_00168B58 *);
// MATCH func_00168B58
int pachislot_00168b58(O_00168B58 *o) { if (o->w360 == 1) return 1; while (o->w360 > 0) { o->w360--; o->w364++; } func_00168AC0(o); return 1; }

int func_001659A8(void *);
// MATCH func_00165A40
int pachislot_00165a40(int *o, int k) { int i; int *t; if (func_001659A8(o)) return 0; i = o[18] + k; t = (int *)o[0]; if (i < 0) i += t[5]; if (i >= t[5]) i -= t[5]; return ((char *)o[1])[i]; }

typedef struct { char p[56]; short adj56; short pad56; void (*fn60)(void *); char p2[16]; short adj80; short pad80; void (*fn84)(void *, int); } VT_1659b0_001659B0;
typedef struct { char p[20]; int w20; } B_1659b0_001659B0;
typedef struct { B_1659b0_001659B0 *base; char p0[6]; short h10; char p1[36]; VT_1659b0_001659B0 *vt; char p2[12]; int w64; char p3[4]; int w72; } O_1659b0_001659B0;
// MATCH func_001659B0
int pachislot_001659b0(O_1659b0_001659B0 *o, int a) { int v; a++; v = o->h10 + a; if (v < 0) v += o->base->w20; if (v >= o->base->w20) v -= o->base->w20; o->w72 = v; o->vt->fn84((char *)o + o->vt->adj80, v); o->vt->fn60((char *)o + o->vt->adj56); o->w64 = 0; return 1; }

typedef struct { char p[20]; int w20; } P_00164C10;
typedef union { int w; struct { short a; short b; } s; } U;
typedef struct { P_00164C10 *p; int pad4; U u; int w12; int w16; int w20; int w24; char pad28[12]; short d40; short i42; short v44; short v46; } O_00164C10;
// MATCH func_00164C10
void pachislot_00164c10(O_00164C10 *o) { int idx; void (*fn)(void *); int d; int dl; long e; o->w12 = o->u.s.b; o->u.w += o->w24; if (o->u.s.b < 0) o->u.s.b = (unsigned short)o->u.s.b + *(unsigned short *)&o->p->w20; if (o->u.s.b >= o->p->w20) o->u.s.b = (unsigned short)o->u.s.b - *(unsigned short *)&o->p->w20; idx = o->i42; if (idx > 0) { long *vt = *(long **)((char *)o + o->v44); e = vt[idx - 1]; fn = (void (*)(void *))(e >> 32); } else fn = *(void (**)(void *))&o->v44; dl = o->d40; d = idx > 0 ? (short)e + dl : dl; fn((char *)o + d); }


int func_00165A40_1673C0(char *, int) __asm__("func_00165A40"); int func_001659A8_1673C0(char *) __asm__("func_001659A8");
// MATCH func_001673C0
int pachislot_001673c0(char *o, int a, int b, int c) { int x, y, z; x = func_00165A40_1673C0(o + 44, a); y = func_00165A40_1673C0(o + 124, b); z = func_00165A40_1673C0(o + 204, c); if (x == 6 || func_001659A8_1673C0(o + 44) != 0) x = -1; if (y == 6 || func_001659A8_1673C0(o + 124) != 0) y = -1; if (z == 6 || func_001659A8_1673C0(o + 204) != 0) z = -1; if (x == y && x != -1) return x; { register int miss __asm__("$3") = -1; if (y == z && y != miss) return y; } if (x == z) return x; x = -1; return x; }

extern char D_0043CBB8_00167940[] __asm__("D_0043CBB8"); extern char D_0043CBD0_00167940[] __asm__("D_0043CBD0"); extern char D_0043CBE8_00167940[] __asm__("D_0043CBE8"); extern char D_0043CC00_00167940[] __asm__("D_0043CC00"); extern char D_0043CC18_00167940[] __asm__("D_0043CC18"); extern int D_00334830_00167940[] __asm__("D_00334830"); int func_001677E8_00167940(char *, int, int, int) __asm__("func_001677E8"); void func_001118F8_00167940() __asm__("func_001118F8");
// MATCH func_00167940
int pachislot_00167940(char *o, int a, int b, int c) {
  int r;
  int q;
  register int res __asm__("$22");
  res = 0; q = 0; if (*(int *)(o + 360) > 0) { r = func_001677E8_00167940(o, a + 1, b + 1, c + 1); if (r != 0) { func_001118F8_00167940(D_0043CBB8_00167940, a, b, c, D_00334830_00167940[r]); res = r; } if (r == 1) return 1; } if (*(int *)(o + 360) >= 2) { r = func_001677E8_00167940(o, a + 2, b + 2, c + 2); if (r != 0) { func_001118F8_00167940(D_0043CBD0_00167940, a, b, c, D_00334830_00167940[r]); res = r; } if (r == 1) return 1; r = func_001677E8_00167940(o, a, b, c); if (r != 0) { func_001118F8_00167940(D_0043CBE8_00167940, a, b, c, D_00334830_00167940[r]); res = r; } if (r == 1) return 1; } if (*(int *)(o + 360) < 3) return res; r = func_001677E8_00167940(o, a + 2, b + 1, c); if (r != 0) { func_001118F8_00167940(D_0043CC00_00167940, a, b, c, D_00334830_00167940[r]); res = r; } if (r == 1) return 1; r = func_001677E8_00167940(o, a, b + 1, c + 2); if (r != 0) { func_001118F8_00167940(D_0043CC18_00167940, a, b, c, D_00334830_00167940[r]); res = r; } {register int z __asm__("$2")=r;if(r!=1){__asm__ volatile("" : : "r"(r));z=res;}return z;} }

extern char D_0043CC30_00167B88[] __asm__("D_0043CC30"); extern char D_0043CC48_00167B88[] __asm__("D_0043CC48"); extern char D_0043CC60_00167B88[] __asm__("D_0043CC60"); extern char D_0043CC78_00167B88[] __asm__("D_0043CC78"); extern char D_0043CC90_00167B88[] __asm__("D_0043CC90"); extern int D_00334830_00167B88[] __asm__("D_00334830");
int func_00167890_00167B88(char *, int, int, int) __asm__("func_00167890"); void func_001118F8_00167B88(char *, ...) __asm__("func_001118F8");
// MATCH func_00167B88
int pachislot_00167b88(char *o, int a, int b, int c) {
  register int r7 __asm__("$22"); int r; int n;
  r7 = 0;
  if (*(int *)(o + 0x168) > 0) {
    r = func_00167890_00167B88(o, a + 1, b + 1, c + 1);
    if (r != 0) { func_001118F8_00167B88(D_0043CC30_00167B88, a, b, c, D_00334830_00167B88[r]); r7 = r; }
    if (r == 1) return 1;
  }
  if (*(int *)(o + 0x168) >= 2) {
    r = func_00167890_00167B88(o, a + 2, b + 2, c + 2);
    if (r != 0) { func_001118F8_00167B88(D_0043CC48_00167B88, a, b, c, D_00334830_00167B88[r]); r7 = r; }
    if (r == 1) return 1;
    r = func_00167890_00167B88(o, a, b, c);
    if (r != 0) { func_001118F8_00167B88(D_0043CC60_00167B88, a, b, c, D_00334830_00167B88[r]); r7 = r; }
    if (r == 1) return 1;
  }
  if (*(int *)(o + 0x168) < 3) return r7;
  n = b + 1;
  r = func_00167890_00167B88(o, a + 2, n, c);
  if (r != 0) { func_001118F8_00167B88(D_0043CC78_00167B88, a, b, c, D_00334830_00167B88[r]); r7 = r; }
  if (r == 1) return 1;
  r = func_00167890_00167B88(o, a, n, c + 2);
  if (r != 0) { func_001118F8_00167B88(D_0043CC90_00167B88, a, b, c, D_00334830_00167B88[r]); r7 = r; }
  {register int z __asm__("$2")=r;if(r!=1){__asm__ volatile("" : : "r"(r));z=r7;}return z;}
}
