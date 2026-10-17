/* pchsysw_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

undefined4 pchsysw_0012e4f0(undefined4 *param_1);
undefined4 pchsysw_0012e4f8(int param_1);
undefined4 pchsysw_0012e608(int);
undefined4 pchsysw_0012e630(int);

// MATCH func_0012F180
void pchsysw_0012f180(undefined4 *param_1)

{
  pchsysw_0012e4f0(*param_1);
  return;
}

// MATCH func_0012F1A0
void pchsysw_0012f1a0(undefined4 *param_1)

{
  pchsysw_0012e4f8(*param_1);
  return;
}

// MATCH func_0012F230
void pchsysw_0012f230(undefined4 *param_1)

{
  pchsysw_0012e608(*param_1);
  return;
}

// MATCH func_0012F250
void pchsysw_0012f250(undefined4 *param_1)

{
  pchsysw_0012e630(*param_1);
  return;
}
