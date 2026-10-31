/* Functions of this report unit, matched by hand. */
// cflags: -O1
#include "../common.h"

typedef struct { char p[36]; int v; } O_00219838;
// MATCH func_00219838
int FUN_00219838(O_00219838 *o) { int v = o->v; if (v == 10) return 0; if (v == 30) return 0; if (v != 0) return 1; return 0; }
