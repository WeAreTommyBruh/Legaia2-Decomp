/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"
#include "battle_load.h"

extern int D_004A1A8C; extern char *D_004A1A20_00120B30 __asm__("D_004A1A20"); extern int D_00327820[]; extern int D_004A6D94;
void func_00122118(void);
// MATCH func_00120B30
void battle_00120b30(void) { int n = D_004A1A8C; int i; char *p = D_004A1A20_00120B30; for (i = 0; i < n; i++) { *(int *)(p + 4836 + i * 5472) = D_00327820[i] + 5; } D_004A6D94 = 0; func_00122118(); }

extern int D_004A1A20_1297C0 __asm__("D_004A1A20"), D_004A1AA8_1297C0 __asm__("D_004A1AA8"); extern int D_003279A0_1297C0[] __asm__("D_003279A0"); extern char D_00431628_1297C0[] __asm__("D_00431628"), D_00431638_1297C0[] __asm__("D_00431638");
void func_0021ECB0_1297C0(int, int, int) __asm__("func_0021ECB0"); void func_0021EBE8_1297C0(int, int, int, int) __asm__("func_0021EBE8"); void func_0021EE50_1297C0(int, int, int, int) __asm__("func_0021EE50"); volatile short func_001118F8_1297C0(char *, ...) __asm__("func_001118F8");
// MATCH func_001297C0
void battle_001297c0(int idx) { int o, p; o = idx * 5472; p = *(int *)(o + D_004A1A20_1297C0 + 5380); if (p != 0) { if (*(int *)(p + 44) != 0) func_0021ECB0_1297C0(D_004A1AA8_1297C0, *(int *)(p + 16), D_003279A0_1297C0[idx]); if (*(int *)(*(int *)(o + D_004A1A20_1297C0 + 5380) + 36) != 0) { func_001118F8_1297C0(D_00431628_1297C0, *(int *)(*(int *)(o + D_004A1A20_1297C0 + 5380) + 36)); func_0021EBE8_1297C0(D_004A1AA8_1297C0, *(int *)(*(int *)(o + D_004A1A20_1297C0 + 5380) + 36), o + D_004A1A20_1297C0, 0x179c00); } if (*(int *)(*(int *)(o + D_004A1A20_1297C0 + 5380) + 32) != 0) { func_001118F8_1297C0(D_00431628_1297C0, *(int *)(*(int *)(o + D_004A1A20_1297C0 + 5380) + 32)); func_0021EBE8_1297C0(D_004A1AA8_1297C0, *(int *)(*(int *)(o + D_004A1A20_1297C0 + 5380) + 32), o + D_004A1A20_1297C0, 0x1c4c00); } if (*(int *)(*(int *)(o + D_004A1A20_1297C0 + 5380) + 48) != 0) { func_001118F8_1297C0(D_00431638_1297C0, *(int *)(*(int *)(o + D_004A1A20_1297C0 + 5380) + 48)); func_0021EE50_1297C0(D_004A1AA8_1297C0, *(int *)(*(int *)(o + D_004A1A20_1297C0 + 5380) + 48), o + D_004A1A20_1297C0, 0); } } }

extern int D_004A1A20; extern int D_004A6E24; extern int D_003279A0[]; extern char D_004317F8[];
int DbgPrintf(char *fmt, ...);
// MATCH func_0012A958
void battle_0012a958(void) { int *pp; int i, off; int e; char *c; int *q; int fl; pp = D_003279A0; i = 0; off = 0; do { e = *pp; pp = pp + 1; if (e != 0) { c = (char *)(off + D_004A1A20); if (*(int *)(*(int *)(c + 0x1444) + 0x38) < 0) *(int *)(*(int *)(c + 0x1444) + 0x38) = 0; if ((*(unsigned *)(c + 0x12d0) & 0x800) == 0) { fl = D_004A6E24; q = *(int **)(c + 0x1550); q[0x16] = 0; q[0x13] = 0; q[0x14] = 0; q[1] = 0; q[0] = 0; if (fl != 0) DbgPrintf(D_004317F8, i); } } i = i + 1; off = off + 0x1560; } while (i < 0x14); }


typedef struct { char c[16]; } V_12B088;
typedef struct { V_12B088 v[3]; } V3_12B088;
typedef struct { V_12B088 a, b, c, d, e, f; int n, m; } O_12B088;
extern V_12B088 D_00327A40[]; extern char D_004318C8[], D_004318E0[], D_004318F0[], D_00431900[];
void func_00239568(char *, ...); void func_0018F138(V_12B088 *, V_12B088 *, V_12B088 *, float);
// MATCH func_0012B088
void battle_0012b088(O_12B088 *o) {
  float t; int n;
  if (o->n <= 0) { o->n = 0; return; }
  n = o->n - 1;
  o->n = n;
  if (n > 0) t = (float)(o->m - n) / (float)o->m;
  else { t = 0.0f; o->a = D_00327A40[0]; o->b = D_00327A40[1]; o->c = D_00327A40[2]; }
  func_00239568(D_004318C8, o->n, o->m, (double)t);
  func_00239568(D_004318E0, &o->d);
  func_00239568(D_004318F0, o);
  func_00239568(D_00431900, D_00327A40);
  func_0018F138(&D_00327A40[1], &o->b, &o->e, t);
  func_0018F138(&D_00327A40[2], &o->c, &o->f, t);
  func_0018F138(&D_00327A40[0], &o->a, &o->d, t);
}

typedef struct {
    char *name;
    char pad[108];
} BattleResourceRecord;

extern int D_00314D08[], D_00314CC8[];
extern BattleResourceRecord D_0040432C[], D_0040478C[];

