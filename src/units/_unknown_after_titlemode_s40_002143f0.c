// compiler: 991111-01-as210
#include "/home/tommy/src/Legaia 2 Decomp/src/ghidra.h"
int FUN_00196ff8(void);
void FUN_00214530(int param_1);
void FUN_00215e60(int param_1);
// MATCH func_002143F0
bool FUN_002143f0(int param_1)

{
  code *pcVar1;
  int iVar2;
  int lVar3;
  int iVar4;
  bool bVar5;
  int iVar6;
  
  iVar6 = (int)param_1;
  *(int *)(iVar6 + 0x28) = *(int *)(iVar6 + 0x28) + 1;
  if (*(int *)(*(int *)(iVar6 + 4) + 8) != 0) FUN_00214530(param_1);
  if (*(int *)(iVar6 + 0x24) == 0) {
    FUN_00196ff8();
    lVar3 = FUN_00196ff8();
    *(uint *)(iVar6 + 0x24) = (uint)(lVar3 == 0);
  }
  FUN_00215e60(param_1);
  if (*(int *)(iVar6 + 0x24) == 0) {
    iVar4 = *(int *)(iVar6 + 4);
  }
  else {
    pcVar1 = *(code **)(*(volatile int *)(iVar6 + 4) + 0x10);
    if (pcVar1 == (code *)0x0) {
      iVar4 = *(int *)(iVar6 + 4);
    }
    else {
      (*pcVar1)(iVar6 + *(short *)(*(int *)(iVar6 + 4) + 0xc));
      iVar4 = *(int *)(iVar6 + 4);
    }
  }
  lVar3 = (**(code **)(iVar4 + 0x18))(iVar6 + *(short *)(iVar4 + 0x14));
  iVar4 = *(int *)(iVar6 + 8) + -1;
  bVar5 = lVar3 != 0;
  *(int *)(iVar6 + 8) = iVar4;
  if ((bVar5) && (iVar4 < 1)) {
    iVar2 = *(int *)(iVar6 + 4) + 0x20;
    iVar4 = *(int *)iVar2;
    *(int *)(iVar6 + 4) = iVar2;
    if (iVar4 == 0) {
      lVar3 = (**(code **)(iVar2 + 0x18))(iVar6 + *(short *)(iVar2 + 0x14));
      do { bVar5 = lVar3 != 0; } while (0);
    }
    *(int *)(iVar6 + 8) = *(int *)(*(int *)(iVar6 + 4) + 4);
  }
  return bVar5;
}
