/* Functions of this report unit, matched by hand. */
// cflags: -fexceptions
#include "../common.h"

extern int D_004A1A20, D_004A6E24;
extern unsigned *D_003279A0[];
extern char D_00430D40[], D_00430D68[];
int func_0012A938(void);
int func_001118F8(char *, ...);
void func_00124020(int);

// MATCH func_001252A0
void battle_001252a0(int actor)
{
    unsigned *object;
    int entry, debug;

    if (func_0012A938() != 0)
        func_001118F8(D_00430D40);
    object = D_003279A0[actor];
    if (object != 0) {
        object[48] |= 0x24;
        entry = actor * 0x1560 + D_004A1A20;
        debug = D_004A6E24;
        *(unsigned *)(entry + 0x12d0) |= 0x40000;
        if (debug != 0) {
            func_001118F8(D_00430D68, actor, *(int *)(entry + 0x1378));
            func_00124020(actor);
        }
    }
}
