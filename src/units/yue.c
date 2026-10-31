/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p[120]; int v; } O_001E8D08;
// MATCH func_001E8D08
int yue_001e8d08(O_001E8D08 *o, int a) { if (a < 2) return 0; o->v = a; return 1; }

typedef struct { char p[100]; char *w100; char q[744]; void *w848; int w852, w856, w860, w864, w868, w872; } O_001E7F28;
extern char D_0044CAE8[]; void func_00131588(void *); void func_001E2400(O_001E7F28 *, int);
// MATCH func_001E7F28
void yue_001e7f28(O_001E7F28 *o, int a) { o->w100 = D_0044CAE8; if (o->w848) func_00131588(o->w848); o->w848 = 0; o->w852 = 0; o->w856 = 0; o->w860 = 0; o->w864 = 0; o->w868 = 0; o->w872 = 0; func_001E2400(o, a); }

typedef struct { float f0, f4, f8, f12, f16, f20, f24, f28; } S_001EA630;
typedef struct { char p[156]; int w156; float f160, f164, f168, f172, f176, f180; int w184; } O_001EA630;
// MATCH func_001EA630
void yue_001ea630(O_001EA630 *o, S_001EA630 *s) { float a = (float)o->w156, b = (float)o->w184; s->f0 = a; s->f4 = o->f160; s->f8 = o->f164; s->f12 = o->f168; s->f16 = o->f172; s->f20 = o->f176; s->f24 = o->f180; s->f28 = b; }

typedef struct { float a, b, c, d, e, f, g; int pad; int h; } E_001E9468;
typedef struct { char p[296]; E_001E9468 e1, e2, e3; } O_001E9468;
// MATCH func_001E9468
void yue_001e9468(O_001E9468 *o, float x, float y, float w) { float z = 0.0f; E_001E9468 *p1 = &o->e1, *p2 = &o->e2, *p3 = &o->e3; p1->b = x; p1->d = z; p1->c = x; p1->f = z; p1->e = z; p1->g = z; p1->h = 1; o->e1.a = x; p2->d = z; p2->b = y; p2->c = y; p2->f = z; p2->e = z; p2->g = z; o->e2.a = y; p3->b = w; p3->c = w; p3->f = z; p3->e = z; p3->g = z; p3->d = z; p2->h = 1; o->e3.a = w; p3->h = 1; }

typedef struct { float a, b, c, d, e, f, g; int pad; int h; } E_001E9558;
typedef struct { char p[512]; E_001E9558 e1, e2, e3; } O_001E9558;
// MATCH func_001E9558
void yue_001e9558(O_001E9558 *o, float x, float y, float w) { float z = 0.0f; E_001E9558 *p1 = &o->e1, *p2 = &o->e2, *p3 = &o->e3; p1->b = x; p1->d = z; p1->c = x; p1->f = z; p1->e = z; p1->g = z; p1->h = 1; o->e1.a = x; p2->d = z; p2->b = y; p2->c = y; p2->f = z; p2->e = z; p2->g = z; o->e2.a = y; p3->b = w; p3->c = w; p3->f = z; p3->e = z; p3->g = z; p3->d = z; p2->h = 1; o->e3.a = w; p3->h = 1; }

typedef struct { float a, b, c, d, e, f, g; int pad; int h; } E_001E9798;
typedef struct { char p[620]; E_001E9798 e1, e2, e3; } O_001E9798;
// MATCH func_001E9798
void yue_001e9798(O_001E9798 *o, float x, float y, float w) { float z = 0.0f; E_001E9798 *p1 = &o->e1, *p2 = &o->e2, *p3 = &o->e3; p1->b = x; p1->d = z; p1->c = x; p1->f = z; p1->e = z; p1->g = z; p1->h = 1; o->e1.a = x; p2->d = z; p2->b = y; p2->c = y; p2->f = z; p2->e = z; p2->g = z; o->e2.a = y; p3->b = w; p3->c = w; p3->f = z; p3->e = z; p3->g = z; p3->d = z; p2->h = 1; o->e3.a = w; p3->h = 1; }

typedef struct { float a, b, c, d, e, f, g; int pad; int h; } E_001E99D8;
typedef struct { char p[728]; E_001E99D8 e1, e2, e3; } O_001E99D8;
// MATCH func_001E99D8
void yue_001e99d8(O_001E99D8 *o, float x, float y, float w) { float z = 0.0f; E_001E99D8 *p1 = &o->e1, *p2 = &o->e2, *p3 = &o->e3; p1->b = x; p1->d = z; p1->c = x; p1->f = z; p1->e = z; p1->g = z; p1->h = 1; o->e1.a = x; p2->d = z; p2->b = y; p2->c = y; p2->f = z; p2->e = z; p2->g = z; o->e2.a = y; p3->b = w; p3->c = w; p3->f = z; p3->e = z; p3->g = z; p3->d = z; p2->h = 1; o->e3.a = w; p3->h = 1; }

typedef struct { float a, b, c, d, e, f, g; int pad; int h; } E_001E94E0;
typedef struct { char p[404]; E_001E94E0 e1, e2, e3; } O_001E94E0;
// MATCH func_001E94E0
void yue_001e94e0(O_001E94E0 *o, float x, float y, float w) { float z = 0.0f; E_001E94E0 *p1 = &o->e1, *p2 = &o->e2, *p3 = &o->e3; p1->b = x; p1->d = z; p1->c = x; p1->f = z; p1->e = z; p1->g = z; p1->h = 1; o->e1.a = x; p2->d = z; p2->b = y; p2->c = y; p2->f = z; p2->e = z; p2->g = z; o->e2.a = y; p3->b = w; p3->c = w; p3->f = z; p3->e = z; p3->g = z; p3->d = z; p2->h = 1; o->e3.a = w; p3->h = 1; }

extern int D_004A3864_001E7E38 __asm__("D_004A3864"); extern char D_004A3E80[], D_0044C398[]; void *func_00162130_001E7E38(int, char *, int) __asm__("func_00162130"); void *func_001E7EC8(void *); void func_001118F8_001E7E38(char *, ...) __asm__("func_001118F8"); void func_001E8008(void *, int, int);
// MATCH func_001E7E38
void *yue_001e7e38(int a, int b, int c) { void *p = func_001E7EC8(func_00162130_001E7E38(880, D_004A3E80, 235)); if (D_004A3864_001E7E38 & 0x40) func_001118F8_001E7E38(D_0044C398, p); if (p == 0) return 0; func_001E8008(p, b, c); return p; }

extern int D_0035A780_001E92B0[] __asm__("D_0035A780");
void func_001E52B0(int); int func_001E7CB0(int, int); int akari_001e2628(int, int);
// MATCH func_001E92B0
void yue_001e92b0(int p1, int p2, int p3) { if (*(int *)(p1 + 0x88) == 0) { if (0 < p2) { func_001E52B0(*(int *)(p1 + 0x84)); akari_001e2628(p1, (int)((char *)D_0035A780_001E92B0 + *(int *)(p1 + 0x84) * 0x100)); } } else if (p2 == 0) { func_001E7CB0(*(int *)(p1 + 0x84), p3); } if ((unsigned)p2 < 2) *(int *)(p1 + 0x88) = p2; }
