/* _unknown_after_noribs: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"


// MATCH func_001548C8
void FUN_001548c8(int *param_1,int param_2)

{
  *(int *)(param_2 + 0x80) = *param_1;
  *param_1 = param_2;
  return;
}
