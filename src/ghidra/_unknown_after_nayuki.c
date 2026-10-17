/* _unknown_after_nayuki: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_0018fd98(int param_1, uint *param_2, uint param_3, int param_4, uint param_5);
undefined1 akari_001e24d0(void);
bool akari_001e2588(int param_1);
void mizuki_001e0ce8(int param_1);

// MATCH func_001DF790
void FUN_001df790(int param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(undefined4 *)(iVar1 + 0x14) = 1;
  *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar1 + 8);
  FUN_0018fd98(param_1,*(undefined4 *)(iVar1 + 8),0x10,0,0);
  return;
}

// MATCH func_001DF860
void FUN_001df860(int param_1)

{
  int lVar1;
  
  lVar1 = akari_001e24d0();
  if ((lVar1 != 0) && (lVar1 = akari_001e2588(param_1), lVar1 == 1)) {
    mizuki_001e0ce8(param_1);
    return;
  }
  return;
}
