/* _unknown_after_rsound: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_00315D98[];
extern uint D_004A12A4;
extern int D_004A6BD0;
extern int D_004A6BD4;
void FUN_0010f000(void);
void MemFree(void *ptr);

// MATCH func_0010E240
bool FUN_0010e240(int param_1)

{
  return *(int *)(param_1 + 0x530) != 0;
}

// MATCH func_0010F038
void FUN_0010f038(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_001114E8
bool FUN_001114e8(void)

{
  return D_004A6BD0 == D_004A6BD4;
}

// MATCH func_00111500
void FUN_00111500(void)

{
  D_004A12A4 = 0x12;
  FUN_0010f000();
  return;
}

#define DAT_00315d98 (D_00315D98[0])
// MATCH func_001118D0
bool FUN_001118d0(void)

{
  return DAT_00315d98 == 7;
}
#undef DAT_00315d98
