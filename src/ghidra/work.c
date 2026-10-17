/* work: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void work_002461e0(void);
undefined4 work_00246810(int param_1);

// MATCH func_00246340
void work_00246340(int param_1)

{
  work_002461e0();
  work_00246810(param_1);
  return;
}

// MATCH func_00246490
void work_00246490(int param_1)

{
  if (*(int *)(param_1 + 0x154) != 0) {
    *(undefined2 *)(*(int *)(param_1 + 0x154) + 0x3000) = 0;
  }
  return;
}

// MATCH func_002468D8
void work_002468d8(int param_1)

{
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffbff;
  return;
}
