/* _unknown_after_noribs: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_00154170(void);
void FUN_001544f0(int param_1);
void FUN_00154ba0(void);
void FUN_0018eb78(undefined4 *param_1);
void FUN_0018ec18(undefined1 (*param_1) [16]);
void FUN_0018ed08(undefined1 (*param_1) [16]);
void FUN_0018ed30(undefined1 (*param_1) [16]);
void FUN_0018edb8(undefined1 (*param_1) [16], undefined1 (*param_2) [16]);
void FUN_0018f068(undefined1 (*param_1) [16], undefined1 (*param_2) [16]);
void FUN_0018f368(undefined1 (*param_1) [16], undefined1 (*param_2) [16], undefined1 (*param_3) [16]);

// MATCH func_00153B38
void FUN_00153b38(int param_1)

{
  FUN_0018edb8(param_1,param_1);
  return;
}

// MATCH func_00153C38
void FUN_00153c38(int param_1)

{
  FUN_0018ed08((int)param_1 + 0x10);
  FUN_001544f0(param_1);
  return;
}

// MATCH func_00154078
void FUN_00154078(int param_1,int param_2)

{
  FUN_0018f368(param_2,(int)param_1 + 0x40,param_2);
  FUN_0018f068(param_1,param_2);
  return;
}

// MATCH func_00154208
void FUN_00154208(float param_1,int param_2)

{
  FUN_00154170();
  *(float *)(param_2 + 0xd0) = *(float *)(param_2 + 0xd0) + param_1;
  return;
}

// MATCH func_001548C8
void FUN_001548c8(int *param_1,int param_2)

{
  *(int *)(param_2 + 0x80) = *param_1;
  *param_1 = param_2;
  return;
}

// MATCH func_00154B78
undefined8 FUN_00154b78(undefined8 param_1)

{
  FUN_00154ba0();
  return param_1;
}

// MATCH func_001556E8
void FUN_001556e8(int param_1)

{
  FUN_0018eb78(param_1 + 0x20);
  return;
}

// MATCH func_001556F0
void FUN_001556f0(int param_1)

{
  FUN_0018eb78(param_1 + 0x20);
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
