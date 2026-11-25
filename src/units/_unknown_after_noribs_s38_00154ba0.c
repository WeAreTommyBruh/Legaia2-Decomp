// compiler: 990721-r5900
typedef struct { float x, y, z, w; } V;
typedef struct { V v0; char p[0xb0 - 16]; int a[4]; char q[0x140 - 0xc0]; int b[2]; int c, d; } S;
// MATCH func_00154BA0
void FUN_00154ba0(S *s)
{
  int i; int *p;
  s->c = 0;
  s->d = 0;
  p = &s->a[3];
  i = 3;
  do { *p = 0; i--; p--; } while (i >= 0);
  i = 31; p = (int *)((char *)s + 320);
  do { *p = 0; i--; p--; } while (i >= 0);
  __asm__("sqc2 $vf0, %0" : "=m"(s->v0));
}
