#include "../src/common.h"
extern float D_00319760[]; void func_0018EC58(float *);
// 9 words differ
// WIP func_00249B80
void FUN_00249b80(float *m, int ang) { float s = D_00319760[ang & 0xfff]; float c = D_00319760[(ang & 0xfff) + 1024]; func_0018EC58(m); m[0] = c; m[2] = -s; m[8] = s; m[10] = c; }
