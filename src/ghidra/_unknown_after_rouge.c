/* _unknown_after_rouge: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_003FEBA8[];

#define DAT_003feba8 (D_003FEBA8[0])
// MATCH func_00133680
void FUN_00133680(void)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  puVar1 = &DAT_003feba8;
  do {
    *puVar1 = 0;
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (uVar2 < 0x900);
  return;
}
#undef DAT_003feba8
