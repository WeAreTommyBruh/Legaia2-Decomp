/* nori.cpp (group nori in decomp/functions.csv): the battle stage's 3D
   objects, saved character positions, a list of messages and a few
   drawing helpers. Matched by hand. */
#include "common.h"

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    char unk0[0x20];
    Vec4 pos;
    char unk30[0x10];
    Vec4 rot;
} Model;

/* a battle character, 0x1560 bytes each (array at D_004A1A20) */
typedef struct {
    char unk0[0x12c0];
    Model *model;
    char unk12c4[0xc];
    int flags;
    char unk12d4[0x1560 - 0x12d4];
} Chr;

typedef struct {
    char unk0[0x22];
    s16 x;
} Slot;

/* the table at +0x90 of a display object (see after_disp.c) */
typedef struct {
    char unk0[0x804];
    int handle[1];
} PosTable;

/* one of the 4 stage lights at D_0041F1D0 (see nori_nogcse.c) */
typedef struct {
    char unk0[0x7b0];
} Light;

/* a light's settings in a Stage */
typedef struct {
    float pos[3];
    float dir[2];
    float unk14;
    float color[3];
} LightSet;

/* the 0x100-byte entries of the table FUN_00133848 returns */
typedef struct {
    char unk0[0x20];
    LightSet light[4];
    char unkb0[0x100 - 0xb0];
} Stage;

extern Chr *D_004A1A20;
extern int D_004A1448, D_004A64A0, D_004A65B8, D_004A660C, D_004A6598, D_004A6908;
extern int D_004A670C, D_004A6710, D_004A6714;
extern int D_004A66E0, D_004A66E4, D_004A66E8, D_004A14AC;
extern s64 D_004A1300;
extern float D_004A65F4, D_004A0AA0, D_004A6644;
extern u32 D_004A5E50;
extern char D_00342D00[], D_00318B70[], D_0041F090[], D_00402930[], D_0040F178[];
extern float D_0041F138[];
extern int D_0040DB60[];
extern int D_005F8B48[8], D_005F8B68[8], D_005F8B88[8];
extern char D_005F8BA8[][8][64];
extern Slot D_0041C600[32];
extern int *D_0041B7EC[];
extern float D_0041C540[3], D_0041C550[3], D_0041C5A0[3], D_0041C5B0[3];
extern Vec4 D_0041EA50[20], D_0041EB90[20];
extern Light D_0041F1D0[4];

char *strcpy(char *, const char *);
float fabsf(float);
int FUN_00133848(void);
int FUN_00154c38(void *);
int FUN_00155510(void *);
int FUN_00155518(void *);
void FUN_0018eb78(void *, int);
void FUN_0018eb98(void *, int);
void FUN_0021b600(int);
void FUN_0022ecb0(int);
int FUN_002306e8(int, int, int, int);
char *FUN_00237a40(int, int, int, int, int, int, int, int, int);
void FUN_00248a58(void *);
void FUN_00248cf8(int, float);
void FUN_00295148(void *, int);
void FUN_00295de8(void *);
void FUN_002a8a38(void);
void FUN_002a8d30(void *);
void FUN_002a8228(Light *, int, int, float, float, float);
void FUN_002a8600(Light *, int, int, float, float);
void FUN_002a8358(Light *, int, int, float, float, float);
void func_002AAE58(void);
float FUN_002d5738(float, float);

// MATCH func_0026C6E8
void nori_0026c6e8(void)
{
    if (D_004A1448 != 0 && (D_004A1300 & 0x200)) {
        if (++D_004A64A0 >= 3)
            D_004A64A0 = 0;
    }
    FUN_00248a58((void *)0x70003c80);
    FUN_002a8a38();
    FUN_0018eb98((void *)0x70003c40, FUN_00155518(D_00342D00));
    FUN_0018eb98((void *)0x70003cc0, FUN_00155510(D_00342D00));
    FUN_0018eb78(D_00318B70, FUN_00154c38(D_00342D00));
    FUN_002a8d30(D_0041F138);
}

