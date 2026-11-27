#include "../common.h"
typedef struct { int a; int b; short c; short d; short e; short f; char p[0x24-0x10]; void *g; char q[0x34-0x28]; int h; char r[0x60-0x38]; short k; char s[128-0x62]; } Sub;
typedef struct { char p[0x88]; Sub e[1]; } O;
void func_00235028(Sub *);
// MATCH func_002215A8
void FUN_002215a8(O *o, int a, int b, int i, int d, int e) {  o->e[i].h = e; o->e[i].e = a; o->e[i].k = d; o->e[i].f = b; o->e[i].c = a; o->e[i].d = b; o->e[i].a = 9; o->e[i].g = (void *)0xfffe7960; o->e[i].b = 0; func_00235028(&o->e[i]); }
