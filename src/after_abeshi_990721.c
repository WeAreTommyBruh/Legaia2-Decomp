/* Functions of _unknown_after_abeshi built with the older ee-gcc
   2.9-ee-990721, which here leaves short loops' delay slots empty (see
   tools/asm_build.py). Matched by hand. */
// compiler: 990721-r5900
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
int FUN_00268580(int);

extern s64 D_004A12F0; /* the pad's buttons */
extern int D_004A140C, D_004A64A0, D_004A1448;
extern float D_004A5AD4;   /* turn step */
extern float D_004028E0[]; /* two angles */
extern float D_004028D0[]; /* a position */
extern char D_00320E20[];
extern int D_002F9800[];
void FUN_00110080(int);
void FUN_00299168(void);
void FUN_00133858(void);
void nori_002709c0(void);
void nori_00270c88(void);
void FUN_00139cf8(void);
void FUN_00290ba8(void);
void FUN_0024ce38(void *);
void FUN_0024ce40(void *);
void window_00195908(void);
void work_00246ad0(int);
void work_00246b98(int);
void nori_0026c7a8(void);
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
/* a frame of the camera test: the pad turns (wrapping at pi) and moves it */
// MATCH func_00264600
void FUN_00264600(void)
{
    FUN_00110080(0);
    D_004A5E50 = 0;
    if ((int)(D_004A12F0 & 1)) {
        if ((D_004A12F0 & 0x40) && (D_004028E0[0] += D_004A5AD4) > 3.14159265f)
            D_004028E0[0] -= 6.28318531f;
        if ((D_004A12F0 & 0x10) && (D_004028E0[0] -= D_004A5AD4) <= -3.14159265f)
            D_004028E0[0] += 6.28318531f;
        if ((D_004A12F0 & 0x20) && (D_004028E0[1] += D_004A5AD4) > 3.14159265f)
            D_004028E0[1] -= 6.28318531f;
        if ((D_004A12F0 & 0x80) && (D_004028E0[1] -= D_004A5AD4) <= -3.14159265f)
            D_004028E0[1] += 6.28318531f;
        if (D_004A12F0 & 0x2000)
            D_004028D0[0] -= 200.0f;
        if (D_004A12F0 & 0x8000)
            D_004028D0[0] += 200.0f;
        if (D_004A12F0 & 0x4000)
            D_004028D0[1] -= 200.0f;
        if (D_004A12F0 & 0x1000)
            D_004028D0[1] += 200.0f;
        if (D_004A12F0 & 2)
            D_004028D0[2] += 400.0f;
        if (D_004A12F0 & 8)
            D_004028D0[2] -= 400.0f;
        D_004A140C = 0;
    }
    if (D_004A64A0 == 1 && D_004A1448 == 1) {
        FUN_00299168();
        FUN_00133858();
        nori_002709c0();
    }
    nori_00270c88();
    FUN_00139cf8();
    FUN_00290ba8();
    FUN_0024ce38(D_00320E20);
    window_00195908();
    work_00246ad0(D_002F9800[1]);
    work_00246b98(D_002F9800[1]);
    work_00246ad0(D_002F9800[2]);
    work_00246b98(D_002F9800[2]);
    FUN_0024ce40(D_00320E20);
    nori_0026c7a8();
}

/* waits (empty counting loops, their bodies compiled out) for each of
   the records of FUN_00268580(0) that have flags set */
// MATCH func_00268470
void FUN_00268470(void)
{
    int p = FUN_00268580(0);
    int i, j, m, k;
    if (FIELD(int, p, 8) != 0) {
        m = FIELD(int, p, 0xb14);
        for (i = 0; i < FIELD(int, p, 4); i = k) {
            int q;
            k = i + 1;
            q = p + 12 + i * 936;
            if (FIELD(u8, q, 0x356))
                for (j = 0; j < 40; j++)
                    ;
            if (FIELD(u8, q, 0x37e))
                for (j = 0; j < 30; j++)
                    ;
            if (FIELD(u8, q, 0x39c))
                for (j = 0; j < 10; j++)
                    ;
        }
        for (i = 0; i < m; i++)
            ;
    }
}

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
