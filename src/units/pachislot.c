/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char pad[24]; int a; int b; } S_00164A20;
// MATCH func_00164A20
int pachislot_00164a20(S_00164A20 *s) { return !(s->a < s->b); }

typedef struct { char c[8]; } V8_00165D78;
typedef struct { char pad[68]; V8_00165D78 v; } S_00165D78;
extern V8_00165D78 D_004A2CF8[2];
int func_00164A00(void *);
// MATCH func_00165D78
void pachislot_00165d78(S_00165D78 *s) { if (func_00164A00(s) != 0) s->v = D_004A2CF8[0]; }

typedef struct { char c[8]; } V8_0016A780;
typedef struct { char pad[544]; V8_0016A780 v; } S_0016A780;
extern V8_0016A780 D_004A2EE8[2];
int func_00168AB8(void *);
// MATCH func_0016A780
int pachislot_0016a780(S_0016A780 *s) { func_00168AB8(s); s->v = D_004A2EE8[0]; return 0; }

// MATCH func_00165F08
void pachislot_00165f08(S_00165D78 *s) { if (func_00164A00(s) != 0) s->v = D_004A2CF8[0]; }

// MATCH func_00166188
void pachislot_00166188(S_00165D78 *s) { if (func_00164A00(s) != 0) s->v = D_004A2CF8[0]; }

// MATCH func_00166388
void pachislot_00166388(S_00165D78 *s) { if (func_00164A00(s) != 0) s->v = D_004A2CF8[0]; }

extern long long D_004A12D8; void func_002DC804(void *, int, int);
// MATCH func_0016ADC8
int pachislot_0016adc8(char *s) { if (D_004A12D8 & 0x200040) func_002DC804(s + 560, 0, 8); return 0; }

typedef struct { char c[8]; } V8_00164A80;
typedef struct { int w[4]; } P_00164A80; typedef struct { P_00164A80 *p; char p1[20]; int a; int b; char p2[8]; V8_00164A80 v; } O_00164A80; extern V8_00164A80 D_004A2CE8[2];
// MATCH func_00164A80
void pachislot_00164a80(O_00164A80 *o) { o->a += o->p->w[3]; if (o->a >= o->b) { o->a = o->b; o->v = D_004A2CE8[0]; } }

typedef struct { char c[8]; } V8_0016AD90;
typedef struct { char p[560]; V8_0016AD90 v; } O_0016AD90; extern V8_0016AD90 D_004A2F10[2]; extern long long D_004A12D8;
// MATCH func_0016AD90
int pachislot_0016ad90(O_0016AD90 *o) { if (D_004A12D8 & 0x200040) o->v = D_004A2F10[0]; return 0; }

typedef struct { char c[8]; } V8_00164A48;
typedef struct { char p[32]; int w; char p2[4]; V8_00164A48 v; } O_00164A48; extern V8_00164A48 D_004A2CE0[2];
// MATCH func_00164A48
void pachislot_00164a48(O_00164A48 *o) { if (o->w >= 0) { o->w--; if (o->w == -1) o->v = D_004A2CE0[0]; } }

typedef struct { char c[8]; } V8_0016AC30;
typedef struct { char p[464]; int w; char p2[40]; int f; char p3[32]; V8_0016AC30 v; } O_0016AC30; extern V8_0016AC30 D_004A2E50[2];
// MATCH func_0016AC30
int pachislot_0016ac30(O_0016AC30 *o) { o->f = 1; if (o->w-- <= 0) { o->w = 0; o->v = D_004A2E50[0]; o->f = 0; } return 0; }

typedef struct { char c[8]; } V8_00165EA8;
typedef struct { char p[56]; short adj; short pad; void (*fn)(void *); } VT_00165EA8;
typedef struct { char p[48]; VT_00165EA8 *vt; int w52; char p2[12]; V8_00165EA8 v; } O_00165EA8;
extern V8_00165EA8 D_004A2D18[2]; int func_00164A20(void *); void func_00164A38(void *, int);
// MATCH func_00165EA8
void pachislot_00165ea8(O_00165EA8 *o) { if (func_00164A20(o)) { o->v = D_004A2D18[0]; func_00164A38(o, o->w52); o->vt->fn((char *)o + o->vt->adj); } }

typedef struct { char c[8]; } V8_00166128;
typedef struct { char p[56]; short adj; short pad; void (*fn)(void *); } VT_00166128;
typedef struct { char p[48]; VT_00166128 *vt; int w52; char p2[12]; V8_00166128 v; } O_00166128;
extern V8_00166128 D_004A2D40[2]; int func_00164A20(void *); void func_00164A38(void *, int);
// MATCH func_00166128
void pachislot_00166128(O_00166128 *o) { if (func_00164A20(o)) { o->v = D_004A2D40[0]; func_00164A38(o, o->w52); o->vt->fn((char *)o + o->vt->adj); } }

