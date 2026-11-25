#include "../common.h"
typedef struct { char p0[8]; short h8, h10; } S; typedef struct { int pad[4]; int a[4]; int b[4]; S *c[4]; } E;
// MATCH func_00247468
void FUN_00247468(E *e, int i, S *s) { e->a[i] = s->h8; e->b[i] = s->h10; e->c[i] = s; }
