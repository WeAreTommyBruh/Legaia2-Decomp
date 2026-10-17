/* modelpkt_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

int modelpkt_0017ffd0(undefined4 param_1, int, int, int);
void modelpkt_001804f0(int *param_1, int param_2, int param_3);

// MATCH func_00180018
void modelpkt_00180018(int param_1,int param_2,int param_3,int param_4,
                      int param_5)

{
  modelpkt_0017ffd0(param_1,param_3,param_4,param_5);
  return;
}

// MATCH func_00180040
void modelpkt_00180040(int param_1,int param_2,int param_3,int param_4)

{
  modelpkt_0017ffd0(param_1,param_3,param_4,1);
  return;
}

// MATCH func_001801D0
int modelpkt_001801d0(int param_1,int param_2)

{
  modelpkt_001804f0(param_1,param_2,1);
  return param_1;
}
