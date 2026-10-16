/* _unknown_after_pchboss: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"


// MATCH func_002194E0
void FUN_002194e0(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x260) != param_2) {
    *(int *)(param_1 + 0x260) = param_2;
    *(undefined4 *)(param_1 + 0x25c) = 1;
    *(undefined4 *)(param_1 + 0x268) = 0;
  }
  return;
}

// MATCH func_0021A540
void FUN_0021a540(float param_1,int param_2,float *param_3,float *param_4)

{
  float fVar1;
  
  if (1.0f < param_1) {
    param_1 = 1.0f;
  }
  fVar1 = 1.0f - param_1;
  *(float *)(param_2 + 0x18) = *param_4 * param_1 + *param_3 * fVar1;
  *(float *)(param_2 + 0x1c) = param_4[1] * param_1 + param_3[1] * fVar1;
  *(float *)(param_2 + 0x20) = param_4[2] * param_1 + param_3[2] * fVar1;
  *(float *)(param_2 + 0x44) = param_4[3] * param_1 + param_3[3] * fVar1;
  *(float *)(param_2 + 0x48) = param_4[4] * param_1 + param_3[4] * fVar1;
  *(float *)(param_2 + 0x4c) = param_4[5] * param_1 + param_3[5] * fVar1;
  return;
}
