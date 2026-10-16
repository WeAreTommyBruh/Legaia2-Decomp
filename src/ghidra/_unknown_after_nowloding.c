/* _unknown_after_nowloding: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_00108b80(void);
undefined * FUN_002cea48(ulong param_1);

// MATCH func_00100680
void FUN_00100680(undefined4 *param_1,undefined8 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_002cea48(param_2);
  *param_1 = uVar1;
  return;
}

// MATCH func_001006F0
void FUN_001006f0(undefined8 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}
