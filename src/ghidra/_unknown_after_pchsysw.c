/* _unknown_after_pchsysw: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

int FUN_0018b508(undefined1 *param_1, undefined8 param_2);
int FileGetSize(char *path);
void MemFree(void *ptr);
void pchsysw_0012f840(void);

// MATCH func_0012FFD8
void FUN_0012ffd8(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((param_2 < *param_1) && (iVar1 = param_2 * 0x40 + param_1[1], *(int *)(iVar1 + 0x10) != 0)) {
    *(undefined4 *)(iVar1 + 0x38) = param_3;
  }
  return;
}

// MATCH func_00130260
void FUN_00130260(int param_1,int param_2)

{
  pchsysw_0012f840();
  *(undefined4 *)(param_2 * 0x40 + *(int *)(param_1 + 4) + 0x10) = 0;
  return;
}

// MATCH func_00131230
undefined4 FUN_00131230(undefined4 *param_1,int param_2)

{
  int iVar1;
  int lVar2;
  undefined4 auStack_40 [4];
  
  *param_1 = 0;
  auStack_40[0] = 0;
  iVar1 = FileGetSize((char *)param_2);
  if (0 < iVar1) {
    lVar2 = FUN_0018b508(param_2,auStack_40);
    *param_1 = (int)lVar2;
    if (lVar2 == 0) {
      auStack_40[0] = 0;
    }
  }
  return auStack_40[0];
}

// MATCH func_00131588
void FUN_00131588(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_001315A0
void FUN_001315a0(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}
