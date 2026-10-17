/* _unknown_after_abeshi: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern char D_003E2013[];
extern undefined * D_003E3D20[];
extern byte D_005F8918[];
extern byte D_005F8930[];
extern byte D_005F8948[];
extern byte D_005F8960[];
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

#define DAT_005f8918 (D_005F8918[0])
// MATCH func_00264DA0
int FUN_00264da0(uint param_1)

{
  if (4 < param_1) {
    return 0xffffffff;
  }
  return *(int *)(&DAT_005f8918 + (int)param_1 * 4);
}
#undef DAT_005f8918

#define DAT_005f8930 (D_005F8930[0])
// MATCH func_00264DC8
int FUN_00264dc8(uint param_1)

{
  if (4 < param_1) {
    return 0xffffffff;
  }
  return *(int *)(&DAT_005f8930 + (int)param_1 * 4);
}
#undef DAT_005f8930

#define DAT_005f8948 (D_005F8948[0])
// MATCH func_00264DF0
int FUN_00264df0(uint param_1)

{
  if (4 < param_1) {
    return 0xffffffff;
  }
  return *(int *)(&DAT_005f8948 + (int)param_1 * 4);
}
#undef DAT_005f8948

#define DAT_005f8960 (D_005F8960[0])
// MATCH func_00264E18
int FUN_00264e18(uint param_1)

{
  if (4 < param_1) {
    return 0xffffffff;
  }
  return *(int *)(&DAT_005f8960 + (int)param_1 * 4);
}
#undef DAT_005f8960

// MATCH func_00269530
int FUN_00269530(int param_1)

{
  return param_1 * 0x1c + ((int)D_003E2013);
}

#define PTR_DAT_003e3d20 (D_003E3D20[0])
// MATCH func_00269588
undefined * FUN_00269588(int param_1)

{
  return (&PTR_DAT_003e3d20)[param_1 * 5];
}
#undef PTR_DAT_003e3d20
