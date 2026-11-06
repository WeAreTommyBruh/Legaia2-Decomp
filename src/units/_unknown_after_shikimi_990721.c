/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
#include "../common.h"

int func_002EDC50_2CF088(void) __asm__("func_002EDC50");
void func_002EDC98_2CF088(unsigned, unsigned) __asm__("func_002EDC98");
inline volatile unsigned inline_fn_002CF088(volatile unsigned *arg0) { return *arg0; }
// MATCH func_002CF088
unsigned FUN_002cf088(unsigned *p) { int r; unsigned en; unsigned ctrl; unsigned v; unsigned nv; r = func_002EDC50_2CF088(); en = *((volatile unsigned *) 0x1000f520); if ((en & 0x10000) == 0) { *((volatile unsigned *) 0x1000f590) = en | 0x10000; } ctrl = inline_fn_002CF088((volatile unsigned *) 0x1000e000); v = inline_fn_002CF088(p); nv = v & 0xfffffeff; *p = nv; *((volatile unsigned *) 0x1000f590) = en; if (0 != r) { func_002EDC98_2CF088(nv, ctrl); } return v; }

