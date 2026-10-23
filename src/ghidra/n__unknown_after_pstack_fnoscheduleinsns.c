/* n__unknown_after_pstack_fnoscheduleinsns: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fno-schedule-insns
#include "../ghidra.h"


// MATCH func_0025DE30
void FUN_0025de30(float param_1,int param_2,undefined4 param_3)

{
  if (168.0f < param_1) {
    if (param_1 < *(float *)(param_2 + 0x20)) {
      *(undefined4 *)(param_2 + 0x24) = param_3;
      *(float *)(param_2 + 0x20) = param_1;
      return;
    }
  }
  else if (56.0f <= param_1) {
    *(undefined4 *)(param_2 + 0x1c) = 1;
  }
  return;
}
