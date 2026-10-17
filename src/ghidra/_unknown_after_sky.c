/* _unknown_after_sky: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern char D_00342CD0[];
void FUN_00158af8(int param_1, ushort *param_2, int param_3, uint param_4);
undefined4 FUN_0018bb70(uint *param_1, int, int, int, int, int);
void MemFree(void *ptr);

// MATCH func_001565B0
void FUN_001565b0(int param_1,int param_2,undefined4 param_3)

{
  *(int *)(param_1 + 0x84) = (int)param_2;
  *(undefined4 *)(param_1 + 0x88) = param_3;
  if (param_2 != 0) {
    FUN_0018bb70(*(undefined4 *)(param_1 + 0x78),(int)param_2,param_3,0,((int)D_00342CD0),
                 *(int *)(param_1 + 0x7c) + *(int *)(param_1 + 0x8c));
    return;
  }
  return;
}

// MATCH func_001568F8
void FUN_001568f8(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_00156928
void FUN_00156928(int param_1,int param_2)

{
  *(int *)(param_1 + 0x10) = param_2 + 8;
  return;
}

// MATCH func_00156D38
void FUN_00156d38(int param_1,int param_2,undefined4 param_3)

{
  *(int *)(param_1 + 0xe0) = (int)param_2;
  *(undefined4 *)(param_1 + 0xe4) = param_3;
  if (param_2 != 0) {
    FUN_0018bb70(*(undefined4 *)(param_1 + 0xd8),(int)param_2,param_3,0,((int)D_00342CD0),
                 (int)*(short *)(param_1 + 0xdc) + *(int *)(param_1 + 0xe8));
    return;
  }
  return;
}

// MATCH func_00158E70
void FUN_00158e70(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 0x13c);
  if (iVar1 != 0) {
    FUN_00158af8(param_1,*(undefined4 *)(iVar1 + 0x14),*(undefined2 *)(iVar1 + 0xc),0);
    iVar1 = *(int *)((int)param_1 + 0x13c);
    FUN_00158af8(param_1,*(undefined4 *)(iVar1 + 0x18),*(undefined2 *)(iVar1 + 0xe),1);
    return;
  }
  return;
}
