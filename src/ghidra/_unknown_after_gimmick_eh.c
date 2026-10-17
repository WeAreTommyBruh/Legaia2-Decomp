/* _unknown_after_gimmick_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

void FUN_002beea0(int param_1);
void clas_min_002a0190(int param_1);

// MATCH func_002ADF58
void FUN_002adf58(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)param_2;
  piVar1[0x7c] = piVar1[0x7c] | 0x20000;
  FUN_002beea0(param_2);
  clas_min_002a0190(param_2);
  *(undefined2 *)(param_1 + 0x24) = *(undefined2 *)(*piVar1 + 0xbc);
  return;
}
