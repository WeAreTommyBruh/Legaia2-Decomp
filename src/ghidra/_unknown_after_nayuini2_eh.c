/* _unknown_after_nayuini2_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern int D_0036CAB0[];
extern int D_003A5118[];
extern int D_003A51C0[];
int nayuwin2_001ad548(undefined8 param_1, int *param_2, int *param_3);

#define DAT_003a51c0 (D_003A51C0[0])
#define DAT_0036cab0 (D_0036CAB0[0])
#define DAT_003a5118 (D_003A5118[0])
// MATCH func_001AA380
undefined4 FUN_001aa380(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined *puVar4;
  undefined *puVar5;
  int aiStack_80 [4];
  
  puVar5 = &DAT_003a51c0;
  piVar3 = &DAT_0036cab0;
  iVar2 = 0;
  puVar4 = &DAT_003a5118;
  do {
    iVar1 = nayuwin2_001ad548(puVar4,puVar5,aiStack_80);
    *(int *)(iVar1 + 0x78) = iVar2;
    *piVar3 = iVar1;
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 1;
    puVar5 = puVar5 + aiStack_80[0] * 0xe8;
    puVar4 = puVar4 + 0xa4;
  } while (iVar2 < 1);
  return DAT_0036cab0;
}
#undef DAT_003a51c0
#undef DAT_0036cab0
#undef DAT_003a5118
