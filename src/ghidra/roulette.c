/* roulette: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern byte D_00335640[];
void roulette_0016f9f8(undefined8 param_1, ulong param_2);
void roulette_00171980(int param_1, uint param_2);
int roulette_00171ad0(void);

// MATCH func_0016FAB0
void roulette_0016fab0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 0x34);
  iVar1 = 0xb;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + -1;
  } while (-1 < iVar1);
  return;
}

// MATCH func_00170AE0
void roulette_00170ae0(int param_1)

{
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & 0xffff0000;
  return;
}

// MATCH func_00171440
void roulette_00171440(undefined4 *param_1,int param_2)

{
  *param_1 = (int)param_2;
  if (999999 < param_2) {
    *param_1 = 999999;
  }
  return;
}

// MATCH func_00171460
void roulette_00171460(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = iVar1 + param_2;
  if (999999 < iVar1 + param_2) {
    *param_1 = 999999;
  }
  return;
}

// MATCH func_00171488
void roulette_00171488(int param_1,int param_2)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + param_2;
  return;
}

#define DAT_00335640 (D_00335640[0])
// MATCH func_00171950
undefined4 roulette_00171950(void)

{
  int iVar1;
  
  iVar1 = roulette_00171ad0();
  return *(undefined4 *)(&DAT_00335640 + iVar1 * 4);
}
#undef DAT_00335640

// MATCH func_00171AB8
void roulette_00171ab8(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xffff0000;
  return;
}

// MATCH func_001723B8
void roulette_001723b8(int param_1)

{
  roulette_00171980(param_1,4);
  *(undefined4 *)((int)param_1 + 0x74) = 0;
  return;
}

// MATCH func_00172768
void roulette_00172768(long param_1)

{
  if (param_1 != 0) {
    roulette_0016f9f8(param_1,3);
    return;
  }
  return;
}
