/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p[144]; void *w144; } O_001E0218;
extern char D_0044B4A0[]; void *func_001334D0(int, char *, int); void func_00133528_001E0218(void *, char *, int) __asm__("func_00133528");
// MATCH func_001E0218
int mizuki_001e0218(O_001E0218 *o, int n) { void *p; if (n <= 0) return 0; p = func_001334D0(n, D_0044B4A0, 320); if (p == 0) return -1; if (o->w144 != 0) func_00133528_001E0218(o->w144, D_0044B4A0, 322); o->w144 = p; return 1; }
