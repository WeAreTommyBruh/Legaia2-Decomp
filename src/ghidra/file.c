/* file: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

undefined4 FUN_0010fe28(undefined8 param_1, undefined4 param_2);
int FUN_0018bae8(char *param_1, char *param_2);

// MATCH func_0018AAB0
int file_0018aab0(int param_1,int param_2)

{
  undefined1 auStack_120 [256];
  
  FUN_0018bae8(auStack_120,param_1);
  FUN_0010fe28(auStack_120,param_2);
  return 0;
}
