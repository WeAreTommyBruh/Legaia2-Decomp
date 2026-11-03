/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char pad[48]; int a48; int pad1; int a56; int pad2; int a64; int pad3; int a72; } S_2a64d0_002A64D0;
void func_0029D010_002A64D0(void *, int, float) __asm__("func_0029D010");
// MATCH func_002A64D0
void FUN_002a64d0(S_2a64d0_002A64D0 *s, int a, int b, int c) { s->a72 = c; s->a56 = 0; s->a64 = 0; s->a48 = 0; func_0029D010_002A64D0(s, 0, (float)a); }

typedef struct { char pad[20]; char sub[1]; char pad1[31]; int a52; int pad2; int a60; int pad3; int a68; int a72; } S_2a64f8_002A64F8;
void func_0029D010_002A64F8(void *, int, float) __asm__("func_0029D010");
// MATCH func_002A64F8
void FUN_002a64f8(S_2a64f8_002A64F8 *s, int a, int b, int c) { s->a72 = c; s->a60 = 0; s->a68 = 0; s->a52 = 0; func_0029D010_002A64F8(s->sub, 0, (float)a); }

typedef struct { char pad[240]; char a240[64]; char a304[1]; char pad2[1583]; int k; } S_2a7aa0_002A7AA0;
// MATCH func_002A7AA0
char *FUN_002a7aa0(S_2a7aa0_002A7AA0 *s) { int k = s->k; if (k == 1) return s->a304; if (k == 2) return s->a240; if (k == 4) return s->a304; return 0; }

typedef struct { char pad[8]; short adj; short p2; void (*fn)(void *, int); } VT_2a63e8_002A63E8;
typedef struct { char pad[56]; VT_2a63e8_002A63E8 *vt; } O_2a63e8_002A63E8;
typedef struct { O_2a63e8_002A63E8 *o; int a4; } S_2a63e8_002A63E8;
// MATCH func_002A63E8
void FUN_002a63e8(S_2a63e8_002A63E8 *s) { O_2a63e8_002A63E8 *p; s->a4 = 0; p = s->o; if (p != 0) { p->vt->fn((char *)p + p->vt->adj, 3); s->o = 0; } }

int func_0015ECB0(void *); float func_0015EC50(void *);
// MATCH func_002A8738
void FUN_002a8738(char *s, int *q, float *r) { *q = func_0015ECB0(s + 432); *r = func_0015EC50(s + 432); }

float func_0015EC48(void *); float func_0015EC40(void *);
// MATCH func_002A87C8
void FUN_002a87c8(char *s, float *q, float *r) { *q = func_0015EC48(s + 432); *r = func_0015EC40(s + 432); }

void func_0015EC38(char *, float); void func_0015EB40(char *, float);
// MATCH func_002A86F0
void FUN_002a86f0(char *o, float x) { func_0015EC38(o + 432, -0.25f); func_0015EB40(o + 432, x); }

void func_0015EB38(char *); void func_0015EB30(char *, float);
// MATCH func_002A8788
void FUN_002a8788(char *o, float a, float b) { func_0015EB38(o + 432); func_0015EB30(o + 432, b); }

extern char D_0041F1D0[], D_00342D00_002A8A38[] __asm__("D_00342D00"), D_004254F0[]; void func_002A7AD8(int, char *); void func_00154C00(char *, char *); void func_00155000(char *);
// MATCH func_002A8A38
void FUN_002a8a38(void) { int p = (int)D_0041F1D0; do { func_002A7AD8(p, D_00342D00_002A8A38); p += 1968; } while (p < (int)D_0041F1D0 + 7872); func_00154C00(D_00342D00_002A8A38, D_004254F0); func_00155000(D_00342D00_002A8A38); }

void func_0029D010_002A8228(void *, float, int, int) __asm__("func_0029D010");
// MATCH func_002A8228
void FUN_002a8228(float a, float b, float c, char *o, int m, int n) { if (m == 0) { if (n == 0) { *(float *)(o + 1928) = a; *(float *)(o + 40) = a; *(float *)(o + 1932) = b; *(float *)(o + 60) = b; *(float *)(o + 1936) = c; *(float *)(o + 80) = c; } else if (n > 0) { func_0029D010_002A8228(o + 40, a, 8, n); func_0029D010_002A8228(o + 60, b, 8, n); func_0029D010_002A8228(o + 80, c, 8, n); } } else if (m > 0) { func_0029D010_002A8228(o + 40, a, 0, m); func_0029D010_002A8228(o + 60, b, 0, m); func_0029D010_002A8228(o + 80, c, 0, m); } }

void func_0029D010_002A8358(void *, float, int, int) __asm__("func_0029D010");
// MATCH func_002A8358
void FUN_002a8358(float a, float b, float c, char *o, int m, int n) { if (m == 0) { if (n == 0) { *(float *)(o + 1940) = a; *(float *)(o + 100) = a; *(float *)(o + 1944) = b; *(float *)(o + 120) = b; *(float *)(o + 1948) = c; *(float *)(o + 140) = c; } else if (n > 0) { func_0029D010_002A8358(o + 100, a, 8, n); func_0029D010_002A8358(o + 120, b, 8, n); func_0029D010_002A8358(o + 140, c, 8, n); } } else if (m > 0) { func_0029D010_002A8358(o + 100, a, 0, m); func_0029D010_002A8358(o + 120, b, 0, m); func_0029D010_002A8358(o + 140, c, 0, m); } }

void func_0029D010_002A8488(void *, float, int, int) __asm__("func_0029D010");
// MATCH func_002A8488
void FUN_002a8488(float a, float b, float c, float d, char *o, int m, int n) { if (m == 0) { if (n == 0) { *(float *)(o + 1904) = a; *(float *)(o + 160) = a; *(float *)(o + 1908) = b; *(float *)(o + 180) = b; *(float *)(o + 1912) = c; *(float *)(o + 200) = c; *(float *)(o + 1916) = d; *(float *)(o + 220) = d; } else if (n > 0) { func_0029D010_002A8488(o + 160, a, 8, n); func_0029D010_002A8488(o + 180, b, 8, n); func_0029D010_002A8488(o + 200, c, 8, n); func_0029D010_002A8488(o + 220, d, 8, n); } } else if (m > 0) { func_0029D010_002A8488(o + 160, a, 0, m); func_0029D010_002A8488(o + 180, b, 0, m); func_0029D010_002A8488(o + 200, c, 0, m); func_0029D010_002A8488(o + 220, d, 0, m); } }

void func_0029D010_002A8600(void *, float, int, int) __asm__("func_0029D010");
// MATCH func_002A8600
void FUN_002a8600(float a, float b, char *o, int m, int n) { if (m == 0) { if (n == 0) { *(float *)(o + 1920) = a; *(float *)(o + 0) = a; *(float *)(o + 1924) = b; *(float *)(o + 20) = b; } else if (n > 0) { func_0029D010_002A8600(o, a, 8, n); func_0029D010_002A8600(o + 20, b, 8, n); } } else if (m > 0) { func_0029D010_002A8600(o, a, 0, m); func_0029D010_002A8600(o + 20, b, 0, m); } }


// MATCH func_002A9038
int FUN_002a9038(char *o) { float d[3]; d[0] = *(float *)(o + 32) - *(float *)(o + 48); d[1] = *(float *)(o + 36) - *(float *)(o + 52); d[2] = *(float *)(o + 40) - *(float *)(o + 56); if (1.0f < __builtin_fabsf(d[0])) return 1; if (1.0f < __builtin_fabsf(d[1])) return 1; if (1.0f < __builtin_fabsf(d[2])) return 1; return 0; }
