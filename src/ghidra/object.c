/* object: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_00318C20[];

#define DAT_00318c20 (D_00318C20[0])
// MATCH func_00244478
void object_00244478(int param_1)

{
  uint uVar1;
  
  for (uVar1 = (uint)*(byte *)((&DAT_00318c20)[param_1] + 3); uVar1 != 0; uVar1 = uVar1 - 1) {
  }
  return;
}
#undef DAT_00318c20
