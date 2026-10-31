/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern char D_0042F2A0[];
int func_00162130_00113928(int, void *, int) __asm__("func_00162130"); void func_002DC804_00113928(int, int, int) __asm__("func_002DC804");
// MATCH func_00113928
int movieplay_00113928(int a) { int r = func_00162130_00113928(a, D_0042F2A0, 187); func_002DC804_00113928(r, 0, a); return r; }
