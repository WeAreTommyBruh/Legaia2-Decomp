/* _unknown_after_screfct: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern char D_00336B00[];
extern int D_0043E460[];
extern int D_0043E538[];
int DbgPrintf(char *fmt);
void FUN_00108b80(int param_1);
void FUN_001809b8(void);
void FUN_00184518(int *param_1);
int FUN_00184590(int param_1);
void FUN_00186ac0(void);
void MemFree(void *ptr);

#define DAT_0043e460 (D_0043E460[0])
// MATCH func_001843A0
void FUN_001843a0(int param_1,int param_2)

{
  if (*(int *)param_1 != 0) {
    DbgPrintf(&DAT_0043e460);
    FUN_00184518(param_1);
  }
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}
#undef DAT_0043e460

// MATCH func_00185068
void FUN_00185068(void)

{
  FUN_00184590(((int)D_00336B00));
  return;
}

#define DAT_0043e538 (D_0043E538[0])
// MATCH func_00185238
int FUN_00185238(int param_1)

{
  *(undefined **)((int)param_1 + 0xc) = &DAT_0043e538;
  FUN_001809b8();
  return param_1;
}
#undef DAT_0043e538

#define DAT_0043e538 (D_0043E538[0])
// MATCH func_00185270
int FUN_00185270(int param_1)

{
  *(undefined **)((int)param_1 + 0xc) = &DAT_0043e538;
  return param_1;
}
#undef DAT_0043e538

// MATCH func_001852D8
void FUN_001852d8(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_001852F0
void FUN_001852f0(int param_1)

{
  if (param_1 != 0) {
    MemFree((void *)param_1);
    return;
  }
  return;
}

// MATCH func_00186A68
undefined8 FUN_00186a68(undefined8 param_1)

{
  FUN_00186ac0();
  return param_1;
}
