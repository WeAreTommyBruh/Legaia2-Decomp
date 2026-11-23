/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns -fno-schedule-insns2
#include "../common.h"

typedef struct { char p[12]; int a; int b; char q[236]; } E_1af130_001AF130;
typedef struct { char p[68]; int a; int b; int n; char q[280]; E_1af130_001AF130 *e; } O_1af130_001AF130;
// MATCH func_001AF130
int nayuwin2_001af130(O_1af130_001AF130 *o, int a, int b) { int i; E_1af130_001AF130 *e; if (a < 0 || b < 0) { a = o->a; b = o->b; } i = 0; if (i < o->n) { e = o->e; do { if (e->a == a && e->b == b) return i; i++; e++; } while (i < o->n); } return -1; }


