// cflags: -fno-schedule-insns2
#include "../src/common.h"
typedef struct { char p[76]; int w76; char p2[56]; int w136; } O; extern float D_004A0D88; int func_0029F948(O *); int func_0029F9B8(O *, float);
// 6 words differ
// WIP func_0029FCC0
void clas_min_0029fcc0(O *o) { func_0029F948(o); o->w136 = 12000; func_0029F9B8(o, D_004A0D88); o->w76 = (o->w76 & ~4) | 0x800; }
