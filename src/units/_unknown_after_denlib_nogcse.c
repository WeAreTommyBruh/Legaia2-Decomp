/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

extern unsigned long D_004A12C8;
extern unsigned long D_004A12D8_0018D6C0 __asm__("D_004A12D8");
extern unsigned *D_004A36AC;
extern int D_004A36B0;
volatile short func_002C0338(int, int);
void func_0018D160(void *);
void func_0018D0A8(void *);
// MATCH func_0018D6C0
void FUN_0018d6c0(void)
{
  int i;
  int off;
  func_002C0338(0, 0);
  if ((D_004A12C8 & 0x100) && (((unsigned *) 0x11008000) < D_004A36AC))
  {
    D_004A36AC = D_004A36AC - 8;
  }
  if ((D_004A12C8 & 0x800) && (D_004A36AC < ((unsigned *) 0x1100fe00)))
  {
    D_004A36AC = D_004A36AC + 8;
  }
  if (D_004A12D8_0018D6C0 & 0x400)
  {
    D_004A36B0 ^= 1;
  }
  i = 0;
  do
  {
    if (D_004A36B0 == 0)
    {
      func_0018D160((unsigned *) (((char *) D_004A36AC) + (i * 16)));
    }
    else
    {
      func_0018D0A8((unsigned *) (((char *) D_004A36AC) + (i * 16)));
    }
    i++;
  }
  while (i < 32);
}