// MATCH func_0012CB20
int battle_0012cb20(BattleLoadList *list, char *buffer)
{
    int i;
    char *names;

    list->buffer = buffer;
    list->current = 0;
    list->remaining = 0;
    list->totalSize = 0;
    for (i = 0; i < 3; i++) {
        int id = D_00314D08[i];

        if (id >= 0) {
            char *name = D_0040432C[id].name;
            int index = list->remaining;

            list->remaining = index + 1;
            list->entries[index].name = name;
        }
    }

    /* The name field is 12 bytes into the first entry. */
    names = (char *)list + 12;
    for (i = 0; i < 4; i++) {
        int id = D_00314CC8[i];

        if (id >= 0) {
            char *name = D_0040478C[id].name;
            int index = list->remaining;
            char **slot = (char **)(names + sizeof(BattleLoadEntry) * index);

            list->remaining = index + 1;
            *slot = name;
        }
    }
    return list->remaining;
}

typedef struct {
    char pad[16];
    const char *motion;
    char gap[12];
    const char *attackSound;
    const char *effectSound;
    int field40;
    int hasMotion;
    const char *effect;
} BattleAssetNames_1298E8;

extern int D_004A1A20, D_004A6CA4;
extern void *D_004A1AA8;
extern char D_00431628[], D_00431638[], D_00431648[], D_00431658[];
int func_001118F8(char *, ...);
void func_002DCE40(char *, const char *, ...);
void func_0012ABF0(int);
void func_0021F048(void *, const char *, int);

#define BATTLE_ASSET_NAMES() FIELD(BattleAssetNames_1298E8 *, offset + D_004A1A20, 5380)

// MATCH func_001298E8
void battle_001298e8(int actor)
{
    char path[256];
    int offset = actor * 5472;
    BattleAssetNames_1298E8 *names;

    if (BATTLE_ASSET_NAMES() != 0) {
        func_0012ABF0(3);
        D_004A6CA4 = actor;
        names = BATTLE_ASSET_NAMES();
        if (names->hasMotion) {
            func_001118F8(D_00431648, names->motion);
            func_0021F048(D_004A1AA8, BATTLE_ASSET_NAMES()->motion, 4);
        }
        if (BATTLE_ASSET_NAMES()->effect) {
            func_001118F8(D_00431638, BATTLE_ASSET_NAMES()->effect);
            func_0021F048(D_004A1AA8, BATTLE_ASSET_NAMES()->effect, 5);
        }
        if (BATTLE_ASSET_NAMES()->effectSound) {
            func_002DCE40(path, D_00431658, BATTLE_ASSET_NAMES()->effectSound);
            func_0021F048(D_004A1AA8, path, 6);
        }
        if (BATTLE_ASSET_NAMES()->attackSound) {
            func_001118F8(D_00431628, BATTLE_ASSET_NAMES()->attackSound);
            func_002DCE40(path, D_00431658, BATTLE_ASSET_NAMES()->attackSound);
            func_0021F048(D_004A1AA8, path, 7);
        }
    }
}

#undef BATTLE_ASSET_NAMES

int func_001269E0(int);

// MATCH func_001266F8
void battle_001266f8(void)
{
    int i = 0, offset = 0;
    int *slot = D_003279A0;

    do {
        int present = *slot++;
        int actor = i++;

        if (present) {
            int *entry = (int *)(offset + D_004A1A20);
            int *stats = (int *)entry[1297];
            int first, second;

            first = stats[14];
            entry[1304] = first;
            second = stats[15];
            entry[1306] = first;
            entry[1305] = second;
            entry[1307] = second;
            if (func_001269E0(actor))
                *(unsigned *)(offset + D_004A1A20 + 4816) |= 0x800;
        }
        offset += 5472;
    } while (i < 10);
}

extern int *D_003279A0_122DE0[] __asm__("D_003279A0");
extern char D_004308C8[], D_0042FDA0[];
void func_001621F8(int, char *, int);

// MATCH func_00122DE0
void battle_00122de0(int skip)
{
    int i;
    register int offset __asm__("$16") = 0;

    for (i = 0; i < 20; i++, offset += 5472) {
        if (skip != i) {
            char *entry = (char *)(offset + D_004A1A20);

            if (*(int *)(entry + 4956) != 0) {
                int value;
                int *actor;
                register int base __asm__("$3");

                func_001118F8(D_004308C8, i);
                base = D_004A1A20;
                base = offset + base;
                func_001621F8(*(int *)(base + 4956), D_0042FDA0, 6523);
                entry = (char *)(offset + D_004A1A20);
                value = *(int *)(entry + 4952);
                actor = D_003279A0_122DE0[i];
                *(int *)(entry + 4956) = 0;
                actor[38] = value;
            }
        }
    }
}

typedef struct {
    char pad[16];
    char *primaryMotion;
    char gap[12];
    char *attackA;
    char *attackB;
    int pad40;
    int hasMotion;
    char *effect;
    char *alternateMotion;
} BattleNames_129BE8;

