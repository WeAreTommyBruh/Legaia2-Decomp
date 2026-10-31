/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns -fno-schedule-insns2
#include "../common.h"

extern int D_004A1A3C;
// MATCH func_00127430
int battle_00127430(void) { int *new_var; int r = 0; if (D_004A1A3C != 0) { r = 1; } if (D_004A1A3C) { new_var = &r; return *new_var; } else { return r; } }

