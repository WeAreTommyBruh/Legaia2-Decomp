/* Functions of this report unit, matched by hand. */
// compiler: 991111
#include "../common.h"

// MATCH func_00191170
void FUN_00191170(int *p, int n) { int t, k; if (*p == 0) { t = 0x28 - p[0xb]; if (n < t) t = n; k = p[0xb] + t; p[0xb] = k; if (0x27 < k) *p = 1; n = n - t; } p[0xd] = (p[0xd] + n) % p[0xf]; p[0xe] = p[0xe] + n; p[0x10] = p[0x10] + n; }
