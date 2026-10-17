/* _unknown_after_object_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

int FUN_002451d8(undefined8 param_1, undefined8 param_2, int param_3);
char * func_002DD4CC(char *dst, char *src);

// MATCH func_002454A8
void FUN_002454a8(int param_1,char *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  func_002DD4CC((char *)(iVar2 + 0x3100),(char *)param_3);
  func_002DD4CC((char *)(iVar2 + 0x3000),param_2);
  uVar1 = FUN_002451d8((char *)(iVar2 + 0x3000),param_3,param_1);
  *(undefined4 *)(iVar2 + 0x3110) = uVar1;
  return;
}
