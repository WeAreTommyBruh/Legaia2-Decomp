// compiler: 991111-01-as210
#include "../common.h"
typedef struct { long long l0, l1; } __attribute__((packed)) U16;
int func_00213088(int, int); char *func_00212F00(int, int);
// MATCH func_00213178
int MotBoneBase(int o, int b, int c, float *out) {
  char *p, *e2; char *e; char *s; int t;
  if (func_00213088(o, b) == 0) {
    t = c * 48 + 104;
    e = (char *)(o + t);
    out[0] = *(float *)(e + 32);
    *(int *)(out + 3) = *(int *)(e + 44);
    out[1] = *(float *)(e + 36);
    out[2] = *(float *)(e + 40);
    return 1;
  }
  p = func_00212F00(o, b);
  e2 = p + *(int *)(p + 52) + c * 24;
  s = p + *(int *)(p + 60);
  *(U16 *)out = ((U16 *)s)[*(unsigned short *)(e2 + 2)];
  return 1;
}
