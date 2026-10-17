/* denlib: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_00440710[];
void FUN_00108b80(int param_1);
void denlib_0018c4c8(void);
void denlib_0018c640(undefined4 *param_1);
void denlib_0018c710(undefined4 *param_1, int param_2);
void denlib_0018c908(void);

#define DAT_00440710 (D_00440710[0])
// MATCH func_0018C450
int denlib_0018c450(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1;
  *puVar1 = 0;
  puVar1[0xe] = &DAT_00440710;
  puVar1[1] = 0;
  return param_1;
}
#undef DAT_00440710

#define DAT_00440710 (D_00440710[0])
// MATCH func_0018C470
void denlib_0018c470(int param_1,int param_2)

{
  *(undefined **)((int)param_1 + 0x38) = &DAT_00440710;
  denlib_0018c4c8();
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}
#undef DAT_00440710

// MATCH func_0018C5D0
void denlib_0018c5d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)((int)param_1 + 0x30) = param_2;
  *(undefined4 *)((int)param_1 + 0x34) = param_3;
  denlib_0018c908();
  denlib_0018c640(param_1);
  return;
}

// MATCH func_0018C600
void denlib_0018c600(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  *(undefined4 *)((int)param_1 + 0x30) = param_2;
  *(undefined4 *)((int)param_1 + 0x34) = param_3;
  denlib_0018c908();
  denlib_0018c710(param_1,param_4);
  return;
}

// MATCH func_0018C7E0
undefined8 denlib_0018c7e0(int param_1)

{
  return *(undefined8 *)(param_1 + 0x28);
}
