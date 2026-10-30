/* Small functions matched by hand. */
// cflags: -fno-schedule-insns -fno-gcse
#include "common.h"

void func_00245F98(void *, int); void func_00108B80(void *);
// MATCH func_00111C00
void FUN_00111c00(char *s, int fl) { char *arr = s + 1056; if (arr != 0) { char *p = s + 111648; if (arr != p) { char *e = arr; do { p -= 432; func_00245F98(p, 0); } while (e != p); } } if (fl & 1) func_00108B80(s); }

void func_00156570(int); void func_00156CF8(int, float, int, int, int);
// MATCH func_0015A9C8
void FUN_0015a9c8(int **o, int a, int b, int c, float x) { if (o[0][10]) func_00156570(o[0][10]); if (o[0][11]) func_00156CF8(o[0][11], x, a, b, c); }

extern char D_0043C238[], D_0043C270[];
unsigned long long func_001118F8(char *, ...);
// MATCH func_001617B0
int FUN_001617b0(int *a) { int *b; int sum, i, v; b = a - 32; sum = 0; a = a - 30; i = 28; do { sum += *a; i--; a++; } while (i >= 0); if (b[31] != sum) { func_001118F8(D_0043C238, b[3], b[31], sum, b[2]); b = b + 5; for (i = 0; i < 26; i++) { v = *b; if (v != i) func_001118F8(D_0043C270, i, v); b++; } return 1; } return 0; }
