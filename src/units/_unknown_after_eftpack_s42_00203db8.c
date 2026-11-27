#include "../common.h"
extern char D_004A4510;
typedef struct { int p0; void * c[64]; int d[64]; int pad[3]; int n; int pad2[2]; short a[64]; char b[64]; char k[64]; } O;
// MATCH func_00203DB8
void FUN_00203db8(O *o, int a, int b, int c, int d) { if (o->n < 64) { o->k[o->n] = d ? 102 : 103; o->a[o->n] = a; o->b[o->n] = b; o->c[o->n] = (void *)&D_004A4510; o->d[o->n] = c; o->n++; } }
