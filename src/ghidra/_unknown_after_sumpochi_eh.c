/* _unknown_after_sumpochi_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern int D_00456178[];
void FUN_00216be8(undefined8 param_1, uint param_2);
undefined8 FUN_00216c40(void);
void sammon_002282e8(int param_1, int param_2, undefined4 param_3);

// MATCH func_00217638
void FUN_00217638(int param_1,int *param_2)

{
  undefined4 *puVar1;
  
  if (*(int **)(param_1 + 0x86c) != (int *)0x0) {
    if (*(int **)(param_1 + 0x86c) == param_2) {
      puVar1 = (undefined4 *)param_2[1];
      *(undefined4 **)(param_1 + 0x86c) = puVar1;
      if (puVar1 != (undefined4 *)0x0) {
        *puVar1 = 0;
      }
    }
    else {
      *(int *)(*param_2 + 4) = param_2[1];
      if ((int *)param_2[1] != (int *)0x0) {
        *(int *)param_2[1] = *param_2;
      }
    }
    param_2[1] = 0;
    *param_2 = 0;
    FUN_00216be8(param_2,3);
  }
  return;
}

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

#define DAT_00456178 (D_00456178[0])
// MATCH func_00218530
int FUN_00218530(int param_1)

{
  FUN_00216c40();
  *(undefined **)((int)param_1 + 0x844) = &DAT_00456178;
  return param_1;
}
#undef DAT_00456178
