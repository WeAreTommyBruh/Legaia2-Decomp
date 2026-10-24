/* n_pchevent_fnoscheduleinsns_fnoscheduleinsns2: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fno-schedule-insns -fno-schedule-insns2
#include "../ghidra.h"


// MATCH func_0020BA30
int * pchevent_0020ba30(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = *(int **)(param_1 + 0xc);
  if ((piVar1 != (int *)0x0) && (iVar3 = *(int *)(param_1 + 4), piVar2 = piVar1, 0 < iVar3)) {
    do {
      piVar1 = (int *)*piVar2;
      piVar2 = piVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return piVar1;
}
