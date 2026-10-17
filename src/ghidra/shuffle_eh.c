/* shuffle_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

void shuffle_00178700(int param_1, uint param_2);

// MATCH func_001786A8
undefined8 shuffle_001786a8(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)param_1;
  do {
    iVar1 = (int)uVar2;
    *(undefined4 *)(iVar1 + 0x58) = 0;
    *(int *)(iVar1 + 0x54) = *(int *)(iVar1 + 0x54) + -4;
    uVar2 = (uint)(iVar1 + 0x60);
  } while ((int)uVar2 < (int)(int)(param_1 + 0x180));
  if (*(int *)(param_1 + 0x54) == 0) {
    shuffle_00178700(param_1,2);
  }
  return 0;
}
