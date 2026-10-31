/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p[304]; int w; char p2[940]; int k; } O_00229800;
extern int D_004A1504; extern volatile float D_004A1508, D_004A05B0;
// MATCH func_00229800
void FUN_00229800(O_00229800 *o) { if (o->k == 1) { D_004A1504 = 0; D_004A1508 = D_004A05B0; o->w = 0; } }

typedef struct { char p0[24]; int w24; char p1[4]; float f32, f36, f40; char p2[20]; float f64, f68, f72; } O_002299C0;
void func_00249108_002299C0(void) __asm__("func_00249108"); void func_00249100(float, float, float); void func_00248E00(float, float, float); void func_002489F0(void); void func_00246550_002299C0(O_002299C0 *) __asm__("func_00246550"); void func_002491D8(void);
// MATCH func_002299C0
void FUN_002299c0(O_002299C0 *o) { if (o->w24 & 0x4000000) { o->w24 |= 0x100; func_00249108_002299C0(); func_00249100(o->f32, o->f36, o->f40); func_00248E00(o->f64, o->f68, o->f72); func_002489F0(); func_00246550_002299C0(o); func_002491D8(); } }

typedef struct { char p0[24]; int w24; } O_00229CD8;
typedef struct { char p0[32]; float f32, f36, f40; char p2[20]; float f64, f68, f72; } P_00229CD8;
typedef struct { char p[324]; int w324; char q[4]; P_00229CD8 *w332; } G_00229CD8;
extern G_00229CD8 *D_004A1A3C_00229CD8 __asm__("D_004A1A3C"); void func_00249108_00229CD8(void) __asm__("func_00249108"); void func_00249100(float, float, float); void func_00248E00(float, float, float); void func_002491D8(void);
// MATCH func_00229CD8
void FUN_00229cd8(O_00229CD8 *o) { if (o->w24 & 0x4000000) { G_00229CD8 *g = D_004A1A3C_00229CD8; P_00229CD8 *p = 0; if (g->w324 > 0) p = g->w332; func_00249108_00229CD8(); func_00249100(p->f32, p->f36, p->f40); func_00248E00(p->f64, p->f68, p->f72); func_002491D8(); } }

extern char D_0043FED0_0022A198[] __asm__("D_0043FED0"), D_0045BE70[];
void func_00202840_0022A198(void *) __asm__("func_00202840"); void func_00229828(void *);
// MATCH func_0022A198
char *FUN_0022a198(char *o) { char *p; int i; *(int *)(o + 2116) = (int)D_0043FED0_0022A198; p = o + 2176; func_00202840_0022A198(o + 24); *(int *)(o + 2116) = (int)D_0045BE70; *(int *)(o + 2128) = -1; *(int *)(o + 2132) = -1; *(int *)(o + 2136) = 0; *(int *)(o + 2140) = 0; *(int *)(o + 2144) = 0; *(int *)(o + 2148) = 0; for (i = 47; i != -1; i--) { func_00229828(p); p += 12432; } *(int *)(o + 2160) = 0; return o; }
