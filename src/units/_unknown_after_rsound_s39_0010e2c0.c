// cflags: -fno-schedule-insns -fexceptions
#include "../common.h"
extern int D_00343028[]; extern volatile int D_004A118C; extern char *D_004A12B0; extern signed char D_00343660[]; extern char D_0042E468[];
void func_001118F8(char *, ...); void func_002D5120(int, int, int);
// MATCH func_0010E2C0
void FUN_0010e2c0(int a, int b) { if (!(D_00343028[0] & 8)) { if (D_004A118C & 0x40) func_001118F8(D_0042E468, D_004A12B0); { register int k __asm__("$4"); k = 1; __asm__("" : "+r"(k)); if (D_00343660[0] == k)
 { b >>= 1; func_002D5120(1, b, b); func_002D5120(2, b, b); } else { func_002D5120(1, b, 0); { register int r6 __asm__("$6") = b; register int r4 __asm__("$4") = 2; register int r5 __asm__("$5") = 0; func_002D5120(r4, r5, r6); } } } } }
