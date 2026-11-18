/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern char *D_0036CE50[];
// MATCH func_0019B6C0
int EfbCommandAllowed(int a, int b, int c) { char *p = D_0036CE50[c]; return p[b - 1] == 0x31 ? 1 : -1; }

typedef struct { char p[280]; int w280; } O_19B6F0;
extern char D_00442B38[], D_00442B48[], D_004A3AB8[], D_004A3AC0[]; extern int D_004A3A84;
void func_001118F8(char *, ...); void func_0019ADC8(O_19B6F0 *, char *, int *); int func_0019B7C0(O_19B6F0 *, int);
// MATCH func_0019B6F0
void ikumi_0019b6f0(O_19B6F0 *o, int k) {
  char buf[16];
  switch (k) {
  case 0: func_0019ADC8(o, buf, &D_004A3A84); break;
  case 1: func_001118F8(D_00442B38); break;
  case 2: func_001118F8(D_004A3AB8); break;
  case 3: func_001118F8(D_00442B48); break;
  default:
    func_001118F8(D_004A3AC0);
    o->w280 += func_0019B7C0(o, o->w280);
    break;
  }
}
