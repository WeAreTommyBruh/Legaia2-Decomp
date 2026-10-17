/* _unknown_after_bwin_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern uint D_004A1440;
extern uint D_004A1444;
extern uint D_004A1454;
extern int D_004A1498;
extern int D_004A149C;
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
