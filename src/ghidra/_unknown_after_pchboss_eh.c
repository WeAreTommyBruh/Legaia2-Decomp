/* _unknown_after_pchboss_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern int D_003279A0[];
float FUN_0022f3c8(float param_1, float param_2);

#define DAT_003279a0 (D_003279A0[0])
// MATCH func_00219F68
void FUN_00219f68(int param_1,int param_2)

{
  FUN_0022f3c8(*(float *)((&DAT_003279a0)[param_1] + 0x20) -
               *(float *)((&DAT_003279a0)[param_2] + 0x20),
               *(float *)((&DAT_003279a0)[param_1] + 0x28) -
               *(float *)((&DAT_003279a0)[param_2] + 0x28));
  return;
}
#undef DAT_003279a0

#define DAT_003279a0 (D_003279A0[0])
// MATCH func_00219FB8
void FUN_00219fb8(int param_1,int param_2)

{
  FUN_0022f3c8(*(float *)((&DAT_003279a0)[param_1] + 0x80) -
               *(float *)((&DAT_003279a0)[param_2] + 0x80),
               *(float *)((&DAT_003279a0)[param_1] + 0x88) -
               *(float *)((&DAT_003279a0)[param_2] + 0x88));
  return;
}
#undef DAT_003279a0
