/* _unknown_after_modelpkt: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_00342CD0[];
extern int D_0043E4F8[];
extern int D_0043E538[];
void FUN_001809b8(int param_1, undefined4 param_2, undefined4 param_3);
void FUN_0018fd98(int param_1, uint *param_2, uint param_3, int param_4, uint param_5);
void FUN_00190328(int param_1);
void FUN_00190420(int param_1);
void MemFree(void *ptr);
undefined8 clas_min_002a4f30(undefined8 param_1);

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

// MATCH func_00180950
void FUN_00180950(int param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(undefined4 *)(iVar1 + 0x14) = 1;
  *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar1 + 8);
  FUN_0018fd98(param_1,*(undefined4 *)(iVar1 + 8),0x10,0,0);
  return;
}

#define DAT_0043e538 (D_0043E538[0])
#define DAT_0043e4f8 (D_0043E4F8[0])
#define DAT_00342cd0 (D_00342CD0[0])
// MATCH func_00180B28
int FUN_00180b28(int param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(undefined **)(iVar1 + 0xc) = &DAT_0043e538;
  FUN_001809b8(param_1,0,0x78);
  *(undefined **)(iVar1 + 0xc) = &DAT_0043e4f8;
  *(int **)(iVar1 + 0x10) = &DAT_00342cd0;
  clas_min_002a4f30(iVar1 + 0x14);
  return param_1;
}
#undef DAT_0043e538
#undef DAT_0043e4f8
#undef DAT_00342cd0
