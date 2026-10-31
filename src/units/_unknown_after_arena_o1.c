/* Functions of this report unit, matched by hand. */
// cflags: -O1
#include "../common.h"

typedef struct { char c[33]; } S33__002224A8;
extern char D_00459CF0[]; extern char D_00321060[]; extern int D_00326F90[];
// MATCH func_002224A8
void FUN_002224a8(int a, int b, int c, int d)
{
    if (a != 0) {
        *(S33__002224A8 *)D_00321060 = *(S33__002224A8 *)D_00459CF0;
    }
    D_00326F90[0] = a;
    D_00326F90[3] = c;
    D_00326F90[8] = d;
    D_00326F90[13] = 0;
}
