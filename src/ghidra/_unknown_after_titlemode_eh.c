/* _unknown_after_titlemode_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern int D_00455A48[];
extern uint D_004A4AB8;
int FUN_0018b508(undefined1 *param_1, undefined8 param_2);
void FUN_0023cb70(undefined4 param_1);
int FileGetSize(char *path);
int titlemode_00214200(void);

// MATCH func_00215B28
undefined8 FUN_00215b28(int param_1)

{
  FUN_0023cb70(0xe);
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 3;
  return 0;
}

// MATCH func_00215B60
undefined8 FUN_00215b60(int param_1)

{
  FUN_0023cb70(0xe);
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 4;
  return 0;
}

// MATCH func_00215F88
bool FUN_00215f88(void)

{
  int lVar1;
  
  lVar1 = titlemode_00214200();
  D_004A4AB8 = (int)lVar1;
  return lVar1 != 0;
}

#define DAT_00455a48 (D_00455A48[0])
// MATCH func_00216850
int FUN_00216850(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)param_1;
  puVar3[1] = 0;
  puVar3[2] = 0;
  *puVar3 = 0;
  puVar3[3] = &DAT_00455a48;
  iVar1 = FileGetSize((char *)param_2);
  if (0 < iVar1) {
    uVar2 = FUN_0018b508(param_2,0);
    puVar3[1] = uVar2;
  }
  return param_1;
}
#undef DAT_00455a48
