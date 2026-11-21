// compiler: 990721-r5900
// cflags: -fno-schedule-insns

extern int D_004A1490, D_004A1494, D_004A126C, D_004A6DD0, D_004A1A94;
extern int D_004A6CEC, D_004A6CC0, D_004A6E40, D_004A6CB8;
extern char *D_004A14E0;
extern char D_0053FD30[], D_0053FD00[], D_0042FA20[], D_00321060[];
extern char D_004312D0[], D_004312E0[], D_004312F8[];
extern char *D_00326ED0[];

extern void func_0024CD68(int, int, float);
extern void func_002E5B20(int);
extern void func_002C0338(int, int);
extern void func_002A3A48(char *);
extern void func_002A3A70(char *, char *, char *);
extern void func_00219778(int, char *);
extern int func_002DCE40(char *, char *, ...);
extern int func_0018B2A8(char *);
extern int func_002DD36C(char *, char *);
extern void func_001118F8(char *, ...);

// MATCH func_00127218
void battle_00127218(void)
{
    char path[256];
    unsigned map;
    char **mapName;
    int savedMode, size;
    volatile unsigned *vif1Control;

    {
        register int first __asm__("$4");
        register int second __asm__("$5");
        float zero;
        second = 0;
        first = 0;
        D_004A1490 = first;
        D_004A1494 = second;
        zero = 0.0f;
        __asm__("" : "+f"(zero));
        func_0024CD68(first, second, zero);
    }
    savedMode = D_004A126C;
    D_004A126C = 200;
    D_004A6DD0 = 0;
    func_002E5B20(0);
    func_002C0338(0, 0);
    vif1Control = (volatile unsigned *)0x10009000;
    do {
        *vif1Control &= 0x100;
    } while (*vif1Control);
    __asm__ volatile ("" : : "r"(vif1Control));

    func_002A3A48(D_0053FD30);
    func_002A3A70(D_0053FD30, D_004A14E0, D_0053FD00);
    func_002E5B20(0);
    func_002C0338(0, 0);
    vif1Control = (volatile unsigned *)0x10009000;
    do {
        *vif1Control &= 0x100;
    } while (*vif1Control);
    D_004A126C = savedMode;
    func_00219778(D_004A1A94, D_0053FD00);

    map = 0;
    D_004A6CEC = 1;
    mapName = D_00326ED0;
    D_004A6CC0 = 0;
    D_004A6E40 = 0;
    do {
        func_002DCE40(path, D_0042FA20, *mapName);
        size = func_0018B2A8(path);
        if (D_004A6E40 < size)
            D_004A6E40 = size;
        if (func_002DD36C(D_00321060, path) == 0) {
            D_004A6CC0 = map;
            func_001118F8(D_004312D0, map);
        }
        map++;
        mapName++;
    } while (map < 48);

    {
        register int negativeOne __asm__("$16") = -1;
        register int largestFile __asm__("$3");
        register int adjusted __asm__("$5");
        largestFile = D_004A6E40;
        adjusted = (int)((unsigned)largestFile + 1023u);
        __asm__("" : "+r"(negativeOne));
        adjusted = negativeOne < largestFile ? largestFile : adjusted;
        func_001118F8(D_004312E0, adjusted >> 10);

        largestFile = D_004A6E40;
        if (largestFile > 0x112fff) {
            register int nonnegative __asm__("$2");
            char *format;
            nonnegative = negativeOne < largestFile;
            __asm__("" : : "r"(nonnegative) : "$5");
            adjusted = (int)((unsigned)largestFile + 1023u);
            if (nonnegative)
                adjusted = largestFile;
            __asm__ volatile ("" : : "r"(adjusted));
            format = D_004312F8;
            __asm__("" : "+r"(format) : "r"(adjusted));
            func_001118F8(format, adjusted >> 10);
            for (;;)
                ;
        }
    }
    D_004A6CB8 = D_004A6CC0;
}
