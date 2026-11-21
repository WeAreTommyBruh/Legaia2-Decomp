// cflags: -fno-gcse -fno-schedule-insns

extern int D_004A1A20;
extern int D_003279A0[];
// MATCH func_00126360
void battle_00126360(void)
{
    int i;
    int table;
    int strideB;
    int mirror;
    register int callbackBase __asm__("$14");
    int strideA;
    int slot;
    int value;
    int next;
    register int displacement __asm__("$2");
    int base;
    int entity;
    register void (*callback)(void) __asm__("$11");
    int remaining;
    int block;
    unsigned index;
    int finishOffset;
    int exitAddress;
    i = 0;
    table = (int)D_003279A0;
    strideB = 5472;
    mirror = table;
    /* The original splits the fixed address of func_00230CB0 across the loops. */
    callbackBase = 0x230000;
    strideA = 5472;

    do {
        slot = i * 4;
        value = *(int *)(slot + table);
        next = i + 1;
        if (value) {
            displacement = i * strideA;
            base = D_004A1A20;
            entity = slot + mirror;
            callback = (void (*)(void))(callbackBase + 0xcb0);
            remaining = 3;
            block = displacement + base;
            do {
                if (*(int *)(block + 112)) {
                    index = *(unsigned *)(block + 120);
                    *(int *)(block + 112) = 0;
                    *(int *)(block + 128) = 0;
                    if (index < 64) {
                        int entryAddress;
                        entryAddress = *(int *)(*(int *)entity + 144);
                        entryAddress += index * 4;
                        ((void (**)(void))entryAddress)[256] = callback;
                    }
                }
                remaining--;
                block += 1200;
            } while (remaining >= 0);
            finishOffset = i * strideB;
            exitAddress = finishOffset + base;
            __asm__ ("" : "+r"(exitAddress));
            *(int *)(exitAddress + 5200) = 0;
        }
        i = next;
    } while (i < 20);
}
