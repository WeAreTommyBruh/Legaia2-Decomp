#include "../common.h"
typedef struct { int *w0; int w4; void *w8; void *w12; } Pk_2CF5A0;
void *func_002CF458(void *);
// MATCH func_002CF5A0
void FUN_002cf5a0(Pk_2CF5A0 *o, unsigned a, unsigned b)
{
    void *r = func_002CF458(o);
    int *p = o->w0;
    *(p++) = b | 0x50000000;
    o->w8 = r;
    *p = a & 0x9fffffff;
    o->w0 = p + 1;
    o->w12 = 0;
}
