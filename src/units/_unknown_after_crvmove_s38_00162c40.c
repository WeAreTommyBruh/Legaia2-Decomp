// compiler: 990721
typedef struct { float x, y, z, w; } V;
typedef struct { char p[16]; V a, b; char q[8]; int x38; } S;
static inline int veq(V *a, V *b) { int r = 0; if (a->x == b->x && a->y == b->y && a->z == b->z) r = 1; return r; }
// MATCH func_00162C40
int FUN_00162c40(S *s)
{
  int r = 0;
  if (s->x38 == 0) r = veq(&s->a, &s->b);
  return r;
}
