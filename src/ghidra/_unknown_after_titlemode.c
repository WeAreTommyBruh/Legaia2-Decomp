/* _unknown_after_titlemode: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_003C2E00[];
extern int D_00425510[];
extern int D_00455A48[];
extern uint D_004A4AB8;
void FUN_00108b80(int param_1);
void FUN_00110098(undefined8 param_1, undefined8 param_2, undefined8 param_3);
int FUN_0018b508(undefined1 *param_1, undefined8 param_2);
void FUN_00197120(void);
void FUN_0023cb70(undefined4 param_1);
void FUN_0024e3c8(void);
void FUN_002af340(void);
void FUN_002af998(void);
int FileGetSize(char *path);
void MemFree(void *ptr);
void battle_0012ae30(void);
void func_00214158(void);
int titlemode_00214200(void);

#define DAT_00425510 (D_00425510[0])
// MATCH func_002144F0
void FUN_002144f0(void)

{
  FUN_002af340();
  DAT_00425510 = DAT_00425510 | 0x4400;
  FUN_0024e3c8();
  battle_0012ae30();
  FUN_00197120();
  func_00214158();
  return;
}
#undef DAT_00425510

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

// MATCH func_00216398
int FUN_00216398(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1;
  puVar1[1] = param_2;
  puVar1[2] = param_3;
  puVar1[3] = param_4;
  puVar1[4] = param_5;
  puVar1[5] = param_6;
  *puVar1 = 0;
  puVar1[7] = 0;
  puVar1[6] = 0;
  return param_1;
}

// MATCH func_002163C0
void FUN_002163c0(int param_1,int param_2)

{
  if (*(int *)param_1 != 0) {
    FUN_002163c0(*(int *)param_1,3);
  }
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
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

#define DAT_00455a48 (D_00455A48[0])
// MATCH func_00216850
int FUN_00216850(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)param_1;
  puVar3[1] = 0;
  puVar3[2] = 0;
  *puVar3 = 0;
  puVar3[3] = &DAT_00455a48;
  iVar1 = FileGetSize((char *)param_2);
  if (0 < iVar1) {
    uVar2 = FUN_0018b508(param_2,0);
    puVar3[1] = uVar2;
  }
  return param_1;
}
#undef DAT_00455a48
