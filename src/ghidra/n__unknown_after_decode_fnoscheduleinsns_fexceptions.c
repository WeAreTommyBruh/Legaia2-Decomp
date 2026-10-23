/* n__unknown_after_decode_fnoscheduleinsns_fexceptions: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fno-schedule-insns -fexceptions
#include "../ghidra.h"

void FUN_00190fe0(void);
void FUN_002d5368(void);
undefined4 FUN_002d53f0(uint param_1);

// MATCH func_00191070
void FUN_00191070(undefined4 *param_1)

{
  FUN_00190fe0();
  FUN_002d53f0(0);
  FUN_002d53f0(1);
  FUN_002d5368();
  param_1[0x14] = 0;
  *param_1 = 0;
  param_1[0xb] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0x10] = 0;
  param_1[0x15] = 0;
  param_1[0x13] = 0;
  return;
}
