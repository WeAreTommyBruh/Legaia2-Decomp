#include "../common.h"
typedef struct { int a, b, c; int bits[8]; } S_25A688;
extern S_25A688 D_003FEBA8;
int func_0025A708(int);
// MATCH func_0025A688
int FUN_0025a688(int a) {
  int pad[4];
  if ((unsigned)a >= 60) return -1;
  if (func_0025A708(a) != 0) return 1;
  { register int m __asm__("$5") = 1 << a; register int v __asm__("$4") = D_003FEBA8.bits[a / 32]; D_003FEBA8.bits[a / 32] = v | m; }
  return 0;
}
