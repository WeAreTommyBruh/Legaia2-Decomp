/* _unknown_after_shikimi_1: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern undefined * D_004293F4[];
int FUN_002d63a8(void);
void FUN_002e1b20(undefined8 param_1, long param_2);
int __fpcmp_parts_d(uint *param_1, uint *param_2);
void __unpack_d(uint *param_1, undefined4 *param_2);
void * _malloc_r(void *reent, uint size);

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
