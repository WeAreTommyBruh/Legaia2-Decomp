/* Functions of this report unit, matched by hand. */
// cflags: -fexceptions
#include "../common.h"

extern int D_004A1A20_0021A3E8 __asm__("D_004A1A20");
extern int D_00456B60_0021A3E8[] __asm__("D_00456B60");
int DbgPrintf(char *fmt, ...);
int FUN_0021a280(int param_1, int param_2, int param_3, int param_4);
void battle_001252a0(long param_1);
// MATCH func_0021A3E8
long FUN_0021a3e8(int param_1)

{
  short sVar1;
  int iVar2;

  sVar1 = *(short *)(param_1 + 0xae);
  FUN_0021a280(sVar1,1,0,0x40000000);
  FUN_0021a280(sVar1,2,0,0x40000001);
  iVar2 = D_004A1A20_0021A3E8;
  *(int *)(param_1 + 0xc0) = 0;
  *(int *)(sVar1 * 0x1560 + iVar2 + 0x1378) = 0;
  battle_001252a0(sVar1);
  DbgPrintf(&(D_00456B60_0021A3E8[0]),sVar1);
  return 0;
}