typedef struct { char c[8]; } V8_00166328;
typedef struct { char p[56]; short adj; short pad; void (*fn)(void *); } VT_00166328;
typedef struct { char p[24]; int a, b; char p2[16]; VT_00166328 *vt; int w52; char p3[12]; V8_00166328 v; } O_00166328;
extern V8_00166328 D_004A2D50[2]; void func_00164A38(void *, int);
// MATCH func_00166328
void pachislot_00166328(O_00166328 *o) { o->a = -o->b; o->v = D_004A2D50[0]; func_00164A38(o, o->w52); o->vt->fn((char *)o + o->vt->adj); return 0; }

typedef struct { char c[8]; } V8_001692B0;
typedef struct { char p[360]; int a, b; char p2[132]; int w; char p3[40]; V8_001692B0 v; } O_001692B0;
extern V8_001692B0 D_004A2E58[2];
// MATCH func_001692B0
int pachislot_001692b0(O_001692B0 *o) { o->w = o->w + 8; if (o->w >= 128) { o->w = 128; o->b = o->b + o->a; o->v = D_004A2E58[0]; } return 0; }

extern char D_0043D098[];
// MATCH func_00166730
void *pachislot_00166730(void *s, int a) {
(*(int *)((char *)s + 4)) = -1;
(*(int *)((char *)s + 8)) = -1;
(*(int *)((char *)s + 12)) = 0;
(*(int *)((char *)s + 32)) = (int)D_0043D098;
(*(int *)((char *)s + 16)) = 0;
(*(int *)((char *)s + 0)) = a;
(*(int *)((char *)s + 24)) = 0;
(*(int *)((char *)s + 20)) = -1;
(*(int *)((char *)s + 28)) = 0;
return s; }

typedef struct { char pad[4]; int a4; char pad1[40]; void *a48; } S_164928_00164928;
extern char D_0043D2F0[];
void func_00131588_00164928(int) __asm__("func_00131588"); void func_00108B80_00164928(void *) __asm__("func_00108B80");
// MATCH func_00164928
void pachislot_00164928(S_164928_00164928 *s, int fl) { s->a48 = D_0043D2F0; if (s->a4 != 0) func_00131588_00164928(s->a4); if (fl & 1) func_00108B80_00164928(s); }

typedef struct { char c[8]; } V8_166038_00166038;
typedef struct { char p[56]; short adj; short pad; void (*fn)(void *); } VT_166038_00166038;
typedef struct { char p[48]; VT_166038_00166038 *vt; char p2[12]; int w; V8_166038_00166038 v; } O_166038_00166038;
extern V8_166038_00166038 D_004A2D30[2]; int func_00164A20(void *); void func_00164A38(void *, int);
// MATCH func_00166038
void pachislot_00166038(O_166038_00166038 *o) { if (func_00164A20(o)) { o->v = D_004A2D30[0]; func_00164A38(o, 3); o->vt->fn((char *)o + o->vt->adj); o->w = 30; } }

typedef struct { char c[8]; } V8_165d08_00165D08;
typedef struct { char p[56]; short adj; short pad; void (*fn)(void *); char p2[8]; short adj2; short pad2; int (*fn2)(void *); } VT_165d08_00165D08;
typedef struct { char p[48]; VT_165d08_00165D08 *vt; int w52; char p2[12]; V8_165d08_00165D08 v; } O_165d08_00165D08;
extern V8_165d08_00165D08 D_004A2D00[2]; void func_00164A38(void *, int);
// MATCH func_00165D08
void pachislot_00165d08(O_165d08_00165D08 *o) { if (o->vt->fn2((char *)o + o->vt->adj2)) { o->v = D_004A2D00[0]; func_00164A38(o, o->w52); o->vt->fn((char *)o + o->vt->adj); } }

typedef struct { char c[8]; } V8_165f48_00165F48;
typedef struct { char p[56]; short adj; short pad; void (*fn)(void *); char p2[8]; short adj2; short pad2; int (*fn2)(void *); } VT_165f48_00165F48;
typedef struct { char p[48]; VT_165f48_00165F48 *vt; int w52; char p2[12]; V8_165f48_00165F48 v; } O_165f48_00165F48;
extern V8_165f48_00165F48 D_004A2D20[2]; void func_00164A38(void *, int);
// MATCH func_00165F48
void pachislot_00165f48(O_165f48_00165F48 *o) { if (o->vt->fn2((char *)o + o->vt->adj2)) { o->v = D_004A2D20[0]; func_00164A38(o, 2); o->vt->fn((char *)o + o->vt->adj); } }

typedef struct { char c[8]; } V8_165db8_00165DB8;
typedef struct { char p[56]; short adj; short pad; void (*fn)(void *); char p2[8]; short adj2; short pad2; int (*fn2)(void *); } VT_165db8_00165DB8;
typedef struct { char p[48]; VT_165db8_00165DB8 *vt; int w52; char p2[12]; V8_165db8_00165DB8 v; } O_165db8_00165DB8;
extern V8_165db8_00165DB8 D_004A2D08[2]; void func_00164A38(void *, int);
// MATCH func_00165DB8
void pachislot_00165db8(O_165db8_00165DB8 *o) { if (o->vt->fn2((char *)o + o->vt->adj2)) { o->v = D_004A2D08[0]; func_00164A38(o, 2); o->vt->fn((char *)o + o->vt->adj); } }

