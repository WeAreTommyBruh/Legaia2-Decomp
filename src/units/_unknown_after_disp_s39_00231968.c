// compiler: 990721-r5900
#include "../common.h"
#define T_231968(ate, atst, aref, afail, date, datm, zte, ztst) ((unsigned long)(ate) | (unsigned long)(atst) << 1 | (unsigned long)(aref) << 4 | (unsigned long)(afail) << 12 | (unsigned long)(date) << 14 | (unsigned long)(datm) << 15 | (unsigned long)(zte) << 16 | (unsigned long)(ztst) << 17)
typedef struct { char p0[16]; unsigned long *q; } P_231968;
extern P_231968 D_00342CD0;
extern int D_004A70BC, D_004A70C0, D_004A7094, D_004A7098;
void func_00190328(P_231968 *); void func_00190420(P_231968 *);
// MATCH func_00231968
void FUN_00231968(int a)
{
    unsigned long *q, *p;
    D_004A70C0 = D_004A70BC;
    D_004A70BC = a;
    func_00190328(&D_00342CD0);
    q = D_00342CD0.q;
    p = q + 2;
    q[1] = 0x49;
    q[0] = 0;
    D_00342CD0.q = p;
    if (a != 0) {
        p[0] = T_231968(1, 6, a, 1, D_004A7094, D_004A7098, 1, 2);
        p[1] = 0x47;
        D_00342CD0.q = p + 2;
    } else {
        p[0] = T_231968(0, 5, 0, 1, D_004A7094, D_004A7098, 1, 2);
        p[1] = 0x47;
        D_00342CD0.q = p + 2;
    }
    func_00190420(&D_00342CD0);
}
