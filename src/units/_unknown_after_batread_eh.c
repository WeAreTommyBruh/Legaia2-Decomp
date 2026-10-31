/* Functions of this report unit, matched by hand. */
// cflags: -fexceptions
#include "../common.h"

void func_002207E8(float);
// MATCH func_002207C0
void FUN_002207c0(void) { func_002207E8(1.0f); }

void func_00220820(int, int, int, int, float);
// MATCH func_002207E8
void FUN_002207e8(int a, int b, int c) { func_00220820(0, a, b, c, 1.0f); }
