/* ikumi: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"


// MATCH func_0019B818
float ikumi_0019b818(char *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = 0.0f;
  fVar3 = 1.0f;
  while (param_2 = param_2 + -1, -1 < param_2) {
    if ((param_2 == 0) && (*param_1 == '-')) {
      fVar1 = -fVar1;
    }
    else if (param_1[param_2] == '.') {
      fVar1 = fVar1 / fVar3;
      fVar3 = 1.0f;
    }
    else {
      fVar2 = (float)(param_1[param_2] + -0x30) * fVar3;
      fVar3 = fVar3 * 10.0f;
      fVar1 = fVar1 + fVar2;
    }
  }
  return fVar1;
}
