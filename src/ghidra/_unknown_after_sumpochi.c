/* _unknown_after_sumpochi: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_0043FED0[];
void FUN_00108b80(int param_1);
void MemFree(void *ptr);
void eftpack_00202878(undefined8 param_1, uint param_2);

#define DAT_0043fed0 (D_0043FED0[0])
// MATCH func_002183D0
void FUN_002183d0(int param_1,int param_2)

{
  *(undefined **)((int)param_1 + 0x844) = &DAT_0043fed0;
  eftpack_00202878((int)param_1 + 0x18,2);
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}
#undef DAT_0043fed0

// MATCH func_00218518
void FUN_00218518(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}
