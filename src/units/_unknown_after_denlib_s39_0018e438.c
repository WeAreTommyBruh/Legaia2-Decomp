#include "../common.h"
void func_0018EC38(float (*)[4]); void func_0018F3D8(float (*)[4], float (*)[4], float (*)[4]);
// MATCH func_0018E438
void FUN_0018e438(float m[4][4], float a, float b, float c, float d, float e, float n, float f, float g, float h) {
  float t[4][4];
  float B = (n * h - f * g) / (h - g);
  float A = h * g * (f - n) / (h - g);
  func_0018EC38(m);
  { register float (*tp)[4] __asm__("$4");
  m[0][0] = a; __asm__("");
  tp = t; __asm__("");
  m[1][1] = a;
  m[2][2] = 0; __asm__("");
  m[3][3] = 0;
  m[2][3] = 1.0f;
  m[3][2] = 1.0f;
  func_0018EC38(tp); }
  t[0][0] = b;
  t[1][1] = c;
  t[2][2] = A;
  t[3][0] = d;
  t[3][1] = e;
  t[3][2] = B;
  func_0018F3D8(m, t, m);
}
