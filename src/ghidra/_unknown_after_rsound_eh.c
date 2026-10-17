/* _unknown_after_rsound_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern uint D_004A6B9C;
extern uint D_004A6BA0;
extern uint D_004A6BB0;
extern uint D_004A6BB4;
extern int D_004DDE00[];
undefined4 FUN_0010fdd8(void);
char * func_002DD4CC(char *dst, char *src);

#define DAT_004dde00 (D_004DDE00[0])
// MATCH func_0010FEB0
undefined4 FUN_0010feb0(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int lVar1;
  
  do {
    lVar1 = FUN_0010fdd8();
  } while (lVar1 != 0);
  func_002DD4CC(&DAT_004dde00,param_1);
  D_004A6BA0 = param_3;
  D_004A6BB4 = param_4;
  D_004A6BB0 = param_2;
  D_004A6B9C = 1;
  return 1;
}
#undef DAT_004dde00
