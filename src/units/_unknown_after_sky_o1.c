/* Functions of this report unit, matched by hand. */
// cflags: -O1
#include "../common.h"

// MATCH func_001577C0
void FUN_001577c0(float *a, float *b) { for (;;) { int n; if (b[74] <= a[74]) { n = ((int *)a)[75]; if (n == 0) { ((int *)a)[75] = (int)b; return; } } else { n = ((int *)a)[76]; if (n == 0) { ((int *)a)[76] = (int)b; return; } } a = (float *)n; } }
