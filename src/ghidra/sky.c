/* sky: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern char D_004A2A80[];
void FUN_00108b80(int param_1);
void MemFreeDbg(void *ptr, char *file, int line);

// MATCH func_00155A08
void sky_00155a08(int param_1,int param_2)

{
  MemFreeDbg(*(void **)((int)param_1 + 0x90),D_004A2A80,0x20);
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}
