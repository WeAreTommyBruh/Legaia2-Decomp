// compiler: 991111-01-as210
#include "../common.h"
int func_002CADE8_2CAD10(void) __asm__("func_002CADE8");
// MATCH func_002CAD10
int FUN_002cad10(int mode) {
  int s;
  s = func_002CADE8_2CAD10();
  if (s == 0) return 0;
  if (s == 1) return 0;
  if (mode == 0) *(volatile int *)0x10003810 = 2;
  else if (mode == 1) *(volatile int *)0x10003810 = 4;
  return 1;
}
