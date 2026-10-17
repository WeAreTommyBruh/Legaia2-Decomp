/* _unknown_after_nayuwin2: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_0036CAB0[];
extern int D_003A8860[];
extern int D_003A8D80[];
extern int D_004A3830;
extern uint D_004A3C30;
void FUN_00108c20(float *param_1);
void FUN_00108c80(int param_1);
void FUN_00110080(int param_1);
void FUN_001100b8(void);
undefined2 FUN_00250ab0(void);
int FUN_00254ce0(uint param_1, int param_2);
int FUN_00255008(uint param_1, int param_2);
void MemFree(void *ptr);
void clas_min_002a6160(void);
int nayuwin2_001ad548(undefined8 param_1, int *param_2, int *param_3);

// MATCH func_001AFF48
undefined4 FUN_001aff48(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x70) = param_2;
  return 1;
}

// MATCH func_001B4B40
void FUN_001b4b40(int param_1)

{
  D_004A3830 = param_1;
  FUN_001100b8();
  FUN_00110080(5);
  D_004A3C30 = 0;
  *(undefined4 *)(param_1 + 0x88) = 4;
  return;
}

// MATCH func_001B4B80
void FUN_001b4b80(int param_1,char param_2,char param_3)

{
  int uVar1;
  int iVar2;
  
  iVar2 = (int)param_3 - (int)param_2;
  if (iVar2 < 0) {
    uVar1 = FUN_00250ab0();
    FUN_00255008(uVar1,-iVar2);
    return;
  }
  uVar1 = FUN_00250ab0();
  FUN_00254ce0(uVar1,iVar2);
  return;
}

// MATCH func_001B78A8
void FUN_001b78a8(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_001B78C0
void FUN_001b78c0(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_001B78F0
void FUN_001b78f0(float param_1,int param_2)

{
  int iVar1;
  
  if (0.0f <= param_1) {
    iVar1 = (int)param_2;
    *(float *)(iVar1 + 0x14) = param_1;
    if (*(float *)(iVar1 + 0xc) < param_1) {
      *(float *)(iVar1 + 0x14) = *(float *)(iVar1 + 0xc);
    }
    FUN_00108c80(param_2);
    FUN_00108c20(param_2);
    return;
  }
  return;
}

// MATCH func_001C79A0
void FUN_001c79a0(int param_1)

{
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined4 *)(param_1 + 4) = 1;
  }
  clas_min_002a6160();
  return;
}

#define DAT_003a8d80 (D_003A8D80[0])
#define DAT_0036cab0 (D_0036CAB0[0])
#define DAT_003a8860 (D_003A8860[0])
// MATCH func_001CE9F0
undefined4 FUN_001ce9f0(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined *puVar4;
  undefined *puVar5;
  int aiStack_80 [4];
  
  puVar5 = &DAT_003a8d80;
  piVar3 = &DAT_0036cab0;
  iVar2 = 0;
  puVar4 = &DAT_003a8860;
  do {
    iVar1 = nayuwin2_001ad548(puVar4,puVar5,aiStack_80);
    *(int *)(iVar1 + 0x78) = iVar2;
    *piVar3 = iVar1;
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 1;
    puVar5 = puVar5 + aiStack_80[0] * 0xe8;
    puVar4 = puVar4 + 0xa4;
  } while (iVar2 < 8);
  return DAT_0036cab0;
}
#undef DAT_003a8d80
#undef DAT_0036cab0
#undef DAT_003a8860
