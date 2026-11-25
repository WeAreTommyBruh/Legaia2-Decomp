// compiler: 991111-01-as210
// cflags: -fno-schedule-insns
#include "../common.h"
extern int D_004A1490, D_004A1494, D_004A126C;
extern char D_0043E318[];
void *func_00162130();
// MATCH func_001804F0
void modelpkt_001804f0(int *p, int *q, int r) {
    int t;
    int *s, *s2;
    int t2;
    void *m;
    p[0] = 0;
    p[1] = 0;
    p[10] = r;
    t = q[3];
    p[2] = t;
    if (t <= 0) {
        { int a = D_004A1490, b = D_004A1494; p[0] = a; p[1] = b; }
    } else {
        p[0] = t;
    }
    q[3] = p[0];
    p[3] = q[14];
    q[4] = p[1];
    p[4] = q[15];
    {char *fn = D_0043E318; int n = 1024; int ln = 3486; __asm__("" : "+r"(fn)); __asm__("" : "+r"(ln)); __asm__("" : "+r"(n)); m = func_00162130(n, fn, ln); }
    p[5] = (int)m;
    s = (int *)p[3];
    q[13] = (int)m;
    p[8] = 0;
    if (s != 0) {
        t = *s;
        p[9] = 0;
        p[8] = t;
    }
    s2 = (int *)p[4];
    q[17] = 0;
    if (s2 != 0) {
        q[17] = D_004A126C + q[2];
        t2 = *s2;
        p[7] = t2;
        p[6] = 0;
        *(short *)(q + 18) = p[7];
    }
}