extern int D_004A1AAC, D_004A1A20;
extern void *D_004A1AA8;
extern void *D_003279A0_129BE8[] __asm__("D_003279A0");
extern char D_004316D8[], D_00431718[], D_00431730[], D_00431628[], D_00431638[];
void func_001118F8_129BE8(char *, ...) __asm__("func_001118F8");
extern void func_0021ECB0(void *, char *, void *);
extern void func_0021EBE8(void *, char *, int, int);
extern void func_0021EE50(void *, char *, int, int);
#define SLOT() (offset + D_004A1A20)
#define NAMES() (*(BattleNames_129BE8 **)(SLOT() + 5380))
// MATCH func_00129BE8
void battle_00129be8(int selected)
{
    int actor, offset;
    D_004A1AAC = 2;
    func_001118F8_129BE8(D_004316D8);
    actor = 0;
    offset = 0;
    do {
        BattleNames_129BE8 *names = NAMES();
        char *name;
        if (names == 0)
            goto next;
        if (D_003279A0_129BE8[actor] == 0)
            goto next;
        if (names->hasMotion) {
            if ((name = names->alternateMotion) != 0) {
                func_001118F8_129BE8(D_00431718, name);
                func_0021ECB0(D_004A1AA8, NAMES()->alternateMotion, D_003279A0_129BE8[actor]);
            } else {
                func_001118F8_129BE8(D_00431730, names->primaryMotion);
                func_0021ECB0(D_004A1AA8, NAMES()->primaryMotion, D_003279A0_129BE8[actor]);
            }
        }
        if (actor != selected)
            goto next;
        if ((name = NAMES()->attackB) != 0) {
            func_001118F8_129BE8(D_00431628, name);
            func_0021EBE8(D_004A1AA8, NAMES()->attackB, SLOT(), 0x179c00);
        }
        if ((name = NAMES()->attackA) != 0) {
            func_001118F8_129BE8(D_00431628, name);
            func_0021EBE8(D_004A1AA8, NAMES()->attackA, SLOT(), 0x1c4c00);
        }
        if ((name = NAMES()->effect) != 0) {
            func_001118F8_129BE8(D_00431638, name);
            func_0021EE50(D_004A1AA8, NAMES()->effect, SLOT(), 0);
        }
next:
        offset += 5472;
    } while (++actor < 20);
}

#undef NAMES
#undef SLOT

typedef struct { char pad[32]; float position[3]; char gap[84]; float original[3]; } ScrollActor;
extern ScrollActor *D_003279A0_124258[] __asm__("D_003279A0");
extern int D_004A1A20;
extern int D_004A13D4,D_004A6E44,D_004A6C9C;
extern float D_004A6C60;
extern float D_0055AB80[];
extern char D_00430C88[], D_00430CA0[];
int func_00127F70(void),func_00129E78(void);
void func_001118F8_124258(char *, ...) __asm__("func_001118F8");
void func_0012A6E0(float),func_00127168(void),func_0024DD98(void),func_0011DBB0(int,float);
// MATCH func_00124258
void battle_00124258(void)
{
    if (D_004A13D4 == 14 || func_00127F70() || !func_00129E78()) return;
    if (D_004A6E44) func_0012A6E0(-D_004A6C60);
    func_00127168();
    if (!D_004A6C9C) {
        func_001118F8_124258(D_00430C88);
        func_0024DD98();
        return;
    }
    func_001118F8_124258(D_00430CA0, D_004A13D4);
    {
        int i;
        char *p = (char *)D_004A1A20;
        ScrollActor **slot = D_003279A0_124258;
        for (i = 0; i < 10; ++slot,++i,p+=5472) {
            ScrollActor *a = *slot;
            if (a) {
                a->position[0] += D_0055AB80[0];
                a->position[2] += D_0055AB80[2];
                a->original[0] += D_0055AB80[0];
                a->original[2] += D_0055AB80[2];
            }
            *(unsigned *)(p+4816) &= 0xfdffffffu;
        }
    }
    {
        float zero = 0.0f, one = 1.0f;

        D_0055AB80[0] = zero;
        D_0055AB80[1] = zero;
        D_0055AB80[2] = zero;
        D_0055AB80[3] = one;
        func_0011DBB0(0, one);
    }
}

typedef struct {
    char pad[56];
    int active;
} BattleMotion_AA18;
typedef struct {
    char pad[4816];
    unsigned flags;
    char gap[368];
    BattleMotion_AA18 *motion;
    char gap2[44];
    unsigned flags2;
    char gap3[64];
    char state;
} BattleActor_AA18;

extern int D_004A1A20, D_004A6D98, D_004A6C40, D_004A1AAC, D_004A6DB8, D_004A6CA4, D_004A6E88;
extern void *D_003279A0_12AA18[] __asm__("D_003279A0");
extern char D_00431828[], D_00431850[], D_00431888[];
extern int func_001118F8(char *, ...);
extern void func_0011D588(int, int);
extern int func_0012C808(int);
extern void func_001266F8(void);
extern void func_0012A958(void);
extern int func_0027C308(void);
extern void func_00126798(void);
extern void func_00127930(void);
#define SLOT() ((BattleActor_AA18 *)(offset + D_004A1A20))
// MATCH func_0012AA18
int battle_0012aa18(void)
{
    int current = D_004A6D98;
    int i, offset;
    unsigned motionFlag;
    if (D_004A6C40 != 0)
        return current;
    D_004A6C40 = 1;
    D_004A1AAC = 0;
    i = 0;
    motionFlag = 0x40000;
    offset = 0;
    do {
        register BattleActor_AA18 *actor __asm__("$2");
        if (D_003279A0_12AA18[i] == 0)
            goto advance;
        if (SLOT()->flags & motionFlag) {
            func_001118F8(D_00431828, i);
            func_0011D588(current, -1);
        }
        actor = SLOT();
        actor->state = 0;
        actor->flags &= ~0x40000U;
        if (D_003279A0_12AA18[i] != 0 && SLOT()->motion->active)
            SLOT()->state = 1;
        actor = SLOT();
        if (!(actor->flags & 0x20000000))
            goto advance;
        if (!(actor->flags2 & 0x200))
            goto advance;
        actor->state = 0;
        func_0012C808(i);
advance:
        offset += 5472;
    } while (++i < 20);
    func_001266F8();
    func_0012A958();
    current = func_0027C308();
    func_001118F8(D_00431850, current);
    func_00126798();
    if (D_004A6DB8 != 0) {
        if (current < 0) {
            D_004A6E88 = 0;
            func_00127930();
        }
    } else if (D_004A6CA4 != current)
        D_004A6E88 = 120;
    func_001118F8(D_00431888, current);
    return current;
}