// MATCH func_0026C7A8
void nori_0026c7a8(void)
{
    FUN_00295148(D_0041F090, D_004A6908);
    FUN_00295de8(D_00402930);
    func_002AAE58();
}

/* adds a message to the first free one of 8 slots */
// MATCH func_0026C7D8
void nori_0026c7d8(char *text, int b, int c, int d)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (D_005F8B48[i] == 0) {
            strcpy(D_005F8BA8[D_004A65B8][i], text);
            D_005F8B48[i] = b;
            D_005F8B68[i] = c;
            D_005F8B88[i] = d;
            return;
        }
    }
}

/* frees the 8 message slots */
// MATCH func_0026CD48
void nori_0026cd48(void)
{
    D_005F8B48[0] = 0;
    D_005F8B48[1] = 0;
    D_005F8B48[2] = 0;
    D_005F8B48[3] = 0;
    D_005F8B48[4] = 0;
    D_005F8B48[5] = 0;
    D_005F8B48[6] = 0;
    D_005F8B48[7] = 0;
}

// MATCH func_0026DA40
void nori_0026da40(int a, int b)
{
    D_004A670C = a;
    D_004A6710 = b;
    D_004A6714 = 1;
}

/* shows text `D_004A660C` (1-49) of the table at 0x40db60 */
// MATCH func_00270838
void nori_00270838(void)
{
    if (D_004A660C != 0 && D_004A660C < 50)
        FUN_00237a40(0, 0, 160, 224, 160, 148, 160, 224, D_0040DB60[D_004A660C]);
}

// MATCH func_00270898
void nori_00270898(int n)
{
    if (n != 0 && n < 50)
        FUN_00237a40(0, 0, 160, 224, 160, 148, 160, 224, D_0040DB60[n]);
}

// MATCH func_00270920
void nori_00270920(void *p)
{
    int q = FIELD(int, p, 0xa8);
    FIELD(int, q, 0x10) = 0;
    FIELD(int, q, 0x14) = 0;
    FIELD(int, q, 0x18) = 0;
}

// MATCH func_00270938
void nori_00270938(void *p)
{
    int q = FIELD(int, p, 0xa8);
    FIELD(int, q, 0x10) = 0;
    FIELD(int, q, 0x18) = 0;
}

/* the entry with id `key` among the 8 in use, or the default at 0x40f178 */
// MATCH func_00270968
char *nori_00270968(void *p, u32 key)
{
    int e = FIELD(int, FIELD(int, p, 0xa8), 0x140);
    u8 *used = (u8 *)(e + 0x24);
    u16 **q = (u16 **)(e + 0x54);
    int i;
    for (i = 0; i < 8; i++, q++) {
        if (used[i] && **q == key)
            return (char *)*q + 52;
    }
    return D_0040F178;
}

// MATCH func_00270C88
void nori_00270c88(void)
{
    int p = FUN_00133848() + D_004A6598 * 0x100;
    float k = 1.0f - D_004A65F4;
    float x = FIELD(float, p, 0xb0) * k, y = FIELD(float, p, 0xb4) * k, z = FIELD(float, p, 0xb8) * k;
    D_0041F138[10] = z;
    D_0041F138[0] = x;
    D_0041F138[5] = y;
}

/* gives the 4 stage lights the settings of stage entry 3 (for 6 and 18)
   and of entry 2 (for 36) */
#define SET_LIGHT(l, n, s) \
    FUN_002a8228(l, n, 0, (s)->pos[0], (s)->pos[1], (s)->pos[2]); \
    FUN_002a8600(l, n, 0, (s)->dir[0], (s)->dir[1]); \
    FUN_002a8358(l, n, 0, (s)->color[0], (s)->color[1], (s)->color[2])

