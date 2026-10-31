/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern char D_00342CD0[]; extern char D_002F3A00[], D_002F6520[]; void func_00190238(void *, int, void *, int, int);
// MATCH func_0017A388
void FUN_0017a388(void) { func_00190238(D_00342CD0, 0, D_002F3A00, (D_002F6520 - D_002F3A00) >> 4, 0); }

float func_0018EAF8(void);
// MATCH func_00179098
int FUN_00179098(float a, float b) { if (func_0018EAF8() <= a + b) return 1; return 0; }

void *func_002A4F30(void *);
// MATCH func_00179FD8
void *FUN_00179fd8(void *o) { func_002A4F30(o); return o; }

void func_0018F0B0(float *, int, int); float func_0018ECB8(float *, float *); void func_0018EF60(float, int, int, float *);
// MATCH func_001795A0
int FUN_001795a0(int a, int b, int c, int d) { float v0[4]; float v1[4]; float n, m; func_0018F0B0(v0, c, b); func_0018F0B0(v1, a, b); n = func_0018ECB8(v1, v0); m = func_0018ECB8(v0, v0); func_0018EF60(n / m, d, b, v0); return 1; }

void func_0018F0B0(float *, int, int); void func_0018EC78_00179648(float *, float *, float *) __asm__("func_0018EC78"); float func_0018EB28(float *);
// MATCH func_00179648
float FUN_00179648(int a, int b, int c) { float v0[4]; float v1[4]; float v2[4]; float n, m; func_0018F0B0(v0, c, b); func_0018F0B0(v1, a, b); func_0018EC78_00179648(v2, v1, v0); n = func_0018EB28(v2); m = func_0018EB28(v0); return n / m; }

float func_00178BB8(int, int, int);
// MATCH func_00178BE8
int FUN_00178be8(int p, int q, int r, int s) { float x = func_00178BB8(p, r, s); float y = func_00178BB8(q, r, s); if (x == 0.0f && y == 0.0f) return 0; if (x == y) return 1; return -1; }

float func_00178BB8(int, int, int);
void func_0018F110(float, int, int, int);
// MATCH func_00178F18
int FUN_00178f18(int a, int b, int c, int d, int e, float *f) {
    float x, y, t;
    x = func_00178BB8(a, c, d);
    y = func_00178BB8(b, c, d);
    t = x - y;
    if (t == 0.0f) return 0;
    t = x / t;
    func_0018F110(t, e, a, b);
    if (f != 0) *f = t;
    return 1;
}

float func_00178BB8(int, int, int);
void func_0018F110(float, int, int, int);
// MATCH func_00178E38
int FUN_00178e38(int a, int b, int c, int d, int e, float *f) {
    float x, y, t;
    x = func_00178BB8(a, c, d);
    y = func_00178BB8(b, c, d);
    t = x - y;
    if (t == 0.0f) return 0;
    if (x * y > 0.0f) return 0;
    t = x / t;
    func_0018F110(t, e, a, b);
    if (f != 0) *f = t;
    return 1;
}

typedef struct { char c[16]; } V16_00178D40;
void func_0018F110_00178D40(float, void *, void *, void *) __asm__("func_0018F110");
// MATCH func_00178D40
int FUN_00178d40(float p1, float p2, V16_00178D40 *a, V16_00178D40 *b, V16_00178D40 *c, float *f) {
    float t = p1 - p2;
    if (t == 0.0f || 0.0f < p1 * p2) return 0;
    if (p1 == 0.0f) {
        *c = *a;
        t = 0.0f;
    } else if (p2 == 0.0f) {
        *c = *b;
        t = 1.0f;
    } else {
        t = p1 / t;
        func_0018F110_00178D40(t, c, a, b);
    }
    if (f != 0) *f = t;
    return 1;
}

long func_00179870(int, int, float, int, int, int, int, int);
// MATCH func_00179BA0
int FUN_00179ba0(float f, int a, int b, int c0, int c1, int c2, int p9, int p10, int p11) {
    int st[4];
    int i, idx, r;
    st[0] = c0;
    st[1] = c1;
    st[2] = c2;
    idx = 2;
    r = 0;
    for (i = 0; i < 3; i++) {
        if (func_00179870(a, b, f, st[i], st[idx], p9, p10, p11) != 0) r = 1;
        idx = i;
    }
    return r;
}
