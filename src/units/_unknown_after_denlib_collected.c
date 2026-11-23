/* Matched functions from this unit. */
#include "../common.h"

float func_0018ECB8(int, int); void func_0018EFA0(int, int, int, float); void func_0018EED8(int, float);
// MATCH func_0018FCC0
void FUN_0018fcc0(int a, int b, int c, float f, float g) {
  float r, s;
  r = func_0018ECB8(a, b);
  s = f * f - (1.0f - r * r);
  if (s < 0.0f) s = 0.0f;
  func_0018EFA0(c, a, b, __builtin_sqrtf(s) - r);
  func_0018EED8(c, g / f);
}
