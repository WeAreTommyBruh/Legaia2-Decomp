/* pchjob0_990721: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// compiler: 990721
#include "../ghidra.h"

void FUN_00108b80(int param_1);
void pchjob0_00204f60(int *param_1);

// MATCH func_00204A10
void pchjob0_00204a10(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)param_1;
  while (0 < iVar1) {
    pchjob0_00204f60(param_1);
    iVar1 = *(int *)param_1;
  }
  if ((param_2 & 1) == 0) {
    return;
  }
  FUN_00108b80(param_1);
  return;
}
