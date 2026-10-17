/* srivus: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern char D_0033ADD8[];
extern char D_0033E7D0[];
void FUN_00186f40(undefined8 param_1, int param_2, int param_3, int param_4);
void FUN_00187028(void);
void FUN_00231688(void);

// MATCH func_00187FD8
void srivus_00187fd8(undefined8 param_1)

{
  FUN_00187028();
  FUN_00186f40(param_1,((int)D_0033ADD8),0x14,0x16);
  return;
}

// MATCH func_00188EE8
void srivus_00188ee8(undefined8 param_1)

{
  FUN_00187028();
  FUN_00186f40(param_1,((int)D_0033E7D0),0x18,0x1a);
  return;
}

// MATCH func_00189078
void srivus_00189078(int param_1)

{
  if ((*(uint *)(param_1 + 0x18) & 0x4000000) != 0) {
    FUN_00231688();
    return;
  }
  return;
}