typedef struct { char c[8]; } V8_169f70_00169F70;
typedef struct { char p[544]; V8_169f70_00169F70 d; V8_169f70_00169F70 s; } O_169f70_00169F70;
int func_00166638(void *);
// MATCH func_00169F70
int pachislot_00169f70(O_169f70_00169F70 *o) { if (func_00166638((char *)o + 284)) o->d = o->s; return 0; }

typedef struct { char c[8]; } V8_00169278;
typedef struct { char pad[500]; int n; char pad2[40]; V8_00169278 a; } Q_00169278;
extern V8_00169278 D_004A2E50_00169278[2] __asm__("D_004A2E50");
// MATCH func_00169278
int pachislot_00169278(Q_00169278 *o) { o->n -= 8; if (o->n < 0) { o->n = 0; o->a = D_004A2E50_00169278[0]; } return 0; }

typedef struct { char p[48]; void *vt; char p2[12]; int a; int b; char p3[4]; int c; } O_1658f8_001658F8;
extern char D_0043D1A0[]; int func_00164D30(void *);
// MATCH func_001658F8
void *pachislot_001658f8(O_1658f8_001658F8 *o) { func_00164D30(o); o->c = -1; o->vt = D_0043D1A0; o->a = 0; o->b = 0; return o; }

typedef struct { char p[48]; void *vt; int a; int b; int c; } O_164d30_00164D30;
extern char D_0043D280[]; int func_00164890(void *);
// MATCH func_00164D30
void *pachislot_00164d30(O_164d30_00164D30 *o) { func_00164890(o); o->c = -1; o->vt = D_0043D280; o->a = 0; o->b = 0; return o; }

typedef struct { char c[8]; } V8_001663E8;
typedef struct { char p[48]; short adj; short pad; void (*fn)(void *, int); } VT_001663E8;
typedef struct { char p[48]; VT_001663E8 *vt; int w52; int w56; int w60; char q[4]; V8_001663E8 v; } O_001663E8;
extern V8_001663E8 D_004A2D58[2];
void func_00164D10(void *);
// MATCH func_001663E8
void pachislot_001663e8(O_001663E8 *o) { if (o->w60 == 0) { o->vt->fn((char *)o + o->vt->adj, 10); o->v = D_004A2D58[0]; func_00164D10(o); } }

typedef struct { char c[8]; } V8_00166458;
typedef struct { char p[48]; short adj; short pad; void (*fn)(void *, int); } VT_00166458;
typedef struct { char p[48]; VT_00166458 *vt; int w52; int w56; int w60; char q[4]; V8_00166458 v; } O_00166458;
extern V8_00166458 D_004A2D60[2];
void func_00164D10(void *);
// MATCH func_00166458
void pachislot_00166458(O_00166458 *o) { if (o->w60 == 0) { o->vt->fn((char *)o + o->vt->adj, 10); o->w56 = 1; o->v = D_004A2D60[0]; func_00164D10(o); } }

typedef struct { char c[8]; } V8_001664D0;
typedef struct { char p[48]; short adj; short pad; void (*fn)(void *, int); } VT_001664D0;
typedef struct { char p[48]; VT_001664D0 *vt; int w52; int w56; int w60; char q[4]; V8_001664D0 v; } O_001664D0;
extern V8_001664D0 D_004A2D68[2];
void func_00164D10(void *);
// MATCH func_001664D0
void pachislot_001664d0(O_001664D0 *o) { if (o->w60 == 0) { o->vt->fn((char *)o + o->vt->adj, 10); o->w56 = 1; o->v = D_004A2D68[0]; func_00164D10(o); } }

typedef struct { char c[8]; } V8_00166548;
typedef struct { char p[48]; short adj; short pad; void (*fn)(void *, int); } VT_00166548;
typedef struct { char p[48]; VT_00166548 *vt; int w52; int w56; int w60; char q[4]; V8_00166548 v; } O_00166548;
extern V8_00166548 D_004A2D70[2];
void func_00164D10(void *);
// MATCH func_00166548
void pachislot_00166548(O_00166548 *o) { if (o->w60 == 0) { o->vt->fn((char *)o + o->vt->adj, 10); o->w56 = 1; o->v = D_004A2D70[0]; func_00164D10(o); } }

typedef struct { char c[8]; } V8_001665C0;
typedef struct { char p[48]; short adj; short pad; void (*fn)(void *, int); } VT_001665C0;
typedef struct { char p0[24]; int w24; int w28; char p1[16]; VT_001665C0 *vt; int w52; int w56; int w60; char q[4]; V8_001665C0 v; } O_001665C0;
extern V8_001665C0 D_004A2D78[2]; void func_00164D10_001665C0(O_001665C0 *) __asm__("func_00164D10");
// MATCH func_001665C0
void pachislot_001665c0(O_001665C0 *o) { if (o->w60 == 0) { o->vt->fn((char *)o + o->vt->adj, 0); o->w24 = -o->w28; o->v = D_004A2D78[0]; func_00164D10_001665C0(o); } }

