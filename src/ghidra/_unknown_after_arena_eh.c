/* _unknown_after_arena_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern char D_004A4DF8[];
extern int D_004A7008;
int DbgPrintf(char *fmt, ...);
void denlib_0018c5d0(undefined8 param_1, undefined4 param_2, undefined4 param_3);
int rand(void);

// MATCH func_002215F8
void FUN_002215f8(int *param_1)

{
  if (*param_1 != 0) {
    denlib_0018c5d0(param_1[0x21],0x2a40,0x3e00);
    param_1[2] = 1;
  }
  return;
}

// MATCH func_00223440
int FUN_00223440(int param_1)

{
  int iVar1;
  
  iVar1 = rand();
  iVar1 = ((iVar1 >> 8) + D_004A7008) % (int)param_1;
  D_004A7008 = (D_004A7008 + 1) % 100;
  DbgPrintf(D_004A4DF8,iVar1);
  return iVar1;
}
