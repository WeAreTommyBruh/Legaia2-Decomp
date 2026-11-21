typedef struct {
    int threshold;
    float duration;
    float values[6];
    char padding[128];
} BattleTransitionPreset;

extern BattleTransitionPreset D_003246D0[];
extern int D_004A6CC0;
extern int func_00127210(void);
extern void func_0011BC88(int, float, float, float, float, float, float, float);

// MATCH func_0011E0B0
void battle_0011e0b0(int mode, float offset, float customDuration)
{
    register float *values __asm__("$3");
    float duration;
    int type = D_004A6CC0;
    int previous = 0;

    if (mode < 221) {
        register int index __asm__("$7");
        register int i __asm__("$6");

        BattleTransitionPreset *presets;
        register int tableBase __asm__("$2");
        register BattleTransitionPreset *chosen __asm__("$2");
        register int bytes __asm__("$4");
        register int stride __asm__("$2");
        register BattleTransitionPreset *p __asm__("$5");

        __asm__ volatile ("" : : "r"(type));
        func_00127210();
        /* D_00323F10 uses separate high and low address loads. */
        tableBase = 0x320000;
        __asm__ ("" : "+r"(tableBase));
        presets = (BattleTransitionPreset *)(tableBase + 0x3f10);
        /* Keep the table address load ahead of the loop initializers. */
        __asm__ volatile ("" : : "r"(presets) : "$7");
        index = 2;
        i = 0;
        __asm__ volatile ("" : : "r"(i) : "$5");
        p = presets;
        for (; i < 4; i++) {
            register int threshold __asm__("$4") = p->threshold;
            if (mode < threshold)
                index = previous <= mode ? i : index;
            previous = threshold;
            p++;
        }
        stride = sizeof(BattleTransitionPreset);
        bytes = index * stride;
        chosen = (BattleTransitionPreset *)(bytes + (int)presets);
        values = chosen->values;
        __asm__ volatile ("" : "+r"(values) : "r"(chosen) : "memory");
        duration = chosen->duration;
    } else {
        register BattleTransitionPreset *presets __asm__("$3") = D_003246D0;
        register BattleTransitionPreset *chosen __asm__("$2");
        duration = 20.0f;
        if (mode == 300)
            duration = customDuration;
        chosen = &presets[type];
        values = chosen->values;
        __asm__ volatile ("" : "+r"(values));
        values[1] = 0.0f;
    }
    func_0011BC88(3976, duration, values[0], values[1], values[2],
                  values[3], values[4] + offset, values[5]);
}

extern unsigned D_004A1A50;
extern char *D_004A1A20;
extern void *D_004A1A94;
extern unsigned D_00425510[];
extern char D_00431430[];
extern void func_001118F8(const char *, ...);
extern unsigned func_002194E0(void *, int);
// MATCH func_001283F0
void battle_001283f0(void)
{
    register unsigned result __asm__("$2");
    register unsigned flags __asm__("$5");
    unsigned *p;
    int id;
    register int battle __asm__("$3");

    result = D_004A1A50 & 0x10;
    if (result)
        return;
    result = func_00127210();
    if (result)
        return;
    flags = D_004A1A50;
    result = flags & 0x400;
    if (result)
        return;
    p = D_00425510;
    if (p[1] & 0x8000) {
        result = *p;
        goto done;
    }
    result = *p;
    if (result &= 0x10000000)
        return;
    if ((result = flags & 8) != 0) {
        id = *(int *)(D_004A1A20 + 26852);
        battle = id - 100;

        if ((unsigned)(id - 214) < 2 || battle == 111 || battle == 173 ||
            battle == 58 || battle == 119 || battle == 291 || battle == 171) {
            func_001118F8(D_00431430);
            return;
        }
        result = func_002194E0(D_004A1A94, 1);
        __asm__ volatile ("" : : "r"(result));
    } else {
        result = func_002194E0(D_004A1A94, 2);
        __asm__ volatile ("" : : "r"(result));
    }

done:
    return;
}

extern int D_004A12B0;
extern int D_0053F900[];
extern void func_002A53B0(int *, int, int, int);
extern void func_002A5EC0(int *);
// MATCH func_00126848
void battle_00126848(int image, int options, int x, int y, int rightMargin, int bottomMargin)
{
    int imageId;
    int imageOptions;
    register int scaledX __asm__("$13");
    register int margin __asm__("$2");
    int width;
    register int height __asm__("$8");
    short screenWidth;
    int remainingWidth;
    int alternate;
    register int leftControl __asm__("$2");
    register int rightControl __asm__("$6");
    register int enabled __asm__("$5");
    int scaledY;
    int *packet;

    imageId = image;
    imageOptions = options;
    scaledX = x;
    screenWidth = 512;
    margin = rightMargin;

    if (!imageId)
        return;
    width = screenWidth - margin;
    alternate = D_004A12B0 & 1;
    height = 256 - bottomMargin;
    leftControl = 2240;
    __asm__("" : "+r"(leftControl));
    rightControl = leftControl;
    __asm__("" : "+r"(rightControl));
    rightControl = alternate ? 0 : rightControl;
    __asm__("" : "+r"(height));
    packet = D_0053F900;
    remainingWidth = width;
    width = remainingWidth - scaledX;
    __asm__("" : "+r"(rightControl));
    height -= y;
    enabled = 1;
    scaledY = y << 4;
    leftControl = alternate ? leftControl : 0;
    packet[29] = enabled;
    scaledX <<= 4;
    packet[22] = rightControl;
    width <<= 4;
    height <<= 4;
    packet[21] = leftControl;
    packet[26] = imageOptions;
    packet[25] = imageId;
    packet[15] = scaledX;
    packet[16] = scaledY;
    packet[17] = width;
    packet[18] = height;
    packet[10] = 27648;
    packet[11] = 30976;
    packet[12] = 10240;
    packet[13] = 3584;
    func_002A53B0(packet, 128, 128, 128);
    func_002A5EC0(packet);
}

