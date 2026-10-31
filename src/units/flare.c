/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { int x, y, z, w; } V_15ec08_0015EC08;
typedef struct { char pad[16]; V_15ec08_0015EC08 v; } S_15ec08_0015EC08;
static inline void set_15ec08_0015EC08(V_15ec08_0015EC08 *v, int x, int y, int z, int w) {
v->x = x;
v->y = y;
v->z = z;
v->w = w;
}
// MATCH func_0015EC08
void flare_0015ec08(S_15ec08_0015EC08 *s, int x, int y, int z) { set_15ec08_0015EC08(&s->v, x, y, z, 128); }

extern float D_0049FF94;
extern float D_0049FF98;
void func_0015E148(void *, float, float);
// MATCH func_0015E2A0
void flare_0015e2a0(char *o, float r, int n)
{
  float step;
  char *p;
  int k;
  unsigned int new_var;
  int m;
  m = 8;
  new_var = n <= 8;
  if (new_var)
  {
    m = n;
  }
  *((int *) o) = m;
  *((float *) (o + 4)) = r;
  step = 0.0f;
  if (m >= 2)
  {
    step = D_0049FF94 / ((float) m);
  }
  if (m > 0)
  {
    p = o + 16;
    k = m;
    do
    {
      func_0015E148(p, r, D_0049FF98);
      p += 80;
      r += step;
    }
    while (--k);
  }
}
