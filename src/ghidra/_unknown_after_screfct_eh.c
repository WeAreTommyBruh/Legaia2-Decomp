/* _unknown_after_screfct_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern int D_0043E538[];
void FUN_001809b8(void);
void FUN_00186ac0(void);

#define DAT_0043e538 (D_0043E538[0])
// MATCH func_00185238
int FUN_00185238(int param_1)

{
  *(undefined **)((int)param_1 + 0xc) = &DAT_0043e538;
  FUN_001809b8();
  return param_1;
}
#undef DAT_0043e538

// MATCH func_00186A68
undefined8 FUN_00186a68(undefined8 param_1)

{
  FUN_00186ac0();
  return param_1;
}
