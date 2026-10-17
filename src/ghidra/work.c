/* work: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_00108b80(int param_1);
byte * FUN_0022d7b8(undefined8 param_1, int param_2);
void FUN_0022f0f8(int param_1);
void func_00246140(void);
void work_002461e0(void);
undefined4 work_00246810(int param_1);

// MATCH func_00245F98
void work_00245f98(int param_1,int param_2)

{
  func_00246140();
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}

// MATCH func_00246340
void work_00246340(int param_1)

{
  work_002461e0();
  work_00246810(param_1);
  return;
}

// MATCH func_00246490
void work_00246490(int param_1)

{
  if (*(int *)(param_1 + 0x154) != 0) {
    *(undefined2 *)(*(int *)(param_1 + 0x154) + 0x3000) = 0;
  }
  return;
}

// MATCH func_002464A8
void work_002464a8(undefined8 param_1)

{
  FUN_0022d7b8(param_1,0);
  return;
}

// MATCH func_00246800
void work_00246800(int param_1)

{
  *(code **)(param_1 + 0x1a0) = FUN_0022f0f8;
  return;
}

// MATCH func_002468D8
void work_002468d8(int param_1)

{
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffbff;
  return;
}
