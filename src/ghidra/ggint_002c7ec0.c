/* ggint: Ghidra output with 64-bit parameter types narrowed to int; compiles to the original bytes. */
#include "../ghidra.h"

void FUN_002c86f0(int param_1, int param_2, int);
void FUN_002c8800(int param_1, int param_2, int param_3, int);
// MATCH func_002C7EC0
void FUN_002c7ec0(int param_1,int param_2,int param_3)

{
  int uVar1;
  int uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = (int)param_1;
  if (param_3 != 0) {
    if (*(int *)(iVar4 + 0x174) == 3) {
      if (*(int *)(iVar4 + 0x150) == 3) {
        uVar1 = *(int *)(iVar4 + 0x1c4);
      }
      else {
        uVar1 = *(int *)(iVar4 + 0x1b8);
      }
      FUN_002c86f0(param_1,uVar1,param_2 + -1);
      iVar3 = *(int *)(iVar4 + 0xf8);
      goto LAB_002c7f30;
    }
    if (*(int *)(iVar4 + 0x150) == 3) {
      uVar1 = *(int *)(iVar4 + 0x1d4);
      uVar2 = *(int *)(iVar4 + 0x1e4);
    }
    else {
      uVar1 = *(int *)(iVar4 + 0x1c8);
      uVar2 = *(int *)(iVar4 + 0x1d8);
    }
    FUN_002c8800(param_1,uVar1,uVar2,param_2 + -1);
  }
  iVar3 = *(int *)(iVar4 + 0xf8);
LAB_002c7f30:
  if (iVar3 == 1) {
    *(int *)(iVar4 + 0xf8) = 2;
  }
  return;
}
