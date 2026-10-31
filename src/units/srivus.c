/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p[1028]; float f; } O_00188090; extern char D_0033B520[]; void func_00187028(void *); void func_00186F40(void *, void *, int, int);
// MATCH func_00188090
void srivus_00188090(O_00188090 *o) { func_00187028(o); o->f = 384.0f; func_00186F40(o, D_0033B520, 22, 23); }

typedef struct { char p[1028]; float f; } O_00188158; extern char D_0033C348[]; void func_00187028(void *); void func_00186F40(void *, void *, int, int);
// MATCH func_00188158
void srivus_00188158(O_00188158 *o) { func_00187028(o); o->f = 384.0f; func_00186F40(o, D_0033C348, 28, 30); }

typedef struct { char p[1028]; float f; } O_00188220; extern char D_0033D190[]; void func_00187028(void *); void func_00186F40(void *, void *, int, int);
// MATCH func_00188220
void srivus_00188220(O_00188220 *o) { func_00187028(o); o->f = 384.0f; func_00186F40(o, D_0033D190, 30, 32); }

typedef struct { char p[1224]; void *vt; } O_00187F10; extern char D_00339F20[], D_0043EDE0[]; void func_00187028(void *); void func_00186F40(void *, void *, int, int);
// MATCH func_00187F10
void srivus_00187f10(O_00187F10 *o) { func_00187028(o); func_00186F40(o, D_00339F20, 6, 11); o->vt = D_0043EDE0; }

typedef struct { char p[1224]; void *vt; char p2[552]; int w; } O_00188FA0;
extern char D_0033FD18[], D_0043F620[]; void func_00187028(void *); void func_00186F40(void *, void *, int, int);
// MATCH func_00188FA0
void srivus_00188fa0(O_00188FA0 *o) { func_00187028(o); func_00186F40(o, D_0033FD18, 37, 40); if (o->w == 39) o->vt = D_0043F620; }

typedef struct { char p0[24]; int w24; char p1[4]; float f32, f36, f40; char p2[20]; float f64, f68, f72; } O_001890A0;
void func_00249108_001890A0(void) __asm__("func_00249108"); void func_00249100(float, float, float); void func_00248E00(float, float, float); void func_002489F0(void); void func_002468F0(O_001890A0 *); void func_00246550(O_001890A0 *); void func_002491D8(void);
// MATCH func_001890A0
void srivus_001890a0(O_001890A0 *o) { if (o->w24 & 0x4000000) { o->w24 |= 0x100; func_00249108_001890A0(); func_00249100(o->f32, o->f36, o->f40); func_00248E00(o->f64, o->f68, o->f72); func_002489F0(); func_002468F0(o); func_00246550(o); func_002491D8(); } }

extern int D_0033D9A0[]; void func_00108B80_00188D00(void *) __asm__("func_00108B80"); void func_00187188(char *);
// MATCH func_00188D00
void srivus_00188d00(char *o) { int *t = D_0033D9A0; char *src = *(char **)(o + 18544) + 2056; char *dst = (char *)(*(int *)(*(int *)(o + 1784) + 144)) + 1024; do { *(int *)(dst + (t[0] << 2)) = *(int *)src; t += 3; src += 2064; } while (t < D_0033D9A0 + 12); func_00108B80_00188D00(*(void **)(o + 18544)); *(int *)(o + 18544) = 0; func_00187188(o); }
