/* _unknown_after_minigame: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void MemFree(void *ptr);

// MATCH func_00164578
void FUN_00164578(int *param_1,int param_2)

{
  *(int *)(param_2 + 0x5c) = *param_1;
  *(undefined4 *)(param_2 + 0x60) = *(undefined4 *)(*param_1 + 0x60);
  *(int *)(*param_1 + 0x60) = param_2;
  *(int *)(*(int *)(param_2 + 0x60) + 0x5c) = param_2;
  return;
}

// MATCH func_001646E8
bool FUN_001646e8(int *param_1)

{
  return *param_1 != *(int *)(*param_1 + 0x5c);
}

// MATCH func_00164780
void FUN_00164780(int param_1,int param_2)

{
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + param_2;
  return;
}

// MATCH func_00164790
void FUN_00164790(int param_1,int param_2)

{
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + param_2;
  return;
}

// MATCH func_001647B0
void FUN_001647b0(int param_1,int param_2)

{
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + param_2;
  return;
}

// MATCH func_001647C0
void FUN_001647c0(int param_1,int param_2)

{
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_2;
  return;
}

// MATCH func_00164878
void FUN_00164878(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}
