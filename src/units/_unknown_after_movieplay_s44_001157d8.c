// compiler: 990721-r5900
// cflags: -fexceptions
#include "../common.h"
typedef struct { char p0[16]; long *q; } Pk_1157D8;
typedef struct { int x, y, z, w; } V_1157D8;
extern Pk_1157D8 D_00314C20;
void func_00190328(Pk_1157D8 *); void func_00190420(Pk_1157D8 *);
// MATCH func_001157D8
void FUN_001157d8(int *p, int w, int h, int a, int b, int g0, int r0, int mode0) {
    int g = g0;
    int r = r0;
    register int mode __asm__("$18") = mode0;
    V_1157D8 v[2];
    long *q;
    long prim;
    v[0].x = p[0] * 32 + 0x6c00;
    v[0].y = p[1] * 16 + 0x7900;
    v[0].z = p[2];
    v[1].x = v[0].x + w * 32;
    v[1].y = v[0].y + h * 16;
    v[1].z = p[2];
    { int n = (v[0].x < 0x9400) + (v[0].y < 0x8700) + (v[1].x > 0x6c00) + (v[1].y > 0x7900); if (n != 4) return; }
    { register Pk_1157D8 *pk __asm__("$17") = &D_00314C20;
    func_00190328(pk);
    if (mode == 1) { D_00314C20.q[0] = 72; D_00314C20.q[1] = 66; D_00314C20.q += 2; }
    else if (mode == 2) { D_00314C20.q[0] = 65; D_00314C20.q[1] = 66; D_00314C20.q += 2; }
    else { D_00314C20.q[0] = 68; D_00314C20.q[1] = 66; D_00314C20.q += 2; }
    q = D_00314C20.q;
    q[0] = 0x31001;
    q[1] = 71;
    q[2] = 70;
    q[3] = 0;
    q[4] = (unsigned long)b | (unsigned long)g << 8 | (unsigned long)r << 16 | (unsigned long)a << 24 | 0x3f80000000000000L;
    q[5] = 1;
    q[6] = (long)v[0].x | (long)v[0].y << 16 | (long)v[0].z << 32 | 0x100000000000000L;
    q[7] = 4;
    q[8] = (long)v[1].x | (long)v[1].y << 16 | (long)v[1].z << 32 | 0x100000000000000L;
    q[9] = 4;
    D_00314C20.q = q + 10;
    func_00190420(&D_00314C20); }
}
