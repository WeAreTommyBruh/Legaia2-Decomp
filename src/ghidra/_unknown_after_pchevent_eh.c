/* _unknown_after_pchevent_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

undefined4 FUN_00131230(void);

// MATCH func_002119E0
void FUN_002119e0(int *param_1)

{
  int lVar1;
  
  if ((*param_1 == 0) && (lVar1 = FUN_00131230(), lVar1 == 0)) {
    *param_1 = 1;
  }
  return;
}
