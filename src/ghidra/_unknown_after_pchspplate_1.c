/* _unknown_after_pchspplate_1: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_00455D38[];
void FUN_00110098(undefined8 param_1, undefined8 param_2, undefined8 param_3);
void FUN_001896b0(undefined8 param_1, uint param_2);
void FUN_00216be8(undefined8 param_1, uint param_2);

#define DAT_00455d38 (D_00455D38[0])
// MATCH func_00216CC0
void FUN_00216cc0(int param_1,int param_2)

{
  int iVar1;
  
  *(undefined **)((int)param_1 + 0x844) = &DAT_00455d38;
  FUN_00110098(0,0,0);
  iVar1 = *(int *)((int)param_1 + 0x86c);
  if (iVar1 != 0) {
    FUN_00216be8(iVar1,3);
  }
  FUN_001896b0(param_1,param_2);
  return;
}
#undef DAT_00455d38