int func_00167730(void *, void *, int);
// MATCH func_00168110
int pachislot_00168110(char *o, int b) { int r = 0; int i = 0; for (; i < 3; i++) { r = func_00167730(o, o + 124, i + b); if (r) break; } return r; }

int func_00167730(void *, void *, int);
// MATCH func_001681C8
int pachislot_001681c8(char *o, int b) { int r = 0; int i = 0; for (; i < 3; i++) { r = func_00167730(o, o + 204, i + b); if (r) break; } return r; }

int func_00167940(char *, int, int, int); int func_00167DD0(char *, int);
// MATCH func_00167FC0
int pachislot_00167fc0(char *o, int b) { int r = 0; int a = func_00167940(o, b, 0, 0); int s = func_00167DD0(o, b); if (a == 1 || s == 1) r = 1; else if (a == 3 || s == 3) r = 3; else if (a == 2 || s == 2) r = 2; return r; }

int func_00167B88(char *, int, int, int); int func_00167DD0(char *, int);
// MATCH func_00168068
int pachislot_00168068(char *o, int b) { int r = 0; int a = func_00167B88(o, b, 0, 0); int s = func_00167DD0(o, b); if (a == 1 || s == 1) r = 1; else if (a == 3 || s == 3) r = 3; else if (a == 2 || s == 2) r = 2; return r; }

typedef struct { char c[8]; } V8_00165E28;
typedef struct { char p[48]; short adj; short pad; void (*fn)(void *, int); char q[32]; short adj2; short pad2; void (*fn2)(void *, int); } VT_00165E28;
typedef struct { char p0[48]; VT_00165E28 *vt; int w52, w56, w60, w64; V8_00165E28 v; } O_00165E28;
extern V8_00165E28 D_004A2D10[2]; int func_00164A00_00165E28(void) __asm__("func_00164A00");
// MATCH func_00165E28
void pachislot_00165e28(O_00165E28 *o) { if (o->w56 == 0 && func_00164A00_00165E28() != 0) { o->v = D_004A2D10[0]; o->vt->fn((char *)o + o->vt->adj, 0); o->vt->fn2((char *)o + o->vt->adj2, 0); } }

typedef struct { char c[8]; } V8_00165FB8;
typedef struct { char p[48]; short adj; short pad; void (*fn)(void *, int); char q[32]; short adj2; short pad2; void (*fn2)(void *, int); } VT_00165FB8;
typedef struct { char p0[48]; VT_00165FB8 *vt; int w52, w56, w60, w64; V8_00165FB8 v; } O_00165FB8;
extern V8_00165FB8 D_004A2D28[2]; int func_00164A00_00165FB8(void) __asm__("func_00164A00");
// MATCH func_00165FB8
void pachislot_00165fb8(O_00165FB8 *o) { if (o->w56 == 0 && func_00164A00_00165FB8() != 0) { o->v = D_004A2D28[0]; o->vt->fn((char *)o + o->vt->adj, 0); o->vt->fn2((char *)o + o->vt->adj2, 0); } }

typedef struct { char c[8]; } V8_001660A0;
typedef struct { char p[48]; short adj; short pad; void (*fn)(void *, int); char q[32]; short adj2; short pad2; void (*fn2)(void *, int); } VT_001660A0;
typedef struct { char p0[48]; VT_001660A0 *vt; int w52, w56, w60, w64; V8_001660A0 v; } O_001660A0;
extern V8_001660A0 D_004A2D38[2]; int func_00164A00_001660A0(void) __asm__("func_00164A00");
// MATCH func_001660A0
void pachislot_001660a0(O_001660A0 *o) { if (func_00164A00_001660A0() != 0 && o->w64-- <= 0) { o->v = D_004A2D38[0]; o->vt->fn((char *)o + o->vt->adj, 0); o->vt->fn2((char *)o + o->vt->adj2, 0); } }

typedef struct { char c[8]; } V8_0016C1D8;
typedef struct { int w0, w4, w8, w12, w16, w20, w24, w28; char p[24]; V8_0016C1D8 v; } O_0016C1D8;
extern V8_0016C1D8 D_004A2F38_0016C1D8[2] __asm__("D_004A2F38");
// MATCH func_0016C1D8
int pachislot_0016c1d8(O_0016C1D8 *o) { o->w4 += 3; o->w12 += 3; o->w16 = 3; o->w20 = 10; if (o->w4 >= 144) { o->w24 = 0; o->w4 = 144; o->w12 = 144; o->w28 = 0; o->v = D_004A2F38_0016C1D8[0]; } return 0; }

typedef struct { char c[8]; } V8_00169308;
typedef struct { char p[468]; int w468; char q[8]; int w480; char q2[4]; int w488; char q3[4]; int w496; char q4[44]; V8_00169308 v; } O_00169308;
extern V8_00169308 D_004A2E60[2]; void func_00168AB8_00169308(O_00169308 *) __asm__("func_00168AB8"); void func_001649C8(char *);
// MATCH func_00169308
int pachislot_00169308(O_00169308 *o) { func_00168AB8_00169308(o); func_001649C8((char *)o + 44); func_001649C8((char *)o + 124); func_001649C8((char *)o + 204); o->w468 = 0; o->w496 = -1; o->w480 = 0; o->w488 = 0; o->v = D_004A2E60[0]; return 0; }

