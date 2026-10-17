/* _unknown_after_nori: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_00456F58[];
extern int D_004A1A20;
extern int D_004A23C8;
extern int D_004A660C;
void FUN_00108b80(void);
void FUN_002a88e0(int param_1, int, int, int);
void MemFree(void *ptr);

// MATCH func_00282A08
void FUN_00282a08(int param_1)

{
  *(int *)(param_1 * 0x1560 + D_004A1A20 + 0x12cc) = param_1;
  return;
}

// MATCH func_00290818
undefined4 FUN_00290818(void)

{
  if ((D_004A23C8 != 0) &&
     (((0xc1 < D_004A660C || (D_004A660C == 0x3d)) || (D_004A660C == 0x3e)))) {
    return 1;
  }
  return 0;
}

// MATCH func_00294418
void FUN_00294418(float param_1,float param_2,float param_3,int param_4)

{
  FUN_002a88e0(param_4,(int)param_1,(int)param_2,(int)param_3);
  return;
}

#define DAT_00456f58 (D_00456F58[0])
// MATCH func_00294438
void FUN_00294438(undefined4 *param_1,uint param_2)

{
  *param_1 = 0;
  param_1[0xe] = &DAT_00456f58;
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}
#undef DAT_00456f58

// MATCH func_002944A0
void FUN_002944a0(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}
