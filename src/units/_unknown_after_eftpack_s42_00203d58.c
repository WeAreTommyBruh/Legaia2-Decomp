#include "../common.h"
typedef struct { int p0; void * c[64]; int d[64]; int pad[3]; int n; int pad2[2]; short a[64]; char b[64]; char k[64]; } O;
// MATCH func_00203D58
void FUN_00203d58(O *o, int a, int b, void * c, int d) { if (o->n < 64) { o->k[o->n] = 104; o->a[o->n] = a; o->b[o->n] = b; o->c[o->n] = c; o->d[o->n] = d; o->n++; } }
