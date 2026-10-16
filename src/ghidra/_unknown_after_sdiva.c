/* _unknown_after_sdiva: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_00456330[];
void FUN_00216cc0(void);

#define DAT_00456330 (D_00456330[0])
// MATCH func_002186F8
void FUN_002186f8(int param_1)

{
  *(undefined **)(param_1 + 0x844) = &DAT_00456330;
  FUN_00216cc0();
  return;
}
#undef DAT_00456330
