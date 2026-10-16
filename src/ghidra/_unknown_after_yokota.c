/* _unknown_after_yokota: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"


// MATCH func_00241C98
undefined4 * FUN_00241c98(undefined4 *param_1,uint param_2)

{
  for (; ((uint)param_1 & 0xf) >> 2 != param_2; param_1 = param_1 + 1) {
    *param_1 = 0;
  }
  return param_1;
}

// MATCH func_00241CC8
undefined1 * FUN_00241cc8(undefined1 *param_1,uint param_2)

{
  for (; ((uint)param_1 & 0xf) != param_2; param_1 = param_1 + 1) {
    *param_1 = 0;
  }
  return param_1;
}

// MATCH func_002421B8
void FUN_002421b8(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  
  param_3 = param_3 >> 2;
  while (param_3 = param_3 + -1, param_3 != -1) {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    *param_1 = uVar1;
    param_1 = param_1 + 1;
  }
  return;
}
