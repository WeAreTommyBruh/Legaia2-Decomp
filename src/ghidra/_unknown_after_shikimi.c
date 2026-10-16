/* _unknown_after_shikimi: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_00429878[];
extern int D_00429890[];
extern int D_00429918[];
extern int D_00429930[];
extern int D_0049E7C8[];
extern int D_0049E7E0[];
extern int D_0049E948[];
extern int D_0049E958[];
extern int D_0049E968[];
extern int D_0049E978[];
extern int D_0049E9A8[];
extern uint D_004A72BC;
extern uint D_004A72C0;
extern int D_004A7428[];
extern int D_00620120[];
extern byte D_00631840[];
extern int D_00631AA8[];
extern byte D_00632980[];
extern byte D_00635568[];
extern byte D_006359E8[];
undefined8 FUN_002c2d58(long param_1,int *param_2);
void FUN_002c33d8(undefined8 param_1);
void FUN_002c35c8(long param_1,undefined8 param_2);
void FUN_002c5c38(int param_1);
void FUN_002c7228(undefined8 param_1,uint param_2);
uint FUN_002c7318(undefined8 param_1,uint param_2);
void FUN_002cf9c8(undefined4 *param_1);
void FUN_002cfab0(int *param_1);
undefined * FUN_002cff38(void);
undefined4 FUN_002cffb0(void);
void FUN_002cffe0(void);
void FUN_002d61e8(void);
void FUN_002d62c8(void);
int FUN_002d63a8(void);
void FUN_002d7e48(undefined8 param_1,undefined8 param_2);
void * FUN_002dbc48(uint param_1);
undefined8 FUN_002e5ee8(long param_1,undefined8 param_2,undefined8 param_3);
void FUN_002e60f0(uint param_1,uint param_2);
void FUN_002e6230(uint param_1,uint param_2);
int FUN_002e6678(void);
void FUN_002e7c98(void);
bool FUN_002edc50(void);
bool FUN_002edc98(void);
void FUN_002edcb0(void);
void FUN_002eddc8(void);
void FUN_002edfe8(void);
void FUN_002ee3a0(void);
void FUN_002ee5c8(void);
void MemFree(void *ptr);
undefined4 SndVoiceSetParam(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void _Exit(int __status);
void * _malloc_r(void *reent,uint size);
void * memset(void *dst,int c,uint n);
int sprintf(char *dst,char *fmt,...);
int strcmp(char *a,char *b);
void thunk_FUN_002ee750(void);

#define DAT_00620120 (D_00620120[0])
// MATCH func_002BC860
void FUN_002bc860(void)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  
  D_004A72C0 = 0;
  D_004A72BC = 0;
  puVar3 = &DAT_00620120;
  iVar2 = 0;
  do {
    iVar1 = iVar2 + -0x80;
    iVar2 = iVar2 + 1;
    if (iVar1 < 0) {
      if (iVar1 < -0x7f) {
        iVar1 = -0x7f;
      }
      iVar1 = iVar1 + 0x18;
      if (0 < iVar1) {
        iVar1 = 0;
      }
      if (iVar1 < -0x40) {
        iVar1 = iVar1 * 2 + 0x40;
      }
    }
    if (0 < iVar1) {
      if (0x7f < iVar1) {
        iVar1 = 0x7f;
      }
      iVar1 = iVar1 + -0x18;
      if (iVar1 < 0) {
        iVar1 = 0;
      }
      if (0x40 < iVar1) {
        iVar1 = iVar1 * 2 + -0x40;
      }
    }
    *puVar3 = (short)iVar1;
    puVar3 = puVar3 + 1;
  } while (iVar2 < 0x100);
  return;
}
#undef DAT_00620120

// MATCH func_002BF350
void FUN_002bf350(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_002BF368
void FUN_002bf368(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_002BF5A0
void FUN_002bf5a0(int param_1,int param_2)

{
  *(int *)(param_1 + 0x10) = param_2 + 8;
  return;
}

// MATCH func_002C2C48
void FUN_002c2c48(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  *param_2 = *(undefined4 *)(iVar1 + 0x94);
  *param_3 = *(undefined4 *)(iVar1 + 0x98);
  *param_4 = *(undefined4 *)(iVar1 + 0x9c);
  return;
}

// MATCH func_002C2C68
undefined4 FUN_002c2c68(int param_1)

{
  return **(undefined4 **)(param_1 + 0x40);
}

// MATCH func_002C2C78
bool FUN_002c2c78(int param_1)

{
  return *(int *)(*(int *)(param_1 + 0x40) + 4) == 0;
}

// MATCH func_002C2CD8
undefined4 FUN_002c2cd8(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  if (*(int *)(iVar1 + 0x1b8) != 0) {
    *(undefined4 *)(*(int *)(iVar1 + 0x1b8) + 0x28) = 0;
  }
  if (*(int *)(iVar1 + 0x1c8) != 0) {
    *(undefined4 *)(*(int *)(iVar1 + 0x1c8) + 0x28) = 0;
  }
  if (*(int *)(iVar1 + 0x1d8) != 0) {
    *(undefined4 *)(*(int *)(iVar1 + 0x1d8) + 0x28) = 0;
  }
  if (*(int *)(iVar1 + 0x1bc) != 0) {
    *(undefined4 *)(*(int *)(iVar1 + 0x1bc) + 0x28) = 0;
  }
  if (*(int *)(iVar1 + 0x1cc) != 0) {
    *(undefined4 *)(*(int *)(iVar1 + 0x1cc) + 0x28) = 0;
  }
  if (*(int *)(iVar1 + 0x1dc) != 0) {
    *(undefined4 *)(*(int *)(iVar1 + 0x1dc) + 0x28) = 0;
  }
  return 1;
}

// MATCH func_002C2DA8
void FUN_002c2da8(undefined8 param_1)

{
  undefined4 auStack_30 [8];
  
  auStack_30[0] = 1;
  FUN_002c2d58(param_1,auStack_30);
  return;
}

// MATCH func_002C2DF8
void FUN_002c2df8(int param_1,undefined4 param_2)

{
  *(undefined4 *)(*(int *)(param_1 + 0x40) + 0xd8) = param_2;
  return;
}

// MATCH func_002C2E08
undefined4 FUN_002c2e08(int param_1)

{
  return *(undefined4 *)(*(int *)(param_1 + 0x40) + 0xcc);
}

// MATCH func_002C2E18
undefined4 FUN_002c2e18(int param_1)

{
  return *(undefined4 *)(*(int *)(param_1 + 0x40) + 0xd0);
}

// MATCH func_002C2E28
int FUN_002c2e28(int param_1)

{
  return *(int *)(param_1 + 0x40) + 0xb4;
}

// MATCH func_002C2E38
int FUN_002c2e38(int param_1)

{
  return *(int *)(param_1 + 0x40) + 0xb4;
}

// MATCH func_002C2E48
undefined4 FUN_002c2e48(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x40) + 0xe8);
  *(undefined4 *)(*(int *)(param_1 + 0x40) + 0xe8) = param_2;
  return uVar1;
}

// MATCH func_002C2E88
void FUN_002c2e88(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 8);
  return;
}

// MATCH func_002C2E98
void FUN_002c2e98(int param_1)

{
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0xc);
  return;
}

// MATCH func_002C2F18
int FUN_002c2f18(int *param_1)

{
  return (*param_1 + param_1[1]) - param_1[2];
}

// MATCH func_002C3360
undefined4 FUN_002c3360(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x40);
  uVar2 = 0;
  if ((*(int *)(iVar1 + 4) != 0) && (*(int *)(iVar1 + 8) != 0)) {
    FUN_002c33d8(iVar1);
    uVar2 = 1;
    *(int *)(param_1 + 8) = *(int *)(iVar1 + 0x118) - *(int *)(iVar1 + 0xac);
    *(undefined4 *)(iVar1 + 4) = 0;
  }
  return uVar2;
}

// MATCH func_002C33C8
void FUN_002c33c8(int param_1)

{
  *(undefined4 *)(param_1 + 0x848) = 0;
  FUN_002c5c38(1);
  return;
}

// MATCH func_002C3590
void FUN_002c3590(undefined8 param_1,char *param_2)

{
  char acStack_120 [256];
  
  sprintf(acStack_120,param_2);
  FUN_002c35c8(param_1,acStack_120);
  return;
}

// MATCH func_002C3ED0
void FUN_002c3ed0(int param_1)

{
  FUN_002cf9c8(*(int *)(param_1 + 0x40) + 0x4c);
  return;
}

// MATCH func_002C3EE0
void FUN_002c3ee0(int param_1)

{
  FUN_002cfab0(*(int *)(param_1 + 0x40) + 0x4c);
  return;
}

// MATCH func_002C7A40
void FUN_002c7a40(undefined8 param_1)

{
  int lVar1;
  
  while (lVar1 = FUN_002c7318(param_1,1), lVar1 != 0) {
    FUN_002c7228(param_1,8);
  }
  return;
}

// MATCH func_002C7D60
void FUN_002c7d60(undefined8 param_1)

{
  FUN_002c7318(param_1,1);
  FUN_002c7318(param_1,8);
  FUN_002c7318(param_1,1);
  FUN_002c7318(param_1,7);
  FUN_002c7318(param_1,1);
  FUN_002c7318(param_1,0x14);
  FUN_002c7318(param_1,1);
  FUN_002c7318(param_1,0x16);
  FUN_002c7318(param_1,1);
  FUN_002c7318(param_1,0x16);
  return;
}

// MATCH func_002C9510
uint FUN_002c9510(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + 8) + (param_2 >> 3);
  if (*(uint *)(param_1 + 0x24) <= uVar1) {
    uVar1 = uVar1 - *(int *)(param_1 + 0x28);
  }
  return uVar1;
}

// MATCH func_002CEA10
void FUN_002cea10(undefined1 *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (int)param_2 + -1;
  if (param_2 != 0) {
    do {
      *param_1 = 0;
      iVar1 = iVar1 + -1;
      param_1 = param_1 + 1;
    } while (iVar1 != -1);
  }
  return;
}

// MATCH func_002CF120
uint FUN_002cf120(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *param_1;
  *param_1 = param_2;
  return uVar1 >> 8 & 1;
}

// MATCH func_002CF148
void FUN_002cf148(undefined4 *param_1)

{
  param_1[2] = 0;
  *param_1 = param_1[1];
  return;
}

// MATCH func_002CF448
void FUN_002cf448(undefined4 *param_1)

{
  param_1[2] = 0;
  *param_1 = param_1[1];
  return;
}

// MATCH func_002CF830
void FUN_002cf830(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  *puVar1 = param_2;
  *param_1 = (int)(puVar1 + 1);
  return;
}

// MATCH func_002CF848
void FUN_002cf848(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  *puVar1 = param_2;
  *param_1 = (int)(puVar1 + 1);
  return;
}

// MATCH func_002CF860
void FUN_002cf860(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  *puVar1 = param_2;
  *param_1 = (int)(puVar1 + 1);
  return;
}

#define DAT_00631840 (D_00631840[0])
// MATCH func_002CFF60
void FUN_002cff60(int param_1,undefined4 param_2)

{
  *(undefined4 *)(&DAT_00631840 + param_1 * 4) = param_2;
  return;
}
#undef DAT_00631840

#define DAT_00631840 (D_00631840[0])
// MATCH func_002CFF78
undefined4 FUN_002cff78(int param_1)

{
  return *(undefined4 *)(&DAT_00631840 + param_1 * 4);
}
#undef DAT_00631840

// MATCH func_002D38F8
void FUN_002d38f8(void)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    SndVoiceSetParam(0xb,iVar1,0xffffff,0);
    SndVoiceSetParam(0x28,iVar1,0,0);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  SndVoiceSetParam(0x1f,0,0,0);
  return;
}

// MATCH func_002D3968
void FUN_002d3968(void)

{
  int iVar1;
  
  iVar1 = FUN_002cff38();
  if (*(int *)(iVar1 + 0x44) != 0) {
    FUN_002cffe0();
    return;
  }
  return;
}

// MATCH func_002D5020
void FUN_002d5020(void)

{
  SndVoiceSetParam(0x3c,0,0,0);
  return;
}

// MATCH func_002D5038
void FUN_002d5038(void)

{
  SndVoiceSetParam(0x3d,0,0,0);
  return;
}

/* WARNING: Removing unreachable block (ram,0x002d5310) */
// MATCH func_002D52E0
undefined4 FUN_002d52e0(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_1 < 0x30) {
    iVar1 = FUN_002cffb0();
    uVar2 = *(undefined4 *)(iVar1 + ((int)param_1 % 0x18) * 4 + ((int)param_1 / 0x18) * 0x60 + 0xc0)
    ;
  }
  return uVar2;
}

