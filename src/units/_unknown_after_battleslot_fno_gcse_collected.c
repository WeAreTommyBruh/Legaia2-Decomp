/* Matched functions from this unit. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct { char p[576]; char *obj; char p2[28]; } C_29BBD0;
extern C_29BBD0 D_005F9640[];
int clas_min_002a0020(int);
// MATCH func_0029BBD0
void FUN_0029bbd0(int *o, unsigned char *s, int v)
{
  int k;
  o[0] = 1;
  o[2] = 1;
  while (1) {
    if (*s == 'M') {
      k = clas_min_002a0020(*(int *)(s + 4));
      s += 8;
      if (k >= 0) { C_29BBD0 *c = &D_005F9640[k]; if (c->obj != 0) *(int *)(c->obj + 16) = v; }
    } else {
      o[2] = 0;
    }
    if (o[2] == 0) return;
  }
}
