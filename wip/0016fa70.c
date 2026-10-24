// cflags: -fno-schedule-insns
#include "../src/common.h"
typedef struct { char p[80]; int w80; char p2[4]; int w88; int w92; int w96; char p3[16]; int w116; } O;
void func_0016FAB0(void *);
// 2 words differ
// WIP func_0016FA70
void roulette_0016fa70(O *o) { func_0016FAB0(o); o->w116 = 1; o->w80 = 12; o->w96 = 0; o->w88 = 0; o->w92 = 0; }
