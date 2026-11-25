// compiler: 990721
extern char D_002F0800[];
extern char D_002F08C0[];
// MATCH func_00192DD0
void FUN_00192dd0(int *base, int i, int j, int a, int b)
{
  int v;
  int *p;
  int *q;
  do {
    v = *(int *)((char *)base + (i * 8 + j * 4));
    p = (int *)(((unsigned)D_002F0800 & 0x0fffffff) | 0x20000000);
    q = (int *)(((unsigned)D_002F08C0 & 0x0fffffff) | 0x20000000);
    p[1] = v;
  } while (0);
  q[1] = b;
  q[0] = a;
}
