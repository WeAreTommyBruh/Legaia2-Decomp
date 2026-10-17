/* repetition: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_0043DF28[];
bool FUN_00172c18(int param_1, uint param_2);
void FUN_001739f0(void);
void FUN_00173a70(int param_1, int);
void FUN_00174060(int param_1);
void repetition_00174300(undefined8 param_1, uint param_2);

// MATCH func_00175EB0
undefined4 repetition_00175eb0(int param_1)

{
  if (*(short *)(param_1 + 0x170) == 1000) {
    return 1;
  }
  *(short *)(param_1 + 0x170) = *(short *)(param_1 + 0x170) + 1;
  return 0;
}

#define DAT_0043df28 (D_0043DF28[0])
// MATCH func_00176970
void repetition_00176970(int param_1,int param_2)

{
  *(undefined **)((int)param_1 + 0x380) = &DAT_0043df28;
  FUN_00173a70((int)param_1 + 0x390,2);
  repetition_00174300(param_1,param_2);
  return;
}
#undef DAT_0043df28

// MATCH func_001769F8
bool repetition_001769f8(int param_1)

{
  int lVar1;
  bool bVar2;
  
  bVar2 = false;
  lVar1 = FUN_00172c18(param_1,0x20);
  if (lVar1 != 0) {
    lVar1 = FUN_00172c18((int)param_1 + 0x390,0x20);
    bVar2 = lVar1 != 0;
  }
  return bVar2;
}

// MATCH func_00177020
void repetition_00177020(int param_1)

{
  FUN_001739f0();
  FUN_00174060(param_1 + 0x390);
  return;
}
