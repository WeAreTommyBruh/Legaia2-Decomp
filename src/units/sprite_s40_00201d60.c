// compiler: 991111-01-as210
#include "../common.h"
typedef struct { int w0, w4, w8, w12, w16; float f20, f24; int w28, w32; } O;
extern char D_00454010[];
void func_0024BD50(int, int, int, int, int, char *, int);
// MATCH func_00201D60
int sprite_00201d60(float w, float h, O *o, int a0, int b, int c) {
  int n, k; register int a __asm__("$18") = a0;
  if (o->w16 == 0) return -1;
  func_0024BD50(o->w16, b, c, 0, a, D_00454010, 120);
o->w0 = a;
  o->w4 = c;
  o->w8 = b;
  o->w28 = 0;
  o->f20 = w - 1.0f;
  n = (int)w;
  o->f24 = h - 1.0f;
  if (n > 1) { k = 0; do { n >>= 1; k++; } while (n > 1); o->w28 = k; }
  n = (int)h;
  o->w32 = 0;
  if (n > 1) { k = 0; do { n >>= 1; k++; } while (n > 1); o->w32 = k; }
  return 1;
}
