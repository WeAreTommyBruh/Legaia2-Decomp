/* _unknown_after_disp_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern uint D_004A70A0;
extern uint D_004A70A4;
extern uint D_004A70F8;
extern uint D_004A70FC;
void FUN_0022fe58(void);
void FUN_00230100(void);
void FUN_002313a8(uint param_1, int param_2, int param_3, int param_4, int param_5, int param_6);

// MATCH func_0022FDB0
void FUN_0022fdb0(void)

{
  D_004A70FC = 1;
  FUN_00230100();
  D_004A70FC = 0;
  return;
}

// MATCH func_0022FEC0
void FUN_0022fec0(void)

{
  D_004A70F8 = 1;
  FUN_0022fe58();
  D_004A70F8 = 0;
  return;
}

// MATCH func_00231548
void FUN_00231548(void)

{
  FUN_002313a8(1,1,0,0,0,0);
  D_004A70A0 = 0;
  D_004A70A4 = 0;
  return;
}
