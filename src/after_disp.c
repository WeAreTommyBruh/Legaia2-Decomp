/* Functions after disp.cpp whose source file is not known (group
   _unknown_after_disp in decomp/functions.csv): drawing helpers that build
   GS register packets, a list of display objects sorted by depth, and small
   wrappers around the drawing calls. Matched by hand. */
#include "common.h"
#include "gs.h"

/* the GS packet being built: `p` is where the next register write goes */
typedef struct {
    int unk0[4];
    u64 *p;
} PacketBuf;

typedef struct {
    float x, y, z, w;
} Vec4;

/* the table at +0x90 of a display object: 128 positions, then one handle each */
typedef struct {
    Vec4 pos[0x80];
    int unk800;
    int handle[1];
} PosTable;

typedef struct {
    char unk0[0x10];
    int x, y;
    char unk18[0x268];
} Grid;

extern PacketBuf D_00342CD0;
extern int D_004A147C, D_004A1480, D_004A1484, D_004A1488; /* texture: base, width, w, h */
extern int D_005EE990[8];                                   /* GS TEST fields */
extern int D_004A70E4, D_004A70E8, D_004A70EC, D_004A70F0, D_004A70F4;
extern float D_004A70B0, D_004A70B8;
extern int D_004A13E8, D_004A13F0, D_004A14B4, D_004A14B8;
extern int D_004A7090;
extern float D_004A7100, D_004A70D4, D_004A70AC;
extern float D_004A0660, D_004A0664, D_004A0668, D_004A066C;
extern int D_003D3F18[];
extern Grid D_003D15C8[];
extern char D_00320E20[], D_00321030[], D_0045C130[], D_005EEA00[];
extern char D_00231898[]; /* a function, passed as a callback */

float sqrtf(float);
void FUN_0022fdd8(void *);
void FUN_0022fee8(int, int, int, int);
void FUN_00231d98(float, float, float);
int FUN_00111870(void);
void FUN_0018df68(void *, void *);
void FUN_0018e860(void *, float, float, float);
void FUN_0018f3d8(void *, void *, void *);
void FUN_00190328(PacketBuf *);
void FUN_00190420(PacketBuf *);
void FUN_0022d470(Vec4 *, void *, void *);
void FUN_002302b0(int, int, int, int);
void FUN_002304a0(int, int, int, int);
int FUN_002306e8(int, int, int, int);
int FUN_00230cb0(void);
void FUN_00231548(void);
int FUN_00231580(float, float, int, int, int);
void FUN_00231f28(float *);
void FUN_00232618(int, int, int, int, int, int, int, int, int, int);
void FUN_00235960(Grid *, int, int, int, int);
void FUN_00236828(int, int, int, int, int, int, int);
void FUN_00237938(int, int, int, int, int, int, int, int, int, int);
void FUN_00239568(int, int);
void object_00243a68(int, PacketBuf *);
void func_00247A40(int, int, int, int);
void FUN_00247970(int);
void FUN_002479f0(void);
void FUN_00247ef8(int, int);
void FUN_00249e18(int);
void FUN_00249e28(float, void *);
int FUN_0024cdd0(void *, void *, Vec4 *);
void battle_00126fa8(float, int, int, s16, s16, s16, int);
void yokota_0023e010(int);
void yokota_0023e1a8(float, float, int, int, int);
void yokota_0023e650(float);
void yokota_0023e7c0(float, int, float, float, int, int);
void yokota_0023ead0(float, int, float, float, int, int);

// MATCH func_0022F0F8
void FUN_0022f0f8(void *p)
{
    int b;
    object_00243a68(0, &D_00342CD0);
    yokota_0023e010(0);
    object_00243a68(0, &D_00342CD0);
    b = FIELD(u8, p, 0xd1);
    yokota_0023e1a8(1.0f, 1.0f, 1, (b * b) / 128, 0);
}

