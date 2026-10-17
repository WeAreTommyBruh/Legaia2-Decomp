/* _unknown_after_arena: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_004A1A20;
extern char D_004A4DF8[];
extern int D_004A4E0C;
extern int D_004A7008;
int DbgPrintf(char *fmt, ...);
void denlib_0018c5d0(undefined8 param_1, undefined4 param_2, undefined4 param_3);
int rand(void);
void shikimi_002b2690(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, undefined4 param_8);

// MATCH func_002215F8
void FUN_002215f8(int *param_1)

{
  if (*param_1 != 0) {
    denlib_0018c5d0(param_1[0x21],0x2a40,0x3e00);
    param_1[2] = 1;
  }
  return;
}

// MATCH func_00221638
int FUN_00221638(int *param_1)

{
  int iVar1;
  
  if (*param_1 == 0) {
    return 0;
  }
  iVar1 = D_004A4E0C;
  if (D_004A4E0C == 0) {
    iVar1 = param_1[0x222];
  }
  return iVar1;
}

// MATCH func_002216F8
bool FUN_002216f8(int param_1)

{
  return *(int *)(param_1 + 0x50) != 0;
}

// MATCH func_00222AB0
void FUN_00222ab0(int *param_1)

{
  int iVar1;
  
  if (*param_1 == 2) {
    iVar1 = *(int *)(D_004A1A20 + 0x1444);
    *(int *)(iVar1 + 4) = param_1[0x1e];
    *(int *)(iVar1 + 8) = param_1[0x1f];
  }
  return;
}

// MATCH func_00223440
int FUN_00223440(int param_1)

{
  int iVar1;
  
  iVar1 = rand();
  iVar1 = ((iVar1 >> 8) + D_004A7008) % (int)param_1;
  D_004A7008 = (D_004A7008 + 1) % 100;
  DbgPrintf(D_004A4DF8,iVar1);
  return iVar1;
}

// MATCH func_002234D8
void FUN_002234d8(void)

{
  shikimi_002b2690(0x78,0xd,2,0,1,0,0,100);
  return;
}
