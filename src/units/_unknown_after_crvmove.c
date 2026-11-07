/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char pad[48]; float v; } S_001625C8;
// MATCH func_001625C8
void FUN_001625c8(S_001625C8 *s, float x) { if (x > 0.0f) s->v = x; else s->v = 0.0f; }

typedef struct { char pad[52]; float v; } S_001625E8;
// MATCH func_001625E8
void FUN_001625e8(S_001625E8 *s, float x) { if (x > 0.0f) s->v = x; else s->v = 1.0f; }

// MATCH func_00163068
int FUN_00163068(int *p) { if (p == 0) return 0; return *p; }

int func_00163080(void);
extern int D_004A2C94;
// MATCH func_001630B8
int FUN_001630b8(void) { int r = func_00163080(); if (r == 0) return D_004A2C94; return r + 4; }

typedef struct { char pad[32]; unsigned char lo, hi; } O_001630E0;
void *func_00163080_p(void) __asm__("func_00163080");
// MATCH func_001630E0
int FUN_001630e0(void) { O_001630E0 *o = func_00163080_p(); if (o == 0) return 0; return o->lo | (o->hi << 8); }

typedef struct { char pad[34]; unsigned char lo, hi; } O_00163118;
void *func_00163080_p(void) __asm__("func_00163080");
// MATCH func_00163118
int FUN_00163118(void) { O_00163118 *o = func_00163080_p(); if (o == 0) return 0; return o->lo | (o->hi << 8); }

typedef struct { char p0[4]; int a4, a8, a12, a16; char p1[8]; float f28, f32, f36, f40; char p2[8]; int a52, a56; } O_00163F70;
// MATCH func_00163F70
int FUN_00163f70(O_00163F70 *o) { o->a12 = o->a4 >> 4; o->a16 = o->a8 >> 4; o->f36 = o->f28; o->f40 = o->f32; o->a56 = o->a52; return 0; }

typedef struct { char pad[36]; float a, b; } O_00164058;
// MATCH func_00164058
int FUN_00164058(O_00164058 *o, int **pp) { int *q = *pp; float x, y; x = (float)q[0]; q++; y = (float)q[0]; q++; *pp = q; o->a = x * 0.000244140625f; o->b = y * 0.000244140625f; return 0; }

typedef struct { char pad[44]; float a, b; } O_00164098;
// MATCH func_00164098
int FUN_00164098(O_00164098 *o, int **pp) { int *q = *pp; float x, y; x = (float)q[0]; q++; y = (float)q[0]; q++; *pp = q; o->a = x * 0.000244140625f; o->b = y * 0.000244140625f; return 0; }

// MATCH func_00163080
char *FUN_00163080(int *p, int i) { if (p == 0) return 0; if (i < 0) return 0; if (i >= p[0]) return 0; return (char *)p + p[i + 1]; }

extern char D_0043C7E8_163D88[] __asm__("D_0043C7E8"); void func_00163E68_163D88(char *, char *) __asm__("func_00163E68");
// MATCH func_00163D88
char *FUN_00163d88(char *o, int a, int b) { *(int *)(o + 88) = 0; *(float *)(o + 36) = 1.0f; *(float *)(o + 40) = 1.0f; *(char **)(o + 104) = D_0043C7E8_163D88; *(int *)(o + 100) = b; *(float *)(o + 44) = 1.0f; *(int *)(o + 84) = 1; *(int *)(o + 68) = 50; *(int *)(o + 72) = 0; *(int *)(o + 76) = 0; *(float *)(o + 48) = 1.0f; *(int *)(o + 80) = 0; *(int *)(o + 12) = 0; *(int *)(o + 56) = 128; *(int *)(o + 64) = 0x808080; *(int *)(o + 16) = 0; *(int *)(o + 20) = 0; *(int *)(o + 0) = a; *(int *)(o + 24) = 0; func_00163E68_163D88(o, o + 100); return o; }