// MATCH func_0022F178
void FUN_0022f178(void *p)
{
    float one = 1.0f;
    float f = one - (float)FIELD(u8, p, 0xd1) * 0.0078125f;
    object_00243a68(0, &D_00342CD0);
    yokota_0023e650(f);
    yokota_0023e010(0);
    yokota_0023ead0(one, 1, one, f, FIELD(u8, p, 0xd1), 0);
}

// MATCH func_0022F208
void FUN_0022f208(void *p)
{
    float one = 1.0f;
    object_00243a68(0, &D_00342CD0);
    yokota_0023e010(0);
    yokota_0023e7c0(one, 1, one, 0.0f, FIELD(u8, p, 0xd1), 0);
}

/* length of (x, y) */
// MATCH func_0022F5A0
float FUN_0022f5a0(float x, float y)
{
    return sqrtf(x * x + y * y);
}

/* length of (x, y, z) */
// MATCH func_0022F5E0
float FUN_0022f5e0(float x, float y, float z)
{
    return sqrtf(x * x + y * y + z * z);
}

// MATCH func_0022FDD8
void FUN_0022fdd8(void *p)
{
    if (FUN_00111870() == 0 && D_004A70E4 != 2) {
        float f = FIELD(float, p, 0x140) + FIELD(float, p, 0x148);
        FIELD(int, p, 0x13c) = 0;
        FIELD(float, p, 0x140) = f;
        if (1.0f < f)
            FIELD(int, p, 0x140) = 0;
        if (FIELD(float, p, 0x140) < 0.0f)
            FIELD(float, p, 0x140) = 1.0f;
    }
}

// MATCH func_0022FE58
void FUN_0022fe58(int a, int b, int c, int d)
{
    D_004A70F0 = 1;
    FUN_0022fdd8((void *)a);
    FUN_0022fee8(a, b, c, d);
    D_004A70F0 = 0;
}

// MATCH func_0022FEE8
void FUN_0022fee8(int a, int b, int c, int d)
{
    D_004A70F4 = 1;
    D_004A70EC = 0;
    FUN_002302b0(a, b, c, d);
    FUN_002304a0(a, b, c, d);
    D_004A70F4 = 0;
}

// MATCH func_00230078
void FUN_00230078(int p, int i, int c, int d)
{
    Vec4 *v = &FIELD(PosTable *, p, 0x90)->pos[i];
    FUN_00231580(v->x, v->y, p, FIELD(PosTable *, p, 0x90)->handle[i], (int)v->z);
    FUN_002306e8(p, i, c, d);
    FUN_00231548();
}

// MATCH func_00230100
void FUN_00230100(int p, int i, int c, int d)
{
    FUN_00231580(FIELD(float, p, 0x13c), FIELD(float, p, 0x140), p,
                 FIELD(PosTable *, p, 0x90)->handle[i], (int)FIELD(float, p, 0x144));
    FUN_002306e8(p, i, c, d);
    FUN_0022fdd8((void *)p);
    FUN_00231548();
}

// MATCH func_00230220
void FUN_00230220(int p, int i, int c, int d)
{
    int h = FIELD(PosTable *, p, 0x90)->handle[i];
    if (h != 0)
        FUN_00231580(FIELD(float, p, 0x13c), FIELD(float, p, 0x140), p, h,
                     (int)FIELD(float, p, 0x144));
    FUN_0022fdd8((void *)p);
    FUN_002306e8(p, i, c, d);
    FUN_00231548();
}

/* TEX0_1 value for the current texture */
// MATCH func_00230690
u64 FUN_00230690(void)
{
    return GS_SET_TEX0(D_004A147C, D_004A1480, 0x13, D_004A1484, D_004A1488, 1, 0, 0x3e24, 0, 0, 0, 1);
}

// MATCH func_00230C90
void FUN_00230c90(int a)
{
    FUN_00239568((int)D_0045C130, *(int *)(D_004A14B4 + 0x14) + a * 0x30);
}

