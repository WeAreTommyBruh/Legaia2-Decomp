/* _unknown_after_pchsysw_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

int FUN_0018b508(undefined1 *param_1, undefined8 param_2);
int FileGetSize(char *path);
void pchsysw_0012f840(void);

// MATCH func_00130260
void FUN_00130260(int param_1,int param_2)

{
  pchsysw_0012f840();
  *(undefined4 *)(param_2 * 0x40 + *(int *)(param_1 + 4) + 0x10) = 0;
  return;
}

// MATCH func_00131230
undefined4 FUN_00131230(undefined4 *param_1,int param_2)

{
  int iVar1;
  int lVar2;
  undefined4 auStack_40 [4];
  
  *param_1 = 0;
  auStack_40[0] = 0;
  iVar1 = FileGetSize((char *)param_2);
  if (0 < iVar1) {
    lVar2 = FUN_0018b508(param_2,auStack_40);
    *param_1 = (int)lVar2;
    if (lVar2 == 0) {
      auStack_40[0] = 0;
    }
  }
  return auStack_40[0];
}
