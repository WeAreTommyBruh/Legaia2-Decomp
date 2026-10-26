/* Ghidra's decompilation, statement order searched by build/work/ghill.py. */
// cflags: -fexceptions
#include "../ghidra.h"
int func_002E5580(int, int, int);
undefined * FUN_002bf838(void);
undefined8 FUN_002e6380(undefined8 param_1);
undefined8 FUN_002e63e8(undefined8 param_1);
void RemoveIntcHandler(int, int);
// MATCH func_002C1188
int FUN_002c1188(int param_1)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  iVar2 = FUN_002bf838();
  iVar1 = *((int *) (iVar2 + 8));
  if (param_1 == 0)
  {
    FUN_002e6380(2);
    RemoveIntcHandler(2, *((undefined4 *) (iVar2 + 0xc)));
    *((undefined4 *) (iVar2 + 8)) = (*((undefined4 *) (iVar2 + 0xc)) = 0);
  }
  else
  {
    if (iVar1 == 0)
    {
      *((int *) (iVar2 + 8)) = (int) param_1;
    }
    else
    {
      FUN_002e6380(2);
      RemoveIntcHandler(2, *((undefined4 *) (iVar2 + 0xc)));
      *((int *) (iVar2 + 8)) = (int) param_1;
    }
    uVar3 = func_002E5580(2, param_1, 0xffffffffffffffff);
    *((undefined4 *) (iVar2 + 0xc)) = uVar3;
    FUN_002e63e8(2);
  }
  return iVar1;
}
