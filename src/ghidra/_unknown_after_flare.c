/* _unknown_after_flare: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_0018fd98(int param_1, uint *param_2, uint param_3, int param_4, uint param_5);

// MATCH func_0015F5A0
void FUN_0015f5a0(int param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(undefined4 *)(iVar1 + 0x14) = 1;
  *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar1 + 8);
  FUN_0018fd98(param_1,*(undefined4 *)(iVar1 + 8),0x10,0,0);
  return;
}

// MATCH func_00161278
void FUN_00161278(int *param_1)

{
  *(int *)param_1[1] = *param_1;
  *(int *)(*param_1 + 4) = param_1[1];
  return;
}
