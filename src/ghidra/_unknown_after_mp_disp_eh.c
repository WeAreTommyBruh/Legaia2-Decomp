/* _unknown_after_mp_disp_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

void FUN_002ccc70(void);
int FUN_002e9bd8(int);

// MATCH func_001953F0
undefined4 FUN_001953f0(int *param_1)

{
  if (!(*param_1 == 0)) {
    FUN_002ccc70();
  }
  else {
    FUN_002e9bd8(param_1[0xc]);
  }
  return 1;
}