// MATCH func_002D5350
void FUN_002d5350(void)

{
  SndVoiceSetParam(0x46,0,0,0);
  return;
}

// MATCH func_002D5368
void FUN_002d5368(void)

{
  SndVoiceSetParam(0x47,0,0,0);
  return;
}

// MATCH func_002D6140
undefined8 FUN_002d6140(int param_1)

{
  FUN_002d7e48(*(undefined8 *)(param_1 + 8),*(undefined8 *)(param_1 + 8));
  return 0;
}

#define DAT_00631aa8 (D_00631AA8[0])
// MATCH func_002D6298
void FUN_002d6298(void)

{
  if (DAT_00631aa8 == 0) {
    DAT_00631aa8 = 1;
    FUN_002d61e8();
    return;
  }
  return;
}
#undef DAT_00631aa8

// MATCH func_002D62F0
undefined8 FUN_002d62f0(char *param_1,char *param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = strcmp(param_1,param_2);
  if (iVar1 != 0) {
    param_3 = 0;
  }
  return param_3;
}

// MATCH func_002D6328
int FUN_002d6328(void)

{
  int lVar1;
  void *dst;
  
  lVar1 = FUN_002dbc48(0x18);
  if (lVar1 == 0) {
    FUN_002d62c8();
  }
  dst = (void *)lVar1;
  memset(dst,0,0x18);
  *(int *)((int)dst + 4) = (int)dst + 0x10;
  return lVar1;
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

// MATCH func_002D8758
undefined4 FUN_002d8758(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 4))();
  return *puVar1;
}

