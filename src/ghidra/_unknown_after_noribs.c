/* _unknown_after_noribs: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_00153b38(undefined8 param_1);
void FUN_001544f0(int param_1);
void FUN_00154550(int param_1);
void FUN_0018ec18(undefined1 (*param_1) [16]);
void FUN_0018ed08(undefined1 (*param_1) [16]);
void FUN_0018ed30(undefined1 (*param_1) [16]);
void FUN_0018f068(undefined1 (*param_1) [16], undefined1 (*param_2) [16]);
void FUN_0018f368(undefined1 (*param_1) [16], undefined1 (*param_2) [16], undefined1 (*param_3) [16]);
void func_00155988(undefined4 *param_1);
void func_00155990(undefined4 *param_1);

// MATCH func_00153C38
void FUN_00153c38(int param_1)

{
  FUN_0018ed08((int)param_1 + 0x10);
  FUN_001544f0(param_1);
  return;
}

// MATCH func_00153FB8
void FUN_00153fb8(int param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1 + 0xc0;
  func_00155990(iVar1);
  FUN_00153b38(iVar1);
  FUN_00154550(param_1);
  return;
}

// MATCH func_00153FF8
void FUN_00153ff8(int param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1 + 0xc0;
  func_00155988(iVar1);
  FUN_00153b38(iVar1);
  FUN_00154550(param_1);
  return;
}

// MATCH func_00154078
void FUN_00154078(int param_1,int param_2)

{
  FUN_0018f368(param_2,(int)param_1 + 0x40,param_2);
  FUN_0018f068(param_1,param_2);
  return;
}

// MATCH func_001548C8
void FUN_001548c8(int *param_1,int param_2)

{
  *(int *)(param_2 + 0x80) = *param_1;
  *param_1 = param_2;
  return;
}

// MATCH func_00155888
void FUN_00155888(int param_1)

{
  FUN_0018ec18(param_1 + 0x20);
  FUN_0018ed30(param_1 + 0x20);
  return;
}

// MATCH func_001558B8
void FUN_001558b8(int param_1)

{
  FUN_0018ec18(param_1 + 0x20);
  FUN_0018ed30(param_1 + 0x20);
  return;
}
