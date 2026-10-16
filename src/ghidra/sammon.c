/* sammon: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_0045AE68[];
int DbgPrintf(char *fmt,...);
int FUN_00237ca0(int param_1,int param_2,undefined8 param_3);

#define DAT_0045ae68 (D_0045AE68[0])
// MATCH func_002293C8
void sammon_002293c8(int param_1)

{
  DbgPrintf(&DAT_0045ae68);
  FUN_00237ca0(0,*(undefined4 *)(param_1 + 0x140),0x3c);
  return;
}
#undef DAT_0045ae68