typedef struct { char p[16]; unsigned long long *w16; } S_00164BB0;
extern S_00164BB0 D_00342CD0_00164BB0 __asm__("D_00342CD0"); extern unsigned long long D_00318680[]; void func_00190328(S_00164BB0 *); void func_00190420(S_00164BB0 *);
// MATCH func_00164BB0
void pachislot_00164bb0(void) { unsigned long long *p; func_00190328(&D_00342CD0_00164BB0); p = D_00342CD0_00164BB0.w16; p[0] = 5; p[1] = 8; D_00342CD0_00164BB0.w16 = p + 4; p[2] = D_00318680[0]; p[3] = 66; func_00190420(&D_00342CD0_00164BB0); }

typedef struct { char c[8]; } V8_00169CE8;
typedef struct { char p[464]; int w464; char q[76]; V8_00169CE8 v; V8_00169CE8 v2; } O_00169CE8;
extern V8_00169CE8 D_004A2EB0[2]; int func_00166638_00169CE8(char *) __asm__("func_00166638"); int func_00167070(char *);
// MATCH func_00169CE8
int pachislot_00169ce8(O_00169CE8 *o) { if (func_00166638_00169CE8((char *)o + 284)) { if (func_00167070((char *)o + 8) == -1) o->v = o->v2; else { o->w464 = 30; o->v = D_004A2EB0[0]; } } return 0; }

typedef struct { char c[8]; } V8_00169930;
typedef struct { char p[460]; int w460; char q[80]; V8_00169930 v; } O_00169930;
extern V8_00169930 D_004A2E80[2]; void func_00164D20(char *); void func_00164D10_00169930(char *) __asm__("func_00164D10");
// MATCH func_00169930
int pachislot_00169930(O_00169930 *o) { char *a = (char *)o + 44; char *b = (char *)o + 124; char *c = (char *)o + 204; func_00164D20(a); func_00164D20(b); func_00164D20(c); if (o->w460 == 0) { func_00164D10_00169930(a); func_00164D10_00169930(b); func_00164D10_00169930(c); o->v = D_004A2E80[0]; } return 0; }

typedef struct { char p[360]; int w360, w364; char q[88]; int w456; } O_00168AC0;
extern char D_00343028_00168AC0[] __asm__("D_00343028"); void func_0010C2B0(char *, int, int, int, int, int, int); void func_0016B158(O_00168AC0 *);
// MATCH func_00168AC0
int pachislot_00168ac0(O_00168AC0 *o) { if (o->w364 == 0) return 0; if (o->w360 >= 3) return 0; func_0010C2B0(D_00343028_00168AC0, 139, 6, 0, 5, 0, 0); o->w360++; o->w364--; func_0016B158(o); if (o->w456 < 5) o->w456 = 0; return 1; }

typedef struct { char c[8]; } V8_0016AB78;
typedef struct { char p[284]; char s[172]; int w456; char q2[4]; int w464; char q3[76]; V8_0016AB78 v; } O_0016AB78;
extern V8_0016AB78 D_004A2F08[2]; extern char D_00343028_0016AB78[] __asm__("D_00343028"); int func_00166638_0016AB78(char *) __asm__("func_00166638"); void func_00164D20(char *); void func_002B26E0(int, int, int, int, int, int, int, int); int func_0010C2B0_0016AB78(char *, int, int, int, int, int, int) __asm__("func_0010C2B0");
// MATCH func_0016AB78
int pachislot_0016ab78(O_0016AB78 *o) { if (func_00166638_0016AB78((char *)o + 284)) { func_00164D20((char *)o + 284); o->v = D_004A2F08[0]; o->w456 = 0; func_002B26E0(139, 6, 0, 10, 1, 0, 0, 100); func_0010C2B0_0016AB78(D_00343028_0016AB78, 139, 6, 0, 11, 0, 0); o->w464 = 150; } return 0; }

typedef struct { char c[8]; } V8_00164890;
typedef struct { char p[16]; int w16, w20; } P_00164890;
typedef struct { P_00164890 *w0; void *w4; int w8, w12; char p1[4]; int w20, w24, w28, w32; char p2[4]; V8_00164890 v; char *w48; } O_00164890;
extern char D_0043D2F0_00164890[] __asm__("D_0043D2F0"), D_0043C8C0[]; extern V8_00164890 D_004A2CD0[2]; void *func_00162130_00164890(int, char *, int) __asm__("func_00162130"); void func_001649C8_00164890(O_00164890 *) __asm__("func_001649C8"); void func_00164D10_00164890(O_00164890 *) __asm__("func_00164D10");
// MATCH func_00164890
O_00164890 *pachislot_00164890(O_00164890 *o, P_00164890 *p) { o->w12 = 0; o->w20 = 0; o->w24 = 0; o->w28 = p->w16; o->w32 = -1; o->w48 = D_0043D2F0_00164890; o->w0 = p; o->w8 = 0; o->w4 = func_00162130_00164890(p->w20, D_0043C8C0, 466); func_001649C8_00164890(o); func_00164D10_00164890(o); o->v = D_004A2CD0[0]; return o; }

