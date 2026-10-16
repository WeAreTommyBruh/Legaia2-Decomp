/* _unknown_after_denlib: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_00190668(void);
void MemFree(void *ptr);

// MATCH func_0018DD78
void FUN_0018dd78(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_0018DD90
void FUN_0018dd90(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_0018DE38
void FUN_0018de38(int param_1,int param_2)

{
  *(int *)(param_1 + 0x10) = param_2 + 8;
  return;
}

// MATCH func_00190640
undefined8 FUN_00190640(undefined8 param_1)

{
  FUN_00190668();
  return param_1;
}
