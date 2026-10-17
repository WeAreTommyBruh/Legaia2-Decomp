/* akari: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"


// MATCH func_001E2478
void akari_001e2478(int param_1,int param_2)

{
  *(bool *)(param_1 + 0x4c) = 0 < param_2;
  return;
}

// MATCH func_001E2488
void akari_001e2488(int param_1,int param_2)

{
  *(bool *)(param_1 + 0x4d) = 0 < param_2;
  return;
}

// MATCH func_001E2498
void akari_001e2498(int param_1,int param_2)

{
  *(bool *)(param_1 + 0x4f) = 0 < param_2;
  return;
}

// MATCH func_001E24A8
void akari_001e24a8(int param_1,int param_2)

{
  *(bool *)(param_1 + 0x4e) = 0 < param_2;
  return;
}

// MATCH func_001E2530
void akari_001e2530(int param_1)

{
  *(float *)(param_1 + 0x44) = *(float *)(param_1 + 0x44) + *(float *)(param_1 + 0x48);
  return;
}

// MATCH func_001E2628
void akari_001e2628(int param_1,int param_2)

{
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_2 + 0x30);
  return;
}
