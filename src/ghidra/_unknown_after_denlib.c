/* _unknown_after_denlib: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_0018e680(undefined4 param_1);
void FUN_0018e860(undefined4 param_1);
void FUN_0018f3d8(undefined1 (*param_1) [16], undefined1 (*param_2) [16], undefined1 (*param_3) [16]);
void FUN_0018fd98(int param_1, uint *param_2, uint param_3, int param_4, uint param_5);
void FUN_00190668(void);
void MemFree(void *ptr);

// MATCH func_0018DD78
void FUN_0018dd78(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_0018DD90
void FUN_0018dd90(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_0018DE38
void FUN_0018de38(int param_1,int param_2)

{
  *(int *)(param_1 + 0x10) = param_2 + 8;
  return;
}

// MATCH func_0018E818
void FUN_0018e818(int param_1,int param_2)

{
  FUN_0018e680(0x70003ec0);
  FUN_0018f3d8(param_1,param_2,0x70003ec0);
  return;
}

// MATCH func_0018E9F0
void FUN_0018e9f0(int param_1,int param_2)

{
  FUN_0018e860(0x70003ec0);
  FUN_0018f3d8(param_1,param_2,0x70003ec0);
  return;
}

// MATCH func_00190610
void FUN_00190610(int param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(undefined4 *)(iVar1 + 0x14) = 1;
  *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar1 + 8);
  FUN_0018fd98(param_1,*(undefined4 *)(iVar1 + 8),0x10,0,0);
  return;
}

// MATCH func_00190640
undefined8 FUN_00190640(undefined8 param_1)

{
  FUN_00190668();
  return param_1;
}
