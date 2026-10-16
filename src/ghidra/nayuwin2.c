/* nayuwin2: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"


// MATCH func_001AD868
void nayuwin2_001ad868(int param_1,int param_2)

{
  if (-1 < param_2) {
    *(int *)(param_1 + 0x60) = (int)param_2;
  }
  return;
}

// MATCH func_001AD878
void nayuwin2_001ad878(int param_1,int param_2)

{
  if (-1 < param_2) {
    *(int *)(param_1 + 0x5c) = (int)param_2;
  }
  return;
}

// MATCH func_001AD888
void nayuwin2_001ad888(int param_1,int param_2)

{
  if (-2 < param_2) {
    *(int *)(param_1 + 0x6c) = (int)param_2;
  }
  return;
}

// MATCH func_001AD8A0
void nayuwin2_001ad8a0(int param_1,int param_2)

{
  if (0 < param_2) {
    *(int *)(param_1 + 0x4c) = (int)param_2;
  }
  return;
}

// MATCH func_001AD8C0
void nayuwin2_001ad8c0(int param_1,int param_2)

{
  if (0 < param_2) {
    *(int *)(param_1 + 0x54) = (int)param_2;
  }
  return;
}

// MATCH func_001AD908
void nayuwin2_001ad908(int param_1,uint param_2)

{
  if (param_2 < 6) {
    *(int *)(param_1 + 0x38) = (int)param_2;
  }
  return;
}

// MATCH func_001AD920
void nayuwin2_001ad920(int param_1,int param_2)

{
  if (-1 < param_2) {
    *(int *)(param_1 + 0x44) = (int)param_2;
  }
  return;
}

// MATCH func_001AF0E0
void nayuwin2_001af0e0(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  *param_2 = *(undefined4 *)(param_1 + 0x5c);
  *param_3 = *(undefined4 *)(param_1 + 0x60);
  return;
}

// MATCH func_001AF908
void nayuwin2_001af908(int param_1,int param_2,undefined4 param_3)

{
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x4c))) {
    *(undefined4 *)(param_2 * 0x100 + *(int *)(param_1 + 0x168) + 0x1c) = param_3;
  }
  return;
}
