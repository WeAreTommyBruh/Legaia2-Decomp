/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p[16]; int w16, w20, w24; char q[116]; int w144; char r[192]; int w340; char s[50]; signed char b394; char t[17]; int w412; } O__00246CE0;
extern int D_004A1384, D_004A7204_00246CE0 __asm__("D_004A7204");
extern char D_0045D540[];
void *func_0024A1C8(int); void func_00246340(O__00246CE0 *); int func_001118F8_00246CE0(char *, ...) __asm__("func_001118F8");
// MATCH func_00246CE0
O__00246CE0 *work_00246ce0(int a, int b, int c, int d)
{
    O__00246CE0 *r = func_0024A1C8(a);
    if (r == 0) {
        D_004A1384 = D_004A1384 + 1;
        func_001118F8_00246CE0(D_0045D540, D_004A1384);
        return 0;
    }
    r->w144 = 0;
    r->w340 = 0;
    D_004A7204_00246CE0 = D_004A7204_00246CE0 + 1;
    r->w412 = 0;
    r->b394 = 0;
    func_00246340(r);
    r->w16 = b;
    r->w20 = c;
    r->w24 = d;
    return r;
}

int func_00246D88_00246C90(int, int) __asm__("func_00246D88");
// MATCH func_00246C90
int work_00246c90(float *v, int a, int b)
{
    int r = func_00246D88_00246C90(a, b);
    if (r != 0) return 0;
    *(float *)(r + 32) = v[0];
    *(float *)(r + 36) = v[1];
    *(float *)(r + 40) = v[2];
    return 0;
}

extern int * D_004A13F0_246C00 __asm__("D_004A13F0");
void func_002468F8_246C00(void *, int) __asm__("func_002468F8");
// MATCH func_00246C00
void work_00246c00(void) { int *n = D_004A13F0_246C00; int *c; int ok; while (n != 0) { c = n; ok = 0; n = (int *)c[3]; if ((c[6] & 10) == 0) { if (c[5] != 0 && (c[6] & 0x20000) != 0) { ((void (*)(int *))c[5])(c); ok = 1; } } if (!ok) func_002468F8_246C00(c, 0); } }

void func_00249108_2468F8(void) __asm__("func_00249108"); void func_00249100_2468F8(float, float, float) __asm__("func_00249100"); void func_00248CF8_2468F8(int, float) __asm__("func_00248CF8");
void func_0018F3D8_2468F8(char *, unsigned, unsigned) __asm__("func_0018F3D8"); void func_0022D470_2468F8(char *, char *, unsigned) __asm__("func_0022D470"); void func_002491D8_2468F8(void) __asm__("func_002491D8");
// MATCH func_002468F8
void work_002468f8(char *o, int a) { char buf[64]; if (a == 0) func_00249108_2468F8(); func_00249100_2468F8(*(float *)(o + 32), *(float *)(o + 36), *(float *)(o + 40)); func_00248CF8_2468F8(0, *(float *)(o + 64)); func_00248CF8_2468F8(1, *(float *)(o + 68)); func_00248CF8_2468F8(2, *(float *)(o + 72)); func_0018F3D8_2468F8(buf, 0x70003c00, 0x70003f80); func_0022D470_2468F8(o + 80, buf, 0x70003e00); if (a == 0) func_002491D8_2468F8(); }

void func_00246140_246AD0(void *) __asm__("func_00246140");
void func_00246DC0_246AD0(void *) __asm__("func_00246DC0");
int func_001114E8_246AD0(void) __asm__("func_001114E8");
void func_0022F268_246AD0(void *) __asm__("func_0022F268");
// MATCH func_00246AD0
void work_00246ad0(int *o) { int *n = (int *) (*o); int *c; unsigned int new_var; unsigned u; while (n != 0) { c = n; u = c[6]; n = (int *) (*c); new_var = 6; c[6] = c[6] & 0xfffffbff; if ((c[6] & 8) != 0) { if ((c[6] & 0x2000000) != 0) { func_00246140_246AD0(c); func_00246DC0_246AD0(c); } u = c[new_var]; c[6] = u | 0x2000000; } else if (c[4] != 0) { ((void (*)(int *)) c[4])(c); if (func_001114E8_246AD0() == 0) { func_0022F268_246AD0(c); } } }  }

