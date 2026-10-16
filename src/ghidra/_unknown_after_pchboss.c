/* _unknown_after_pchboss: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"


// MATCH func_002194E0
void FUN_002194e0(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x260) != param_2) {
    *(int *)(param_1 + 0x260) = param_2;
    *(undefined4 *)(param_1 + 0x25c) = 1;
    *(undefined4 *)(param_1 + 0x268) = 0;
  }
  return;
}
