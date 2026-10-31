/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p[84]; int v; } O_00172C68;
// MATCH func_00172C68
int FUN_00172c68(O_00172C68 *o) { if (o->v == 0 || o->v == 2) return 1; return 0; }

typedef struct { char p[112]; char *q; char p2[216]; void *vt; } O_00173A70; extern char D_0043DFD8[]; void func_00172A60(void *, int);
// MATCH func_00173A70
void FUN_00173a70(O_00173A70 *o, int f) { o->vt = D_0043DFD8; *(float *)(o->q + 200) = 1.0f; func_00172A60(o, f); }

typedef struct { char p[112]; char *q; char p2[216]; void *vt; } O_00172A60; extern char D_0043E020[]; void func_00108B80(void);
// MATCH func_00172A60
void FUN_00172a60(O_00172A60 *o, int f) { o->vt = D_0043E020; *(float *)(o->q + 200) = 1.0f; if (f & 1) func_00108B80(); }

typedef struct { char c[8]; } V8_172e00_00172E00;
typedef struct { char p[316]; V8_172e00_00172E00 d; V8_172e00_00172E00 s; } O_172e00_00172E00;
int func_00172C18(void *, int);
// MATCH func_00172E00
int FUN_00172e00(O_172e00_00172E00 *o) { if (func_00172C18(o, 32)) o->d = o->s; return 0; }

typedef struct { char c[8]; } V8_172e40_00172E40;
typedef struct { char p[56]; short adj; short pad; void (*fn)(void *, int); } VT_172e40_00172E40;
typedef struct { char p[124]; int w; char p2[188]; V8_172e40_00172E40 x; V8_172e40_00172E40 y; VT_172e40_00172E40 *vt; } O_172e40_00172E40;
extern V8_172e40_00172E40 D_004A3150[2], D_004A3148[2]; void func_00172BE8(void *, int);
// MATCH func_00172E40
void FUN_00172e40(O_172e40_00172E40 *o) { o->w = 0; o->vt->fn((char *)o + o->vt->adj, 4); func_00172BE8(o, 4); o->x = D_004A3150[0]; o->y = D_004A3148[0]; }

typedef struct { char c[8]; } V8_001731E8;
typedef struct { char p[32]; short adj; short pad; void (*fn)(void *); } VT_001731E8;
typedef struct { char p[80]; float f80; char q[24]; float f108; char r[204]; V8_001731E8 v; char s[8]; VT_001731E8 *vt; } X_001731E8;
extern char D_00335FF0[], D_00336000[]; extern V8_001731E8 D_004A3180[2]; void func_001734F0(X_001731E8 *, float, float); void func_00172DD0(X_001731E8 *); void func_00173468(X_001731E8 *, char *, char *);
// MATCH func_001731E8
int FUN_001731e8(X_001731E8 *o) { o->vt->fn((char *)o + o->vt->adj); func_001734F0(o, 0.0f, -o->f80); if (o->f108 == 30.0f) { func_00172DD0(o); o->v = D_004A3180[0]; func_00173468(o, D_00335FF0, D_00336000); } return 0; }

typedef struct { char c[8]; } V8_00173288;
typedef struct { char p[32]; short adj; short pad; void (*fn)(void *); } VT_00173288;
typedef struct { char p[80]; float f80; char q[24]; float f108; char r[204]; V8_00173288 v; char s[8]; VT_00173288 *vt; } X_00173288;
extern char D_00336010[], D_00336020[]; extern V8_00173288 D_004A3188[2]; void func_001734F0_00173288(X_00173288 *, float, float) __asm__("func_001734F0"); void func_00172DD0_00173288(X_00173288 *) __asm__("func_00172DD0"); void func_00173468_00173288(X_00173288 *, char *, char *) __asm__("func_00173468");
// MATCH func_00173288
int FUN_00173288(X_00173288 *o) { o->vt->fn((char *)o + o->vt->adj); func_001734F0_00173288(o, 0.0f, o->f80); if (o->f108 == 30.0f) { func_00172DD0_00173288(o); o->v = D_004A3188[0]; func_00173468_00173288(o, D_00336010, D_00336020); } return 0; }

typedef struct { char c[8]; } V8_00173328;
typedef struct { char p[32]; short adj; short pad; void (*fn)(void *); } VT_00173328;
typedef struct { char p[80]; float f80; char q[24]; float f108; char r[204]; V8_00173328 v; char s[8]; VT_00173328 *vt; } X_00173328;
extern char D_00336010_00173328[] __asm__("D_00336010"), D_00336020_00173328[] __asm__("D_00336020"); extern V8_00173328 D_004A3158[2]; void func_001734F0_00173328(X_00173328 *, float, float) __asm__("func_001734F0"); void func_00172DD0_00173328(X_00173328 *) __asm__("func_00172DD0"); void func_00173468_00173328(X_00173328 *, char *, char *) __asm__("func_00173468");
// MATCH func_00173328
int FUN_00173328(X_00173328 *o) { o->vt->fn((char *)o + o->vt->adj); func_001734F0_00173328(o, -o->f80, 0.0f); if (o->f108 == 30.0f) { func_00172DD0_00173328(o); o->v = D_004A3158[0]; func_00173468_00173328(o, D_00336010_00173328, D_00336020_00173328); } return 0; }

