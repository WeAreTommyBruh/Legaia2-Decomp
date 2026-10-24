/* n_memo2_fnoscheduleinsns_fexceptions: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fno-schedule-insns -fexceptions
#include "../ghidra.h"

void FUN_00108b20(void);
void memo2_00101148(void);

// MATCH func_00101190
undefined4 memo2_00101190(int param_1,int param_2,int param_3,int param_4)

{
  if (param_2 == 3) {
    memo2_00101148();
    FUN_00108b20();
  }
  if (param_2 == 4) {
    *(undefined4 *)(param_1 + 0x534) = 0;
    *(char *)(param_1 + 0x1195) = 0xff;
    *(char *)(param_1 + 0x1194) = 0xff;
  }
  if (-1 < param_2) {
    *(int *)(param_1 + 0x514) = (int)param_2;
  }
  if (-1 < param_3) {
    *(int *)(param_1 + 0x119c) = (int)param_3;
  }
  if (-1 < param_4) {
    *(int *)(param_1 + 0x11a0) = (int)param_4;
  }
  *(undefined4 *)(param_1 + 0x50c) = 0;
  *(undefined4 *)(param_1 + 0x518) = 0;
  *(undefined4 *)(param_1 + 0x52c) = 0;
  return 1;
}