#define DAT_0049e7c8 (D_0049E7C8[0])
// MATCH func_002DA548
void FUN_002da548(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1;
  if (param_1 != 0) {
    puVar1[2] = param_3;
    *puVar1 = param_2;
    puVar1[1] = &DAT_0049e7c8;
  }
  return;
}
#undef DAT_0049e7c8

#define DAT_0049e7e0 (D_0049E7E0[0])
// MATCH func_002DA568
void FUN_002da568(int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    *(undefined4 *)param_1 = param_2;
    ((undefined4 *)param_1)[1] = &DAT_0049e7e0;
  }
  return;
}
#undef DAT_0049e7e0

// MATCH func_002DAB80
uint FUN_002dab80(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  
  uVar1 = strcmp((char *)*param_1,(char *)*param_2);
  return uVar1 >> 0x1f;
}

#define DAT_0049e9a8 (D_0049E9A8[0])
// MATCH func_002DB0C0
void FUN_002db0c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1;
  if (param_1 != 0) {
    puVar1[2] = param_3;
    *puVar1 = param_2;
    puVar1[1] = &DAT_0049e9a8;
  }
  return;
}
#undef DAT_0049e9a8

#define DAT_0049e978 (D_0049E978[0])
// MATCH func_002DB108
void FUN_002db108(int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    *(undefined4 *)param_1 = param_2;
    ((undefined4 *)param_1)[1] = &DAT_0049e978;
  }
  return;
}
#undef DAT_0049e978

