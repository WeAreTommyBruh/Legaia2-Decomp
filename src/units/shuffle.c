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

