/* _unknown_after_screfct_1: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_0043E4F8[];
void FUN_00108b80(void);

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
