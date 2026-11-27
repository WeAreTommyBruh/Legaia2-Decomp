// compiler: 991111-01-as210
#include "../common.h"
#define W(o, n) (*(int *)((char *)(o) + (n)))
int func_002C7318_2C7C68(char *, int) __asm__("func_002C7318");
// MATCH func_002C7C68
void FUN_002c7c68(char *o) {
  int n, i;
  if (W(o, 0x13c) != 0) {
    if (W(o, 0x184) != 0) n = W(o, 0x178) != 0 ? 3 : 2;
    else n = 1;
  } else if (W(o, 0x174) != 3) n = 1;
  else n = W(o, 0x184) != 0 ? 3 : 2;
  for (i = 0; i < n; i++) {
    int *a = (int *)(o + 0x18c);
    int *b = (int *)(o + 0x198);
    *(int *)((char *)a + (i << 2)) = func_002C7318_2C7C68(o, 0x10); func_002C7318_2C7C68(o, 1); *(int *)((char *)b + (i << 2)) = func_002C7318_2C7C68(o, 0x10);
    func_002C7318_2C7C68(o, 1);
  }
}
