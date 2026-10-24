#include "../src/common.h"
extern float D_00319760[]; void func_0018EC58(float *);
// 9 words differ
// WIP func_00249BF0
void FUN_00249bf0(float *m, int ang) { float s = D_00319760[ang & 0xfff]; float c = D_00319760[(ang & 0xfff) + 1024]; func_0018EC58(m); m[0] = c; m[1] = s; m[4] = -s; m[5] = c; }
