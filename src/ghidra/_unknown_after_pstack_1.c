/* _unknown_after_pstack_1: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

undefined4 * FUN_0024fb88(void);
undefined1 FUN_00251070(void);
undefined1 FUN_00251090(void);
undefined1 FUN_002510b0(void);

// MATCH func_00250DA0
undefined4 FUN_00250da0(void)

{
  int iVar1;
  
  iVar1 = FUN_0024fb88();
  return *(undefined4 *)(iVar1 + 0x38);
}

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
