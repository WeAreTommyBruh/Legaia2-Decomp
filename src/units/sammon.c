/* Functions of this report unit, matched by hand. */
#include "../common.h"

void func_00227F68(float);
// MATCH func_00227E58
void sammon_00227e58(void) { func_00227F68(1.0f); }

extern char D_0045AE50[]; int func_002DCE40_00229390(char *, char *, ...) __asm__("func_002DCE40");
// MATCH func_00229390
void sammon_00229390(int *o, int a, int b) { if (b < 0) { o[292] = 0; o[293] = -b; } else { o[293] = 0; o[292] = b + 1; } func_002DCE40_00229390((char *)(o + 282), D_0045AE50, a); }

int func_00223620(void *, int);
typedef struct { char p[2092]; int w2092; char q[4]; int w2100; } O__00228940;
// MATCH func_00228940
int sammon_00228940(O__00228940 *o)
{
    int d, i;
    d = func_00223620(o, o->w2092) - o->w2100;
    for (i = o->w2092 + 1; i < 31; i++) {
        if (func_00223620(o, i) >= 0) d += func_00223620(o, i);
        else i = 32;
    }
    return d;
}

typedef struct { char p[2056]; int w2056; char q[32]; int w2092; } O__002275B8_002275B8;
extern int D_004A1448;
extern int D_004A7084;
extern float D_004A059C;
int func_00223500(int, int, int);
void func_00227640(void *, void *, int);
void func_00249108_002275B8(void) __asm__("func_00249108"); void func_00249100(float, float, float); void func_002489F0(void);
void func_002486F8(float); void func_002491D8(void);
// MATCH func_002275B8
void sammon_002275b8(O__002275B8_002275B8 *o)
{
    float v[4];
    int r;
    if (o->w2056 != 0) {
        if (D_004A1448 == 2) {
            r = func_00223500(o->w2056, o->w2092, D_004A7084);
            if (r != 0) {
                func_00227640(o, v, r);
                func_00249108_002275B8();
                func_00249100(v[0], v[1], v[2]);
                func_002489F0();
                func_002486F8(D_004A059C);
                func_002491D8();
            }
        }
    }
}

int func_00223620_002288C0(int, int) __asm__("func_00223620");
static inline int inl_2288c0_002288C0(int a, int b) { return (a + b) + 0x28; }
// MATCH func_002288C0
int sammon_002288c0(char *o, int k) { int r; int off; if (k < 0x1f) { do { r = func_00223620_002288C0((int)o, k); if (r != 0) return *(int *)inl_2288c0_002288C0(k * 0x38, *(int *)(o + 0x810)); off = off + 0x38; k = k + 1; } while (k < 0x1f); } return 0; }
