#include "../common.h"
extern char D_003FEBA8[];
void func_00255278(int); int func_00250AB0(int); int func_00254F48(int);
// MATCH func_00253328
int FUN_00253328(int a, int b) { int i; unsigned short *p; func_00255278(7);
  p = (unsigned short *)(D_003FEBA8 + b * 472); p += 3344;
  for (i = 4; i < 16; i++, p++) {
    if (*p == 0) {
      if (func_00250AB0(a) < 300) { *p = func_00250AB0(a); func_00254F48(a); func_00255278(8); return 1; }
      func_00255278(8); return 0;
    }
  }
  func_00255278(8); return 0; }
