/* mizuki: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"


// MATCH func_001DFDB0
int mizuki_001dfdb0(int param_1)

{
  return *(int *)(param_1 + 0xa8) * *(int *)(param_1 + 0xac);
}

// MATCH func_001DFEE0
void mizuki_001dfee0(float param_1,int param_2)

{
  *(float *)(param_2 + 0xcc) = *(float *)(param_2 + 0xcc) + param_1;
  return;
}
