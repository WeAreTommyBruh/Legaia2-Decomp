/* Functions of this report unit, matched by hand. */
// cflags: -fexceptions
#include "../common.h"

typedef struct { char p[8]; int fl; char p2[28]; float f40; int w44; } O_2AE048_002AE048;
extern volatile float D_004A0ECC_2AE048 __asm__("D_004A0ECC"), D_004A0ED0_2AE048 __asm__("D_004A0ED0");
void func_0029FE18_2AE048(int, int, float, float, float) __asm__("func_0029FE18");
// MATCH func_002AE048
void FUN_002ae048(O_2AE048_002AE048 *o, int b) { float v, m, g; if (o->fl & 8) return; if (o->fl & 4) return; if (o->w44 == 0) return; v = *(volatile float *)&o->f40; m = D_004A0ECC_2AE048; g = D_004A0ED0_2AE048; v = v - (float)(int)(v / m) * m; o->f40 = v; func_0029FE18_2AE048(b, o->w44, g, v, g); }
