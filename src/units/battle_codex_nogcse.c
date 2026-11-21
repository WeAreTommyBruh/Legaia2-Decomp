// cflags: -fno-gcse

typedef struct {
    char pad00[0x12cc];
    int selectedCommand;
    char pad12d0[0x94];
    int state;
    char pad1368[0x1f8];
} BattleCommandSlot_121C90;

typedef struct { char data[128]; } BattleCommand_121C90;

extern int D_004A6DA4, D_004A6D94, D_004A6D80, D_004A1A48, D_004A6D84;
extern unsigned int D_004A6E74;
extern BattleCommandSlot_121C90 *D_004A1A20_121C90 __asm__("D_004A1A20");
extern float D_0049FDA4, D_0049FDA8;
extern BattleCommand_121C90 D_00327DA0[];
extern int D_004A1A8C, D_004A1A2C, D_004A1A54, D_004A1A58, D_004A1A60;

extern void func_00232028(float, BattleCommand_121C90 *);
extern void func_001100B8(void);
extern void func_001297A0(int, int, int, int, int, int);
extern void func_0021A8F8(BattleCommandSlot_121C90 *);
extern void func_0012AEA8(int);
extern void func_0012C800(int);
extern void func_0012C1D8(int, int);
extern void func_0011BB28(int, int, int, int, int);
extern void func_00122118(void);
extern void func_00235130(int, int);

// MATCH func_00121C90
void battle_00121c90(void)
{
    int slot = D_004A6D94;
    int selection = D_004A6DA4;
    D_004A6D80 = -1;
    if (D_004A1A48 == 0) {
        if (D_004A6D84 == 7 && D_004A1A20_121C90[slot].state == 4)
            D_004A6E74 &= 0xfff35fff;
        if (D_004A6E74 & 0x82000) {
            func_00232028(D_0049FDA4, &D_00327DA0[selection]);
            D_004A6DA4++;
            if (D_004A6DA4 > D_004A1A8C - 1)
                D_004A6DA4 = 0;
            D_004A1A2C = 10;
            func_001100B8();
            D_004A6E74 = 0;
        }
        if (D_004A6E74 & 0x48000) {
            func_00232028(D_0049FDA8, &D_00327DA0[selection]);
            D_004A6DA4--;
            if (D_004A6DA4 < 0)
                D_004A6DA4 = D_004A1A8C - 1;
            D_004A1A2C = 10;
            func_001100B8();
            D_004A6E74 = 0;
        }
        if (D_004A6E74 & 0x200040) {
            D_004A1A2C = 0;
            if (D_004A1A54 != 0 && D_004A6DA4 != 0) {
                func_001297A0(0, 2, 0, 3, 0, 0);
                D_004A1A58 = -1;
                D_004A1A54 += 2;
            } else {
                D_004A1A48 = 1;
            }
            D_004A6E74 = 0;
        }
        if (D_004A6E74 & 0x100010) {
            D_004A1A2C = 0;
            func_001297A0(0, 2, 0, 2, 0, 0);
            func_0021A8F8(&D_004A1A20_121C90[slot]);
            func_0012AEA8(D_004A6D84);
            D_004A6E74 = 0;
        }
        if (selection != D_004A6DA4)
            func_001297A0(0, 2, 0, 0, 0, 0);
        func_0012C800(selection);
    } else {
        D_004A1A48++;
    }
    selection = D_004A6DA4;
    func_0012C1D8(selection, 0);
    func_0011BB28(selection, 12, 160, 0, 0);
    if (D_004A1A48 > 10) {
        D_004A1A48 = 0;
        func_001297A0(0, 2, 0, 1, 0, 0);
        D_004A1A20_121C90[slot].selectedCommand = D_004A6DA4;
        func_0012AEA8(3);
        {
            int next;
            register int count __asm__("$2");
            next = D_004A6D94 + 1;
            count = D_004A1A8C;
            D_004A6D94 = next;
            if (next >= count)
                func_00122118();
        }
        func_00235130(-1, D_004A1A60);
    }
}

typedef struct {
    char pad00[0xc4];
    float initiative;
    char padC8[9];
    unsigned char opacity;
} BattleIntroActor;

typedef struct {
    char pad00[0x12d0];
    unsigned int flags;
    char pad12D4[0x7b];
    char excludeFromInitiative;
    char pad1350[0x210];
} BattleIntroSlot;

typedef struct {
    float x, y, z, w;
} BattleIntroVector;

typedef struct {
    BattleIntroVector eye, target, up;
} BattleIntroCamera;

typedef struct {
    int x, y;
} BattleIntroPosition;

