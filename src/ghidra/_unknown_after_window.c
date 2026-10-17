/* _unknown_after_window: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern uint D_004A3828;
undefined4 DiskReady(int param_1);
undefined4 FUN_002cbb80(int param_1);

// MATCH func_00196FD8
void FUN_00196fd8(void)

{
  FUN_002cbb80(0);
  DiskReady(0);
  return;
}

// MATCH func_001972D0
void FUN_001972d0(void)

{
  D_004A3828 = D_004A3828 + (0x14996fe < D_004A3828 ^ 1);
  return;
}
