/* clas_min_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern char D_00343028[];
extern int D_004A69B8;
undefined4 FUN_0010d660(int param_1, uint param_2);
void clas_min_002a1618(int param_1);
void clas_min_002a3a48(void);

// MATCH func_002A1918
void clas_min_002a1918(void)

{
  if (D_004A69B8 < 0) {
    clas_min_002a1618(0);
  }
  FUN_0010d660(((int)D_00343028),D_004A69B8);
  D_004A69B8 = 0xffffffff;
  return;
}

// MATCH func_002A39D0
undefined8 clas_min_002a39d0(undefined8 param_1)

{
  clas_min_002a3a48();
  return param_1;
}
