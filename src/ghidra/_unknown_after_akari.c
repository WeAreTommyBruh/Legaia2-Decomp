/* _unknown_after_akari: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void MemFree(void *ptr);
undefined1 akari_001e24d0(int param_1);
undefined1 akari_001e24e0(void);
bool akari_001e2588(int param_1);
void yue_001ec860(undefined8 param_1);

// MATCH func_001E5248
void FUN_001e5248(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_001E7DD8
void FUN_001e7dd8(int param_1)

{
  int lVar1;
  
  lVar1 = akari_001e24e0();
  if (((lVar1 != 0) && (lVar1 = akari_001e24d0(param_1), lVar1 != 0)) &&
     (lVar1 = akari_001e2588(param_1), lVar1 == 1)) {
    yue_001ec860(param_1);
    return;
  }
  return;
}
