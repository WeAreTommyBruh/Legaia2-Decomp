/* _unknown_start: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_002ee2c0(int param_1);

// MATCH func_001001C8
void FUN_001001c8(void)

{
  FUN_002ee2c0(0);
  return;
}

// MATCH func_00100240
void FUN_00100240(int param_1)

{
  *(undefined4 *)(param_1 + 0x2824) = 0x40;
  *(undefined4 *)(param_1 + 0x2828) = 8;
  return;
}
