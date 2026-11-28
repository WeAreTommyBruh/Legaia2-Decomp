// compiler: 991111-01-as210
#include "../common.h"
extern char D_00321640[];
void func_001910D0(void *, void *, unsigned, unsigned, unsigned); int func_00190C78(int, int, int, int, unsigned, int, unsigned, int); void func_00191170(void *, int);
// MATCH func_00190BA0
int FUN_00190ba0(int a0, int *a1, unsigned a2) {
  int v[4]; int r; unsigned s, end, pos; int cap, n;
  cap = a1[3] - 4; pos = a1[2] + 4;
  s = *(int *)(a2 + 0x50008); end = a2 + s;
  if (end <= pos) pos = pos - s;
  n = end - pos;
  if (cap <= n) n = cap;
  { int c2 = cap - n; cap = c2; }
  func_001910D0(D_00321640, v, (unsigned)v | 4, (unsigned)v | 8, (unsigned)v | 0xc);
  { int x0 = v[0], x1 = v[1], x2 = v[2], x3 = v[3]; r = func_00190C78(x0, x1, x2, x3, pos, n, a2, cap); }
  func_00191170(D_00321640, r);
  return 0 < r;
}
