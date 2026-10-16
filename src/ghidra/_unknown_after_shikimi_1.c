/* _unknown_after_shikimi_1: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

int __fpcmp_parts_d(uint *param_1,uint *param_2);
void __unpack_d(uint *param_1,undefined4 *param_2);

// MATCH func_002D7E48
void FUN_002d7e48(undefined8 param_1,undefined8 param_2)

{
  undefined1 auStack_70 [32];
  undefined1 auStack_50 [32];
  undefined8 uStack_30;
  undefined8 uStack_28;
  
  uStack_30 = param_1;
  uStack_28 = param_2;
  __unpack_d(&uStack_30,auStack_70);
  __unpack_d(&uStack_28,auStack_50);
  __fpcmp_parts_d(auStack_70,auStack_50);
  return;
}
