#include "../common.h"
int func_0025A3B0(int); int *func_0025A3F0(int); int func_0025A470(int); int func_00250B68(int);
// MATCH func_001CCB80
int FUN_001ccb80(int a)
{
    int n, i, k, c, v;
    int *ids, *p;
    n = func_0025A3B0(a);
    if (n <= 0) return 0;
    i = 0;
    ids = func_0025A3F0(a);
    for (; i < n; i++, ids++) {
        c = 0;
        p = (int *)(func_0025A470(*ids) + 0x10);
        for (k = 7; k >= 0; k--) {
            v = *p;
            if (v > 0) c = (unsigned)(func_00250B68(v) > 0) + c;
            else c++;
            p++;
        }
        if (c == 8) return 1;
    }
    return 0;
}
