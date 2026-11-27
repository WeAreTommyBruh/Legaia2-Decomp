#include "../common.h"
extern int D_0603D140[4], D_0603D144[4], D_0603D148[4];
extern char D_004A5540[];
extern int (*D_004A1478)(int);
void func_00239568(char *, int, int, int);
int yokota_0023f1c8(int, int);
int func_0023B7C0(int, int, int, int, int, int);
// MATCH func_0023F2D0
int yokota_0023f2d0(void)
{
  int r;
  int (*fn)(int);
  func_00239568(D_004A5540, D_0603D140[0], D_0603D144[0] + 8, D_0603D148[0]);
  r = yokota_0023f1c8(D_0603D140[0] + 0x20, D_0603D144[0] + 0x20);
  if (r == 2) { D_004A1478(8); return 1; }
  if (r == 3) { D_004A1478(4); return 1; }
  func_0023B7C0(0, D_0603D140[0], D_0603D144[0], 0x80, 0x30, 0x808080);
  return 0;
}
