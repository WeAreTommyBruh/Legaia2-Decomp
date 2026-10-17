/* screfct_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern int D_0043E480[];
undefined8 FUN_00180b28(void);

#define DAT_0043e480 (D_0043E480[0])
// MATCH func_00183C18
int screfct_00183c18(int param_1)

{
  FUN_00180b28();
  *(undefined **)((int)param_1 + 0xc) = &DAT_0043e480;
  return param_1;
}
#undef DAT_0043e480