extern void (*D_004A1360)(void); extern void (*D_004A1364)(void); extern int D_004A12A4_0016BFD0 __asm__("D_004A12A4"); extern int D_004A2F24, D_004A2F28; extern char D_0043C8C0_0016BFD0[] __asm__("D_0043C8C0"), D_00334748[]; void func_00110490(void); void func_0016BF38(void); int func_00294210(void); void *func_00162130_0016BFD0(int, char *, int) __asm__("func_00162130"); int func_001670B8(void *, char *, int, int);
// MATCH func_0016BFD0
void pachislot_0016bfd0(void) { int r; void *p; D_004A1360 = func_00110490; D_004A12A4_0016BFD0 = 25; D_004A1364 = func_0016BF38; r = func_00294210(); p = func_00162130_0016BFD0(576, D_0043C8C0_0016BFD0, 4241); D_004A2F24 = func_001670B8(p, D_00334748, D_004A2F28, r); }

typedef struct { char c[8]; } V8_00169378;
typedef struct { int w0; char p[24]; int w28; char q[448]; int w480, w484; char q2[8]; int w496; char q3[44]; V8_00169378 v; V8_00169378 v2; } O_00169378;
extern char D_0043CE48[]; extern V8_00169378 D_004A2E68[2]; void func_00168AB8_00169378(O_00169378 *) __asm__("func_00168AB8"); int func_001118F8_00169378(char *, int) __asm__("func_001118F8");
// MATCH func_00169378
int pachislot_00169378(O_00169378 *o) { func_00168AB8_00169378(o); func_001118F8_00169378(D_0043CE48, ++o->w480); if (o->w480 >= 4) { o->w480 = 0; o->w484 = 1; o->w28 = 0; } o->w496 = -1; o->v = D_004A2E68[0]; return 0; }

typedef struct { char p[360]; int w360, w364; } O_00168BC0;
extern char D_00343028_00168BC0[] __asm__("D_00343028"); void func_0010C2B0(char *, int, int, int, int, int, int); void func_0016B158_00168BC0(O_00168BC0 *) __asm__("func_0016B158");
// MATCH func_00168BC0
int pachislot_00168bc0(O_00168BC0 *o) { if (o->w364 == 0) return 0; if (o->w360 > 0) return 0; func_0010C2B0(D_00343028_00168BC0, 139, 6, 0, 5, 0, 0); o->w360++; o->w364--; func_0016B158_00168BC0(o); return 1; }

typedef struct { char p[360]; int w360, w364; } O_00168C40;
extern char D_00343028_00168C40[] __asm__("D_00343028"); void func_0010C2B0(char *, int, int, int, int, int, int); void func_0016B158_00168C40(O_00168C40 *) __asm__("func_0016B158");
// MATCH func_00168C40
int pachislot_00168c40(O_00168C40 *o) { if (o->w360 < 3) return 0; func_0010C2B0(D_00343028_00168C40, 139, 6, 0, 5, 0, 0); while (o->w360 >= 2) { o->w360--; o->w364++; func_0016B158_00168C40(o); } return 1; }

typedef struct { char c[8]; } V8_001699D0;
typedef struct { char p[464]; int w464; char q[76]; V8_001699D0 v, v2; } O_001699D0;
int func_00164A20_001699D0(char *) __asm__("func_00164A20"); void func_00165990(char *);
// MATCH func_001699D0
int pachislot_001699d0(O_001699D0 *o) { if (!func_00164A20_001699D0((char *)o + 44)) return 0; if (!func_00164A20_001699D0((char *)o + 124)) return 0; if (!func_00164A20_001699D0((char *)o + 204)) return 0; { int n = o->w464++; if (n < 30) return 0; o->w464 = 0; func_00165990((char *)o + 44); func_00165990((char *)o + 124); func_00165990((char *)o + 204); o->v = o->v2; return 0; } }

typedef struct { char c[8]; } V8_001662C0;
typedef struct { char p[24]; int w24; char q[40]; V8_001662C0 v; } O_001662C0;
extern V8_001662C0 D_004A2CF8_001662C0[2] __asm__("D_004A2CF8"); int func_00164A00_001662C0(void) __asm__("func_00164A00");
// MATCH func_001662C0
void pachislot_001662c0(O_001662C0 *o) { if (func_00164A00_001662C0() != 0) { o->w24 = 0; o->v = D_004A2CF8_001662C0[0]; } else { o->w24 -= 32; if (o->w24 < 1024) o->w24 = 1024; } }

