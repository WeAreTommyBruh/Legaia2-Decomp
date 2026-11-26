#include "../common.h"
// compiler: 990721-r5900
extern int D_004A69A8;
extern int D_005F9830[];
extern char D_005F9640[];
char *clas_min_0029c6f8(int);
// MATCH func_0029C878
int clas_min_0029c878(int a, int b) { char *p; if (a != 0) return a; if (b != 0 && !(D_005F9830[0] & 0x80000)) return 0; p = D_005F9640; for (a = 0; a < D_004A69A8; a++) { if (clas_min_0029c6f8(-1) == p) break; p += 608; } return a; }
