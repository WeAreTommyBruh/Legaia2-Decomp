/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_004A1A54; extern int *D_004A6FBC;
// MATCH func_0021DD18
int FUN_0021dd18(void) { int *p; if (D_004A1A54 != 0) return 0; p = D_004A6FBC; return (p[-4] & 0x10000000) > 0; }

extern int D_004A1A54_21E7C0 __asm__("D_004A1A54"), D_004A6FBC_21E7C0 __asm__("D_004A6FBC"); extern char D_003CA1C0_21E7C0[] __asm__("D_003CA1C0");
// MATCH func_0021E7C0
char *FUN_0021e7c0(void) { return D_003CA1C0_21E7C0 + *(int *)(D_004A1A54_21E7C0 * 60 + D_004A6FBC_21E7C0 - 56) * 32; }
