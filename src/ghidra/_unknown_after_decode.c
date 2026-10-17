/* _unknown_after_decode: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_002cf4b0(int *param_1, uint param_2);
void FUN_002cf848(int *param_1, undefined4 param_2);
void FUN_002d41a8(undefined8 param_1, undefined8 param_2, undefined8 param_3);
void FUN_002d5518(uint param_1, ulong param_2, long param_3);
void MemFree(void *ptr);

// MATCH func_00190A60
void FUN_00190a60(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_00190DC8
int FUN_00190dc8(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x50008) - *(int *)(param_1 + 0x50004);
  if (iVar1 != 0) {
    *param_2 = param_1 + *(int *)(param_1 + 0x50000);
  }
  return iVar1;
}

// MATCH func_00191618
void FUN_00191618(undefined8 param_1)

{
  FUN_002d41a8(0,param_1,param_1);
  FUN_002d41a8(1,param_1,param_1);
  return;
}

// MATCH func_00191658
void FUN_00191658(undefined8 param_1)

{
  FUN_002d5518(1,param_1,0);
  FUN_002d5518(2,0,param_1);
  return;
}

// MATCH func_00192950
undefined4 FUN_00192950(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0xa8);
  *(undefined4 *)(param_1 + 0xa8) = param_2;
  return uVar1;
}

// MATCH func_00194848
void FUN_00194848(int param_1,int param_2,int param_3)

{
  FUN_002cf4b0(param_1,0);
  FUN_002cf848(param_1,param_2);
  FUN_002cf848(param_1,param_3);
  return;
}

// MATCH func_00194900
bool FUN_00194900(int param_1)

{
  return *(int *)(param_1 + 0xc) == *(int *)(param_1 + 0x10);
}

// MATCH func_001949D0
bool FUN_001949d0(int param_1)

{
  return *(int *)(param_1 + 0xc) == 0;
}
