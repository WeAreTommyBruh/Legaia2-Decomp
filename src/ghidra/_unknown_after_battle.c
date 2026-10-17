/* _unknown_after_battle: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_00329640[];
extern int D_004322E8[];
void FUN_00108b80(int param_1);
void FUN_0012d498(void);
void battle_001297a0(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6);
void shikimi_002b3198(int, int);

// MATCH func_0012D018
void FUN_0012d018(void)

{
  battle_001297a0(0,2,0,0,0,0);
  return;
}

// MATCH func_0012D388
void FUN_0012d388(void)

{
  shikimi_002b3198(0,0);
  return;
}

#define DAT_00329640 (D_00329640[0])
// MATCH func_0012D3D8
undefined4 FUN_0012d3d8(int param_1)

{
  return (&DAT_00329640)[param_1];
}
#undef DAT_00329640

#define DAT_004322e8 (D_004322E8[0])
// MATCH func_0012D3F0
int FUN_0012d3f0(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1;
  *puVar1 = 0;
  puVar1[4] = &DAT_004322e8;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  return param_1;
}
#undef DAT_004322e8

#define DAT_004322e8 (D_004322E8[0])
// MATCH func_0012D418
void FUN_0012d418(int param_1,int param_2)

{
  *(undefined **)((int)param_1 + 0x10) = &DAT_004322e8;
  FUN_0012d498();
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}
#undef DAT_004322e8
