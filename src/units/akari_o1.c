/* Functions of this report unit, matched by hand. */
// cflags: -O1
#include "../common.h"

extern int *D_004A3838;
// MATCH func_001E2678
int akari_001e2678(int a, int *b) {
    int *p;
    for (p = D_004A3838; p != 0; p = (int *)p[1]) if (p == b) return 1;
    return 0;
}
