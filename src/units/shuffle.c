/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern char D_0043E188[]; void *func_00162130_00178AF8(int, char *, int) __asm__("func_00162130"); void *func_001779C8(void *, int, int, int, int, int, int);
// MATCH func_00178AF8
void *shuffle_00178af8(int a, int b, int c, int d, int e, int f) { return func_001779C8(func_00162130_00178AF8(496, D_0043E188, 764), a, b, c, d, e, f); }

extern char D_0043E188_00178A80[] __asm__("D_0043E188"); void *func_00162130_00178A80(int, char *, int) __asm__("func_00162130"); void *func_001779C8(void *, int, int, int, int, int, int);
// MATCH func_00178A80
void *shuffle_00178a80(int a, int b, int c, int d) { return func_001779C8(func_00162130_00178A80(496, D_0043E188_00178A80, 760), a, b, c, d, 20, 10); }

typedef struct { signed char a, b; char pad[6]; } T8_00177D38;
extern T8_00177D38 D_00336680[]; extern float D_004A00CC;
// MATCH func_00177D38
int shuffle_00177d38(char *o) { T8_00177D38 *t; char *p; char *q; float v; float lim; t = &D_00336680[*(int *)(o + 396)]; lim = D_004A00CC; p = o + t->a * 96; q = o + t->b * 96; *(float *)(p + 56) = *(float *)(p + 56) + *(float *)(o + 404); *(float *)(q + 56) = *(float *)(q + 56) + *(float *)(o + 404); *(float *)(p + 24) = *(float *)(p + 24) - *(float *)(o + 404); v = *(float *)(q + 24) - *(float *)(o + 404); *(float *)(q + 24) = v; if (v <= lim) return 1; return 0; }

typedef struct { signed char a, b; char pad[6]; } T8_00177DC8;
extern T8_00177DC8 D_00336680_00177DC8[] __asm__("D_00336680"); extern float D_004A00D0;
// MATCH func_00177DC8
int shuffle_00177dc8(char *o) { T8_00177DC8 *t; char *p; char *q; float v; float lim; t = &D_00336680_00177DC8[*(int *)(o + 396)]; lim = D_004A00D0; p = o + t->a * 96; q = o + t->b * 96; *(float *)(p + 56) = *(float *)(p + 56) - *(float *)(o + 404); *(float *)(q + 56) = *(float *)(q + 56) - *(float *)(o + 404); *(float *)(p + 24) = *(float *)(p + 24) + *(float *)(o + 404); v = *(float *)(q + 24) + *(float *)(o + 404); *(float *)(q + 24) = v; if (lim <= v) return 1; return 0; }

typedef struct { signed char a, b; char pad[6]; } T8_00177E58;
extern T8_00177E58 D_00336680_00177E58[] __asm__("D_00336680"); extern float D_004A00D4;
// MATCH func_00177E58
int shuffle_00177e58(char *o) { T8_00177E58 *t; char *p; char *q; float v; float lim; t = &D_00336680_00177E58[*(int *)(o + 396)]; lim = D_004A00D4; p = o + t->a * 96; q = o + t->b * 96; *(float *)(p + 52) = *(float *)(p + 52) + *(float *)(o + 404); *(float *)(q + 52) = *(float *)(q + 52) + *(float *)(o + 404); *(float *)(p + 20) = *(float *)(p + 20) - *(float *)(o + 404); v = *(float *)(q + 20) - *(float *)(o + 404); *(float *)(q + 20) = v; if (lim <= *(float *)(q + 52)) return 1; return 0; }

typedef struct { signed char a, b; char pad[6]; } T8_00177EF0;
extern T8_00177EF0 D_00336680_00177EF0[] __asm__("D_00336680"); extern float D_004A00D8;
// MATCH func_00177EF0
int shuffle_00177ef0(char *o) { T8_00177EF0 *t; char *p; char *q; float v; float lim; t = &D_00336680_00177EF0[*(int *)(o + 396)]; lim = D_004A00D8; p = o + t->a * 96; q = o + t->b * 96; *(float *)(p + 52) = *(float *)(p + 52) - *(float *)(o + 404); *(float *)(q + 52) = *(float *)(q + 52) - *(float *)(o + 404); *(float *)(p + 20) = *(float *)(p + 20) + *(float *)(o + 404); v = *(float *)(q + 20) + *(float *)(o + 404); *(float *)(q + 20) = v; if (*(float *)(q + 52) <= lim) return 1; return 0; }

