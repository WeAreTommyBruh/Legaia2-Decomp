/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

extern int D_00320D20_00248170[] __asm__("D_00320D20"); extern float D_00319760_00248170[] __asm__("D_00319760"); extern int D_004A565C_00248170 __asm__("D_004A565C"), D_004A5658_00248170 __asm__("D_004A5658"); extern float D_004A0810_00248170 __asm__("D_004A0810");
float func_0015FB58_00248170(float, int) __asm__("func_0015FB58");
// MATCH func_00248170
void FUN_00248170(void) { int *p; float *q; int i,v;register int one; float f; p = D_00320D20_00248170; one=1;i = 15; D_004A565C_00248170 = 0; D_004A5658_00248170 = 0; for (; i >= 0; i--) { p[0] = 0; p[1] = 0; p[2] = 0; p[3]=one; p += 4; } q = D_00319760_00248170; f = (6.28000020980835f); for (i = 0; i < 0x1400; i++) { v = i & 0xfff; *q = func_0015FB58_00248170((float)v * f * 0.00024414062f, 0); q++; } }
