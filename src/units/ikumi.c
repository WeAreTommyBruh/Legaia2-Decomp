/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern char *D_0036CE50[];
// MATCH func_0019B6C0
int EfbCommandAllowed(int a, int b, int c) { char *p = D_0036CE50[c]; return p[b - 1] == 0x31 ? 1 : -1; }