#define DAT_0049e968 (D_0049E968[0])
// MATCH func_002DB128
void FUN_002db128(int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    *(undefined4 *)param_1 = param_2;
    ((undefined4 *)param_1)[1] = &DAT_0049e968;
  }
  return;
}
#undef DAT_0049e968

#define DAT_0049e958 (D_0049E958[0])
// MATCH func_002DB148
void FUN_002db148(int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    *(undefined4 *)param_1 = param_2;
    ((undefined4 *)param_1)[1] = &DAT_0049e958;
  }
  return;
}
#undef DAT_0049e958

#define DAT_0049e948 (D_0049E948[0])
// MATCH func_002DB168
void FUN_002db168(int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    *(undefined4 *)param_1 = param_2;
    ((undefined4 *)param_1)[1] = &DAT_0049e948;
  }
  return;
}
#undef DAT_0049e948

// MATCH func_002DB9B0
undefined4 * FUN_002db9b0(void *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = _malloc_r(param_1,param_2 * 0x58 + 0xc);
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_2;
    *puVar1 = 0;
    puVar1[2] = puVar1 + 3;
    memset(puVar1 + 3,0,param_2 * 0x58);
    puVar2 = puVar1;
  }
  return puVar2;
}

// MATCH func_002DD4B0
int FUN_002dd4b0(char *param_1,char *param_2)

