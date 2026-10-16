/* _unknown_after_batread: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"


// MATCH func_00220B48
void FUN_00220b48(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1b44) + 1;
  *(int *)(param_1 + 0x1b44) = iVar1;
  if (0x3f < iVar1) {
    *(undefined4 *)(param_1 + 0x1b44) = 0;
  }
  *(int *)(param_1 + 0x1b40) = *(int *)(param_1 + 0x1b40) + 1;
  return;
}
