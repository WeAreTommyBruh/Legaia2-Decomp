#include "../common.h"
// compiler: 991111-01
// cflags: -fno-gcse
typedef struct { int f0, f4, f8; } A_1140C0;
typedef struct { int f0, n; } C_1140C0;
extern int D_004A1628, D_004A1638, D_004A1610;
extern unsigned D_004A12C8;
extern char D_00321588[], D_00321300[], D_00321640[];
int func_00192948(A_1140C0 *); int func_001929F8(A_1140C0 *); int func_00192AC8(A_1140C0 *);
void func_00114358(void); void func_00195288(void); void func_00191070(char *); void func_00191068(char *);
void func_00111968(void); void func_00192938(char *);
int func_00190DC8(char *, int *); int func_00195430(C_1140C0 *, int, int); void func_00190DF8(char *, int);
int func_00190E40(char *, int *); int func_002C1CF0(A_1140C0 *, int, int, char *, int); void func_00190E88(char *, int);
void func_001143B8(void); int func_00194900(char *); int func_00114360(void); void func_00195248(int);
// MATCH func_001140C0
int FUN_001140c0(A_1140C0 *a, char *b, C_1140C0 *c)
{
    int done = 0;
    unsigned prev = 0, v;
    int n, m, r, t;
    int s[2];
    n = c->n;
    m = n;
    while (n >= 5 && func_00192948(a) != 3) {
        if (D_004A1628 >= 3990) {
            D_004A1638 = 64;
            func_00192938(D_00321588);
        } else {
            D_004A1638 = 0;
            func_00111968();
            v = D_004A12C8;
            D_004A1638 = v;
            { register unsigned ch __asm__("$2") = (prev ^ v) & v & 0x860; prev = v;
            if (ch != 0 && a->f8 > 10)
                func_00192938(D_00321588); }
        }
        r = func_00190DC8(b, &s[0]);
        if (m > 0 && r > 0xffff) {
            t = func_00195430(c, s[0], 0x10000);
            m -= t;
            func_00190DF8(b, t);
        }
        func_00114358();
        t = func_00190E40(b, &s[1]);
        if (t > 0) {
            t = func_002C1CF0(a, s[1], t, b, *(int *)(b + 0x50008));
            n -= t;
            func_00190E88(b, t);
        }
        func_001143B8();
        if (!done && func_00194900(D_00321300) != 0 && func_00114360() != 0) {
            func_00195248(1);
            if (D_004A1610 != 0) func_00191068(D_00321640);
            done = 1;
        }
    }
    while (func_001929F8(a) == 0) func_00114358();
    while (func_00192AC8(a) == 0 && func_00192948(a) != 3) func_00114358();
    func_00195288();
    if (D_004A1610 != 0) func_00191070(D_00321640);
    return 1;
}
