// cflags: -fno-gcse -fno-schedule-insns
#include "../common.h"
extern float D_004A0D1C; extern char D_0049A700[];
int *func_00162130(int, char *, int);
// MATCH func_0029C980
void clas_min_0029c980(int *o, int b, int c, float x0, float y0, float z0) {
  int *n; int nx; register float x __asm__("$f22") = x0; register float y __asm__("$f20") = y0; register float z __asm__("$f21") = z0;
  nx = o[7];
  while (nx != 0) { o = *(int * volatile *)(o + 7); nx = o[7]; }
  if (x == D_004A0D1C) x = *(float *)o;
  if (y == D_004A0D1C) y = *(float *)(o + 1);
  if (z == D_004A0D1C) z = *(float *)(o + 2);
  n = func_00162130(32, D_0049A700, 780);
  n[7] = 0; __asm__("");
  { register float one __asm__("$f0"); one = 1.0f; __asm__("");
  o[7] = (int)n;
  *(float *)n = x;
  *(float *)(n + 1) = y;
  *(float *)(n + 2) = z;
  n[5] = c;
  n[6] = b;
  *(float *)(n + 3) = one;
  n[4] = 0; }
}
