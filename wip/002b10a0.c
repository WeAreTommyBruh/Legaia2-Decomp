#include "../src/common.h"
typedef struct { char p0[0x20]; signed char f20; char p21[3]; int f24, f28; char p2c[0xc]; int f38, f3c, f40, f44, f48, f4c, f50; char p54[12]; } Win;
extern Win D_00620320[16], D_00421430;
extern int D_004A72EC;
// WIP func_002B10A0
void shikimi_002b10a0(void)
{
  int i;
  D_004A72EC = 0;
  for (i = 0; i < 16; i++) {
    D_00620320[i] = D_00421430;
    D_00620320[i].f38 = 0;
    D_00620320[i].f3c = 0;
    D_00620320[i].f40 = 0;
    D_00620320[i].f44 = 0;
    D_00620320[i].f48 = 0;
    D_00620320[i].f4c = 0;
    D_00620320[i].f50 = 0;
  }
}
