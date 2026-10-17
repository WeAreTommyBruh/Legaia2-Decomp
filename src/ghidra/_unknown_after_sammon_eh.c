/* _unknown_after_sammon_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

undefined8 th_tex_0022cff0(void);

// MATCH func_00229828
int FUN_00229828(int param_1)

{
  th_tex_0022cff0();
  *(undefined4 *)((int)param_1 + 0x3084) = 0;
  return param_1;
}
