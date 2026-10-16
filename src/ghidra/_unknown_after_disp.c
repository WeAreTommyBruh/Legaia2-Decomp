/* _unknown_after_disp: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_004A14B8;
extern int D_004A5128;
extern uint D_004A7094;
extern uint D_004A7098;
extern uint D_004A70A0;
extern uint D_004A70A4;
extern uint D_004A70F8;
extern uint D_004A70FC;
void FUN_0018df68(undefined4 *param_1, undefined1 (*param_2) [16]);
void FUN_0018e860(undefined4 param_1);
void FUN_0018f3d8(undefined1 (*param_1) [16], undefined1 (*param_2) [16], undefined1 (*param_3) [16]);
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

// MATCH func_00231D98
void FUN_00231d98(void)

{
  FUN_0018e860(0x70003f00);
  FUN_0018f3d8(0x70003f80,0x70003f80,0x70003f00);
  FUN_0018f3d8(0x70003c80,0x70003c80,0x70003f00);
  if (D_004A14B8 != 0) {
    FUN_0018df68(0x70003f40,0x70003f00);
    FUN_0018f3d8(0x70003d80,0x70003f40,0x70003d80);
    return;
  }
  return;
}
