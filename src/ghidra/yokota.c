/* yokota: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void yokota_0023e010(int param_1);
void yokota_0023e1a8(float param_1, float param_2, ulong param_3, int param_4, long param_5);

// MATCH func_0023EFF8
void yokota_0023eff8(float param_1,float param_2,undefined8 param_3)

{
  yokota_0023e010(1);
  yokota_0023e1a8(param_1,param_2,0,0,0);
  yokota_0023e1a8(param_1,param_2,2,0x80,param_3);
  yokota_0023e010(0);
  return;
}

// MATCH func_0023FAC0
float yokota_0023fac0(float param_1,float param_2,float param_3)

{
  return param_1 * param_1 + param_2 * param_2 + param_3 * param_3;
}
