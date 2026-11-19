/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
#include "../common.h"

extern int D_004A1A50;
extern int D_00425510[];
extern char D_004308E8[], D_004A1980[], D_004A1988[];
int func_001118F8(char *, ...);
void func_0012AEA8(int);

// MATCH func_00123018
void SetBattleEnd(int result)
{
    func_001118F8(D_004308E8);
    if (result == -2) {
        func_001118F8(D_004A1980);
        D_004A1A50 |= 8;
        D_00425510[1] |= 0x12000;
    }
    if (result == -3) {
        func_001118F8(D_004A1988);
        if (D_00425510[1] & 0x8000)
            D_004A1A50 |= 0x400;
        D_00425510[1] = (D_00425510[1] | 0x10000u) & ~0x2000u;
    }
    func_0012AEA8(14);
}
