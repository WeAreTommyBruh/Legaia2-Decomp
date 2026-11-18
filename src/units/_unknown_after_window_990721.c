/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
#include "../common.h"

typedef struct { char p0[12]; int n; char p16[12]; int a, b, c; } S_196FF8;
extern S_196FF8 D_00343028[]; extern int D_004A3850, D_004A11F0, D_004A3800, D_004A3864; extern char D_004419B0[], D_004419E8[];
int func_0010FDD8(void); int func_002CBB80(int); int func_002CC9A0(void); int func_002CCAF0(void); void func_001118F8(char *, ...); void func_00196AF8(int, int, int, int);
// MATCH func_00196FF8
int FUN_00196ff8(void) {
  int r;
  if (D_004A3850 == 0) return func_0010FDD8();
  r = func_002CBB80(1);
  if (r == 0) {
    D_004A11F0 = 0;
    if (D_004A3800 != 0) {
      if (func_002CC9A0() != 0) {
        if (D_004A3864 & 2) func_001118F8(D_004419B0, D_00343028[0].a, D_00343028[0].c, D_00343028[0].b);
        if (D_00343028[0].n < 2) {
          while (func_002CCAF0() == 0);
          func_002CBB80(0);
          func_00196AF8(D_00343028[0].a, D_00343028[0].b, D_00343028[0].c, D_00343028[0].n);
          return 1;
        }
      }
      if (D_004A3864 & 2) func_001118F8(D_004419E8);
      D_004A3800 = 0;
    }
  }
  return r;
}
