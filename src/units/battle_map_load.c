typedef struct {
    char bytes[27];
} BattleMapPath;

extern BattleMapPath D_00321060[];
extern const BattleMapPath D_00430FF8[];
extern char *D_004A14E0, *D_004A6D68, *D_004A6D6C;
extern int D_004A6D64, D_004A6EA8, D_004A12A4, D_004A6D70, D_004A6D74;
extern char D_00430FD8[], D_00431018[], D_00431030[], D_00431048[], D_00431060[], D_00431078[];
extern char D_00431090[], D_004310A8[], D_004310C0[], D_0055B3F0[], D_00343028[];

extern int func_002AF9A0(void);
extern int func_0018B2A8(void *);
extern int func_001118F8(char *, ...);
extern void func_0018B7C8(void *, char *);
extern void func_0018B668(void *, char *);
extern void loadEffect(void *, char *) __asm__("func_0018B7C8");
extern void loadEffectAsync(void *, char *) __asm__("func_0018B668");
extern int func_00196FF8(void);
extern void func_0012CB20(char *, char *);
extern int func_0012CBE8(char *);
extern void func_002A1618(char *);
extern int func_0010C780(char *);

// MATCH func_00126B20
int battle_00126b20(void)
{
    register char *base __asm__("$6");
    register char *window __asm__("$4");
    char *path;
    int status;
    int size;
    register char *printBase __asm__("$3");
    int regionOffset;
    register int stage __asm__("$3");
    int phase;
    int span;
    register char *effects __asm__("$3");

    if (func_002AF9A0())
        return 1;
    window = D_004A14E0;
    base = window;
    window += 0x113000;
    span = 0x2a800;
    phase = D_004A6D64;
    effects = window + span;
    D_004A6D68 = window;
    D_004A6D6C = effects;
    switch (phase) {
    case 0:
        D_004A6EA8 = size = func_0018B2A8(D_00321060);
        if (size > 0x113000) {
            func_001118F8(D_00430FD8, D_00321060);
            *D_00321060 = *D_00430FF8;
            D_004A6EA8 = func_0018B2A8(D_00321060);
        }
        func_001118F8(D_00431018, D_00321060);
        if (D_004A12A4 == 10)
            func_0018B7C8(D_00321060, D_004A14E0);
        else
            func_0018B668(D_00321060, D_004A14E0);
        func_001118F8(D_00431030, D_004A14E0, 0x113000);
        printBase = D_004A14E0;
        func_001118F8(D_00431048, printBase + 0x113000, 0x4b000);
        printBase = D_004A14E0;
        func_001118F8(D_00431060, printBase + 0x15e000, 0x7d000);
        printBase = D_004A14E0;
        regionOffset = 0x1db000;
        func_001118F8(D_00431078, printBase + regionOffset, 0x125000);
        goto nextMap;
    case 1:
        if (func_00196FF8())
            return 1;
        D_004A6D64 = 10;
        break;
    case 10:
        path = D_00431090;
        D_004A6D70 = func_0018B2A8(path);
        if (D_004A12A4 == 10)
            loadEffect(path, D_004A6D68);
        else
            loadEffectAsync(path, D_004A6D68);
        goto nextResource;
    case 11:
        if (func_00196FF8())
            return 1;
        D_004A6D64 = 20;
        break;
    case 20:
        path = D_004310A8;
        D_004A6D74 = func_0018B2A8(path);
        if (D_004A12A4 == 10)
            func_0018B7C8(path, D_004A6D6C);
        else
            func_0018B668(path, D_004A6D6C);
        goto nextResource;
    case 21:
        if (func_00196FF8())
            return 1;
        D_004A6D64 = 30;
        break;
    case 30:
        func_0012CB20(D_0055B3F0, base + 0x1db000);
    nextMap:
        stage = D_004A6D64;
        D_004A6D64 = stage + 1;
        break;
    case 31:
        if (func_0012CBE8(D_0055B3F0))
            goto stillLoading;
        goto soundStage;
    case 50:
        if (D_004A12A4 == 10) {
            D_004A6D64 = 100;
            break;
        }
        func_002A1618(base + 0x15e000);
    nextResource:
        D_004A6D64++;
        break;
    case 51:
        status = func_0010C780(D_00343028);
        if (status == 0)
            D_004A6D64 = 100;
        if (status >= 0)
            return 1;
    soundStage:
        D_004A6D64 = 50;
        break;
    case 100:
        func_001118F8(D_004310C0);
        return 0;
    }
stillLoading:
    return 1;
}
