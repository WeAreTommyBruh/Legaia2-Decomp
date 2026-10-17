/* _unknown_after_mapdata: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern uint D_004A12A4;
extern char * D_004A1360;
extern char * D_004A1364;
void FUN_00110490(void);
void FUN_0015a570(int param_1, undefined4 param_2);
void FUN_0015e060(void);
int FUN_0018b508(undefined1 *param_1, undefined8 param_2);
void MemFree(void *ptr);
void init_0024a510(void);
int * mapdata_0015a1f8(undefined8 param_1, undefined8 param_2, undefined8 param_3);

// MATCH func_0015A578
void FUN_0015a578(int param_1,int param_2,int param_3)

{
  int uVar1;
  
  uVar1 = FUN_0018b508(param_2,0);
  mapdata_0015a1f8(param_1,uVar1,param_3);
  return;
}

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

// MATCH func_0015AA68
int FUN_0015aa68(int param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(undefined4 *)(iVar1 + 0x120) = 0;
  *(undefined4 *)(iVar1 + 0x138) = 0;
  *(undefined4 *)(iVar1 + 0x144) = 0;
  return param_1;
}

// MATCH func_0015ACE0
int FUN_0015ace0(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1;
  *puVar1 = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[7] = 0;
  puVar1[9] = 0;
  puVar1[10] = 0;
  puVar1[0xb] = 0;
  return param_1;
}

// MATCH func_0015DEB0
undefined4 FUN_0015deb0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 8)) {
    iVar2 = *(int *)(param_1 + 4);
    do {
      iVar1 = iVar1 + 1;
      if ((*(short *)(iVar2 + 0x4a) == param_2) && (param_3 = param_3 + -1, param_3 == -1)) {
        return *(undefined4 *)(iVar2 + 0x120);
      }
      iVar2 = iVar2 + 0x150;
    } while (iVar1 < *(int *)(param_1 + 8));
  }
  return 0;
}

// MATCH func_0015DFA8
void FUN_0015dfa8(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_0015DFC0
void FUN_0015dfc0(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_0015E038
void FUN_0015e038(void)

{
  D_004A1360 = FUN_00110490;
  D_004A1364 = FUN_0015e060;
  D_004A12A4 = 0xd;
  init_0024a510();
  return;
}
