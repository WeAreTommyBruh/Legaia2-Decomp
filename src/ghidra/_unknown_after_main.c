/* _unknown_after_main: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void MemFree(void *ptr);

// MATCH func_00111D40
void FUN_00111d40(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_00111D58
void FUN_00111d58(int param_1,int param_2)

{
  *(int *)(param_1 + 0x10) = param_2 + 8;
  return;
}

// MATCH func_00112B00
undefined4 FUN_00112b00(int *param_1)

{
  return *(undefined4 *)(*param_1 + 0xc);
}

// MATCH func_00112B18
undefined4 FUN_00112b18(int *param_1)

{
  return *(undefined4 *)(*param_1 + 8);
}
