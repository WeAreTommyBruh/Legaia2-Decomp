/* _unknown_after_work_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern uint D_004A14B8;
extern int D_004A1518;
void FUN_0018f2c0(undefined1 *param_1, undefined1 (*param_2) [16], byte *param_3);
void thunk_FUN_0018ec38(undefined1 (*param_1) [16]);

// MATCH func_00247940
void FUN_00247940(int param_1)

{
  FUN_0018f2c0(D_004A1518,param_1,D_004A1518);
  *(undefined1 *)(D_004A1518 + 3) = 0x80;
  return;
}

// MATCH func_00249390
void FUN_00249390(void)

{
  thunk_FUN_0018ec38(0x70003f80);
  thunk_FUN_0018ec38(0x70003d80);
  thunk_FUN_0018ec38(0x70003c80);
  D_004A14B8 = 0;
  return;
}
