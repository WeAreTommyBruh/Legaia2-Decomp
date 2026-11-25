// cflags: -fno-gcse -fno-schedule-insns
#include "../common.h"
extern char D_0049A700[];
int *func_00162130(int, char *, int);
// MATCH func_0029D420
void clas_min_0029d420(int *o, float f0, float f1, float f2, float f3, float f4, float f5, int b, int c, int d) {
  int *n; int nx; register int B __asm__("$19") = b; register int C __asm__("$17") = c; register int D __asm__("$18") = d;
  nx = o[15];
  while (nx != 0) { o = *(int * volatile *)(o + 15); nx = o[15]; }
  n = func_00162130(64, D_0049A700, 1092);
  n[15] = 0;
  o[15] = (int)n;
  n[11] = B;
  *(float *)n = f0;
  *(float *)(n + 1) = f1;
  *(float *)(n + 2) = f2;
  *(float *)(n + 3) = f3;
  *(float *)(n + 4) = f4;
  *(float *)(n + 5) = f5;
  n[9] = C;
  n[10] = D;
}
