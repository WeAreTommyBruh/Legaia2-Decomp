/* pchjob0_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

int pchjob0_002056a8(void);

// MATCH func_00205718
int pchjob0_00205718(void)

{
  int lVar1;
  int uVar2;
  
  lVar1 = pchjob0_002056a8();
  uVar2 = 0xffffffff;
  if (lVar1 != 0) {
    uVar2 = *(int *)lVar1;
  }
  return uVar2;
}

// MATCH func_00205748
int pchjob0_00205748(void)

{
  int lVar1;
  int uVar2;
  
  lVar1 = pchjob0_002056a8();
  uVar2 = 0xffffffff;
  if (lVar1 != 0) {
    uVar2 = *(int *)((int)lVar1 + 4);
  }
  return uVar2;
}
