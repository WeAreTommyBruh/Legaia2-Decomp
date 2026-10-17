/* _unknown_after_srenia_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern char D_0045BFA0[];
int FUN_0018b508(undefined1 *param_1, undefined8 param_2);

// MATCH func_0022C080
void FUN_0022c080(int param_1)

{
  undefined4 uVar1;
  undefined1 auStack_30 [16];
  
  uVar1 = FUN_0018b508(((int)D_0045BFA0),auStack_30);
  *(undefined4 *)(param_1 + 0x282c) = uVar1;
  return;
}
