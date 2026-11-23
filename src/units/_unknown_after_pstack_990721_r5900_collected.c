/* Matched functions from this unit. */
// compiler: 990721-r5900
#include "../common.h"

extern char *D_003279A0[];
void func_0018F020(void *, void *, void *);
void func_0018F080(void *, void *, void *);
// MATCH func_0024D810
int FUN_0024d810(float f, int i)
{
  char buf[16] __attribute__((aligned(16)));
  char *p = D_003279A0[i];
  func_0018F080(buf, p + 0x20, p + 0x80);
  { float *g = (float *)(D_003279A0[i] + 0x80); if (0.0f < *g) *g = f; else *g = -f; }
  func_0018F020(D_003279A0[i] + 0x20, D_003279A0[i] + 0x80, buf);
  return 1;
}
