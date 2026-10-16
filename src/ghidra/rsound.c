/* rsound: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"


// MATCH func_0010C780
uint rsound_0010c780(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x574);
  if (-1 < (int)uVar1) {
    uVar1 = (uint)(0 < (int)uVar1);
  }
  return uVar1;
}
