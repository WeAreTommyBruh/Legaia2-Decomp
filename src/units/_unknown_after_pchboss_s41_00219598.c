#include "../common.h"
extern char D_00456990[];
extern int D_004A1504, D_004A1508;
void func_001118F8(char *, ...);
// MATCH func_00219598
void FUN_00219598(int *o, int a, int b0)
{
    register int b __asm__("$18") = b0;
    if (o[9] == 0) {
        func_001118F8(D_00456990);
        D_004A1504 = 0;
        o[9] = 1;
        o[8] = a;
        o[74] = b;
        D_004A1508 = 0;
    }
}
