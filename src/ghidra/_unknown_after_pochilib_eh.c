/* _unknown_after_pochilib_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

int FUN_001624e0(int param_1);
void FUN_00162f68(undefined8 param_1, uint param_2);
undefined8 pochilib_00161590(uint param_1, undefined8 param_2, int param_3);

// MATCH func_00161668
void FUN_00161668(int param_1,int param_2)

{
  pochilib_00161590(0,param_1,param_2);
  return;
}

// MATCH func_001623A8
void FUN_001623a8(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)param_1;
  iVar1 = piVar3[0xe];
  if (iVar1 != 0) {
    if (*piVar3 == 0) {
      piVar3[0xe] = *(int *)(iVar1 + 0xc);
      *(undefined4 *)(iVar1 + 0xc) = 0;
      FUN_00162f68(iVar1,3);
    }
    else {
      iVar2 = FUN_001624e0(param_1);
      if (iVar1 != iVar2) {
        piVar3[0xe] = *(int *)(iVar1 + 0xc);
        *(undefined4 *)(iVar1 + 0xc) = 0;
        *(int *)(iVar2 + 0xc) = iVar1;
      }
    }
  }
  return;
}
