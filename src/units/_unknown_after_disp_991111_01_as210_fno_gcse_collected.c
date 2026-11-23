/* Matched functions from this unit. */
// compiler: 991111-01-as210
// cflags: -fno-gcse
#include "../common.h"

extern int D_003D3F18[];
extern char D_003D1A98[], D_003D1360[], D_003D2A98[], D_005EEA00[];
void func_00232030();
// MATCH func_00234F58
void FUN_00234f58(void)
{
    char *p;
    unsigned i;
    D_003D3F18[1] = 0;
    D_003D3F18[2] = 0;
    { unsigned j = 0; char *q = D_003D1A98; D_003D3F18[0] = 0; do { j++; func_00232030(q); q += 128; } while (j < 32); }
    p = (char *)D_003D1360;
    i = 0;
    do { func_00232030(p); i++; p += 128; } while (i < 1);
    i = 0;
    p = (char *)D_003D2A98;
    do { func_00232030(p); i++; p += 128; } while (i < 33);
    p = (char *)D_005EEA00;
    i = 0;
    do { func_00232030(p); p += 128; i++; } while (i < 32);
}
