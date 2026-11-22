/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
#include "../common.h"
typedef struct { int w0; char *p4; short h8, ha; char pc[8]; short h14, h16; char p18[12]; int w24; char p28[12]; int w34; char p38[44]; char b64; char p65[7]; short h6c; char p6e[18]; } W;
typedef struct { int w0; int cur; int pages; int top; char p10[16]; int count; int col; } M;
extern W D_00322930[];
extern M D_00327830;
extern int D_004A6D94, D_004A1A48, D_004A6E74, D_004A1A54, D_004A1A58, D_004A1A60, D_004A6D84, D_004A13D4, D_004A1A44;
extern int D_004A6CA8, D_004A6E9C, D_004A6DA4, D_004A1A8C, D_004A6D80, D_004A6CF4;
extern char *D_004A6DC0; extern char D_004A18E0;
extern char *D_00323CAC[]; extern char D_0042FBF0[];
extern char *D_004A1A20;
extern float D_0049FD90, D_0049FD94;
extern char D_0055B6C0[], D_0055B7C0[], D_00430740[];
extern int func_00254790(void);
extern void func_0011B868(int, int, int);
extern void func_0012A6D8(void);
extern void func_001297A0(int, int, int, int, int, int);
extern int func_00235028(W *, float);
extern int func_002511D0(int);
extern void func_00127000(int, int, int, int, int, int, int, int, int, float);
extern void func_00127080(float, int, int, int, int, int);
extern int func_00250D60(int);
extern void func_002191A0(char *, int);
extern void func_001302A8(char *, char *, int);
extern int func_00250AB0(int);
extern void func_00235130(int, int);
extern void func_001118F8(char *, ...);
extern int func_0012AEA8(int);
extern void func_00254990(int);
extern void func_00254E38(int);
extern int func_00251F28(int);
extern void func_00122118(void);
extern int func_0021AEE0(char *);
extern void func_00121980(int, int);
extern int func_0024CF68(int);
extern void func_0012C1D8(int, int);
extern void func_0021AC30(char *, int);
extern void func_0021AC88(char *, int);
// MATCH func_00120b78
void battle_00120b78(void)
{
    int r, l1, a, n, rows, sum, lim, d, idx, x, i, v, k, y;
    char *slot;

    a = D_004A6D94;
    n = func_00254790();
    rows = (n + 7) / 8 - 1;
    sum = D_00327830.cur + D_00327830.top;
    if (rows < 0)
        rows = 0;
    D_00327830.count = n;
    func_0011B868(160, 0, 0);
    lim = 8;
    if (n < 8)
        lim = n;
    if (D_004A1A48 == 0) {
        l1 = lim - 1;
        if (D_004A6E74 & 8) {
            if (sum < n - 1) {
                if (D_00327830.cur != l1)
                    D_00327830.cur = l1;
                else
                    D_00327830.top += 8;
            }
            D_004A6E74 = 0;
        }
        if (D_004A6E74 & 4) {
            if (sum != 0) {
                if (D_00327830.cur != 0)
                    D_00327830.cur = 0;
                else
                    D_00327830.top -= 8;
            }
            D_004A6E74 = 0;
        }
        if (D_004A6E74 & 0x11000) {
            if (sum != 0)
                D_00327830.cur--;
            D_004A6E74 = 0;
        }
        if (D_004A6E74 & 0x24000) {
            if (sum < n - 1)
                D_00327830.cur++;
            D_004A6E74 = 0;
        }
    } else {
        D_004A6E74 = 0;
        l1 = lim - 1;
    }
    if (l1 < D_00327830.cur) {
        D_00327830.top++;
        D_00327830.cur = l1;
    }
    if (D_00327830.cur < 0) {
        D_00327830.cur = 0;
        D_00327830.top--;
    }
    d = n - 8;
    if (d > 0) {
        if (d < D_00327830.top) {
            D_00327830.top = d;
            D_00327830.cur = l1;
            func_0012A6D8();
        }
    } else {
        D_00327830.top = 0;
    }
    if (D_00327830.top < 0) {
        D_00327830.top = 0;
        D_00327830.cur = 0;
        func_0012A6D8();
    }
    if (sum != D_00327830.cur + D_00327830.top)
        func_001297A0(0, 2, 0, 0, 0, 0);
    idx = D_00327830.top + D_00327830.cur;
    x = *(int *)(a * 0x1560 + D_004A1A20 + 0x1370);
    if (D_004A1A48 == 0) {
        D_00322930[14].h8 = 12;
        D_00322930[14].ha = 36;
        D_00322930[14].h14 = 240;
        D_00322930[14].h16 = 200;
        D_00322930[14].w0 = 8;
        D_00322930[14].b64 = 1;
        D_00322930[14].h6c = rows;
        if (idx != 0)
            D_00327830.pages = D_00327830.top / 8 + 1;
        else
            D_00327830.pages = 1;
        D_00322930[14].w24 = D_00327830.pages;
        func_00235028(&D_00322930[14], D_0049FD90);
        for (i = 0; i < 8; i++) {
            v = D_00327830.top + i;
            k = -1;
            if (v < n) {
                k = v;
                func_002511D0(k);
            }
            if (k >= 0)
                func_00127000(1, k, 0, 0, 32, i * 12 + 40, D_00327830.col, 0, 0x808080, 0.0f);
        }
        r = D_00327830.cur * 12 + 40;
        if (n != 0) {
            func_00127080(1.0f, 0, 146, 0, r, 128);
            D_00322930[15].h8 = 31;
            D_00322930[15].ha = 146;
            D_00322930[15].h14 = 260;
            func_002191A0(D_0055B6C0, func_00250D60(idx));
            func_001302A8(D_0055B7C0, D_0055B6C0, 256);
            D_00322930[15].p4 = D_0055B7C0;
            D_00322930[15].w0 = 0;
            func_00235028(&D_00322930[15], D_0049FD94);
            D_00322930[15].w34 |= 8;
        }
        if (D_004A6E74 & 0x200040) {
            if (n == 0)
                return;
            if (D_004A1A54 != 0 && (x = func_00250AB0(idx)) != 700) {
                func_001297A0(0, 2, 0, 3, 0, 0);
                D_004A1A58 = -1;
                D_004A1A54 += 2;
                return;
            }
            if (func_002511D0(idx) != 0 && idx < n)
                D_004A1A48 = 1;
            else
                func_001297A0(0, 2, 0, 3, 0, 0);
            func_00235130(-1, D_004A1A60);
        }
    } else {
        D_004A1A48++;
    }
    if (D_004A1A48 > 10) {
        D_004A1A48 = 0;
        D_004A6D84 = D_004A13D4;
        func_001118F8(D_00430740);
        func_001297A0(0, 2, 0, 1, 0, 0);
        D_004A1A44 = 12;
        D_004A6DC0 = &D_004A18E0;
        func_0012AEA8(3);
        if (x >= 0)
            func_00254990(x);
        x = func_00250AB0(idx);
        *(int *)(a * 0x1560 + D_004A1A20 + 0x1448) = idx;
        *(int *)(a * 0x1560 + D_004A1A20 + 0x1370) = x;
        func_00254E38(x);
        switch (y = func_00251F28(x)) {
        case 2:
        case 4:
        case 5:
            D_004A6CA8 = 1 << D_004A6D94;
            D_004A6E9C = y;
            func_0012AEA8(16);
            break;
        case 0:
            D_004A6CA8 = 1 << D_004A6D94;
            D_004A6D94++;
            if (D_004A6D94 >= D_004A1A8C)
                func_00122118();
            break;
        case 1:
            D_004A6DA4 = a;
            func_0012AEA8(13);
            D_00323CAC[0] = D_0042FBF0;
            break;
        case 3:
            D_004A6DA4 = func_0021AEE0(D_004A1A20 + a * 0x1560) - 4;
            func_00121980(a, 1);
            D_004A6CA8 = 1 << D_004A6D94;
            break;
        }
    }
    D_004A6D80 = -1;
    if (D_004A6E74 & 0x100010) {
        func_0012AEA8(func_0024CF68(D_004A6CF4));
        func_00235130(-1, D_004A1A60);
    }
    func_0012C1D8(a, 0);
    func_0021AC30(D_004A1A20 + a * 0x1560, D_00327830.cur);
    func_0021AC88(D_004A1A20 + a * 0x1560, D_00327830.top);
}
