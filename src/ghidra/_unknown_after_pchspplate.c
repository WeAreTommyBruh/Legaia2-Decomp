/* _unknown_after_pchspplate: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

undefined4 FUN_00216418(undefined4 *param_1);
void FUN_00216520(int param_1, int param_2);
void FUN_00249108(void);
void FUN_002491d8(void);
void MemFree(void *ptr);
void sammon_002275b8(undefined8 param_1);

// MATCH func_00216B18
void FUN_00216b18(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  if (iVar2 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 4);
    while( true ) {
      FUN_00216520(iVar2,uVar1);
      iVar2 = FUN_00216418(iVar2);
      if (iVar2 == 0) break;
      uVar1 = *(undefined4 *)(param_1 + 4);
    }
  }
  return;
}

// MATCH func_00216BB0
void FUN_00216bb0(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_00216E88
void FUN_00216e88(undefined8 param_1)

{
  FUN_00249108();
  sammon_002275b8(param_1);
  FUN_002491d8();
  return;
}
