/* _unknown_after_multi: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern uint D_004A12A4;
extern uint * D_004A1A20;
extern int D_0053FEA0[];
void FUN_0010f000(void);
bool battle_00126058(void);
void battle_001260b0(void);

// MATCH func_00116A90
void FUN_00116a90(float param_1,float param_2,float param_3,float *param_4)

{
  *param_4 = *param_4 * param_1;
  param_4[1] = param_4[1] * param_2;
  param_4[2] = param_4[2] * param_3;
  return;
}

// MATCH func_001171B8
void FUN_001171b8(char *param_1,char param_2,int param_3)

{
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *param_1 = param_2;
    param_1 = param_1 + 1;
  }
  return;
}

#define DAT_0053fea0 (D_0053FEA0[0])
// MATCH func_001171F0
void FUN_001171f0(void)

{
  D_004A1A20 = &DAT_0053fea0;
  return;
}
#undef DAT_0053fea0

// MATCH func_00117200
void FUN_00117200(void)

{
  int lVar1;
  
  lVar1 = battle_00126058();
  if (lVar1 == 0) {
    battle_001260b0();
    D_004A12A4 = 0x12;
    FUN_0010f000();
    return;
  }
  return;
}