typedef struct { char c[8]; } B8_00178038;
extern char D_004A3340_178038[] __asm__("D_004A3340"), D_004A3348_178038[] __asm__("D_004A3348");
// MATCH func_00178038
int shuffle_00178038(char *o) { int i; for (i = 0; i < 4; i++) { char *p = o + i * 96; float f = *(float *)(p + 4) + 6.0f; *(float *)(p + 4) = f; if (0.0f <= f) { *(int *)(p + 4) = 0; *(int *)(o + 448) = 100; *(B8_00178038 *)(o + 476) = *(B8_00178038 *)D_004A3340_178038; *(B8_00178038 *)(o + 484) = *(B8_00178038 *)D_004A3348_178038; *(int *)(p + 88) = 1; } } return 0; }

typedef struct { int a, b; } P8_1780C0_001780C0;
extern float D_004A00DC_1780C0 __asm__("D_004A00DC"), D_004A00E0_1780C0 __asm__("D_004A00E0");
extern P8_1780C0_001780C0 D_004A3350_1780C0[] __asm__("D_004A3350");
// MATCH func_001780C0
int shuffle_001780c0(int p) { float d = D_004A00DC_1780C0; float m = D_004A00E0_1780C0; int e = p; do { *(float *)(e + 0x14) += d; if (*(float *)(e + 0x14) >= m) { *(float *)(e + 0x14) = m; *(P8_1780C0_001780C0 *)(p + 0x1dc) = D_004A3350_1780C0[0]; } *(int *)(e + 0x58) = 0; e += 0x60; } while (e < p + 0x180); return 0; }

typedef struct { int a, b; } P8_178120_00178120;
typedef struct { char a, b; short pad; float f; } T_178120_00178120;
extern T_178120_00178120 D_00336680_178120[] __asm__("D_00336680");
extern P8_178120_00178120 D_004A3358_178120[] __asm__("D_004A3358");
extern char D_00343028_178120[] __asm__("D_00343028");
int rand(void);
void rsound_0010c2b0(void *, int, int, int, int, int, int);
// MATCH func_00178120
int shuffle_00178120(int p) { unsigned int q, r, n, lim; T_178120_00178120 *t; n = 5; lim = 0x7fffff - 0x800000 % n; do { q = rand() >> 8; } while (q > lim); *(int *)(p + 0x184) = q % n; n = 6; lim = 0x7fffff - 0x800000 % n; do { r = rand() >> 8; } while (r > lim); r = r % n; *(int *)(p + 0x1a4) = 0; *(int *)(p + 0x18c) = r; t = &D_00336680_178120[r]; { int b = t->b; *(float *)(t->a * 0x60 + p + 0x20) = -t->f; *(float *)(b * 0x60 + p + 0x20) = t->f; } rsound_0010c2b0(D_00343028_178120, 0xa2, 0xc, 0, 1, 0, 0); *(P8_178120_00178120 *)(p + 0x1dc) = D_004A3358_178120[0]; return 0; }

typedef int u128_1784E0 __attribute__((mode(TI)));
typedef struct { int a, b; } P8_1784E0_001784E0;
extern float D_004A00E8_1784E0 __asm__("D_004A00E8"), D_004A00EC_1784E0 __asm__("D_004A00EC");
extern P8_1784E0_001784E0 D_004A3370_1784E0[] __asm__("D_004A3370");
// MATCH func_001784E0
int shuffle_001784e0(int p) { int e = *(int *)(p + 0x198) * 0x60 + p; float d = D_004A00E8_1784E0, m = D_004A00EC_1784E0; *(float *)(e + 0x14) += d; if (*(float *)(e + 0x14) >= m) { *(u128_1784E0 *)(p + 0x1b0) = *(u128_1784E0 *)e; *(int *)(e + 0x14) = 0; *(int *)(p + 0x1a4) = 0; *(P8_1784E0_001784E0 *)(p + 0x1dc) = D_004A3370_1784E0[0]; } return 0; }
