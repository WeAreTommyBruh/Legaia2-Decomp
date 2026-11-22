/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
#include "../common.h"
typedef struct { int w0; char *p4; char p8[0x38]; int w40; char p44[0x3c]; } W;
typedef struct { int w0; int cur; int pages; int top; } M;
typedef struct { char p0[0x12d0]; unsigned f12d0; char p12d4[0x10]; int f12e4; char p12e8[0x7c]; int f1364; char p1368[0xf0]; int f1458; char p145c[0x18]; unsigned f1474; char p1478[0xe8]; } Slot;
typedef struct { char p[0xac]; short id; } Act;
typedef struct { char p[0x29]; char b29; char p2a[0x26]; } T80;
typedef struct { int w0; int w4; int w8; } MF;
extern W D_00321DB0[];
extern M D_00327830, D_00327880, D_00327858;
extern MF D_003279F0;
extern T80 D_003210E0[];
extern Act *D_003279A0[];
extern Slot *D_004A1A20;
extern char D_004A1940[], D_004A18C8[], D_00430658[], D_004A1948[];
extern char D_004A18E0;
extern char *D_004A6DC0;
extern int D_004A6D94, D_004A6CA8, D_004A1A54, D_004A6E74, D_004A1A2C, D_004A1A8C, D_004A6D88, D_004A1A60, D_004A6D8C;
extern int D_004A6CF4, D_004A13D4, D_004A1A48, D_004A1A4C, D_004A1A44, D_004A6DA0, D_004A6D80;
extern volatile float D_0049FD70;
extern float D_0049FD74, D_0049FD78, D_0049FD7C;
extern void func_00247630(MF *, int, int);
extern int func_002162E8(void);
extern void func_001118F8(char *, ...);
extern int func_0021A938(Slot *);
extern void func_00122118(void);
extern void func_00235130(int, int);
extern void func_00235028(W *, float);
extern void func_00247468(MF *, int, W *);
extern void func_00247490(MF *, int);
extern void func_00247580(MF *, int);
extern void func_0011BB28(int, int, int, int, int);
extern void func_0024CEE8(int, int);
extern void func_0012D038(void);
extern int func_0012AEA8(int);
extern int func_0021AB90(Slot *);
extern int func_0021ABE0(Slot *);
extern int func_0021ACE0(Slot *);
extern int func_0021AD30(Slot *);
extern void func_00255278(int);
extern void func_001297A0(int, int, int, int, int, int);
extern void func_0012C800(int);
extern void func_0021A8F8(Slot *);
extern int func_0024CF68(int);
extern void func_0012C1D8(int, int);
// MATCH func_0011ec78
void battle_0011ec78(void)
{
    int a, k, st, v;
    unsigned m;
    char c;

    a = D_004A6D94;
    D_004A6CA8 &= ~(1 << a);
    k = 0;
    m = 0;
    if (D_004A1A54 != 0) {
        m = D_004A6E74;
        func_00247630(&D_003279F0, m, D_004A1A2C);
    }
    if (D_004A1A20[a].f1364 == 4)
        D_00321DB0[3].p4 = D_004A1940;
    else
        D_00321DB0[3].p4 = D_004A18C8;
    if (!(D_004A1A20[a].f1474 & 0x20))
        D_00321DB0[3].w40 = 0x808080;
    else
        D_00321DB0[3].w40 = 0x404040;
    c = 0;
    st = D_004A1A20[a].f12e4;
    if (D_004A1A20[a].f1364 < 7)
        c = (&D_003210E0[0] + D_004A1A20[a].f1364)->b29;
    if (func_002162E8() != 0) {
        D_004A6E74 &= 0xfff48fff;
        D_00321DB0[0].w40 = 0x404040;
        D_00321DB0[2].w40 = 0x404040;
        D_00321DB0[3].w40 = 0x404040;
        c = 0;
    }
    if (D_004A1A20[a].f12d0 & 0x20000) {
        st = 20;
        func_001118F8(D_00430658, a);
    }
    if (func_0021A938(&D_004A1A20[a]) == 0) {
        D_004A6DC0 = &D_004A18E0;
        D_004A6D94++;
        D_004A6D88 = -1;
        if (D_004A6D94 >= D_004A1A8C)
            func_00122118();
        func_00235130(-1, D_004A1A60);
        return;
    }
    if (D_004A1A20[a].f12d0 & 0x2000)
        func_00235028(&D_00321DB0[0], D_0049FD70);
    else
        D_003279F0.w8 |= 0x11000;
    if (D_004A1A20[a].f12d0 & 0x4000) {
        func_00235028(&D_00321DB0[1], D_0049FD74);
    } else {
        D_003279F0.w8 |= 0x48000;
        if (st == 0) {
            st = 1;
            c = 1;
        }
    }
    if (D_004A1A20[a].f12d0 & 0x8000)
        func_00235028(&D_00321DB0[2], D_0049FD78);
    else
        D_003279F0.w8 |= 0x82000;
    if (D_004A1A20[a].f12d0 & 0x10000) {
        func_00235028(&D_00321DB0[3], D_0049FD7C);
    } else {
        D_003279F0.w8 |= 0x24000;
        if (st == 3) {
            st = 1;
            c = 1;
        }
    }
    switch (c) {
    case 2: k = 0; m = 0x11000; break;
    case 0: k = 1; m = 0x48000; break;
    case 3: k = 3; m = 0x24000; break;
    case 1: k = 2; m = 0x82000; break;
    }
    if (D_004A6D8C == 0) {
        func_00247468(&D_003279F0, 0, &D_00321DB0[0]);
        func_00247468(&D_003279F0, 1, &D_00321DB0[1]);
        func_00247468(&D_003279F0, 2, &D_00321DB0[2]);
        func_00247468(&D_003279F0, 3, &D_00321DB0[3]);
        func_00247490(&D_003279F0, k);
    }
    func_00247580(&D_003279F0, m);
    func_0011BB28(a, 12, 160, 0, 0);
    if ((D_004A6E74 & 0x11000) && (D_004A1A20[a].f12d0 & 0x2000)) {
        if (D_003279A0[a]->id == 0 || D_004A1A54 == 0)
            func_0024CEE8(D_004A6CF4, D_004A13D4);
        func_0012D038();
        st = 2;
        func_0012AEA8(6);
        c = 2;
        D_004A6D88 = -1;
        D_004A1A48 = 0;
        D_00327830.cur = func_0021AB90(&D_004A1A20[a]);
        D_00327830.top = func_0021ABE0(&D_004A1A20[a]);
        func_00255278(5);
        func_00235130(-1, D_004A1A60);
        D_004A6E74 = 0;
        D_004A1A2C = 10;
    }
    if ((D_004A6E74 & 0x48000) && (D_004A1A20[a].f12d0 & 0x4000)) {
        if (D_003279A0[a]->id == 0 || D_004A1A54 == 0)
            func_0024CEE8(D_004A6CF4, D_004A13D4);
        func_0012D038();
        st = 0;
        func_0012AEA8(4);
        c = 0;
        D_004A6D88 = -1;
        D_004A1A4C = 0;
        D_00327880.cur = func_0021ACE0(&D_004A1A20[a]);
        D_00327880.top = func_0021AD30(&D_004A1A20[a]);
        D_004A1A48 = 0;
        func_00235130(-1, D_004A1A60);
        D_004A6E74 = 0;
        D_004A6CA8 = 1 << D_004A6D94;
        D_004A1A2C = 10;
    }
    if ((D_004A6E74 & 0x82000) && (D_004A1A20[a].f12d0 & 0x8000)) {
        if (D_003279A0[a]->id == 0 || D_004A1A54 == 0)
            func_0024CEE8(D_004A6CF4, D_004A13D4);
        func_0012D038();
        st = 1;
        func_001118F8(D_004A1948);
        c = 1;
        D_004A6D94++;
        D_004A1A44 = 12;
        D_004A6D88 = -1;
        D_004A6DC0 = &D_004A18E0;
        func_00235130(-1, D_004A1A60);
        D_004A6E74 = 0;
        D_004A1A2C = 10;
    }
    if ((D_004A6E74 & 0x24000) && (D_004A1A20[a].f12d0 & 0x10000)) {
        if (!(D_004A1A20[a].f1474 & 0x20)) {
            if (D_003279A0[a]->id == 0 || D_004A1A54 == 0)
                func_0024CEE8(D_004A6CF4, D_004A13D4);
            func_0012D038();
            st = 3;
            func_0012AEA8(7);
            c = 3;
            D_004A6D88 = -1;
            func_00235130(-1, D_004A1A60);
            v = D_004A1A20[a].f1458;
            if (v >= 0) {
                D_00327858.pages = v / 8;
                D_00327858.cur = D_004A1A20[a].f1458 % 8;
            } else {
                D_00327858.pages = 0;
                D_00327858.cur = 0;
            }
            D_004A6E74 = 0;
            D_004A6CA8 = 1 << D_004A6D94;
            D_004A1A2C = 10;
        } else {
            func_001297A0(0, 2, 0, 3, 0, 0);
        }
    }
    D_004A1A20[a].f12e4 = st;
    if (D_004A6D94 >= D_004A1A8C)
        func_00122118();
    func_0012C800(a);
    D_004A6D80 = -1;
    if (D_004A6E74 & 0x100010) {
        func_001297A0(0, 2, 0, 2, 0, 0);
        func_0021A8F8(&D_004A1A20[a]);
        D_004A6D94--;
        if (D_004A6D94 < 0)
            D_004A6D94 = 0;
        while (func_0021A938(&D_004A1A20[D_004A6D94]) == 0 && D_004A6D94 > 0)
            D_004A6D94--;
        if (D_004A6D94 < 0) {
            D_004A6D94 = 0;
            D_004A6DA0 = -1;
        } else if (a > 0) {
            func_0021A8F8(&D_004A1A20[D_004A6D94]);
        }
        func_0012AEA8(func_0024CF68(D_004A6CF4));
        D_004A6D88 = -1;
        D_004A1A44 = 12;
        func_00235130(-1, D_004A1A60);
        D_004A6DC0 = &D_004A18E0;
    }
    if (D_004A1A20[a].f1364 < 7)
        (&D_003210E0[0] + D_004A1A20[a].f1364)->b29 = c;
    func_0012C1D8(a, 0);
}
