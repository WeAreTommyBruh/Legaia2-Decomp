#include "../common.h"
extern int D_004A6F10;
extern int D_004A6F14;
extern int D_00583CC0[];
extern void *D_00583E00[];
extern char *D_00583EA0[];
extern char D_004A26E0[];
void func_00152A90(char *, int, int, int, int, float, float);
// MATCH func_001529F8
void FUN_001529f8(int param_1)
{
    if (D_004A6F10 != 1 || param_1 == 0) {
        int i = D_004A6F14;
        D_00583E00[i] = 0;
        D_00583EA0[i] = 0;
        D_00583CC0[i] = 0;
        func_00152A90(D_004A26E0, 0, 0, 0, 0, 0.0f, 0.0f);
        D_004A6F10 = param_1;
    }
}
