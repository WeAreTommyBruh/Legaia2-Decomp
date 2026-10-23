/* n__unknown_after_nayuwin2_fnoscheduleinsns_fexceptions: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fno-schedule-insns -fexceptions
#include "../ghidra.h"

extern int D_0034365C[];
int FUN_001b4738(char param_1, char param_2);

#define DAT_0034365c (D_0034365C[0])
// MATCH func_001B4708
void FUN_001b4708(undefined1 param_1,undefined1 param_2,undefined8 param_3,undefined8 param_4,
                 undefined4 param_5)

{
  DAT_0034365c = param_5;
  FUN_001b4738(param_1,param_2);
  return;
}
#undef DAT_0034365c
