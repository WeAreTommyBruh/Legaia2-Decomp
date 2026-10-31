/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns -fno-gcse
#include "../common.h"

void func_00156570(int); void func_00156CF8(int, float, int, int, int);
// MATCH func_0015A9C8
void FUN_0015a9c8(int **o, int a, int b, int c, float x) { if (o[0][10]) func_00156570(o[0][10]); if (o[0][11]) func_00156CF8(o[0][11], x, a, b, c); }
