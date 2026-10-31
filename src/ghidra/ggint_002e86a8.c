/* ggint: Ghidra output with 64-bit parameter types narrowed to int; compiles to the original bytes. */
#include "../ghidra.h"

void FUN_002e7ed0(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6);
int FUN_002e8378(int param_1);
int * FUN_002e8658(int param_1, int param_2);
// MATCH func_002E86A8
void FUN_002e86a8(int param_1,int param_2)

{
  undefined4 uVar1;
  int uVar2;
  int lVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = FUN_002e8378(param_2);
  uVar1 = *(undefined4 *)(param_1 + 0x14);
  iVar5 = (int)uVar2;
  *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(iVar5 + 0x14) = uVar1;
  *(undefined4 *)(iVar5 + 0x20) = 0x80000009;
  lVar3 = FUN_002e8658(*(undefined4 *)(param_1 + 0x20),param_2);
  if (lVar3 == 0) {
    *(undefined4 *)(iVar5 + 0x24) = 0;
    *(undefined4 *)(iVar5 + 0x28) = 0;
    *(undefined4 *)(iVar5 + 0x2c) = 0;
  }
  else {
    iVar4 = (int)lVar3;
    *(int *)(iVar5 + 0x24) = iVar4;
    *(undefined4 *)(iVar5 + 0x28) = *(undefined4 *)(iVar4 + 8);
    *(undefined4 *)(iVar5 + 0x2c) = *(undefined4 *)(iVar4 + 0x14);
  }
  FUN_002e7ed0(0xffffffff80000008,uVar2,0x40,0,0,0);
  return;
}
