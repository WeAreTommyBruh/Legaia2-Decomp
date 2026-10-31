/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_00318C20[]; extern int D_004A126C, D_004A1268; int func_0017FDB0(int, int, int, int);
// MATCH func_0017FFD0
int modelpkt_0017ffd0(int a, int b, int c, int d) { int n; D_00318C20[D_004A126C] = a; func_0017FDB0(a, b, c, d); D_004A1268 = n = D_004A126C; D_004A126C = ++n; return n - 1; }
