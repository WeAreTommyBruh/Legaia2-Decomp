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
void FUN_00260150(int, int);
void FUN_00265db0(int);
int FUN_0010e240(void *);
void FUN_0010e368(void *);
void work_00246d88(void *, int);

extern int D_00314CC8[], D_002F9808[];
extern int D_005F8780[21];
extern int D_004A724C, D_004A7250, D_004A7254, D_004A7258, D_004A66C4, D_004A12A4;
extern int D_004A5E3C, D_004A5E40, D_004A5E44;
extern char D_00343028[], D_004029E0[];

/* like FUN_0025feb0, but starts work_00246d88 only for a new (set, id),
   and not while FUN_0010e240 is busy outside mode 11 */
// MATCH func_00260150
void FUN_00260150(int set, int id)
{
    if (set == 1 && D_003FEC2C[0] != 0)
        return;
    D_005F8780[0] = 82;
    D_005F8780[1] = 69;
    D_005F8780[2] = 75;
    D_005F8780[3] = 48;
    D_005F8780[4] = 145;
    D_005F8780[5] = 97;
    D_005F8780[6] = 480;
    D_005F8780[7] = 84;
    D_005F8780[8] = 34;
    D_005F8780[9] = 24;
    D_005F8780[10] = 19;
    D_005F8780[11] = 9;
    D_005F8780[12] = 16;
    D_005F8780[13] = 21;
    D_005F8780[14] = 7;
    D_005F8780[15] = 22;
    D_005F8780[16] = 16;
    D_005F8780[17] = 8;
    D_005F8780[18] = 14;
    D_005F8780[19] = 12;
    D_005F8780[20] = 218;
    D_004A724C = set;
    D_004A7250 = id;
    if (set == 8 && id < 4 && D_00314CC8[0] == 173 && (D_004A66C4 & 3) == 1)
        D_004A7250 += 4;
    if (D_004A724C == 5 && D_004A7250 >= 12 && D_004A7250 < 22 && D_00314CC8[0] == 173 &&
        (D_004A66C4 & 3) == 1)
        D_004A7250 += 10;
    if (D_004A724C == 8 && D_004A7250 >= 8 && D_004A7250 < 10 && D_00314CC8[0] == 115 &&
        (D_004A66C4 & 0x40))
        D_004A7250 += 2;
    if (D_004A724C == 5 && D_004A7250 >= 32 && D_004A7250 < 42 && D_00314CC8[0] == 115 &&
        (D_004A66C4 & 0x40))
        D_004A7250 += 10;
    if (D_004A724C != D_004A7254 || D_004A7250 != D_004A7258) {
        if (D_004A5E44 == 0 && FUN_0010e240(D_00343028) != 0) {
            if (D_004A12A4 != 11)
                return;
            FUN_0010e368(D_00343028);
        }
        D_004A5E3C = 0;
        D_004A5E40 = 0;
        work_00246d88(D_004029E0, D_002F9808[0]);
    }
    D_004A7254 = D_004A724C;
    D_004A7258 = D_004A7250;
}

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
