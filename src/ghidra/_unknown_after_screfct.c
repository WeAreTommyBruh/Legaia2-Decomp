/* _unknown_after_screfct: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_0043E460[];
int DbgPrintf(char *fmt);
void FUN_00108b80(int param_1);
void FUN_00184518(int *param_1);
void MemFree(void *ptr);

#define DAT_0043e460 (D_0043E460[0])
// MATCH func_001843A0
void FUN_001843a0(int param_1,int param_2)

{
  if (*(int *)param_1 != 0) {
    DbgPrintf(&DAT_0043e460);
    FUN_00184518(param_1);
  }
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}
#undef DAT_0043e460

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
