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
