/* modelpkt: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

void FUN_00108b80(void);
void modelpkt_001804f0(void);

// MATCH func_00180200
undefined8 modelpkt_00180200(undefined8 param_1)

{
  modelpkt_001804f0();
  return param_1;
}

// MATCH func_00180228
void modelpkt_00180228(undefined8 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    FUN_00108b80();
    return;
  }
  return;
}
