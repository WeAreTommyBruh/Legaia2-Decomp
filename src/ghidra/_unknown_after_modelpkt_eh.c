/* _unknown_after_modelpkt_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern int D_00342CD0[];
extern int D_0043E4F8[];
extern int D_0043E538[];
void FUN_001809b8(int param_1, undefined4 param_2, undefined4 param_3);
void FUN_001809d0(void);
bool FUN_001809f8(void);
undefined8 clas_min_002a4f30(undefined8 param_1);

#define DAT_0043e538 (D_0043E538[0])
#define DAT_0043e4f8 (D_0043E4F8[0])
#define DAT_00342cd0 (D_00342CD0[0])
// MATCH func_00180B28
int FUN_00180b28(int param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(undefined **)(iVar1 + 0xc) = &DAT_0043e538;
  FUN_001809b8(param_1,0,0x78);
  *(undefined **)(iVar1 + 0xc) = &DAT_0043e4f8;
  *(int **)(iVar1 + 0x10) = &DAT_00342cd0;
  clas_min_002a4f30(iVar1 + 0x14);
  return param_1;
}
#undef DAT_0043e538
#undef DAT_0043e4f8
#undef DAT_00342cd0

// MATCH func_00180B90
void FUN_00180b90(void)

{
  FUN_001809d0();
  return;
}

// MATCH func_00180BB0
void FUN_00180bb0(void)

{
  FUN_001809f8();
  return;
}
