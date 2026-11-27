// cflags: -fno-gcse
#include "../common.h"
typedef struct { int type; int w52; int id; int w60; int val; int pad[5]; } E_10C2D0; typedef struct { char p[48]; E_10C2D0 e[32]; } O_10C2D0;
extern int D_004A118C_10C2D0 __asm__("D_004A118C"); extern int D_004A12B0_10C2D0 __asm__("D_004A12B0"), D_004A3850_10C2D0 __asm__("D_004A3850");
extern int D_00343028_10C2D0[] __asm__("D_00343028"); extern int D_002F95F0_10C2D0[] __asm__("D_002F95F0"), D_002F96B0[];
extern char D_0042D718_10C2D0[] __asm__("D_0042D718"), D_0042D7B0[], D_0042D7D0[], D_0042D810[], D_0042D838[], D_0042D878[];
void func_001118F8_10C2D0(char *, ...) __asm__("func_001118F8"); int func_002D48F8_10C2D0(int, int, int) __asm__("func_002D48F8");
// MATCH func_0010C2D0
int rsound_0010c2d0(O_10C2D0 *o, int b, unsigned i, int c, int d) {
  int r;
  int *pid;
  if ((D_00343028_10C2D0[0] & 8) || D_004A3850_10C2D0 == 2) return 0;
  if (D_004A118C_10C2D0 & 0x40) func_001118F8_10C2D0(D_0042D718_10C2D0, D_004A12B0_10C2D0);
  if (i >= 32) {
    if (D_004A118C_10C2D0 & 0x20) func_001118F8_10C2D0(D_0042D7B0, i);
    return -2;
  }
  if (D_004A118C_10C2D0 & 0x20) func_001118F8_10C2D0(D_0042D7D0, b, i, c, d);
  if (o->e[i].type != 1) {
    if (D_004A118C_10C2D0 & 0x20) func_001118F8_10C2D0(D_0042D810, i, o->e[i].type);
    return -2;
  }
  if (D_00343028_10C2D0[0] & 4) {
    { char *b = (char *)o + 56; pid = (int *)(b + i * 40); }
    if (*pid >= 0) {
      r = func_002D48F8_10C2D0(*pid, c, d);
      if (r >= 0) {
        if (D_004A118C_10C2D0 & 0x20) func_001118F8_10C2D0(D_0042D838, r, o->e[i].val, i, *pid, c, d);
        D_002F95F0_10C2D0[r] = -1;
        D_002F96B0[r] = *pid;
        return r;
      }
    }
  }
  if (D_004A118C_10C2D0 & 0x20) func_001118F8_10C2D0(D_0042D878, i, o->e[i].id);
  return -2;
}
