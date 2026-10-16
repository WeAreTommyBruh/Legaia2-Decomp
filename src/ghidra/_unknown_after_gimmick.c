/* _unknown_after_gimmick: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"


// MATCH func_002ADFB0
void FUN_002adfb0(int param_1,int param_2)

{
  undefined2 uVar1;
  
  if (*(short *)(param_1 + 0x26) != -1) {
    uVar1 = *(undefined2 *)(param_1 + 0x24);
    *(undefined4 *)(param_2 + 0xc0) = *(undefined4 *)(param_1 + 0x20);
    *(undefined2 *)(param_2 + 0xbc) = uVar1;
  }
  return;
}
