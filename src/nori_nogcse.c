/* Functions of nori that were built without global CSE (`-fno-gcse`): the
   other nori functions do not match that way, so they come from another
   source file. Matched by hand. */
// cflags: -fno-gcse
#include "common.h"

extern int D_004A12A4;
extern s64 D_004A12F0;
extern int D_004A6724, D_004A6728, D_004A672C;
extern float D_004A6730, D_004A6734, D_004A6738, D_004A673C;
extern float D_0041EA40[4];
void FUN_00249108(void);
void func_00249100(float, float, float);
void FUN_00248cf8(int, float);
void FUN_002489f0(void);
void FUN_00218dc0(int, float, float);
void FUN_002491d8(void);
void FUN_0021b600(int);
void nori_002772f0(int);
void FUN_0022ecb0(int);
void FUN_0018f3d8(void *, void *, void *);
void FUN_0022d470(void *, void *, void *);

/* one of the 4 stage lights at D_0041F1D0, 0x7b0 bytes each */
typedef struct {
    char unk0[0x760];
    int kind;
    char unk764[0x7a0 - 0x764];
    int unk7a0;
    int unk7a4;
    char unk7a8[0x7b0 - 0x7a8];
} Light;

extern int D_004A6598;
extern float D_004254F0[4];
extern int D_0041F090[];
extern Light D_0041F1D0[4];
extern int D_0041B7E0[];
extern float D_0041F138[];
int FUN_00133848(void);
void FUN_002a8228(Light *, int, int, float, float, float);
void FUN_002a8600(Light *, int, int, float, float);
void FUN_002a8358(Light *, int, int, float, float, float);
void FUN_00299118(int);
void FUN_002a8818(Light *, int);
void FUN_002a8850(Light *, int, int);
void FUN_002a86f0(Light *, int, float);
void FUN_002a8788(Light *, float, float);
void FUN_002a8950(Light *, float, float, float);
void FUN_00294418(Light *, float, float, float);

/* sets up the stage's lights from the 0x100-byte entry `D_004A6598` of
   the table FUN_00133848 returns */
// MATCH func_002709C0
void nori_002709c0(void)
{
    int p = FUN_00133848() + D_004A6598 * 0x100;
    Light *l0 = &D_0041F1D0[0], *l1 = &D_0041F1D0[1], *l2 = &D_0041F1D0[2], *l;
    D_004254F0[0] = FIELD(float, p, 16);
    D_0041F090[31] = FIELD(int, p, 0);
    D_004254F0[1] = FIELD(float, p, 20);
    D_0041F090[32] = FIELD(int, p, 4);
    D_0041F090[40] = 0;
    D_004254F0[2] = FIELD(float, p, 24);
    D_0041F090[33] = FIELD(int, p, 8);
    D_004254F0[3] = FIELD(float, p, 28);
    D_0041F090[34] = FIELD(int, p, 12);
    l0->kind = 2;
    FUN_002a8228(l0, 0, 0, FIELD(float, p, 32), FIELD(float, p, 36), FIELD(float, p, 40));
    FUN_002a8600(l0, 0, 0, FIELD(float, p, 44), FIELD(float, p, 48));
    FUN_002a8358(l0, 0, 0, FIELD(float, p, 56), FIELD(float, p, 60), FIELD(float, p, 64));
    l1->kind = 2;
    FUN_002a8228(l1, 0, 0, FIELD(float, p, 68), FIELD(float, p, 72), FIELD(float, p, 76));
    FUN_002a8600(l1, 0, 0, FIELD(float, p, 80), FIELD(float, p, 84));
    FUN_002a8358(l1, 0, 0, FIELD(float, p, 92), FIELD(float, p, 96), FIELD(float, p, 100));
    l2->kind = 2;
    FUN_002a8228(l2, 0, 0, FIELD(float, p, 104), FIELD(float, p, 108), FIELD(float, p, 112));
    FUN_002a8600(l2, 0, 0, FIELD(float, p, 116), FIELD(float, p, 120));
    FUN_002a8358(l2, 0, 0, FIELD(float, p, 128), FIELD(float, p, 132), FIELD(float, p, 136));
    if (FIELD(float, p, 160) == 2.0f)
        FUN_00299118(0);
    if (FIELD(float, p, 160) == 4.0f)
        FUN_00299118(2);
    l = &D_0041F1D0[3];
    if (FIELD(float, p, 160) != 4.0f) {
        D_0041F1D0[3].kind = 2;
    } else {
        do {
            l->kind = 4;
        } while (0);
        do {
            l->unk7a4 = -1;
        } while (0);
        {
            int b = D_0041B7E0[0];
            int a = FIELD(int, p, 204);
            l->unk7a0 = b;
            FUN_002a8818(l, a);
        }
        FUN_002a8850(l, FIELD(int, p, 208), FIELD(int, p, 212));
        FUN_002a86f0(l, FIELD(int, p, 216), FIELD(float, p, 220));
        FUN_002a8788(l, FIELD(float, p, 224), FIELD(float, p, 228));
        FUN_002a8950(l, FIELD(float, p, 232), FIELD(float, p, 236), FIELD(float, p, 240));
        FUN_00294418(l, FIELD(float, p, 244), FIELD(float, p, 248), FIELD(float, p, 252));
    }
    D_0041F138[15] = FIELD(float, p, 188);
    D_0041F138[25] = FIELD(float, p, 192);
    D_0041F138[20] = FIELD(float, p, 196);
    D_0041F138[30] = FIELD(float, p, 200);
}

/* draws model `o` */
// MATCH func_002770E8
void nori_002770e8(int o)
{
    float m[16];
    if (D_004A12A4 == 11)
        return;
    if (FIELD(u32, o, 24) & 2)
        return;
    if (!(FIELD(u32, o, 24) & 0x80)) {
        FUN_00249108();
        func_00249100(FIELD(float, o, 128), 0.0f, FIELD(float, o, 136));
        FUN_00248cf8(0, FIELD(float, o, 64));
        FUN_00248cf8(1, FIELD(float, o, 68));
        FUN_00248cf8(2, FIELD(float, o, 72));
        FUN_002489f0();
        if ((int)(D_004A12F0 & 1))
            FUN_00218dc0(255, D_0041EA40[0] * 4608.0f, D_0041EA40[1] * 4608.0f);
        else
            FUN_00218dc0(0xff00, D_0041EA40[2] * 4608.0f, D_0041EA40[3] * 4608.0f);
        FUN_002491d8();
    }
    FUN_00249108();
    func_00249100(FIELD(float, o, 32), FIELD(float, o, 36), FIELD(float, o, 40));
    FUN_00248cf8(0, FIELD(float, o, 64));
    FUN_00248cf8(1, FIELD(float, o, 68));
    FUN_00248cf8(2, FIELD(float, o, 72));
    FUN_0021b600(o);
    nori_002772f0(o);
    if (D_004A6724 != 0 && FIELD(float, o, 196) == 0.0f) {
        D_004A6728 = D_004A672C;
        D_004A6730 = D_004A6734;
        D_004A6738 = D_004A673C;
    }
    if (!(FIELD(u32, o, 24) & 0x80))
        FUN_0022ecb0(o);
    if (D_004A6724 != 0 && D_004A6728 != 0 && D_004A6738 < FIELD(float, o, 196)) {
        D_004A6728--;
        FIELD(float, o, 196) = FIELD(float, o, 196) + (D_004A6730 - D_004A6738);
    }
    FUN_0018f3d8(m, (void *)0x70003c00, (void *)0x70003f80);
    FUN_0022d470((void *)(o + 80), m, (void *)0x70003e00);
    FUN_002491d8();
}