// MATCH func_00231128
void FUN_00231128(float a)
{
    D_004A70B8 = a;
}

// MATCH func_002311E0
int FUN_002311e0(int p, int i)
{
    float *v;
    FUN_00230cb0();
    v = (float *)(FIELD(int, p, 0x90) + i * 0x10);
    FUN_00231d98(v[0], v[1], v[2]);
    return 1;
}

/* writes TEX0_1 for the current texture to the packet */
// MATCH func_00231308
void FUN_00231308(void)
{
    u64 *p;
    FUN_00190328(&D_00342CD0);
    p = D_00342CD0.p;
    p[0] = GS_SET_TEX0(D_004A147C, D_004A1480, 0x13, D_004A1484, D_004A1488, 1, 0, 0x3c00, 0, 0, 0, 1);
    p[1] = GS_TEX0_1;
    D_00342CD0.p = p + 2;
    FUN_00190420(&D_00342CD0);
}

/* inserts `n` into the list at D_004A13F0, which is sorted by the float at +0x58 */
// MATCH func_00231688
void FUN_00231688(int n)
{
    int cur, next, i = 0;
    float k;
    if (D_004A13F0 == 0) {
        D_004A13F0 = n;
        FIELD(int, n, 0xc) = 0;
        return;
    }
    next = D_004A13F0;
    do {
        cur = next;
        next = FIELD(int, cur, 0xc);
        k = FIELD(float, cur, 0x58);
        if ((FIELD(u32, cur, 0x18) & 10) == 0 && k < FIELD(float, n, 0x58)) {
            if (i != 0) {
                FIELD(int, cur, 0xc) = n;
                FIELD(int, n, 0xc) = next;
                return;
            }
            FIELD(int, n, 0xc) = cur;
            D_004A13F0 = n;
            return;
        }
        i++;
    } while (next != 0);
    FIELD(int, cur, 0xc) = n;
    FIELD(int, n, 0xc) = 0;
}

// MATCH func_00231700
void FUN_00231700(float *a, float *b)
{
    a[0] = b[0];
    a[1] = b[1];
    a[2] = b[2];
}

// MATCH func_00231808
void FUN_00231808(int p, int i)
{
    FUN_00230cb0();
    if (D_004A70E8 != 0) {
        Vec4 *v;
        FUN_0022d470(&FIELD(Vec4 *, p, 0x90)[i], (void *)0x70003f80, (void *)0x70003e00);
        v = &FIELD(Vec4 *, p, 0x90)[i];
        v->w = D_004A70B0;
        FUN_0024cdd0(D_00320E20, D_00231898, v);
    }
}

// MATCH func_002318A0
void FUN_002318a0(void)
{
    D_004A7090 = 0;
    FUN_00249e28(D_004A7100, D_00321030);
    D_004A70D4 = D_004A70D4 + D_004A0660;
    D_004A70B0 = D_004A70B0 + D_004A0664;
    if (D_004A0668 < D_004A70D4)
        D_004A70D4 = 0.0f;
    D_004A70AC = D_004A70AC + D_004A066C;
    if (1.0f < D_004A70AC)
        D_004A70AC = 0.0f;
}

// MATCH func_00231930
void FUN_00231930(float a, float b, float c, float d)
{
    D_004A7100 = d;
    FUN_00249e18((int)D_00321030);
}

/* sets the fields of the GS TEST register (see FUN_00231b90) */
// MATCH func_00231B60
void FUN_00231b60(int ate, int atst, int aref, int afail, int date, int datm, int zte, int ztst)
{
    D_005EE990[0] = ate;
    D_005EE990[1] = atst;
    D_005EE990[2] = aref;
    D_005EE990[3] = afail;
    D_005EE990[4] = date;
    D_005EE990[5] = datm;
    D_005EE990[6] = zte;
    D_005EE990[7] = ztst;
}

