/* _unknown_after_noribs_eh_990721: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
// compiler: 990721
#include "../ghidra.h"

extern char D_00342D00[];
void FUN_00155520(int param_1, int);

// MATCH func_001548D8
void FUN_001548d8(int *param_1)

{
  int iVar1;
  
  for (iVar1 = *param_1; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x80)) {
    FUN_00155520(((int)D_00342D00),iVar1);
  }
  *param_1 = 0;
  return;
}
