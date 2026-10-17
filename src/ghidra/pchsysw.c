/* pchsysw: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_004322C8[];
extern int D_004322D8[];
void FUN_00108b80(int param_1);
void func_0012EDE8(void);
void pchsysw_0012d970(undefined4 *param_1);
void pchsysw_0012d980(void);

#define DAT_004322d8 (D_004322D8[0])
// MATCH func_0012D8D8
int pchsysw_0012d8d8(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1;
  *puVar1 = 0;
  puVar1[4] = &DAT_004322d8;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  return param_1;
}
#undef DAT_004322d8

#define DAT_004322d8 (D_004322D8[0])
// MATCH func_0012D900
void pchsysw_0012d900(int param_1,int param_2)

{
  *(undefined **)((int)param_1 + 0x10) = &DAT_004322d8;
  pchsysw_0012d980();
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}
#undef DAT_004322d8

#define DAT_004322c8 (D_004322C8[0])
// MATCH func_0012ECF0
void pchsysw_0012ecf0(int param_1,int param_2)

{
  *(undefined **)((int)param_1 + 0x10) = &DAT_004322c8;
  func_0012EDE8();
  if ((param_2 & 1) != 0) {
    FUN_00108b80(param_1);
    return;
  }
  return;
}
#undef DAT_004322c8

// MATCH func_0012EDE8
void pchsysw_0012ede8(undefined4 *param_1)

{
  pchsysw_0012d970(*param_1);
  pchsysw_0012d970(param_1[1]);
  pchsysw_0012d970(param_1[2]);
  pchsysw_0012d970(param_1[3]);
  return;
}
