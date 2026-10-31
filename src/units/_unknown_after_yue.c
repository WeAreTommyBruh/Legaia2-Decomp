/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_003B7048[], D_0036CAB0_001F1DA0[] __asm__("D_0036CAB0"), D_003B6DB8[];
int func_001AD548(void *, void *, void *);
// MATCH func_001F1DA0
int FUN_001f1da0(void) { int r, i; int *q; char *a, *b; int st[4]; b = (char *)D_003B7048; q = D_0036CAB0_001F1DA0; i = 3; a = (char *)D_003B6DB8; do { r = func_001AD548(a, b, st); *q = r; q = q + 1; b = b + st[0] * 0xe8; a = a + 0xa4; i = i - 1; } while (-1 < i); return D_0036CAB0_001F1DA0[0]; }
