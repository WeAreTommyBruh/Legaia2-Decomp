/* _unknown_after_shikimi_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern char D_002CB588[];
extern char D_002DAB40[];
extern char D_002DB890[];
extern int D_00426364[];
extern int D_0042637C[];
extern int D_00427DB0[];
extern undefined * D_004293F4[];
extern int D_00429890[];
extern int D_00429918[];
extern int D_0042991C[];
extern int D_00429930[];
extern int D_00429938[];
extern int D_0049E690[];
extern int D_0049E828[];
extern float D_004A1018;
extern float D_004A101C;
extern int D_004A7428[];
extern char D_0062B8D8[];
extern byte D_00635568[];
extern byte D_006359E8[];
void Deci2Call(int, int);
void FUN_001001c8(int);
void FUN_00108b80(void);
float FUN_0015fb58(float param_1, int param_2);
void FUN_002c15f8(undefined8 *param_1);
undefined8 FUN_002c2d58(long param_1, int *param_2);
void FUN_002c33d8(undefined8 param_1);
void FUN_002c35c8(long param_1, undefined8 param_2);
undefined2 FUN_002c6fa8(int param_1, int param_2);
void FUN_002c7228(undefined8 param_1, uint param_2);
uint FUN_002c7318(undefined8 param_1, uint param_2);
undefined4 FUN_002c9368(void);
void FUN_002c9388(uint *param_1, int param_2);
undefined4 FUN_002cb640(undefined8 *param_1, char *param_2, undefined4 param_3);
undefined4 FUN_002ccf20(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, int param_5);
void FUN_002ce8f0(void);
void FUN_002ce960(undefined8 param_1, uint param_2, int param_3);
undefined * FUN_002cff38(void);
int FUN_002cff48(void);
void FUN_002cff60(int param_1, undefined4 param_2);
undefined4 FUN_002cff78(int param_1);
undefined4 FUN_002cffb0(void);
void FUN_002d3a08(undefined8 param_1, uint param_2, uint param_3, uint param_4);
void FUN_002d62c8(void);
int FUN_002d63a8(void);
void FUN_002d7e48(undefined8 param_1, undefined8 param_2);
undefined4 FUN_002da4e0(void);
int FUN_002db188(code *param_1, code *param_2, undefined8 param_3, undefined8 param_4, code *param_5, undefined8 param_6);
undefined * FUN_002db948(void);
void FUN_002db958(undefined4 *param_1, undefined2 param_2, undefined2 param_3, undefined4 param_4);
void FUN_002dbb00(undefined8 param_1);
void * FUN_002dbc48(uint param_1);
void FUN_002dbc70(void);
undefined4 FUN_002dca08(void *param_1);
undefined4 FUN_002dca78(undefined8 param_1, uint param_2, undefined4 param_3);
undefined4 FUN_002dcbf8(undefined8 param_1, ulong param_2);
void FUN_002dccb0(undefined8 param_1);
uint FUN_002ddb58(undefined4 *param_1, char *param_2, undefined4 *param_3, int param_4);
int FUN_002e04b8(int *param_1, undefined8 param_2);
undefined8 FUN_002e18f8(void);
undefined * FUN_002e2388(int param_1, undefined4 param_2, int param_3);
undefined ** FUN_002e2410(int);
long FUN_002e3768(int *param_1, undefined8 param_2, undefined8 param_3, undefined8 param_4);
void FUN_002e48a8(undefined8 param_1, undefined8 param_2);
uint FUN_002e4900(undefined4 *param_1, char *param_2, int param_3, int param_4);
undefined4 FUN_002e5f98(int, int, int);
undefined4 FUN_002e6070(void);
void FUN_002e7c98(void);
void FUN_002e7d00(int param_1, undefined4 param_2, undefined4 param_3);
int FUN_002e8378(void);
void FUN_002e9560(void);
undefined4 FUN_002ea9f0(char *param_1, undefined8 param_2);
undefined4 FUN_002ec868(void);
undefined4 FUN_002ece08(void);
bool FUN_002edc50(void);
bool FUN_002edc98(void);
void FUN_002edcf8(int, int, int);
void FUN_002ee2c0(int param_1);
undefined4 SndVoiceSetParam(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);
void WaitSema(int);
void * _malloc_r(void *reent, uint size);
void * memset(void *dst, int c, uint n);
undefined4 sceGsPutDrawEnv(undefined8 *param_1);
int sprintf(char *dst, char *fmt);
int strcmp(char *a, char *b);
int vfprintf(void *fp, char *fmt, void *ap);

// MATCH func_002BC930
float FUN_002bc930(float param_1,float param_2)

{
  float fVar1;
  
  fVar1 = (float)FUN_0015fb58((param_1 * D_004A1018) / param_2 - D_004A101C,0);
  return (fVar1 + 1.0f) * 0.5f * param_2;
}

// MATCH func_002C0240
void FUN_002c0240(int param_1,uint param_2)

{
  FUN_002c15f8((param_2 & 1) * 0x28 + param_1);
  if (!((param_2 & 1) == 0)) {
    sceGsPutDrawEnv(param_1 + 0x140);
  }
  else {
    sceGsPutDrawEnv(param_1 + 0x50);
  }
  return;
}

// MATCH func_002C1598
void FUN_002c1598(int param_1,uint param_2)

{
  FUN_002c15f8((param_2 & 1) * 0x28 + param_1);
  if (!((param_2 & 1) == 0)) {
    sceGsPutDrawEnv(param_1 + 0x1c0);
  }
  else {
    sceGsPutDrawEnv(param_1 + 0x50);
  }
  return;
}

// MATCH func_002C2DA8
void FUN_002c2da8(undefined8 param_1)

{
  undefined4 auStack_30 [8];
  
  auStack_30[0] = 1;
  FUN_002c2d58(param_1,auStack_30);
  return;
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

// MATCH func_002C3590
void FUN_002c3590(undefined8 param_1,char *param_2)

{
  char acStack_120 [256];
  
  sprintf(acStack_120,param_2);
  FUN_002c35c8(param_1,acStack_120);
  return;
}

// MATCH func_002C5E60
void FUN_002c5e60(int param_1)

{
  FUN_002c6fa8(param_1,3);
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

// MATCH func_002C9420
int FUN_002c9420(int param_1,int param_2)

{
  int uVar1;
  
  uVar1 = FUN_002c9368();
  FUN_002c9388(param_1,param_2);
  return uVar1;
}

#define DAT_00426364 (D_00426364[0])
#define DAT_0042637c (D_0042637C[0])
// MATCH func_002CB5C8
undefined4 FUN_002cb5c8(void)

{
  int lVar1;
  
  DAT_00426364 = 1;
  lVar1 = FUN_002edc50();
  FUN_002e7d00(0xffffffff80000012,((int)D_002CB588),0);
  if (lVar1 != 0) {
    FUN_002edc98();
  }
  DAT_00426364 = 0;
  DAT_0042637c = 1;
  return 1;
}
#undef DAT_00426364
#undef DAT_0042637c

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
// MATCH func_002CB958
int sceCdSearchFile(void *file,char *name)

{
  int iVar1;
  
  iVar1 = FUN_002cb640(file,name,0);
  return iVar1;
}

#define DAT_00427db0 (D_00427DB0[0])
// MATCH func_002CCBD8
void FUN_002ccbd8(int param_1,int param_2)

{
  DAT_00427db0 = 1;
  FUN_002ccf20(param_1,0,0,1,param_2);
  return;
}
#undef DAT_00427db0

#define DAT_00427db0 (D_00427DB0[0])
// MATCH func_002CCC70
void FUN_002ccc70(void)

{
  DAT_00427db0 = 0;
  FUN_002ccf20(0,0,0,3,((int)D_0062B8D8));
  return;
}
#undef DAT_00427db0

// MATCH func_002CF018
uint FUN_002cf018(uint *param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 1) {
    uVar1 = *param_1 >> 8 & 1;
  }
  else {
    FUN_002ce8f0();
    uVar1 = 0;
  }
  return uVar1;
}

// MATCH func_002CF050
bool FUN_002cf050(int param_1,uint param_2,int param_3,int param_4)

{
  bool bVar1;
  
  if (param_3 == 1) {
    bVar1 = *(uint *)(param_1 + 0x10) < param_2;
  }
  else {
    FUN_002ce960(param_1,param_2,param_4);
    bVar1 = false;
  }
  return bVar1;
}

// MATCH func_002D39B0
int FUN_002d39b0(int param_1,int param_2,int param_3)

{
  FUN_002d3a08(0x20,param_1,param_2,param_3);
  return 0;
}

// MATCH func_002D39E0
int FUN_002d39e0(int param_1,int param_2,int param_3)

{
  FUN_002d3a08(0x21,param_2,param_1,param_3);
  return 0;
}

// MATCH func_002D4058
void FUN_002d4058(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_002cff38();
  *(undefined2 *)(iVar1 + 0x38) = param_1;
  return;
}

// MATCH func_002D4080
void FUN_002d4080(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_002cff38();
  *(undefined2 *)(iVar1 + 0x3a) = param_1;
  return;
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

// MATCH func_002D50E0
int FUN_002d50e0(uint param_1)

{
  int uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 < 0x30) {
    SndVoiceSetParam(0x3f,param_1,0,0);
    uVar1 = 0;
  }
  return uVar1;
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

// MATCH func_002D53F0
int FUN_002d53f0(uint param_1)

{
  int uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 < 0x10) {
    SndVoiceSetParam(0x49,param_1,0,0);
    uVar1 = 0;
  }
  return uVar1;
}

// MATCH func_002D54C8
int FUN_002d54c8(uint param_1,uint param_2)

{
  int uVar1;
  
  uVar1 = 0xffffffff;
  if ((param_1 < 0x10) && (param_2 < 0x200000)) {
    SndVoiceSetParam(0x4d,param_1,param_2,0);
    uVar1 = 0;
  }
  return uVar1;
}

// MATCH func_002D6140
undefined8 FUN_002d6140(int param_1)

{
  FUN_002d7e48(*(undefined8 *)(param_1 + 8),*(undefined8 *)(param_1 + 8));
  return 0;
}

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

// MATCH func_002D8250
void FUN_002d8250(void)

{
  FUN_002dbc70();
  return;
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

#define DAT_0049e690 (D_0049E690[0])
// MATCH func_002D8780
void FUN_002d8780(undefined4 *param_1,uint param_2)

{
  *param_1 = &DAT_0049e690;
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
  }
  return;
}
#undef DAT_0049e690

#define DAT_0049e690 (D_0049E690[0])
// MATCH func_002D8818
void FUN_002d8818(undefined4 *param_1,uint param_2)

{
  *param_1 = &DAT_0049e690;
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
  }
  return;
}
#undef DAT_0049e690

#define DAT_0049e828 (D_0049E828[0])
// MATCH func_002DA4B0
void FUN_002da4b0(int param_1,uint param_2)

{
  *(undefined **)(param_1 + 4) = &DAT_0049e828;
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
  }
  return;
}
#undef DAT_0049e828

#define DAT_0049e690 (D_0049E690[0])
// MATCH func_002DA9D0
void FUN_002da9d0(undefined4 *param_1,uint param_2)

{
  *param_1 = &DAT_0049e690;
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
  }
  return;
}
#undef DAT_0049e690

#define DAT_0049e690 (D_0049E690[0])
// MATCH func_002DAA68
void FUN_002daa68(undefined4 *param_1,uint param_2)

{
  *param_1 = &DAT_0049e690;
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
  }
  return;
}
#undef DAT_0049e690

// MATCH func_002DAB00
uint FUN_002dab00(void)

{
  uint uVar1;
  
  uVar1 = FUN_002da4e0();
  return uVar1 ^ 1;
}

// MATCH func_002DAB80
uint FUN_002dab80(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  
  uVar1 = strcmp((char *)*param_1,(char *)*param_2);
  return uVar1 >> 0x1f;
}

// MATCH func_002DB070
bool FUN_002db070(int param_1)

{
  short *psVar1;
  int lVar2;
  
  lVar2 = 0;
  if (param_1 != 0) {
    psVar1 = *(short **)((int)param_1 + 4);
    lVar2 = FUN_002db188(*(undefined4 *)(psVar1 + 2),((int)D_002DB890),1,(int)param_1 + (int)*psVar1,((int)D_002DAB40)
                         ,param_1);
  }
  return lVar2 != 0;
}

// MATCH func_002DB900
void FUN_002db900(void)

{
  do {
    FUN_002dccb0(6);
    FUN_001001c8(1);
  } while( true );
}

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

// MATCH func_002DBB20
void FUN_002dbb20(int param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(code **)(iVar1 + 0x3c) = FUN_002dbb00;
  *(undefined4 *)(iVar1 + 0x38) = 1;
  FUN_002db958(iVar1 + 0x1e4,4,0,param_1);
  FUN_002db958(iVar1 + 0x23c,9,1,param_1);
  FUN_002db958(iVar1 + 0x294,10,2,param_1);
  *(int *)(iVar1 + 0x1e0) = iVar1 + 0x1e4;
  *(undefined4 *)(iVar1 + 0x1dc) = 3;
  *(undefined4 *)(iVar1 + 0x1d8) = 0;
  return;
}

#define PTR_DAT_004293f4 (D_004293F4[0])
// MATCH func_002DCCD8
void FUN_002dccd8(int param_1,int param_2)

{
  FUN_002dca78(PTR_DAT_004293f4,param_1,param_2);
  return;
}
#undef PTR_DAT_004293f4

#define PTR_DAT_004293f4 (D_004293F4[0])
// MATCH func_002DCD08
void FUN_002dcd08(void)

{
  FUN_002dca08(PTR_DAT_004293f4);
  return;
}
#undef PTR_DAT_004293f4

#define PTR_DAT_004293f4 (D_004293F4[0])
// MATCH func_002DCD30
void FUN_002dcd30(undefined8 param_1)

{
  FUN_002dcbf8(PTR_DAT_004293f4,param_1);
  return;
}
#undef PTR_DAT_004293f4

// MATCH func_002DCDB8
void FUN_002dcdb8(void)

{
  FUN_002e6070();
  return;
}

// MATCH func_002DCF40
int FUN_002dcf40(int param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = FUN_002e3768(*(undefined4 *)(param_1 + 0x54),*(short *)(param_1 + 0xe),param_2,
                       param_3);
  if (!(iVar1 < 0)) {
    *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + iVar1;
  }
  else {
    *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) & 0xefff;
  }
  return iVar1;
}

// MATCH func_002DD090
void FUN_002dd090(int param_1)

{
  FUN_002e04b8(*(undefined4 *)(param_1 + 0x54),*(short *)(param_1 + 0xe));
  return;
}

// MATCH func_002DD4B0
int FUN_002dd4b0(char *param_1,char *param_2)

{
  int iVar1;
  
  iVar1 = strcmp(param_1,param_2);
  return iVar1;
}

#define PTR_DAT_004293f4 (D_004293F4[0])
// MATCH func_002DDD90
void FUN_002ddd90(int param_1,int param_2,int param_3)

{
  FUN_002ddb58(PTR_DAT_004293f4,param_1,param_2,param_3);
  return;
}
#undef PTR_DAT_004293f4

#define PTR_DAT_004293f4 (D_004293F4[0])
// MATCH func_002E02F8
int FUN_002e02f8(char *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = vfprintf(*(void **)(PTR_DAT_004293f4 + 8),param_1,param_2);
  return iVar1;
}
#undef PTR_DAT_004293f4

// MATCH func_002E0498
void FUN_002e0498(undefined8 param_1)

{
  FUN_002e48a8(param_1,0);
  return;
}

#define PTR_DAT_004293f4 (D_004293F4[0])
// MATCH func_002E2420
void FUN_002e2420(int param_1,int param_2)

{
  FUN_002e2388(PTR_DAT_004293f4,param_1,param_2);
  return;
}
#undef PTR_DAT_004293f4

#define PTR_DAT_004293f4 (D_004293F4[0])
// MATCH func_002E2450
void FUN_002e2450(void)

{
  FUN_002e2410(PTR_DAT_004293f4);
  return;
}
#undef PTR_DAT_004293f4

#define DAT_004a7428 (D_004A7428[0])
// MATCH func_002E2478
int FUN_002e2478(int *param_1,int param_2,int param_3,int param_4)

{
  int lVar1;
  
  DAT_004a7428 = 0;
  lVar1 = FUN_002e5f98(param_2,param_3,param_4);
  if ((lVar1 == -1) && (DAT_004a7428 != 0)) {
    *param_1 = DAT_004a7428;
  }
  return lVar1;
}
#undef DAT_004a7428

// MATCH func_002E37C8
void FUN_002e37c8(void)

{
  FUN_002e18f8();
  return;
}

#define PTR_DAT_004293f4 (D_004293F4[0])
// MATCH func_002E4B20
void FUN_002e4b20(int param_1,int param_2,int param_3)

{
  FUN_002e4900(PTR_DAT_004293f4,param_1,param_2,param_3);
  return;
}
#undef PTR_DAT_004293f4

// MATCH func_002E5F60
int FUN_002e5f60(void)

{
  int *puVar1;
  
  puVar1 = (int *)FUN_002db948();
  *puVar1 = 5;
  return 0xffffffff;
}

// MATCH func_002E6078
int FUN_002e6078(int param_1,int param_2)

{
  if (param_1 == 1) {
    FUN_002ee2c0(param_2);
  }
  return 0;
}

// MATCH func_002E60A0
int FUN_002e60a0(void)

{
  int *puVar1;
  
  puVar1 = (int *)FUN_002db948();
  *puVar1 = 5;
  return 0xffffffff;
}

// MATCH func_002E60C8
int FUN_002e60c8(void)

{
  int *puVar1;
  
  puVar1 = (int *)FUN_002db948();
  *puVar1 = 5;
  return 0xffffffff;
}

// MATCH func_002E6948
void FUN_002e6948(undefined4 param_1)

{
  undefined4 auStack_20 [4];
  
  auStack_20[0] = param_1;
  Deci2Call(2,auStack_20);
  return;
}

// MATCH func_002E69A0
void FUN_002e69a0(undefined4 param_1)

{
  undefined4 auStack_20 [4];
  
  auStack_20[0] = param_1;
  Deci2Call(4,auStack_20);
  return;
}

// MATCH func_002E6A68
void FUN_002e6a68(undefined4 param_1)

{
  undefined4 auStack_20 [4];
  
  auStack_20[0] = param_1;
  Deci2Call(0xfffffffffffffff8,auStack_20);
  return;
}

// MATCH func_002E6A90
void FUN_002e6a90(undefined4 param_1)

{
  undefined4 auStack_20 [4];
  
  auStack_20[0] = param_1;
  Deci2Call(0xfffffffffffffff7,auStack_20);
  return;
}

// MATCH func_002E6AB8
void FUN_002e6ab8(undefined4 param_1)

{
  undefined4 auStack_20 [4];
  
  auStack_20[0] = param_1;
  Deci2Call(0x10,auStack_20);
  return;
}

#define DAT_00429890 (D_00429890[0])
// MATCH func_002E8288
void FUN_002e8288(void)

{
  FUN_002e7c98();
  DAT_00429890 = 0;
  return;
}
#undef DAT_00429890

// MATCH func_002E83A8
int FUN_002e83a8(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 < 0) || (*(int *)(param_1 + 0x20) <= param_2)) {
    iVar1 = FUN_002e8378();
  }
  else {
    iVar1 = *(int *)(param_1 + 0x1c) + param_2 * 0x40;
  }
  return iVar1;
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

#define DAT_0042991c (D_0042991C[0])
// MATCH func_002E95B0
undefined8 FUN_002e95b0(void)

{
  FUN_002e9560();
  WaitSema(DAT_0042991c);
  return 0;
}
#undef DAT_0042991c

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

// MATCH func_002EAB98
void FUN_002eab98(int param_1)

{
  FUN_002ea9f0(param_1,6);
  return;
}

// MATCH func_002EAD68
void FUN_002ead68(int param_1)

{
  FUN_002ea9f0(param_1,8);
  return;
}

// MATCH func_002EB118
void FUN_002eb118(int param_1)

{
  FUN_002ea9f0(param_1,0x10);
  return;
}

// MATCH func_002EBA90
void FUN_002eba90(int param_1)

{
  FUN_002ea9f0(param_1,0x12);
  return;
}

// MATCH func_002EBEB8
void FUN_002ebeb8(int param_1)

{
  FUN_002ea9f0(param_1,0x15);
  return;
}

// MATCH func_002EC8E0
void FUN_002ec8e0(void)

{
  FUN_002ec868();
  return;
}

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

// MATCH func_002ED3F8
void FUN_002ed3f8(void)

{
  FUN_002ece08();
  return;
}

#define DAT_00429938 (D_00429938[0])
// MATCH func_002EDD90
undefined4 FUN_002edd90(int param_1)

{
  undefined4 auStack_20 [4];
  
  FUN_002edcf8(auStack_20,DAT_00429938 + param_1 * 4,4);
  return auStack_20[0];
}
#undef DAT_00429938
