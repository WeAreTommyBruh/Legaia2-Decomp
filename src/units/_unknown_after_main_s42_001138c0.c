#include "../common.h"
extern int D_004A12A4; extern char D_00343667[];
typedef struct { int p[8]; int x[2]; int y[2]; } OO;
static inline int max0(int a) { return a > -1 ? a : 0; }
static inline int min255(int a) { return a < 256 ? a : 255; }
// MATCH func_001138C0
void FUN_001138c0(OO *o, int i, int x, int y) { int m1 = -1; if (!(m1 < x)) x = 0; if (!(m1 < y)) y = 0; if (x >= 256) x = 255; if (y >= 256) y = 255; if (D_004A12A4 == 11 && D_00343667[0] == 0) { x = 0; y = 0; } o->x[i] = x; o->y[i] = y; }
