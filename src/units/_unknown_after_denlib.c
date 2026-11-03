/* Functions of this report unit, matched by hand. */
#include "../common.h"

void func_0018D160(void *);
// MATCH func_0018D1B8
void FUN_0018d1b8(char *o) { func_0018D160(o); func_0018D160(o + 16); func_0018D160(o + 32); func_0018D160(o + 48); }

// MATCH func_0018D908
int FUN_0018d908(void) { int *p = (int *)0x10000800; __asm__("" : "+r"(p)); return *p; }

// MATCH func_0018D918
void FUN_0018d918(void) { int *p = (int *)0x10000810; __asm__("" : "+r"(p)); *p = 0; }

typedef int u128 __attribute__((mode(TI)));
// MATCH func_0018EB78
void FUN_0018eb78(u128 *d, u128 *s) { *d = *s; }

// MATCH func_0018EBC0
u128 *FUN_0018ebc0(u128 *d, u128 *s, unsigned n) { while (n--) *d++ = *s++; return d; }

extern char D_0042EEC8[]; extern int D_00342CE8[]; extern char D_00342D00[], D_00342E60[]; void func_00154B78(void *); void func_00153B40(void *);
// MATCH func_0018DE00
void FUN_0018de00(void) { D_00342CE8[0] = (int)D_0042EEC8; func_00154B78(D_00342D00); func_00153B40(D_00342E60); }

void func_0018D810(int, int, int, int, int, int, int);
// MATCH func_0018D8B8
void FUN_0018d8b8(int a, int b, int c, int d, int e, int f) { int t = *(volatile int *)0x10000000; func_0018D810(a, t, b, c, d, e, f); }

// MATCH func_0018DA70
void FUN_0018da70(unsigned char *d, unsigned char *a, unsigned char *b, float t) { int i; for (i = 255; i >= 0; i--) { d[3] = a[3]; d[0] = a[0] + (int)((b[0] - a[0]) * t); d[1] = a[1] + (int)((b[1] - a[1]) * t); d[2] = a[2] + (int)((b[2] - a[2]) * t); a += 4; b += 4; d += 4; } }

// MATCH func_0018D9A8
void FUN_0018d9a8(unsigned char *d, unsigned char *a, unsigned char *b, float t) { int i; float u = 1.0f - t; for (i = 255; i >= 0; i--) { d[3] = a[3]; d[0] = (int)(a[0] * u + b[0] * t); d[1] = (int)(a[1] * u + b[1] * t); d[2] = (int)(a[2] * u + b[2] * t); a += 4; b += 4; d += 4; } }

extern int D_004A129C; extern char D_00440638[]; int func_002DCE40_0018CF98(char *, char *, ...) __asm__("func_002DCE40"); void func_00239568_0018CF98(char *) __asm__("func_00239568");
// MATCH func_0018CF98
void FUN_0018cf98(float *o) { char buf[128]; int s = D_004A129C; D_004A129C = 1; func_002DCE40_0018CF98(buf, D_00440638, (double)o[0], (double)o[1], (double)o[2], (double)o[3]); func_00239568_0018CF98(buf); D_004A129C = s; }

extern int D_004A129C_0018D0A8 __asm__("D_004A129C"); extern char D_00440658[]; int func_002DCE40_0018D0A8(char *, char *, ...) __asm__("func_002DCE40"); void func_00239568_0018D0A8(char *) __asm__("func_00239568");
// MATCH func_0018D0A8
void FUN_0018d0a8(float *o) { char buf[128]; int s = D_004A129C_0018D0A8; D_004A129C_0018D0A8 = 1; func_002DCE40_0018D0A8(buf, D_00440658, o, (double)o[0], (double)o[1], (double)o[2], (double)o[3]); func_00239568_0018D0A8(buf); D_004A129C_0018D0A8 = s; }

extern char D_004406A8[]; void func_001118F8_0018D2B0(char *, ...) __asm__("func_001118F8");
// MATCH func_0018D2B0
void FUN_0018d2b0(char *a, int *p) { if (a != 0) func_001118F8_0018D2B0(a); if (p != 0) func_001118F8_0018D2B0(D_004406A8, p, p[0], p[1], p[2], p[3]); }

void func_0018ED08_0018E5C8(int *, int) __asm__("func_0018ED08"); void func_0018EC08(int *); void func_0018DED8(int, int *);
// MATCH func_0018E5C8
void FUN_0018e5c8(int a, int b, int c, int d, int e) { int v0[4], v1[4], v2[4], v3[4]; func_0018ED08_0018E5C8(v0, b); func_0018ED08_0018E5C8(v1, c); func_0018ED08_0018E5C8(v2, d); func_0018ED08_0018E5C8(v3, e); func_0018EC08(v0); func_0018EC08(v1); func_0018EC08(v2); func_0018EC08(v3); func_0018DED8(a, v0); }

extern int D_004A129C_0018D160 __asm__("D_004A129C");
int func_002DCE40_0018D160(void *, void *, ...) __asm__("func_002DCE40");
int func_00239568_0018D160(void *, ...) __asm__("func_00239568");
extern char D_00440678[];
// MATCH func_0018D160
void FUN_0018d160(int *o)
{
  int new_var6;
  char *new_var4;
  int new_var3;
  int *new_var2;
  int *new_var5;
  int *new_var;
  char buf[128];
  int s = D_004A129C_0018D160;
  D_004A129C_0018D160 = 1;
  new_var = o;
  new_var2 = new_var;
  new_var3 = 3;
  new_var4 = buf;
  new_var5 = &new_var2[2];
  new_var6 = 0;
  func_002DCE40_0018D160(new_var4, D_00440678, new_var, new_var[new_var6], new_var[1], *new_var5, new_var[new_var3]);
  func_00239568_0018D160(buf);
  D_004A129C_0018D160 = s;
}

extern char D_00440690[];
int func_001118F8_0018D1F0(void *, ...) __asm__("func_001118F8");
// MATCH func_0018D1F0
void FUN_0018d1f0(char *s, float *o) {
    if (s != 0) func_001118F8_0018D1F0(s);
    if (o != 0) func_001118F8_0018D1F0(D_00440690, o, (double)o[0], (double)o[1], (double)o[2], (double)o[3]);
}

extern float D_004A0174_18E538 __asm__("D_004A0174");
void func_0018EC38_18E538(float *) __asm__("func_0018EC38"); void func_0018F3D8_18E538(float *, float *, float *) __asm__("func_0018F3D8");
// MATCH func_0018E538
void FUN_0018e538(float *v, float a, float b, float c) { float m[16]; func_0018EC38_18E538(v); func_0018EC38_18E538(m); m[0] = 1.0f / b; m[5] = 1.0f / c; m[12] = 0.5f; m[13] = D_004A0174_18E538; func_0018F3D8_18E538(v, m, v); }
