/* _unknown_after_sdiva: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_00456330[];
undefined8 FUN_00216c40(void);
void FUN_00216cc0(void);

#define DAT_00456330 (D_00456330[0])
// MATCH func_002186C0
int FUN_002186c0(int param_1)

{
  FUN_00216c40();
  *(undefined **)((int)param_1 + 0x844) = &DAT_00456330;
  return param_1;
}
#undef DAT_00456330

#define DAT_00456330 (D_00456330[0])
// MATCH func_002186F8
void FUN_002186f8(int param_1)

{
  *(undefined **)(param_1 + 0x844) = &DAT_00456330;
  FUN_00216cc0();
  return;
}
#undef DAT_00456330
