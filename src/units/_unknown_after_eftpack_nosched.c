/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns
#include "../common.h"

// MATCH func_00203520
void FUN_00203520(float *v) { float z = 0.0f; __asm__("" : "+f"(z)); v[0] = z; v[3] = 1.0f; v[2] = z; v[1] = z; }
