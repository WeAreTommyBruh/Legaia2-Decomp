/* _unknown_after_sumpochi: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_00456178[];
void FUN_00216cc0(void);
void MemFree(void *ptr);
void sammon_002282e8(int param_1, int param_2, undefined4 param_3);

// MATCH func_00218240
void FUN_00218240(int param_1)

{
  float fVar1;
  
  if (*(int *)(param_1 + 0xb8) == 0) {
    sammon_002282e8(*(undefined4 *)(param_1 + 0xd8),*(undefined4 *)(param_1 + 0x18c),
                    (int)(*(float *)(param_1 + 0x11c) + 0.5f));
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 8;
  }
  else {
    fVar1 = *(float *)(param_1 + 0x118) +
            (*(float *)(param_1 + 0x11c) - *(float *)(param_1 + 0x118)) /
            (float)*(int *)(param_1 + 0xb8);
    *(float *)(param_1 + 0x118) = fVar1;
    sammon_002282e8(*(undefined4 *)(param_1 + 0xd8),*(undefined4 *)(param_1 + 0x18c),
                    (int)(fVar1 + 0.5f));
    *(int *)(param_1 + 0xb8) = *(int *)(param_1 + 0xb8) + -1;
  }
  return;
}

// MATCH func_00218518
void FUN_00218518(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

#define DAT_00456178 (D_00456178[0])
// MATCH func_00218568
void FUN_00218568(int param_1)

{
  *(undefined **)(param_1 + 0x844) = &DAT_00456178;
  FUN_00216cc0();
  return;
}
#undef DAT_00456178
