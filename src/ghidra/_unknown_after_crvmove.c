/* _unknown_after_crvmove: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_0043C7E8[];
void FUN_00108b80(int param_1);
undefined4 FUN_00163068(int param_1);
int FUN_001630b8(int, int);
void MemFree(void *ptr);
int strcmp(char *a, char *b);

// MATCH func_00162F68
void FUN_00162f68(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 0xc);
  if (iVar1 != 0) {
    FUN_00162f68(iVar1,3);
  }
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}

// MATCH func_00162FC0
undefined4 FUN_00162fc0(undefined8 param_1,float *param_2,float *param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((*param_2 == *param_3) && (param_2[1] == param_3[1])) && (param_2[2] == param_3[2])) {
    uVar1 = 1;
  }
  return uVar1;
}

// MATCH func_00163050
void FUN_00163050(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_00163150
int FUN_00163150(int param_1,int param_2)

{
  int iVar1;
  char *a;
  int iVar2;
  int iVar3;
  
  if ((param_2 == 0) || (*(char *)param_2 == '\0')) {
    iVar2 = -1;
  }
  else {
    iVar1 = FUN_00163068(param_1);
    for (iVar3 = 0; iVar3 < iVar1; iVar3 = iVar3 + 1) {
      a = (char *)FUN_001630b8(param_1,iVar3);
      iVar2 = strcmp(a,(char *)param_2);
      if (iVar2 == 0) break;
    }
    iVar2 = -1;
    if (iVar3 < iVar1) {
      iVar2 = iVar3;
    }
  }
  return iVar2;
}

#define DAT_0043c7e8 (D_0043C7E8[0])
// MATCH func_00163D48
int FUN_00163d48(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1;
  puVar1[0x16] = 0;
  puVar1[0x1a] = &DAT_0043c7e8;
  puVar1[0x19] = 0;
  *puVar1 = 0;
  return param_1;
}
#undef DAT_0043c7e8

#define DAT_0043c7e8 (D_0043C7E8[0])
// MATCH func_00163D68
int FUN_00163d68(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1;
  puVar1[0x19] = param_2;
  puVar1[0x16] = 0;
  puVar1[0x1a] = &DAT_0043c7e8;
  *puVar1 = 0;
  return param_1;
}
#undef DAT_0043c7e8

#define DAT_0043c7e8 (D_0043C7E8[0])
// MATCH func_00163E28
void FUN_00163e28(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(undefined **)(iVar1 + 0x68) = &DAT_0043c7e8;
  *(undefined4 *)(*(int *)(iVar1 + 0x60) + 0x5c) = *(undefined4 *)(iVar1 + 0x5c);
  *(undefined4 *)(*(int *)(iVar1 + 0x5c) + 0x60) = *(undefined4 *)(iVar1 + 0x60);
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}
#undef DAT_0043c7e8

// MATCH func_00163F50
undefined8 FUN_00163f50(int param_1)

{
  *(undefined4 *)(param_1 + 0x54) = 0;
  return 0;
}

// MATCH func_00163F60
undefined8 FUN_00163f60(int param_1)

{
  *(undefined4 *)(param_1 + 0x54) = 1;
  return 0;
}

// MATCH func_00163FA8
undefined4 FUN_00163fa8(int param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)*param_2;
  uVar2 = *puVar1;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *param_2 = (int)(puVar1 + 1);
  *(undefined4 *)(param_1 + 0x44) = uVar2;
  return 1;
}

// MATCH func_00164018
undefined8 FUN_00164018(int param_1,int *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_2;
  *(undefined4 *)(param_1 + 0x38) = *puVar1;
  *param_2 = (int)(puVar1 + 1);
  return 0;
}

// MATCH func_00164038
undefined8 FUN_00164038(int param_1,int *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_2;
  *(undefined4 *)(param_1 + 0x3c) = *puVar1;
  *param_2 = (int)(puVar1 + 1);
  return 0;
}

// MATCH func_001640D8
undefined8 FUN_001640d8(int param_1,int *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_2;
  *(undefined4 *)(param_1 + 0x40) = *puVar1;
  *param_2 = (int)(puVar1 + 1);
  return 0;
}

// MATCH func_001640F8
undefined8 FUN_001640f8(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)*param_2;
  return 0;
}

// MATCH func_00164110
undefined4 FUN_00164110(int param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)*param_2;
  uVar2 = *puVar1;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *param_2 = (int)(puVar1 + 1);
  *(undefined4 *)(param_1 + 0x58) = uVar2;
  return 1;
}

// MATCH func_00164130
undefined4 FUN_00164130(undefined8 param_1,int *param_2)

{
  *param_2 = *param_2 + -4;
  return 1;
}
