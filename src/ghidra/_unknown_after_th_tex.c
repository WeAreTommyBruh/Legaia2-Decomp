/* _unknown_after_th_tex: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void MemFree(void *ptr);

// MATCH func_0022D068
void FUN_0022d068(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_0022D788
int FUN_0022d788(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_3 < 0) {
    param_3 = 0;
  }
  iVar1 = *(ushort *)(param_1 + *(int *)(param_2 * 4 + param_1 + 4) + 2) - 1;
  if (param_3 <= iVar1) {
    iVar1 = param_3;
  }
  return iVar1;
}
