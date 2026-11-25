#include "../common.h"
extern int D_004A5128, D_004A70FC; extern float D_004A70A0, D_004A70A4;
void func_002313A8(int, int, int, int, int, int);
// MATCH func_00231580
int FUN_00231580(float u, float v, int o, int *h, int mode)
{
    int c, r;
    if (h == 0) return -1;
    c = 0;
    switch (mode) {
    case 2: c = 0; break;
    case 3: c = 1; break;
    case 0: c = 2; break;
    case 1: c = 3; break;
    }
    if (D_004A5128 == 1)
        func_002313A8(c, c, h[0], h[1], h[2], h[3]);
    else
        func_002313A8(c, c, h[0] >> 1, h[1] >> 1, h[2] >> 1, h[3] >> 1);
    r = D_004A70FC;
    if (r == 0) {
        D_004A70A0 = u;
        D_004A70A4 = v;
    } else {
        D_004A70A0 = 1.0f - u;
        D_004A70A4 = 1.0f - v;
    }
    return r;
}
