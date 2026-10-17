/* _unknown_after_pstack: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern byte D_003E2010[];
extern char D_003E9DF0[];
extern char D_003EC550[];
extern short D_003FED1C[];
extern int D_00401028[];
extern int D_004257D4[];
extern int D_004A1A20;
void FUN_00108b80(void);
bool FUN_0024dae8(undefined8 param_1);
undefined4 FUN_0024e098(int param_1);
undefined4 * FUN_0024f380(void);
undefined4 * FUN_0024f8a0(void);
undefined4 * FUN_0024f9a0(void);
undefined4 * FUN_0024faa0(void);
undefined4 * FUN_0024fc70(void);
undefined4 * FUN_00250388(void);
char FUN_00250c00(uint param_1);
undefined4 FUN_00250da0(int);
void FUN_002523d8(uint param_1);
undefined4 FUN_00254990(uint param_1);
void FUN_00255278(uint param_1);
undefined * FUN_00255c68(void);
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

// MATCH func_00250E90
char FUN_00250e90(void)

{
  int iVar1;
  
  iVar1 = FUN_0024f380();
  return *(char *)(iVar1 + 0x62);
}

// MATCH func_00250EB0
char FUN_00250eb0(void)

{
  int iVar1;
  
  iVar1 = FUN_0024fc70();
  return *(char *)(iVar1 + 0x62);
}

// MATCH func_00250ED0
char FUN_00250ed0(void)

{
  int iVar1;
  
  iVar1 = FUN_00250388();
  return *(char *)(iVar1 + 0x62);
}

// MATCH func_00250FB0
char FUN_00250fb0(void)

{
  int iVar1;
  
  iVar1 = FUN_0024f380();
  return *(char *)(iVar1 + 99);
}

// MATCH func_00250FD0
char FUN_00250fd0(void)

{
  int iVar1;
  
  iVar1 = FUN_0024fc70();
  return *(char *)(iVar1 + 99);
}

// MATCH func_00250FF0
char FUN_00250ff0(void)

{
  int iVar1;
  
  iVar1 = FUN_00250388();
  return *(char *)(iVar1 + 99);
}

// MATCH func_00251010
char FUN_00251010(void)

{
  int iVar1;
  
  iVar1 = FUN_0024f8a0();
  return *(char *)(iVar1 + 100);
}

// MATCH func_00251030
char FUN_00251030(void)

{
  int iVar1;
  
  iVar1 = FUN_0024fc70();
  return *(char *)(iVar1 + 100);
}

// MATCH func_00251050
char FUN_00251050(void)

{
  int iVar1;
  
  iVar1 = FUN_00250388();
  return *(char *)(iVar1 + 100);
}

// MATCH func_00251070
char FUN_00251070(void)

{
  int iVar1;
  
  iVar1 = FUN_0024faa0();
  return *(char *)(iVar1 + 0x65);
}

// MATCH func_00251090
char FUN_00251090(void)

{
  int iVar1;
  
  iVar1 = FUN_0024fc70();
  return *(char *)(iVar1 + 0x65);
}

// MATCH func_002510B0
char FUN_002510b0(void)

{
  int iVar1;
  
  iVar1 = FUN_00250388();
  return *(char *)(iVar1 + 0x65);
}

// MATCH func_002510D0
char FUN_002510d0(void)

{
  int iVar1;
  
  iVar1 = FUN_0024f9a0();
  return *(char *)(iVar1 + 0x66);
}

// MATCH func_002510F0
char FUN_002510f0(void)

{
  int iVar1;
  
  iVar1 = FUN_0024fc70();
  return *(char *)(iVar1 + 0x66);
}

// MATCH func_00251110
char FUN_00251110(void)

{
  int iVar1;
  
  iVar1 = FUN_00250388();
  return *(char *)(iVar1 + 0x66);
}

// MATCH func_00251F28
char FUN_00251f28(void)

{
  int iVar1;
  
  iVar1 = FUN_0024f380();
  return *(char *)(iVar1 + 0x69);
}

// MATCH func_00251F48
char FUN_00251f48(void)

{
  int iVar1;
  
  iVar1 = FUN_0024fc70();
  return *(char *)(iVar1 + 0x69);
}

// MATCH func_00251F68
char FUN_00251f68(void)

{
  int iVar1;
  
  iVar1 = FUN_00250388();
  return *(char *)(iVar1 + 0x69);
}

// MATCH func_00251F88
char FUN_00251f88(void)

{
  int iVar1;
  
  iVar1 = FUN_0024f8a0();
  return *(char *)(iVar1 + 0x67);
}

// MATCH func_00251FA8
char FUN_00251fa8(void)

{
  int iVar1;
  
  iVar1 = FUN_0024fc70();
  return *(char *)(iVar1 + 0x67);
}

// MATCH func_00251FC8
char FUN_00251fc8(void)

{
  int iVar1;
  
  iVar1 = FUN_00250388();
  return *(char *)(iVar1 + 0x67);
}

// MATCH func_00252080
short FUN_00252080(void)

{
  int iVar1;
  
  iVar1 = FUN_0024f380();
  return *(short *)(iVar1 + 0x40);
}

// MATCH func_002520A0
short FUN_002520a0(void)

{
  int iVar1;
  
  iVar1 = FUN_0024fc70();
  return *(short *)(iVar1 + 0x40);
}

// MATCH func_002520C0
short FUN_002520c0(void)

{
  int iVar1;
  
  iVar1 = FUN_00250388();
  return *(short *)(iVar1 + 0x40);
}

// MATCH func_002520E0
short FUN_002520e0(void)

{
  int iVar1;
  
  iVar1 = FUN_0024f380();
  return *(short *)(iVar1 + 0x42);
}

// MATCH func_00252100
short FUN_00252100(void)

{
  int iVar1;
  
  iVar1 = FUN_0024fc70();
  return *(short *)(iVar1 + 0x42);
}

// MATCH func_00252120
short FUN_00252120(void)

{
  int iVar1;
  
  iVar1 = FUN_00250388();
  return *(short *)(iVar1 + 0x42);
}

// MATCH func_00252140
short FUN_00252140(void)

{
  int iVar1;
  
  iVar1 = FUN_0024f380();
  return *(short *)(iVar1 + 0x44);
}

// MATCH func_00252160
short FUN_00252160(void)

{
  int iVar1;
  
  iVar1 = FUN_0024fc70();
  return *(short *)(iVar1 + 0x44);
}

// MATCH func_00252180
short FUN_00252180(void)

{
  int iVar1;
  
  iVar1 = FUN_00250388();
  return *(short *)(iVar1 + 0x44);
}

// MATCH func_002521A0
short FUN_002521a0(void)

{
  int iVar1;
  
  iVar1 = FUN_0024f380();
  return *(short *)(iVar1 + 0x46);
}

// MATCH func_002521C0
short FUN_002521c0(void)

{
  int iVar1;
  
  iVar1 = FUN_0024fc70();
  return *(short *)(iVar1 + 0x46);
}

// MATCH func_002521E0
short FUN_002521e0(void)

{
  int iVar1;
  
  iVar1 = FUN_00250388();
  return *(short *)(iVar1 + 0x46);
}

// MATCH func_00252200
short FUN_00252200(void)

{
  int iVar1;
  
  iVar1 = FUN_0024f380();
  return *(short *)(iVar1 + 0x48);
}

// MATCH func_00252220
short FUN_00252220(void)

{
  int iVar1;
  
  iVar1 = FUN_0024fc70();
  return *(short *)(iVar1 + 0x48);
}

// MATCH func_00252240
short FUN_00252240(void)

{
  int iVar1;
  
  iVar1 = FUN_00250388();
  return *(short *)(iVar1 + 0x48);
}

// MATCH func_00252260
short FUN_00252260(void)

{
  int iVar1;
  
  iVar1 = FUN_0024f380();
  return *(short *)(iVar1 + 0x4a);
}

// MATCH func_00252280
short FUN_00252280(void)

{
  int iVar1;
  
  iVar1 = FUN_0024fc70();
  return *(short *)(iVar1 + 0x4a);
}

// MATCH func_002522A0
short FUN_002522a0(void)

{
  int iVar1;
  
  iVar1 = FUN_00250388();
  return *(short *)(iVar1 + 0x4a);
}

// MATCH func_002522C0
short FUN_002522c0(void)

{
  int iVar1;
  
  iVar1 = FUN_0024f380();
  return *(short *)(iVar1 + 0x4c);
}

// MATCH func_002522E0
short FUN_002522e0(void)

{
  int iVar1;
  
  iVar1 = FUN_0024fc70();
  return *(short *)(iVar1 + 0x4c);
}

// MATCH func_00252300
short FUN_00252300(void)

{
  int iVar1;
  
  iVar1 = FUN_00250388();
  return *(short *)(iVar1 + 0x4c);
}

// MATCH func_00252320
short FUN_00252320(void)

{
  int iVar1;
  
  iVar1 = FUN_0024f380();
  return *(short *)(iVar1 + 0x4e);
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

// MATCH func_00255DE8
char FUN_00255de8(undefined8 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_00255c68();
  return *(char *)(param_2 * 2 + iVar1);
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

// MATCH func_002561F8
short FUN_002561f8(void)

{
  int iVar1;
  
  iVar1 = FUN_002560a8();
  return *(short *)(iVar1 + 8);
}

// MATCH func_00256218
undefined4 FUN_00256218(void)

{
  int iVar1;
  
  iVar1 = FUN_002560a8();
  return *(undefined4 *)(iVar1 + 0xc);
}

// MATCH func_00256240
char FUN_00256240(void)

{
  int iVar1;
  
  iVar1 = FUN_002560a8();
  return *(char *)(iVar1 + 0xb);
}

// MATCH func_0025A470
int FUN_0025a470(int param_1)

{
  return param_1 * 0x50 + ((int)D_003EC550);
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

// MATCH func_0025A7D0
int FUN_0025a7d0(int param_1)

{
  return param_1 * 0xa8 + ((int)D_003E9DF0);
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
