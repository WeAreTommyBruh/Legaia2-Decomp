/* Matched functions from this unit. */
#include "../common.h"

extern unsigned long D_004A12D8; extern void *D_003C2E40[]; extern int D_003C2E44[]; extern char D_00343028[];
int rsound_0010c2b0(char *, int, int, int, int, int, int) __asm__("func_0010C2B0");
// MATCH func_00215940
int FUN_00215940(int *o)
{
  o[7] = 0x65;
  if (D_004A12D8 & 0x200840) {
    do { rsound_0010c2b0(D_00343028, 0, 2, 0, 1, 0, 0); } while (0);
    o[7] = 0x66;
    o[1] = (int)D_003C2E40;
    o[2] = *(int *)(o[1] + 4) + 0x3c;
  }
  return 1;
}
