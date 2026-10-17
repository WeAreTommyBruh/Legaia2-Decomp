/* pchevent: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern uint D_004A140C;
extern int D_004A1444;
extern int D_004A4678;
extern uint D_004A467C;
int FUN_001301e0(int *param_1, int param_2);
void FUN_00130260(int param_1, int param_2);
void pchsysw_0012f840(undefined8 param_1, int param_2);

// MATCH func_0020CF48
void pchevent_0020cf48(int param_1)

{
  int lVar1;
  
  if ((((param_1 != 0) && (D_004A1444 == 0)) && ((D_004A140C & 8) != 0)) &&
     ((D_004A4678 != 0 && (lVar1 = FUN_001301e0(D_004A4678,D_004A467C), lVar1 != 0)))) {
    FUN_00130260(D_004A4678,D_004A467C);
    return;
  }
  return;
}

// MATCH func_0020CFA8
void pchevent_0020cfa8(int param_1)

{
  int lVar1;
  
  if ((((param_1 != 0) && (D_004A1444 == 0)) && ((D_004A140C & 8) != 0)) &&
     ((D_004A4678 != 0 && (lVar1 = FUN_001301e0(D_004A4678,D_004A467C), lVar1 != 0)))) {
    pchsysw_0012f840(D_004A4678,D_004A467C);
    return;
  }
  return;
}
