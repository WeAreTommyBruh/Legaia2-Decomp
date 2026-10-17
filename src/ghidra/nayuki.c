/* nayuki: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern byte D_00346780[];
extern int D_004A12A4;
undefined * FUN_001cea90(int param_1, int);
void FUN_001d7f00(uint param_1);
void akari_001e2628(int param_1, int param_2);

#define DAT_00346780 (D_00346780[0])
// MATCH func_001D8D30
void nayuki_001d8d30(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((-1 < param_2) && ((iVar1 = (int)param_1, 0 < *(int *)(iVar1 + 0x114) || (D_004A12A4 == 7))))
  {
    FUN_001d7f00(*(undefined4 *)(iVar1 + 0x84));
    *(int *)(iVar1 + 0x84) = (int)param_2;
    FUN_001cea90(param_2,param_3);
    akari_001e2628(param_1,&DAT_00346780 + (int)param_2 * 0x100);
    return;
  }
  return;
}
#undef DAT_00346780
