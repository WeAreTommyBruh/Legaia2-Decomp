/* _unknown_after_decode_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern char D_003215D0[];
void FUN_00191618(undefined8 param_1);
void FUN_00191658(undefined8 param_1);
undefined4 FUN_00192168(int param_1);
undefined4 FUN_00192268(int param_1);
int FUN_00192300(int param_1);
bool FUN_00194900(void);
undefined4 FUN_002c2008(void);
undefined4 FUN_002c2b20(int);
undefined8 FUN_002d5488(uint param_1);
void SignalSema(int);
void WaitSema(int);

// MATCH func_00190FC0
undefined4 FUN_00190fc0(void)

{
  FUN_00191618(0);
  return 1;
}

// MATCH func_00190FE0
void FUN_00190fe0(undefined4 *param_1)

{
  FUN_00191658(0);
  FUN_002d5488(3);
  *param_1 = 3;
  return;
}

// MATCH func_001922C0
undefined4 FUN_001922c0(int param_1)

{
  undefined4 uVar1;
  
  WaitSema(*(undefined4 *)(param_1 + 0x40));
  uVar1 = *(undefined4 *)(param_1 + 0x44);
  SignalSema(*(undefined4 *)(param_1 + 0x40));
  return uVar1;
}

// MATCH func_001926F8
undefined4 FUN_001926f8(int param_1)

{
  FUN_00192268((int)param_1 + 0x48);
  FUN_002c2b20(param_1);
  return 1;
}

// MATCH func_00192908
undefined4 FUN_00192908(void)

{
  FUN_002c2008();
  return 1;
}

// MATCH func_001929A0
void FUN_001929a0(int param_1)

{
  FUN_00192300(param_1 + 0x48);
  return;
}

// MATCH func_00192BB8
undefined4 FUN_00192bb8(void)

{
  FUN_00192168(((int)D_003215D0));
  return 1;
}

// MATCH func_00194988
int FUN_00194988(int *param_1)

{
  int iVar1;
  int lVar2;
  
  lVar2 = FUN_00194900();
  if (lVar2 == 0) {
    iVar1 = *param_1 + param_1[2] * 0x195000;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}
