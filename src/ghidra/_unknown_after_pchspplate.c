/* _unknown_after_pchspplate: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_00249108(void);
void FUN_002491d8(void);
void MemFree(void *ptr);
void sammon_002275b8(undefined8 param_1);

// MATCH func_00216BB0
void FUN_00216bb0(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_00216E88
void FUN_00216e88(undefined8 param_1)

{
  FUN_00249108();
  sammon_002275b8(param_1);
  FUN_002491d8();
  return;
}
