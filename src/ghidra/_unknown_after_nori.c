/* _unknown_after_nori: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_00314CC8[];
extern byte D_00400643[];
extern int D_004A1A20;
extern int D_004A23C8;
extern int D_004A660C;
extern int D_004A66AC;
extern uint D_004A66C4;
undefined4 FUN_00290850(void);
uint FUN_00291c20(int param_1,char param_2,char param_3);
void MemFree(void *ptr);

// MATCH func_00282A08
void FUN_00282a08(int param_1)

{
  *(int *)(param_1 * 0x1560 + D_004A1A20 + 0x12cc) = param_1;
  return;
}

#define DAT_00314cc8 (D_00314CC8[0])
#define DAT_00400643 (D_00400643[0])
// MATCH func_00285988
undefined8 FUN_00285988(undefined8 param_1,int param_2,undefined8 param_3)

{
  int lVar1;
  
  if ((param_2 == 4) &&
     (((((DAT_00314cc8 == 0x53 && (DAT_00400643 == '\0')) || (DAT_00314cc8 == 0x39)) ||
       ((DAT_00314cc8 == 100 && ((D_004A66C4 & 8) == 0)))) ||
      ((DAT_00314cc8 == 0x70 && (D_004A66C4 != 4)))))) {
    param_3 = 0;
  }
  lVar1 = FUN_00291c20(*(undefined4 *)(param_2 * 0x1560 + D_004A1A20 + 0x12c0),9,0);
  if ((lVar1 < 0) &&
     (lVar1 = FUN_00291c20(*(undefined4 *)(param_2 * 0x1560 + D_004A1A20 + 0x12c0),9,1), lVar1 < 0)
     ) {
    param_3 = 0;
  }
  return param_3;
}
#undef DAT_00314cc8
#undef DAT_00400643

// MATCH func_00290818
undefined4 FUN_00290818(void)

{
  if ((D_004A23C8 != 0) &&
     (((0xc1 < D_004A660C || (D_004A660C == 0x3d)) || (D_004A660C == 0x3e)))) {
    return 1;
  }
  return 0;
}

// MATCH func_00290BA8
void FUN_00290ba8(void)

{
  if (D_004A66AC == 0) {
    FUN_00290850();
    D_004A66AC = D_004A66AC + 1;
  }
  return;
}

// MATCH func_002944A0
void FUN_002944a0(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}
