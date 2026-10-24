// cflags: -O1
#include "../src/common.h"
// 7 words differ
// WIP func_002D6168
int FUN_002d6168(float f) { unsigned u = *(unsigned *)&f; return (0x7f800000 - (u & 0x7fffffff)) >> 31; }
