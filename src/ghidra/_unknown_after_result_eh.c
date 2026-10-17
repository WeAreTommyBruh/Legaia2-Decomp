/* _unknown_after_result_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern char D_0061F870[];
bool clas_min_002a1df8(int param_1, int param_2, int, int);

// MATCH func_002AF9A0
bool FUN_002af9a0(void)

{
  int lVar1;
  
  lVar1 = clas_min_002a1df8(((int)D_0061F870),0xffffffffffffffff,0,0);
  return lVar1 == 0;
}
