// cflags: -fno-gcse
#include "../common.h"
typedef struct { int idx; unsigned short len; unsigned char flag; char pad; } K_3410;
// MATCH func_00213410
short MotChannelValue(int a, char *m, int c, int ch, int t) {
  K_3410 *k = (K_3410 *)(m + *(int *)(m + 0x40)) + ch;
  short *v;
  if (t >= k->len) { do { t -= k->len; k++; } while (t >= k->len); }
  v = (short *)(m + *(int *)(m + 0x44)) + k->idx;
  return k->flag != 0 ? *v : v[t];
}