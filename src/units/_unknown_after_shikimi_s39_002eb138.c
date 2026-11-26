// compiler: 990721-r5900
// cflags:
#include "../common.h"
typedef struct { int w0; int w4; int w8; int w12; } H_2eb138;
extern H_2eb138 D_00635340[]; extern int D_00429918[]; extern int D_00429920[];
H_2eb138 *func_002E90A8(void); int func_002EA9F0(int, int);
int func_002E95B0(int); void func_002E96B8(void); void func_002E95E0(void); void func_002E58E0(int); void func_002E58C0(int);
// MATCH func_002EB138
int FUN_002eb138(int a0)
{
    H_2eb138 *h;
    int r;
    func_002E95B0(9);
    if (D_00429918[0] == 0)
        func_002E96B8();
    func_002E95E0();
    h = func_002E90A8();
    if (h == 0)
        return -19;
    r = func_002EA9F0(a0, 9);
    if (r < 0) {
        func_002E58E0(D_00429920[0]);
        h->w4 = 0;
        func_002E58C0(D_00429920[0]);
        return r;
    }
    func_002E58E0(D_00429920[0]);
    { register H_2eb138 *b __asm__("$3") = D_00635340; int s; h->w0 = r; __asm__(""); { register int s4 __asm__("$4"); register int d __asm__("$3"); s4 = D_00429920[0]; __asm__(""); d = (char *)h - (char *)b; r = d >> 4; func_002E58C0(s4); } }

    return r;
}
