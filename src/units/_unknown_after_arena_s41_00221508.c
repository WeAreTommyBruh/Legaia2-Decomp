#include "../common.h"
typedef struct { int a; int b; short c; short d; short e; short f; char p[0x24-0x10]; void *g; char q[0x34-0x28]; int h; char r[0x60-0x38]; short k; char s[128-0x62]; } Sub_221508;
typedef struct { char p[0x88]; Sub_221508 e[1]; } O_221508;
void func_00235028(Sub_221508 *);
// MATCH func_00221508
void FUN_00221508(O_221508 *o, int b, int c, int i, int k, int f, void *g) { o->e[i].h = f; o->e[i].a = 9; o->e[i].g = g; o->e[i].k = k; o->e[i].e = b; o->e[i].c = b; o->e[i].b = 0; o->e[i].f = c; o->e[i].d = c; func_00235028(&o->e[i]); }
