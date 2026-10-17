/* _unknown_after_modelpkt: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_00314C20[];
extern char D_00342CD0[];
void FUN_0018fd98(int param_1, uint *param_2, uint param_3, int param_4, uint param_5);
void MemFree(void *ptr);

// MATCH func_001808C0
void FUN_001808c0(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
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

#define DAT_00342cd0 (D_00342CD0[0])
#define DAT_00314c20 (D_00314C20[0])
// MATCH func_00180BD0
void FUN_00180bd0(int param_1,int param_2)

{
  *(int *)(param_1 + 0x10) = (int)param_2;
  if (param_2 == ((int)D_00342CD0)) {
    *(undefined8 **)(param_1 + 0x8c) = &DAT_00342cd0;
    return;
  }
  *(undefined8 **)(param_1 + 0x8c) = &DAT_00314c20;
  return;
}
#undef DAT_00342cd0
#undef DAT_00314c20
