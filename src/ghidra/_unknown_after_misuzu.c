/* _unknown_after_misuzu: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"


// MATCH func_001F5E78
int FUN_001f5e78(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1;
  *puVar1 = 0;
  puVar1[0x3e] = 0xffffff;
  puVar1[1] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[0x3f] = 0;
  return param_1;
}

// MATCH func_001F6BE8
void FUN_001f6be8(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x18) = param_2;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}
