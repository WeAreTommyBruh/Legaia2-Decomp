/* _unknown_after_bwin: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_00329640[];
extern uint D_004A1440;
extern uint D_004A1444;
extern uint D_004A1454;
extern int D_004A1498;
extern int D_004A149C;
extern uint D_004A714C;
extern uint D_004A7150;
extern uint D_004A7154;
int FUN_00245590(void);
undefined4 yokota_0023f2d0(void);

// MATCH func_00238FF8
void FUN_00238ff8(void)

{
  int lVar1;
  
  D_004A1444 = 0;
  D_004A1440 = 0;
  D_004A1454 = 0;
  if ((D_004A1498 == 1) && (lVar1 = FUN_00245590(), lVar1 != 0)) {
    D_004A1498 = 0;
  }
  if ((D_004A149C != 0) && (lVar1 = yokota_0023f2d0(), lVar1 != 0)) {
    D_004A149C = 0;
  }
  return;
}

#define DAT_00329640 (D_00329640[0])
// MATCH func_002393B8
void FUN_002393b8(int param_1,undefined4 param_2)

{
  if (param_1 - 8U < 0x18) {
    (&DAT_00329640)[param_1] = param_2;
  }
  return;
}
#undef DAT_00329640

// MATCH func_0023AAC0
void FUN_0023aac0(undefined4 param_1,undefined4 param_2)

{
  D_004A714C = param_1;
  D_004A7150 = param_2;
  D_004A7154 = 1;
  return;
}
