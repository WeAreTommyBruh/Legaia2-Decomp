/* pchjob0: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_00216a30(int *param_1);
void FUN_00216b18(int param_1);
int pchjob0_002056a8(void);
void pchjob0_00206f38(int param_1);

// MATCH func_00204A00
int pchjob0_00204a00(int param_1)

{
  *(undefined4 *)param_1 = 0;
  return param_1;
}

// MATCH func_00205718
int pchjob0_00205718(void)

{
  int lVar1;
  int uVar2;
  
  lVar1 = pchjob0_002056a8();
  uVar2 = 0xffffffff;
  if (lVar1 != 0) {
    uVar2 = *(int *)lVar1;
  }
  return uVar2;
}

// MATCH func_00205748
int pchjob0_00205748(void)

{
  int lVar1;
  int uVar2;
  
  lVar1 = pchjob0_002056a8();
  uVar2 = 0xffffffff;
  if (lVar1 != 0) {
    uVar2 = *(int *)((int)lVar1 + 4);
  }
  return uVar2;
}

// MATCH func_002057D8
int pchjob0_002057d8(float param_1,float *param_2)

{
  return (int)((param_1 - *param_2) / param_2[6] + 0.5f);
}

// MATCH func_00205810
int pchjob0_00205810(float param_1,int param_2)

{
  return (int)((param_1 - *(float *)(param_2 + 8)) / *(float *)(param_2 + 0x18) + 0.5f);
}

// MATCH func_00206F10
void pchjob0_00206f10(int param_1)

{
  if (*(int *)(param_1 + 0xd8) == 0) {
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 8;
  }
  *(code **)(param_1 + 0x14) = pchjob0_00206f38;
  return;
}

// MATCH func_002076E0
void pchjob0_002076e0(int param_1)

{
  FUN_00216a30(*(undefined4 *)(param_1 + 0xd8));
  FUN_00216b18(*(undefined4 *)(param_1 + 0xd8));
  return;
}

// MATCH func_00207710
void pchjob0_00207710(int param_1)

{
  if (*(int *)(param_1 + 0x18c) == 0) {
    *(undefined4 *)(param_1 + 0x18c) = 1;
  }
  return;
}
