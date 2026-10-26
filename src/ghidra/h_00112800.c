/* Ghidra's decompilation, statement order searched by build/work/ghill.py. */
// cflags: -fexceptions
#include "../ghidra.h"
void FUN_00112b10(int param_1, undefined4 param_2);
// MATCH func_00112800
void FUN_00112800(int param_1, undefined4 param_2, unsigned int param_3, int param_4)
{
  int iVar1;
  undefined4 *puVar2;
  FUN_00112b10(param_1, param_4);
  puVar2 = (undefined4 *) param_1;
  iVar1 = puVar2[3];
  *puVar2 = param_2;
  puVar2[2] = 0;
  puVar2[1] = ((0xf + (iVar1 + (param_3 * 0x24))) / iVar1) * iVar1;
  return;
}
