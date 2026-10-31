/* ggint: Ghidra output with hand fixes (narrowed 64-bit types, data addresses as symbols); compiles to the original bytes. */
// cflags: -fexceptions
#include "../ghidra.h"
extern char D_00320E20[]; void func_00188400(void);
bool FUN_00187068(int param_1);
bool FUN_0024cdd0(int *param_1, int param_2, int param_3);
void srivus_00188980(int param_1);
// MATCH func_00188C70
void srivus_00188c70(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = (int)param_1;
  if (*(int *)(iVar3 + 0x834) == 0) {
    uVar2 = 0;
    puVar1 = (undefined4 *)(*(int *)(iVar3 + 0x4870) + 0x800);
    do {
      *puVar1 = 0;
      uVar2 = uVar2 + 1;
      puVar1 = puVar1 + 0x204;
    } while (uVar2 < 4);
    iVar3 = *(int *)(iVar3 + 0x82c);
  }
  else {
    iVar3 = *(int *)(iVar3 + 0x82c);
  }
  if (iVar3 < 6) {
    srivus_00188980(param_1);
    FUN_0024cdd0((int *)D_00320E20,(int)func_00188400,param_1);
  }
  FUN_00187068(param_1);
  return;
}
