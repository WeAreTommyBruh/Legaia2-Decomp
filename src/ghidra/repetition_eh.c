/* repetition_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

bool FUN_00172c18(int param_1, uint param_2);
undefined4 FUN_00172cf0(void);

// MATCH func_00175F38
void repetition_00175f38(int param_1)

{
  FUN_00172c18(param_1,0x20);
  return;
}

// MATCH func_001768D0
void repetition_001768d0(void)

{
  FUN_00172cf0();
  return;
}

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
