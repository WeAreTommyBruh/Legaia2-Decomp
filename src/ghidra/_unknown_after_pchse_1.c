/* _unknown_after_pchse_1: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_00108b80(int param_1);

// MATCH func_00212E90
void FUN_00212e90(int param_1,int param_2)

{
  if (*(int *)param_1 != 0) {
    FUN_00212e90(*(int *)param_1,3);
  }
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}
