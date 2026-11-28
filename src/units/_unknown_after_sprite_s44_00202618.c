// compiler: 990721-r5900
#include "../common.h"
typedef struct { char p[64]; short off; short s66; void (*fn)(void *, int); } VT_2618;
typedef struct { char p[76]; VT_2618 *vt; } O_2618;
extern void *D_004A1B24;
char *func_0025B170(int, int); int func_0025B308(int, int); int func_0025B6E0(int, int); void func_0023CB68(int); void func_00114478(char *, int, int, int, int, int);
int func_00114660(int, int, int, int, int, int, int, int); void func_002022D8(O_2618 *, int, int, int, int);
// MATCH func_00202618
void FUN_00202618(O_2618 *o, int a, int b, int *xy, int col, int c6, int c7) { char *s; int r;
  s = func_0025B170(a, b); if (s == 0) return;
  r = func_0025B308(a, b);
  if (func_0025B6E0(a, b) == 10) { c6 = 64; c7 = 0x404040; }
  func_0023CB68(col);
  { int x = xy[0]; D_004A1B24 = (void *)2; func_00114478(s, x, xy[1], 10, 10, c7); }
  D_004A1B24 = (void *)0;
  func_0023CB68(128);
  func_00114660(5, xy[0] + 120, xy[1], r, 3, col, c6, 17);
  o->vt->fn((char *)o + o->vt->off, col & 0xff);
  func_002022D8(o, a, b, xy[0], xy[1] + 11); }
