/* battle_1: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_00327880[];
extern uint D_004A13D4;
extern uint D_004A1A2C;
extern int D_004A1A94;
extern uint D_004A1A9C;
extern uint D_004A6C24;
extern uint D_004A6C40;
extern uint D_004A6C44;
extern int D_004A6E30;
extern uint D_004A6E88;
void FUN_001100b8(void);
void FUN_001aa530(void);
void battle_00126810(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6);
undefined4 battle_00127430(void);

// MATCH func_00126830
void battle_00126830(int param_1,int param_2)

{
  battle_00126810(param_1,param_2,8,4,8,4);
  return;
}

// MATCH func_0012A948
void battle_0012a948(void)

{
  D_004A6C40 = 0;
  D_004A6C44 = 0;
  D_004A6E88 = 0;
  return;
}

// MATCH func_0012ADF0
void battle_0012adf0(undefined4 param_1)

{
  int lVar1;
  
  lVar1 = battle_00127430();
  if (lVar1 == 0) {
    D_004A6C24 = param_1;
  }
  if (D_004A6E30 != 0) {
    *(undefined4 *)(D_004A1A94 + 0x14c) = 0;
    D_004A6E30 = 0;
  }
  return;
}

#define DAT_00327880 (D_00327880[0])
// MATCH func_0012AE58
void battle_0012ae58(void)

{
  DAT_00327880 = 0;
  return;
}
#undef DAT_00327880

// MATCH func_0012AEA8
void battle_0012aea8(int param_1)

{
  if (param_1 == 2) {
    D_004A1A9C = 0;
  }
  FUN_001aa530();
  FUN_001100b8();
  D_004A13D4 = (int)param_1;
  D_004A1A2C = 10;
  return;
}
