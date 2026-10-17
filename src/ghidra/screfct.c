/* screfct: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_0043E480[];
void FUN_00180a58(int param_1);
undefined8 FUN_00180b28(void);
void thunk_FUN_001809c8(void);

// MATCH func_00181140
void screfct_00181140(int param_1)

{
  thunk_FUN_001809c8();
  FUN_00180a58(param_1 + 0x2f0);
  FUN_00180a58(param_1 + 0x330);
  FUN_00180a58(param_1 + 0x90);
  FUN_00180a58(param_1 + 0xd0);
  FUN_00180a58(param_1 + 0x110);
  FUN_00180a58(param_1 + 0x150);
  FUN_00180a58(param_1 + 400);
  FUN_00180a58(param_1 + 0x1d0);
  FUN_00180a58(param_1 + 0x210);
  FUN_00180a58(param_1 + 0x250);
  FUN_00180a58(param_1 + 0x290);
  return;
}

#define DAT_0043e480 (D_0043E480[0])
// MATCH func_00183C18
int screfct_00183c18(int param_1)

{
  FUN_00180b28();
  *(undefined **)((int)param_1 + 0xc) = &DAT_0043e480;
  return param_1;
}
#undef DAT_0043e480