#undef SLOT

extern int D_004A13D4,D_004A6E24,D_004A6C18,D_004A1A20;
extern char D_004A1920[],D_00430530[],D_00430540[];
void func_001118F8_11D3F0(char *, ...) __asm__("func_001118F8");
int func_00277788(void),func_00277F80(void);
#define ENTRY() (actor*5472+D_004A1A20)
#define FLAGS() (*(int *)(ENTRY()+4816))
// MATCH func_0011D3F0
int battle_0011d3f0(int actor, int motion)
{
    int result;
    unsigned mask, flags;
    if (D_004A13D4 == 14)
        return 0;
    if (D_004A6E24)
        func_00239568(D_004A1920,actor);
    if (D_004A6C18 == 1)
        return 0;
    mask = *(unsigned *)(*(int *)(ENTRY()+5456) + motion*156);
    result = 0;
    if ((mask & 0x40000041) == 0x40000041 || (mask & 0x40)) {
        int current = FLAGS();
        result = 1;
        if (!(current & 0x300)) FLAGS()
            = current | 0x100;
    }
    if (FLAGS() & 0x100) {
        result = 1;
        if (!func_00277788()) FLAGS() = (FLAGS() & -257)
            | 0x200;
    }
    flags = FLAGS();
    if (flags & 0x100)
        result = 1;
    if (flags & 0x200) {
        result = 1;
        if (D_004A6E24)
            func_00239568(D_00430530);
        if (func_00277F80())
            goto finish;
        if (D_004A6E24)
            func_001118F8_11D3F0(D_00430540);
        FLAGS() &= -513;
    }
finish:
    return result;
}

#undef FLAGS
#undef ENTRY

extern int D_004A6C78;
// MATCH func_00120588
void battle_00120588(int actor)
{
    int offset = actor * 5472;
    int base = D_004A1A20;
    int *entry = (int *)(offset + base);
    int count = entry[1226];
    if (count != 0) {
        signed char *p;
        int start;
        int id;
        register int *out __asm__("$4");
        int end = count + offset;
        start = base + 5151;
        id = D_004A6C78;
        p = (signed char *)(end + start);
        out = entry;
        do {
            int next = count - 1;
            if (*p != id)
                break;
            count = next;
            p--;
        } while (count > 0);
        out[1226] = count;
        {
            register int next __asm__("$2") = id - 1;
            D_004A6C78 = next;
        }
    }
}

extern int D_004A1A20;
extern int D_004A1AA8_125388 __asm__("D_004A1AA8");
extern int D_00321820[];
extern char D_00404318[], D_00404778[], D_00430D98[], D_00430DD8[];
extern int func_001118F8(char *, ...);
extern void func_0021EB20(int, char *, char *, int);

// MATCH func_00125388
void battle_00125388(int actor, char *arg)
{
    int offset, index;
    char *entry;
    char *name = arg;
    register int slotBase __asm__("$2");

    func_001118F8(D_00430D98);
    offset = actor * 5472;
    slotBase = D_004A1A20;
    entry = (char *)(offset + slotBase);
    index = *(int *)(entry + 4964);
    if (*(unsigned *)(entry + 4816) & 0x40000000u)
        func_0021EB20(D_004A1AA8_125388, name, D_00404318 + index * 112,
                      D_00321820[*(int *)(entry + 4948)]);


    offset += D_004A1A20;
    if (*(unsigned *)(offset + 4816) & 0x20000000u) {
        char *base = D_00404778;
        char *data;
        int type;
        base -= 11200;
        data = base + index * 112;
        type = *(int *)(offset + 4964);
        index = *(int *)(offset + 4948) + 3;
        if (type == 165 || type == 214 || type == 340)
            index = 6;
        func_0021EB20(D_004A1AA8_125388, name, data, D_00321820[index]);
        func_001118F8(D_00430DD8, name, index);
    }
}

typedef struct {
    char *name;
    char pad[108];
} BattleNameRecord_128058;

extern int D_004A6DF0, D_004A6DF4, D_004A1A20;
extern int D_00314CC8[];
extern BattleNameRecord_128058 D_004047A0[];
extern char *D_0055B320[];
extern int D_00324490[];
extern int func_002DD36C(const char *, const char *);
extern int func_001118F8(char *, ...);
extern int func_0023C728(void *, int);

