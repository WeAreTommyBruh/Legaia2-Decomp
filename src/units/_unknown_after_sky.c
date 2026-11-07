/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char pad[128]; int n; char p[8]; int v; } S_001565E8;
void func_001562F8(void *);
// MATCH func_001565E8
void FUN_001565e8(S_001565E8 *s, int i) { if (i < 0) i = 0; if (i >= s->n) i = s->n - 1; s->v = i; func_001562F8(s); }

typedef struct { char pad[222]; short n; char p[8]; int v; } S_00156D70;
void func_00156A78(void *);
// MATCH func_00156D70
void FUN_00156d70(S_00156D70 *s, int i) { if (i < 0) i = 0; if (i >= s->n) i = s->n - 1; s->v = i; func_00156A78(s); }

typedef struct { float x, y, z, w; } V_156570_00156570;
typedef struct { char pad[96]; V_156570_00156570 v; float f112; } S_156570_00156570;
static inline void set_156570_00156570(V_156570_00156570 *v, float x, float y, float z, float w) { v->x = x; v->y = y; v->z = z; v->w = w; }
// MATCH func_00156570
void FUN_00156570(S_156570_00156570 *s, float f, int a, int b, int c) { s->f112 = f; set_156570_00156570(&s->v, (float)a, (float)b, (float)c, 1.0f); }

typedef struct { float x, y, z, w; } V_156b20_00156B20;
typedef struct { char pad[176]; V_156b20_00156B20 v; } S_156b20_00156B20;
static inline void set_156b20_00156B20(V_156b20_00156B20 *v, float x, float y, float z, float w) { v->x = x; v->y = y; v->z = z; v->w = w; }
// MATCH func_00156B20
void FUN_00156b20(S_156b20_00156B20 *s, int a, int b, int c) { set_156b20_00156B20(&s->v, (float)a, (float)b, (float)c, 128.0f); }

typedef struct { float x, y, z, w; } V_156cf8_00156CF8;
typedef struct { char pad[192]; V_156cf8_00156CF8 v; float f208; } S_156cf8_00156CF8;
static inline void set_156cf8_00156CF8(V_156cf8_00156CF8 *v, float x, float y, float z, float w) { v->x = x; v->y = y; v->z = z; v->w = w; }
// MATCH func_00156CF8
void FUN_00156cf8(S_156cf8_00156CF8 *s, float f, int a, int b, int c) { s->f208 = f; set_156cf8_00156CF8(&s->v, (float)a, (float)b, (float)c, 1.0f); }

typedef struct { float x, y, z, w; } V4_001563A0;
typedef struct { char p[64]; V4_001563A0 v1; V4_001563A0 v2; } O_001563A0;
static inline void set_001563A0(V4_001563A0 *v, int x, int y, int z) { v->x = x; v->y = y; v->z = z; v->w = 128.0f; }
// MATCH func_001563A0
void FUN_001563a0(O_001563A0 *o, int a, int b, int c, int d, int e, int f) { set_001563A0(&o->v1, a, b, c); set_001563A0(&o->v2, d, e, f); }

extern int D_004A2ABC; extern char D_00589040[]; void func_0018EB98_00159138(char *, int) __asm__("func_0018EB98"); int func_002492E8(char *);
// MATCH func_00159138
int FUN_00159138(int i) { func_0018EB98_00159138(D_00589040 + i * 128, 0x70003f80); func_002492E8(D_00589040 + 64 + i * 128); if (i == 0) D_004A2ABC = 1; return 1; }

// MATCH func_00156C10
void FUN_00156c10(char *o, unsigned c) { float r = (float)(c & 0xff); float g = (float)((c >> 8) & 0xff); float b = (float)((c >> 16) & 0xff); float a = (float)((c >> 24) & 0xff); float *p = (float *)(o + 176); 
*(float *)(o + 176) = r;
p[1] = g;
p[2] = b;
p[3] = a;}

extern unsigned short D_004A14B8_001591A0 __asm__("D_004A14B8"); void func_00249100(float, float, float); void func_00248E00(float, float, float); void func_00248B28(float, float, float); void func_0018EB98_001591A0(char *, int) __asm__("func_0018EB98"); void func_002492E8_001591A0(char *) __asm__("func_002492E8");
// MATCH func_001591A0
void FUN_001591a0(char *o) { float *f = (float *)o; func_00249100(f[0], f[1], f[2]); func_00248E00(f[4], f[5], f[6]); func_00248B28(f[8], f[9], f[10]); func_0018EB98_001591A0(o + 80, 0x70003f80); func_0018EB98_001591A0(o + 208, 0x70003c80); func_002492E8_001591A0(o + 144); *(unsigned short *)(o + 272) = D_004A14B8_001591A0; }

