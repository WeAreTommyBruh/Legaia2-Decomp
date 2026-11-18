/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

extern unsigned short D_004A1490, D_004A1494; extern int D_004A7214, D_004A7218; extern char D_0045DD58[], D_0045DD48[];
unsigned *func_0018B508(int, char *); int func_0024B2A8(unsigned *, int, int); void func_001118F8(char *, ...);
// MATCH func_0024AF30
unsigned *init_0024af30(int a, int b, int c, short *o) {
  char tmp[16]; unsigned *h; unsigned i;
  h = func_0018B508(a, tmp);
  if (*h > 64) func_001118F8(D_0045DD58, *h);
  for (i = 0; i < *h; i++, o += 8) {
    { unsigned short x = D_004A1490, y = D_004A1494; o[0] = x; o[1] = y; }
    if (func_0024B2A8(h + h[i + 1], b, c) == -1) { func_001118F8(D_0045DD48); return 0; }
    o[4] = D_004A7214 / 64;
    o[2] = D_004A7214;
    o[3] = D_004A7218;
  }
  return h;
}
