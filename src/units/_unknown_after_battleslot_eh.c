/* Functions of this report unit, matched by hand. */
// cflags: -fexceptions
#include "../common.h"

extern int D_004A683C; extern char D_00342CD0[];
void func_00190328(char *); void func_00190420(char *);
// MATCH func_002975B8
void FUN_002975b8(void) { if (D_004A683C & 2) { unsigned long u; long *q; char *p = D_00342CD0; func_00190328(p); q = *(long **)(p + 16); q[0] = 68; q[1] = 66; q[2] = (u << 32) | 0x60000000; q[3] = 1; q[4] = 70; q[5] = 0; q[6] = 0x00FFFFF079006C00L; q[7] = 5; q[8] = 0x00FFFFF087009400L; q[9] = 5; *(long **)(p + 16) = q + 10; func_00190420(p); } }