extern BattleIntroSlot *D_004A1A20_11E1A0 __asm__("D_004A1A20");
extern BattleIntroActor *D_003279A0_11E1A0[] __asm__("D_003279A0");
extern BattleIntroCamera D_00327A40_11E1A0[] __asm__("D_00327A40");
extern BattleIntroCamera D_0055ABC0[];
extern BattleIntroPosition D_00323DA0[][4], D_00323D20[][4];
extern char D_004305F0[], D_00430600[];
extern char D_00326F90[];
extern int D_004A1A34, D_004A1A54, D_004A1A60, D_004A1A84, D_004A1A8C;
extern float D_0049FD60;
extern int D_004A6DA8, D_004A6E98, D_004A6E70, D_004A6DB4, D_004A6CA4, D_004A6E94;
extern int D_004A6D94, D_004A6D9C, D_004A6D80;
extern void func_00237A40(int, int, int, int, int, int, int, int, char *);
extern void func_00290850(void);
extern void func_0024DD98(void);
extern void func_001265D0(int);
extern int rand(void);
extern int func_0021B5B8(BattleIntroActor *);
extern int func_00127210(void);
extern int func_00221708(void *);
extern void func_00235138(float, int, int);
extern int func_002216F8(void *);
extern float func_00127498(int);
extern void func_0011E0B0(int, float, float);
extern void func_0011BB28(int, int, int, int, int);
extern void func_00235130(int, int);
extern int func_00221D60(void *, int, int);
extern void func_0012AEA8(int);
extern void func_00122118(void);

// MATCH func_0011E1A0
void battle_0011e1a0(void)
{
    char *announcement = 0;
    BattleIntroSlot *slot;
    BattleIntroPosition *position;
    register BattleIntroPosition *table __asm__("$3");
    int count;
    register int countBound __asm__("$3");
    int active;
    BattleIntroActor **combatant;
    int i;
    int offset;
    int initiative;
    int initiativeLimit;
    int skipPositions;

    D_00327A40_11E1A0[0].eye.z = -10240.0f;
    D_00327A40_11E1A0[0].eye.x = 0.0f;
    D_00327A40_11E1A0[0].eye.y = 0.0f;
    D_004A6DA8 = 0;
    D_004A6E98 = 0;
    if (D_004A1A34 == 2) {
        D_004A6E98 = 120;
        announcement = D_004305F0;
    }
    if (D_004A1A34 == 1)
        announcement = D_00430600;
    if (announcement)
        func_00237A40(0, 0, 0, 0, 160, 16, 320, 320, announcement);
    if (D_004A6E70 == 0) {
        func_00290850();
        {
            register int needsUpdate __asm__("$3") = D_004A6DB4;
            if (needsUpdate)
                func_0024DD98();
        }
        slot = D_004A1A20_11E1A0;
        {
            unsigned int activeFlag = 0x20000;
            i = 19;
            do {
                if (slot->flags & activeFlag)
                    slot->flags |= 2;
                i--;
                slot++;
            } while (i >= 0);
        }

        D_004A6CA4 = -1;
        i = 0;
        func_001265D0(0);
        func_001265D0(7);
        if (i < D_004A1A8C) {
            BattleIntroActor **portrait = D_003279A0_11E1A0;
            do {
                if (*portrait)
                    (*portrait)->opacity = 0;
                i++;
                portrait++;
            } while (i < D_004A1A8C);
        }

        D_004A6E70 = 1;
        combatant = D_003279A0_11E1A0;
        D_004A6E94 = 0;
        i = 0;
        offset = 0;
        do {
            if (*combatant && !((BattleIntroSlot *)(offset + (int)D_004A1A20_11E1A0))->excludeFromInitiative) {
                initiative = (rand() & 63) + i * i * 5;
                initiativeLimit = func_0021B5B8(*combatant);
                if (initiativeLimit)
                    initiative %= initiativeLimit;
                (*combatant)->initiative = (float)initiative;
            }
            i++;
            offset += sizeof(BattleIntroSlot);
            combatant++;
        } while (i < 20);
    }

    skipPositions = 0;
    if (func_00127210() != 0) {
        if (D_004A6E94 == 0) {
            if (func_00221708(D_00326F90) == 0) {
                int source = D_004A1A60;
                __asm__ volatile("" : : "r"(source));
                func_00235138(D_0049FD60, -1, source);
                D_004A6E94 = 2;
            }
            if (func_002216F8(D_00326F90) != 0) {
                D_004A6E70 = 1;
                skipPositions = 1;
                D_004A6E94 = 0;
            }
        }
    } else {
        D_004A6E94 = 10;
    }

    func_0011E0B0(D_004A6E70, func_00127498(0x70003e00), 0.0f);
    active = func_00127210();
    if (active != 0) {
        count = D_004A1A84;
        __asm__ volatile("" : : "r"(count));
        table = D_00323DA0[0];
    } else {
        count = D_004A1A84;
        __asm__ volatile("" : : "r"(count));
        table = D_00323D20[0];
    }
    table = (BattleIntroPosition *)((int)table - 32);

    {
        register int scaled __asm__("$4") = count * 32;
        position = (BattleIntroPosition *)(scaled + (int)table);
    }
    countBound = count;
    __asm__ volatile("" : : "r"(countBound));

    if ((unsigned int)(D_004A6E70 - 3) < 257 && !skipPositions) {
        i = 0;
        if (countBound > 0) {
            do {
                func_0011BB28(i + 4, position->x - 45, position->y, 1, 0);
                i++;
                position++;
            } while (i < D_004A1A84);
        }
    }
    if ((unsigned int)(D_004A6E70 - 221) < 40) {
        int cap;
        BattleIntroActor **portrait;
        cap = 128;
        portrait = D_003279A0_11E1A0;
        i = 2;
        do {
            if (*portrait) {
                (*portrait)->opacity += 4;
                if ((*portrait)->opacity > 128)
                    (*portrait)->opacity = cap;
            }
            i--;
            portrait++;
        } while (i >= 0);
    }
    if (D_004A6E70 > 260) {
        if ((unsigned int)(D_004A6E94 - 2) < 2) {
            if (D_004A6E94 == 2) {
                func_00235130(-1, D_004A1A60);
                D_004A6E94 = 3;
            }
            if (func_00221D60(D_00326F90, 4, 0) == 0)
                D_004A6E94 = 4;
        } else {
            func_00235130(-1, D_004A1A60);
            D_004A6D94 = 0;
            D_004A6D9C = 0;
            if (D_004A1A54 != 0)
                func_0012AEA8(15);
            else
                func_0012AEA8(2);
            if (D_004A1A34 == 2)
                func_00122118();
            __builtin_memcpy(&D_0055ABC0[0].target, &D_00327A40_11E1A0[0].target, 16);
            __builtin_memcpy(&D_0055ABC0[0].eye, &D_00327A40_11E1A0[0].eye, 16);
            __builtin_memcpy(&D_0055ABC0[0].up, &D_00327A40_11E1A0[0].up, 16);
        }
    }
    D_004A6D80 = -1;
    D_004A6E70++;
}

