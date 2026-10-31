/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns
#include "../common.h"

typedef struct { char pad[32]; int a[4]; } O_0015EBE8;
// MATCH func_0015EBE8
void flare_0015ebe8(O_0015EBE8 *o, int a, int b, int c) { int *q; o->a[0] = a; q = o->a; q[3] = 128; q[1] = b; q[2] = c; }
