/* Matched functions from this unit. */
#include "../common.h"

typedef struct { char p0[16]; long *q; } Pk_1159D8;
extern Pk_1159D8 D_00342CD0;
void func_00190328(Pk_1159D8 *); void func_00190420(Pk_1159D8 *);
// MATCH func_001159D8
void FUN_001159d8(int x, int y, int w, int h, int col0, int col1, int a0, int a1, int d)
{
    int c[2][4];
    int x0, y0, x1, y1;
    long *q;
    x0 = x * 32 + 0x6c00;
    y0 = y * 16 + 0x7900;
    y1 = y0 + h * 16;
    x1 = x0 + w * 32;
    c[0][0] = col0 & 0xff;
    c[0][1] = (col0 / 256) & 0xff;
    c[0][2] = (col0 / 65536) & 0xff;
    c[0][0] = c[0][0] * 128 / d;
    c[0][1] = c[0][1] * 128 / d;
    c[0][2] = c[0][2] * 128 / d;
    c[1][0] = col1 & 0xff;
    c[1][1] = (col1 / 256) & 0xff;
    c[1][2] = (col1 / 65536) & 0xff;
    c[1][0] = c[1][0] * 128 / d;
    c[1][1] = c[1][1] * 128 / d;
    c[1][2] = c[1][2] * 128 / d;
    func_00190328(&D_00342CD0);
    q = D_00342CD0.q;
    q[0] = 68;
    q[1] = 66;
    q[2] = 0x51001;
    q[3] = 71;
    q[4] = 76;
    q[5] = 0;
    q[6] = (long)c[0][0] | (long)c[0][1] << 8 | (long)c[0][2] << 16 | (long)a0 << 24 | 0x3f80000000000000L;
    q[7] = 1;
    q[8] = (long)x0 | (long)y0 << 16;
    q[9] = 5;
    q[10] = (long)x0 | (long)y1 << 16;
    q[11] = 5;
    q[12] = (long)c[1][0] | (long)c[1][1] << 8 | (long)c[1][2] << 16 | (long)a1 << 24 | 0x3f80000000000000L;
    q[13] = 1;
    q[14] = (long)x1 | (long)y0 << 16;
    q[15] = 5;
    q[16] = (long)x1 | (long)y1 << 16;
    q[17] = 5;
    q[18] = 0x5000d;
    q[19] = 71;
    D_00342CD0.q = q + 20;
    func_00190420(&D_00342CD0);
}

typedef struct { int x, y, z, w; } __attribute__((aligned(8))) S_1161B0;
typedef struct { int f0, f4, f8; char p12[36]; int f48; char p52[4]; int f56, f60; char p64[36]; int f100; char p104[72]; } E_1161B0;
extern E_1161B0 D_00419D18[];
extern char D_00364700[], D_003647D4[], D_00360B60[];
int func_00114660(int, int, int, int, int, int, int, int);
void func_00115390(S_1161B0 *, int, int, char *);
// MATCH func_001161B0
void FUN_001161b0(int idx, int mode, S_1161B0 *src, int a, int c, int c6)
{
    int v1 = 0;
    char *t = 0;
    int v2 = 0;
    S_1161B0 s;
    E_1161B0 *e;
    s = *src;
    switch (mode) {
    case 0:
        t = D_00364700;
        v2 = D_00419D18[idx].f56;
        v1 = D_00419D18[idx].f4;
        break;
    case 1:
        t = D_003647D4;
        v2 = D_00419D18[idx].f60;
        v1 = D_00419D18[idx].f8;
        break;
    case 2:
        t = D_003647D4;
        v2 = D_00419D18[idx].f100;
        v1 = D_00419D18[idx].f48;
        break;
    }
    func_00115390(&s, a, c, t);
    s.x += 48;
    func_00114660(5, s.x, s.y, v2, 4, a, c6, 17);
    func_00115390(&s, a, c, D_00360B60);
    s.x += 35;
    func_00114660(5, s.x, s.y, v1, 4, a, c6, 17);
}
