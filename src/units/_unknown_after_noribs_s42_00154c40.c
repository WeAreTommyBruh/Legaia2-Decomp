// compiler: 990721
#include "../common.h"
typedef struct { char pad[176]; int a[38]; int n; } O;
// MATCH func_00154C40
int FUN_00154c40(O *o, int v) { int i; if (v == 0) return 0; if (o->n >= 4) return 0; for (i = 0; i < o->n; i++) if (o->a[i] == v) return 0; o->a[o->n++] = v; return 1; }
