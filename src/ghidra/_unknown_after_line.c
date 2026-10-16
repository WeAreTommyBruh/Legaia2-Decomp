/* _unknown_after_line: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_00249108(void);
void FUN_002491d8(void);
void battle_00126830(undefined8 param_1,undefined8 param_2);
void sammon_002275b8(undefined8 param_1);

// MATCH func_00187158
void FUN_00187158(undefined8 param_1)

{
  FUN_00249108();
  sammon_002275b8(param_1);
  FUN_002491d8();
  return;
}

// MATCH func_00187188
void FUN_00187188(void)

{
  battle_00126830(0,0);
  return;
}
