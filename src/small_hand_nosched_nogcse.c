/* Small functions matched by hand. */
// cflags: -fno-schedule-insns -fno-gcse
#include "common.h"

void func_00245F98(void *, int); void func_00108B80(void *);
// MATCH func_00111C00
void FUN_00111c00(char *s, int fl) { char *arr = s + 1056; if (arr != 0) { char *p = s + 111648; if (arr != p) { char *e = arr; do { p -= 432; func_00245F98(p, 0); } while (e != p); } } if (fl & 1) func_00108B80(s); }

void func_00156570(int); void func_00156CF8(int, float, int, int, int);
// MATCH func_0015A9C8
void FUN_0015a9c8(int **o, int a, int b, int c, float x) { if (o[0][10]) func_00156570(o[0][10]); if (o[0][11]) func_00156CF8(o[0][11], x, a, b, c); }