{
  int iVar1;
  
  iVar1 = strcmp(param_1,param_2);
  return iVar1;
}

// MATCH func_002E27F0
void FUN_002e27f0(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)param_2;
  if (param_2 != 0) {
    puVar1 = (undefined4 *)(puVar2[1] * 4 + *(int *)(param_1 + 0x4c));
    *puVar2 = *puVar1;
    *puVar1 = puVar2;
  }
  return;
}

// MATCH func_002E2A80
int FUN_002e2a80(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if ((param_1 & 0xffff0000) == 0) {
    iVar1 = 0x10;
    param_1 = param_1 << 0x10;
  }
  if ((param_1 & 0xff000000) == 0) {
    iVar1 = iVar1 + 8;
    param_1 = param_1 << 8;
  }
  if ((param_1 & 0xf0000000) == 0) {
    iVar1 = iVar1 + 4;
    param_1 = param_1 << 4;
  }
  if ((param_1 & 0xc0000000) == 0) {
    iVar1 = iVar1 + 2;
    param_1 = param_1 << 2;
  }
  if ((-1 < (int)param_1) && (iVar1 = iVar1 + 1, (param_1 & 0x40000000) == 0)) {
    return 0x20;
  }
  return iVar1;
}

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

#define DAT_00429878 (D_00429878[0])
// MATCH func_002E5D20
void FUN_002e5d20(void)

{
  DAT_00429878 = 0;
  return;
}
#undef DAT_00429878

// MATCH func_002E6058
undefined8 FUN_002e6058(undefined8 param_1,int param_2)

{
  *(undefined8 *)(param_2 + 0x48) = 0;
  *(undefined4 *)(param_2 + 4) = 0x2000;
  return 0;
}

// MATCH func_002E6218
void FUN_002e6218(uint param_1,uint param_2)

{
  FUN_002e60f0(param_1 & 0xffffffffffffffc0,param_2 & 0xffffffffffffffc0);
  return;
}

// MATCH func_002E6358
void FUN_002e6358(uint param_1,uint param_2)

{
  FUN_002e6230(param_1 & 0xffffffffffffffc0,param_2 & 0xffffffffffffffc0);
  return;
}

// MATCH func_002E79A0
void FUN_002e79a0(int param_1,int param_2)

