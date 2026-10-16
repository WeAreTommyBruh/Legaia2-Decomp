/* _unknown_after_sarva: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_004564F8[];
void FUN_00216cc0(void);

#define DAT_004564f8 (D_004564F8[0])
// MATCH func_00218938
void FUN_00218938(int param_1)

{
  *(undefined **)(param_1 + 0x844) = &DAT_004564f8;
  FUN_00216cc0();
  return;
}
#undef DAT_004564f8
