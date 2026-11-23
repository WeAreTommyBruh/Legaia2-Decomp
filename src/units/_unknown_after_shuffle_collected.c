/* Matched functions from this unit. */
#include "../common.h"

extern float D_00336760[]; extern struct { char p[16]; long *q; } D_00342CD0;
void func_00190328(void *); void func_00190420(void *);
// MATCH func_00179F00
void FUN_00179f00(float a, float b, float c, float d, int e, long f, long g) {
  long *p;
  D_00336760[2] = ((b - a) * (d + c) / (d - c) + (b + a)) * 0.5f;
  D_00336760[3] = d * c * (b - a) / (d - c);
  D_00336760[0] = b; D_00336760[1] = a;
  func_00190328(&D_00342CD0);
  p = D_00342CD0.q; p[0] = (f << 8 | e) | g << 16; D_00342CD0.q = p + 2; p[1] = 0x3d;
  func_00190420(&D_00342CD0);
}
