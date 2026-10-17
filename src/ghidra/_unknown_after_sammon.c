/* _unknown_after_sammon: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_00249108(void);
void FUN_002491d8(void);
void battle_00126830(undefined8 param_1, undefined8 param_2);
void sammon_002275b8(undefined8 param_1);
void th_tex_0022cf58(undefined8 param_1);
undefined8 th_tex_0022cff0(void);

// MATCH func_00229828
int FUN_00229828(int param_1)

{
  th_tex_0022cff0();
  *(undefined4 *)((int)param_1 + 0x3084) = 0;
  return param_1;
}

// MATCH func_0022AEA0
void FUN_0022aea0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0x2f;
  iVar1 = (int)param_1 + 0x880;
  FUN_00249108();
  sammon_002275b8(param_1);
  do {
    iVar2 = iVar2 + -1;
    th_tex_0022cf58(iVar1);
    iVar1 = iVar1 + 0x3090;
  } while (-1 < iVar2);
  FUN_002491d8();
  return;
}

// MATCH func_0022BDD0
void FUN_0022bdd0(void)

{
  battle_00126830(0,0);
  return;
}
