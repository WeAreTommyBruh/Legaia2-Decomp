/* Small functions matched by hand. */
// cflags: -fno-schedule-insns -fno-schedule-insns2
#include "common.h"

typedef struct { int a0, a4, a8, a12, a16, a20; } N_2da070_002DA070;
extern N_2da070_002DA070 *D_00631AF8[];
// MATCH func_002DA070
void FUN_002da070(int a, N_2da070_002DA070 *s) { N_2da070_002DA070 *h = D_00631AF8[0]; s->a12 = a; s->a20 = (int)h; D_00631AF8[0] = s; s->a8 = a; s->a4 = 0; s->a0 = 0; s->a16 = 0; }
