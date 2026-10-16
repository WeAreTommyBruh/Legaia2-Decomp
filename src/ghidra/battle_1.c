/* battle_1: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern uint D_004A13D4;
extern uint D_004A1A2C;
extern uint D_004A1A9C;
extern uint D_004A6C40;
extern uint D_004A6C44;
extern uint D_004A6E88;
void FUN_001100b8(void);
void FUN_001aa530(void);

// MATCH func_0012A948
void battle_0012a948(void)

{
  D_004A6C40 = 0;
  D_004A6C44 = 0;
  D_004A6E88 = 0;
  return;
}

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
