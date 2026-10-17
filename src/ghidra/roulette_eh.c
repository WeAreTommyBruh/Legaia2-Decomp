/* roulette_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern byte D_00335640[];
void roulette_00171980(int param_1, uint param_2);
int roulette_00171ad0(void);

#define DAT_00335640 (D_00335640[0])
// MATCH func_00171950
undefined4 roulette_00171950(void)

{
  int iVar1;
  
  iVar1 = roulette_00171ad0();
  return *(undefined4 *)(&DAT_00335640 + iVar1 * 4);
}
#undef DAT_00335640

// MATCH func_001723B8
void roulette_001723b8(int param_1)

{
  roulette_00171980(param_1,4);
  *(undefined4 *)((int)param_1 + 0x74) = 0;
  return;
}
