/* main: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern char D_00314C20[];
extern char D_0042EE38[];
extern uint D_004A13A4;
void init_0024bd50(int, int, int, int, int, int, int);

// MATCH func_00111BD8
void main_00111bd8(void)

{
  init_0024bd50(D_004A13A4,0x3140,0x3c00,0,((int)D_00314C20),((int)D_0042EE38),0x644);
  return;
}
