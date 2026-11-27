// compiler: 990721-r5900
#include "../common.h"
#define T_231A68(ate, atst, aref, afail, date, datm, zte, ztst) ((unsigned long)(ate) | (unsigned long)(atst) << 1 | (unsigned long)(aref) << 4 | (unsigned long)(afail) << 12 | (unsigned long)(date) << 14 | (unsigned long)(datm) << 15 | (unsigned long)(zte) << 16 | (unsigned long)(ztst) << 17)
typedef struct { char p0[16]; unsigned long *q; } P_231A68;
extern int D_004A70BC, D_004A7094, D_004A7098;
void func_00190328(P_231A68 *); void func_00190420(P_231A68 *);
// MATCH func_00231A68
void FUN_00231a68(int a, P_231A68 *g)
{
    unsigned long *q, *p;
    func_00190328(g);
    q = g->q;
    p = q + 2;
    q[1] = 0x49;
    q[0] = 0;
    g->q = p;
    if (a != 0) {
        p[0] = T_231A68(1, 6, a, 1, D_004A7094, D_004A7098, 1, 2);
        p[1] = 0x47;
        g->q = p + 2;
    } else {
        p[0] = T_231A68(0, 5, 0, 1, D_004A7094, D_004A7098, 1, 2);
        p[1] = 0x47;
        g->q = p + 2;
    }
    func_00190420(g);
    D_004A70BC = a;
}
