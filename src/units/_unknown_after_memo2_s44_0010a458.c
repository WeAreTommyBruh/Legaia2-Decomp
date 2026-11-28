// compiler: 990721-r5900
#include "../common.h"
typedef struct { char p[72]; int w72, w76; char q[280-80]; signed char b280; } G_10A458;
extern int D_00343028[]; extern G_10A458 D_00343660; extern int D_004A118C, D_004A12B0; extern char D_0042CE78[], D_0042CEA0[];
void func_001118F8(char *, ...); void func_002D41A8(int, int, int);
// MATCH func_0010A458
int FUN_0010a458(int a, int b, int c, int d) { int x, y, l, r, k; if (D_00343028[0] & 8) return -1; if (D_00343028[0] & 0x10) return -1; if (D_004A118C & 0x40) func_001118F8(D_0042CE78, D_004A12B0); if (D_004A118C & 4) func_001118F8(D_0042CEA0, c, d); k = D_00343660.b280 * 0x3fff; y = c * k / 0x319c; l = y < 0x4000 ? y : 0x3fff; x = d * k / 0x319c; r = x < 0x4000 ? x : 0x3fff; func_002D41A8(0, l, r); func_002D41A8(1, l, r); D_00343660.w72 = c; D_00343660.w76 = d; return 1; }
