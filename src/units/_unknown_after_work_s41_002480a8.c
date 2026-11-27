#include "../common.h"
typedef struct { char p[16]; unsigned long *q; } G;
extern G *D_004A1524; extern int D_004A1540;
// MATCH func_002480A8
void FUN_002480a8(float x, float y, int z) {
  int v[3]; unsigned long *q;
  v[1] = (int)y;
  v[0] = (int)x;
  v[2] = z + 0xffffff;
  q = D_004A1524->q;
  D_004A1524->q = q + 2;
  q[1] = 12;
  q[0] = (unsigned long)v[0] | (unsigned long)v[1] << 16 | (unsigned long)v[2] << 32;
  D_004A1540++;
}
