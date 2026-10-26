/* Ghidra's decompilation, statement order searched by build/work/ghill.py. */
// cflags: -fexceptions
#include "../ghidra.h"
int FUN_002d6990(int param_1, int *param_2, int);
void * memcpy(void *dst, void *src, uint n);
// MATCH func_002D6A18
void *FUN_002d6a18(int param_1, int param_2, int param_3)
{
  void *pvVar1;
  void *dst;
  uint n;
  pvVar1 = (void *) FUN_002d6990(param_1, param_2, 0);
  dst = (void *) FUN_002d6990(param_1, param_3, 0);
  if (!(param_1 < 0x1f))
  {
    n = 8;
    if (param_1 < 0x40)
    {
      n = 4;
    }
  }
  else
  {
    n = 0x10;
  }
  pvVar1 = memcpy(dst, pvVar1, n);
  return pvVar1;
}
