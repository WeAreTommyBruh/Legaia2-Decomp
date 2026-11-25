// compiler: 990721
typedef struct { float x, y, z, w; } V;
typedef struct { int a, b; float f, g; V v[4]; int x50, x54, x58; } S;
#define VZ(p) __asm__ volatile("sqc2 $vf0, 0(%0)" : : "r"(p))
// MATCH func_00177568
S *FUN_00177568(S *s)
{
  s->f = 1000.0f;
  s->g = 1.0f;
  s->x50 = 0;
  s->a = 0;
  s->b = 0;
  VZ(&s->v[0]); VZ(&s->v[1]); VZ(&s->v[2]); VZ(&s->v[3]);
  s->x54 = 0x80;
  s->x58 = 0;
  return s;
}
