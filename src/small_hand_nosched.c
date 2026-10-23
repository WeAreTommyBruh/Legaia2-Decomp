/* Small functions matched by hand. */
// cflags: -fno-schedule-insns
#include "common.h"

typedef struct { char pad[32]; int a[4]; } O_0015EBE8;
// MATCH func_0015EBE8
void flare_0015ebe8(O_0015EBE8 *o, int a, int b, int c) { int *q; o->a[0] = a; q = o->a; q[3] = 128; q[1] = b; q[2] = c; }

typedef struct { char p[68]; float f; char p2[8]; int n; } O_001E2588;
// MATCH func_001E2588
int akari_001e2588(O_001E2588 *o) { return (int)o->f >= o->n; }

// MATCH func_0022D080
float FUN_0022d080(float a, float b, float c) { return __builtin_fabsf(a - b) / __builtin_fabsf(b - c); }
