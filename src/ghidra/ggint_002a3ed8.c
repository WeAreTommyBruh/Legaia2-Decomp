/* ggint: Ghidra output with 64-bit parameter types narrowed to int; compiles to the original bytes. */
#include "../ghidra.h"

extern int D_005F9640[];
extern char D_0041EF40[];
extern char D_004A6A28[];
int FUN_00160778(int param_1, char *param_2);
int FUN_00160c70(int param_1, char *param_2, int param_3);
undefined4 shikimi_002b3f10(int param_1, int *param_2, int *param_3);
#define DAT_005f9640 (D_005F9640[0])
// MATCH func_002A3ED8
void clas_min_002a3ed8(int *param_1,int param_2)

{
  int lVar1;
  int uVar2;
  undefined4 auStack_60 [4];
  
  if ((param_1[6] != 0) && (lVar1 = FUN_00160778(((int)D_0041EF40),((int)D_004A6A28)), param_2 < lVar1)) {
    auStack_60[0] = 0;
    uVar2 = FUN_00160c70(((int)D_0041EF40),((int)D_004A6A28),param_2);
    shikimi_002b3f10(uVar2,&DAT_005f9640 + *param_1 * 0x98,auStack_60);
  }
  return;
}
#undef DAT_005f9640