typedef struct {
    char pad00[32];
    float x;
    char pad24[4];
    float z;
    char pad2c[24];
    float angle;
    char pad48[56];
    float targetX;
    char pad84[4];
    float targetZ;
} BattleMotion;

extern int D_004A6D34, D_004A6E50, D_004A6D9C, D_004A6DAC, D_004A6C98, D_004A6D94, D_004A6C80;
extern float D_004A6D30, D_0049FD48, D_0049FD4C, D_0049FD50;
extern char D_004305C8[];
extern void *D_004A1AA8;
extern int func_00129E78(void);
extern void func_001243A0(int, int);
extern int func_0021AEE0(char *);
extern int func_00127FC8(int);
extern float func_00126930(int, int);
extern float func_0022F3C8(float, float);
extern float func_0022F5A0(float, float);
extern int func_0021F2A8(void *, int, int);

// MATCH func_0011D8A8
int battle_0011d8a8(int actor, int waitForReads)
{
    char *slot;
    char *base;
    register char *table __asm__("$4");
    BattleMotion *motion;
    BattleMotion *otherMotion;
    register int result __asm__("$20");
    int actionIndex, target, reads, secondRead;
    float dx, dz, limit, nextAngle;

    register int offset __asm__("$2");
    register char *initialBase __asm__("$4");

    offset = actor * 5472;
    initialBase = D_004A1A20;
    slot = (char *)(offset + (int)initialBase);
    actionIndex = *(int *)(slot + 4984);
    table = *(char **)(slot + 5456);
    result = 0;
    if (!(*(unsigned *)(table + actionIndex * 156) & 0x102)) {
        result = -1;
        goto pollReads;
    }
    if (!func_00129E78() && !D_004A6E50) {
        func_001243A0(actor, D_004A6D9C);
        D_004A6E50 = 1;
        D_004A6DAC = 0;
        func_001118F8(D_004305C8);
    }
    if (--D_004A6D34 < 0)
        goto pollReads;
    {
        register float current __asm__("$f1");
        register float empty __asm__("$f0");
        current = D_004A6D30;
        empty = 0.0f;
        if (current == empty)
            goto pollReads;
    }

    target = D_004A6D94;
    if (!D_004A6C98)
        target = func_0021AEE0(D_004A1A20 + actor * 5472);
    base = D_004A1A20;
    motion = *(BattleMotion **)(base + actor * 5472 + 4800);
    otherMotion = *(BattleMotion **)(base + target * 5472 + 4800);
    if (!func_00127FC8(D_004A6D9C)) {
        limit = func_00126930(actor, target);
        dx = motion->targetX - otherMotion->targetX;
        dz = motion->targetZ - otherMotion->targetZ;
    } else {
        float measured;
        register float zero __asm__("$f1");
        limit = func_00126930(actor, actor);
        measured = motion->x;
        zero = 0.0f;
        __asm__("" : "+f"(zero));
        dx = measured - zero;
        dz = motion->z - D_0049FD48;
    }

    {
        register char *actionBase __asm__("$5") = D_004A1A20;
        table = *(char **)(actionBase + actor * 5472 + 5456);
    }
    if (*(unsigned *)(table + actionIndex * 156) & 0x100) {
        register int a1 __asm__("$3"), a2 __asm__("$2");
        nextAngle = func_0022F3C8(-dx, -dz);
        a1 = (int)(nextAngle * 10.0f);
        a2 = (int)(motion->angle * 10.0f);
        __asm__ volatile ("" : : "r"(a1) : "$20");
        result = 1;
        if (a1 != a2) {
            motion->angle += D_0049FD4C;
            if (motion->angle > D_0049FD50)
                motion->angle = 0.0f;
        }
    } else {
        motion->angle = func_0022F3C8(dx, dz);
        if (func_0022F5A0(dx, dz) < limit) {
            if (!D_004A6E50) {
                D_004A6D30 = 0.0f;
                result = 0;
            }
        } else {
            result = 1;
        }
    }

pollReads:
    if (waitForReads && !D_004A6C80) {
        reads = func_0021F2A8(D_004A1AA8, D_004A6D94, 0);
        secondRead = func_0021F2A8(D_004A1AA8, D_004A6D94, 1);
        if (reads | secondRead)
            return 1;
        D_004A6C80 = 1;
    }
    return result;
}
