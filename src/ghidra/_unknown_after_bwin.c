/* _unknown_after_bwin: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_00329640[];
extern uint D_004A714C;
extern uint D_004A7150;
extern uint D_004A7154;

// MATCH func_002392E0
undefined8 FUN_002392e0(void)

{
  undefined1 auStack_pad[128];
  return 0;
}

#define DAT_00329640 (D_00329640[0])
// MATCH func_002393B8
void FUN_002393b8(int param_1,undefined4 param_2)

{
  if (param_1 - 8U < 0x18) {
    (&DAT_00329640)[param_1] = param_2;
  }
  return;
}
#undef DAT_00329640

// MATCH func_0023AAC0
void FUN_0023aac0(undefined4 param_1,undefined4 param_2)

{
  D_004A714C = param_1;
  D_004A7150 = param_2;
  D_004A7154 = 1;
  return;
}
