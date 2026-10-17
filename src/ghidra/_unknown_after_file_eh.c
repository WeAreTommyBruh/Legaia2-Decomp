/* _unknown_after_file_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern int D_004A3850;
uint FUN_0018b180(void);
int FUN_0018b1f8(int param_1);
undefined8 file_0018a798(void);

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
// MATCH func_0018B2A8
int FileGetSize(char *path)

{
  int iVar1;
  
  iVar1 = -1;
  if (D_004A3850 == 0) {
    iVar1 = FUN_0018b180();
  }
  else if ((-1 < D_004A3850) && (iVar1 = -1, D_004A3850 < 4)) {
    iVar1 = FUN_0018b1f8(path);
  }
  return iVar1;
}

// MATCH func_0018B978
void FUN_0018b978(void)

{
  file_0018a798();
  return;
}
