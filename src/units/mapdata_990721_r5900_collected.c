/* Matched functions from this unit. */
// compiler: 990721-r5900
#include "../common.h"

typedef struct { char p[308]; int a; int b; int c; char q[16]; } E336;
typedef struct { char *e0; E336 *e1; int n; E336 **list; int nvis; char pad[16]; int *other; } O_159798;
extern char D_0043B680[];
void func_00248A58(int); void func_0015AA68(E336 *); void *func_00162130(int, char *, int); int *func_00159250(E336 *, int *, int *);
// MATCH func_00159798
void mapdata_00159798(O_159798 *o, int *src) {
  char *str; int n, m, i, k, cnt, t; E336 *base; E336 *p; E336 *e; int *blk;

  func_00248A58(0x70003f80);
  func_00248A58(0x70003c80);
  n = *src;
  o->n = n;
  src++;
  blk = (int *)func_00162130((n + 1) * 336 + 16, D_0043B680, 1534);
  base = (E336 *)(blk + 4);
  blk[0] = n + 1;
  p = base;
  m = n;
  for (; m != -1; m--) { func_0015AA68(p); p++; }
  i = 0;
  o->e1 = base;
  e = base + o->n;
  e->c = o->other[9];
  o->e0 = (char *)e;
  func_00248A58((int)e + 80);
  func_00248A58((int)o->e0 + 208);
  func_00248A58((int)o->e0 + 144);
  *(short *)(o->e0 + 272) = 0; *(short *)(o->e0 + 72) = -1; *(short *)(o->e0 + 74) = -1;
  o->nvis = 0;
  p = o->e1;
  if (o->n > 0) {
    do {
      p->a = 0;
      src = func_00159250(p, src, o->other);
      if (p->c != 0) o->nvis++;
      i++;
      p++;
    } while (i < o->n);
  }
  o->list = (E336 **)func_00162130(o->nvis << 2, D_0043B680, 1556);
  t = o->n; k = 0;
  p = o->e1;
  if (t > 0) {
    cnt = t;
    do {
      if (p->c != 0) { o->list[k] = p; k++; }
      cnt--; p++;
    } while (cnt != 0);
  }
}
