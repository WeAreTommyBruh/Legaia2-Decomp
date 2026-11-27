#include "../common.h"
typedef struct { char p[144]; float v[6]; int g; int z; } S44;
typedef struct { char p[132]; int n; } E;
typedef struct { char p[0x918]; E *e[1]; } W;
typedef struct { char p[0x90]; W *w; } O;
// MATCH func_0021CAE0
void FUN_0021cae0(O *o, int i, float a, float b, float c, float d, float e, float f, int g)
{
  E *t = o->w->e[i];
  if (t != 0 && t->n < 4) {
    S44 *s = (S44 *)((char *)t + t->n * 44);
     s->z = 0; s->g = g; s->v[1] = b; s->v[2] = c; s->v[3] = d; s->v[4] = e; s->v[5] = f; t->n++; s->v[0] = a;   }
}
