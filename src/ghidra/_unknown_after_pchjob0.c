/* _unknown_after_pchjob0: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern char D_003C0F00[];
void FUN_00108b80(void);
void MemFree(void *ptr);
int work_00246d88(undefined4 *param_1, undefined8 param_2);

// MATCH func_0020B360
int FUN_0020b360(undefined8 param_1,undefined4 param_2)

{
  int lVar1;
  
  lVar1 = work_00246d88(((int)D_003C0F00),param_1);
  if (lVar1 != 0) {
    *(undefined4 *)((int)lVar1 + 0xd8) = param_2;
    *(undefined2 *)((int)lVar1 + 0xae) = 0x10;
  }
  return lVar1;
}

// MATCH func_0020B4B8
void FUN_0020b4b8(undefined8 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}

// MATCH func_0020B4D8
void FUN_0020b4d8(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_0020B4F0
void FUN_0020b4f0(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}
