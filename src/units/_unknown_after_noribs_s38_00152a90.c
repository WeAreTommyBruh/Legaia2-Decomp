// compiler: 990721
typedef struct { int a; int pad; int d; int c; float x; float y; int e; int b; } E;
extern E D_0032CCF0[];
extern int D_004A6F14, D_004A6F10;
// MATCH func_00152A90
void FUN_00152a90(int a, int b, int c, int d, int e, float x, float y)
{
  if (D_004A6F14 < 33) {
    E *p = &D_0032CCF0[D_004A6F14];
    p->a = a;
  p->b = b;
  p->c = c;
  p->d = d;
  p->e = e;
  p->x = x;
  p->y = y;
  }
  D_004A6F10 = 0;
  D_004A6F14++;
}
