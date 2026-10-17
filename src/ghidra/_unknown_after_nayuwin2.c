/* _unknown_after_nayuwin2: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_00108c20(float *param_1);
void FUN_00108c80(int param_1);
undefined2 FUN_00250ab0(void);
int FUN_00254ce0(uint param_1, int param_2);
int FUN_00255008(uint param_1, int param_2);
void MemFree(void *ptr);
void clas_min_002a6160(void);

// MATCH func_001B4B80
void FUN_001b4b80(int param_1,char param_2,char param_3)

{
  int uVar1;
  int iVar2;
  
  iVar2 = (int)param_3 - (int)param_2;
  if (iVar2 < 0) {
    uVar1 = FUN_00250ab0();
    FUN_00255008(uVar1,-iVar2);
    return;
  }
  uVar1 = FUN_00250ab0();
  FUN_00254ce0(uVar1,iVar2);
  return;
}

// MATCH func_001B78A8
void FUN_001b78a8(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_001B78C0
void FUN_001b78c0(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_001B78F0
void FUN_001b78f0(float param_1,int param_2)

{
  int iVar1;
  
  if (0.0f <= param_1) {
    iVar1 = (int)param_2;
    *(float *)(iVar1 + 0x14) = param_1;
    if (*(float *)(iVar1 + 0xc) < param_1) {
      *(float *)(iVar1 + 0x14) = *(float *)(iVar1 + 0xc);
    }
    FUN_00108c80(param_2);
    FUN_00108c20(param_2);
    return;
  }
  return;
}

// MATCH func_001C79A0
void FUN_001c79a0(int param_1)

{
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined4 *)(param_1 + 4) = 1;
  }
  clas_min_002a6160();
  return;
}
