// compiler: 991111-01-as210
#include "../common.h"
int func_00165A40(char *, int); int func_001659A8(char *); int func_00167058(char *);
// MATCH func_00167550
int pachislot_00167550(char *o, int a, int b, int c) {
    int x, y, z, r, a1, b1, c1;
    x = func_00165A40(o + 44, a);
    y = func_00165A40(o + 124, b);
    z = func_00165A40(o + 204, c);
    if (func_001659A8(o + 44)) x = -1;
    if (func_001659A8(o + 124)) y = -1;
    if (func_001659A8(o + 204)) z = -1;
    a1 = (unsigned)(x - 1) < 3;
    b1 = (unsigned)(y - 1) < 3;
    c1 = (unsigned)(z - 1) < 3;
    r = func_00167058(o + 8);
    if ((a1 && b1) || (b1 && c1) || (a1 && c1)) {
if (r != -1) return 4;
    }
    return 0;
}
