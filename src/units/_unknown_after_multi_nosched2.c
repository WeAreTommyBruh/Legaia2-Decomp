/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns2
#include "../common.h"

extern long long D_004A1300; extern int D_004A6CB8, D_004A1A98; extern int D_00326ED0[]; extern char D_00321060[], D_0042FA20[]; int func_002DCE40(char *, char *, ...); void func_00127480(char *, int);
// MATCH func_00116D00
int FUN_00116d00(int a) { if (a != 0 && (D_004A1300 & 0x200040)) { func_002DCE40(D_00321060, D_0042FA20, D_00326ED0[D_004A6CB8]); func_00127480(D_00321060, 60); D_004A1A98 = 1; } return 0; }

