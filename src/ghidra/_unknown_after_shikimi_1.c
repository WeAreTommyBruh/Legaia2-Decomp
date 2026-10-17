/* _unknown_after_shikimi_1: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern undefined * D_004293F4[];
extern int D_00456F58[];
void FUN_00108b80(void);
void FUN_002c5c38(int param_1);
undefined4 FUN_002c9368(uint *param_1, int param_2);
void FUN_002c9388(uint *param_1, int param_2);
int FUN_002cff48(void);
void FUN_002cff60(int param_1, undefined4 param_2);
undefined4 FUN_002cff78(int param_1);
int FUN_002d63a8(void);
void FUN_002dbb00(undefined8 param_1);
void FUN_002e1b20(undefined8 param_1, long param_2);
void _Exit(int __status);
int __fpcmp_parts_d(uint *param_1, uint *param_2);
void __unpack_d(uint *param_1, undefined4 *param_2);
void * _malloc_r(void *reent, uint size);
void thunk_FUN_002ee750(void);

// MATCH func_002BEDF8
void FUN_002bedf8(undefined8 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}

// MATCH func_002BEE18
void FUN_002bee18(undefined8 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}

// MATCH func_002BF110
void FUN_002bf110(undefined8 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}

// MATCH func_002BF1A0
void FUN_002bf1a0(undefined8 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}

// MATCH func_002BF1C0
void FUN_002bf1c0(undefined8 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}

// MATCH func_002BF1E0
void FUN_002bf1e0(undefined8 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}

// MATCH func_002BF250
void FUN_002bf250(undefined8 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}

// MATCH func_002BF2C0
void FUN_002bf2c0(undefined8 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}

// MATCH func_002BF330
void FUN_002bf330(undefined8 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}

#define DAT_00456f58 (D_00456F58[0])
// MATCH func_002BF380
void FUN_002bf380(undefined4 *param_1,uint param_2)

{
  *param_1 = 0;
  param_1[0xe] = &DAT_00456f58;
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}
#undef DAT_00456f58

// MATCH func_002C33C8
void FUN_002c33c8(int param_1)

{
  *(undefined4 *)(param_1 + 0x848) = 0;
  FUN_002c5c38(1);
  return;
}

// MATCH func_002C9470
int FUN_002c9470(int param_1)

{
  int uVar1;
  
  uVar1 = FUN_002c9368(param_1,1);
  FUN_002c9388(param_1,1);
  return uVar1;
}

// MATCH func_002D4268
int FUN_002d4268(int param_1,int param_2)

{
  int iVar1;
  int uVar2;
  
  uVar2 = 0xffffffffffffffff;
  if (((((int)param_1 - 1U < 0x7f) && (-1 < (int)param_2)) && ((int)param_2 < 0x80)) &&
     (iVar1 = FUN_002cff48(), *(int *)(iVar1 + 8) != 0)) {
    uVar2 = FUN_002cff78(param_1);
    uVar2 = uVar2 & 0x7f;
    FUN_002cff60(param_1,param_2 | 0x80);
  }
  return uVar2;
}

// MATCH func_002D7E48
void FUN_002d7e48(undefined8 param_1,undefined8 param_2)

{
  undefined1 auStack_70 [32];
  undefined1 auStack_50 [32];
  undefined8 uStack_30;
  undefined8 uStack_28;
  
  uStack_30 = param_1;
  uStack_28 = param_2;
  __unpack_d(&uStack_30,auStack_70);
  __unpack_d(&uStack_28,auStack_50);
  __fpcmp_parts_d(auStack_70,auStack_50);
  return;
}

// MATCH func_002D81D0
undefined4 FUN_002d81d0(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_002d63a8();
  return *puVar1;
}

// MATCH func_002D81F0
int FUN_002d81f0(void)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)FUN_002d63a8();
  iVar1 = *piVar2;
  *(undefined4 *)(iVar1 + 0x14) = 1;
  *(long *)(iVar1 + 0x20) = *(long *)(iVar1 + 0x20) + 1;
  return iVar1;
}

// MATCH func_002D8720
bool FUN_002d8720(void)

{
  int *piVar1;
  bool bVar2;
  
  piVar1 = (int *)FUN_002d63a8();
  bVar2 = false;
  if (*piVar1 != 0) {
    bVar2 = *(int *)(*piVar1 + 0x14) == 0;
  }
  return bVar2;
}

#define PTR_DAT_004293f4 (D_004293F4[0])
// MATCH func_002DBB10
void FUN_002dbb10(void)

{
  FUN_002dbb00(PTR_DAT_004293f4);
  return;
}
#undef PTR_DAT_004293f4

#define PTR_DAT_004293f4 (D_004293F4[0])
// MATCH func_002DBC48
void * FUN_002dbc48(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = _malloc_r(PTR_DAT_004293f4,param_1);
  return pvVar1;
}
#undef PTR_DAT_004293f4

#define PTR_DAT_004293f4 (D_004293F4[0])
// MATCH func_002DBC70
void FUN_002dbc70(undefined8 param_1)

{
  FUN_002e1b20(PTR_DAT_004293f4,param_1);
  return;
}
#undef PTR_DAT_004293f4

// MATCH func_002EE2C0
void FUN_002ee2c0(int param_1)

{
  thunk_FUN_002ee750();
  _Exit(param_1);
  return;
}
