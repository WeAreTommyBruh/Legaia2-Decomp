/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns -fno-schedule-insns2
#include "../common.h"

typedef struct { int a0, a4, a8, a12, a16, a20; } N_2da070_002DA070;
extern N_2da070_002DA070 *D_00631AF8[];
// MATCH func_002DA070
void FUN_002da070(int a, N_2da070_002DA070 *s) { N_2da070_002DA070 *h = D_00631AF8[0]; s->a12 = a; s->a20 = (int)h; D_00631AF8[0] = s; s->a8 = a; s->a4 = 0; s->a0 = 0; s->a16 = 0; }

// MATCH func_002E2628
int FUN_002e2628(void *r, unsigned *pwc, const char *s, unsigned n) { unsigned dummy; unsigned char *t = (unsigned char *)s; if (pwc == 0) pwc = &dummy; if (s != 0 && n == 0) return -1; if (s == 0) return 0; *pwc = (unsigned)*t; return *t != 0; }
