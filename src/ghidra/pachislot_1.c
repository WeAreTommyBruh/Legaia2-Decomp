/* pachislot_1: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_00108b80(int param_1);
void FUN_00164500(undefined8 param_1, uint param_2);

// MATCH func_0016C148
void pachislot_0016c148(int param_1,int param_2)

{
  FUN_00164500((int)param_1 + 0x30,2);
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}
