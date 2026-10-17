/* yue: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern byte D_0035A780[];
extern int D_0044CAE8[];
extern int D_004A12A4;
undefined * FUN_001e52b0(int param_1, int);
void FUN_001e7cb0(uint param_1);
undefined8 akari_001e23b8(void);
void akari_001e2628(int param_1, int param_2);

#define DAT_0044cae8 (D_0044CAE8[0])
// MATCH func_001E7EC8
int yue_001e7ec8(int param_1)

{
  int iVar1;
  
  akari_001e23b8();
  iVar1 = (int)param_1;
  *(undefined **)(iVar1 + 100) = &DAT_0044cae8;
  *(undefined4 *)(iVar1 + 0x78) = 3;
  *(undefined4 *)(iVar1 + 0x7c) = 2;
  *(undefined4 *)(iVar1 + 0x350) = 0;
  *(undefined4 *)(iVar1 + 0x354) = 0;
  *(undefined4 *)(iVar1 + 0x358) = 0;
  *(undefined4 *)(iVar1 + 0x35c) = 0;
  *(undefined4 *)(iVar1 + 0x360) = 0;
  *(undefined4 *)(iVar1 + 0x364) = 0;
  *(undefined4 *)(iVar1 + 0x368) = 0;
  return param_1;
}
#undef DAT_0044cae8

// MATCH func_001E7F98
void yue_001e7f98(int param_1,int param_2)

{
  if (-1 < param_2) {
    *(int *)(param_1 + 0x80) = (int)param_2;
  }
  return;
}

// MATCH func_001E7FA8
void yue_001e7fa8(int param_1,int param_2)

{
  if (-1 < param_2) {
    *(int *)(param_1 + 0x74) = (int)param_2;
  }
  return;
}

// MATCH func_001E7FB8
void yue_001e7fb8(int param_1,int param_2)

{
  if (-1 < param_2) {
    *(int *)(param_1 + 0x8c) = (int)param_2;
  }
  return;
}

// MATCH func_001E7FC8
void yue_001e7fc8(int param_1,int param_2)

{
  if (-1 < param_2) {
    *(int *)(param_1 + 0x70) = (int)param_2;
  }
  return;
}

// MATCH func_001E7FD8
void yue_001e7fd8(int param_1,int param_2)

{
  if (-1 < param_2) {
    *(int *)(param_1 + 0x94) = (int)param_2;
  }
  return;
}

#define DAT_0035a780 (D_0035A780[0])
// MATCH func_001E9338
void yue_001e9338(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((-1 < param_2) && ((iVar1 = (int)param_1, 0 < *(int *)(iVar1 + 0x88) || (D_004A12A4 == 7))))
  {
    FUN_001e7cb0(*(undefined4 *)(iVar1 + 0x84));
    *(int *)(iVar1 + 0x84) = (int)param_2;
    FUN_001e52b0(param_2,param_3);
    akari_001e2628(param_1,&DAT_0035a780 + (int)param_2 * 0x100);
    return;
  }
  return;
}
#undef DAT_0035a780

// MATCH func_001EA270
int yue_001ea270(int param_1)

{
  return *(int *)(param_1 + 0x78) * *(int *)(param_1 + 0x7c);
}
