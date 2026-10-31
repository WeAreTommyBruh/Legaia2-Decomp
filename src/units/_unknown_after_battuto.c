/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_004A1A54; extern int *D_004A6FBC;
// MATCH func_0021DD18
int FUN_0021dd18(void) { int *p; if (D_004A1A54 != 0) return 0; p = D_004A6FBC; return (p[-4] & 0x10000000) > 0; }
