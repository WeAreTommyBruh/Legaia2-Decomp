/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern char D_0043C7D8_001644A0[] __asm__("D_0043C7D8"), D_0043C7C8[]; void *func_00162130_001644A0(int, char *, int) __asm__("func_00162130"); void *func_00163D48(void *);
// MATCH func_001644A0
int *minigame_001644a0(int *o) { o[1] = (int)D_0043C7D8_001644A0; o[0] = (int)func_00163D48(func_00162130_001644A0(108, D_0043C7C8, 346)); ((int *)o[0])[23] = o[0]; ((int *)o[0])[24] = o[0]; return o; }
