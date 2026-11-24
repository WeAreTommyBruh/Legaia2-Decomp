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

extern const float D_0049FF8C,D_0049FF90;float func_0015FB58(float,int);

// MATCH func_0015E148
void flare_0015e148(float *p,float angle,float scale)
{
    float a, b, c, d, *v, *p1, *p2, *p3, *p4;
    a = func_0015FB58(angle, 1);
    b = func_0015FB58(angle, 0);
    angle+=D_0049FF8C;
    c = func_0015FB58(angle, 1)*scale;
    d = func_0015FB58(angle, 0)*scale;
    p[0] = a;
    p[1] = b;
    p[2] = D_0049FF90;
    p[3] = 1.0f;
    p1 = p+4;
    p1[0] = c;
    p1[1] = d;
    p1[2] = D_0049FF90;
    p1[3] = 1.0f;
    p2 = p+8;
    p2[0] = -a;
    p2[1] = -b;
    p2[2] = D_0049FF90;
    p2[3] = 1.0f;
    p3 = p+12;
    p3[0] = -c;
    p3[1] = -d;
    p3[2] = D_0049FF90;
    p3[3] = 1.0f;
    p4 = p+16;
    p4[0] = a;
    p4[1] = b;
    p4[2] = D_0049FF90;
    p4[3] = 1.0f;
}


extern char D_0043BB00_15E068[] __asm__("D_0043BB00");
extern char D_0043BB10_15E068[] __asm__("D_0043BB10");
void *func_00162130_15E068(int, void *, int) __asm__("func_00162130");
void func_001118F8_15E068(void *) __asm__("func_001118F8");
void func_002C0838_15E068(void *, int, int, int, short, short, short, short) __asm__("func_002C0838");
void func_002E5B20_15E068(int) __asm__("func_002E5B20");
void func_002C0AF8_15E068(void *, unsigned) __asm__("func_002C0AF8");
void func_002C0338_15E068(int, int) __asm__("func_002C0338");
// MATCH func_0015E068
void *flare_0015e068(int x, int y, int w, int h) { char buf[112]; void *p = func_00162130_15E068(w * h * 4 + 15, D_0043BB00_15E068, 49); if (p == 0) func_001118F8_15E068(D_0043BB10_15E068); func_002C0838_15E068(buf, 4480, 10, 48, x, y, w, h); func_002E5B20_15E068(0); func_002C0AF8_15E068(buf, (unsigned)p & 0xfffffff0); func_002C0338_15E068(0, 0); return p; }
