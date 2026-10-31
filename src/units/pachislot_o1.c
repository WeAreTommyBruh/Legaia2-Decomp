/* Functions of this report unit, matched by hand. */
// cflags: -O1
#include "../common.h"

typedef struct { char p[4]; int w4; } O_00166F90;
// MATCH func_00166F90
int pachislot_00166f90(O_00166F90 *o, int k) { if (o->w4 == 0) { if (k == 1) return 0; if (k == 2) return 0; } if (o->w4 == 1) { if (k == 3) return 1; } return -1; }
