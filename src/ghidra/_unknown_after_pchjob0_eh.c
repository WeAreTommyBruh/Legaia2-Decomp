/* _unknown_after_pchjob0_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern char D_003C0F00[];
int work_00246d88(undefined4 *param_1, undefined8 param_2);

// MATCH func_0020B360
int FUN_0020b360(undefined8 param_1,undefined4 param_2)

{
  int lVar1;
  
  lVar1 = work_00246d88(((int)D_003C0F00),param_1);
  if (lVar1 != 0) {
    *(undefined4 *)((int)lVar1 + 0xd8) = param_2;
    *(undefined2 *)((int)lVar1 + 0xae) = 0x10;
  }
  return lVar1;
}
