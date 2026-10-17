/* pchse: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_00108b80(int param_1);
void FUN_00212dc8(undefined8 param_1, uint param_2);
void FUN_00212e20(undefined8 param_1, uint param_2);

// MATCH func_00212138
void pchse_00212138(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 8);
  if (iVar1 != 0) {
    FUN_00212e20(iVar1,3);
  }
  iVar1 = *(int *)((int)param_1 + 0xc);
  if (iVar1 != 0) {
    FUN_00212dc8(iVar1,3);
  }
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}
