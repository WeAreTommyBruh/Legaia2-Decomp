#include "../common.h"
// compiler: 991111-01
extern float D_0049FE6C;
extern void func_002DC804(void *, int, int);
extern int func_00163118(int, int);
extern float func_001631E8(int, int, int, int, int);
extern float func_00160018(float);
extern void func_0018EC58(int), func_0018E3A8(float *, float *, float *, float *), func_00248CF8(int, float), func_0018F3D8(int, int, float *), func_00249100(float, float, float), func_0018EB98(int, int);
// MATCH func_0012C498
float battle_0012c498(float s, int p2, int p3, int n, int flag, float *q)
{
    float a[8], b[4], c[4], d[4], m[16];
    float k, r6, r, ret;
    register float *pb __asm__("$20"); register float *pc __asm__("$18"); float *pd, *pm;
    func_002DC804(a, 0, 16);
    func_002DC804(a + 4, 0, 16);
    if (func_00163118(p2, p3) - 1 < n) n = func_00163118(p2, p3) - 1;
    k = 0.017453292f;
    a[0] = func_001631E8(p2, p3, 0, 0, n);
    a[1] = func_001631E8(p2, p3, 0, 1, n);
    a[2] = func_001631E8(p2, p3, 0, 2, n);
    a[4] = func_001631E8(p2, p3, 0, 3, n);
    a[5] = func_001631E8(p2, p3, 0, 4, n);
    a[6] = func_001631E8(p2, p3, 0, 5, n);
    r6 = func_001631E8(p2, p3, 0, 6, n) * k;
    r = func_00160018(func_001631E8(p2, p3, 0, 7, n) * k);
    ret = 448.0f / r;
    if (flag == 0) {
        b[0] = -a[0] * s;
        b[2] = -(a[2] * s);
        b[1] = a[1] * s;
        { float *x = b; x[3] = 1.0f; pb = x; }
        c[0] = -a[4] * s - b[0];
        c[1] = a[5] * s - b[1];
        c[2] = -a[6] * s - b[2];
        { float *x = c; x[3] = 1.0f; pc = x; }
    } else {
        b[0] = a[0] * s;
        b[1] = a[1] * s;
        b[2] = a[2] * s;
        { float *x = b; x[3] = 1.0f; pb = x; }
        c[0] = a[4] * s - b[0];
        c[1] = a[5] * s - b[1];
        c[2] = a[6] * s - b[2];
        { float *x = c; x[3] = 1.0f; pc = x; }
    }
    pd = d;
    d[0] = 0.0f; pd[1] = 1.0f; d[2] = 0.0f; pd[3] = 1.0f;
    func_0018EC58(0x70003f80);
    pm = m;
    func_0018E3A8(pm, pb, pc, pd);
    func_00248CF8(2, r6);
    func_0018F3D8(0x70003f80, 0x70003f80, pm);
    func_00249100(-q[0], -q[1], -q[2]);
    func_0018EB98(0x70003c00, 0x70003f80);
    func_0018EC58(0x70003f80);
    return ret;
}
