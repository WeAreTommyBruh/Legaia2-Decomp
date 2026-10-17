/* _unknown_after_shikimi_1: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_00456F58[];
void FUN_00108b80(void);

// MATCH func_002BEDF8
void FUN_002bedf8(undefined8 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}

// MATCH func_002BEE18
void FUN_002bee18(undefined8 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}

// MATCH func_002BF110
void FUN_002bf110(undefined8 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}

// MATCH func_002BF1A0
void FUN_002bf1a0(undefined8 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}

// MATCH func_002BF1C0
void FUN_002bf1c0(undefined8 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}

// MATCH func_002BF1E0
void FUN_002bf1e0(undefined8 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}

// MATCH func_002BF250
void FUN_002bf250(undefined8 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}

// MATCH func_002BF2C0
void FUN_002bf2c0(undefined8 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}

// MATCH func_002BF330
void FUN_002bf330(undefined8 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}

#define DAT_00456f58 (D_00456F58[0])
// MATCH func_002BF380
void FUN_002bf380(undefined4 *param_1,uint param_2)

{
  *param_1 = 0;
  param_1[0xe] = &DAT_00456f58;
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}
#undef DAT_00456f58
