/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_004A3864_1335E8 __asm__("D_004A3864");
extern char D_00432AD8_1335E8[] __asm__("D_00432AD8"), D_00432AC0_1335E8[] __asm__("D_00432AC0");
void func_001118F8_001335E8(void *, ...) __asm__("func_001118F8");
// MATCH func_001335E8
void FUN_001335e8(int a, int b, int c) { if ((D_004A3864_1335E8 & 0x800) == 0) return; switch (c) { case 1: func_001118F8_001335E8(D_00432AD8_1335E8, a); break; case 0: case 2: func_001118F8_001335E8(D_00432AC0_1335E8, a); break; case 3: func_001118F8_001335E8(D_00432AD8_1335E8, a); break; } }
