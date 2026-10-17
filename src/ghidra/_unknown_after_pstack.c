/* _unknown_after_pstack: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern byte D_003E2010[];
extern char D_003E9DF0[];
extern char D_003EC550[];
extern short D_003FED1C[];
extern int D_00401028[];
void FUN_00108b80(void);
char FUN_00250c00(uint param_1);
undefined4 FUN_00250da0(int);
undefined4 FUN_00254990(uint param_1);
void FUN_00255278(uint param_1);

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

// MATCH func_00253FF8
bool FUN_00253ff8(int param_1)

{
  return param_1 < 300;
}

// MATCH func_0025A470
int FUN_0025a470(int param_1)

{
  return param_1 * 0x50 + ((int)D_003EC550);
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
