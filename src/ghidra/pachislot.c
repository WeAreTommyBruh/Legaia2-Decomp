/* pachislot: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_0043D098[];
void FUN_00108b80(void);
void FUN_0018ea38(void);
void FUN_001976b8(void);
void func_0016BFD0(void);
void init_0024a510(void);
void init_0024ad58(undefined1 param_1, undefined1 param_2, undefined1 param_3, int param_4);
void pachislot_00164d20(void);
void yokota_0023efb8(void);

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

// MATCH func_00164CD8
char pachislot_00164cd8(int param_1)

{
  return *(char *)(*(int *)(param_1 + 4) + (int)*(short *)(param_1 + 10));
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

// MATCH func_0016C050
void pachislot_0016c050(void)

{
  init_0024a510();
  yokota_0023efb8();
  FUN_0018ea38();
  FUN_001976b8();
  init_0024ad58(0,0,0,0x80);
  func_0016BFD0();
  return;
}
