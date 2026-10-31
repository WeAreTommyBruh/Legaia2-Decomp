/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns
#include "../common.h"

// MATCH func_0022D080
float FUN_0022d080(float a, float b, float c) { return __builtin_fabsf(a - b) / __builtin_fabsf(b - c); }

// MATCH func_0022D420
void FUN_0022d420(float *d, float *s) { int i, j; for (i = 0; i < 4; i++) for (j = 0; j < 4; j++) d[i * 4 + j] = s[i * 4 + j]; }
