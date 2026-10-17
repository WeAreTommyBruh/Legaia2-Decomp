/* pachislot_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern int D_0043D210[];
extern char D_004A2E48[];
int DbgPrintf(char *fmt);
undefined8 pachislot_00164890(void);
void pachislot_001649d8(void);
undefined4 pachislot_00166fd8(int param_1, int param_2);
int pachislot_00167940(undefined8 param_1, undefined8 param_2, undefined8 param_3, undefined8 param_4);
int pachislot_00167b88(undefined8 param_1, undefined8 param_2, undefined8 param_3, undefined8 param_4);
undefined4 pachislot_00167dd0(int param_1, undefined8 param_2);

#define DAT_0043d210 (D_0043D210[0])
// MATCH func_00164D78
int pachislot_00164d78(int param_1)

{
  pachislot_00164890();
  *(undefined **)((int)param_1 + 0x30) = &DAT_0043d210;
  return param_1;
}
#undef DAT_0043d210

// MATCH func_00165958
void pachislot_00165958(int param_1)

{
  pachislot_001649d8();
  *(undefined4 *)(param_1 + 0x40) = 1;
  return;
}

// MATCH func_00168178
void pachislot_00168178(undefined8 param_1,undefined8 param_2)

{
  pachislot_00167940(param_1,0,param_2,0);
  return;
}

// MATCH func_001681A0
void pachislot_001681a0(undefined8 param_1,undefined8 param_2)

{
  pachislot_00167b88(param_1,0,param_2,0);
  return;
}

// MATCH func_00168230
void pachislot_00168230(undefined8 param_1,undefined8 param_2)

{
  pachislot_00167940(param_1,0,0,param_2);
  return;
}

// MATCH func_00168258
void pachislot_00168258(undefined8 param_1,undefined8 param_2)

{
  pachislot_00167b88(param_1,0,0,param_2);
  return;
}

// MATCH func_001689A0
undefined4 pachislot_001689a0(int param_1)

{
  int lVar1;
  int *piVar2;
  undefined4 uVar3;
  
  lVar1 = pachislot_00167dd0(param_1,0);
  uVar3 = 0;
  if (lVar1 == 3) {
    piVar2 = (int *)param_1;
    lVar1 = pachislot_00166fd8(piVar2 + 2,6);
    uVar3 = 0;
    if (lVar1 == 2) {
      uVar3 = 1;
      DbgPrintf(D_004A2E48);
      piVar2[0x5c] = piVar2[0x5c] + *(int *)(*piVar2 + 0xcc);
    }
  }
  return uVar3;
}
