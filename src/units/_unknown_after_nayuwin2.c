/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_004A3C60; void func_002A6110(void *, int);
// MATCH func_001C7980
void FUN_001c7980(void) { func_002A6110(&D_004A3C60, 2); }

extern int D_004A3C60; void func_002A6100(void *);
// MATCH func_001C7990
void FUN_001c7990(void) { func_002A6100(&D_004A3C60); }

void func_00254CE0(int, int); void func_00255008(int, int);
// MATCH func_001B4BE8
void FUN_001b4be8(int x, signed char a, signed char b) { int d = b - a; if (d < 0) func_00255008(x, -d); else func_00254CE0(x, d); }

void func_00254D70(int, int); void func_00255098(int, int);
// MATCH func_001B4C18
void FUN_001b4c18(int x, signed char a, signed char b) { int d = b - a; if (d < 0) func_00255098(x, -d); else func_00254D70(x, d); }

typedef struct { float f0; float f4, f8; float f12; float f16; float f20, f24, f28, f32, f36; float f40; } F_1b79b0_001B79B0;
void func_00108C80(void *); void func_00108C20(void *);
// MATCH func_001B79B0
void FUN_001b79b0(F_1b79b0_001B79B0 *s, float a, float b, float c, float d, float e) {
s->f0 = 0.0f;
s->f4 = a;
s->f8 = b;
s->f16 = d;
s->f40 = 1.0f;
s->f12 = 0.0f;
s->f24 = 0.0f;
s->f28 = 0.0f;
s->f32 = 0.0f;
s->f36 = 0.0f;
s->f20 = 0.0f;
if (s->f0 <= c) s->f12 = c;
if (s->f0 <= e) { s->f24 = e; s->f28 = e; }
func_00108C80(s); func_00108C20(s);
}

typedef struct { float f0; float f4, f8; float f12; float f16; float f20, f24, f28, f32, f36; float f40; } F_1c79e8_001C79E8;
void func_00108C80(void *); void func_00108C20(void *);
// MATCH func_001C79E8
void FUN_001c79e8(F_1c79e8_001C79E8 *s, float a, float b, float c, float d, float e) {
s->f0 = 0.0f;
s->f4 = a;
s->f8 = b;
s->f16 = d;
s->f40 = 1.0f;
s->f12 = 0.0f;
s->f24 = 0.0f;
s->f28 = 0.0f;
s->f32 = 0.0f;
s->f36 = 0.0f;
s->f20 = 0.0f;
if (s->f0 <= c) s->f12 = c;
if (s->f0 <= e) { s->f24 = e; s->f28 = e; }
func_00108C80(s); func_00108C20(s);
}

extern int D_00343654[]; extern char D_00343650[]; void func_001B4738(int, int, int, int);
// MATCH func_001B4610
void FUN_001b4610(int a, int b) { if (b >= 0) { if (a == 1 && D_00343654[0] == 0) { func_001B4738(1, 1, b, 0); return; } if (a == 0 && D_00343650[0] == 1) func_001B4738(1, 2, b, 0); } }

extern int D_00343654_001B4690[] __asm__("D_00343654"); extern char D_00343650_001B4690[] __asm__("D_00343650"); void func_001B4738(int, int, int, int);
// MATCH func_001B4690
void FUN_001b4690(int a, int b) { if (b >= 0) { if (a == 1 && D_00343654_001B4690[0] == 0) { func_001B4738(2, 1, b, 0); return; } if (a == 0 && D_00343650_001B4690[0] == 1) func_001B4738(2, 2, b, 0); } }

extern long long D_004A12D8_001BA3C0 __asm__("D_004A12D8"); extern int D_0036CB68[]; extern char D_00343028_001BA3C0[] __asm__("D_00343028"); void func_001B4B40(int); void func_0010C2B0(char *, int, int, int, int, int, int);
// MATCH func_001BA3C0
void FUN_001ba3c0(void) { if (D_004A12D8_001BA3C0 & 0x48000) { func_001B4B40(D_0036CB68[0]); func_0010C2B0(D_00343028_001BA3C0, 0, 2, 0, 2, 0, 0); } }

