/* _unknown_after_darts: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void MemFree(void *ptr);
void darts_0016ce98(undefined8 param_1,ulong param_2);

// MATCH func_0016F768
void FUN_0016f768(long param_1)

{
  if (param_1 != 0) {
    darts_0016ce98(param_1,3);
    return;
  }
  return;
}

// MATCH func_0016F7D0
void FUN_0016f7d0(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}
