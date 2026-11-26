// compiler: 990721-r5900
#include "../common.h"
extern int D_004022E8[];
int func_0025D858(int, int);
// MATCH func_0025D920
int *FUN_0025d920(int a) { int i, n, m = -1; for (i = 63; i >= 0; i--) D_004022E8[i + 1] = m; if ((unsigned)a >= 5) { D_004022E8[0] = -1; return D_004022E8; } n = 0; for (i = 0; i < 64; i++) if (func_0025D858(a, i) != 0) D_004022E8[1 + n++] = i; D_004022E8[0] = n; return D_004022E8; }
