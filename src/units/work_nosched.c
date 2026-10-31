/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns
#include "../common.h"

extern char D_0045D4F0[]; void func_002444C0(void); void func_001621F8(int, char *, int);
// MATCH func_00246368
void work_00246368(int *o) { if (o[36]) { func_002444C0(); func_001621F8(o[36], D_0045D4F0, 223); o[36] = 0; } if (o[85]) { func_001621F8(o[85], D_0045D4F0, 227); o[85] = 0; } if (o[96]) func_001621F8(o[96], D_0045D4F0, 232); if (o[97]) func_001621F8(o[97], D_0045D4F0, 235); o[97] = 0; o[96] = 0; }
