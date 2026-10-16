/* _unknown_after_battuto: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_00456F58[];
void FUN_00108b80(void);
void MemFree(void *ptr);

#define DAT_00456f58 (D_00456F58[0])
// MATCH func_0021E7F0
void FUN_0021e7f0(undefined4 *param_1,uint param_2)

{
  *param_1 = 0;
  param_1[0xe] = &DAT_00456f58;
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}
#undef DAT_00456f58

// MATCH func_0021E858
void FUN_0021e858(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}
