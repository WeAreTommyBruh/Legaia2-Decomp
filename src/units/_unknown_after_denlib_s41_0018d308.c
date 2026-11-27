#include "../common.h"
extern char D_004A3690[], D_004406C0[];
void func_001118F8(char *, ...);
// MATCH func_0018D308
void FUN_0018d308(char *s, volatile float *m) {
  if (s != 0) func_001118F8(D_004A3690, s);
  if (m == 0) return;
  func_001118F8(D_004406C0, (double)m[0], (double)m[1], (double)m[2], (double)m[3]);
  func_001118F8(D_004406C0, (double)m[4], (double)m[5], (double)m[6], (double)m[7]);
  func_001118F8(D_004406C0, (double)m[8], (double)m[9], (double)m[10], (double)m[11]);
  func_001118F8(D_004406C0, (double)m[12], (double)m[13], (double)m[14], (double)m[15]);
}
