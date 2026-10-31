/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"

extern char D_0044B678[], D_0044B4A0[]; void func_00133528(int, char *, int); void func_001E2400(void *, int);
// MATCH func_001DFC78
void mizuki_001dfc78(int *o, int a) { o[25] = (int)D_0044B678; if (o[36] != 0) func_00133528(o[36], D_0044B4A0, 154); if (o[22] != 0) func_00133528(o[22], D_0044B4A0, 155); if (o[21] != 0) { if (o[57] != 0) func_00133528(o[21], D_0044B4A0, 156); } o[22] = 0; o[36] = 0; o[21] = 0; func_001E2400(o, a); }
