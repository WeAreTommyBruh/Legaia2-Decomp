// compiler: 990721-r5900
#include "../common.h"

typedef struct { char p0[32]; float f32, f36, f40; char p1[20]; float f64; int w68; float f72; char p2[48]; int w124; float f128; char p3[4]; float f136; char p4[32]; short h172, h174; char p5[16]; unsigned w192; int pad196; float f200; char p6[5]; unsigned char b209; char p7[2]; unsigned w212; } BattleActorModel;
typedef struct { char p0[4816]; int fl; char p1[368]; int w5188; char p1b[8]; int w5200; char p2[32]; int w5236; char p3[4]; short h5244, h5246; float f5248, f5252; char p4[96]; float f5352; char p5[116]; } BattleActorEntry;
typedef struct { float f0, f4, f8, f12; int w16, w20; int pad[2]; } BattleActorCue;
typedef struct { char p[1240]; int w1240; } BattleRenderContext;
typedef struct { char p[1188]; int w1188; } BattleRenderState;
extern char *D_004A1A20;
extern BattleActorModel *D_003279A0[];
extern BattleActorCue D_003293C0[];
extern int D_004A6E04, D_004A6D94, D_004A13D4, D_004A6E28, D_004A6C18, D_004A1AAC, D_004A1664, D_004A6D28, D_004A6C08, D_004A6C0C, D_004A13C8, D_004A14C8;
extern volatile float D_0049FDEC;
extern float D_0049FDF0, D_0049FDF4, D_0049FDF8, D_0049FDFC, D_0049FE00, D_0049FE04, D_004A1680;
extern BattleRenderContext *D_004A1A3C;
extern char D_00430D28[];
extern short D_003D1220[];
extern signed char D_00324460[];
extern char D_00343010[];
extern void func_00239568(char *, ...);
extern int battle_00127fc8(int), battle_00127430(void), func_001241F0(int), func_00127450(void), func_001227B8(void), func_00128030(void), func_00220820(float, int, int, BattleActorCue *, int);
extern void func_00179EF8(void), func_00249108(void), func_00249100(float, float, float), func_00248E00(float, float, float), func_0024CD68(int, int, float), func_002468F0(BattleActorModel *), func_0018F3D8(void *, int, int), func_0022D470(void *, void *, int), func_002489F0(void), func_0022D550(BattleActorModel *), func_002491D8(void), func_0022FDA0(int), func_00246550(BattleActorModel *), func_002464A8(BattleActorModel *), func_0022F268(BattleActorModel *), func_00179EE8(void), func_001E42A0(char *, int, BattleActorCue *), func_001E4308(char *, int, int);
extern float func_0015FB58(int, float), func_0021AF68(char *);
extern void func_0021AF40(char *);
extern int func_002441F0(void *, float, float, float, float, float, float);

