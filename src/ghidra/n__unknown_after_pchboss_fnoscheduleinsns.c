/* n__unknown_after_pchboss_fnoscheduleinsns: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fno-schedule-insns
#include "../ghidra.h"


// MATCH func_0021AE98
void FUN_0021ae98(float param_1,float param_2,int param_3,int param_4,undefined2 param_5)

{
  *(undefined2 *)(param_4 + 0xae) = param_5;
  *(int *)(param_3 + 0x12c0) = param_4;
  if (param_2 < param_1) {
    *(float *)(param_3 + 0x1554) = param_1;
  }
  else {
    *(float *)(param_3 + 0x1554) = param_2;
  }
  *(float *)(param_3 + 0x155c) = param_2;
  *(float *)(param_3 + 0x1558) = param_1;
  return;
}
