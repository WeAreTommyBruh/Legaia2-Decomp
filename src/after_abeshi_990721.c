/* Functions of _unknown_after_abeshi built with the older ee-gcc
   2.9-ee-990721 (see tools/asm_build.py). Matched by hand. */
// compiler: 990721
#include "common.h"

typedef struct {
    char unk0[0xa2];
    u8 kind;
    char unka3[0xb0 - 0xa3];
} Member;

extern u32 D_004A5E50;   /* the current party member, 0-2 */
extern int D_00314D08[4]; /* the 3 members' states, then one more */
extern int D_004A5E38;
extern int D_003FEC2C[];
extern Member D_00419D18[];
extern int D_004A657C, D_004A6580, D_004A6584;
int FUN_00260150(int, int);
void FUN_00265db0(int);

// MATCH func_00260A18
void FUN_00260a18(void)
{
    if (D_004A5E50 > 2) {
        D_004A5E38 = 1;
        return;
    }
    if (D_00314D08[D_004A5E50] == 1 && D_003FEC2C[0] != 0) {
        D_004A5E38 = 1;
        return;
    }
    switch (D_00314D08[D_004A5E50]) {
    case 0:
        if ((D_00419D18 + D_004A5E50)->kind == 116)
            FUN_00260150(0, 76);
        else
            FUN_00260150(0, 70);
        break;
    case 1:
        if ((D_00419D18 + D_004A5E50)->kind == 116)
            FUN_00260150(1, 65);
        else
            FUN_00260150(1, 59);
        break;
    case 2:
        if ((D_00419D18 + D_004A5E50)->kind == 116)
            FUN_00260150(2, 46);
        else
            FUN_00260150(2, 40);
        break;
    case 3:
        if ((D_00419D18 + D_004A5E50)->kind == 116)
            FUN_00260150(3, 46);
        else
            FUN_00260150(3, 40);
        break;
    case 4:
        if ((D_00419D18 + D_004A5E50)->kind == 116)
            FUN_00260150(4, 38);
        else
            FUN_00260150(4, 32);
        break;
    case 5:
        FUN_00260150(0, 81);
        break;
    }
}

// MATCH func_00260C00
void FUN_00260c00(void)
{
    if (D_004A5E50 > 2) {
        D_004A5E38 = 1;
        return;
    }
    if (D_00314D08[D_004A5E50] == 1 && D_003FEC2C[0] != 0) {
        D_004A5E38 = 1;
        return;
    }
    switch (D_00314D08[D_004A5E50]) {
    case 0:
        FUN_00260150(0, 0x43);
        break;
    case 1:
        FUN_00260150(1, 0x38);
        break;
    case 2:
        FUN_00260150(2, 0x25);
        break;
    case 3:
        FUN_00260150(3, 0x25);
        break;
    case 4:
        FUN_00260150(4, 0x1d);
        break;
    }
}

/* runs FUN_00265db0 for each of the 5 states, then puts everything back */
// MATCH func_0026A570
void FUN_0026a570(void)
{
    int saved[7];
    int i;
    saved[0] = D_00314D08[0];
    saved[1] = D_00314D08[1];
    saved[2] = D_00314D08[2];
    saved[3] = D_00314D08[3];
    saved[4] = D_004A657C;
    saved[5] = D_004A6584;
    saved[6] = D_004A6580;
    D_00314D08[3] = -1;
    D_00314D08[2] = -1;
    D_00314D08[1] = -1;
    for (i = 0; i < 5; i++) {
        D_00314D08[0] = i;
        D_004A657C = 0;
        D_004A6584 = 0;
        D_004A6580 = 0;
        FUN_00265db0(1);
    }
    D_00314D08[0] = saved[0];
    D_00314D08[1] = saved[1];
    D_00314D08[2] = saved[2];
    D_00314D08[3] = saved[3];
    D_004A657C = saved[4];
    D_004A6584 = saved[5];
    D_004A6580 = saved[6];
}
