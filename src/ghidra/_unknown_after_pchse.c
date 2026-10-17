/* _unknown_after_pchse: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_00108b80(int param_1);
bool FUN_0010e240(int param_1);
void FUN_0010e368(undefined8 param_1);
void FUN_00212e90(undefined8 param_1, uint param_2);
void MemFree(void *ptr);

// MATCH func_00212890
int FUN_00212890(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  for (puVar1 = *(undefined4 **)(param_1 + 8); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}

// MATCH func_00212930
int FUN_00212930(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  for (puVar1 = *(undefined4 **)(param_1 + 0xc); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}

// MATCH func_00212D50
void FUN_00212d50(int *param_1)

{
  int lVar1;
  
  lVar1 = FUN_0010e240(*param_1);
  if (lVar1 == 1) {
    FUN_0010e368(*param_1);
    return;
  }
  return;
}

// MATCH func_00212D90
void FUN_00212d90(int param_1)

{
  undefined4 *puVar1;
  
  for (puVar1 = *(undefined4 **)(param_1 + 0xc); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
  }
  return;
}

// MATCH func_00212DC8
void FUN_00212dc8(int param_1,int param_2)

{
  if (*(int *)param_1 != 0) {
    FUN_00212dc8(*(int *)param_1,3);
  }
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}

// MATCH func_00212E20
void FUN_00212e20(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = ((int *)param_1)[4];
  if (iVar1 != 0) {
    FUN_00212e90(iVar1,3);
  }
  iVar1 = *(int *)param_1;
  if (iVar1 != 0) {
    FUN_00212e20(iVar1,3);
  }
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}

// MATCH func_00212EE8
void FUN_00212ee8(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_002141B0
void FUN_002141b0(int param_1,int param_2)

{
  FUN_00108b80(*(undefined4 *)param_1);
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}
