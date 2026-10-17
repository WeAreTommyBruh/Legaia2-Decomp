/* _unknown_after_decode_990721: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// compiler: 990721
#include "../ghidra.h"


// MATCH func_00190E40
undefined4 FUN_00190e40(int param_1,int *param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x50004) != 0) {
    iVar1 = *(int *)(param_1 + 0x50008);
    *param_2 = param_1 + ((*(int *)(param_1 + 0x50000) - *(int *)(param_1 + 0x50004)) + iVar1) %
                         iVar1;
  }
  return *(undefined4 *)(param_1 + 0x50004);
}
