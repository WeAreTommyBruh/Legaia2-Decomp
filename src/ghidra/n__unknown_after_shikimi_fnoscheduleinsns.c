/* n__unknown_after_shikimi_fnoscheduleinsns: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fno-schedule-insns
#include "../ghidra.h"

void clas_min_002a6160(void);

// MATCH func_002BEA30
void FUN_002bea30(int param_1)

{
  if (*(int *)(param_1 + 4) == 3) {
    *(undefined4 *)(param_1 + 4) = 4;
  }
  clas_min_002a6160();
  return;
}
