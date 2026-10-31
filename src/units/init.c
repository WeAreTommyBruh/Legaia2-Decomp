/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p[16]; unsigned long long *w16; } S_0024C568;
void func_0024BF60(int, int, int, int, S_0024C568 *, int); void func_00190328_0024C568(S_0024C568 *) __asm__("func_00190328"); void func_00190420_0024C568(S_0024C568 *) __asm__("func_00190420");
// MATCH func_0024C568
int init_0024c568(int a, int b, int c, int d, S_0024C568 *s) { unsigned long long *p; func_0024BF60(a, b, c, d, s, 0); func_00190328_0024C568(s); p = s->w16; p[0] = 0; p[1] = 63; s->w16 = p + 2; func_00190420_0024C568(s); return 0; }

extern char D_0045DCF8[]; int func_001618C8(void); int func_001118F8_0024ABE0(char *, char *, int) __asm__("func_001118F8");
// MATCH func_0024ABE0
int DbgPrintFreeMem(char *name) { int r = func_001618C8(); func_001118F8_0024ABE0(D_0045DCF8, name, r / 1024); return r; }

extern int D_004A1468; extern int D_004A1464; extern void *D_004A1398; extern void *D_004A139C; extern char D_0045DBE0[]; void func_002E5B20(int); void *func_00162130(int, void *, int);
// MATCH func_0024C688
void init_0024c688(int a, int b) { func_002E5B20(0); D_004A1468 = a; D_004A1464 = b; D_004A1398 = func_00162130(b, D_0045DBE0, 1257); D_004A139C = func_00162130(b, D_0045DBE0, 1258); }

void func_002C0838(int *, int, int, int, int, int, int, int); void func_002E5B20(int); void func_002C0AF8(int *, int); void func_002C0338(int, int);
// MATCH func_0024C5C0
void init_0024c5c0(short a, short b, int c, short d, short e, short f, short g, short h)
{
    int buf[28];
    func_002C0838(buf, a, b, d, e, f, g, h);
    func_002E5B20(0);
    func_002C0AF8(buf, c);
    func_002C0338(0, 0);
}

typedef struct { char p[12]; signed char b12; unsigned char b13; char q[2]; } E__0024B210;
extern char D_0045DD78[];
void func_00239568_0024B210(void *, ...) __asm__("func_00239568");
// MATCH func_0024B210
int init_0024b210(E__0024B210 *o, int i)
{
    E__0024B210 *p = (E__0024B210 *)((i << 4) + (int)o);
    func_00239568_0024B210(D_0045DD78, i, p->b12);
    return o[p->b12].b13;
}

extern char D_0045DD48[];
void *func_0018B508_0024AE70(int, int *) __asm__("func_0018B508"); int func_0024B2A8(int *, int, int); int func_001118F8_0024AE70(char *, ...) __asm__("func_001118F8");
// MATCH func_0024AE70
int *init_0024ae70(int a, int x, int y)
{
    int buf[4];
    int *r, *p;
    unsigned i;
    i = 0;
    r = func_0018B508_0024AE70(a, buf);
    if (r[0] != 0) {
        do {
            if (func_0024B2A8(r + r[1 + i], x, y) == -1) {
                func_001118F8_0024AE70(D_0045DD48);
                return 0;
            }
            i++;
        } while (i < r[0]);
    }
    return r;
}

extern unsigned D_004A13D8;
// MATCH func_0024C640
unsigned init_0024c640(void) { unsigned u, v; u = D_004A13D8 + (D_004A13D8 * 5 + 1); v = ((u >> 16) + (u << 16)) | (((u & 0xff00) >> 8) + ((u & 0xff) << 8)); D_004A13D8 = v; return v; }
