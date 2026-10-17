/* _unknown_after_disp: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_004A14B8;
extern int D_004A5128;
extern uint D_004A7094;
extern uint D_004A7098;
void FUN_0018df68(undefined4 *param_1, undefined1 (*param_2) [16]);
void FUN_0018f3d8(undefined1 (*param_1) [16], undefined1 (*param_2) [16], undefined1 (*param_3) [16]);
void FUN_0018f620(int param_1, undefined1 (*param_2) [16]);
void thunk_FUN_0018ec38(undefined1 (*param_1) [16]);

// MATCH func_00231940
void FUN_00231940(uint param_1,uint param_2)

{
  D_004A7094 = param_1 & 1;
  D_004A7098 = param_2 & 1;
  return;
}

// MATCH func_00231958
void FUN_00231958(uint param_1)

{
  D_004A7094 = param_1 & 1;
  return;
}

// MATCH func_00231B50
bool FUN_00231b50(void)

{
  return D_004A5128 != 1;
}

// MATCH func_00231F28
void FUN_00231f28(int param_1)

{
  thunk_FUN_0018ec38(0x70003f00);
  FUN_0018f620(0x70003f00,param_1);
  FUN_0018f3d8(0x70003f80,0x70003f80,0x70003f00);
  if (D_004A14B8 != 0) {
    FUN_0018df68(0x70003f40,0x70003f00);
    FUN_0018f3d8(0x70003d80,0x70003f40,0x70003d80);
    return;
  }
  return;
}