int func_0018D800(void); void func_00248A58(int); void func_002468F8(int *, int); void func_0018D8B8(int, int, int, int, int, int);
// MATCH func_00157978
int FUN_00157978(int *o) { int r = func_0018D800(); int n; if ((o[6] & 0x2000a) == 0) { func_00248A58(0x70003f80); func_00248A58(0x70003d80); func_00248A58(0x70003c80); if (o[5] != 0) ((void (*)(int *))o[5])(o); } else func_002468F8(o, 0); n = o[3]; func_0018D8B8(r, 0, 0, 0, 8, 0xf08080); return n; }

void func_0018F450(int, char *); void func_0018F348(int, int); void func_001577C0(char *, char *);
// MATCH func_00157800
void FUN_00157800(char *o, char **h1, char **h2) { *(int *)(o + 300) = 0; *(int *)(o + 304) = 0; if (*(short *)(o + 282) != 0) { func_0018F450(0x70003c00, o + 80); func_0018F348(0x70003e10, 0x70003e00); *(float *)(o + 296) = *(float *)0x70003e18; if (*h1 == 0) *h1 = o; else func_001577C0(*h1, o); } else { *(char **)(o + 304) = *h2; *h2 = o; } }

int func_0018D800(void); void func_00248A58(int); void func_002468F8(int *, int); void func_0018D8B8(int, int, int, int, int, int);
// MATCH func_00157A30
int FUN_00157a30(int *o) { int r = func_0018D800(); if ((o[6] & 0x2000a) == 0) { func_00248A58(0x70003f80); func_00248A58(0x70003d80); func_00248A58(0x70003c80); if (o[5] != 0) { unsigned s = o[6]; unsigned t = s & 0x10000000; o[6] = s & 0xefffffff; ((void (*)(int *))o[5])(o); o[6] |= t; } } else func_002468F8(o, 0); o = (int *)o[3]; func_0018D8B8(r, 0, 0, 0, 8, 0xf08080); return (int)o; }

extern unsigned D_004A6F40; extern unsigned D_004A14B8_001588F8 __asm__("D_004A14B8"); extern int D_004A13F0; extern char D_00333910[]; extern char D_00333990[]; extern char D_00333950[];
int func_00157978(int); void func_0018EB98_001588F8(int, int) __asm__("func_0018EB98"); void func_00247970_001588F8(unsigned) __asm__("func_00247970"); void func_002479F0(void); void func_00247A48_001588F8(unsigned, long) __asm__("func_00247A48"); void func_00249108_001588F8(void) __asm__("func_00249108"); void func_002491D8(void); void func_002492E8_001588F8(int) __asm__("func_002492E8");
// MATCH func_001588F8
void FUN_001588f8(void) { int iVar1; func_00249108_001588F8(); func_0018EB98_001588F8((int) D_00333910, 0x70003f80); func_0018EB98_001588F8((int) D_00333990, 0x70003c80); func_002492E8_001588F8((int) D_00333950); D_004A6F40 = D_004A14B8_001588F8; func_00247970_001588F8(2); func_00247A48_001588F8(0x42, 0x44); func_00247A48_001588F8(0x47, 0x5000d); func_002479F0(); for (iVar1 = D_004A13F0; iVar1 != 0; iVar1 = func_00157978(iVar1)) { } func_002491D8(); }

typedef struct O__001578A0 { char pad[80]; char v80[202]; short s282; char pad2[12]; float f296; int i300; struct O__001578A0 *i304; } O__001578A0;
extern float D_70003E18_1578A0[] __asm__("D_70003E18");
float func_0018ECB8_1578A0() __asm__("func_0018ECB8"); void func_0018F450_1578A0(int, void *) __asm__("func_0018F450"); void func_0018F348_1578A0(int, int) __asm__("func_0018F348"); void func_001577C0_1578A0(O__001578A0 *, O__001578A0 *) __asm__("func_001577C0");
// MATCH func_001578A0
void FUN_001578a0(O__001578A0 *o, O__001578A0 **p2, O__001578A0 **p3, float *a3) { o->i300 = 0; o->i304 = 0; if (func_0018ECB8_1578A0(o, a3) - a3[3] <= 0.0f) return; if (o->s282 != 0) { func_0018F450_1578A0(0x70003c00, o->v80 - 0 + 0); func_0018F348_1578A0(0x70003e10, 0x70003e00); o->f296 = *(float *)0x70003e18; if (*p2 == 0) *p2 = o; else func_001577C0_1578A0(*p2, o); } else { *(O__001578A0 **)((char *)o + 304) = *p3; *p3 = o; } }

