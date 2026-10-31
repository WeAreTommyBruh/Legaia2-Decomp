/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

extern int D_004A3838; extern int D_004A383C; extern char D_004A380A_001E3F88 __asm__("D_004A380A"); extern int D_004A3864_001E3F88 __asm__("D_004A3864"); extern char D_0044B998[]; extern char D_0044B9C0[];
int func_001118F8(char *, ...); int func_001E24A8(int, int); int func_001E2498(int, int); int func_001E2488(int, int);
// MATCH func_001E3F88
void FUN_001e3f88(int a, int b) { int *cur; int *next; int *q; int n; int i; if (D_004A3838 == 0) return; if (D_004A380A_001E3F88 == 0) return; if (D_004A3864_001E3F88 & 0x80) func_001118F8(D_0044B998); if (D_004A383C == 0) return; next = (int *)D_004A3838; q = next; cur = q; while (cur != 0) { next = (int *)next[1]; if (cur[208] == b) { if (D_004A3864_001E3F88 & 0x80) func_001118F8(D_0044B9C0, cur); n = cur[75]; if (n > 0) { q = cur + 76; i = n; do { if (q[64] != 0) { func_001E24A8(q[0], 0); func_001E2498(q[0], 0); func_001E2488(q[0], 0); } i--; q++; } while (i != 0); } } if (cur == (int *)D_004A383C) return; cur = next; } }
