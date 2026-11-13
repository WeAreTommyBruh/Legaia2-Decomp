/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern volatile int D_005F75A0_00245BD0[] __asm__("D_005F75A0");
int func_002E6900_00245BD0(int, volatile int *, void *) __asm__("func_002E6900"); void func_00245AC8_00245BD0(void) __asm__("func_00245AC8");
// MATCH func_00245BD0
int FUN_00245bd0(void) { D_005F75A0_00245BD0[0] = func_002E6900_00245BD0(0xe000, D_005F75A0_00245BD0, (void *)func_00245AC8_00245BD0); {register long x __asm__("$2");register long neg __asm__("$3")=-1;x=D_005F75A0_00245BD0[0];__asm__ ("" : "+r"(x));return neg<x;} }
