/* _unknown_after_decode_1: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

bool FUN_00194900(void);
void FUN_002d41a8(undefined8 param_1, undefined8 param_2, undefined8 param_3);
void FUN_002d5518(uint param_1, ulong param_2, long param_3);

// MATCH func_00191618
void FUN_00191618(undefined8 param_1)

{
  FUN_002d41a8(0,param_1,param_1);
  FUN_002d41a8(1,param_1,param_1);
  return;
}

// MATCH func_00191658
void FUN_00191658(undefined8 param_1)

{
  FUN_002d5518(1,param_1,0);
  FUN_002d5518(2,0,param_1);
  return;
}

// MATCH func_00194988
int FUN_00194988(int *param_1)

{
  int iVar1;
  int lVar2;
  
  lVar2 = FUN_00194900();
  if (lVar2 == 0) {
    iVar1 = *param_1 + param_1[2] * 0x195000;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}
