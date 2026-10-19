#include "../src/common.h"
extern int D_0603D140[4], D_0603D144[4], D_0603D148[4];
extern char D_004A5540[];
extern int (*D_004A1478)(int);
void FUN_00239568(char *, int, int, int);
int yokota_0023f1c8(int, int);
void FUN_0023b7c0(int, int, int, int, int, int);
// WIP func_23F2D0
int yokota_0023f2d0(void)
{
  int r;
  int (*fn)(int);
  FUN_00239568(D_004A5540, D_0603D140[0], D_0603D144[0] + 8, D_0603D148[0]);
  r = yokota_0023f1c8(D_0603D140[0] + 0x20, D_0603D144[0] + 0x20);
  if (r == 2) {
    D_004A1478(8);
  } else {
    if (r != 3) {
      FUN_0023b7c0(0, D_0603D140[0], D_0603D144[0], 0x80, 0x30, 0x808080);
      return 0;
    }
    D_004A1478(4);
  }
  return 1;
}
