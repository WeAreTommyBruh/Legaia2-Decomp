// compiler: 990721
#include "../common.h"
typedef struct { char pad[196]; int a[34]; int n; } O;
// MATCH func_00154CB0
int FUN_00154cb0(O *o, int v) { int i; if (v == 0) return 0; if (o->n >= 32) return 0; for (i = 0; i < o->n; i++) if (o->a[i] == v) return 0; o->a[o->n++] = v; return 1; }
