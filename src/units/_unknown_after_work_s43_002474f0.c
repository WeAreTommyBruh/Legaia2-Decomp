// cflags: -fexceptions
#include "../common.h"
typedef struct { short n; short pad; unsigned f; char q[8]; int a[4]; int b[4]; } O_2474F0;
extern int D_00343668[];
int func_002350E8(void); int battle_00127080(float, int, int, int, int, int);
// MATCH func_002474F0
void FUN_002474f0(O_2474F0 *o) { if (((o->f ^ 1) & 1) == 0) { int b, a; a = o->a[o->n]; b = o->b[o->n]; if (D_00343668[1] != 0) { if (func_002350E8() != 0) battle_00127080(1.0f, 0, 146, a - 36, b, 128); } } }
