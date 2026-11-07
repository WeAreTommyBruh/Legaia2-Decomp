/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
#include "../common.h"

typedef struct { char p[32]; unsigned short a, b; char q[36]; } E13_00294290;
extern E13_00294290 D_003FDFA0[];
// MATCH func_00294290
int FUN_00294290(int idx) { E13_00294290 *e = &D_003FDFA0[idx]; return e->b * 100 / e->a; }

typedef struct { char p[36]; unsigned short a, b; char q[32]; } E13_002942c8_002942C8;
extern E13_002942c8_002942C8 D_003FDFA0_2942C8[] __asm__("D_003FDFA0");
// MATCH func_002942C8
int FUN_002942c8(int idx) { E13_002942c8_002942C8 *e = &D_003FDFA0_2942C8[idx]; return e->b * 100 / e->a; }

