#include "../common.h"
typedef struct { char p[488]; int h; int q; int f; int g; char r[608 - 504]; } S608;
extern int D_004A69A8; extern S608 D_005F9640[]; extern int D_004A72F8;
// MATCH func_002BA608
int FUN_002ba608(unsigned m, int k) {
  int i = 3;
  if (i < D_004A69A8) {
    S608 *s = &D_005F9640[i];
    do {
      if ((s->f & 4) && s->g == D_004A72F8 && !(s->f & m) && s->h == k) break;
      i++; s++;
    } while (i < D_004A69A8);
  }
  return i;
}