#define BATTLE_ENTRY(o) ((BattleActorEntry *)((o) + (int)D_004A1A20))
// MATCH func_00124B68
void battle_00124b68(BattleActorModel *actorModel)
{
    int loopOffset;
    void *destination;
    float *boundsPtr;
    int hasSpecialMotion;
    int id, renderMode, allowCue, allowMotion, motionFlags, j, k, h, off;
    register int activeMotions __asm__("$9");
    register int cueOffset __asm__("$16");
    float f20, f21, f22, one, t0;
    float matrix[16];
    float bounds;
    BattleActorModel *actor;
    BattleActorEntry *entry;
    int color;
    unsigned short motion;
    register BattleActorCue *cue __asm__("$16");
    id = actorModel->h174;
    if (D_004A6E04 != 0) func_00239568(D_00430D28, id, actorModel->b209, (char *)actorModel + 128);
    if (battle_00127fc8(id) != 0) actorModel->w68 = 0;
    if (battle_00127430() != 0) {
        actorModel->b209 = *(unsigned char *)(D_004A1A20 + id * 5472 + 5348);
        if (D_004A1A3C->w1240 != 0 && ((BattleRenderState *)D_004A1A3C->w1240)->w1188 != 0 && D_004A6D94 == id) {
            actorModel->b209 = 128;
            BATTLE_ENTRY(id * 5472)->fl &= -17;
        }
    }
    if (D_004A13D4 == 14 && D_004A6D94 == id) {
        actorModel->b209 = 128;
        BATTLE_ENTRY(id * 5472)->fl &= -17;
    }
    func_00179EF8();
    func_00249108();
    if (battle_00127fc8(id) != 0 && func_001241F0(id) != 0) {
        if (func_00127450() == 0) actorModel->w68 = 0;
        else *(float *)&actorModel->w68 = D_0049FDEC;
    }
    func_00249100(actorModel->f32, actorModel->f36, actorModel->f40);
    one = 1.0f;
    func_00248E00(actorModel->f64, *(float *)&actorModel->w68, actorModel->f72);
    battle_00127430();
    off = id * 5472;
    BATTLE_ENTRY(off)->f5252 = BATTLE_ENTRY(off)->f5252 + D_0049FDF0;
    if (one < BATTLE_ENTRY(off)->f5252) *(int *)&BATTLE_ENTRY(off)->f5252 = 0;
    { float amplitude; char *base; float delta; BattleActorEntry *slot;
      amplitude = D_004A1680;
      base = D_004A1A20;
      delta = D_0049FDF4;
      __asm__("" : : "r"(base), "f"(delta));
      slot = (BattleActorEntry *)(off + (int)base);
      slot->f5248 += amplitude * delta; }
    if (one < BATTLE_ENTRY(off)->f5248) *(int *)&BATTLE_ENTRY(off)->f5248 = 0;
    motionFlags = 0; allowCue = 1; allowMotion = 1;
    cueOffset = id * 32;

    t0 = func_0015FB58(0, BATTLE_ENTRY(off)->f5248 * D_0049FDF8) + one;
    func_0024CD68(BATTLE_ENTRY(off)->h5244, BATTLE_ENTRY(off)->h5246, t0 * 0.5f);
    cue = (BattleActorCue *)((char *)D_003293C0 + cueOffset);
    actor = D_003279A0[id];
    cue->f0 = actor->f128;
    cue->f4 = actor->f36 - BATTLE_ENTRY(off)->f5352;
    { register float z __asm__("$f1");
      z = actor->f136;
      __asm__("" : "+f"(z));
      t0 = z; }
    cue->f12 = one;
    cue->f8 = t0;
    if (func_001227B8() != 0) { allowCue = 0; allowMotion = 0; }
    D_004A6E28 = D_004A6E28 - 1;
    if (D_004A6C18 == 1) allowCue = 0;
    if (D_004A6E28 > 0) allowCue = 0;
    else D_004A6E28 = 0;
    if (func_00128030() == 0) { allowCue = 0; allowMotion = 0; }
    if (actorModel->b209 < 32) { allowCue = 0; allowMotion = 0; }
    if (*(int *)(*(int *)(D_004A1A20 + id * 5472 + 5188) + 56) == 0) { allowCue = 0; allowMotion = 0; }
    if (D_004A1AAC != 0) { allowCue = 0; allowMotion = 0; }
    if (D_004A1664 != 0) { allowCue = 0; allowMotion = 0; }
    destination = (char *)actorModel + 80;
    if (D_004A6D28 != 0) allowCue = 0;
    boundsPtr = &bounds;
    activeMotions = 0;
    if (allowMotion != 0) {
        register const unsigned short *table __asm__("$2");
        const unsigned short *motionTable;
        table = (const unsigned short *)D_003D1220;
        motionTable = table + 6;
        for (j = 0; j < 20; j++) {
            if ((BATTLE_ENTRY(id * 5472)->w5236 >> j) & 1) {
                motionFlags |= 1;
                BATTLE_ENTRY(id * 5472)->h5244 = *motionTable;
                if (j == 9) motionFlags |= 2;
                activeMotions++;
            }
            motionTable += 8;
        }
    }
    hasSpecialMotion = motionFlags & 2;
    if (allowCue != 0) {
        BattleActorCue *queuedCue;
        BattleActorCue *row;
        row = (BattleActorCue *)((char *)D_003293C0 + (id * 32));
        if (row->w16 == 0) {
            int singleMotion;
            queuedCue = row;
            loopOffset = id * 5472;
            singleMotion = activeMotions < 2;
            for (j = 0; j < 20; j++) {
                k = (queuedCue->w20 + j) % 20;
                if ((BATTLE_ENTRY(loopOffset)->w5236 >> k) & 1) {
                    h = 0;
                    if (D_00324460[k] >= 0) h = func_00220820(1.0f, 1, D_00324460[k], queuedCue, 0);
                    if (h != 0) {
                        func_001E42A0(D_00343010, h, queuedCue);
                        func_001E4308(D_00343010, h, 2);
                    }
                    queuedCue->w20 = (k + 1) % 20;
                    if (singleMotion) queuedCue->w16 = 140; else queuedCue->w16 = 70;
                    j = 1000;
                }
            }
        } else row->w16 = row->w16 - 1;
    }
    entry = BATTLE_ENTRY(id * 5472);
    entry->h5246 = 0;
    if (hasSpecialMotion != 0) {
        color = *(volatile unsigned int *)&actorModel->w192 | 0x8000;
        entry->h5244 = D_003D1220[78];
        motion = *(volatile unsigned short *)&D_003D1220[78];
        *(volatile unsigned int *)&actorModel->w192 = color;
        entry->h5246 = motion;
    } else actorModel->w192 &= 0xffff7fff;
    if (motionFlags == 0) { BATTLE_ENTRY(id * 5472)->h5244 = 0; BATTLE_ENTRY(id * 5472)->h5246 = 0; }
    if ((D_004A6C08 | D_004A6C0C) != 0) {
        BattleActorEntry *state;
        unsigned short x;
        unsigned short y;
        x = *(unsigned short *)&D_004A6C08;
        y = *(unsigned short *)&D_004A6C0C;
        state = BATTLE_ENTRY(id * 5472);
        state->h5244 = x;
        state->h5246 = y;
    }
    func_002468F0(actorModel);
    func_0018F3D8(matrix, 0x70003c00, 0x70003f80);
    func_0022D470(destination, matrix, 0x70003e00);
    { int opt = D_004A13C8 & 4; int player;
      if (opt) actorModel->f200 = *(volatile float *)&D_0049FDFC;
      player = actorModel->h172;
      if (player < 4) D_004A14C8 = 0; else D_004A14C8 = 1; }
    f22 = 4608.0f;
    { char *target = D_004A1A20 + id * 5472;
      D_004A14C8 = 0;
      func_0021AF40(target); }
    f21 = func_0021AF68(D_004A1A20 + id * 5472) * f22;
    f21 = f21 * D_0049FE00;
    f20 = func_0021AF68(D_004A1A20 + id * 5472) * f22;
    f20 = f20 * D_0049FE04;
    func_00249108();
    func_002489F0();
    func_0022D550(actorModel);
    renderMode = func_002441F0(boundsPtr, -f21, 9216.0f, -f20, f21, -18432.0f, f20);
    if (battle_00127430() != 0) renderMode = 1;
    func_002491D8();
    func_002489F0();
    func_0022FDA0(1);
    if (battle_00127430() != 0) { actorModel->w124 = 0; actorModel->w212 = 0x80808080; }
    if (renderMode != 0) func_00246550(actorModel);
    else {
        if (BATTLE_ENTRY(id * 5472)->w5200 != 0) func_002464A8(actorModel);
        func_0022F268(actorModel);
    }
    func_002491D8();
    func_00179EE8();
}

#undef BATTLE_ENTRY
