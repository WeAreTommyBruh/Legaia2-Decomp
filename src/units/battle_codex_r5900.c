// compiler: 990721-r5900

typedef struct {
    char pad00[0x12d0];
    unsigned int flags;
    char pad12d4[0x28c];
} EnemyPortraitSlot_11B910;

extern EnemyPortraitSlot_11B910 *D_004A1A20_11B910 __asm__("D_004A1A20");
extern int D_004A1A84;
extern int D_004303C8[];
extern int D_004A1918[];
extern int func_0021A980(EnemyPortraitSlot_11B910 *);
extern void func_0011BB28(int, int, int, int, long);
extern void drawPortraitWithStatus_11B910(int, int, int, int, long) __asm__("func_0011BB28");
extern void func_00127080(float, int, int, int, int, int);

// MATCH func_0011B910
void battle_0011b910(int y, int style, long colors, int selected)
{
    int columns[3];
    int rows[2];
    register int i __asm__("$17") = 0;
    int divisor;
    int col, x, portrait;
    EnemyPortraitSlot_11B910 *actor;
    unsigned int flags;

    __builtin_memcpy(columns, D_004303C8, sizeof(columns));
    __builtin_memcpy(rows, D_004A1918, sizeof(rows));
    if (D_004A1A84 > 0) {
        divisor = 3;
        __asm__("" : "+r"(divisor));
        do {
            col = i % divisor;
            {
                register int offset __asm__("$2") = i * sizeof(EnemyPortraitSlot_11B910);
                char *base = (char *)D_004A1A20_11B910;
                flags = *(unsigned int *)(offset + (int)base + 0x6850);
                actor = (EnemyPortraitSlot_11B910 *)(base + (offset + 0x5580));
            }
            x = columns[col];
            if (func_0021A980(actor) == 0) {
                if (selected) {
                    if (flags & 0x800)
                        drawPortraitWithStatus_11B910(portrait = i + 4, x - 4, y + rows[i / divisor], style, colors);
                    else
                        func_0011BB28(portrait = i + 4, x - 4, y + rows[i / divisor], style, colors);
                    if (portrait == selected || selected < 0)
                        func_00127080(1.0f, i, 146, x - 22, y + rows[i / divisor], 128);
                } else if (!(flags & 0x800)) {
                    func_0011BB28(i + 4, x - 4, y + rows[i / divisor], style, colors);
                }
            }
            i++;
        } while (i < ({
            register int count __asm__("$2") = D_004A1A84;
            count;
        }));
    }
}
