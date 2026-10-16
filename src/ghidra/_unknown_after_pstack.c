/* _unknown_after_pstack: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern byte D_003E2010[];
extern short D_003FED1C[];
extern int D_00401028[];
extern int D_004A1A20;
bool FUN_0024dae8(undefined8 param_1);
undefined4 FUN_0024e098(int param_1);
undefined1 FUN_00251070(void);
undefined1 FUN_00251090(void);
undefined1 FUN_002510b0(void);
void FUN_002523d8(uint param_1);
undefined4 FUN_0025a688(uint param_1);
uint FUN_0025dce0(uint param_1);

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

// MATCH func_0025E900
void FUN_0025e900(int param_1)

{
  (**(code **)(param_1 + 0x28))(param_1 + *(short *)(param_1 + 0x24));
  return;
}
