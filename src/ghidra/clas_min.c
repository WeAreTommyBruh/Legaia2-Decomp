/* clas_min: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_004A69A8;
extern int D_005F9640[];
void FUN_00108b80(int param_1);
void FUN_002a63e8(void);
void FUN_002bc990(undefined8 param_1);
void clas_min_0029c900(undefined8 param_1);
void clas_min_0029cfb8(undefined8 param_1);
void clas_min_002a3dd8(void);
void work_002468d8(int param_1);

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

// MATCH func_0029D640
int clas_min_0029d640(int param_1)

{
  if (*(int *)(param_1 + 0x3c) != 0) {
    return *(int *)(*(int *)(param_1 + 0x3c) + 0x2c);
  }
  return 0xffffffff;
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

// MATCH func_0029FD70
void clas_min_0029fd70(int *param_1)

{
  if (param_1[0x7d] != -1) {
    work_002468d8(*param_1);
    FUN_002bc990(*param_1);
    return;
  }
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

// MATCH func_002A1310
int clas_min_002a1310(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1;
  puVar1[1] = param_2;
  puVar1[2] = param_3;
  puVar1[3] = param_4;
  puVar1[4] = param_5;
  puVar1[5] = param_6;
  puVar1[6] = param_7;
  puVar1[7] = param_8;
  puVar1[8] = param_9;
  *puVar1 = 0;
  return param_1;
}

// MATCH func_002A2090
int clas_min_002a2090(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1;
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[9] = 0;
  puVar1[10] = 0;
  puVar1[0xb] = 0;
  return param_1;
}

// MATCH func_002A39F8
void clas_min_002a39f8(int param_1,int param_2)

{
  clas_min_002a3dd8();
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}

#define DAT_005f9640 (D_005F9640[0])
// MATCH func_002A3F78
undefined4 clas_min_002a3f78(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < D_004A69A8) {
    puVar1 = &DAT_005f9640;
    do {
      if (((((puVar1[0x7c] & 4) != 0) && (puVar1[0x90] != 0)) &&
          (*(short *)(puVar1[0x90] + 0x4a) == param_1)) && (param_2 = param_2 + -1, param_2 == -1))
      {
        return *puVar1;
      }
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 0x98;
    } while (iVar2 < D_004A69A8);
  }
  return 0;
}
#undef DAT_005f9640

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

// MATCH func_002A6110
void clas_min_002a6110(int param_1,int param_2)

{
  FUN_002a63e8();
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}
