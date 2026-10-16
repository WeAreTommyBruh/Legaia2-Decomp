/* _unknown_after_disp: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_004A5128;
extern uint D_004A7094;
extern uint D_004A7098;
extern uint D_004A70A0;
extern uint D_004A70A4;
void FUN_002313a8(uint param_1,int param_2,int param_3,int param_4,int param_5,int param_6);

// MATCH func_00231548
void FUN_00231548(void)

{
  FUN_002313a8(1,1,0,0,0,0);
  D_004A70A0 = 0;
  D_004A70A4 = 0;
  return;
}

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
