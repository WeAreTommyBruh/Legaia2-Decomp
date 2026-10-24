/* Small functions matched by hand. */
// cflags: -O1
#include "common.h"

extern volatile int D_004A1444, D_004A140C; extern int D_004A46AC; void func_00212D50(int);
// MATCH func_0020D368
void pchevent_0020d368(int on) { if (on && D_004A1444 == 0 && (D_004A140C & 8) && D_004A46AC != 0) func_00212D50(D_004A46AC); }
