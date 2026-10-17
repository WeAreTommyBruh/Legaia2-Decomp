/* th_tex: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern char D_00342CD0[];
extern char D_0045BFC0[];
void init_0024bd50(int, int, int, int, int, int, int);

// MATCH func_0022C0B8
void th_tex_0022c0b8(int param_1)

{
  init_0024bd50(*(undefined4 *)(param_1 + 0x282c),0x3140,0x3c00,0,((int)D_00342CD0),((int)D_0045BFC0),0x2e);
  return;
}

// MATCH func_0022C138
void th_tex_0022c138(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 0x3030) * 0x50 + param_1 + 0x30) = 1;
  return;
}