int pachislot_00165a40(char *, int); int func_00167058(char *);
// MATCH func_00167678
int pachislot_00167678(char *o, int a, int b, int c) { int x = pachislot_00165a40(o + 44, a); int y = pachislot_00165a40(o + 124, b); int z = pachislot_00165a40(o + 204, c); if ((unsigned)(x - 1) < 3 && (unsigned)(y - 1) < 3 && (unsigned)(z - 1) < 3) return func_00167058(o + 8) == -1 ? 1 : 4; return 0; }

int pachislot_00165a40(char *, int);
// MATCH func_001674C8
int pachislot_001674c8(char *o, int a, int b, int c) { int x = pachislot_00165a40(o + 44, a); int y = pachislot_00165a40(o + 124, b); int z = pachislot_00165a40(o + 204, c); if (x == y && x == z && x != 6) return x; return -1; }

int pachislot_001673c0(char *, int, int, int); int pachislot_00167550(char *, int, int, int); int func_00166F90(char *, int); int pachislot_00166fd8(char *, int);
// MATCH func_001677E8
int pachislot_001677e8(char *o, int a, int b, int c) { int r = pachislot_001673c0(o, a, b, c); char *q; if (r < 0) return pachislot_00167550(o, a, b, c); q = o + 8; if (func_00166F90(q, r) != -1) return 2; return pachislot_00166fd8(q, r) == -1 ? 0 : 3; }

extern char D_0043D088[], D_0043C8C0_001672D0[] __asm__("D_0043C8C0"); void func_001621F8_001672D0(int, char *, int) __asm__("func_001621F8"); void func_0016C148(int, int); void func_0018C470(char *, int); void func_00165C80(char *, int); void func_00165940(char *, int); void func_00166768(char *, int); void func_00108B80_001672D0(char *) __asm__("func_00108B80");
// MATCH func_001672D0
void pachislot_001672d0(char *o, int flag) { *(int *)(o + 568) = (int)D_0043D088; func_001621F8_001672D0(*(int *)(o + 376), D_0043C8C0_001672D0, 1766); func_001621F8_001672D0(*(int *)(o + 380), D_0043C8C0_001672D0, 1767); if (*(int *)(o + 460)) func_0016C148(*(int *)(o + 460), 3); func_0018C470(o + 384, 2); func_00165C80(o + 284, 2); func_00165940(o + 204, 2); func_00165940(o + 124, 2); func_00165940(o + 44, 2); func_00166768(o + 8, 2); if (flag & 1) func_00108B80_001672D0(o); }

int pachislot_001674c8(char *, int, int, int); int pachislot_00167678(char *, int, int, int); int func_00166F90(char *, int); int pachislot_00166fd8(char *, int);
// MATCH func_00167890
int pachislot_00167890(char *o, int a, int b, int c) { int r = pachislot_001674c8(o, a, b, c); char *q; if (r < 0) return pachislot_00167678(o, a, b, c); q = o + 8; if (func_00166F90(q, r) != -1) return 2; if (pachislot_00166fd8(q, r) != -1) return 3; return 1; }

typedef struct { char c[8]; } V8_001684A8;
extern V8_001684A8 D_004A2DF8[3]; extern V8_001684A8 D_004A2E00[3]; extern V8_001684A8 D_004A2E08[3]; int func_001659A8(char *); int func_00168280(char *, V8_001684A8); void func_001686A0(char *); void func_001659B0(char *, int);
// MATCH func_001684A8
void pachislot_001684a8(char *o) { int a; int b; int r; func_001686A0(o); a = func_001659A8(o + 124); b = func_001659A8(o + 204); if (a != 0) { if (b != 0) r = func_00168280(o, D_004A2DF8[0]); else r = func_00168280(o, D_004A2E00[0]); } else { if (b != 0) r = func_00168280(o, D_004A2E00[0]); else r = func_00168280(o, D_004A2E08[0]); } func_001659B0(o + 44, r); }

typedef struct { char c[8]; } V8_00168550;
extern V8_00168550 D_004A2E10[3]; extern V8_00168550 D_004A2E18[3]; extern V8_00168550 D_004A2E20[3]; int func_001659A8(char *); int func_00168280_00168550(char *, V8_00168550) __asm__("func_00168280"); void func_001686A0(char *); void func_001659B0(char *, int);
// MATCH func_00168550
void pachislot_00168550(char *o) { int a; int b; int r; func_001686A0(o); a = func_001659A8(o + 44); b = func_001659A8(o + 204); if (a != 0) { if (b != 0) r = func_00168280_00168550(o, D_004A2E10[0]); else r = func_00168280_00168550(o, D_004A2E18[0]); } else { if (b != 0) r = func_00168280_00168550(o, D_004A2E18[0]); else r = func_00168280_00168550(o, D_004A2E20[0]); } func_001659B0(o + 124, r); }

