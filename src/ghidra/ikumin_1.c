/* ikumin_1: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

undefined4 FUN_001f60a8(undefined4 *param_1);
void ikumin_001f7220(int param_1);

// MATCH func_001F79C8
void ikumin_001f79c8(int param_1)

{
  int iVar1;
  
  for (iVar1 = *(int *)(param_1 + 0xb0); iVar1 != 0; iVar1 = FUN_001f60a8(iVar1)) {
    ikumin_001f7220(iVar1);
  }
  return;
}
