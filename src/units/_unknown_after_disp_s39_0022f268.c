// compiler: 990721-r5900
#include "../common.h"
typedef struct { char p0[0x18]; unsigned fl; char p1c[0x7c]; int h98; char p9c[0x24]; unsigned m; float pos; float spd; char pcc[0x80]; int r14c; char p150[0x2c]; float acc; } O_22f268;
extern float D_004A062C, D_004A0630; extern int D_004A12B0;
int func_00111870(void); int func_0021B5B8(O_22f268 *);
// MATCH func_0022F268
void FUN_0022f268(O_22f268 *o)
{
    float s, a, lim;
    if (func_00111870() != 0) return;
    s = o->spd;
    a = o->acc;
    if (o->h98 == 0) return;
    if (o->fl & 0x400) return;
    o->fl |= 0x400;
    if ((o->m & 0x24) == 0x24 || (o->m & 2)) goto done;
    if (o->m & 0x800) {
        o->pos += s;
    } else if (s > 0.0f) {
        if (o->pos < 1.0f && a != 0.0f) {
            o->pos += a;
            if (o->pos > D_004A062C) { o->pos = 1.0f; o->acc = 0.0f; }
        } else {
            o->pos += s;
        }
    } else {
        lim = func_0021B5B8(o) - 2;
        if (lim <= o->pos && a != 0.0f) {
            o->pos += a;
            if (o->pos <= lim + D_004A0630) { o->pos = lim; o->acc = 0.0f; }
        } else {
            o->pos += s;
        }
    }
done:
    o->r14c = D_004A12B0;
}
