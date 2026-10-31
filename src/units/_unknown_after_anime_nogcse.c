/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

int func_0021D420(void *, int, int, int, int, int, int, int);
// MATCH func_0021D3C0
int FUN_0021d3c0(char *o, int b, int key, int d, int e, int f, int g) { int i; char *p; i = 0; if (*(int *)(o + 132) > 0) { p = o + 168; do { if (*(int *)p == key) return func_0021D420(o, b, key, d, e, f, i, g); i++; p += 44; } while (i < *(int *)(o + 132)); } return 0; }
