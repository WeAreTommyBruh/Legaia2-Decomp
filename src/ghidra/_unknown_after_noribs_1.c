/* _unknown_after_noribs_1: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_00153b38(undefined8 param_1);
void FUN_00154550(int param_1);
void func_00155988(undefined4 *param_1);
void func_00155990(undefined4 *param_1);

// MATCH func_00153FB8
void FUN_00153fb8(int param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1 + 0xc0;
  func_00155990(iVar1);
  FUN_00153b38(iVar1);
  FUN_00154550(param_1);
  return;
}

// MATCH func_00153FF8
void FUN_00153ff8(int param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1 + 0xc0;
  func_00155988(iVar1);
  FUN_00153b38(iVar1);
  FUN_00154550(param_1);
  return;
}
