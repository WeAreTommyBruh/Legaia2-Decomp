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


extern char *D_003279A0_24E0C8[] __asm__("D_003279A0");
extern char *D_004A1A20_0024E0C8 __asm__("D_004A1A20");
// MATCH func_0024E0C8
int FUN_0024e0c8(int a, int b) { char *o = D_003279A0_24E0C8[a]; char *p; int r = 0; if (o == 0) return 0; if (b == 0) r = *(int *)(*(char **)(D_004A1A20_0024E0C8 + a * 5472 + 5188) + 56) != 0; p = D_004A1A20_0024E0C8 + a * 5472; if (b == 1) r = 1; if (*(int *)(p + 4816) & 0x40000000) r = 1; if (*(signed char *)(p + 4943) != 0) r = 1; if (*(unsigned char *)(o + 210) == 0) r = 0; if (*(int *)(o + 20) == 0) return 0; return r; }
