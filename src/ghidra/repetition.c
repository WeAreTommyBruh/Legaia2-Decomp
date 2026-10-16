/* repetition: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_001739f0(void);
void FUN_00174060(int param_1);

// MATCH func_00175EB0
undefined4 repetition_00175eb0(int param_1)

{
  if (*(short *)(param_1 + 0x170) == 1000) {
    return 1;
  }
  *(short *)(param_1 + 0x170) = *(short *)(param_1 + 0x170) + 1;
  return 0;
}

// MATCH func_00177020
void repetition_00177020(int param_1)

{
  FUN_001739f0();
  FUN_00174060(param_1 + 0x390);
  return;
}
