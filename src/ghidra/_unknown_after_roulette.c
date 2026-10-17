/* _unknown_after_roulette: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_001736d0(void);
void MemFree(void *ptr);

// MATCH func_001728F0
void FUN_001728f0(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_00172BC8
void FUN_00172bc8(int param_1,int param_2)

{
  *(undefined2 *)(*(int *)(param_1 + 0x70) + 0xbc) =
       *(undefined2 *)(param_2 * 4 + *(int *)(param_1 + 0x74));
  return;
}

// MATCH func_00172BE8
void FUN_00172be8(int param_1,uint param_2)

{
  *(uint *)(*(int *)(param_1 + 0x70) + 0xc0) = *(uint *)(*(int *)(param_1 + 0x70) + 0xc0) | param_2;
  return;
}

// MATCH func_00172C00
void FUN_00172c00(int param_1,uint param_2)

{
  *(uint *)(*(int *)(param_1 + 0x70) + 0xc0) = *(uint *)(*(int *)(param_1 + 0x70) + 0xc0) & ~param_2
  ;
  return;
}

// MATCH func_00172C18
bool FUN_00172c18(int param_1,uint param_2)

{
  return (*(uint *)(*(int *)(param_1 + 0x70) + 0xc0) & param_2) != 0;
}

// MATCH func_00172C90
bool FUN_00172c90(int param_1)

{
  return *(uint *)(param_1 + 0x54) < 2;
}

// MATCH func_00172CC8
bool FUN_00172cc8(int param_1)

{
  return *(int *)(param_1 + 0x5c) == 0;
}

// MATCH func_00172D78
void FUN_00172d78(int param_1)

{
  if (*(int *)(param_1 + 0x78) != 0) {
    FUN_001736d0();
    return;
  }
  return;
}

// MATCH func_00172D98
void FUN_00172d98(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x5c) + 1;
  *(int *)(param_1 + 0x5c) = iVar1;
  *(float *)(param_1 + 0x68) = (float)(iVar1 * iVar1) * 0.5f + 1.0f;
  return;
}

// MATCH func_00172DD0
void FUN_00172dd0(int param_1)

{
  *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + -1;
  if (*(int *)(param_1 + 0x60) < 999) {
    *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
  }
  return;
}

// MATCH func_00173A98
void FUN_00173a98(int param_1,int param_2)

{
  *(undefined2 *)(*(int *)(param_1 + 0x70) + 0xbc) =
       *(undefined2 *)((param_2 + *(int *)(param_1 + 0x160)) * 4 + *(int *)(param_1 + 0x74));
  return;
}
