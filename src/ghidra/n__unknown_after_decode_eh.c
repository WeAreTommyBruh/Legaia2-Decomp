/* n__unknown_after_decode_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

void FUN_00191658(undefined8 param_1);
undefined8 FUN_002d5448(uint param_1);
undefined4 FUN_002d54c8(uint param_1, uint param_2);

// MATCH func_00191018
void FUN_00191018(undefined4 *param_1)

{
  FUN_00191658(0x3c78);
  FUN_002d54c8(0,0);
  FUN_002d54c8(1,0);
  FUN_002d5448(3);
  *param_1 = 2;
  return;
}
