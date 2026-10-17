/* Functions after abeshi.cpp whose source file is not known (group
   _unknown_after_abeshi in decomp/functions.csv). Matched by hand. */
#include "common.h"

/* the party's shared state */
extern struct {
    int money;
    char unk4[0x88];
    int count;
} D_003FEBA8;
extern int D_004A3860, D_004A66C8, D_004A64A0, D_004A12A4, D_004A24E8, D_004A1448;
extern void *D_004A1360, *D_004A1364;
extern float D_004A11F8;
extern int D_0041AAD8[5];
extern char D_00343028[], D_004A64A8[];
extern int D_005F8918[5], D_005F8930[5], D_005F8948[5], D_005F8960[5];
extern int D_005F87D8[5][16];

typedef struct {
    char unk0[0x20];
    u16 id;
} Obj;
typedef struct {
    char unk0[0x140];
    Obj *obj[1];
} ObjTable;
typedef struct {
    char unk0[0xa8];
    ObjTable *objs;
} Model;
typedef struct {
    char unk0[0x12c0];
    Model *model;
    char unk12c4[0x1560 - 0x12c4];
} Chr;
extern Chr *D_004A1A20;

int FUN_0010a268(void *, int);
int FUN_0010ef68(void *, void *, int);
void FUN_00110490(void);
void FUN_001976b8(void);
void FUN_00261bd8(void);
void FUN_00264600(void);
void FUN_00291b60(void);
void init_0024a510(void);
void noriwin_00139490(void);
void yokota_0023efb8(void);

// MATCH func_00261B08
void FUN_00261b08(void)
{
    D_004A3860 = 1;
    D_004A66C8 = 14;
    D_004A64A0 = 0;
    init_0024a510();
    D_004A1360 = FUN_00110490;
    D_004A1364 = FUN_00264600;
    D_004A12A4 = 21;
    yokota_0023efb8();
    D_004A24E8 = 0;
    D_0041AAD8[0] = 0;
    D_0041AAD8[1] = 0;
    D_0041AAD8[2] = 0;
    D_0041AAD8[3] = 0;
    D_0041AAD8[4] = 0;
    noriwin_00139490();
    D_004A1448 = 1;
    FUN_001976b8();
    FUN_00291b60();
    FUN_00261bd8();
    D_004A11F8 = 0.75f;
    FUN_0010a268(D_00343028, 7);
    D_0041AAD8[1] = FUN_0010ef68(D_00343028, D_004A64A8, 0xe3c00);
}

// MATCH func_00264CF8
void FUN_00264cf8(void)
{
    int i, j;
    for (i = 0; i < 5; i++) {
        D_005F8918[i] = -1;
        D_005F8930[i] = -1;
        D_005F8948[i] = -1;
        D_005F8960[i] = -1;
        for (j = 15; j >= 0; j--)
            D_005F87D8[i][j] = 0;
    }
}
extern void *D_0040D228[];
extern void *D_0040D8B8[];

/* adds to the money, kept within 0 to 9,999,999 */
// MATCH func_00264E78
void FUN_00264e78(int amount)
{
    D_003FEBA8.money += amount;
    if (D_003FEBA8.money > 9999999)
        D_003FEBA8.money = 9999999;
    if (D_003FEBA8.money < 0)
        D_003FEBA8.money = 0;
}

/* counts up to INT_MAX and stays there */
// MATCH func_00264E40
void FUN_00264e40(void)
{
    if (D_003FEBA8.count != 0x7fffffff)
        D_003FEBA8.count++;
}

/* entry `i` (from 1) of the table at 0x40d228 */
// MATCH func_00269548
void *FUN_00269548(u32 i)
{
    return D_0040D228[i - 1];
}

/* entry `i` (from 1) of the table at 0x40d8b8 */
// MATCH func_00269568
void *FUN_00269568(u32 i)
{
    return D_0040D8B8[i - 1];
}

/* 1 when object `j` of character `i` has id 0x6306 */
// MATCH func_002695A8
int FUN_002695a8(int i, int j)
{
    return D_004A1A20[i].model->objs->obj[j]->id == 0x6306;
}

extern int D_004A23E0;
extern int D_0041AB60[], D_0041B360[], D_0041AF60[];
extern char D_00343010[];
int FUN_002207e8(int);
int akari_001e2a98(void *, int, int, int, float);
int akari_001e3890(void *, int, int);
int FUN_001e3e38(void *, int, int);
void akari_001e26a8(void *, int, int, int, float);

/* starts effect `id`: 190-253 are one kind, the others come from three tables */
// MATCH func_002619D8
int FUN_002619d8(float s, int id, int a, int b)
{
    int r = 0;
    if ((u32)(id - 190) < 64) {
        r = FUN_002207e8(id - 190);
    } else if (D_0041AB60[id] != 0) {
        r = akari_001e2a98(D_00343010, D_0041AB60[id], a, b, s);
    } else {
        int c = D_0041B360[id];
        if (c != 0 && !((u32)(id - 40) < 6 && D_004A23E0 != 0)) {
            r = akari_001e3890(D_00343010, c, D_0041AF60[id]);
            FUN_001e3e38(D_00343010, r, 0);
            akari_001e26a8(D_00343010, r, a, b, s);
        }
    }
    return r;
}
