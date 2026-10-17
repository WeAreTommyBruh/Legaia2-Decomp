/* _unknown_after_slasteg_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern int D_00456878[];
undefined8 FUN_00216c40(void);

#define DAT_00456878 (D_00456878[0])
// MATCH func_00218B30
int FUN_00218b30(int param_1)

{
  FUN_00216c40();
  *(undefined **)((int)param_1 + 0x844) = &DAT_00456878;
  return param_1;
}
#undef DAT_00456878
