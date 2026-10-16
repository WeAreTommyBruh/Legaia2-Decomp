/* _unknown_after_screfct: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_0043E4F8[];
void FUN_00108b80(void);
void FUN_00186ac0(void);
void MemFree(void *ptr);

// MATCH func_00184748
void FUN_00184748(undefined8 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}

#define DAT_0043e4f8 (D_0043E4F8[0])
// MATCH func_00185168
void FUN_00185168(int param_1,uint param_2)

{
  *(undefined **)(param_1 + 0xc) = &DAT_0043e4f8;
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}
#undef DAT_0043e4f8

// MATCH func_001852D8
void FUN_001852d8(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_001852F0
void FUN_001852f0(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_00186A68
undefined8 FUN_00186a68(undefined8 param_1)

{
  FUN_00186ac0();
  return param_1;
}
