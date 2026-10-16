/* clas_min: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern uint D_004A14B8;
extern uint D_004A6A0C;
void FUN_00108b80(void);
void FUN_002492e8(void);
void clas_min_0029c900(undefined8 param_1);
void clas_min_0029cfb8(undefined8 param_1);
void clas_min_002a2f00(undefined8 param_1, long param_2, long param_3);
void clas_min_002a3a48(void);

// MATCH func_0029C4F8
int clas_min_0029c4f8(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x18);
  iVar1 = 0;
  do {
    if (*piVar2 == param_2) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 < 8);
  return -1;
}

// MATCH func_0029E918
void clas_min_0029e918(float param_1,float param_2,int param_3,int param_4)

{
  if (param_4 == 0) {
    if (*(float *)(param_3 + 0x30) == 0.0f) {
      *(float *)(param_3 + 0x18) = param_1;
    }
    if (*(float *)(param_3 + 0x34) == 0.0f) {
      *(float *)(param_3 + 0x1c) = param_2;
      return;
    }
  }
  else if (*(int *)(param_3 + 0x3c) == 0) {
    *(int *)(param_3 + 0x3c) = (int)param_4;
    if (*(float *)(param_3 + 0x30) == 0.0f) {
      *(float *)(param_3 + 0x10) = (param_1 - *(float *)(param_3 + 0x18)) / (float)(int)param_4;
    }
    if (*(float *)(param_3 + 0x34) == 0.0f) {
      *(float *)(param_3 + 0x14) =
           (param_2 - *(float *)(param_3 + 0x1c)) / (float)*(int *)(param_3 + 0x3c);
    }
  }
  return;
}

// MATCH func_0029E9C8
void clas_min_0029e9c8(int param_1)

{
  if (*(int *)(param_1 + 0x3c) != 0) {
    *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + -1;
    *(float *)(param_1 + 0x18) = *(float *)(param_1 + 0x18) + *(float *)(param_1 + 0x10);
    *(float *)(param_1 + 0x1c) = *(float *)(param_1 + 0x1c) + *(float *)(param_1 + 0x14);
  }
  return;
}

// MATCH func_0029F9F0
float clas_min_0029f9f0(int param_1)

{
  return *(float *)(param_1 + 0x6c) / *(float *)(param_1 + 0x6c);
}

// MATCH func_0029FA08
void clas_min_0029fa08(int param_1)

{
  *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x1000;
  return;
}

// MATCH func_0029FB60
void clas_min_0029fb60(void)

{
  D_004A14B8 = 0;
  FUN_002492e8();
  return;
}

// MATCH func_0029FDB8
int clas_min_0029fdb8(int param_1,int param_2)

{
  return param_2 * 0x260 + param_1;
}

// MATCH func_002A0190
void clas_min_002a0190(int param_1)

{
  clas_min_0029c900(param_1 + 0x50);
  clas_min_0029c900(param_1 + 0x80);
  clas_min_0029c900(param_1 + 0xb0);
  clas_min_0029cfb8(param_1 + 0xe0);
  clas_min_0029cfb8(param_1 + 0xf4);
  clas_min_0029cfb8(param_1 + 0x108);
  clas_min_0029cfb8(param_1 + 0x11c);
  clas_min_0029cfb8(param_1 + 0x204);
  clas_min_0029cfb8(param_1 + 0x218);
  clas_min_0029cfb8(param_1 + 0x22c);
  return;
}

// MATCH func_002A2EF0
void clas_min_002a2ef0(int param_1,undefined4 param_2,undefined8 param_3)

{
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  clas_min_002a2f00(param_1,param_3,1);
  return;
}

// MATCH func_002A3268
void clas_min_002a3268(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x20) = param_2;
  D_004A6A0C = 0;
  return;
}

// MATCH func_002A39D0
undefined8 clas_min_002a39d0(undefined8 param_1)

{
  clas_min_002a3a48();
  return param_1;
}

// MATCH func_002A3FF0
void clas_min_002a3ff0(undefined8 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}

// MATCH func_002A60E0
void clas_min_002a60e0(int param_1,undefined4 param_2,int param_3)

{
  *(undefined4 *)(param_1 + 0x54) = param_2;
  *(undefined4 *)(param_1 + 0x74) = 0;
  if (param_3 == 0) {
    *(undefined4 *)(param_1 + 0x58) = param_2;
    return;
  }
  *(int *)(param_1 + 0x58) = (int)param_3;
  return;
}
