/* _unknown_after_roulette_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern uint D_004A132C;
extern uint D_004A1334;
undefined4 FUN_00172908(int param_1);
void FUN_00172aa0(void);

// MATCH func_00172958
void FUN_00172958(void)

{
  FUN_00172908(D_004A1334);
  return;
}

// MATCH func_00172978
void FUN_00172978(void)

{
  FUN_00172908(D_004A132C);
  return;
}

// MATCH func_00173AC0
void FUN_00173ac0(int param_1)

{
  FUN_00172aa0();
  *(undefined4 *)(param_1 + 0x158) = 0;
  *(undefined4 *)(param_1 + 0x154) = *(undefined4 *)(param_1 + 0x150);
  return;
}
