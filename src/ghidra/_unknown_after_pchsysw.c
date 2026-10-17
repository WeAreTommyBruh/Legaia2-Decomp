/* _unknown_after_pchsysw: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void MemFree(void *ptr);

// MATCH func_0012FFD8
void FUN_0012ffd8(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((param_2 < *param_1) && (iVar1 = param_2 * 0x40 + param_1[1], *(int *)(iVar1 + 0x10) != 0)) {
    *(undefined4 *)(iVar1 + 0x38) = param_3;
  }
  return;
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
