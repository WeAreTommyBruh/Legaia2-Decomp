/* _unknown_after_clas_min: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

float FUN_0015fb58(float param_1,int param_2);
undefined4 flare_0015ec58(int param_1);
undefined4 flare_0015ec88(int param_1);
undefined4 flare_0015ec90(int param_1);
undefined4 flare_0015ec98(int param_1);
undefined4 flare_0015eca0(int param_1);
undefined4 flare_0015eca8(int param_1);

// MATCH func_002A8820
void FUN_002a8820(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = flare_0015ec58(param_1 + 0x1b0);
  *param_2 = uVar1;
  return;
}

// MATCH func_002A8890
void FUN_002a8890(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  uVar1 = flare_0015eca0(param_1 + 0x1b0);
  *param_2 = uVar1;
  uVar1 = flare_0015eca8(param_1 + 0x1b0);
  *param_3 = uVar1;
  return;
}

// MATCH func_002A88E8
void FUN_002a88e8(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  param_1 = param_1 + 0x1b0;
  uVar1 = flare_0015ec88(param_1);
  *param_2 = uVar1;
  uVar1 = flare_0015ec90(param_1);
  *param_3 = uVar1;
  uVar1 = flare_0015ec98(param_1);
  *param_4 = uVar1;
  return;
}

// MATCH func_002A89A8
void FUN_002a89a8(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  param_1[1] = 0;
  return;
}

// MATCH func_002A8F30
void FUN_002a8f30(float *param_1)

{
  float fVar1;
  
  fVar1 = (float)FUN_0015fb58(param_1[4],0);
  param_1[1] = fVar1 * param_1[5];
  fVar1 = (float)FUN_0015fb58(param_1[4],1);
  param_1[2] = fVar1 * param_1[5];
  fVar1 = (float)FUN_0015fb58(param_1[3],0);
  *param_1 = fVar1 * param_1[2];
  fVar1 = (float)FUN_0015fb58(param_1[3],1);
  param_1[2] = fVar1 * param_1[2];
  return;
}
