// cflags: -fno-gcse
#include "../common.h"
typedef struct { float u, v, du, dv; } V_22ff58;
typedef struct { char p0[0x90]; char *t; } O_22ff58;
int func_00231580(float, float, O_22ff58 *, int, int);
int func_002306E8(O_22ff58 *, int, int, int);
int func_00231548(void);
// MATCH func_0022FF58
void FUN_0022ff58(O_22ff58 *o, int i, int c, int d)
{
    V_22ff58 *v;
    char *t;
    {
        float *p = (float *)(o->t + i * 16);
        if (*p > 1.0f) *p = 0.0f;
    }
    t = o->t;
    v = (V_22ff58 *)(t + i * 16);
    if (v->u < 0.0f) v->u = 1.0f;
    if (v->v > 1.0f) v->v = 0.0f;
    if (v->v < 0.0f) v->v = 1.0f;
    func_00231580(v->u, v->v, o, *(int *)((int)t + (i << 2) + 0x804), 1);
    func_002306E8(o, i, c, d);
    func_00231548();
    v = (V_22ff58 *)(o->t + i * 16);
    v->u += v->du;
    v->v += v->dv;
}
