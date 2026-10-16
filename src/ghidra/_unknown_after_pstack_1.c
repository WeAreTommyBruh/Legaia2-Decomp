/* _unknown_after_pstack_1: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

undefined4 * FUN_0024fb88(void);

// MATCH func_00250DA0
undefined4 FUN_00250da0(void)

{
  int iVar1;
  
  iVar1 = FUN_0024fb88();
  return *(undefined4 *)(iVar1 + 0x38);
}
