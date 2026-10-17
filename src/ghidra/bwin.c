/* bwin: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern char D_00314C20[];
extern int D_003D19F0[];
extern char D_0045C358[];
void init_0024bd50(int, int, int, int, int, int, int);

#define DAT_003d19f0 (D_003D19F0[0])
// MATCH func_00237AB0
void bwin_00237ab0(void)

{
  init_0024bd50(DAT_003d19f0,0x3140,0x3c00,0,((int)D_00314C20),((int)D_0045C358),0xa7a);
  return;
}
#undef DAT_003d19f0
