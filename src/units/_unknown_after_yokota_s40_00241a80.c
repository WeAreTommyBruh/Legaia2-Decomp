#include "../common.h"
typedef struct { char p[1280]; void (*fn[3])(void); char q[2052 - 1292]; int *t[3]; } X;
typedef struct { char p[24]; unsigned fl; char q[116]; X *x; char r[24]; short h; } O;
extern int D_003D6D10[];
void func_0022FEC0(void);
// MATCH func_00241A80
void FUN_00241a80(O *o) { if (o->h == 0xd9) o->fl |= 0x40000000; o->fl |= 0x140000; o->x->fn[0] = func_0022FEC0;   o->x->t[0] = D_003D6D10;   o->x->fn[1] = func_0022FEC0;   o->x->fn[2] = func_0022FEC0;   o->x->t[1] = D_003D6D10;   o->x->t[2] = D_003D6D10; }