/* writes TEST_1 to the packet */
// MATCH func_00231B90
void FUN_00231b90(void)
{
    u64 *p = D_00342CD0.p;
    p[0] = GS_SET_TEST(D_005EE990[0], D_005EE990[1], D_005EE990[2], D_005EE990[3],
                       D_005EE990[4], D_005EE990[5], D_005EE990[6], D_005EE990[7]);
    p[1] = GS_TEST_1;
    D_00342CD0.p = p + 2;
}

/* x, y, z go on to FUN_0018e860 (matrices in the scratchpad) */
// MATCH func_00231D98
void FUN_00231d98(float x, float y, float z)
{
    FUN_0018e860((void *)0x70003f00, x, y, z);
    FUN_0018f3d8((void *)0x70003f80, (void *)0x70003f80, (void *)0x70003f00);
    FUN_0018f3d8((void *)0x70003c80, (void *)0x70003c80, (void *)0x70003f00);
    if (D_004A14B8 != 0) {
        FUN_0018df68((void *)0x70003f40, (void *)0x70003f00);
        FUN_0018f3d8((void *)0x70003d80, (void *)0x70003f40, (void *)0x70003d80);
    }
}

// MATCH func_00231EF0
void FUN_00231ef0(float x, float y, float z)
{
    ((float *)0x70003e40)[0] = x;
    ((float *)0x70003e40)[1] = y;
    ((float *)0x70003e40)[2] = z;
    ((float *)0x70003e40)[3] = 1.0f;
    FUN_00231f28((float *)0x70003e40);
}

// MATCH func_00231FC8
int FUN_00231fc8(int x)
{
    return (x & 7) + (x / 32) * 32 + (((x & 0x1f) / 16) * 8 + ((x & 0xf) / 8) * 16);
}

// MATCH func_002327A8
void FUN_002327a8(int a, int b, int c, int d, int e, int f, int g, int h)
{
    FUN_00232618(a, b, c, f, g, d, e, f, g, h);
}

// MATCH func_002327F0
void FUN_002327f0(int a, int b, int c, int d, int e)
{
    D_004A13E8 = e;
    FUN_00247970(4);
    func_00247A40(a, b, c, d);
    FUN_00247ef8(0x6c00, 0x7900);
    FUN_00247ef8(0x9400, 0x7900);
    FUN_00247ef8(0x6c00, 0x8800);
    FUN_00247ef8(0x9400, 0x8800);
    FUN_002479f0();
    D_004A13E8 = -1;
}

// MATCH func_00233680
void FUN_00233680(void *p)
{
    u16 x = FIELD(u16, p, 8);
    u16 y = FIELD(u16, p, 10);
    FIELD(u16, p, 0x5c) = x;
    FIELD(u16, p, 0x5e) = y;
    battle_00126fa8(1.0f, -1, -1, FIELD(s16, p, 0x62), x, y, (int)(FIELD(float, p, 0x28) * 128.0f));
}

/* 1 when every object in the list at D_003D3F18 has 1.0 at +0x28 */
// MATCH func_002350E8
int FUN_002350e8(void)
{
    int p = D_003D3F18[0];
    while (p) {
        int q = p;
        p = FIELD(int, q, 0x3c);
        if (FIELD(float, q, 0x28) != 1.0f)
            return 0;
    }
    return 1;
}

// MATCH func_00236C60
void FUN_00236c60(int a, int b, int c, int d, int e, int f)
{
    FUN_00236828(0, a, b, c, d, e, f);
}

/* cell `c` of an 11-wide grid of 22-pixel cells */
// MATCH func_00236D60
void FUN_00236d60(int a, int b, int c, int d)
{
    D_003D15C8[1].x = (c % 11) * 22;
    D_003D15C8[1].y = (c / 11) * 22;
    FUN_00235960(&D_003D15C8[1], a, b, 0x808080, d);
}

// MATCH func_00237A40
char *FUN_00237a40(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    FUN_00237938(a, b, 2, c, d, e, f, g, h, i);
    return D_005EEA00 + a * 0x80;
}
