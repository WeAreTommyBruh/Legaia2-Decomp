#include "../common.h"
extern unsigned char *D_004A1B18;
// MATCH func_00130AD8
int FUN_00130ad8(int key) { unsigned char *base = D_004A1B18; unsigned char *lo = base, *hi = base + 752, *mid; int v; while (lo != hi) { mid = lo + (((hi - lo) >> 1) & ~1); v = mid[0] * 256 + mid[1]; if (key < v) hi = mid; else if (v < key) lo = mid + 2; else break; } if (lo != hi) return (mid - base) >> 1; return 0; }