extern int D_004A1A20;
extern char D_00430C38[], D_00430C48[], D_004A19A8[];
extern void func_001118F8(char *, ...);

// MATCH func_00124020
void battle_00124020(int actor)
{
    register unsigned *records __asm__("$16");
    register unsigned *cursor __asm__("$3");
    register int again __asm__("$3");
    int count = 1;
    int i;

    func_001118F8(D_00430C38, actor);
    records = *(unsigned **)(actor * 5472 + D_004A1A20 + 5456);
    if ((records[0] ^ 1) & 1) {
        cursor = records;
        do {
            cursor += 39;
            ++count;
            if (!((cursor[0] ^ 1) & 1))
                break;
        } while (count < 256);
    }
    count += 3;

    i = 0;
    if (count > 0) {
        register int actorOffset __asm__("$20");
        int offset;
        register int stride __asm__("$2") = 5472;
        register int prefixBase __asm__("$23") = 0x4a0000;

        __asm__ volatile ("" : : "r"(stride) : "$20");
        actorOffset = actor * stride;
        __asm__ volatile ("" : : "r"(actorOffset) : "$19");
        offset = 0;
        do {
            char *entry = (char *)(actor * 5472 + D_004A1A20);
            unsigned *record = (unsigned *)(*(char **)(entry + 5456) + offset);
            unsigned last;
            register char *format __asm__("$4");
            unsigned first;
            unsigned second;
            unsigned third;
            unsigned fourth;
            unsigned size;

            if (*(int *)(entry + 4984) == i) {
                /* D_004A19A0 uses separate high and low address loads. */
                func_001118F8((char *)(prefixBase + 0x19a0));
                __asm__ volatile ("" : : : "memory");
                last = record[22];
            } else {
                func_001118F8(D_004A19A8);
                last = record[22];
            }
            format = D_00430C48;
            __asm__ volatile ("" : : "r"(format) : "$5", "$6", "$7", "$8", "$9");
            first = record[0];
            __asm__ volatile ("" : "+r"(i) : "r"(first));
            i++;
            second = record[1];
            offset += 156;
            third = record[19];
            fourth = record[20];
            __asm__ volatile ("" : : "r"(first), "r"(second), "r"(third), "r"(fourth) : "memory");
            size = record[11];
            func_001118F8(format, first, second, third, fourth, size, last);
        } while ((again = i < count));
    }
}

