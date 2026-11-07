/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { int a0, a4, a8, a12, a16, a20, a24; int a28; int a32; } T36_002185a8_002185A8;
extern T36_002185a8_002185A8 D_003C4D00_2185A8[] __asm__("D_003C4D00"); void func_00216D28_2185A8(void) __asm__("func_00216D28"); void func_00229390_2185A8(char *, int, int) __asm__("func_00229390");
// MATCH func_002185A8
void FUN_002185a8(char *o) { int k; int u1, u2, u3, u4, u5, u6, u7; T36_002185a8_002185A8 *e; func_00216D28_2185A8(); k = -1; if (*(int *)(o + 1780) == 0xe) k = 0; if (*(int *)(o + 1780) == 0xd) k = 1; if (*(int *)(o + 1780) == 0xc) k = 2; if (*(int *)(o + 1780) == 0xb) k = 3; if (k >= 0) { e = &D_003C4D00_2185A8[k]; u1 = e->a0; u2 = e->a4; *(int *)(o + 60) = u1; *(int *)(o + 64) = u2; u3 = e->a24; u4 = e->a8; *(int *)(o + 2064) = u3; *(int *)(o + 68) = u4; u5 = e->a12; *(int *)(o + 2076) = u5; u6 = e->a16; *(int *)(o + 2080) = u6; u7 = e->a20; *(int *)(o + 2084) = u7; if (e->a28 != 0) func_00229390_2185A8(o, e->a28, e->a32); } }

