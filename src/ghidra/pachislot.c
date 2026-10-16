/* pachislot: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_0043D098[];
void FUN_00108b80(void);
void pachislot_001649d8(void);
void * pachislot_00164d08(int param_1, void *param_2, uint param_3);
void pachislot_00164d20(void);

// MATCH func_001649C8
void pachislot_001649c8(int *param_1)

{
  pachislot_00164d08(param_1,*(undefined4 *)(*param_1 + 0x18),*(undefined4 *)(*param_1 + 0x14));
  return;
}

// MATCH func_00164A00
bool pachislot_00164a00(int param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if (*(int *)(param_1 + 0x20) < 0) {
    bVar1 = *(int *)(param_1 + 0x18) == 0;
  }
  return bVar1;
}

// MATCH func_00164CF0
undefined4 pachislot_00164cf0(int *param_1)

{
  return *(undefined4 *)(*param_1 + 0x14);
}

// MATCH func_00165958
void pachislot_00165958(int param_1)

{
  pachislot_001649d8();
  *(undefined4 *)(param_1 + 0x40) = 1;
  return;
}

// MATCH func_00165CE8
void pachislot_00165ce8(int param_1)

{
  if (*(int *)(param_1 + 0x34) == 4) {
    *(undefined4 *)(param_1 + 0x3c) = 1;
  }
  return;
}

// MATCH func_001663C8
void pachislot_001663c8(int param_1)

{
  if (*(int *)(param_1 + 0x3c) == 0) {
    pachislot_00164d20();
    return;
  }
  return;
}

#define DAT_0043d098 (D_0043D098[0])
// MATCH func_00166768
void pachislot_00166768(int param_1,uint param_2)

{
  *(undefined **)(param_1 + 0x20) = &DAT_0043d098;
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}
#undef DAT_0043d098

// MATCH func_00167080
undefined4 pachislot_00167080(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(int *)(param_1 + 4) != -1) || (*(int *)(param_1 + 8) != -1)) {
    uVar1 = 1;
  }
  return uVar1;
}
