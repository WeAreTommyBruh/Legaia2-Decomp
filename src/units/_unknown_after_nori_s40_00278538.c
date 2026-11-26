#include "../common.h"
typedef struct { int id; int v; int w8, w12, w16; char p[112]; } E132; extern E132 D_0040F398[][32];
// MATCH func_00278538
int FUN_00278538(unsigned a) { int n; if (a >= 5) return -1; n = 0; while (D_0040F398[a][n].w16 != 0) n++; return n; }
