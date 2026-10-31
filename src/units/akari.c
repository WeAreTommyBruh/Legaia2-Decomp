/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern char D_004A380A; typedef struct { char p[296]; int v; } O_001E2660;
// MATCH func_001E2660
void akari_001e2660(int a, O_001E2660 *p, int v) { if (D_004A380A != 0) p->v = v; }

extern char D_0044BCF8[];
// MATCH func_001E23B8
void *akari_001e23b8(void *s) {
(*(int *)((char *)s + 100)) = (int)D_0044BCF8;
(*(float *)((char *)s + 72)) = 1.0f;
(*(unsigned char *)((char *)s + 78)) = 1;
(*(int *)((char *)s + 68)) = 0;
(*(unsigned char *)((char *)s + 76)) = 0;
(*(unsigned char *)((char *)s + 77)) = 0;
(*(unsigned char *)((char *)s + 79)) = 0;
(*(int *)((char *)s + 80)) = 0;
(*(int *)((char *)s + 84)) = 0;
(*(int *)((char *)s + 88)) = 0;
(*(unsigned char *)((char *)s + 0)) = 0;
return s; }

typedef struct { char pad[84]; int a84; int a88; char pad1[8]; char *a100; } S_001E2400;
extern char D_0044BCF8_001E2400[] __asm__("D_0044BCF8"), D_0044B740[];
void func_00133528(int, void *, int); void func_00108B80_001E2400(void *) __asm__("func_00108B80");
// MATCH func_001E2400
void akari_001e2400(S_001E2400 *s, int fl) { s->a100 = D_0044BCF8_001E2400; if (s->a88 != 0) func_00133528(s->a88, D_0044B740, 241); s->a84 = 0; s->a88 = 0; if (fl & 1) func_00108B80_001E2400(s); }

typedef struct { char p[88]; void *w88; } O_001E25A8;
extern char D_0044B740_001E25A8[] __asm__("D_0044B740"); void *func_001334D0(int, char *, int); void func_00133528_001E25A8(void *, char *, int) __asm__("func_00133528");
// MATCH func_001E25A8
int akari_001e25a8(O_001E25A8 *o, int n) { void *p; if (n <= 0) return 0; p = func_001334D0(n << 4, D_0044B740_001E25A8, 285); if (p == 0) return -1; if (o->w88 != 0) func_00133528_001E25A8(o->w88, D_0044B740_001E25A8, 287); o->w88 = p; return 1; }

extern char D_004A380A_001E2C60 __asm__("D_004A380A"); int func_00132B78(int); void func_001E3E38(int, int, int); int func_001E28A0(int, int, int, int);
// MATCH func_001E2C60
int akari_001e2c60(int a, int b, int c, int d) { int r; if (D_004A380A_001E2C60 == 0) return 0; if (b == 0) return 0; r = func_00132B78(b); if (r == 0) return 0; func_001E3E38(a, r, 0); func_001E28A0(a, r, c, d); return r; }

extern char D_004A380A_001E2A98 __asm__("D_004A380A"); int func_00132B78(int); void func_001E3E38(int, int, int); int func_001E26A8(int, int, int, int, float);
// MATCH func_001E2A98
int akari_001e2a98(int a, int b, int c, int d, float x) { int r; if (D_004A380A_001E2A98 == 0) return 0; if (b == 0) return 0; r = func_00132B78(b); if (r == 0) return 0; func_001E3E38(a, r, 0); func_001E26A8(a, r, c, d, x); return r; }

extern char D_004A380A_001E2CF8 __asm__("D_004A380A"); int func_001E2678(int, int);
typedef struct { float *w88; } T_1e2cf8_001E2CF8;
// MATCH func_001E2CF8
int akari_001e2cf8(int a, int *h, float *v) { int n; int i; int *p; if (D_004A380A_001E2CF8 == 0) return 0; if (h == 0) return 0; if (func_001E2678(a, (int)h) == 0) return 0; n = h[75]; if (n <= 0) return 1; p = h + 76; i = n; do { if (p[64] == 1) { float *q = (float *)(((int *)p[0])[22]); q[0] = v[0]; q[1] = v[1]; q[2] = v[2]; } i--; p++; } while (i != 0); return 1; }

extern char D_004A380A_001E32A0 __asm__("D_004A380A"); int func_001E2678_001E32A0(int, int *) __asm__("func_001E2678"); void func_001E2488(int, int); void func_001E2478(int, int);
// MATCH func_001E32A0
void akari_001e32a0(int a, int *h) { int n; int i; int *p; if (D_004A380A_001E32A0 == 0) return; if (h == 0) return; if (func_001E2678_001E32A0(a, h) == 0) return; n = h[75]; if (n <= 0) return; p = h + 76; i = n; do { switch (p[64]) { case 1: func_001E2488(p[0], 0); break; case 2: func_001E2488(p[0], 0); break; case 3: func_001E2488(p[0], 0); break; } p++; i--; } while (i != 0); }

extern char D_004A380A_001E3380 __asm__("D_004A380A"); int func_001E2678_001E3380(int, int *) __asm__("func_001E2678"); void func_001E2488(int, int); void func_001E2478(int, int);
// MATCH func_001E3380
void akari_001e3380(int a, int *h, int c) { int n; int i; int *p; if (D_004A380A_001E3380 == 0) return; if (h == 0) return; if (func_001E2678_001E3380(a, h) == 0) return; n = h[75]; if (n <= 0) return; p = h + 76; i = n; do { switch (p[64]) { case 1: func_001E2478(p[0], c); break; case 2: func_001E2478(p[0], c); break; case 3: func_001E2478(p[0], c); break; } p++; i--; } while (i != 0); }

extern char D_004A380A_001E3100 __asm__("D_004A380A"); int func_001E2678_001E3100(int, int *) __asm__("func_001E2678"); void func_00131F68_001E3100(int *) __asm__("func_00131F68"); void func_001E2488(int, int); void func_001E2478(int, int);
// MATCH func_001E3100
void akari_001e3100(int a, int *h) { int n; int i; int *p; int t; if (D_004A380A_001E3100 == 0) return; if (h == 0) return; if (func_001E2678_001E3100(a, h) == 0) return; func_00131F68_001E3100(h); n = h[75]; if (n <= 0) return; p = h + 76; i = n; do { switch (p[64]) { case 1: t = p[0]; func_001E2488(t, 0); func_001E2478(t, 0); break; case 2: t = p[0]; func_001E2488(t, 0); func_001E2478(t, 0); break; case 3: t = p[0]; func_001E2488(t, 0); func_001E2478(t, 0); break; } p++; i--; } while (i != 0); }
