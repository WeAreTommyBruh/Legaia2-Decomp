/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
// cflags: -fno-gcse
#include "../common.h"

typedef struct { char p0[1784]; char *b; char p1[16756]; char *c; } O_;
extern int D_0033D9A0[]; extern int D_0033D8D8[]; extern char D_0043EDD0[];
void func_00187028(O_ *); void func_00186F40(O_ *, int *, int, int); char *func_00162130(int, char *, int); void func_00188870(O_ *);
// MATCH func_00188B88
void srivus_00188b88(O_ *o) {
  char *p, *p3; int i; int *q; char *e; char *t;
  func_00187028(o);
  func_00186F40(o, D_0033D8D8, 19, 20);
  if (o->c == 0) {
    p = func_00162130(8256, D_0043EDD0, 1552); p3 = p;
    i = 3;
    do { *(int *)(p3 + 2048) = 0; i--; *(int *)(p3 + 2052) = 0; p3 += 2064; } while (i != -1);
    o->c = p;
    if (p == 0) return;
  }
  q = D_0033D9A0; t = *(char **)(o->b + 144) + 1024; e = o->c;
  do {
    int k = *q;
    *(int **)(e + 2052) = q; q += 3;
    *(int *)(e + 2056) = *(int *)((k << 2) + t);
    e += 2064;
  } while (q < D_0033D9A0 + 12);
  func_00188870(o);
}
