/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct { char p[76]; int n; char p2[280]; char *q; } O_001AE438;
// MATCH func_001AE438
void nayuwin2_001ae438(O_001AE438 *o) { int i; for (i = 0; i < o->n; i++) { o->q[i * 256 + 254] = 0; *(int *)(o->q + i * 256 + 40) = -1; } }
