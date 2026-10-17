/* darts_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

undefined4 FUN_00164148(void);
void darts_0016f508(int param_1, int param_2);

// MATCH func_0016F5D8
int darts_0016f5d8(int param_1)

{
  int lVar1;
  
  lVar1 = FUN_00164148();
  if ((lVar1 != 0) && (*(int *)(param_1 + 0x70) != 0)) {
    darts_0016f508(*(int *)(param_1 + 0x70),*(undefined4 *)(param_1 + 0x6c));
  }
  return lVar1;
}
