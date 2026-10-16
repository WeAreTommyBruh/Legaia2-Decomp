/* pachislot: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void * pachislot_00164d08(int param_1,void *param_2,uint param_3);

// MATCH func_001649C8
void pachislot_001649c8(int *param_1)

{
  pachislot_00164d08(param_1,*(undefined4 *)(*param_1 + 0x18),*(undefined4 *)(*param_1 + 0x14));
  return;
}

// MATCH func_00164CF0
undefined4 pachislot_00164cf0(int *param_1)

{
  return *(undefined4 *)(*param_1 + 0x14);
}

// MATCH func_00165CE8
void pachislot_00165ce8(int param_1)

{
  if (*(int *)(param_1 + 0x34) == 4) {
    *(undefined4 *)(param_1 + 0x3c) = 1;
  }
  return;
}

// MATCH func_00167080
undefined4 pachislot_00167080(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(int *)(param_1 + 4) != -1) || (*(int *)(param_1 + 8) != -1)) {
    uVar1 = 1;
  }
  return uVar1;
}
