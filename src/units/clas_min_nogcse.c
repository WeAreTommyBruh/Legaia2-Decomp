/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct N_0029D3D0 { char p[60]; struct N_0029D3D0 *w60; } N_0029D3D0;
void func_002BF250(N_0029D3D0 *, int);
// MATCH func_0029D3D0
void clas_min_0029d3d0(N_0029D3D0 *o) { if (o->w60 != 0) { N_0029D3D0 *p; do { p = o->w60; o->w60 = p->w60; if (p != 0) func_002BF250(p, 3); } while (o->w60 != 0); } }

void func_00190328(int); void func_00190420(int *); void func_002A5470(int *, int, int, int);
typedef struct { char p[16]; long *q; } P_002A53B0;
// MATCH func_002A53B0
void clas_min_002a53b0(int *o, int a, int b, int c) { P_002A53B0 *p; long *q; if (o[28] != 0) func_00190328(o[30]); p = (P_002A53B0 *)o[30]; q = p->q; q[0] = 97; q[1] = 20; q[2] = 0x31001; q[3] = 71; q[4] = 0x790000006c00L; q[5] = 24; p->q = q + 6; if (o[28] != 0) func_00190420((int *)p); func_002A5470(o, a, b, c); }

typedef struct { char p[16]; long *q; } G_002A5EC0;
typedef struct { char p[88]; int w88; int w92; int w96; char p2[12]; int w112; char p3[4]; G_002A5EC0 *g; } O_002A5EC0;
extern unsigned D_004A12B0_002A5EC0 __asm__("D_004A12B0"); extern unsigned D_004A12B4;
void func_00190328_002A5EC0(G_002A5EC0 *) __asm__("func_00190328"); void func_00190420_002A5EC0(G_002A5EC0 *) __asm__("func_00190420");
// MATCH func_002A5EC0
void clas_min_002a5ec0(O_002A5EC0 *o) { G_002A5EC0 *g; long *q; int x, y; o->w88 = (D_004A12B0_002A5EC0 & 1) ? 0 : 2240; o->w96 = (D_004A12B4 & 1) << 3; if (o->w112 != 0) func_00190328_002A5EC0(o->g); x = o->w88; y = o->w96; g = o->g; q = g->q; q[0] = 0x5000d; q[1] = 71; q[2] = 33; q[3] = 20; q[4] = 68; q[5] = 66; q[6] = (x / 32) | 0xa0000; q[7] = 76; q[8] = ((long)(y + 30976) << 32) | 27648; q[9] = 24; q[10] = 5; q[11] = 8; g->q = q + 12; if (o->w112 != 0) func_00190420_002A5EC0(g); }

typedef struct P_29cfb8_0029CFB8 { char p[16]; struct P_29cfb8_0029CFB8 *w16; } P_29cfb8_0029CFB8;
extern float D_004A6990;
int func_0029D0B8(void *, void *);
void func_002BF2C0(void *, int);
// MATCH func_0029CFB8
void clas_min_0029cfb8(P_29cfb8_0029CFB8 *o)
{
    if (func_0029D0B8(o, &D_004A6990))
        *(float *)o = D_004A6990;
    while (o->w16 != 0) {
        P_29cfb8_0029CFB8 *p = o->w16;
        o->w16 = p->w16;
        if (p != 0) func_002BF2C0(p, 3);
    }
}
