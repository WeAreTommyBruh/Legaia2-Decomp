#include "../src/common.h"

typedef struct { char pad[16]; u64 *cur; } Gp;
extern Gp D_00342CD0;
void FUN_00190328(Gp *);
void FUN_00190420(Gp *);
// WIP func_23E518
void yokota_0023e518(float x, float y, long unused, long a, long b)
{
  int ix, iy;
  u64 *p;
  u64 *q;
  ix = 0x8000 - (int)(x * 5120.0f);
  iy = 0x8000 - (int)(y * 1792.0f);
  FUN_00190328(&D_00342CD0);
  p = D_00342CD0.cur;
  p[6] = (a << 24) | 0x3f80000000000000;
  p[8] = (long)ix | ((long)iy << 16) | (b << 32);
  p[10] = (long)(ix + (int)(x * 5120.0f) * 2) | ((long)(iy + (int)(y * 1792.0f) * 2) << 16) | (b << 32);
  q = p + 2;
  D_00342CD0.cur = p + 14;
  *q = 0x31001;
  p[3] = 0x47;
  p[4] = 6;
  p[7] = 1;
  p[11] = 4;
  p[13] = 0x3f;
  p[0] = 0;
  p[1] = 0x3f;
  p[5] = 0;
  p[9] = 4;
  p[12] = 0;
  FUN_00190420(&D_00342CD0);
}
