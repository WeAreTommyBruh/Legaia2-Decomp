/* _unknown_after_pchspplate_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern int D_0043FED0[];
extern int D_00455D38[];
undefined8 FUN_00202840(undefined8 param_1);
undefined4 FUN_00216418(undefined4 *param_1);
void FUN_00216520(int param_1, int param_2);

// MATCH func_00216B18
void FUN_00216b18(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  if (iVar2 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 4);
    while( true ) {
      FUN_00216520(iVar2,uVar1);
      iVar2 = FUN_00216418(iVar2);
      if (iVar2 == 0) break;
      uVar1 = *(undefined4 *)(param_1 + 4);
    }
  }
  return;
}

#define DAT_0043fed0 (D_0043FED0[0])
#define DAT_00455d38 (D_00455D38[0])
// MATCH func_00216C40
int FUN_00216c40(int param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(undefined **)(iVar1 + 0x844) = &DAT_0043fed0;
  FUN_00202840(iVar1 + 0x18);
  *(undefined4 *)(iVar1 + 0x860) = 0;
  *(undefined **)(iVar1 + 0x844) = &DAT_00455d38;
  *(undefined4 *)(iVar1 + 0x86c) = 0;
  *(undefined4 *)(iVar1 + 0x874) = 0;
  *(undefined4 *)(iVar1 + 0x870) = 0;
  *(undefined4 *)(iVar1 + 0x884) = 0;
  *(undefined4 *)(iVar1 + 0x880) = 0;
  *(undefined4 *)(iVar1 + 0x87c) = 0;
  *(undefined4 *)(iVar1 + 0x878) = 0;
  *(undefined4 *)(iVar1 + 0x888) = 0;
  *(undefined4 *)(iVar1 + 0x898) = 0;
  *(undefined4 *)(iVar1 + 0x894) = 0;
  *(undefined4 *)(iVar1 + 0x890) = 0;
  *(undefined4 *)(iVar1 + 0x88c) = 0;
  *(undefined4 *)(iVar1 + 0x868) = 0;
  return param_1;
}
#undef DAT_0043fed0
#undef DAT_00455d38