// MATCH func_00128058
void battle_00128058(int input, int unused, char *name)
{
    register int actor __asm__("$23") = input;
    int count, matches;
    int fmtBase;
    int i;
    if (actor < 4)
        return;
    count = 0;
    matches = 0;
    if (D_004A6DF0 >= 0) {
        matches = 1;
        i = 0;
        fmtBase = 0x430000;

        for (; i < 4; i++) {
            int id = D_00314CC8[i];
            if (id >= 0 && func_002DD36C(name, D_004047A0[id].name) == 0) {
                if (D_004A6DF0 != i)
                    matches++;
            }
        }
        if (matches >= 2) {
            for (i = 0; i < D_004A6DF0 + 1; i++) {
                int id = D_00314CC8[i];
                if (id >= 0) {
                    int same = func_002DD36C(name, D_004047A0[id].name);
                    if (same == 0)
                        count++;
                }
            }
        }
    } else {
        i = 0;
        fmtBase = 0x430000;
        if (D_004A6DF4 > 0) do {
            int same = func_002DD36C(D_0055B320[i], name);
            if (same == 0)
                count++;
        } while (++i < D_004A6DF4);
        if (count)
            count++;
        __asm__ ("" : "+r"(fmtBase));
    }
    /* The format at D_00431398 uses separate high and low address loads. */
    func_001118F8((char *)(fmtBase + 0x1398), count, matches);
    if (count) {
        register int offset __asm__("$6") = actor * 5472;

        func_0023C728((void *)(D_004A1A20 + offset + 4872), D_00324490[count - 1]);
    }
}

typedef struct { char p0[4816]; unsigned int fl; char p1[164]; int w4984; char p2[484]; } E5472_00129E80;
typedef struct { char p[192]; int w192; } Q_00129E80;
extern E5472_00129E80 *D_004A1A20_129E80 __asm__("D_004A1A20"); extern Q_00129E80 *D_003279A0_129E80[] __asm__("D_003279A0"); extern int D_004A6CF8_129E80 __asm__("D_004A6CF8"), D_004A6C54_129E80 __asm__("D_004A6C54"), D_004A6C58_129E80 __asm__("D_004A6C58"); extern float D_0049FE40_129E80 __asm__("D_0049FE40"), D_0049FE44_129E80 __asm__("D_0049FE44"), D_0049FE48_129E80 __asm__("D_0049FE48");
extern char D_00431768_129E80[] __asm__("D_00431768"), D_00431778_129E80[] __asm__("D_00431778"), D_00431790_129E80[] __asm__("D_00431790");
int func_001118F8_129E80(char *, ...) __asm__("func_001118F8"); void func_00127890_129E80(int) __asm__("func_00127890"); int func_00264E40_129E80(void) __asm__("func_00264E40"); void func_0021A280_129E80(int, int, int, int) __asm__("func_0021A280"); void func_001252A0_129E80(int) __asm__("func_001252A0");
void func_00237938_129E80(int, int, int, int, int, int, int, int, int, char *) __asm__("func_00237938"); void func_0011BC88_129E80(float, float, float, float, float, float, float, int) __asm__("func_0011BC88"); void func_00124A48_129E80(float, float, float, float, int) __asm__("func_00124A48"); void func_0012AEA8_129E80(int) __asm__("func_0012AEA8");
// MATCH func_00129E80
int battle_00129e80(int p) { int i; if (D_004A1A20_129E80[p].fl & 0x40000000) { if (D_004A6CF8_129E80 & 4) { if (D_004A6CF8_129E80 & 0x10) return 1; D_004A6C54_129E80 = 0; func_001118F8_129E80(D_00431768_129E80); D_004A6CF8_129E80 |= 0x10; func_00127890_129E80(0); func_00264E40_129E80(); for (i = 0; i < 20; i++) { if (D_004A1A20_129E80[i].fl & 0x40000000) { D_004A1A20_129E80[i].w4984 = 0; D_003279A0_129E80[i]->w192 &= 4; func_0021A280_129E80(p, 1, 1, 0); func_0021A280_129E80(p, 2, 1, 0x40000009); } } return 1; } if (D_004A6CF8_129E80 & 8) { if (D_004A6C54_129E80 == 119) func_00237938_129E80(0, 0, 120, 255, 255, 160, 112, 0, 0, D_00431778_129E80); if (D_004A6CF8_129E80 & 0x10) return 2; D_004A6C54_129E80 = 120; D_004A6C58_129E80 = 1; func_001118F8_129E80(D_00431790_129E80); D_004A6CF8_129E80 |= 0x10; func_0011BC88_129E80(0.0f, D_0049FE44_129E80, D_0049FE48_129E80, 0.0f, 0.0f, D_0049FE40_129E80, -76800.0f, 10289); func_00124A48_129E80(0.0f, 0.0f, 0.0f, 0.0f, 10290); func_0012AEA8_129E80(12); for (i = 0; i < 20; i++) if (D_004A1A20_129E80[i].fl & 0x40000000) D_004A1A20_129E80[i].fl |= 2; for (i = 0; i < 20; i++) { if (D_004A1A20_129E80[i].fl & 0x40000000) { D_004A1A20_129E80[i].w4984 = 0; func_0021A280_129E80(p, 1, 0, 0x40000000); func_0021A280_129E80(p, 2, 0, 0x40000001); func_001252A0_129E80(p); D_003279A0_129E80[i]->w192 &= 4; } } return 2; } } return 0; }

