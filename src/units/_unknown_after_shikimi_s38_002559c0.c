#include "../common.h"
typedef struct { char p[10]; short v; char q[8]; } T20;
typedef struct { int p; int f4; int f8; char q[60]; } E72;
typedef struct { char p[112]; int f112; int f116; int f120; int f124; char q[48]; } E176;
extern T20 D_003E3D20[];
extern E72 D_003FDFA0[];
extern E176 D_00419D18[];
extern int D_00314D08[];
extern int D_004A12A4;
// MATCH func_002559C0
int FUN_002559c0(unsigned a, int b)
{
    short v; int r, i;
    if (a >= 10 || b < 0 || (unsigned)b >= 94) return -1;
    v = (&D_003E3D20[b])->v;
    r = v;
    if (D_004A12A4 != 11) {
        E72 *e = &D_003FDFA0[a];
        unsigned f, g;
        f = e->f4;
        if (f & 0x400) r -= v / 10;
        g = e->f8;
        if (g & 2) r += v / 10;
        if (f & 0x800) r -= v / 5;
        if (g & 4) r += v / 5;
        if (f & 0x1000) r -= v * 30 / 100;
    } else {
        E176 *e;
        unsigned f, g;
        for (i = 0; i < 3; i++) if (D_00314D08[i] == a) break;
        if (i == 3) return -1;
        e = &D_00419D18[i];
        f = e->f120;
        if (f & 0x400) r = v - v / 10;
        g = e->f124;
        if (g & 2) r += v / 10;
        if (f & 0x800) r -= v / 5;
        if (g & 4) r += v / 5;
        if (f & 0x1000) r -= v * 30 / 100;
        if (e->f112 & 0x40000) r /= 2;
        if (e->f112 & 0x400) r = 0;
    }
    return r;
}
