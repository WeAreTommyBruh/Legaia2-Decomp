/* _unknown_after_init_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

undefined * FUN_002cea48(ulong param_1);

// MATCH func_0024CDA0
void FUN_0024cda0(undefined4 *param_1,undefined8 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_002cea48(param_2);
  *param_1 = uVar1;
  return;
}
