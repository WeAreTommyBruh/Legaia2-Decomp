/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
#include "../common.h"

extern int D_004A140C_116D80 __asm__("D_004A140C"), D_004A6CC0_116D80 __asm__("D_004A6CC0"); extern char D_00324630_116D80[] __asm__("D_00324630"), D_003246D0_116D80[] __asm__("D_003246D0"); void *memcpy(void *, const void *, unsigned);
// MATCH func_00116D80
int FUN_00116d80(int a) { if (a == 0) return 0; if ((D_004A140C_116D80 & 8) != 0) memcpy(D_00324630_116D80, D_003246D0_116D80 + D_004A6CC0_116D80 * 160, 160); return 0; }

