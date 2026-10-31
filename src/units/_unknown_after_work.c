/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern float D_005F76C0[3];
// MATCH func_002478E0
void FUN_002478e0(float a, float b, float c) { D_005F76C0[0] = a; D_005F76C0[1] = b; D_005F76C0[2] = c; }

// MATCH func_00249E18
void FUN_00249e18(float *v, float a, float b, float c) { v[0] = a; v[1] = b; v[2] = c; }

void func_00247C98(float, float, float);
// MATCH func_00247E30
void FUN_00247e30(float *v) { func_00247C98(v[0], v[1], v[2]); }

extern int D_004A14B8;
void func_0018EB98_002492E8(void *, int) __asm__("func_0018EB98"); void func_0018DF68(void *, int);
// MATCH func_002492E8
void FUN_002492e8(void *a) { if (D_004A14B8 != 0) func_0018EB98_002492E8(a, 0x70003d80); else func_0018DF68(a, 0x70003f80); }

void func_00231F28(void *);
// MATCH func_00249618
void FUN_00249618(float x, float y, float z) { ((float *)0x70003e40)[0] = x; ((float *)0x70003e40)[1] = y; ((float *)0x70003e40)[2] = z; ((float *)0x70003e40)[3] = 1.0f; func_00231F28((void *)0x70003e40); }

extern int D_004A14B8_00249650 __asm__("D_004A14B8");
void func_0018EC58(void *); void func_0018F620(void *, int); void func_0018F3D8(void *, void *, void *); void func_0018DF68_00249650(void *, void *) __asm__("func_0018DF68");
// MATCH func_00249650
void FUN_00249650(int p) { func_0018EC58((void *)0x70003f00); func_0018F620((void *)0x70003f00, p); func_0018F3D8((void *)0x70003f80, (void *)0x70003f80, (void *)0x70003f00); if (D_004A14B8_00249650 != 0) { func_0018DF68_00249650((void *)0x70003f40, (void *)0x70003f00); func_0018F3D8((void *)0x70003d80, (void *)0x70003f40, (void *)0x70003d80); return; } return; }

// MATCH func_00249DB8
void FUN_00249db8(short *d, float *s) { d[0] = (int)(s[0] * 4096.0f); d[1] = (int)(s[1] * 4096.0f); d[2] = (int)(s[2] * 4096.0f); d[3] = (int)(s[3] * 4096.0f); }

extern float D_004A0820; extern int D_004A14B8_00248F38 __asm__("D_004A14B8"); void func_0018E680(float *, float, float, float); void func_0018F3D8_00248F38(float *, float *, float *) __asm__("func_0018F3D8"); void func_0018DF68_00248F38(float *, float *) __asm__("func_0018DF68");
// MATCH func_00248F38
void FUN_00248f38(int a, int b, int c) { func_0018E680((float *)0x70003f00, a * D_004A0820, b * D_004A0820, c * D_004A0820); func_0018F3D8_00248F38((float *)0x70003f80, (float *)0x70003f80, (float *)0x70003f00); func_0018F3D8_00248F38((float *)0x70003c80, (float *)0x70003c80, (float *)0x70003f00); if (D_004A14B8_00248F38 != 0) { func_0018DF68_00248F38((float *)0x70003f40, (float *)0x70003f00); func_0018F3D8_00248F38((float *)0x70003d80, (float *)0x70003f40, (float *)0x70003d80); } }

extern float D_004A0824; extern int D_004A14B8_00249558 __asm__("D_004A14B8"); void func_0018E860(float *, float, float, float); void func_0018F3D8_00249558(float *, float *, float *) __asm__("func_0018F3D8"); void func_0018DF68_00249558(float *, float *) __asm__("func_0018DF68");
// MATCH func_00249558
void FUN_00249558(int a, int b, int c) { func_0018E860((float *)0x70003f00, a * D_004A0824, b * D_004A0824, c * D_004A0824); func_0018F3D8_00249558((float *)0x70003f80, (float *)0x70003f80, (float *)0x70003f00); func_0018F3D8_00249558((float *)0x70003c80, (float *)0x70003c80, (float *)0x70003f00); if (D_004A14B8_00249558 != 0) { func_0018DF68_00249558((float *)0x70003f40, (float *)0x70003f00); func_0018F3D8_00249558((float *)0x70003d80, (float *)0x70003f40, (float *)0x70003d80); } }

typedef struct { char p[8]; short adj; short pad; void (*fn)(void *, int); } VT_002479F0;
typedef struct { char p[8]; int w8; char q[12]; VT_002479F0 *vt; } G_002479F0;
extern G_002479F0 *D_004A1524; extern int D_004A1540; extern int D_004A152C; void func_00190420_002479F0(G_002479F0 *) __asm__("func_00190420");
// MATCH func_002479F0
void FUN_002479f0(void) { func_00190420_002479F0(D_004A1524); if (D_004A1540 == 0) { G_002479F0 *g = D_004A1524; int v = D_004A152C; g->w8 = v; g->vt->fn((char *)g + g->vt->adj, v); } }

typedef struct { char p[16]; char *w16; } P_00247A48;
extern P_00247A48 *D_004A1524_00247A48 __asm__("D_004A1524");
// MATCH func_00247A48
void FUN_00247a48(unsigned a, unsigned long long b) { P_00247A48 *p = D_004A1524_00247A48; char *q = p->w16; *(unsigned long long *)q = b; *(unsigned long long *)(q + 8) = a; p->w16 = q + 16; }