typedef struct { char c[8]; } V8_001685F8;
extern V8_001685F8 D_004A2E28[3]; extern V8_001685F8 D_004A2E30[3]; extern V8_001685F8 D_004A2E38[3]; int func_001659A8(char *); int func_00168280_001685F8(char *, V8_001685F8) __asm__("func_00168280"); void func_001686A0(char *); void func_001659B0(char *, int);
// MATCH func_001685F8
void pachislot_001685f8(char *o) { int a; int b; int r; func_001686A0(o); a = func_001659A8(o + 44); b = func_001659A8(o + 124); if (a != 0) { if (b != 0) r = func_00168280_001685F8(o, D_004A2E28[0]); else r = func_00168280_001685F8(o, D_004A2E30[0]); } else { if (b != 0) r = func_00168280_001685F8(o, D_004A2E30[0]); else r = func_00168280_001685F8(o, D_004A2E38[0]); } func_001659B0(o + 204, r); }

typedef struct { char c[8]; } V8_00165C20;
extern V8_00165C20 D_004A2CF8_00165C20[3] __asm__("D_004A2CF8"); extern char D_0043D0A8[]; int func_00164D78(char *); void func_00164D20(char *);
// MATCH func_00165C20
char *pachislot_00165c20(char *o) { func_00164D78(o); *(int *)(o + 56) = 0; *(int *)(o + 60) = 0; *(char **)(o + 48) = D_0043D0A8; *(V8_00165C20 *)(o + 68) = D_004A2CF8_00165C20[0]; func_00164D20(o); return o; }

int func_00165A40(int, int); int func_00166F90(char *, int); int func_00166FD8(char *, int); int func_00167058(char *);
// MATCH func_00167730
int pachislot_00167730(char *o, int a, int b) { int r, x, y; r = func_00165A40(a, b); if (r != 6) { x = func_00166F90(o + 8, r); if (x != -1) return 2; y = func_00166FD8(o + 8, r); if (y != x) return 3; if ((unsigned)(r - 1) < 3) { if (func_00167058(o + 8) != y) return 4; } } return 0; }

extern char D_00343028_00166678[] __asm__("D_00343028");
void func_00164C10(char *); void func_0010C2B0(char *, int, int, int, int, int, int);
// MATCH func_00166678
void pachislot_00166678(char *o) { int idx = *(short *)(o + 70); void (*fn)(void *); int d; int dl; long e; if (idx > 0) { long *vt = *(long **)(o + *(short *)(o + 72)); e = vt[idx - 1]; fn = (void (*)(void *))(e >> 32); } else fn = *(void (**)(void *))(o + 72); dl = *(short *)(o + 68); d = idx > 0 ? (short)e + dl : dl; fn(o + d); func_00164C10(o); if (*(int *)(o + 12) != *(short *)(o + 10)) func_0010C2B0(D_00343028_00166678, 139, 6, 0, 4, 0, 0); }

typedef struct { char c[8]; } V8_00169400;
extern long D_004A12D8_00169400 __asm__("D_004A12D8"); extern V8_00169400 D_004A2E60_00169400[3] __asm__("D_004A2E60"); extern char D_00343028_00169400[] __asm__("D_00343028");
void func_0010C2B0(char *, int, int, int, int, int, int); void func_0016B158_00169400(char *) __asm__("func_0016B158");
// MATCH func_00169400
int pachislot_00169400(char *o) { int *w = (int *)o; if (D_004A12D8_00169400 & 0x20000) w[117] = 1; if (w[116]++ < 10) return 0; w[116] = 0; if (w[119] != 0) { func_0010C2B0(D_00343028_00169400, 139, 6, 0, 5, 0, 0); w[90]++; w[119]--; func_0016B158_00169400(o); return 0; } w[122] = 1; *(V8_00169400 *)(o + 544) = D_004A2E60_00169400[0]; return 0; }

typedef struct { char c[8]; } V8_001697F0_001697F0;
extern unsigned long D_004A12D8_001697F0 __asm__("D_004A12D8"), D_004A12E0;
extern V8_001697F0_001697F0 D_004A2E98[3];
extern V8_001697F0_001697F0 D_004A2E60_001697F0[3] __asm__("D_004A2E60");
extern char D_00343028_001697F0[] __asm__("D_00343028");
int func_0010C2B0_001697F0(void *, int, int, int, int, int, int) __asm__("func_0010C2B0");
// MATCH func_001697F0
int pachislot_001697f0(char *o) {
    if ((D_004A12D8_001697F0 | D_004A12E0) & 0x35000) {
        *(int *)(o + 464) = 1 - *(int *)(o + 464);
        func_0010C2B0_001697F0(D_00343028_001697F0, 0, 2, 0, 0, 0, 0);
    } else if (D_004A12D8_001697F0 & 0x200040) {
        func_0010C2B0_001697F0(D_00343028_001697F0, 0, 2, 0, 1, 0, 0);
        if (*(int *)(o + 464) == 0) *(V8_001697F0_001697F0 *)(o + 544) = D_004A2E98[0];
        else *(V8_001697F0_001697F0 *)(o + 544) = D_004A2E60_001697F0[0];
    } else if (D_004A12D8_001697F0 & 0x100010) {
        func_0010C2B0_001697F0(D_00343028_001697F0, 0, 2, 0, 2, 0, 0);
        *(V8_001697F0_001697F0 *)(o + 544) = D_004A2E60_001697F0[0];
    }
    return 0;
}
