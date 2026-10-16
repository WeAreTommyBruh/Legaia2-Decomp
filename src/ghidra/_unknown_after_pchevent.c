/* _unknown_after_pchevent: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

undefined4 FUN_00131230(void);
void MemFree(void *ptr);

// MATCH func_002119E0
void FUN_002119e0(int *param_1)

{
  int lVar1;
  
  if ((*param_1 == 0) && (lVar1 = FUN_00131230(), lVar1 == 0)) {
    *param_1 = 1;
  }
  return;
}

// MATCH func_00211B70
bool FUN_00211b70(char *param_1,char *param_2,char *param_3,char *param_4)

{
  char cVar1;
  
  if ((param_1 != param_2) && (param_3 != param_4)) {
    cVar1 = *param_1;
    while( true ) {
      if (cVar1 < *param_3) {
        return true;
      }
      param_1 = param_1 + 1;
      if (*param_3 < cVar1) {
        return false;
      }
      param_3 = param_3 + 1;
      if ((param_1 == param_2) || (param_3 == param_4)) break;
      cVar1 = *param_1;
    }
  }
  return param_1 == param_2 && param_3 != param_4;
}

// MATCH func_00211C50
void FUN_00211c50(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}
