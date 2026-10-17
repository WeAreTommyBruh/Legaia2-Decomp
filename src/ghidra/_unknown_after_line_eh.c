/* _unknown_after_line_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern int D_0043FE40[];
undefined8 FUN_00186ec8(void);

#define DAT_0043fe40 (D_0043FE40[0])
// MATCH func_00187E90
int FUN_00187e90(int param_1)

{
  FUN_00186ec8();
  *(undefined **)((int)param_1 + 0x844) = &DAT_0043fe40;
  return param_1;
}
#undef DAT_0043fe40
