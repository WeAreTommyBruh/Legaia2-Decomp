/* ikumin: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void ikumin_001f7970(void);
void ikumin_001f79c8(int param_1);

// MATCH func_001F7280
int ikumin_001f7280(int param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(undefined4 *)(iVar1 + 4) = 0;
  *(undefined1 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(undefined4 *)(iVar1 + 0xb0) = 0;
  *(undefined4 *)(iVar1 + 0xb4) = 0;
  *(undefined4 *)(iVar1 + 0xb8) = 0;
  *(undefined4 *)(iVar1 + 0xbc) = 0;
  *(undefined4 *)(iVar1 + 0xc0) = 0;
  *(undefined4 *)(iVar1 + 0xc4) = 0;
  *(undefined4 *)(iVar1 + 200) = 0;
  *(undefined4 *)(iVar1 + 0xcc) = 0;
  *(undefined4 *)(iVar1 + 0xd0) = 0;
  *(undefined4 *)(iVar1 + 0xd4) = 0;
  return param_1;
}

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

// MATCH func_001F7468
void ikumin_001f7468(int param_1,int param_2)

{
  *(bool *)((int)param_1 + 8) = param_2 == 1;
  ikumin_001f7970();
  ikumin_001f79c8(param_1);
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
