/* _unknown_after_pochilib: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_0043C688[];
void FUN_00108b80(int param_1);
void FUN_00162f68(undefined8 param_1, uint param_2);

#define DAT_0043c688 (D_0043C688[0])
// MATCH func_00162340
void FUN_00162340(int param_1,int param_2)

{
  int iVar1;
  
  *(undefined **)((int)param_1 + 0x3c) = &DAT_0043c688;
  iVar1 = *(int *)((int)param_1 + 0x38);
  if (iVar1 != 0) {
    FUN_00162f68(iVar1,3);
  }
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}
#undef DAT_0043c688
