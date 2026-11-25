#include "../common.h"
// compiler: 990721-r5900
// cflags: -fno-strength-reduce
typedef struct { char p0[188]; short h188; short p1; unsigned w192; float f196, f200; char p2[24 - 8 + 0]; } Z;
typedef struct { char p0[24]; int w24; char p1[160]; short h188; char p2[2]; unsigned w192; float f196; float f200; char p3[172]; short h376, h378; } O;
typedef struct { char p0[4816]; unsigned fl; char p1[19]; unsigned char b4835; unsigned char pad; char p1b[0]; } Dummy;
typedef struct { char p0[4816]; int fl; char p1[16]; int w4836; char p2[103]; signed char b4943; char p3[40]; int w4984; char p4[216]; float f5204; char p5[97]; char b5305; char p6[150]; char *tbl; char p7[12]; } E;
extern E *D_004A1A20;
extern int D_004A6E24, D_004A129C, D_004A6D94, D_004A6C98, D_004A6CF0, D_004A1A6C, D_004A6D60, D_004A6DD8, D_004A6D40, D_004A13D4, D_004A6D3C, D_004A6DC8;
extern float D_0049FE64;
extern char D_00431A00[], D_00431940[], D_00431A30[], D_00431A48[], D_00431A58[], D_00431A70[], D_00431A80[], D_00431A98[], D_00431AB0[], D_00431AC8[], D_00431AD8[];
extern int DbgPrintf(char *, ...);
extern void func_00239568(char *, ...);
extern long func_002D9440(float);
extern int battle_00124168(int), battle_00127430(void), battle_0011d8a8(int, int), func_00129650(int, int), func_001269E0(int);
extern void battle_0012c1d8(int, int), battle_0011d588(int, int), battle_0012aea8(int), battle_0011bb28(int, int, int, int, int), func_00126270(int, int, int), func_00236C60(int, int, int, int, int, int), func_00128E68(int);
// MATCH func_0012BBF8
int battle_0012bbf8(O *q, int a, int *p3, int *p4, int *p5)
{
    unsigned *P;
    char *t, *t2;
    int r6, i, r16, n;
    unsigned u;
    E *e;
    P = (unsigned *)(D_004A1A20[a].tbl + *p5 * 156);
    if (battle_00124168(a) == 0) return 0;
    if (*p3 != 0) return 0;
    if (D_004A6E24 != 0) {
        { E *ee = D_004A1A20; float f = q->f196; D_004A129C = 1;
        func_00239568(D_00431A00, ee[a].w4984, func_002D9440(f), q->w192, q->h188); }
        func_00239568(D_00431940, q->w24, func_002D9440(q->f200), q->h376, q->h378);
    }
    if (D_004A1A20[D_004A6D94].w4836 == 13) return 1;
    if (battle_00127430() == 0) *p3 = 1;
    r16 = D_004A6C98 & 5;
    if (r16 == 1) {
        r6 = battle_0011d8a8(a, 1);
        if ((*(unsigned *)(D_004A1A20[a].tbl + *p5 * 156) & 0x12) == 0x12 || (*(unsigned *)(D_004A1A20[a].tbl + *p5 * 156) & 0x22) == 0x22) {
            battle_0012c1d8(a, 0);
            *p3 = r16;
            if (q->w192 & 0x20) {
                DbgPrintf(D_00431A30);
                *p4 = 2;
                *p5 = *p5 + 1;
            }
            return 1;
        }
        if (r6 > 0) battle_0012c1d8(a, 0);
        else if (D_004A13D4 == 10) {
            D_004A1A20[D_004A6D94].w4984 = D_004A1A20[D_004A6D94].w4984 + 1;
            if (D_004A6E24 != 0) DbgPrintf(D_00431A48);
            battle_0011d588(D_004A6D94, -1);
            battle_0012aea8(11);
            return 1;
        } else if (r6 == 0) {
            D_004A6C98 = D_004A6C98 | 4;
            DbgPrintf(D_00431A58);
            *p4 = 2;
            *p5 = *p5 + 1;
        }
    }
    if (D_004A6CF0 >= 6) battle_0011bb28(a, 12, 192, 1, 0);
    if (D_004A1A6C != 0) func_00239568(D_00431A70, D_004A6D60);
    if (D_004A1A20[a].fl & 0x20) {
        D_004A1A20[a].fl = D_004A1A20[a].fl & -33;
        DbgPrintf(D_00431A80);
        D_004A6DD8 = D_004A6DD8 + 1;
        *p4 = 2;
        t = D_004A1A20[a].tbl;
        i = *p5;
        if (((*(unsigned *)(t + i * 156) ^ 1) & 1) && i < 256) {
            t2 = t;
            do {
                n = i + 1;
                *p5 = n;
                u = *(unsigned *)(t2 + n * 156);
                if (u & 4) break;
                if (u & 0x800) break;
                if (!((u ^ 1) & 1)) break;
                i = n;
            } while (i < 256);
        }
        func_00126270(180, 180, 10);
        func_00236C60(0, 0, 0, 0, *(int *)(D_004A1A20[a].tbl + *p5 * 156 + 12), a);
        D_004A6D40 = D_004A6D40 + 1;
    } else if ((*P & 0x40000008) == 0 && func_00129650(a, *p5) != 0) {
        DbgPrintf(D_00431A98);
        *p4 = 2;
        *p5 = *p5 + 1;
    }
    if ((D_004A13D4 == 12 || D_004A6D60 != 0) && *p4 == 0) {
        if (func_00129650(a, *p5) != 0) {
            DbgPrintf(D_00431AB0);
            *p4 = 2;
            *p5 = *p5 + 1;
        }
    }
    if (D_004A6D3C == 0) {
        if ((*(unsigned *)(D_004A1A20[a].tbl + *p5 * 156) & 0x10000004) == 0x10000004) {
            D_004A6D3C = 1;
            func_00128E68(60);
        }
    }
    if ((*(unsigned *)(D_004A1A20[a].tbl + *p5 * 156) & 1) == 0) return 1;
    if (func_001269E0(a) != 0) {
        D_004A1A20[a].fl = D_004A1A20[a].fl | 0x800;
        if (a < 4 || D_004A1A20[a].b4943 != 0) {
            D_004A6DC8 = D_004A6DC8 - 1;
            DbgPrintf(D_00431AC8);
            D_004A1A20[a].b5305 = 0;
            D_004A6D60 = 0;
        } else {
            float fv;
            D_004A6D60 = 0;
            D_004A6DC8 = D_004A6DC8 - 1;
            fv = (0.00999999978f);
            D_004A1A20[a].b5305 = 0;
            D_004A1A20[a].f5204 = fv;
        }
    } else {
        D_004A6D60 = 0;
        D_004A6DC8 = D_004A6DC8 - 1;
        DbgPrintf(D_00431AD8);
        D_004A1A20[a].b5305 = 0;
    }
    return 1;
}
