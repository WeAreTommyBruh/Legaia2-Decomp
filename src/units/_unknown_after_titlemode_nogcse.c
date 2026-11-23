/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

// MATCH func_00216480
void FUN_00216480(char *o) { int n = *(int *)(o + 0x18); int t; float x, y, a, b, c, d, ft, fn; if (n != 0) { t = *(int *)(o + 0x1c) + 1; *(int *)(o + 0x1c) = t; if (n < t) *(int *)(o + 0x1c) = n; if (*(int *)(o + 0x1c) == *(int *)(o + 0x18)) { x = *(float *)(o + 0x30); y = *(float *)(o + 0x34); } else { ft = (float)*(int *)(o + 0x1c); fn = (float)*(int *)(o + 0x18); x = ((*(float *)(o + 0x30) - *(float *)(o + 0x28)) * ft) / fn + *(float *)(o + 0x28); y = ((*(float *)(o + 0x34) - *(float *)(o + 0x2c)) * ft) / fn + *(float *)(o + 0x2c); } *(float *)(o + 0x24) = y; *(float *)(o + 0x20) = x; } }

typedef struct { char p0[12]; unsigned col; char p16[28]; float a; float da; } O_215E60;
extern char D_003C2B70[];
void func_00214A68(O_215E60 *, char *, int, int);
// MATCH func_00215E60
void FUN_00215e60(O_215E60 *o)
{
  unsigned c;
  o->a = o->a + o->da;
  if (o->a <= 0.0f) { o->a = 0.0f; o->da = 0.0f; }
  if (1.0f <= o->a) { o->a = 1.0f; o->da = 0.0f; }
  if (0.0f < o->a) {
    c = o->col;
    o->col = (int)(o->a * 128.0f) << 24 | 0x808080;
    func_00214A68(o, D_003C2B70, 0, 0);
    o->col = c;
  }
}
