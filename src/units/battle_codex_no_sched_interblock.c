/* Functions of this report unit, matched by hand. */
// cflags: -fno-sched-interblock

typedef struct {
    float x, y, z;
} BattleRgb;

typedef struct {
    char pad00[8];
    short adjustment;
    short pad0a;
    BattleRgb *(*getColor)(void *);
} BattleModelVtable;

typedef struct {
    char pad00[52];
    BattleModelVtable *vtable;
} BattleModel;

typedef struct {
    unsigned char red, green, blue, alpha;
} BattleRgba;

extern BattleModel *D_0055AA20[];
extern char D_0041F1D0[], D_00318B70[];

extern void func_00116A90(char *, float, float, float);
extern BattleModel *func_002A7AA0(char *);
extern void func_00154940(BattleModel *, char *);
extern void func_00154930(BattleModel *, BattleRgb *);

// MATCH func_0011DE28
void battle_0011de28(float amount, BattleRgba color)
{
    float remaining, red, green, blue;
    int i;
    char *scratch;

    remaining = 1.0f - amount;
    red = remaining + color.red * 0.0078125f * amount;
    green = remaining + color.green * 0.0078125f * amount;
    blue = remaining + color.blue * 0.0078125f * amount;
    func_00116A90((char *)0x70003c40, red, green, blue);
    func_00116A90((char *)0x70003c50, red, green, blue);
    func_00116A90((char *)0x70003c60, red, green, blue);
    func_00116A90((char *)0x70003c70, red, green, blue);
    func_00116A90(D_00318B70, red, green, blue);

    scratch = (char *)0x70003c40;
    for (i = 0; i < 4; i++) {
        if ((D_0055AA20[i] = func_002A7AA0(D_0041F1D0 + i * 1968)) != 0) {
            BattleRgb *modelColor;
            func_00154940(D_0055AA20[i], scratch);
            modelColor = D_0055AA20[i]->vtable->getColor((char *)D_0055AA20[i] + D_0055AA20[i]->vtable->adjustment);
            modelColor->x *= red;
            modelColor->y *= green;
            modelColor->z *= blue;
            func_00154930(D_0055AA20[i], modelColor);
        }
        scratch += 16;
    }
}
