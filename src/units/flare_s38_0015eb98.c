// compiler: 990721
typedef struct { int r, g, b, a; } C;
typedef struct { char p[16]; C c0, c1; } O;
extern unsigned char D_004A2B60[6];
static inline void setc(C *c, int r, int g, int b) { c->r = r; c->g = g; c->b = b; c->a = 0x80; }
// MATCH func_0015EB98
void flare_0015eb98(O *o, unsigned char *c)
{
  unsigned char *p = D_004A2B60;
  if (c) p = c;
  setc(&o->c0, p[0], p[1], p[2]);
  setc(&o->c1, p[3], p[4], p[5]);
}
