/* _unknown_after_pstack_eh_1: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

undefined1 FUN_00251070(void);
undefined1 FUN_00251090(void);
undefined1 FUN_002510b0(void);

// MATCH func_00251E88
bool FUN_00251e88(void)

{
  uint uVar1;
  
  uVar1 = FUN_00251070();
  return (uVar1 & 0x60) != 0;
}

// MATCH func_00251ED8
bool FUN_00251ed8(void)

{
  uint uVar1;
  
  uVar1 = FUN_00251090();
  return (uVar1 & 0x60) != 0;
}

// MATCH func_00251F00
bool FUN_00251f00(void)

{
  uint uVar1;
  
  uVar1 = FUN_002510b0();
  return (uVar1 & 0x60) != 0;
}
