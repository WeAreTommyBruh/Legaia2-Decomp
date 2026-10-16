/* yue: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"


// MATCH func_001E7F98
void yue_001e7f98(int param_1,int param_2)

{
  if (-1 < param_2) {
    *(int *)(param_1 + 0x80) = (int)param_2;
  }
  return;
}

// MATCH func_001E7FA8
void yue_001e7fa8(int param_1,int param_2)

{
  if (-1 < param_2) {
    *(int *)(param_1 + 0x74) = (int)param_2;
  }
  return;
}

// MATCH func_001E7FB8
void yue_001e7fb8(int param_1,int param_2)

{
  if (-1 < param_2) {
    *(int *)(param_1 + 0x8c) = (int)param_2;
  }
  return;
}

// MATCH func_001E7FC8
void yue_001e7fc8(int param_1,int param_2)

{
  if (-1 < param_2) {
    *(int *)(param_1 + 0x70) = (int)param_2;
  }
  return;
}

// MATCH func_001E7FD8
void yue_001e7fd8(int param_1,int param_2)

{
  if (-1 < param_2) {
    *(int *)(param_1 + 0x94) = (int)param_2;
  }
  return;
}

// MATCH func_001EA270
int yue_001ea270(int param_1)

{
  return *(int *)(param_1 + 0x78) * *(int *)(param_1 + 0x7c);
}
