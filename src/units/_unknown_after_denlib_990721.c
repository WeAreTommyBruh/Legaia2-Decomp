/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"

extern char D_004A3698[];
extern char D_004A36A8[];
extern char D_004A3688[];
unsigned long long func_001118F8_0018D550(char *, ...) __asm__("func_001118F8");
// MATCH func_0018D550
void FUN_0018d550(float *p, float *q)
{
  int i;
  float v;
  while (p < q)
  {
    func_001118F8_0018D550(D_004A3698, p);
    i = 3;
    do
    {
      v = *p;
      i--;
      p++;
      func_001118F8_0018D550(D_004A36A8, (double) v);
    }
    while (i >= 0);
    func_001118F8_0018D550(D_004A3688);
  }

  func_001118F8_0018D550(D_004A3688);
}

extern char D_004A3698_0018D4A8[] __asm__("D_004A3698"); extern char D_004A36A0[]; extern char D_004A3688_0018D4A8[] __asm__("D_004A3688");
unsigned long long func_001118F8_0018D4A8(char *, ...) __asm__("func_001118F8");
// MATCH func_0018D4A8
void FUN_0018d4a8(int *p, int *q)
{
  int i;
  int v;
  while (p < q)
  {
    func_001118F8_0018D4A8(D_004A3698_0018D4A8, p);
    i = 3;
    do
    {
      v = *p;
      p++;
      func_001118F8_0018D4A8(D_004A36A0, v);
      i--;
    }
    while (i >= 0);
    func_001118F8_0018D4A8(D_004A3688_0018D4A8);
  }

  func_001118F8_0018D4A8(D_004A3688_0018D4A8);
}

extern char D_004A3698_0018D600[] __asm__("D_004A3698"); extern char D_004A36A0_0018D600[] __asm__("D_004A36A0"); extern char D_004A3688_0018D600[] __asm__("D_004A3688");
extern int D_004A129C;
unsigned long long func_00239568(char *, ...);
// MATCH func_0018D600
void FUN_0018d600(int *p, int *q)
{
  int i;
  int v;
  int save;
  save = D_004A129C;
  D_004A129C = 1;
  while (p < q)
  {
    func_00239568(D_004A3698_0018D600, p);
    i = 3;
    do
    {
      v = *p;
      p++;
      func_00239568(D_004A36A0_0018D600, v);
      i--;
    }
    while (i >= 0);
    func_00239568(D_004A3688_0018D600);
  }
  func_00239568(D_004A3688_0018D600);
  D_004A129C = save;
}
