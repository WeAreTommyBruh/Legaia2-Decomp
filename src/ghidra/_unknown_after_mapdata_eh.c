/* _unknown_after_mapdata_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

void FUN_0015a570(int param_1, undefined4 param_2);
bool FUN_0015bf90(undefined4 *param_1);
undefined4 FUN_0015c7f0(undefined4 param_1);
int FUN_0015d788(int param_1);
int FUN_0015d8b0(int param_1);
int FUN_0015dba8(int param_1);
int FUN_0015dc68(int param_1);
int FUN_0015de00(int param_1);
undefined4 FUN_0015deb0(int param_1);
int FUN_0018b508(undefined1 *param_1, undefined8 param_2);

// MATCH func_0015A5C0
void FUN_0015a5c0(int param_1,int param_2)

{
  int uVar1;
  undefined1 auStack_30 [16];
  
  if (param_2 == 0) {
    FUN_0015a570(param_1,0);
  }
  else {
    uVar1 = FUN_0018b508(param_2,auStack_30);
    FUN_0015a570(param_1,uVar1);
  }
  return;
}

// MATCH func_0015A888
void FUN_0015a888(undefined4 *param_1)

{
  FUN_0015bf90(*param_1);
  return;
}

// MATCH func_0015A8A8
void FUN_0015a8a8(undefined4 *param_1)

{
  FUN_0015c7f0(*param_1);
  return;
}

// MATCH func_0015A8C8
void FUN_0015a8c8(undefined4 *param_1)

{
  FUN_0015d788(*param_1);
  return;
}

// MATCH func_0015A908
void FUN_0015a908(undefined4 *param_1)

{
  FUN_0015dba8(*param_1);
  return;
}

// MATCH func_0015A928
void FUN_0015a928(undefined4 *param_1)

{
  FUN_0015d8b0(*param_1);
  return;
}

// MATCH func_0015A968
void FUN_0015a968(undefined4 *param_1)

{
  FUN_0015dc68(*param_1);
  return;
}

// MATCH func_0015A988
void FUN_0015a988(undefined4 *param_1)

{
  FUN_0015de00(*param_1);
  return;
}

// MATCH func_0015DE90
void FUN_0015de90(undefined4 *param_1)

{
  FUN_0015deb0(*param_1);
  return;
}
