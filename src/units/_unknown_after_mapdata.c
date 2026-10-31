/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char pad[40]; int v; } S_0015ADE8;
// MATCH func_0015ADE8
int FUN_0015ade8(S_0015ADE8 **p) { S_0015ADE8 *q = *p; if (q == 0) return 0; return q->v; }

typedef struct { char pad[44]; int v; } S_0015AE08;
// MATCH func_0015AE08
int FUN_0015ae08(S_0015AE08 **p) { S_0015AE08 *q = *p; if (q == 0) return 0; return q->v; }

typedef struct { float a, b, c; } V_0015DF00;
void func_0029C980(void *, float, float, float, int, int);
// MATCH func_0015DF00
void FUN_0015df00(char *s, V_0015DF00 *v) { func_0029C980(s + 176, v->a, v->b, v->c, 0, 0); }

void func_0015D788(int, int, int, int, int);
// MATCH func_0015A8E8
void FUN_0015a8e8(int *p, int a, int b, int c) { int v[2]; func_0015D788(*p, a, b, c, (int)v); }

void func_0015D8B0(int, int, int, int, int, int);
// MATCH func_0015A948
void FUN_0015a948(int *p, int a, int b, int c, int d) { int v[4]; func_0015D8B0(*p, a, b, c, d, (int)v); }

typedef struct { void *p; } O_0015AE28;
int func_0015D430(void *, int, int);
// MATCH func_0015AE28
int FUN_0015ae28(O_0015AE28 *o, int b) { void *p = o->p; int r = 0; if (p) r = func_0015D430(p, b, 0); return r; }

typedef struct { void *p; } O_0015AE50;
int func_0015D430(void *, int, int);
// MATCH func_0015AE50
int FUN_0015ae50(O_0015AE50 *o, int b) { void *p = o->p; int r = 0; if (p) r = func_0015D430(p, b, 1); return r; }

typedef struct { void *p; } O_0015AE78;
int func_0015D530(void *);
// MATCH func_0015AE78
int FUN_0015ae78(O_0015AE78 *o) { void *p = o->p; int r = 0; if (p) r = func_0015D530(p); return r; }

void func_0029C980_b(void *, int, int, float, float, float) __asm__("func_0029C980");
// MATCH func_0015DF20
void FUN_0015df20(char *a, float *v) { func_0029C980_b(a + 128, 0, 0, v[0], v[1], v[2]); }

typedef struct { char pad[40]; int v; } S_15ad98_0015AD98;
// MATCH func_0015AD98
int FUN_0015ad98(S_15ad98_0015AD98 **p) { S_15ad98_0015AD98 *q = *p; if (q == 0 || q->v == 0) return 0; return 1; }

typedef struct { char pad[44]; int v; } S_15adc0_0015ADC0;
// MATCH func_0015ADC0
int FUN_0015adc0(S_15adc0_0015ADC0 **p) { S_15adc0_0015ADC0 *q = *p; if (q == 0 || q->v == 0) return 0; return 1; }

void func_00131588_0015AB58(int) __asm__("func_00131588"); void func_00108B80_0015AB58(void *) __asm__("func_00108B80");
// MATCH func_0015AB58
void FUN_0015ab58(int *s, int fl) { if (*s != 0) func_00131588_0015AB58(*s); *s = 0; if (fl & 1) func_00108B80_0015AB58(s); }

typedef struct { char pad[224]; char a[1]; char pad1[19]; char b[1]; char pad2[19]; char c[1]; } S_0015DF40;
void func_0029D010_0015DF40(void *, int, int, float) __asm__("func_0029D010");
// MATCH func_0015DF40
void FUN_0015df40(S_0015DF40 *s, float *v) { func_0029D010_0015DF40(s->a, 0, 0, v[0]); func_0029D010_0015DF40(s->b, 0, 0, v[1]); func_0029D010_0015DF40(s->c, 0, 0, v[2]); }

typedef struct { int x, y, z; float w; } V_0015DFD8;
typedef struct { char p[48]; V_0015DFD8 v; } O_0015DFD8;
void func_0018EB98_0015DFD8(O_0015DFD8 *, int) __asm__("func_0018EB98"); void func_0018F3D8_0015DFD8(O_0015DFD8 *, int, O_0015DFD8 *) __asm__("func_0018F3D8");
static inline void set_0015DFD8(V_0015DFD8 *v) { v->x = 0; v->y = 0; v->z = 0; v->w = 1.0f; }
// MATCH func_0015DFD8
void FUN_0015dfd8(O_0015DFD8 *o, int b, int c) { func_0018EB98_0015DFD8(o, c); set_0015DFD8(&o->v); func_0018F3D8_0015DFD8(o, b, o); }

typedef struct { char p[16]; unsigned long long *w16; } S_0015A6D0;
extern S_0015A6D0 D_00342CD0_0015A6D0 __asm__("D_00342CD0"); typedef struct { int w0; } O_0015A6D0; void func_00190328_0015A6D0(S_0015A6D0 *) __asm__("func_00190328"); void func_00190420_0015A6D0(S_0015A6D0 *) __asm__("func_00190420"); void func_001588F8(int);
// MATCH func_0015A6D0
void FUN_0015a6d0(O_0015A6D0 *o) { unsigned long long *p; func_00190328_0015A6D0(&D_00342CD0_0015A6D0); p = D_00342CD0_0015A6D0.w16; p[0] = 5; p[1] = 8; D_00342CD0_0015A6D0.w16 = p + 2; func_00190420_0015A6D0(&D_00342CD0_0015A6D0); func_001588F8(o->w0); }

int func_0018D800(void); void func_00190328_0015A610(char *) __asm__("func_00190328"); void func_00190420_0015A610(char *) __asm__("func_00190420"); void func_001585E0(int); void func_0018F3D8_0015A610(int *, int, int) __asm__("func_0018F3D8"); void func_001555A0(char *, int *); void func_0018D8B8(int, int, int, int, int, int);
extern char D_00342CD0_0015A610[] __asm__("D_00342CD0"); extern char D_00342D00_0015A610[] __asm__("D_00342D00"); extern char D_004A2AE8[];
// MATCH func_0015A610
void FUN_0015a610(int *a) { int v[16]; int r = func_0018D800(); long *q; func_00190328_0015A610(D_00342CD0_0015A610); q = *(long **)(D_00342CD0_0015A610 + 16); 
q[0] = 5;
q[1] = 8;
*(long **)(D_00342CD0_0015A610 + 16) = q + 2;func_00190420_0015A610(D_00342CD0_0015A610); func_001585E0(*a); func_0018F3D8_0015A610(v, 0x70003bc0, 0x70003c00); func_001555A0(D_00342D00_0015A610, v); func_0018D8B8(r, (int)D_004A2AE8, 120, 198, 0, 0x80f080); }