{
  *(undefined4 *)(*(int *)(param_1 + 0x10) * 4 + *(int *)(param_2 + 0x1c)) =
       *(undefined4 *)(param_1 + 0x14);
  return;
}

// MATCH func_002E79C0
void FUN_002e79c0(int param_1,int param_2)

{
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 0x10);
  return;
}

#define DAT_00632980 (D_00632980[0])
// MATCH func_002E79D0
undefined4 FUN_002e79d0(int param_1)

{
  return *(undefined4 *)(&DAT_00632980 + param_1 * 4);
}
#undef DAT_00632980

#define DAT_00429890 (D_00429890[0])
// MATCH func_002E8288
void FUN_002e8288(void)

{
  FUN_002e7c98();
  DAT_00429890 = 0;
  return;
}
#undef DAT_00429890

// MATCH func_002E8358
void FUN_002e8358(int param_1)

{
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffffe;
  return;
}

// MATCH func_002E8DE8
int FUN_002e8de8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_002edc50();
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 4) = 0;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x3c);
    *(undefined4 *)(param_1 + 4) = 1;
    *(undefined4 *)(param_1 + 0xc) = uVar2;
  }
  FUN_002edc98();
  return iVar1;
}

#define DAT_00429918 (D_00429918[0])
#define DAT_00635568 (D_00635568[0])
// MATCH func_002E9918
undefined8 FUN_002e9918(void)

{
  DAT_00429918 = 0;
  memset(&DAT_00635568,0,4);
  return 0;
}
#undef DAT_00429918
#undef DAT_00635568

#define DAT_00429930 (D_00429930[0])
#define DAT_006359e8 (D_006359E8[0])
// MATCH func_002ECDD0
undefined8 FUN_002ecdd0(void)

{
  DAT_00429930 = 0xffffffff;
  memset(&DAT_006359e8,0,4);
  return 0;
}
#undef DAT_00429930
#undef DAT_006359e8

// MATCH func_002EDD08
undefined8 FUN_002edd08(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_3 >> 2 != 0) {
    do {
      uVar1 = *param_2;
      uVar2 = uVar2 + 1;
      param_2 = param_2 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    } while (uVar2 < param_3 >> 2);
  }
  return 0;
}

// MATCH func_002EDED8
void FUN_002eded8(void)

{
  FUN_002edcb0();
  FUN_002eddc8();
  FUN_002ee3a0();
  FUN_002e6678();
  FUN_002edfe8();
  FUN_002ee5c8();
  return;
}

// MATCH func_002EDF38
undefined8 FUN_002edf38(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_3 >> 2 != 0) {
    do {
      uVar1 = *param_2;
      uVar2 = uVar2 + 1;
      param_2 = param_2 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    } while (uVar2 < param_3 >> 2);
  }
  return 0;
}

// MATCH func_002EE0A8
undefined8 FUN_002ee0a8(undefined1 *param_1,undefined1 *param_2,uint param_3)

{
  undefined1 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_3 != 0) {
    do {
      uVar1 = *param_2;
      uVar2 = uVar2 + 1;
      param_2 = param_2 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    } while (uVar2 < param_3);
  }
  return 0;
}

// MATCH func_002EE2C0
void FUN_002ee2c0(int param_1)

{
  thunk_FUN_002ee750();
  _Exit(param_1);
  return;
}

// MATCH func_002EE358
undefined8 FUN_002ee358(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_3 >> 2 != 0) {
    do {
      uVar1 = *param_2;
      uVar2 = uVar2 + 1;
      param_2 = param_2 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    } while (uVar2 < param_3 >> 2);
  }
  return 0;
}

// MATCH func_002EE570
undefined8 FUN_002ee570(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_3 >> 2 != 0) {
    do {
      uVar1 = *param_2;
      uVar2 = uVar2 + 1;
      param_2 = param_2 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    } while (uVar2 < param_3 >> 2);
  }
  return 0;
}