typedef struct { char c[8]; } V8_001733C8;
typedef struct { char p[32]; short adj; short pad; void (*fn)(void *); } VT_001733C8;
typedef struct { char p[80]; float f80; char q[24]; float f108; char r[204]; V8_001733C8 v; char s[8]; VT_001733C8 *vt; } X_001733C8;
extern char D_00335FF0_001733C8[] __asm__("D_00335FF0"), D_00336000_001733C8[] __asm__("D_00336000"); extern V8_001733C8 D_004A3158_001733C8[2] __asm__("D_004A3158"); void func_001734F0_001733C8(X_001733C8 *, float, float) __asm__("func_001734F0"); void func_00172DD0_001733C8(X_001733C8 *) __asm__("func_00172DD0"); void func_00173468_001733C8(X_001733C8 *, char *, char *) __asm__("func_00173468");
// MATCH func_001733C8
int FUN_001733c8(X_001733C8 *o) { o->vt->fn((char *)o + o->vt->adj); func_001734F0_001733C8(o, o->f80, 0.0f); if (o->f108 == 30.0f) { func_00172DD0_001733C8(o); o->v = D_004A3158_001733C8[0]; func_00173468_001733C8(o, D_00335FF0_001733C8, D_00336000_001733C8); } return 0; }

typedef struct { char p[332]; char *w332; int w336; char q[8]; int w348, w352, w356, w360; } O_001739F8;
extern char D_0043DFD8_001739F8[] __asm__("D_0043DFD8"); void func_00172998(O_001739F8 *, int, int); void func_00173AC0(O_001739F8 *);
// MATCH func_001739F8
O_001739F8 *FUN_001739f8(O_001739F8 *o, int x, int c, int d) { func_00172998(o, x, 0); o->w332 = D_0043DFD8_001739F8; o->w336 = d; o->w348 = c != 5 ? 5 : 0; o->w352 = 0; o->w356 = 0; o->w360 = 0; func_00173AC0(o); return o; }

typedef struct { char p[16]; float v16[1]; } M0_00173468;
typedef struct { char p[16]; char q[96]; int w112; char r[196]; int w312; } O_00173468;
extern char D_00343010_00173468[] __asm__("D_00343010"); void func_0018F368_00173468(float *, char *, int) __asm__("func_0018F368"); void func_0018F050(float *, int, float *); void func_001E2C60(char *, int, float *, float *);
// MATCH func_00173468
void FUN_00173468(O_00173468 *o, int b, int c) { float m0[4]; float m1[4]; func_0018F368_00173468(m0, (char *)o + 16, b); func_0018F050(m0, o->w112 + 32, m0); func_0018F050(m1, o->w112 + 64, c); func_001E2C60(D_00343010_00173468, o->w312, m0, m1); }

typedef struct { char c[8]; } V8_00172B30;
typedef struct { char p[40]; short adj; short pad; void (*fn)(void *); char q[8]; short adj2; short pad2; void (*fn2)(void *, int); } VT_00172B30;
typedef struct { char p[316]; V8_00172B30 v, v2; VT_00172B30 *vt; } O_00172B30;
extern V8_00172B30 D_004A3150_00172B30[2] __asm__("D_004A3150"), D_004A3158_00172B30[2] __asm__("D_004A3158"); void func_00172BE8(void *, int); void func_00172C00(void *, int);
// MATCH func_00172B30
void FUN_00172b30(O_00172B30 *o) { o->vt->fn((char *)o + o->vt->adj); o->vt->fn2((char *)o + o->vt->adj2, 0); func_00172BE8(o, 516); func_00172C00(o, 32); o->v = D_004A3150_00172B30[0]; o->v2 = D_004A3158_00172B30[0]; }

extern char D_004A3190[]; int func_00130FD8(int); void func_00239568_00174060(char *, int, int, int) __asm__("func_00239568");
// MATCH func_00174060
void FUN_00174060(int *o) { int t = o[89]; if (t > 0 && o[90] != 0) { int w; o[89] = t - 1; w = func_00130FD8(o[90]); func_00239568_00174060(D_004A3190, 160 - w / 2, 44, o[90]); } }

typedef struct { char c[8]; } V8_00173BE0;
extern V8_00173BE0 D_004A3150_00173BE0[3] __asm__("D_004A3150"); extern char D_0043D7C0[];
typedef struct { char p[56]; short adj56; short pad56; void (*fn60)(void *, int); } VT_173be0_00173BE0;
typedef struct { char p[200]; float f200; } T2_173be0_00173BE0;
typedef struct { char p0[112]; T2_173be0_00173BE0 *w112; char p1[200]; V8_00173BE0 v316; V8_00173BE0 v324; VT_173be0_00173BE0 *vt; int w336; char p2[8]; int w348; int w352; int w356; char *w360; } O_173be0_00173BE0;
void func_00172BE8(void *, int); void func_00172C00(void *, int);
// MATCH func_00173BE0
void FUN_00173be0(O_173be0_00173BE0 *o) { float t = (float)o->w336; o->w360 = D_0043D7C0; o->w352 = o->w348; o->w356 = 50; t = t * 0.75f; o->w336 = (int)t; o->vt->fn60((char *)o + o->vt->adj56, 0); func_00172BE8(o, 516); func_00172C00(o, 32); o->w112->f200 = 1.0f; o->v324 = o->v316; o->v316 = D_004A3150_00173BE0[0]; }

// MATCH func_00173980
void FUN_00173980(char *o) {
    int idx, d, dl;
    long e;
    void (*fn)(void *);
    idx = *(short *)(o + 318);
    if (idx > 0) {
        long *vt = *(long **)(o + *(short *)(o + 320));
        e = vt[idx - 1];
        fn = (void (*)(void *))(e >> 32);
    } else fn = *(void (**)(void *))(o + 320);
    dl = *(short *)(o + 316);
    d = idx > 0 ? (short)e + dl : dl;
    fn(o + d);
}
