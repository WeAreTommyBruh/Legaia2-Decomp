/* init: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"


// MATCH func_0024B260
char init_0024b260(int param_1,int param_2)

{
  return *(char *)(param_2 * 0x10 + param_1 + 0xc);
}

// MATCH func_0024B270
void init_0024b270(char *param_1)

{
  int lVar1;
  
  lVar1 = (int)*param_1;
  if (0 < lVar1) {
    do {
      lVar1 = (int)((int)lVar1 + -1);
    } while (lVar1 != 0);
  }
  return;
}
