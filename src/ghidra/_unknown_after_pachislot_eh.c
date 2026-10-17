/* _unknown_after_pachislot_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

void FUN_00164608(int *param_1);

// MATCH func_0016C8F8
void FUN_0016c8f8(int param_1)

{
  FUN_00164608(param_1 + 0x30);
  (**(code **)(param_1 + 0x3c))(param_1 + *(short *)(param_1 + 0x38));
  return;
}
