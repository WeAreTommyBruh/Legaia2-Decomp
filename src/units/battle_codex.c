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
