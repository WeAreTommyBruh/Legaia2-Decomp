/* _unknown_after_rsound: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern char D_00315D88[];
extern int D_00315D98[];
extern uint D_004A12A4;
extern uint D_004A6B9C;
extern uint D_004A6BA0;
extern uint D_004A6BB0;
extern uint D_004A6BB4;
extern int D_004A6BD0;
extern int D_004A6BD4;
extern int D_004DDE00[];
void FUN_0010f000(void);
undefined4 FUN_0010fdd8(void);
int FUN_00113038(int *param_1);
void MemFree(void *ptr);
char * func_002DD4CC(char *dst, char *src);

// MATCH func_0010E240
bool FUN_0010e240(int param_1)

{
  return *(int *)(param_1 + 0x530) != 0;
}

// MATCH func_0010F038
void FUN_0010f038(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

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

// MATCH func_001114E8
bool FUN_001114e8(void)

{
  return D_004A6BD0 == D_004A6BD4;
}

// MATCH func_00111500
void FUN_00111500(void)

{
  D_004A12A4 = 0x12;
  FUN_0010f000();
  return;
}

#define DAT_00315d98 (D_00315D98[0])
// MATCH func_001118D0
bool FUN_001118d0(void)

{
  return DAT_00315d98 == 7;
}
#undef DAT_00315d98

// MATCH func_00111958
void FUN_00111958(void)

{
  FUN_00113038(((int)D_00315D88));
  return;
}
