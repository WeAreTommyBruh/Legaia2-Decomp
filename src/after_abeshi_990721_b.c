/* More of _unknown_after_abeshi built like after_abeshi_990721.c (its
   switch table is in another part of .rodata, so it comes from another
   source file). Matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "common.h"

/* a 472-byte record of D_003FEBA8 */
typedef struct {
    char unk0[0x78];
    int x78, x7c, x80, x84;
    char unk88[0x94 - 0x88];
    u32 need94, need98; /* compared with a threshold in FUN_002695e0 */
    char unk9c[0xe8 - 0x9c];
    float xe8, xec;
    int xf0;
    char unkf4[0x1ab - 0xf4];
    u8 b1ab;
    char unk1ac[0x1d8 - 0x1ac];
} Rec;
extern struct {
    int money;
    char unk4[4];
    int x8;
    char unkc[0x7c - 0xc];
    int x7c, x80, x84, x88, x8c;
    char unk90[0x18f0 - 0x90];
    Rec rec[5];
} D_003FEBA8;
typedef struct {
    char unk0[0x12d0];
    int flags;
    char unk12d4[0x1560 - 0x12d4];
} Chr;
extern Chr *D_004A1A20;
extern int D_00314D08[4];
extern int D_004A12A4;
extern int D_004A657C, D_004A6580, D_004A6584;
void FUN_00265db0(int);
void FUN_00290bd8(int);

typedef struct { char pad[0x42]; u8 b42, b43; char pad2[0x48 - 0x44]; } Slot;
extern Slot D_003FDFA0[];
typedef struct { char pad[0x30]; int x30; char p2[0x64 - 0x34]; int x64; char p3[0xb0 - 0x68]; } Member;
extern Member D_00419D18[];
void FUN_0025b108(int);

/* runs FUN_00265db0(1) for each of five thresholds with the first
   member's state set to 0-4 and the others to -1, then puts the states and
   D_004A657C-84 back */
// MATCH func_002695E0
void FUN_002695e0(void)
{
    int saved[7];
    u32 xp;
    int i;
    D_003FEBA8.rec[1].xf0 = 0;
    if (D_003FEBA8.rec[0].b1ab == 0)
        D_003FEBA8.rec[0].b1ab = 1;
    if (D_004A12A4 == 11) {
        for (i = 0; i < 3; i++) {
            if (D_00314D08[i] == 1)
                D_004A1A20[i].flags |= 0x4000;
        }
    }
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
    xp = 0;
    for (i = 0; i < 5; i++) {
        switch (i) {
        case 0:
            xp = 0x98214e;
            break;
        case 1:
            xp = 0x95140f;
            break;
        case 2:
            xp = 0x90802f;
            break;
        case 3:
            xp = 0x88df0f;
            break;
        case 4:
            xp = 0x85d1cf;
            break;
        }
        D_00314D08[0] = i;
        if (D_003FEBA8.rec[i].need94 < xp)
            D_004A657C = xp - D_003FEBA8.rec[i].need94;
        if (D_003FEBA8.rec[i].need98 < xp)
            D_004A6580 = xp - D_003FEBA8.rec[i].need98;
        D_003FEBA8.rec[i].x84 = 0x7ffffffb;
        D_003FEBA8.rec[i].x80 = 0x7ffffffc;
        D_003FEBA8.rec[i].x78 = 0x7fffffff;
        D_003FEBA8.rec[i].x7c = 0x7fffffff;
        FUN_00265db0(1);
    }
    D_003FEBA8.x8c = 0x7ffffffc;
    D_00314D08[0] = saved[0];
    D_003FEBA8.x8 = 0x7ffffffc;
    D_00314D08[1] = saved[1];
    D_00314D08[2] = saved[2];
    D_00314D08[3] = saved[3];
    D_004A657C = saved[4];
    D_004A6584 = saved[5];
    D_004A6580 = saved[6];
    for (i = 0; i < 4; i++) {
        if (D_00314D08[i] >= 0)
            FUN_00290bd8(i);
    }
}

/* the same five-state sweep, which also copies each record's xe8 to xec and
   each slot's b42 to b43, and finally restarts the characters that were on */
// MATCH func_0026A2B8
void FUN_0026a2b8(void)
{
    int saved[7];
    Slot *tbl;
    int i;
    D_003FEBA8.rec[1].xf0 = 0;
    if (D_004A12A4 == 11) {
        for (i = 0; i < 3; i++) {
            if (D_00314D08[i] == 1)
                D_004A1A20[i].flags |= 0x4000;
        }
    }
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
    tbl = D_003FDFA0;
    for (i = 0; i < 5; i++) {
        D_00314D08[0] = i;
        if (i == 0 && D_003FEBA8.rec[0].b1ab == 0)
            D_003FEBA8.rec[0].b1ab = 1;
        D_003FEBA8.rec[i].xec = D_003FEBA8.rec[i].xe8;
        { Slot *s = tbl + i; s->b43 = s->b42; }
        if (i < 3 && D_004A12A4 == 11)
            D_00419D18[i].x64 = D_00419D18[i].x30;
        if (D_003FEBA8.rec[i].need94 < 9999999)
            D_004A657C = 9999999 - D_003FEBA8.rec[i].need94;
        if (D_003FEBA8.rec[i].need98 < 5999999)
            D_004A6580 = 9999999 - D_003FEBA8.rec[i].need98;
        FUN_00265db0(1);
        FUN_0025b108(i);
        if (D_003FEBA8.money < 9999999 && i == 0)
            D_004A6584 = 9999999 - D_003FEBA8.money;
    }
    D_00314D08[0] = saved[0];
    D_00314D08[1] = saved[1];
    D_00314D08[2] = saved[2];
    D_00314D08[3] = saved[3];
    D_004A657C = saved[4];
    D_004A6584 = saved[5];
    D_004A6580 = saved[6];
    D_003FEBA8.x88 = 0;
    D_003FEBA8.x84 = 0;
    D_003FEBA8.x80 = 0;
    D_003FEBA8.x7c = 0;
    for (i = 0; i < 4; i++) {
        if (D_00314D08[i] >= 0)
            FUN_00290bd8(i);
    }
}
