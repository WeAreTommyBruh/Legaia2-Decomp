/* _unknown_after_eftedit: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_001540c0(undefined4 param_1);
void FUN_00154118(undefined4 param_1);
void FUN_00154170(undefined4 param_1);
void FUN_00154388(undefined4 param_1);

// MATCH func_00200CA8
void FUN_00200ca8(undefined4 *param_1,uint param_2)

{
  if ((param_2 & param_1[0xb]) != 0) {
    FUN_00154388(*param_1);
    return;
  }
  return;
}

// MATCH func_00200D38
void FUN_00200d38(undefined4 *param_1,uint param_2)

{
  if ((param_2 & param_1[5]) != 0) {
    FUN_00154170(*param_1);
    return;
  }
  return;
}

// MATCH func_00200D80
void FUN_00200d80(undefined4 *param_1,uint param_2)

{
  if ((param_2 & param_1[3]) != 0) {
    FUN_00154118(*param_1);
    return;
  }
  return;
}

// MATCH func_00200DC8
void FUN_00200dc8(undefined4 *param_1,uint param_2)

{
  if ((param_2 & param_1[1]) != 0) {
    FUN_001540c0(*param_1);
    return;
  }
  return;
}
