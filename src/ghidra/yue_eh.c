/* yue_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern int D_0044CAE8[];
undefined8 akari_001e23b8(void);

#define DAT_0044cae8 (D_0044CAE8[0])
// MATCH func_001E7EC8
int yue_001e7ec8(int param_1)

{
  int iVar1;
  
  akari_001e23b8();
  iVar1 = (int)param_1;
  *(undefined **)(iVar1 + 100) = &DAT_0044cae8;
  *(undefined4 *)(iVar1 + 0x78) = 3;
  *(undefined4 *)(iVar1 + 0x7c) = 2;
  *(undefined4 *)(iVar1 + 0x350) = 0;
  *(undefined4 *)(iVar1 + 0x354) = 0;
  *(undefined4 *)(iVar1 + 0x358) = 0;
  *(undefined4 *)(iVar1 + 0x35c) = 0;
  *(undefined4 *)(iVar1 + 0x360) = 0;
  *(undefined4 *)(iVar1 + 0x364) = 0;
  *(undefined4 *)(iVar1 + 0x368) = 0;
  return param_1;
}
#undef DAT_0044cae8
