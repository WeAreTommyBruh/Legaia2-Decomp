/* _unknown_after_shikimi_eh_990721: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
// compiler: 990721
#include "../ghidra.h"

long FUN_002e0328(int *param_1, undefined8 param_2, undefined8 param_3, undefined8 param_4);
long FUN_002e2478(int *param_1, undefined8 param_2, undefined8 param_3, undefined8 param_4);

// MATCH func_002DCFA8
undefined4 FUN_002dcfa8(int param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  
  if ((*(short *)(param_1 + 0xc) & 0x100) != 0) {
    FUN_002e2478(*(undefined4 *)(param_1 + 0x54),*(short *)(param_1 + 0xe),0,2);
  }
  *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) & 0xefff;
  uVar1 = FUN_002e0328(*(undefined4 *)(param_1 + 0x54),*(short *)(param_1 + 0xe),param_2,
                       param_3);
  return uVar1;
}
