// compiler: 991111-01
#include "../common.h"
typedef struct { char p[476]; void * a; char q[16]; unsigned f; char r[108]; } E608;
typedef struct { char p[76]; int f76; int f80; char q[8]; int f92; } O_29F948;
extern E608 D_005F9640[];
void clas_min_0029fa18(void *);
// MATCH func_0029F948
void clas_min_0029f948(O_29F948 *o, int i) { o->f80 = i; if (i != -1) { int k = 608; E608 *e = (E608 *)((char *)D_005F9640 + i * k); o->f92 = 3; o->f76 &= ~0x2000; if (e->a != 0 && !(e->f & 0x2000)) { e->f |= 0x2000; clas_min_0029fa18(o); } } }
