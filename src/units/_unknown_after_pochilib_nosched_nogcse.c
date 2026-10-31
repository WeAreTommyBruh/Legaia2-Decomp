/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns -fno-gcse
#include "../common.h"

extern char D_0043C238[], D_0043C270[];
unsigned long long func_001118F8(char *, ...);
// MATCH func_001617B0
int FUN_001617b0(int *a) { int *b; int sum, i, v; b = a - 32; sum = 0; a = a - 30; i = 28; do { sum += *a; i--; a++; } while (i >= 0); if (b[31] != sum) { func_001118F8(D_0043C238, b[3], b[31], sum, b[2]); b = b + 5; for (i = 0; i < 26; i++) { v = *b; if (v != i) func_001118F8(D_0043C270, i, v); b++; } return 1; } return 0; }

