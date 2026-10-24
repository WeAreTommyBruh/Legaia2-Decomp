// cflags: -fno-schedule-insns
#include "../src/common.h"
extern int D_00314D08[]; extern char *D_004A1A20;
// 9 words differ
// WIP func_00278648
int FUN_00278648(int a, int b) { int i = 0; int *p = D_00314D08; char *e = D_004A1A20 + 4836; do { if (*p == a) { if (*(int *)e == b) return 1; return 0; } i++; p++; e += 5472; } while (i < 3); return -1; }
