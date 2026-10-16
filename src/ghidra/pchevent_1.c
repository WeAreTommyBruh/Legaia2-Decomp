/* pchevent_1: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_004A45E4;
extern int D_004A4960;
void pchevent_0020b910(int param_1,int param_2,int param_3);

// MATCH func_0020F090
undefined8 pchevent_0020f090(uint param_1)

{
  if (((param_1 & 8) != 0) && (D_004A4960 < *(int *)(D_004A45E4 + 8) + -1)) {
    pchevent_0020b910(D_004A45E4,D_004A4960,D_004A4960 + 1);
    D_004A4960 = D_004A4960 + 1;
  }
  return 0;
}
