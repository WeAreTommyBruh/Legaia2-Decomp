#include "../src/common.h"
typedef struct { int *w0; int w4; int w8; int w12; } Pk;
int func_002CF158(Pk *);
// 2 words differ
// WIP func_002CF2C0
void FUN_002cf2c0(Pk *o, int b, int c, int d) { int r = func_002CF158(o); int *p = o->w0; o->w8 = r; *p++ = d | 0x70000000; o->w0 = p + 3; p[1] = b; p[2] = c; p[0] = 0; }