typedef struct { char pad00[0x12cc]; int sel; char pad12d0[0x290]; } Slot_001219E8;
typedef struct { char data[128]; } Cmd_001219E8;
extern int D_004A6DA4_1219E8 __asm__("D_004A6DA4"), D_004A6D94_1219E8 __asm__("D_004A6D94"), D_004A6D9C_1219E8 __asm__("D_004A6D9C"), D_004A1A4C_1219E8 __asm__("D_004A1A4C"), D_004A1A2C_1219E8 __asm__("D_004A1A2C"), D_004A1A84_1219E8 __asm__("D_004A1A84"), D_004A1A8C_1219E8 __asm__("D_004A1A8C"), D_004A1A60_1219E8 __asm__("D_004A1A60"), D_004A6D80_1219E8 __asm__("D_004A6D80"), D_004A6D84_1219E8 __asm__("D_004A6D84");
extern unsigned int D_004A6E74_1219E8 __asm__("D_004A6E74");
extern Slot_001219E8 *D_004A1A20_1219E8 __asm__("D_004A1A20"); extern float D_0049FDA0_1219E8 __asm__("D_0049FDA0"); extern Cmd_001219E8 D_00327DA0_1219E8[] __asm__("D_00327DA0");
void func_00232028_1219E8(float, Cmd_001219E8 *) __asm__("func_00232028"); void func_001100B8_1219E8(void) __asm__("func_001100B8"); void func_001297A0_1219E8(int, int, int, int, int, int) __asm__("func_001297A0"); void func_0021A8F8_1219E8(Slot_001219E8 *) __asm__("func_0021A8F8");
void func_0012AEA8_1219E8(int) __asm__("func_0012AEA8"); void func_0012C800_1219E8(int) __asm__("func_0012C800"); void func_0012C1D8_1219E8(int, int) __asm__("func_0012C1D8"); void func_0011B910_1219E8(int, int, int, int) __asm__("func_0011B910"); void func_00122118_1219E8(void) __asm__("func_00122118");
void func_00235130_1219E8(int, int) __asm__("func_00235130"); int func_00121918_1219E8(int) __asm__("func_00121918"); void func_00121980_1219E8(int, int) __asm__("func_00121980");
// MATCH func_001219E8
void battle_001219e8(void) { int old = D_004A6DA4_1219E8; int slot; int dir; D_004A1A4C_1219E8 = 0; dir = 0; D_004A6D9C_1219E8 = old + 4; slot = D_004A6D94_1219E8; if (D_004A6E74_1219E8 & 0x82000) { D_004A6DA4_1219E8++; dir = 1; D_004A1A2C_1219E8 = 10; func_001100B8_1219E8(); D_004A6E74_1219E8 = 0; } if (D_004A6E74_1219E8 & 0x48000) { D_004A1A2C_1219E8 = 10; dir = -1; D_004A6DA4_1219E8--; func_001100B8_1219E8(); D_004A6E74_1219E8 = 0; } if (D_004A6E74_1219E8 & 0x24000) { dir = 1; if (D_004A6DA4_1219E8 < 3) { D_004A6DA4_1219E8 += 3; if (func_00121918_1219E8(D_004A6DA4_1219E8) == 0) D_004A6DA4_1219E8 = 3; } if (D_004A6DA4_1219E8 > D_004A1A84_1219E8 - 1) D_004A6DA4_1219E8 = D_004A1A84_1219E8 - 1; D_004A6E74_1219E8 = 0; func_001100B8_1219E8(); } if (D_004A6E74_1219E8 & 0x11000) { dir = -1; if (D_004A6DA4_1219E8 >= 3) { D_004A6DA4_1219E8 -= 3; if (func_00121918_1219E8(D_004A6DA4_1219E8) == 0) D_004A6DA4_1219E8 = 2; } if (D_004A6DA4_1219E8 < 0) D_004A6DA4_1219E8 = 0; D_004A6E74_1219E8 = 0; func_001100B8_1219E8(); } if (dir != 0) { if (old != D_004A6DA4_1219E8) func_001297A0_1219E8(0, 2, 0, 0, 0, 0); func_00232028_1219E8(D_0049FDA0_1219E8, &D_00327DA0_1219E8[old + 4]); func_00121980_1219E8(slot, dir); } old = D_004A6DA4_1219E8; func_0012C800_1219E8(old + 4); func_0011B910_1219E8(116, 1, 0, old + 4); if (D_004A6E74_1219E8 & 0x200040) { D_004A1A2C_1219E8 = 0; func_001297A0_1219E8(0, 2, 0, 1, 0, 0); D_004A1A20_1219E8[slot].sel = D_004A6DA4_1219E8 + 4; func_0012AEA8_1219E8(3); { int next; register int count __asm__("$2"); next = D_004A6D94_1219E8 + 1; count = D_004A1A8C_1219E8; D_004A6D94_1219E8 = next; if (next >= count) func_00122118_1219E8(); } func_00235130_1219E8(-1, D_004A1A60_1219E8); } D_004A6D80_1219E8 = -1; if (D_004A6E74_1219E8 & 0x100010) { D_004A1A2C_1219E8 = 0; func_0012AEA8_1219E8(D_004A6D84_1219E8); func_00235130_1219E8(-1, D_004A1A60_1219E8); func_0021A8F8_1219E8(&D_004A1A20_1219E8[slot]); } func_0012C1D8_1219E8(old + 4, 0); }

