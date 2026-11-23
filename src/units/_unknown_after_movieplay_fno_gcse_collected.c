/* Matched functions from this unit. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct { float a, b, c, d, e; int f, g; } S_;
void func_00115090(int *, int, int, float, float, int, int, float, int, int);
// MATCH func_00115618
int FUN_00115618(int x, int y, int *pos, int u3, int u4, S_ *s) {
  float r = 0.0f; int px = pos[0], py = pos[1];
  float fx = (float)px + s->c * s->e, fy = (float)py + s->d * s->e;
  if (px < x && (float)x < fx) { if (py < y && (float)y < fy) r = 1.0f; }
  func_00115090(pos, (int)s->c, (int)s->d, s->a + r * s->c, s->b, s->f, s->g, s->e, 128, 128);
  return (int)r;
}
