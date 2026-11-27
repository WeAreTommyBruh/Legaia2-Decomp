// compiler: 991111-01-as210
#include "../common.h"
typedef struct { char c[8]; } V8_1747F8;
extern V8_1747F8 D_004A31D0[];
void func_00172CB0(char *); void func_00172CF8(char *); int repetition_00175ed8();
// MATCH func_001747F8
int repetition_001747f8(char *o) { int idx = *(short *)(o + 890); int (*fn)(void *); int d; int dl; long e; if (idx > 0) { long *vt = *(long **)(o + *(short *)(o + 892)); e = vt[idx - 1]; fn = (int (*)(void *))(e >> 32); } else fn = *(int (**)(void *))(o + 892); dl = *(short *)(o + 888); d = idx > 0 ? (short)e + dl : dl; if (fn(o + d) != 0) { func_00172CB0(o); *(V8_1747F8 *)(o + 408) = D_004A31D0[0]; if (*(short *)(o + 890) == -1 && *(void **)(o + 892) == (void *)repetition_00175ed8) func_00172CF8(o); } return 0; }
