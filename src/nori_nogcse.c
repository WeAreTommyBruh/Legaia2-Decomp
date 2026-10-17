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
