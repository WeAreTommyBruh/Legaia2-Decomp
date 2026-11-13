/* Functions of this report unit, matched by hand. */
// cflags: -O1 -fexceptions
#include "../common.h"

void func_00215AA8_00215AC8() __asm__("func_00215AA8"); void func_00215A90_00215AC8(void) __asm__("func_00215A90");
// MATCH func_00215AC8
void FUN_00215ac8(int *p) { { register int val __asm__("$2") = 2;  if (p[8] == val) func_00215AA8_00215AC8(); else func_00215A90_00215AC8(); } }
