/* _unknown_after_crvmove_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

undefined4 FUN_00163068(int param_1);
int FUN_001630b8(int, int);
int strcmp(char *a, char *b);

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