typedef struct { unsigned int fl; char p[152]; } M_00122800;
typedef struct { char p0[4816]; unsigned int fl; char p1[16]; int f4836; char p2[136]; int f4976; char p3[4]; int mc; char p4[317]; char b5305; char p5[42]; int f5348; char p6[64]; int f5416; char p7[36]; M_00122800 *mot; char pa[12]; } E5472_00122800;
typedef struct { char p[209]; unsigned char b209; } Q_00122800;
typedef struct { char p[8]; short adj; char q[2]; void (*fn)(void *, int); } VT_00122800;
typedef struct { char p0[1096]; int w1096; char p1[92]; int w1192; char p2[920]; VT_00122800 *vt; } A3C_00122800;
typedef struct { char p[332]; int w332; } A94_00122800;
typedef struct { int w0; } S880_00122800;
extern E5472_00122800 *D_004A1A20_122800 __asm__("D_004A1A20"); extern Q_00122800 *D_003279A0_122800[] __asm__("D_003279A0"); extern A3C_00122800 *D_004A1A3C_122800 __asm__("D_004A1A3C"); extern A94_00122800 *D_004A1A94_122800 __asm__("D_004A1A94"); extern S880_00122800 D_00327880_122800[] __asm__("D_00327880");
extern int D_004A6E24_122800 __asm__("D_004A6E24"), D_004A6DC8_122800 __asm__("D_004A6DC8"), D_004A6DCC_122800 __asm__("D_004A6DCC"), D_004A1AA0_122800 __asm__("D_004A1AA0"), D_004A1A60_122800 __asm__("D_004A1A60"), D_004A6E50_122800 __asm__("D_004A6E50"), D_004A6E68_122800 __asm__("D_004A6E68"), D_004A6D94_122800 __asm__("D_004A6D94"), D_004A6D9C_122800 __asm__("D_004A6D9C"), D_004A6DD4_122800 __asm__("D_004A6DD4"), D_004A6D98_122800 __asm__("D_004A6D98");
extern int D_004A6C18_122800 __asm__("D_004A6C18"), D_004A6E28_122800 __asm__("D_004A6E28"), D_004A6CAC_122800 __asm__("D_004A6CAC"), D_004A6C98_122800 __asm__("D_004A6C98"), D_004A6D60_122800 __asm__("D_004A6D60"), D_004A6E90_122800 __asm__("D_004A6E90"), D_004A6CB0_122800 __asm__("D_004A6CB0"), D_004A6C30_122800 __asm__("D_004A6C30"), D_004A1A34_122800 __asm__("D_004A1A34"), D_004A1A54_122800 __asm__("D_004A1A54"), D_004A6DB4_122800 __asm__("D_004A6DB4"), D_004A6DB8_122800 __asm__("D_004A6DB8");
extern int D_004A1A8C_122800 __asm__("D_004A1A8C"), D_004A6CF8_122800 __asm__("D_004A6CF8"), D_004A6E60_122800 __asm__("D_004A6E60"), D_004A6E64_122800 __asm__("D_004A6E64"), D_004A6CA0_122800 __asm__("D_004A6CA0"), D_004A1AAC_122800 __asm__("D_004A1AAC"), D_004A6C3C_122800 __asm__("D_004A6C3C"), D_004A6E30_122800 __asm__("D_004A6E30"), D_004A6C14_122800 __asm__("D_004A6C14"), D_004A6E54_122800 __asm__("D_004A6E54"), D_004A6C50_122800 __asm__("D_004A6C50"), D_004A6DFC_122800 __asm__("D_004A6DFC"), D_004A6C20_122800 __asm__("D_004A6C20");
extern int D_004A6E88_122800 __asm__("D_004A6E88"), D_004A6C34_122800 __asm__("D_004A6C34"), D_004A1460_122800 __asm__("D_004A1460");
extern char D_00430828_122800[] __asm__("D_00430828"), D_00430838_122800[] __asm__("D_00430838"), D_00430850_122800[] __asm__("D_00430850"), D_00430868_122800[] __asm__("D_00430868"), D_00430878_122800[] __asm__("D_00430878"), D_00430888_122800[] __asm__("D_00430888"), D_004308A0_122800[] __asm__("D_004308A0");
void func_00239568_122800(char *, ...) __asm__("func_00239568"); int func_001118F8_122800(char *, ...) __asm__("func_001118F8"); void func_00235130_122800(int, int) __asm__("func_00235130"); int func_0012ACB0_122800(int) __asm__("func_0012ACB0"); int func_00127430_122800(void) __asm__("func_00127430");
void func_002268D0_122800(A3C_00122800 *) __asm__("func_002268D0"); int func_0012AA18_122800(void) __asm__("func_0012AA18"); int func_0012A860_122800(int) __asm__("func_0012A860"); void func_00126360_122800(void) __asm__("func_00126360"); void func_0012A948_122800(void) __asm__("func_0012A948"); void func_001296B0_122800(void) __asm__("func_001296B0");
int func_0012AEA8_122800(int) __asm__("func_0012AEA8"); void func_00124A48_122800(float, float, float, float, int) __asm__("func_00124A48"); void func_0011E0B0_122800(int, float, float) __asm__("func_0011E0B0"); int func_00127930_122800(void) __asm__("func_00127930");
void func_0012CE40_122800(void) __asm__("func_0012CE40"); void func_00122DE0_122800(int) __asm__("func_00122DE0"); void func_00124258_122800(int) __asm__("func_00124258"); void func_0011DBB0_122800(int, float) __asm__("func_0011DBB0"); int func_00127F70_122800(void) __asm__("func_00127F70"); void func_00128E70_122800(int) __asm__("func_00128E70");
void func_00129BE8_122800(int) __asm__("func_00129BE8"); void func_001234C8_122800(int) __asm__("func_001234C8"); int func_00127210_122800(void) __asm__("func_00127210"); void func_0012AC10_122800(void) __asm__("func_0012AC10");
// MATCH func_00122800
void battle_00122800(void) { int r = D_004A6D94_122800; int b = 0, c = 0, ok, i; int ok2; if (D_004A6E24_122800 != 0) func_00239568_122800(D_00430828_122800, D_004A6DC8_122800, D_004A6DCC_122800); if (--D_004A1AA0_122800 < 0) D_004A1AA0_122800 = 0; if (D_004A6DC8_122800 > 0) { r = 1; goto dbg; } D_004A6E50_122800 = 0; func_00235130_122800(-1, D_004A1A60_122800); if (D_004A6E68_122800 == -1) { D_004A6E68_122800 = -2; if (!(D_004A1A20_122800[D_004A6D94_122800].fl & 0x40000000)) D_004A6E68_122800 = D_004A1A20_122800[D_004A6D94_122800].f4836; func_001118F8_122800(D_00430838_122800, D_004A6E68_122800); D_004A1A20_122800[D_004A6D9C_122800].b5305 = 0; D_004A1A20_122800[D_004A6D94_122800].b5305 = 0; } b = func_0012ACB0_122800(1); if (func_00127430_122800() != 0) { if (D_004A1A3C_122800->w1192 != 0) { D_004A1A3C_122800->w1192--; r = 2; goto dbg; } ok = 1; { int mc = D_004A1A20_122800[D_004A6D94_122800].mc; if (D_004A1A3C_122800->w1096 != 0) { unsigned int f = D_004A1A20_122800[D_004A6D94_122800].mot[mc].fl; D_003279A0_122800[D_004A6D94_122800]->b209 = 128; if ((f ^ 1) & 1) ok = 0; D_004A1A20_122800[D_004A6D94_122800].f5348 = 128; } } if (ok) { func_002268D0_122800(D_004A1A3C_122800); if (D_004A1A3C_122800 != 0) D_004A1A3C_122800->vt->fn((char *)D_004A1A3C_122800 + D_004A1A3C_122800->vt->adj, 3); D_004A1A3C_122800 = 0; } else { r = 7; goto dbg; } } if (D_004A6DD4_122800 != 0) { r = 3; goto check; } if (b != 0) { r = 4; goto check; } D_004A6D98_122800 = func_0012AA18_122800(); c = func_0012A860_122800(D_004A6D98_122800); if (c != 0) { r = 5; goto check; } if (D_004A1AA0_122800 > 0) { r = 6; goto check; } func_00126360_122800(); D_004A6D94_122800 = D_004A6D98_122800; func_0012A948_122800(); if (D_004A6C18_122800 == 1) D_004A6E28_122800 = 10; D_004A6C18_122800 = 0; D_004A1A20_122800[r].f5416 = -1; D_004A6C98_122800 = 0; D_004A6D60_122800 = 0; D_004A6E90_122800 = 0; if (D_004A6CAC_122800 == 0) D_004A6CB0_122800 = 30; func_001118F8_122800(D_00430850_122800, D_004A6D94_122800); func_001296B0_122800(); D_004A6C30_122800 = 0; if (D_004A6D94_122800 < 0) { D_004A6D94_122800 = 0; D_00327880_122800[0].w0 &= ~2; D_004A6D9C_122800 = 0; D_004A1A34_122800 = 0; for (i = 0; i < 20; i++) D_004A1A20_122800[i].fl &= ~0x20000; func_0012AEA8_122800(2); if (D_004A1A54_122800 != 0) { func_0012AEA8_122800(15); } else { func_00124A48_122800(0.0f, 0.0f, 0.0f, 0.0f, 6405); func_0011E0B0_122800(300, 0.0f, 0.0f); } D_004A6DB8_122800 = 0; if (++D_004A6DB4_122800 >= 1000) D_004A6DB4_122800 = 999; D_004A6CF8_122800 = 0; for (i = 0; i < D_004A1A8C_122800; i++) D_004A1A20_122800[i].f4976 = -1; D_004A6E60_122800 = 0; if (func_00127930_122800() >= 0) { func_0012CE40_122800(); func_00122DE0_122800(-1); func_00124258_122800(0); func_0011DBB0_122800(0, 1.0f); } else if (D_004A6E68_122800 == 30) { func_001118F8_122800(D_00430868_122800); D_004A6E64_122800 = 0; D_004A6E60_122800 = 1; func_00124258_122800(0); D_004A6CA0_122800 = 0; func_0011DBB0_122800(0, 1.0f); func_0011E0B0_122800(300, 0.0f, 0.0f); func_00124A48_122800(0.0f, 0.0f, 0.0f, 0.0f, 6438); } if (D_004A1AAC_122800 == 0 && func_00127F70_122800() != 0) func_00128E70_122800(3); if (D_004A1AAC_122800 != 0) func_00129BE8_122800(D_004A6C3C_122800); func_001118F8_122800(D_00430878_122800); } else { func_00122DE0_122800(-1); func_00124258_122800(0); D_004A6CA0_122800 = 0; func_0011DBB0_122800(0, 1.0f); if (D_004A1AAC_122800 == 0 && func_00127F70_122800() != 0) func_00128E70_122800(3); if (D_004A1AAC_122800 != 0) func_00129BE8_122800(D_004A6C3C_122800); func_001234C8_122800(D_004A6D94_122800); } if (D_004A6E30_122800 != 0) { D_004A1A94_122800->w332 = 0; D_004A6E30_122800 = 0; } D_004A6C14_122800 = 0; D_004A6E54_122800 = 0; D_004A6C50_122800 = 0; D_004A6DFC_122800 = 0; D_004A6C20_122800 = 0; return; check: if (D_004A6E24_122800 != 0) func_00239568_122800(D_00430888_122800, D_004A6E88_122800); ok2 = 1; if (func_00127210_122800() != 0 && D_004A6D98_122800 < 0) ok2 = 0; if (D_004A1AAC_122800 != 0) ok2 = 0; if (D_004A6E88_122800 == 0) ok2 = 0; if ((unsigned)(D_004A6C34_122800 + 3) <= 1) ok2 = 0; if (func_00127F70_122800() != 0) ok2 = 0; if (!ok2) goto dbg; func_0012AC10_122800(); dbg: if (D_004A1460_122800 != 0) func_00239568_122800(D_004308A0_122800, r, b, c); }

