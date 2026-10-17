/* shuffle: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"


// MATCH func_00178688
int shuffle_00178688(int param_1)

{
  return *(int *)(*(int *)(param_1 + 0x198) * 0x60 + param_1 + 0x50) + 1;
}
