/* _unknown_after_battleslot: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern uint D_004A6B40;
extern uint D_004A72FC;
extern uint D_004A7300;
void FUN_00295a30(void);
void MemFree(void *ptr);
void battleslot_00294b20(undefined8 param_1, ulong param_2);

// MATCH func_00295010
void FUN_00295010(long param_1)

{
  if (param_1 != 0) {
    battleslot_00294b20(param_1,3);
    return;
  }
  return;
}

// MATCH func_00295080
void FUN_00295080(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_00295DA8
void FUN_00295da8(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x88) == 0) {
    if (param_2 == -1) {
      *(undefined4 *)(param_1 + 0x80) = 0;
      *(undefined4 *)(param_1 + 0x84) = 0xffff;
    }
    else {
      *(int *)(param_1 + 0x84) = (int)param_2;
      *(undefined4 *)(param_1 + 0x80) = 1;
    }
    FUN_00295a30();
    return;
  }
  return;
}

// MATCH func_002971C0
void FUN_002971c0(undefined4 param_1,undefined4 param_2)

{
  D_004A72FC = param_1;
  D_004A7300 = param_2;
  return;
}

// MATCH func_002978E0
void FUN_002978e0(void)

{
  if ((D_004A6B40 & 2) == 0) {
    D_004A6B40 = D_004A6B40 & 0xfffffffe;
  }
  return;
}

// MATCH func_0029B700
void FUN_0029b700(void)

{
  D_004A6B40 = D_004A6B40 | 0x2000;
  return;
}

// MATCH func_0029B9C0
int FUN_0029b9c0(int param_1,int param_2)

{
  int iVar1;
  int *puVar2;
  
  puVar2 = (int *)(param_1 + 0x18);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    if (param_2 == puVar2[3]) {
      return *puVar2;
    }
    puVar2 = puVar2 + 1;
  } while (iVar1 < 3);
  return 0xffffffff;
}
