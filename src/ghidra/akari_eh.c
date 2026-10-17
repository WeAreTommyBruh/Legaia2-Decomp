/* akari_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern char D_0044B740[];
extern char D_004A380A;
void FUN_00131f68(int param_1);
undefined4 akari_001e2678(void);
void rouge_00133528(void *param_1, int, int);

// MATCH func_001E2548
void akari_001e2548(int param_1)

{
  if (*(int *)(param_1 + 0x58) != 0) {
    rouge_00133528(*(int *)(param_1 + 0x58),((int)D_0044B740),0x10d);
  }
  *(undefined4 *)(param_1 + 0x58) = 0;
  return;
}

// MATCH func_001E3210
void akari_001e3210(undefined8 param_1,int param_2,int param_3)

{
  int lVar1;
  int iVar2;
  
  if (((D_004A380A != '\0') && (param_2 != 0)) && (lVar1 = akari_001e2678(), lVar1 != 0)) {
    if (param_3 == 0) {
      FUN_00131f68(param_2);
    }
    else {
      iVar2 = *(int *)((int)param_2 + 300);
      if (0 < iVar2) {
        do {
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
    }
  }
  return;
}
