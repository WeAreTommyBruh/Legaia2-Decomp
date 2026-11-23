/* Matched functions from this unit. */
// compiler: 991111-01-as210
// cflags: -fno-gcse
#include "../common.h"

extern int D_004A565C, D_004A5658, D_004A14B8; extern char D_0045D778[], D_003DA170[], D_003DC570[];
int func_001118F8(char *, ...); void func_0018EB98(char *, int);
// MATCH func_00249108
void FUN_00249108(void) {
  int i;
  if (!(D_004A565C < 144)) { func_001118F8(D_0045D778); D_004A565C = 143; }
  i = D_004A565C++ * 64;
  func_0018EB98(D_003DA170 + i, 0x70003f80);
  i = D_004A565C++ * 64;
  func_0018EB98(D_003DA170 + i, 0x70003c80);
  if (D_004A14B8 != 0) {
    i = D_004A565C++ * 64;
    func_0018EB98(D_003DA170 + i, 0x70003d80);
  }
  D_003DC570[D_004A5658] = D_004A14B8;
  D_004A5658 = D_004A5658 + 1;
}
