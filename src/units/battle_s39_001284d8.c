#include "../common.h"
// compiler: 990721-r5900
typedef struct { char p[0x14c]; int f14c; } P94;
typedef struct { unsigned long a, b; } V16;
extern V16 D_00431450;
typedef struct { char p[0x20]; int f20; int f24; char p28[0xc]; int f34; } S90;
extern int D_004A6D60, D_004A6D28, D_004A1A60, D_004A6E30, D_004A1A54, D_004A1A50, D_004A6E74, D_004A6D24, D_004A6C50, D_004A6DB4;
extern int D_004A6E60, D_004A17B0, D_004A6E64, D_004A6E48, D_004A1460, D_004A1A74, D_004A6C5C, D_004A1AA8, D_004A6CE8, D_004A12A4, D_004A1668, D_004A1510;
extern unsigned D_004A6C88;
extern unsigned long D_004A12D8;
extern P94 *D_004A1A94;
extern S90 D_00326F90;
extern int D_00314CC8[];
extern int D_00425514[], D_00425510[];
extern char D_0053F980[], D_004A1938[], D_00431460[], D_00343028[], D_00343010[], D_004A1550;
extern char D_00431478[], D_00431488[], D_004314A0[], D_004314B0[], D_004314C0[], D_004314D0[], D_004314E0[], D_004314F0[], D_00431508[], D_00431518[], D_00431528[], D_00431538[], D_00431548[], D_00431558[];
extern float D_0049FE20, D_0049FE24, D_0049FE28, D_0049FE2C;
extern void *func_002DC804(void *, int, int);
extern void func_00235130(int, int);
extern void func_001283F0(void);
extern void func_00181140(char *);
extern void func_0027C3E0(void);
extern void func_0012ABF0(int);
extern void func_0012A7F8(float, int);
extern int func_00127210(void);
extern int func_00127F30(int, int, int, int, int, int);
extern void func_00222AB0(S90 *);
extern void func_00237938(int, int, int, int, int, int, int, int, int, char *);
extern void func_0011BC88(float, float, float, float, float, float, float, int);
extern void func_00124A48(float, float, float, float, int);
extern void func_0012AC10(void);
extern int func_00222AE0(S90 *, int);
extern int func_00222858(S90 *);
extern int func_001B4738(int, int, int, int);
extern int func_002194C0(P94 *);
extern void func_002194B0(P94 *);
extern int func_0010E240(char *);
extern void func_0012C960(void);
extern void func_002A3FE8(void *);
extern void func_002A4100(void *);
extern void func_002A3FF0(void *, int);
extern void func_00239568(char *);
extern void func_00261018(void);
extern int func_00126058(void);
extern int func_001E3A00(char *, int *, char *, int);
extern int func_001118F8(char *, ...);
extern void func_001E3E38(char *, int, int);
extern void func_001E28A0(char *, int, void *, void *);
extern void func_002206E0(int, int);
extern void func_0012D388(char *);
extern int func_00294220(int);
extern void func_00220B88(S90 *);
extern void func_002224A8(int, int, int, int);
extern void func_001260B0(void);
// MATCH func_001284D8
void battle_001284d8(void)
{
    char buf[16];
    V16 v;
    int b50[1];
    int res;
    int r;
    int n;

    D_004A6D60 = 0;
    func_002DC804(buf, 0, 16);
    v = D_00431450;
    if (D_004A6D28 == 0) {
        func_00235130(-1, D_004A1A60);
        func_001283F0();
        func_00181140(D_0053F980);
        D_004A1A94->f14c = 0;
        D_004A6E30 = 0;
    }
    func_0027C3E0();
    func_0012ABF0(2);
    if (D_004A1A54 != 0 && !(D_004A1A50 & 0x1000)) {
        if (D_004A6E74 & 0x200040)
            D_004A1A50 |= 0x1000;
        return;
    }
    if (D_004A1A50 & 0x10) {
        switch (D_004A6D28) {
        case 0:
            D_004A6D28 = 1;
            func_0012A7F8(-1.0f, 1);
            if (func_00127210() != 0)
                func_00127F30(0, 2, 0xffffff, 120, 120, -1);
            break;
        case 1:
            if (func_00127210() != 0) {
                func_00222AB0(&D_00326F90);
                func_00237938(0, 0, 120, 255, 255, 160, 112, 0, 0, D_004A1938);
                func_0012A7F8(-1.0f, 1);
            } else {
                func_00237938(0, 0, 120, 255, 255, 160, 112, 0, 0, D_00431460);
                func_0011BC88(60.0f, (0.0799999982f), (3.1099999f), 0.0f, -400.0f, (-6600.0f), (-66400.0f), 0x2500);
                func_00124A48(0.0f, 0.0f, 0.0f, 0.0f, 0x2502);
                func_0012A7F8(-1.0f, 0);
            }
            if (++D_004A6D24 <= 120)
                goto done;
            goto fail;
        }
        goto done;
    }
    if (func_00127210() != 0) {
        if (D_004A1A50 & 8) {
            func_00235130(-1, D_004A1A60);
            func_0012AC10();
            D_004A6C50 = 1;
            switch (func_00222AE0(&D_00326F90, D_004A6DB4)) {
            case 0:
                D_004A6D28 = 1;
                break;
            case 20:
                goto fail;
            }
        } else {
            func_0012AC10();
            switch (D_004A6D28) {
            case 0:
                D_004A6D28 = 1;
                func_00222AB0(&D_00326F90);
                break;
            case 1:
                if (func_00222858(&D_00326F90) != 0) {
                fail:
                    D_004A6D28 = 10;
                    D_004A1A50 |= 0x4020;
                    goto done;
                }
                break;
            }
        }
        func_0012A7F8(-1.0f, 1);
        goto done;
    }
    if (D_004A1A50 & 8) {
        if (D_004A6E60 != 0) {
            func_0012AC10();
            if (++D_004A6E64 < 90)
                return;
            D_004A6E64 = 90;
        }
        if (D_004A17B0 == 0) {
            switch (D_004A6D28) {
            case 0:
                func_001B4738(4, 1, 1, 0);
                func_00127F30(0, 2, 0xffffff, 120, 120, -1);
                D_004A6D28++;
                break;
            case 1:
                if (func_001B4738(4, 1, 1, 1) == 0) {
                    D_004A6D28 = 10;
                    D_004A1A50 |= 0xa0;
                }
                break;
            }
        } else switch (D_004A6D28) {
        case 0:
            D_004A6E48 = 1;
            D_004A6D28 = 1;
            D_004A6D24 = 0;
            break;
        case 1:
            if (++D_004A6D24 > 20) {
                D_004A6D24 = 20;
                if (func_002194C0(D_004A1A94) != 0 && func_0010E240(D_00343028) == 0) {
                    func_002194B0(D_004A1A94);
                    func_00127F30(0, 2, 0xffffff, 60, 20, -1);
                    func_0012C960();
                    D_004A6D24 = 0;
                    D_004A6D28++;
                    func_002A3FE8(b50);
                    func_002A4100(b50);
                    func_002A3FF0(b50, 2);
                } else if (D_004A1460 != 0) {
                    if (func_002194C0(D_004A1A94) == 0)
                        func_00239568(D_00431478);
                    if (func_0010E240(D_00343028) != 0)
                        func_00239568(D_00431488);
                }
            }
            break;
        case 2:
            if (++D_004A6D24 > 60) {
                D_004A6D28 = 10;
                D_004A1A74 = 7;
            }
            break;
        }
    } else {
        func_0012A7F8(-1.0f, 1);
        if (func_00127210() == 0) {
            switch (D_004A6D28) {
            case 0:
                D_004A6D28 = 1;
                break;
            case 1:
                if (func_002194C0(D_004A1A94) != 0) {
                    func_002194B0(D_004A1A94);
                    if (!(D_00425514[0] & 0x8000))
                        func_00261018();
                    D_004A6D28++;
                }
                break;
            case 2:
                if (D_00425514[0] & 0x8000)
                    goto quit;
                if (func_00126058() == 0)
                    D_004A6C88 = 0;
                D_004A6D28++;
                break;
            case 3:
                r = func_001E3A00(D_00343010, &res, D_004314A0, 0);
                if (res == 1) {
                    func_001118F8(D_004314B0);
                    func_001E3E38(D_00343010, r, 0);
                    func_001E28A0(D_00343010, r, &v, buf);
                    D_004A6D28++;
                }
                if (res < 0) {
                    func_001118F8(D_004314C0);
                    D_004A6D28 = 10;
                }
                break;
            case 4:
                func_0012AC10();
                if (++D_004A6C88 > 240) {
                    D_004A6C88 = 240;
                    if (D_004A12D8 & 0x200040) {
                    quit:
                        D_004A6D28 = 10;
                        D_004A1A50 |= 0x4020;
                    }
                }
                break;
            }
        }
    }
    if (D_004A1A50 & 0x400) {
        D_004A1A50 |= 0x4020;
        D_004A6D28 = 10;
    }
done:
    if (D_004A6D28 == 10) {
        func_002206E0(D_004A1AA8, 0);
        func_002206E0(D_004A1AA8, 1);
        D_004A6C5C++;
    }
    if (D_004A6C5C < 6)
        return;
    D_004A6C5C = 5;
    if (D_004A1A74 != 7)
        return;
    if (func_00127210() != 0) {
        func_0012D388(&D_004A1550);
        if (D_004A1A50 & 0x10) {
            func_001118F8(D_004314D0, D_00326F90.f34);
            func_00294220(D_00326F90.f34);
            D_004A6CE8 = D_00326F90.f20;
        } else if (D_004A1A50 & 8) {
            if ((func_00127210() == 4 || func_00127210() == 5) && D_00314CC8[0] == 177) {
                func_001118F8(D_004314E0);
                D_00425510[1] |= 0x100;
            }
            { register int m __asm__("$2") = D_00326F90.f20;
            register int k __asm__("$5");
            register int c __asm__("$2");
            register int l __asm__("$6") = D_00326F90.f24;
            D_004A6CE8 = m;
            k = m + 1;
            D_00326F90.f20 = k;
            c = k < l;
            if (c) {
                func_001118F8(D_004314F0);
                D_004A12A4 = 10;
            end:
                func_001260B0();
                return;
            }}
            func_001118F8(D_00431508);
            func_00294220(D_00326F90.f34);
            func_00220B88(&D_00326F90);
            func_002224A8(0, 0, 0, 0);
        } else {
            func_001118F8(D_00431518);
            D_004A6CE8 = D_00326F90.f20;
        }
    }
    if (D_004A6E48 != 0) {
        D_004A12A4 = 26;
        goto end;
    }
    if (D_004A1A50 & 1) {
        if (D_004A1A50 & 8) {
            D_004A12A4 = 14;
            func_001118F8(D_00431528);
        } else if (D_00425514[0] & 0x8000) {
            D_004A12A4 = 14;
            func_001118F8(D_00431538);
        } else if (D_004A1668 == 0 || (D_004A1A50 & 0x10)) {
            D_004A12A4 = 14;
        } else {
            func_001118F8(D_00431548);
            D_004A12A4 = 0;
            D_004A1510 = 1;
        }
        goto end;
    }
    func_001118F8(D_00431558);
    D_004A12A4 = 18;
    func_001260B0();
}
