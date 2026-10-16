/* pchjob0: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_00216a30(int *param_1);
void FUN_00216b18(int param_1);

// MATCH func_002076E0
void pchjob0_002076e0(int param_1)

{
  FUN_00216a30(*(undefined4 *)(param_1 + 0xd8));
  FUN_00216b18(*(undefined4 *)(param_1 + 0xd8));
  return;
}

// MATCH func_00207710
void pchjob0_00207710(int param_1)

{
  if (*(int *)(param_1 + 0x18c) == 0) {
    *(undefined4 *)(param_1 + 0x18c) = 1;
  }
  return;
}
