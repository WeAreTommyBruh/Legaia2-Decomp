/* _unknown_after_abeshi: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern undefined * D_003E3D20[];
extern int D_003FEBA8[];
extern ushort D_004005C0[];
void MemFree(void *ptr);
void abeshi_0025eca8(undefined8 param_1, ulong param_2);

// MATCH func_0025FE50
void FUN_0025fe50(long param_1)

{
  if (param_1 != 0) {
    abeshi_0025eca8(param_1,3);
    return;
  }
  return;
}

// MATCH func_0025FE68
void FUN_0025fe68(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *param_1;
  *param_1 = *param_2;
  *param_2 = uVar1;
  return;
}

// MATCH func_0025FE80
void FUN_0025fe80(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_0025FE98
void FUN_0025fe98(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

#define DAT_003feba8 (D_003FEBA8[0])
// MATCH func_00264E78
void FUN_00264e78(int param_1)

{
  DAT_003feba8 = DAT_003feba8 + param_1;
  if (9999999 < DAT_003feba8) {
    DAT_003feba8 = 9999999;
  }
  if (DAT_003feba8 < 0) {
    DAT_003feba8 = 0;
  }
  return;
}
#undef DAT_003feba8

#define PTR_DAT_003e3d20 (D_003E3D20[0])
// MATCH func_00269588
undefined * FUN_00269588(int param_1)

{
  return (&PTR_DAT_003e3d20)[param_1 * 5];
}
#undef PTR_DAT_003e3d20

#define DAT_004005c0 (D_004005C0[0])
// MATCH func_0026AF28
int FUN_0026af28(void)

{
  return DAT_004005c0 - 0x12d;
}
#undef DAT_004005c0
