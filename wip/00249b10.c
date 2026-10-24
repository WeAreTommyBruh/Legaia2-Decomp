#include "../src/common.h"
extern float D_00319760[]; void func_0018EC58(float *);
// WIP func_00249B10
void FUN_00249b10(float *m, int ang) { int i = ang & 0xfff; float s = D_00319760[i]; float c = D_00319760[i + 1024]; func_0018EC58(m); m[10] = m[5] = c; m[6] = s; m[9] = -s; }