float func_0015FB58(int, float); void func_0018EC58_002499C0(float *) __asm__("func_0018EC58");
// MATCH func_002499C0
void FUN_002499c0(float *m, float ang) { float c = func_0015FB58(1, ang); float s = func_0015FB58(0, ang); func_0018EC58_002499C0(m); *(volatile float *)(m + 5) = c; *(volatile float *)(m + 6) = s; *(volatile float *)(m + 9) = -s; *(volatile float *)(m + 10) = c; }

float func_0015FB58(int, float); void func_0018EC58_00249A30(float *) __asm__("func_0018EC58");
// MATCH func_00249A30
void FUN_00249a30(volatile float *m, float ang) { float c = func_0015FB58(1, ang); float s = func_0015FB58(0, ang); func_0018EC58_00249A30((float *)m); m[0] = c; m[2] = -s; m[8] = s; m[10] = c; }

float func_0015FB58(int, float); void func_0018EC58_00249AA0(float *) __asm__("func_0018EC58");
// MATCH func_00249AA0
void FUN_00249aa0(volatile float *m, float ang) { float c = func_0015FB58(1, ang); float s = func_0015FB58(0, ang); func_0018EC58_00249AA0((float *)m); m[0] = c; m[1] = s; m[4] = -s; m[5] = c; }

extern float D_00319760[]; void func_0018EC58_00249B10(float *) __asm__("func_0018EC58");
// MATCH func_00249B10
void FUN_00249b10(volatile float *m, int ang) { int i = ang & 0xfff; float c = D_00319760[i + 1024]; float s = D_00319760[i]; func_0018EC58_00249B10((float *)m); m[5] = c; m[6] = s; m[9] = -s; m[10] = c; }

extern float D_00319760_00249B80[] __asm__("D_00319760"); void func_0018EC58_00249B80(float *) __asm__("func_0018EC58");
// MATCH func_00249B80
void FUN_00249b80(volatile float *m, int ang) { int i = ang & 0xfff; float c = D_00319760_00249B80[i + 1024]; float s = D_00319760_00249B80[i]; func_0018EC58_00249B80((float *)m); m[0] = c; m[2] = -s; m[8] = s; m[10] = c; }

extern float D_00319760_00249BF0[] __asm__("D_00319760"); void func_0018EC58_00249BF0(float *) __asm__("func_0018EC58");
// MATCH func_00249BF0
void FUN_00249bf0(volatile float *m, int ang) { int i = ang & 0xfff; float c = D_00319760_00249BF0[i + 1024]; float s = D_00319760_00249BF0[i]; func_0018EC58_00249BF0((float *)m); m[0] = c; m[1] = s; m[4] = -s; m[5] = c; }

extern char *D_004A1518; extern char D_005F76C0_002478F8[] __asm__("D_005F76C0"); void func_0018F2C0(char *, float *, char *);
// MATCH func_002478F8
void FUN_002478f8(float x, float y, float z) { float *v = (float *)D_005F76C0_002478F8; v[0] = x; v[1] = y; v[2] = z; func_0018F2C0(D_004A1518, v, D_004A1518); ((unsigned char *)D_004A1518)[3] = 128; }

extern char D_00320D20[]; extern char *D_004A1524_00248118 __asm__("D_004A1524");
// MATCH func_00248118
void FUN_00248118(int i) { long *p = *(long **)(D_004A1524_00248118 + 16); int *e = (int *)(D_00320D20 + i * 16); p[1] = 4; *(long **)(D_004A1524_00248118 + 16) = p + 2; *p = (long)e[0] | ((long)e[1] << 16) | ((long)e[2] << 32); }

typedef struct N__0024A1C8 { struct N__0024A1C8 *next, *prev; void *owner; } N__0024A1C8;
typedef struct { char p[16]; N__0024A1C8 *w16; } O__0024A1C8;
extern int D_002F9800_0024A1C8[] __asm__("D_002F9800");
// MATCH func_0024A1C8
N__0024A1C8 *FUN_0024a1c8(O__0024A1C8 *o)
{
    int i = D_002F9800_0024A1C8[0];
    N__0024A1C8 *n, *old;
    if (i < 0) return 0;
    old = o->w16;
    n = *(N__0024A1C8 **)((char *)D_002F9800_0024A1C8 + i * 4 + 16);
    D_002F9800_0024A1C8[0] = i - 1;
    old->next = n;
    n->prev = old;
    n->owner = o;
    o->w16 = n;
    n->next = 0;
    return n;
}

// MATCH func_00247490
void FUN_00247490(char *o, int v) { int i; *(short *)o = v; *(int *)(o + 4) |= 1; *(int *)(o + 12) = 0; i = (short)v; if (i >= 0) { char *t = *(char **)(o + (i << 2) + 48); *(int *)(t + 52) |= 0x40; } }

typedef struct { int n; int pad[3]; int *v[1]; } L24_0024A190;
extern L24_0024A190 D_002F9800_0024A190 __asm__("D_002F9800");
// MATCH func_0024A190
int *FUN_0024a190(void) { int *t; t = D_002F9800_0024A190.v[D_002F9800_0024A190.n--]; t[0] = 0; t[1] = (int)t; t[4] = (int)t; return t; }
