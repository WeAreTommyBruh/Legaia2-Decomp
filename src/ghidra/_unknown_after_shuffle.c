/* _unknown_after_shuffle: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_0017a220(uint param_1,int param_2,int param_3,int param_4);
void MemFree(void *ptr);
void shuffle_00177b00(int param_1,uint param_2);

// MATCH func_00178B88
void FUN_00178b88(int param_1)

{
  if (param_1 != 0) {
    shuffle_00177b00(param_1,3);
    return;
  }
  return;
}

// MATCH func_00178BA0
void FUN_00178ba0(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_0017A370
void FUN_0017a370(void)

{
  FUN_0017a220(0x3140,0x140,0x70,10);
  return;
}
