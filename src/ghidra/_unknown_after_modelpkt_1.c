/* _unknown_after_modelpkt_1: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_00314C20[];
extern char D_00342CD0[];

#define DAT_00342cd0 (D_00342CD0[0])
#define DAT_00314c20 (D_00314C20[0])
// MATCH func_00180BD0
void FUN_00180bd0(int param_1,int param_2)

{
  *(int *)(param_1 + 0x10) = (int)param_2;
  if (param_2 == ((int)D_00342CD0)) {
    *(undefined8 **)(param_1 + 0x8c) = &DAT_00342cd0;
    return;
  }
  *(undefined8 **)(param_1 + 0x8c) = &DAT_00314c20;
  return;
}
#undef DAT_00342cd0
#undef DAT_00314c20
