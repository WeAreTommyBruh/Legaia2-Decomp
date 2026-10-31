/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

extern int D_00343028[]; extern int D_004A3850, D_004A118C; extern char *D_004A12B0; extern char D_0042D8A0[], D_0042D8C0[]; extern int D_002F95F0[], D_002F96B0[]; void func_001118F8_0010C4C0(char *, ...) __asm__("func_001118F8"); void func_002D4B20(int);
// MATCH func_0010C4C0
void rsound_0010c4c0(int a, unsigned i) { if (!(D_00343028[0] & 8) && D_004A3850 != 2 && i < 48) { if (D_004A118C & 0x40) func_001118F8_0010C4C0(D_0042D8A0, D_004A12B0); if (D_004A118C & 1) func_001118F8_0010C4C0(D_0042D8C0, i); func_002D4B20(i); D_002F95F0[i] = -1; D_002F96B0[i] = -1; } }
