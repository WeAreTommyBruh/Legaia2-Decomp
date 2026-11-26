#include "../common.h"
typedef struct { char p[248]; short a[11]; short b[11]; char q[180]; } E472; extern E472 D_00400498[];
// MATCH func_0025ADB8
void FUN_0025adb8(void) { E472 *e = D_00400498; E472 *end = e + 5; do { if (e->b[0] <= 0) e->a[0] = 0; if (e->b[1] <= 0) e->a[1] = 0; if (e->b[2] <= 0) e->a[2] = 0; if (e->b[3] <= 0) e->a[3] = 0; if (e->b[4] <= 0) e->a[4] = 0; if (e->b[5] <= 0) e->a[5] = 0; if (e->b[6] <= 0) e->a[6] = 0; if (e->b[7] <= 0) e->a[7] = 0; if (e->b[8] <= 0) e->a[8] = 0; if (e->b[9] <= 0) e->a[9] = 0; if (e->b[10] <= 0) e->a[10] = 0; e++; } while ((int)e < (int)end); }
