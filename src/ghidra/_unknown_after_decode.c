/* _unknown_after_decode: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_00191618(undefined8 param_1);
void FUN_00191658(undefined8 param_1);
undefined4 FUN_002c2008(void);
undefined8 FUN_002d5448(uint param_1);
undefined8 FUN_002d5488(uint param_1);
undefined4 FUN_002d54c8(uint param_1, uint param_2);
void MemFree(void *ptr);
void SignalSema(int);
void WaitSema(int);

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

// MATCH func_00190FC0
undefined4 FUN_00190fc0(void)

{
  FUN_00191618(0);
  return 1;
}

// MATCH func_00190FE0
void FUN_00190fe0(undefined4 *param_1)

{
  FUN_00191658(0);
  FUN_002d5488(3);
  *param_1 = 3;
  return;
}

// MATCH func_00191018
void FUN_00191018(undefined4 *param_1)

{
  FUN_00191658(0x3c78);
  FUN_002d54c8(0,0);
  FUN_002d54c8(1,0);
  FUN_002d5448(3);
  *param_1 = 2;
  return;
}

// MATCH func_001922C0
undefined4 FUN_001922c0(int param_1)

{
  undefined4 uVar1;
  
  WaitSema(*(undefined4 *)(param_1 + 0x40));
  uVar1 = *(undefined4 *)(param_1 + 0x44);
  SignalSema(*(undefined4 *)(param_1 + 0x40));
  return uVar1;
}

// MATCH func_00192908
undefined4 FUN_00192908(void)

{
  FUN_002c2008();
  return 1;
}

// MATCH func_00192950
undefined4 FUN_00192950(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0xa8);
  *(undefined4 *)(param_1 + 0xa8) = param_2;
  return uVar1;
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
