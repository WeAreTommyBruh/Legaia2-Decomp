/* _unknown_after_slasteg: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_00456878[];
void FUN_00216cc0(void);

#define DAT_00456878 (D_00456878[0])
// MATCH func_00218B68
void FUN_00218b68(int param_1)

{
  *(undefined **)(param_1 + 0x844) = &DAT_00456878;
  FUN_00216cc0();
  return;
}
#undef DAT_00456878
