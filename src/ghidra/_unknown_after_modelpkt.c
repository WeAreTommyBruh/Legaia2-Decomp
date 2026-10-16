/* _unknown_after_modelpkt: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_00190328(int param_1);
void FUN_00190420(int param_1);
void MemFree(void *ptr);

// MATCH func_001808B0
void FUN_001808b0(int param_1)

{
  FUN_00190420(*(undefined4 *)(param_1 + 0x78));
  return;
}

// MATCH func_001808B8
void FUN_001808b8(int param_1)

{
  FUN_00190328(*(undefined4 *)(param_1 + 0x78));
  return;
}

// MATCH func_001808C0
void FUN_001808c0(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_001808F0
void FUN_001808f0(int param_1,int param_2)

{
  *(int *)(param_1 + 0x10) = param_2 + 8;
  return;
}
