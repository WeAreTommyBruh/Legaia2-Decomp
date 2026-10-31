/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

extern volatile int D_004A1444, D_004A140C; extern char D_00455020[], D_00455030[]; int func_00211A20(void); int func_00211A58(int); int func_001118F8(char *, ...);
// MATCH func_0020C920
void pchevent_0020c920(int on) { int i, n; if (on) { if (D_004A1444 == 0 && (D_004A140C & 8)) { if (func_00211A20() < 10) n = func_00211A20(); else n = 10; i = 0; func_001118F8(D_00455020, func_00211A20()); for (i = 0; i < n; i++) func_001118F8(D_00455030, i, func_00211A58(i)); } } }

typedef struct { char p[208]; float f208; } S_0020C430;
extern S_0020C430 D_0041EFB0; extern float D_004A6F74;
// MATCH func_0020C430
int pchevent_0020c430(void) { float d = (D_004A6F74 - D_0041EFB0.f208) * 0.5f; float q = d * d; if (d < 0) q = -q; D_004A6F74 = D_0041EFB0.f208 + q; if (D_004A6F74 < 0) D_004A6F74 = 0; D_0041EFB0.f208 = D_004A6F74; return 0; }
