/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns
#include "../common.h"

typedef struct { char p[32]; int a; char p2[76]; int b; } T_00222A80;
extern T_00222A80 D_00326F90;
// MATCH func_00222A80
int FUN_00222a80(void) { int a = D_00326F90.a; int b = D_00326F90.b; if (b - 1 == a) return 2; return b - 2 == a; }
