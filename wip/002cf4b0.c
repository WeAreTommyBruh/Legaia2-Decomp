#include "../src/common.h"
typedef struct { int *w0; int w4; int w8; int w12; } Pk;
int func_002CF458(Pk *);
// 2 words differ
// WIP func_002CF4B0
void FUN_002cf4b0(Pk *o, int x) { int r = func_002CF458(o); int *p = o->w0; o->w8 = r; *p++ = x | 0x10000000; o->w12 = 0; o->w0 = p + 1; *p = 0; }
