/* batread: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern uint D_004A6FC4;
extern uint D_004A6FCC;
extern uint D_004A6FD0;
extern uint D_004A6FD4;
extern uint D_004A6FD8;
extern uint D_004A6FDC;
extern uint D_004A6FE4;

// MATCH func_0021F280
undefined4 batread_0021f280(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  D_004A6FCC = param_1;
  D_004A6FD0 = param_2;
  D_004A6FD4 = param_3;
  D_004A6FD8 = param_4;
  D_004A6FDC = 1;
  D_004A6FE4 = 0;
  D_004A6FC4 = 0;
  return 1;
}
