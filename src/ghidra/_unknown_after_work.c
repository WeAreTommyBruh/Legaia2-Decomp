/* _unknown_after_work: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern uint D_004A14B8;
extern uint D_004A14BC;
extern uint D_004A1514;
void FUN_0018f1f8(undefined1 (*param_1) [16]);
void FUN_0018f208(undefined1 (*param_1) [16]);
void FUN_0018f3d8(undefined1 (*param_1) [16],undefined1 (*param_2) [16],undefined1 (*param_3) [16]);
void FUN_00248960(undefined1 (*param_1) [16],undefined1 (*param_2) [16],undefined1 (*param_3) [16]);
void FUN_002489d8(undefined1 (*param_1) [16]);
void MemFree(void *ptr);
void thunk_FUN_0018ec38(undefined1 (*param_1) [16]);

// MATCH func_00246FD0
void FUN_00246fd0(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_002478B8
void FUN_002478b8(uint param_1)

{
  D_004A14BC = D_004A14BC & ~param_1;
  return;
}

// MATCH func_002478D0
void FUN_002478d0(uint param_1)

{
  D_004A14BC = D_004A14BC | param_1;
  return;
}

// MATCH func_00247C88
void FUN_00247c88(void)

{
  D_004A1514 = D_004A1514 | 2;
  return;
}

// MATCH func_002489F0
void FUN_002489f0(void)

{
  FUN_00248960(0x70003d40,0x70003c00,0x70003f80);
  FUN_00248960(0x70003fc0,0x70003bc0,0x70003d40);
  FUN_002489d8(0x70003fc0);
  return;
}

// MATCH func_00248A48
void FUN_00248a48(void)

{
  FUN_002489d8(0x70003f80);
  return;
}

// MATCH func_002492A0
void FUN_002492a0(void)

{
  FUN_0018f208(0x70003c40);
  FUN_0018f3d8(0x70003d00,0x70003cc0,0x70003c80);
  FUN_0018f1f8(0x70003d00);
  return;
}

// MATCH func_00249390
void FUN_00249390(void)

{
  thunk_FUN_0018ec38(0x70003f80);
  thunk_FUN_0018ec38(0x70003d80);
  thunk_FUN_0018ec38(0x70003c80);
  D_004A14B8 = 0;
  return;
}

// MATCH func_002498E0
void FUN_002498e0(float *param_1,float *param_2)

{
  *param_1 = *param_1 + *param_2;
  param_1[1] = param_1[1] + param_2[1];
  param_1[2] = param_1[2] + param_2[2];
  return;
}

// MATCH func_00249918
void FUN_00249918(float *param_1,float *param_2,float *param_3)

{
  *param_1 = *param_2 + *param_3;
  param_1[1] = param_2[1] + param_3[1];
  param_1[2] = param_2[2] + param_3[2];
  return;
}

// MATCH func_00249950
void FUN_00249950(float *param_1,float *param_2)

{
  *param_1 = *param_1 - *param_2;
  param_1[1] = param_1[1] - param_2[1];
  param_1[2] = param_1[2] - param_2[2];
  return;
}

// MATCH func_00249988
void FUN_00249988(float *param_1,float *param_2,float *param_3)

{
  *param_1 = *param_2 - *param_3;
  param_1[1] = param_2[1] - param_3[1];
  param_1[2] = param_2[2] - param_3[2];
  return;
}

// MATCH func_00249D70
void FUN_00249d70(undefined2 *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = *param_2;
  fVar2 = param_2[1];
  fVar1 = param_2[2];
  param_1[3] = (short)(int)param_2[3];
  *param_1 = (short)(int)fVar3;
  param_1[1] = (short)(int)fVar2;
  param_1[2] = (short)(int)fVar1;
  return;
}
