/* srivus: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_00231688(void);

// MATCH func_00189078
void srivus_00189078(int param_1)

{
  if ((*(uint *)(param_1 + 0x18) & 0x4000000) != 0) {
    FUN_00231688();
    return;
  }
  return;
}
