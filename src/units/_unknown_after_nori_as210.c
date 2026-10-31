/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
#include "../common.h"

typedef struct { char p[32]; unsigned short a, b; char q[36]; } E13_00294290;
extern E13_00294290 D_003FDFA0[];
// MATCH func_00294290
int FUN_00294290(int idx) { E13_00294290 *e = &D_003FDFA0[idx]; return e->b * 100 / e->a; }
