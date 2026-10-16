/* rouge: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"


// MATCH func_001330E0
int rouge_001330e0(int param_1)

{
  if (param_1 < 0) {
    return -param_1;
  }
  return param_1;
}
