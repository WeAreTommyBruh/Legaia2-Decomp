/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns
#include "../common.h"

typedef struct { char p[68]; float f; char p2[8]; int n; } O_001E2588;
// MATCH func_001E2588
int akari_001e2588(O_001E2588 *o) { return (int)o->f >= o->n; }
