/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

// MATCH func_00216480
void FUN_00216480(char *o) { int n = *(int *)(o + 0x18); int t; float x, y, a, b, c, d, ft, fn; if (n != 0) { t = *(int *)(o + 0x1c) + 1; *(int *)(o + 0x1c) = t; if (n < t) *(int *)(o + 0x1c) = n; if (*(int *)(o + 0x1c) == *(int *)(o + 0x18)) { x = *(float *)(o + 0x30); y = *(float *)(o + 0x34); } else { ft = (float)*(int *)(o + 0x1c); fn = (float)*(int *)(o + 0x18); x = ((*(float *)(o + 0x30) - *(float *)(o + 0x28)) * ft) / fn + *(float *)(o + 0x28); y = ((*(float *)(o + 0x34) - *(float *)(o + 0x2c)) * ft) / fn + *(float *)(o + 0x2c); } *(float *)(o + 0x24) = y; *(float *)(o + 0x20) = x; } }
