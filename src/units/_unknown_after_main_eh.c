/* Functions of this report unit, matched by hand. */
// cflags: -fexceptions
#include "../common.h"

extern char D_0042F098_00112A28[] __asm__("D_0042F098"), D_0042F0A8_00112A28[] __asm__("D_0042F0A8"); int func_001128E0_00112A28() __asm__("func_001128E0"); void func_001118F8_00112A28(char *, ...) __asm__("func_001118F8"); int func_00112878_00112A28(int, int) __asm__("func_00112878");
// MATCH func_00112A28
int FUN_00112a28(int a) { int r = func_001128E0_00112A28(a); if (r >= 0) { func_001118F8_00112A28(D_0042F098_00112A28, r); return func_00112878_00112A28(a, r); } else { func_001118F8_00112A28(D_0042F0A8_00112A28); return 0; } }
