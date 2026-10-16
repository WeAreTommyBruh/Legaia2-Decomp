/* shikimi: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern char D_00421260[];
extern uint D_004A67B4;
extern uint D_004A7358;
extern uint D_004A735C;
extern int D_00620920[];

// MATCH func_002B0DC8
void shikimi_002b0dc8(void)

{
  D_004A735C = 0;
  D_004A7358 = 3;
  return;
}

#define DAT_00620920 (D_00620920[0])
// MATCH func_002B1C18
void shikimi_002b1c18(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0x1f;
  puVar1 = &DAT_00620920;
  do {
    *puVar1 = 0;
    iVar2 = iVar2 + -1;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0;
    puVar1[0xb] = 0;
    puVar1[0xc] = 0;
    puVar1[0xd] = 0;
    puVar1[0xe] = 0;
    puVar1[0xf] = 0;
    puVar1 = puVar1 + 0x10;
  } while (-1 < iVar2);
  return;
}
#undef DAT_00620920

// MATCH func_002B8DC0
int shikimi_002b8dc0(int param_1,int param_2,int param_3)

{
  if (param_3 != 0) {
    return param_2 + *(int *)(param_1 + 0x10);
  }
  return param_1 + 0x14;
}

#define s_NOT_FILE_00421260 D_00421260
// MATCH func_002B8E58
void shikimi_002b8e58(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = D_004A67B4;
  *param_2 = s_NOT_FILE_00421260;
  return;
}
#undef s_NOT_FILE_00421260