// MATCH func_00270CF0
void nori_00270cf0(void)
{
    Stage *t = (Stage *)FUN_00133848();
    Stage *s = &t[3];
    Light *l0 = &D_0041F1D0[0], *l1 = &D_0041F1D0[1], *l2 = &D_0041F1D0[2], *l3 = &D_0041F1D0[3];
    SET_LIGHT(l0, 6, &s->light[0]);
    SET_LIGHT(l1, 6, &s->light[1]);
    SET_LIGHT(l2, 6, &s->light[2]);
    SET_LIGHT(l3, 6, &s->light[3]);
    SET_LIGHT(l0, 18, &s->light[0]);
    SET_LIGHT(l1, 18, &s->light[1]);
    SET_LIGHT(l2, 18, &s->light[2]);
    SET_LIGHT(l3, 18, &s->light[3]);
    s = &t[2];
    SET_LIGHT(l0, 36, &s->light[0]);
    SET_LIGHT(l1, 36, &s->light[1]);
    SET_LIGHT(l2, 36, &s->light[2]);
    SET_LIGHT(l3, 36, &s->light[3]);
}

// MATCH func_00271A58
void nori_00271a58(void)
{
    int i;
    for (i = 0; i < 32; i++)
        D_0041C600[i].x = 0;
    if (D_004A66E0 != 0) {
        float *a = FIELD(float *, D_0041B7EC[0], 196);
        float *b = FIELD(float *, D_0041B7EC[0], 200);
        D_0041C5A0[0] = a[0] = D_0041C540[0];
        D_0041C5A0[1] = a[1] = D_0041C540[1];
        D_0041C5A0[2] = a[2] = D_0041C540[2];
        D_0041C5B0[0] = b[0] = D_0041C550[0];
        D_0041C5B0[1] = b[1] = D_0041C550[1];
        D_0041C5B0[2] = b[2] = D_0041C550[2];
    }
    D_004A66E4 = 0;
    D_004A66E8 = 0;
    D_004A66E0 = 0;
}

/* wraps *p into [0, D_004A0AA0) */
// MATCH func_00271B18
void nori_00271b18(float *p)
{
    float x = *p;
    float m = D_004A0AA0;
    float r = FUN_002d5738(fabsf(x), m);
    if (x < 0.0f)
        r = m - r;
    *p = r;
}

// MATCH func_00277578
void nori_00277578(int p, int i, int c, int d)
{
    int saved, o;
    FUN_002306e8(p, i, c, d);
    saved = D_004A14AC;
    o = FIELD(PosTable *, p, 0x90)->handle[i];
    FUN_0021b600(o);
    FIELD(u32, o, 24) = (FIELD(u32, o, 24) | 0x2000) & ~0x140;
    FIELD(u32, o, 24) |= FIELD(u32, p, 24) & 0x140;
    FIELD(u8, o, 209) = FIELD(u8, p, 209);
    FUN_00248cf8(0, FIELD(float, o, 64));
    FUN_00248cf8(1, FIELD(float, o, 68));
    FUN_00248cf8(2, FIELD(float, o, 72));
    FUN_0022ecb0(o);
    D_004A14AC = saved;
}

/* saves the position and rotation of the characters in play */
// MATCH func_00277638
void nori_00277638(void)
{
    int i;
    for (i = 0; i < 20; i++) {
        if (D_004A1A20[i].flags & 0x60000000) {
            D_0041EA50[i] = D_004A1A20[i].model->pos;
            D_0041EB90[i] = D_004A1A20[i].model->rot;
        }
    }
}

/* puts them back (see nori_00277638) */
// MATCH func_002776D0
void nori_002776d0(void)
{
    int i;
    for (i = 0; i < 20; i++) {
        if (D_004A1A20[i].flags & 0x60000000) {
            D_004A1A20[i].model->pos = D_0041EA50[i];
            D_004A1A20[i].model->rot = D_0041EB90[i];
        }
    }
    (D_0041EB90 + D_004A5E50)->y = D_004A6644;
}
