/* _unknown_after_titlemode: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_003C2E00[];
extern uint D_004A4AB8;
void FUN_00110098(undefined8 param_1, undefined8 param_2, undefined8 param_3);
void FUN_0023cb70(undefined4 param_1);
void FUN_002af998(void);
void MemFree(void *ptr);
int titlemode_00214200(void);

// MATCH func_002159C8
undefined4 FUN_002159c8(int param_1)

{
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return 1;
}

#define DAT_003c2e00 (D_003C2E00[0])
// MATCH func_00215A78
undefined4 FUN_00215a78(int param_1)

{
  *(undefined **)(param_1 + 4) = &DAT_003c2e00;
  return 1;
}
#undef DAT_003c2e00

#define DAT_003c2e00 (D_003C2E00[0])
// MATCH func_00215AA8
undefined8 FUN_00215aa8(int param_1)

{
  *(undefined4 *)(param_1 + 0x1c) = 2;
  *(undefined **)(param_1 + 4) = &DAT_003c2e00;
  return 0;
}
#undef DAT_003c2e00

// MATCH func_00215B10
undefined4 FUN_00215b10(int param_1)

{
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return 1;
}

// MATCH func_00215B28
undefined8 FUN_00215b28(int param_1)

{
  FUN_0023cb70(0xe);
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 3;
  return 0;
}

// MATCH func_00215B60
undefined8 FUN_00215b60(int param_1)

{
  FUN_0023cb70(0xe);
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 4;
  return 0;
}

// MATCH func_00215F88
bool FUN_00215f88(void)

{
  int lVar1;
  
  lVar1 = titlemode_00214200();
  D_004A4AB8 = (int)lVar1;
  return lVar1 != 0;
}

// MATCH func_002162B0
void FUN_002162b0(void)

{
  FUN_002af998();
  FUN_00110098(0,0,0);
  FUN_00110098(1,0,0);
  return;
}

// MATCH func_00216380
void FUN_00216380(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_00216810
bool FUN_00216810(int param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if (0 < *(int *)(param_1 + 0x18)) {
    bVar1 = *(int *)(param_1 + 0x1c) < *(int *)(param_1 + 0x18);
  }
  return bVar1;
}

// MATCH func_00216830
bool FUN_00216830(int param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if (0 < *(int *)(param_1 + 0x18)) {
    bVar1 = *(int *)(param_1 + 0x18) == *(int *)(param_1 + 0x1c);
  }
  return bVar1;
}