extern long long D_004A12D8_001C5EB8 __asm__("D_004A12D8"); extern int D_004A12A4_001C5EB8 __asm__("D_004A12A4"), D_004A382C; extern int D_0036CAB0[]; extern char D_00343028_001C5EB8[] __asm__("D_00343028"); void func_001AE398(int); void func_001B4738_001C5EB8(int, int, int, int) __asm__("func_001B4738"); void func_0010E368(char *); void func_001B4B40(int); void func_002552B8(void); void func_001C7B60(int);
// MATCH func_001C5EB8
void FUN_001c5eb8(void) { if (D_004A12D8_001C5EB8 & 0x40) { if (D_004A12A4_001C5EB8 == 17) { func_001AE398(D_0036CAB0[0]); func_001AE398(D_0036CAB0[1]); func_001AE398(D_0036CAB0[2]); func_001B4738_001C5EB8(4, 2, 2, 0); func_0010E368(D_00343028_001C5EB8); } else func_001B4738_001C5EB8(4, 2, 2, 0); func_001B4B40(D_004A382C); func_002552B8(); func_001C7B60(3); } }

extern int D_00319680[];
void func_00115090(float, float, float, void *, int, int, unsigned, int, int, unsigned);
// MATCH func_001B2AE0
void FUN_001b2ae0(int a, int b, int c, int d, unsigned char e) { func_00115090((float)((c % 10) * 0x18), (float)((c / 10) * 0x18), 0.5f, (int *)b, 0x18, 0x18, D_00319680[0] + 0x3140, 0x3f40, d, e); }

void akari_001e2530(int, int); int akari_001e2588(int); void nayuki_001dafa8(int); void nayuki_001db5a0(int); int rouge_001322c0(int, int, int);
// MATCH func_001D7F88
int FUN_001d7f88(int p, int q, int r) { int u; int v; if ((*(long long *)(p + 0x48) & 0xffff000000000000LL) == 0) { u = rouge_001322c0(q, r, 1); } else { if (*(char *)(p + 0x4d) != 0) { akari_001e2530(p, r); v = akari_001e2588(p); if (v == 1) { if (*(int *)(p + 0x80) < 6 || *(int *)(p + 0x80) == 8) nayuki_001db5a0(p); else nayuki_001dafa8(p); } } u = 0; } return u; }

extern unsigned long D_004A12D8_1B7FB0 __asm__("D_004A12D8");
extern int D_004A3874_1B7FB0 __asm__("D_004A3874"), D_004A12A4_1B7FB0 __asm__("D_004A12A4");
extern int D_0036CB88_1B7FB0[] __asm__("D_0036CB88"), D_0036CAB0_1B7FB0[] __asm__("D_0036CAB0"), D_0036CAD4_1B7FB0[] __asm__("D_0036CAD4"), D_00343654_1B7FB0[] __asm__("D_00343654"), D_00425510_1B7FB0[] __asm__("D_00425510");
extern char D_00343028_1B7FB0[] __asm__("D_00343028");
void func_001AE398_1B7FB0(int) __asm__("func_001AE398");
void func_001AD888_1B7FB0(int, int) __asm__("func_001AD888");
void func_001B4B40_1B7FB0(int) __asm__("func_001B4B40");
int func_001AD848_1B7FB0(int) __asm__("func_001AD848");
void func_0029B670_1B7FB0() __asm__("func_0029B670");
int func_0010C2B0_1B7FB0(void *, int, int, int, int, int, int) __asm__("func_0010C2B0");
// MATCH func_001B7FB0
void FUN_001b7fb0(void) { int *s, *r, *p; int k; char buf[16]; if (D_004A12D8_1B7FB0 & 0x50) { s = D_0036CB88_1B7FB0; func_001AE398_1B7FB0(s[2]); func_001AD888_1B7FB0(s[2], 10); func_001B4B40_1B7FB0(D_004A3874_1B7FB0); p = *(int **)(s[2] + 360); if (p[10] == 1) D_004A3874_1B7FB0 = D_0036CAD4_1B7FB0[0]; p[10] = 0; k = p[11]; if (k == 1 && D_004A12A4_1B7FB0 != 17) { r = D_0036CAB0_1B7FB0; func_001AE398_1B7FB0(r[13]); func_001AD888_1B7FB0(r[13], 20); func_001AE398_1B7FB0(r[9]); func_001AD888_1B7FB0(r[9], 20); func_001AE398_1B7FB0(r[12]); func_001AD888_1B7FB0(r[12], 20); func_001AE398_1B7FB0(r[11]); func_001AD888_1B7FB0(r[11], 20); func_001AE398_1B7FB0(s[12]); func_001AD888_1B7FB0(s[12], 20); D_00343654_1B7FB0[0] = 4; k = func_001AD848_1B7FB0(r[11]); { int t = *(int *)(k * 256 + *(int *)(r[11] + 360) + 44); D_00425510_1B7FB0[2] |= 4; func_0029B670_1B7FB0(buf, t); } } else { func_0010C2B0_1B7FB0(D_00343028_1B7FB0, 0, 2, 0, 1, 0, 0); } } }

