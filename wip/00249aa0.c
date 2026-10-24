#include "../src/common.h"
float func_0015FB58(int, float); void func_0018EC58(float *);
// 4 words differ
// WIP func_00249AA0
void FUN_00249aa0(float *m, float ang) { float c = func_0015FB58(1, ang); float s = func_0015FB58(0, ang); func_0018EC58(m); m[0] = c; m[1] = s; m[4] = -s; m[5] = c; }
