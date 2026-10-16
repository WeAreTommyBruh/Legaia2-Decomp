/* _unknown_after_nayuwin2: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_004A3830;
extern uint D_004A3C30;
void FUN_00110080(int param_1);
void FUN_001100b8(void);
void MemFree(void *ptr);

// MATCH func_001AFF48
undefined4 FUN_001aff48(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x70) = param_2;
  return 1;
}

// MATCH func_001B4B40
void FUN_001b4b40(int param_1)

{
  D_004A3830 = param_1;
  FUN_001100b8();
  FUN_00110080(5);
  D_004A3C30 = 0;
  *(undefined4 *)(param_1 + 0x88) = 4;
  return;
}

// MATCH func_001B78A8
void FUN_001b78a8(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_001B78C0
void FUN_001b78c0(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}
