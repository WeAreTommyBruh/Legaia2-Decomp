// cflags: -ffixed-2
#include "../common.h"

// MATCH func_001D9798
void nayuki_001d9798(float scale, char *o) {
  float *p, *q, *r;
  int *ip, *iq, *ir;
  register float t __asm__("$f2");
  register float x0 __asm__("$f1");
  register float x1 __asm__("$f2");
  float a, b;

  p = (float *)(o + 1256);
  ip = (int *)p;
  a = p[9];
  b = p[10];
  t = p[0];
  x0 = t * scale;
  {
    register int n0 __asm__("$3");
    n0 = (int)((float)ip[3] * scale);
    p[0] = x0;
    p[6] = x0;
    p[9] = a;
    p[10] = b;
    if (n0 >= 0) ip[3] = n0;

    q = (float *)(o + 1336);
    iq = (int *)q;
    a = q[9];
    b = q[10];
    t = q[0];
    x0 = t * scale;
    n0 = (int)((float)iq[3] * scale);
    q[0] = x0;
    q[6] = x0;
    q[9] = a;
    q[10] = b;
    if (n0 >= 0) iq[3] = n0;
  }

  r = (float *)(o + 1416);
  ir = (int *)r;
  a = r[9];
  b = r[10];
  t = r[0];
  x0 = t * scale;
  {
    register int n1 __asm__("$4");
    n1 = (int)((float)ir[3] * scale);
    r[0] = x0;
    r[6] = x0;
    r[9] = a;
    r[10] = b;
    if (n1 >= 0) ir[3] = n1;

    x1 = p[1] * scale;
    n1 = (int)((float)ip[4] * scale);
    p[1] = x1;
    p[7] = x1;
    if (n1 >= 0) ip[4] = n1;
    x1 = q[1] * scale;
    n1 = (int)((float)iq[4] * scale);
    q[1] = x1;
    q[7] = x1;
    if (n1 >= 0) iq[4] = n1;
    x1 = r[1] * scale;
    n1 = (int)((float)ir[4] * scale);
    r[1] = x1;
    r[7] = x1;
    if (n1 >= 0) ir[4] = n1;
    x1 = p[2] * scale;
    n1 = (int)((float)ip[5] * scale);
    p[2] = x1;
    p[8] = x1;
    if (n1 >= 0) ip[5] = n1;
    x1 = q[2] * scale;
    n1 = (int)((float)iq[5] * scale);
    q[2] = x1;
    q[8] = x1;
    if (n1 >= 0) iq[5] = n1;
    x1 = r[2] * scale;
    n1 = (int)((float)ir[5] * scale);
    r[2] = x1;
    r[8] = x1;
    if (n1 >= 0) ir[5] = n1;
  }
}
