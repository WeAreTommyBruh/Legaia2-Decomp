/* _unknown_after_sarva_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern int D_004564F8[];
undefined8 FUN_00216c40(void);

#define DAT_004564f8 (D_004564F8[0])
// MATCH func_00218900
int FUN_00218900(int param_1)

{
  FUN_00216c40();
  *(undefined **)((int)param_1 + 0x844) = &DAT_004564f8;
  return param_1;
}
#undef DAT_004564f8
