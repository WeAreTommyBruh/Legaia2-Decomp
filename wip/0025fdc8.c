// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../src/common.h"

extern char D_00489110[];
int DbgPrintf(char *, ...);
// WIP func_25FDC8
int abeshi_0025fdc8(int *o){ int a = o[2], b = o[3], c = o[0]; if (c != a + b) DbgPrintf(D_00489110); return o[3]; }
