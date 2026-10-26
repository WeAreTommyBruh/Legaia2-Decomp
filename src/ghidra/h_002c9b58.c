/* Ghidra's decompilation, statement order searched by build/work/ghill.py. */
// cflags: -fexceptions
#include "../ghidra.h"
extern byte D_0062B3D0[];
void FUN_002e6198(uint param_1, uint param_2);
// MATCH func_002C9B58
int FUN_002c9b58(int param_1, int param_2)
{
  int iVar1;
  int new_var;
  int new_var2;
  iVar1 = *((int *) (((&D_0062B3D0[0]) + (param_2 * 0x1c)) + (param_1 * 0x70)));
  new_var = iVar1 + 0x58;
  FUN_002e6198(iVar1, iVar1 + 0x100);
  new_var2 = ((uint) ((*((int *) new_var)) < (*((int *) (iVar1 + 0xd8))))) * 0x80;
  return iVar1 + new_var2;
}
