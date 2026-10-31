/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern char D_00425E22[]; extern char D_0049B968[];
int func_002DD36C(void *, void *);
// MATCH func_002AF418
char *FUN_002af418(void) { if (func_002DD36C(D_00425E22, D_0049B968) == 0) return D_00425E22 - 148; return D_00425E22; }

extern char D_0061F870_002AF9D0[] __asm__("D_0061F870"), D_00343028_002AF9D0[] __asm__("D_00343028"); extern int D_004A12A4_002AF9D0 __asm__("D_004A12A4"); extern int D_004A6B40; extern int D_004A69FC_002AF9D0 __asm__("D_004A69FC");
int func_00196FF8_002AF9D0(void) __asm__("func_00196FF8"); int func_002A1DF8(char *, int, int, int); void func_002A1988(void); void func_0010ED80_002AF9D0(char *) __asm__("func_0010ED80"); void func_0010E820_002AF9D0(char *, int) __asm__("func_0010E820"); void func_0010E368(char *);
// MATCH func_002AF9D0
void FUN_002af9d0(void) { if (func_00196FF8_002AF9D0() == 0) { if (func_002A1DF8(D_0061F870_002AF9D0, -1, 0, 0) != 0) { D_004A12A4_002AF9D0 = 18; func_002A1988(); func_0010ED80_002AF9D0(D_00343028_002AF9D0); func_0010E820_002AF9D0(D_00343028_002AF9D0, 102); D_004A6B40 |= 0x4000; func_0010E368(D_00343028_002AF9D0); D_004A69FC_002AF9D0 = 0; } } }
