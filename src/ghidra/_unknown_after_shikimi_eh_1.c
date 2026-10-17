/* _unknown_after_shikimi_eh_1: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern undefined * D_004293F4[];
extern int D_004A7428[];
undefined4 FUN_002c9368(uint *param_1, int param_2);
void FUN_002c9388(uint *param_1, int param_2);
void FUN_002da4b0(void);
undefined8 FUN_002dcb08(undefined8 param_1, ulong param_2);
void FUN_002e39a8(undefined8 param_1, char *param_2, undefined4 *param_3);
undefined8 FUN_002e5ee8(long param_1, undefined8 param_2, undefined8 param_3);
undefined4 FUN_002e5f88(int);
int __fpcmp_parts_d(uint *param_1, uint *param_2);
void __unpack_d(uint *param_1, undefined4 *param_2);
void * _malloc_r(void *reent, uint size);

// MATCH func_002C9470
int FUN_002c9470(int param_1)

{
  int uVar1;
  
  uVar1 = FUN_002c9368(param_1,1);
  FUN_002c9388(param_1,1);
  return uVar1;
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

// MATCH func_002DA898
void FUN_002da898(void)

{
  FUN_002da4b0();
  return;
}

// MATCH func_002DA928
void FUN_002da928(void)

{
  FUN_002da4b0();
  return;
}

// MATCH func_002DA9B0
void FUN_002da9b0(void)

{
  FUN_002da4b0();
  return;
}

// MATCH func_002DB640
void FUN_002db640(void)

{
  FUN_002da4b0();
  return;
}

// MATCH func_002DB6B0
void FUN_002db6b0(void)

{
  FUN_002da4b0();
  return;
}

// MATCH func_002DB720
void FUN_002db720(void)

{
  FUN_002da4b0();
  return;
}

// MATCH func_002DB790
void FUN_002db790(void)

{
  FUN_002da4b0();
  return;
}

// MATCH func_002DB800
void FUN_002db800(void)

{
  FUN_002da4b0();
  return;
}

// MATCH func_002DB870
void FUN_002db870(void)

{
  FUN_002da4b0();
  return;
}

// MATCH func_002DB8E0
void FUN_002db8e0(void)

{
  FUN_002da4b0();
  return;
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
// MATCH func_002DCCB0
void FUN_002dccb0(undefined8 param_1)

{
  FUN_002dcb08(PTR_DAT_004293f4,param_1);
  return;
}
#undef PTR_DAT_004293f4

#define DAT_004a7428 (D_004A7428[0])
// MATCH func_002E04B8
int FUN_002e04b8(int *param_1,int param_2)

{
  int lVar1;
  
  DAT_004a7428 = 0;
  lVar1 = FUN_002e5f88(param_2);
  if ((lVar1 == -1) && (DAT_004a7428 != 0)) {
    *param_1 = DAT_004a7428;
  }
  return lVar1;
}
#undef DAT_004a7428

#define DAT_004a7428 (D_004A7428[0])
// MATCH func_002E3768
long FUN_002e3768(int *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  
  DAT_004a7428 = 0;
  lVar1 = FUN_002e5ee8(param_2,param_3,param_4);
  if ((lVar1 == -1) && (DAT_004a7428 != 0)) {
    *param_1 = DAT_004a7428;
  }
  return lVar1;
}
#undef DAT_004a7428

#define PTR_DAT_004293f4 (D_004293F4[0])
// MATCH func_002E48A8
void FUN_002e48a8(int param_1,int param_2)

{
  FUN_002e39a8(PTR_DAT_004293f4,param_1,param_2);
  return;
}
#undef PTR_DAT_004293f4