extern int D_004A1A50, D_004A6D94, D_004A1A20;

// MATCH func_00124168
int battle_00124168(int input)
{
    register int actor __asm__("$8") = input;
    register int current __asm__("$7");
    register int base __asm__("$4");
    register int stride __asm__("$2");
    int result;

    if (D_004A1A50 & 0x10)
        return 0;

    current = D_004A6D94;
    if (actor < 4) {
        stride = 5472;
        base = D_004A1A20;
        if (*(int *)(current * stride + base + 4812) == 100)
            return 0;
    } else {
        stride = 5472;
        base = D_004A1A20;
        if (*(int *)(current * stride + base + 4812) == 101)
            return 0;
    }

    {
        register int selected __asm__("$4");
        register int address __asm__("$3");
        register int savedBase __asm__("$6") = base;
        register int scale __asm__("$5") = 5472;

        selected = current * scale;
        address = selected + savedBase;
        __asm__ volatile ("" : "+r"(address));
        selected = *(int *)(address + 4812);
        result = 0;
        if (selected == actor) {
            result = actor * scale;
            address = result + savedBase;
            __asm__ ("" : "+r"(address));
            result = *(signed char *)(address + 5305) != 0;
        }
    }
    return result;
}

typedef struct {
    char pad[40];
    int source;
    int target;
} BattleTransition_11DBB0;

extern BattleTransition_11DBB0 D_003244F0[];
extern char *D_004A1A20_11DBB0 __asm__("D_004A1A20");
extern void *D_003279A0[];
extern char D_004305D8[];
extern int func_00127F70(void);
extern void func_0024DD98(void);
extern void func_0021B550(char *);
extern void func_0024D048(float, int);
extern void func_0024D8C0(int, float, float, int, int);
extern int func_0024CFC8(void);

// MATCH func_0011DBB0
void battle_0011dbb0(float step, int input)
{
    int frames;
    int limit;
    int i;
    int offset;
    void **actors;
    void **actorTable;
    int range;
    int stride;
    int running;
    int source, target;
    int same;
    BattleTransition_11DBB0 *transition;
    int mode = input;

    if (func_00127F70())
        return;
    switch (mode) {
    case 0:
        transition = D_003244F0;
        same = -1;
        goto setSame;
    case 1: {
        int from;
        register int to __asm__("$4");
        from = D_004A6D94;
        to = D_004A6D9C;
        D_003244F0->source = from;
        D_003244F0->target = to;
        break;
    }
    case 2: {
        register int selected __asm__("$4") = D_004A6D94;
        D_003244F0->target = -1;
        __asm__("" : "+r"(selected));
        D_003244F0->source = selected;
        break;
    }
    case 3:
        same = D_004A6D94;
        __asm__ volatile ("" : : "r"(same));
        transition = D_003244F0;
    setSame:
        transition->source = same;
        transition->target = same;
        break;
    }
    frames = 0;
    limit = 12;
    if (mode == 0) {
        limit = 30;
        func_0024DD98();
    }
    actorTable = D_003279A0;
    range = mode - 1;
    stride = 5472;

    offset = 0;
    do {
        actors = actorTable;
        i = 9;
        do {
            if (*actors)
                func_0021B550(D_004A1A20_11DBB0 + offset);
            offset += 5472;
            i--;
            actors++;
        } while (i >= 0);
        for (i = 0; i < 10; i++)
            func_0024D048(step, i);
        target = D_004A6D9C;
        if ((unsigned)range < 2) {
            char *base;
            register int displacement __asm__("$2");
            unsigned flags;
            unsigned mask;
            mask = 0x400000;
            base = D_004A1A20_11DBB0;
            displacement = target * stride;
            __asm__("" : "+r"(mask), "+r"(base));
            __asm__("" : "+r"(displacement));
            flags = *(unsigned *)(displacement + (int)base + 4816);
            if (flags & mask)
                func_0024D8C0(0, 1.0f, 1.0f, D_004A6D94, target);
        }
        if (mode == 3) {
            source = D_004A6D94;
            func_0024D8C0(0, 1.0f, 1.0f, source, source);
        }
        if (func_0024CFC8()) {
            for (i = 0; i < 10; i++)
                func_0024D048(step, i);
        }
        frames++;
        running = func_0024CFC8();
        offset = 0;
        if (frames > limit)
            running = 0;
    } while (running);
    func_001118F8(D_004305D8, frames);
}
