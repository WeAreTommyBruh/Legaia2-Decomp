/* n__unknown_after_shikimi_fnoscheduleinsns_fexceptions: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fno-schedule-insns -fexceptions
#include "../ghidra.h"

void FUN_002cf7b0(undefined4 *param_1, int param_2, int param_3);

// MATCH func_002CF668
void FUN_002cf668(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *piVar3;
  
  FUN_002cf7b0(param_1,2,3);
  piVar3 = (int *)param_1;
  puVar1 = (undefined4 *)*piVar3;
  uVar2 = 0x50000000;
  if (param_2 != 0) {
    uVar2 = 0xd0000000;
  }
  *piVar3 = (int)(puVar1 + 1);
  piVar3[3] = (int)puVar1;
  *puVar1 = uVar2;
  return;
}
