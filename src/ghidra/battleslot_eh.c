/* battleslot_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

undefined1 pachislot_00164cd8(void);

// MATCH func_00294BB0
int battleslot_00294bb0(void)

{
  int iVar1;
  
  iVar1 = pachislot_00164cd8();
  return iVar1 + -1;
}
