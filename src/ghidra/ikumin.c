/* ikumin: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

undefined4 FUN_001f60a8(undefined4 *param_1);
void ikumin_001f7220(int param_1);

// MATCH func_001F72C0
void ikumin_001f72c0(int param_1,int param_2)

{
  *(bool *)(param_1 + 9) = param_2 == 1;
  return;
}

// MATCH func_001F72E8
void ikumin_001f72e8(int param_1,int param_2)

{
  if (-1 < param_2) {
    *(int *)(param_1 + 0xc4) = (int)param_2;
  }
  return;
}

// MATCH func_001F72F8
void ikumin_001f72f8(int param_1,int param_2)

{
  if (-1 < param_2) {
    *(int *)(param_1 + 0xc0) = (int)param_2;
  }
  return;
}

// MATCH func_001F7588
void ikumin_001f7588(int param_1,int param_2)

{
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (*(int *)(param_1 + 0xc0) < param_2) {
    param_2 = *(int *)(param_1 + 0xc0);
  }
  *(int *)(param_1 + 0xb8) = param_2;
  return;
}

// MATCH func_001F75A8
void ikumin_001f75a8(int param_1,int param_2)

{
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (*(int *)(param_1 + 0xc4) < param_2) {
    param_2 = *(int *)(param_1 + 0xc4);
  }
  *(int *)(param_1 + 0xbc) = param_2;
  return;
}

// MATCH func_001F79C8
void ikumin_001f79c8(int param_1)

{
  int iVar1;
  
  for (iVar1 = *(int *)(param_1 + 0xb0); iVar1 != 0; iVar1 = FUN_001f60a8(iVar1)) {
    ikumin_001f7220(iVar1);
  }
  return;
}
