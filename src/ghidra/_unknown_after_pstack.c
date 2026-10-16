/* _unknown_after_pstack: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern byte D_003E2010[];
extern short D_003FED1C[];
extern int D_00401028[];
extern int D_004257D4[];
extern int D_004A1A20;
void FUN_00108b80(void);
bool FUN_0024dae8(undefined8 param_1);
undefined4 FUN_0024e098(int param_1);
undefined4 * FUN_0024f380(void);
undefined4 * FUN_0024fc70(void);
undefined4 * FUN_00250388(void);
char FUN_00250c00(uint param_1);
undefined4 FUN_00250da0(int);
undefined1 FUN_00251070(void);
undefined1 FUN_00251090(void);
undefined1 FUN_002510b0(void);
void FUN_002523d8(uint param_1);
undefined4 FUN_00254990(uint param_1);
void FUN_00255278(uint param_1);
undefined4 * FUN_002560a8(void);
undefined4 FUN_0025a688(uint param_1);
uint FUN_0025dce0(uint param_1);
void FUN_0029b758(void);

// MATCH func_0024DA70
void FUN_0024da70(void)

{
  int lVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  do {
    lVar1 = FUN_0024e098(iVar2);
    if (lVar1 == 0) {
      lVar1 = FUN_0024dae8(iVar2);
      if (lVar1 != 0) {
        *(uint *)(iVar3 + D_004A1A20 + 0x12d0) =
             *(uint *)(iVar3 + D_004A1A20 + 0x12d0) | 0x1000000;
      }
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x1560;
  } while (iVar2 < 10);
  return;
}

// MATCH func_0024F108
void FUN_0024f108(void)

{
  int lVar1;
  int iVar2;
  
  iVar2 = 1;
  FUN_00255278(6);
  do {
    lVar1 = FUN_00250c00(iVar2);
    if ((lVar1 == 0) && (lVar1 = FUN_00250da0(iVar2), -1 < lVar1)) {
      FUN_00254990(iVar2);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x12d);
  iVar2 = 0x12d;
  do {
    lVar1 = FUN_00250da0(iVar2);
    if (-1 < lVar1) {
      FUN_00254990(iVar2);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x6c2);
  FUN_00255278(5);
  return;
}

#define DAT_00401028 (D_00401028[0])
#define DAT_003fed1c (D_003FED1C[0])
// MATCH func_00250B18
uint FUN_00250b18(uint param_1)

{
  uint uVar1;
  ushort *puVar2;
  
  puVar2 = &DAT_00401028;
  uVar1 = 0;
  do {
    if ((ushort)(&DAT_003fed1c)[*puVar2] == param_1) {
      return uVar1;
    }
    uVar1 = uVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (uVar1 < 0x4b0);
  return 0x4c0;
}
#undef DAT_00401028
#undef DAT_003fed1c

// MATCH func_00250CE0
undefined4 FUN_00250ce0(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_0024f380();
  return *puVar1;
}

// MATCH func_00250D00
undefined4 FUN_00250d00(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_0024fc70();
  return *puVar1;
}

// MATCH func_00250D20
undefined4 FUN_00250d20(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00250388();
  return *puVar1;
}

// MATCH func_00250D40
undefined4 FUN_00250d40(void)

{
  int iVar1;
  
  iVar1 = FUN_0024f380();
  return *(undefined4 *)(iVar1 + 4);
}

// MATCH func_00250D60
undefined4 FUN_00250d60(void)

{
  int iVar1;
  
  iVar1 = FUN_0024fc70();
  return *(undefined4 *)(iVar1 + 4);
}

// MATCH func_00250D80
undefined4 FUN_00250d80(void)

{
  int iVar1;
  
  iVar1 = FUN_00250388();
  return *(undefined4 *)(iVar1 + 4);
}

// MATCH func_00250DC0
undefined4 FUN_00250dc0(void)

{
  int iVar1;
  
  iVar1 = FUN_0024fc70();
  return *(undefined4 *)(iVar1 + 0x38);
}

// MATCH func_00250DE0
undefined4 FUN_00250de0(void)

{
  int iVar1;
  
  iVar1 = FUN_00250388();
  return *(undefined4 *)(iVar1 + 0x38);
}

// MATCH func_00250E00
int FUN_00250e00(void)

{
  int iVar1;
  
  iVar1 = FUN_0024f380();
  return (*(int *)(iVar1 + 0x38) + 1) / 2;
}

// MATCH func_00250E30
int FUN_00250e30(void)

{
  int iVar1;
  
  iVar1 = FUN_0024fc70();
  return (*(int *)(iVar1 + 0x38) + 1) / 2;
}

// MATCH func_00250E60
int FUN_00250e60(void)

{
  int iVar1;
  
  iVar1 = FUN_00250388();
  return (*(int *)(iVar1 + 0x38) + 1) / 2;
}

// MATCH func_00251E88
bool FUN_00251e88(void)

{
  uint uVar1;
  
  uVar1 = FUN_00251070();
  return (uVar1 & 0x60) != 0;
}

// MATCH func_00251ED8
bool FUN_00251ed8(void)

{
  uint uVar1;
  
  uVar1 = FUN_00251090();
  return (uVar1 & 0x60) != 0;
}

// MATCH func_00251F00
bool FUN_00251f00(void)

{
  uint uVar1;
  
  uVar1 = FUN_002510b0();
  return (uVar1 & 0x60) != 0;
}

// MATCH func_00252340
int FUN_00252340(void)

{
  int iVar1;
  
  iVar1 = FUN_0024f380();
  return iVar1 + 0x50;
}

// MATCH func_00252360
int FUN_00252360(void)

{
  int iVar1;
  
  iVar1 = FUN_0024fc70();
  return iVar1 + 0x50;
}

// MATCH func_00252380
int FUN_00252380(void)

{
  int iVar1;
  
  iVar1 = FUN_00250388();
  return iVar1 + 0x50;
}

// MATCH func_002523A0
void FUN_002523a0(void)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    FUN_002523d8(iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 10);
  return;
}

// MATCH func_00253FF8
bool FUN_00253ff8(int param_1)

{
  return param_1 < 300;
}

// MATCH func_002561B8
undefined4 FUN_002561b8(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_002560a8();
  return *puVar1;
}

// MATCH func_002561D8
undefined4 FUN_002561d8(void)

{
  int iVar1;
  
  iVar1 = FUN_002560a8();
  return *(undefined4 *)(iVar1 + 4);
}

// MATCH func_00256218
undefined4 FUN_00256218(void)

{
  int iVar1;
  
  iVar1 = FUN_002560a8();
  return *(undefined4 *)(iVar1 + 0xc);
}

// MATCH func_0025A798
void FUN_0025a798(void)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    FUN_0025a688(iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x40);
  return;
}

#define DAT_003e2010 (D_003E2010[0])
// MATCH func_0025D0D8
undefined1 * FUN_0025d0d8(int param_1)

{
  return &DAT_003e2010 + param_1 * 0x1c;
}
#undef DAT_003e2010

// MATCH func_0025DD18
int FUN_0025dd18(void)

{
  int lVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 1;
  do {
    lVar1 = FUN_0025dce0(iVar2);
    iVar2 = iVar2 + 1;
    if (lVar1 != 0) {
      iVar3 = iVar3 + 1;
    }
  } while (iVar2 < 0x700);
  return iVar3;
}

#define DAT_004257d4 (D_004257D4[0])
// MATCH func_0025DD68
void FUN_0025dd68(void)

{
  DAT_004257d4 = 0;
  FUN_0029b758();
  return;
}
#undef DAT_004257d4

// MATCH func_0025DDC8
void FUN_0025ddc8(undefined8 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}

// MATCH func_0025E900
void FUN_0025e900(int param_1)

{
  (**(code **)(param_1 + 0x28))(param_1 + *(short *)(param_1 + 0x24));
  return;
}
