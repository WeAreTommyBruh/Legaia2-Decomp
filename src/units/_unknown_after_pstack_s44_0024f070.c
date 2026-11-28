// compiler: 990721-r5900
#include "../common.h"
extern char D_003FDFA0[];
extern int D_005F7930[];
// MATCH func_0024F070
int *FUN_0024f070(int id) { int i; int n; int k = 72; char *w = D_003FDFA0 + id * k; for (i = 255; i >= 0; i--) D_005F7930[i] = 0; n = 0; for (i = 1; i < 256; i++) if (*(int *)(w + ((i >> 5) << 2)) >> (i & 31) & 1) D_005F7930[n++] = i; return D_005F7930; }