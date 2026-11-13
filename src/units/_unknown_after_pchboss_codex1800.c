/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern volatile float D_004A04A8_00219240 __asm__("D_004A04A8"), D_004A04AC_00219240 __asm__("D_004A04AC"), D_004A04B0_00219240 __asm__("D_004A04B0"); float func_002D5738_00219240(float, float) __asm__("func_002D5738");
// MATCH func_00219240
float FUN_00219240(float a, float b) {
  float k, r1, r2, d, r, ab;
  ab = __builtin_fabsf(b); k = (6.2831854820251465f); r1 = func_002D5738_00219240(ab, k);
  if (b < 0.0f) r1 = k - r1;
  r2 = func_002D5738_00219240(__builtin_fabsf(a), k);
  if (a < 0.0f) r2 = k - r2;
  d = r2 - r1;
  if (d < 0.0f) d = d + k;
  if ((3.1415927410125732f) < d) r = k - d; else { r = (-3.1415927410125732f); if (d < r) r = d + k; }
  return r;
}
