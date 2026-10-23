/* n__unknown_after_shikimi_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

int FUN_002ee790(void);
int GetMemorySize(void);
void _InitTLB(void);

// MATCH func_002EE750
void FUN_002ee750(void)

{
  int lVar1;
  
  lVar1 = GetMemorySize();
  if (lVar1 == 0x2000000) {
    FUN_002ee790();
  }
  else {
    _InitTLB();
  }
  return;
}
