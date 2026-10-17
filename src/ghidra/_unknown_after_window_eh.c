/* _unknown_after_window_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

void FUN_001976b8(void);
undefined4 FUN_002cc6d8(void);

// MATCH func_00196F80
void FUN_00196f80(void)

{
  FUN_002cc6d8();
  return;
}

// MATCH func_00197100
undefined4 FUN_00197100(void)

{
  FUN_001976b8();
  return 1;
}
