/* _unknown_after_shikimi: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern undefined * D_00427DE0[];
extern undefined * D_00427EF8[];
extern undefined * D_004284EC[];
extern undefined * D_004293F4[];
extern int D_00429878[];
extern int D_0042AC40[];
extern int D_0049E7C8[];
extern int D_0049E7E0[];
extern int D_0049E948[];
extern int D_0049E958[];
extern int D_0049E968[];
extern int D_0049E978[];
extern int D_0049E9A8[];
extern float D_004A0F74;
extern uint D_004A72BC;
extern uint D_004A72C0;
extern int D_00620120[];
extern char D_0062CF40[];
extern char D_0062D540[];
extern char D_0062E5C0[];
extern byte D_00631840[];
extern int D_00631AA8[];
extern byte D_00632980[];
void FUN_001001c8(int);
void FUN_00108b80(int param_1);
void FUN_001540c0(undefined4 param_1);
void FUN_00154118(undefined4 param_1);
void FUN_00154170(undefined4 param_1);
void FUN_00154268(undefined8 param_1);
void FUN_00154388(undefined4 param_1);
void FUN_002a88e0(int param_1, int, int, int);
void FUN_002bf270(undefined8 param_1, uint param_2);
void FUN_002c33c8(int param_1);
void FUN_002c34b8(int param_1);
uint FUN_002c7318(undefined8 param_1, uint param_2);
undefined * FUN_002cff38(void);
void FUN_002cffe0(void);
void FUN_002d6190(void);
void FUN_002d61e8(void);
void FUN_002da018(undefined4 param_1, undefined4 *param_2);
void FUN_002da070(undefined4 param_1, undefined4 *param_2);
int * FUN_002da0c8(void);
void FUN_002dbb10(void);
void * FUN_002dbc48(uint param_1);
void FUN_002dbc70(undefined8 param_1);
void FUN_002e60f0(uint param_1, uint param_2);
void FUN_002e6230(uint param_1, uint param_2);
int FUN_002e6678(void);
void FUN_002edcb0(void);
void FUN_002eddc8(void);
void FUN_002edfe8(void);
int FUN_002ee0e8(void);
void FUN_002ee3a0(void);
void FUN_002ee5c8(void);
void MemFree(void *ptr);
undefined4 SndVoiceSetParam(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);
void _LoadExecPS2(int, int, int);
void clas_min_002a6160(void);
void thunk_FUN_002ee750(void);

// MATCH func_002B9C00
float FUN_002b9c00(float param_1)

{
  param_1 = param_1 - (float)(int)(param_1 / D_004A0F74) * D_004A0F74;
  if (param_1 < 0.0f) {
    param_1 = param_1 + D_004A0F74;
  }
  if (D_004A0F74 <= param_1) {
    param_1 = param_1 - D_004A0F74;
  }
  return param_1;
}

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

// MATCH func_002BDE18
void FUN_002bde18(int param_1,int param_2)

{
  FUN_002bf270((int)param_1 + 0x14,2);
  FUN_002bf270(param_1,2);
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}

// MATCH func_002BDEC8
void FUN_002bdec8(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  FUN_002bf270(iVar1 + 0xdc,2);
  FUN_002bf270(iVar1 + 200,2);
  FUN_002bf270(iVar1 + 0xb4,2);
  FUN_002bf270(iVar1 + 0xa0,2);
  FUN_002bf270(iVar1 + 0x8c,2);
  FUN_002bf270(iVar1 + 0x78,2);
  FUN_002bf270(iVar1 + 100,2);
  FUN_002bf270(iVar1 + 0x50,2);
  FUN_002bf270(iVar1 + 0x3c,2);
  FUN_002bf270(iVar1 + 0x28,2);
  FUN_002bf270(iVar1 + 0x14,2);
  FUN_002bf270(param_1,2);
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}

// MATCH func_002BDFA0
void FUN_002bdfa0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  FUN_002bf270(iVar1 + 0x78,2);
  FUN_002bf270(iVar1 + 100,2);
  FUN_002bf270(iVar1 + 0x50,2);
  FUN_002bf270(iVar1 + 0x3c,2);
  FUN_002bf270(iVar1 + 0x28,2);
  FUN_002bf270(iVar1 + 0x14,2);
  FUN_002bf270(param_1,2);
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}

// MATCH func_002BEA50
void FUN_002bea50(int param_1)

{
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined4 *)(param_1 + 4) = 3;
  }
  clas_min_002a6160();
  return;
}

// MATCH func_002BEB38
void FUN_002beb38(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 0x100);
  if (iVar1 != 0) {
    FUN_002beb38(iVar1,3);
  }
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}

// MATCH func_002BEB90
void FUN_002beb90(int param_1,int param_2)

{
  if (*(int *)param_1 != 0) {
    FUN_002beb90(*(int *)param_1,3);
  }
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}

// MATCH func_002BEDD8
void FUN_002bedd8(float param_1,float param_2,float param_3,int param_4)

{
  FUN_002a88e0(param_4,(int)param_1,(int)param_2,(int)param_3);
  return;
}

// MATCH func_002BF0B0
void FUN_002bf0b0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)param_1;
  if (iVar1 != 0) {
    FUN_002bf0b0(iVar1,3);
  }
  *(int *)param_1 = 0;
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}

// MATCH func_002BF130
void FUN_002bf130(int param_1,int param_2)

{
  FUN_002bf270((int)param_1 + 0x28,2);
  FUN_002bf270((int)param_1 + 0x14,2);
  FUN_002bf270(param_1,2);
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}

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

// MATCH func_002BF410
void FUN_002bf410(undefined4 *param_1,uint param_2)

{
  if ((param_2 & param_1[0xb]) != 0) {
    FUN_00154388(*param_1);
    return;
  }
  return;
}

// MATCH func_002BF458
void FUN_002bf458(int *param_1,int param_2)

{
  if ((param_2 & param_1[9]) != 0) {
    FUN_00154268(*param_1);
    return;
  }
  return;
}

// MATCH func_002BF4A0
void FUN_002bf4a0(undefined4 *param_1,uint param_2)

{
  if ((param_2 & param_1[5]) != 0) {
    FUN_00154170(*param_1);
    return;
  }
  return;
}

// MATCH func_002BF4E8
void FUN_002bf4e8(undefined4 *param_1,uint param_2)

{
  if ((param_2 & param_1[3]) != 0) {
    FUN_00154118(*param_1);
    return;
  }
  return;
}

// MATCH func_002BF530
void FUN_002bf530(undefined4 *param_1,uint param_2)

{
  if ((param_2 & param_1[1]) != 0) {
    FUN_001540c0(*param_1);
    return;
  }
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

// MATCH func_002C2C78
bool FUN_002c2c78(int param_1)

{
  return *(int *)(*(int *)(param_1 + 0x40) + 4) == 0;
}

// MATCH func_002C2C88
void FUN_002c2c88(int param_1)

{
  int *puVar1;
  
  puVar1 = *(int **)(param_1 + 0x40);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  *(int *)(param_1 + 8) = 0;
  puVar1[0x2b] = 0;
  puVar1[0x20] = 0xffffffff;
  FUN_002c34b8(puVar1);
  puVar1[0x46] = 0;
  FUN_002c33c8(puVar1);
  return;
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

// MATCH func_002C2DF8
void FUN_002c2df8(int param_1,undefined4 param_2)

{
  *(undefined4 *)(*(int *)(param_1 + 0x40) + 0xd8) = param_2;
  return;
}

// MATCH func_002C2E48
undefined4 FUN_002c2e48(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x40) + 0xe8);
  *(undefined4 *)(*(int *)(param_1 + 0x40) + 0xe8) = param_2;
  return uVar1;
}

// MATCH func_002C2F18
int FUN_002c2f18(int *param_1)

{
  return (*param_1 + param_1[1]) - param_1[2];
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

#define PTR_REG_DMAC_0_VIF0_CHCR_00427de0 (D_00427DE0[0])
// MATCH func_002CEA48
undefined * FUN_002cea48(uint param_1)

{
  if (param_1 < 10) {
    return (&PTR_REG_DMAC_0_VIF0_CHCR_00427de0)[(int)param_1];
  }
  return (undefined *)0x0;
}
#undef PTR_REG_DMAC_0_VIF0_CHCR_00427de0

// MATCH func_002CF120
uint FUN_002cf120(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *param_1;
  *param_1 = param_2;
  return uVar1 >> 8 & 1;
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

// MATCH func_002CFF08
int FUN_002cff08(int param_1)

{
  return param_1 * 0x58 + ((int)D_0062D540);
}

// MATCH func_002CFF20
int FUN_002cff20(int param_1)

{
  return param_1 * 0x54 + ((int)D_0062E5C0);
}

// MATCH func_002CFF48
int FUN_002cff48(int param_1)

{
  return param_1 * 0xc + ((int)D_0062CF40);
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

// MATCH func_002D35F0
uint FUN_002d35f0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  return (param_1 & 0xff) +
         (int)(((param_2 & 0xff) - (param_1 & 0xff)) * (param_4 & 0xff)) / (int)(param_3 & 0xff) &
         0xff;
}

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

#define PTR_FUN_00427ef8 (D_00427EF8[0])
// MATCH func_002D6380
void FUN_002d6380(void)

{
  (*(code *)PTR_FUN_00427ef8)();
  return;
}
#undef PTR_FUN_00427ef8

#define PTR_FUN_00427ef8 (D_00427EF8[0])
// MATCH func_002D63A8
int FUN_002d63a8(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_FUN_00427ef8)();
  return iVar1 + 8;
}
#undef PTR_FUN_00427ef8

#define PTR_FUN_00427ef8 (D_00427EF8[0])
// MATCH func_002D6460
int FUN_002d6460(void)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_FUN_00427ef8)();
  return iVar1 + 4;
}
#undef PTR_FUN_00427ef8

// MATCH func_002D7228
void FUN_002d7228(int param_1)

{
  FUN_002d6190();
  FUN_002dbb10();
  FUN_001001c8(param_1);
  return;
}

#define PTR_FUN_004284ec (D_004284EC[0])
// MATCH func_002D8180
undefined * FUN_002d8180(undefined *param_1)

{
  undefined *puVar1;
  
  puVar1 = PTR_FUN_004284ec;
  PTR_FUN_004284ec = param_1;
  return puVar1;
}
#undef PTR_FUN_004284ec

// MATCH func_002D8758
undefined4 FUN_002d8758(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 4))();
  return *puVar1;
}

// MATCH func_002DA040
void FUN_002da040(int param_1)

{
  int uVar1;
  
  uVar1 = FUN_002dbc48(0x18);
  FUN_002da018(param_1,uVar1);
  return;
}

// MATCH func_002DA098
void FUN_002da098(int param_1)

{
  int uVar1;
  
  uVar1 = FUN_002dbc48(0x18);
  FUN_002da070(param_1,uVar1);
  return;
}

// MATCH func_002DA140
void FUN_002da140(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_002da0c8();
  FUN_002dbc70(uVar1);
  return;
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

#define PTR_DAT_004293f4 (D_004293F4[0])
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
// MATCH func_002DC968
void srand(uint seed)

{
  *(uint *)(PTR_DAT_004293f4 + 0x58) = seed;
  return;
}
#undef PTR_DAT_004293f4

#define PTR_DAT_004293f4 (D_004293F4[0])
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
// MATCH func_002DC978
int rand(void)

{
  uint uVar1;
  
  uVar1 = *(int *)(PTR_DAT_004293f4 + 0x58) * 0x41c64e6d + 0x3039;
  *(uint *)(PTR_DAT_004293f4 + 0x58) = uVar1;
  return uVar1 & 0x7fffffff;
}
#undef PTR_DAT_004293f4

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

#define DAT_00632980 (D_00632980[0])
// MATCH func_002E79E8
int FUN_002e79e8(int param_1,int param_2)

{
  *(int *)(&DAT_00632980 + param_1 * 4) = (int)param_2;
  return param_2;
}
#undef DAT_00632980

// MATCH func_002E8358
void FUN_002e8358(int param_1)

{
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffffe;
  return;
}

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

#define DAT_0042ac40 (D_0042AC40[0])
// MATCH func_002EE278
void FUN_002ee278(int param_1,int param_2)

{
  int uVar1;
  
  uVar1 = FUN_002ee0e8();
  thunk_FUN_002ee750();
  _LoadExecPS2(uVar1,param_2,DAT_0042ac40 + 4);
  return;
}
#undef DAT_0042ac40

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
