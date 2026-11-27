#include "../common.h"
extern int D_04609030[], D_04601020[];
// MATCH func_00112010
void FUN_00112010(void) { int i; for (i = 0; i < 256; i++) D_04609030[0x1100 - i] = 0x1000; for (i = 0; i < 4096; i++) D_04601020[i] = 0x1000; }
