/* Small functions matched by hand. */
// compiler: 991111-01-as210
#include "common.h"

typedef struct { char c[8]; } V8_00175E80;
typedef struct { char p[408]; V8_00175E80 v; } O_00175E80;
extern V8_00175E80 D_00336530[];
// MATCH func_00175E80
void repetition_00175e80(O_00175E80 *o, unsigned i) { if (i >= 4) i = 0; o->v = D_00336530[i]; }

typedef struct { char c[8]; } V8_00178700;
typedef struct { char p[476]; V8_00178700 v; } O_00178700;
extern V8_00178700 D_00336738[];
// MATCH func_00178700
void shuffle_00178700(O_00178700 *o, unsigned i) { if (i >= 4) i = 0; o->v = D_00336738[i]; }

typedef struct { char c[8]; } V8_0016E4E0;
typedef struct { char p[104]; V8_0016E4E0 v; } O_0016E4E0;
extern V8_0016E4E0 D_00334E70[];
// MATCH func_0016E4E0
void darts_0016e4e0(O_0016E4E0 *o, unsigned i) { if (i >= 8) i = 0; o->v = D_00334E70[i]; }

typedef struct { char c[8]; } V8_00170910;
typedef struct { char p[136]; V8_00170910 v; } O_00170910;
extern V8_00170910 D_00335628[];
// MATCH func_00170910
void roulette_00170910(O_00170910 *o, unsigned i) { if (i >= 3) i = 0; o->v = D_00335628[i]; }

typedef struct { char c[8]; } V8_00171980;
typedef struct { char p[44]; V8_00171980 v; } O_00171980;
extern V8_00171980 D_00335690[];
// MATCH func_00171980
void roulette_00171980(O_00171980 *o, unsigned i) { if (i >= 5) i = 0; o->v = D_00335690[i]; }

typedef struct { char c[8]; } V8_0025F778;
typedef struct { char p[412]; V8_0025F778 v; } O_0025F778;
extern V8_0025F778 D_00402450[];
// MATCH func_0025F778
void abeshi_0025f778(O_0025F778 *o, unsigned i) { if (i >= 4) i = 0; o->v = D_00402450[i]; }

typedef struct { char c[8]; } V8_00294D98;
typedef struct { char p[76]; V8_00294D98 v; } O_00294D98;
extern V8_00294D98 D_0041EF28[];
// MATCH func_00294D98
void battleslot_00294d98(O_00294D98 *o, unsigned i) { if (i >= 3) i = 0; o->v = D_0041EF28[i]; }

typedef struct { char c[8]; } V8_00164990;
typedef struct { int w0, w4, w8, w12, w16, w20, w24, w28, w32, w36; V8_00164990 v; } O_00164990;
extern V8_00164990 D_004A2CD0[];
// MATCH func_00164990
void pachislot_00164990(O_00164990 *o) { o->w32 = -1; o->w12 = 0; o->w20 = 0; o->w24 = 0; o->w8 = 0; o->v = D_004A2CD0[0]; }

typedef struct { char c[8]; } V8_001649E0;
typedef struct { char p[40]; V8_001649E0 v; } O_001649E0;
extern V8_001649E0 D_004A2CD8[];
// MATCH func_001649E0
void pachislot_001649e0(O_001649E0 *o) { o->v = D_004A2CD8[0]; }

typedef struct { char c[16]; } V16_0012AF88;
typedef struct { char p[48]; V16_0012AF88 v; } O_0012AF88;
// MATCH func_0012AF88
void battle_0012af88(O_0012AF88 *o, V16_0012AF88 *s) { o->v = *s; }

typedef struct { char c[16]; } V16_001DFEA0;
typedef struct { char p[128]; V16_001DFEA0 v; } O_001DFEA0;
// MATCH func_001DFEA0
void mizuki_001dfea0(O_001DFEA0 *o, V16_001DFEA0 *s) { o->v = *s; }

typedef struct { char c[16]; } V16_0012C918;
typedef struct { char p[128]; V16_0012C918 v; } O_0012C918;
extern O_0012C918 *D_003279A0[]; extern V16_0012C918 D_0055B3B0;
// MATCH func_0012C918
void battle_0012c918(int i) { D_0055B3B0 = D_003279A0[i]->v; }

typedef struct { char c[8]; } V8_0025E4D8;
typedef struct { int w0, w4, w8, w12, w16; char p[16]; V8_0025E4D8 v; } O_0025E4D8;
extern V8_0025E4D8 D_004A59B0[];
// MATCH func_0025E4D8
void FUN_0025e4d8(O_0025E4D8 *o, int x) { o->w8 = x; o->w16 = 0; o->v = D_004A59B0[0]; }

// MATCH func_00192E20
void FUN_00192e20(unsigned a) { *(volatile unsigned *)0x10009030 = a & 0xfffffff; *(volatile unsigned *)0x10009020 = 0; *(volatile unsigned *)0x10009000 = 325; }

typedef struct { char c[8]; } V8_00177D00;
typedef struct { char pad[476]; V8_00177D00 v; } O_00177D00;
extern V8_00177D00 D_004A3338[];
int func_00177BB0(void *);
// MATCH func_00177D00
int shuffle_00177d00(O_00177D00 *o){ o->v = D_004A3338[0]; func_00177BB0(o); return 0; }

// MATCH func_0018D8E8
void FUN_0018d8e8(void) { *(volatile unsigned *)0x10000810 = 0x83; *(volatile unsigned *)0x10000800 = 0; }

// MATCH func_002CACE8
void FUN_002cace8(void) { *(volatile int *)0x10003810 = 1; *(volatile int *)0x10003820 = 6; }

// MATCH func_002E7000
int FUN_002e7000(int c) { while (*(volatile unsigned *)0x1000f130 & 0x8000); *(volatile unsigned char *)0x1000f180 = c; return c; }

// MATCH func_0018EB98
void FUN_0018eb98(void *d, void *s)
{
    __asm__ volatile (
        "lq $7, 0($5)\n"
        "lq $6, 16($5)\n"
        "lq $3, 32($5)\n"
        "lq $2, 48($5)\n"
        "sq $7, 0($4)\n"
        "sq $6, 16($4)\n"
        "sq $3, 32($4)\n"
        "sq $2, 48($4)\n"
    );
}

typedef struct { volatile unsigned w0; char p[20]; unsigned short h24; } Ch_002D42F0;
typedef struct { char p[8]; int w8; } Q_002D42F0;
void *func_002CFF20(int); Q_002D42F0 *func_002CFF48(int);
// MATCH func_002D42F0
void FUN_002d42f0(unsigned ch) { if (ch < 48) { Ch_002D42F0 *p = func_002CFF20(ch); p->w0 |= 0x2000; if ((unsigned)(p->h24 - 1) < 127 && (p->w0 & 1)) { if (func_002CFF48(((volatile Ch_002D42F0 *)p)->h24)->w8 != 0) { p->w0 |= 2; p->w0 &= ~0x70; } } p->w0 &= ~0x2000; } }

// MATCH func_002CADB8
int FUN_002cadb8(unsigned a, unsigned b, unsigned c) { unsigned v = a | (b << 1) | (c << 2); *(volatile unsigned *)0x10003820 = v; return v; }

typedef struct { char p[156]; int a; float b, c, d, e, f, g; int h; } O_001E9260;
// MATCH func_001E9260
void yue_001e9260(O_001E9260 *o, float *s) { o->a = (int)s[0]; o->b = s[1]; o->c = s[2]; o->d = s[3]; o->e = s[4]; o->f = s[5]; o->g = s[6]; o->h = (int)s[7]; }

// MATCH func_002C9368
int FUN_002c9368(unsigned long long *p, int n) { return (int)(*p >> (64 - n)); }

float func_0015FB58(int, float); void func_0018EC58(float *); void func_0018F3D8(int, int, float *);
// MATCH func_0018F790
void FUN_0018f790(int a, int b, float ang) { volatile float m[16]; float c = func_0015FB58(1, ang); float s = func_0015FB58(0, ang); func_0018EC58((float *)m); m[5] = c; m[6] = s; m[9] = -s; m[10] = c; func_0018F3D8(a, b, (float *)m); }

float func_0015FB58(int, float); void func_0018EC58(float *); void func_0018F3D8(int, int, float *);
// MATCH func_0018F818
void FUN_0018f818(int a, float ang) { volatile float m[16]; float c = func_0015FB58(1, ang); float s = func_0015FB58(0, ang); func_0018EC58((float *)m); m[5] = c; m[6] = s; m[9] = -s; m[10] = c; func_0018F3D8(a, a, (float *)m); }

float func_0015FB58(int, float); void func_0018EC58(float *); void func_0018F520(float *);
// MATCH func_0018F898
void FUN_0018f898(float ang) { volatile float m[16]; float c = func_0015FB58(1, ang); float s = func_0015FB58(0, ang); func_0018EC58((float *)m); m[5] = c; m[6] = s; m[9] = -s; m[10] = c; func_0018F520((float *)m); }

float func_0015FB58(int, float); void func_0018EC58(float *); void func_0018F3D8(int, int, float *);
// MATCH func_0018F900
void FUN_0018f900(int a, int b, float ang) { volatile float m[16]; float c = func_0015FB58(1, ang); float s = func_0015FB58(0, ang); func_0018EC58((float *)m); m[0] = c; m[2] = -s; m[8] = s; m[10] = c; func_0018F3D8(a, b, (float *)m); }

float func_0015FB58(int, float); void func_0018EC58(float *); void func_0018F3D8(int, int, float *);
// MATCH func_0018F988
void FUN_0018f988(int a, float ang) { volatile float m[16]; float c = func_0015FB58(1, ang); float s = func_0015FB58(0, ang); func_0018EC58((float *)m); m[0] = c; m[2] = -s; m[8] = s; m[10] = c; func_0018F3D8(a, a, (float *)m); }

float func_0015FB58(int, float); void func_0018EC58(float *); void func_0018F520(float *);
// MATCH func_0018FA08
void FUN_0018fa08(float ang) { volatile float m[16]; float c = func_0015FB58(1, ang); float s = func_0015FB58(0, ang); func_0018EC58((float *)m); m[0] = c; m[2] = -s; m[8] = s; m[10] = c; func_0018F520((float *)m); }

float func_0015FB58(int, float); void func_0018EC58(float *); void func_0018F3D8(int, int, float *);
// MATCH func_0018FA70
void FUN_0018fa70(int a, int b, float ang) { volatile float m[16]; float c = func_0015FB58(1, ang); float s = func_0015FB58(0, ang); func_0018EC58((float *)m); m[0] = c; m[1] = s; m[4] = -s; m[5] = c; func_0018F3D8(a, b, (float *)m); }

float func_0015FB58(int, float); void func_0018EC58(float *); void func_0018F3D8(int, int, float *);
// MATCH func_0018FAF8
void FUN_0018faf8(int a, float ang) { volatile float m[16]; float c = func_0015FB58(1, ang); float s = func_0015FB58(0, ang); func_0018EC58((float *)m); m[0] = c; m[1] = s; m[4] = -s; m[5] = c; func_0018F3D8(a, a, (float *)m); }

float func_0015FB58(int, float); void func_0018EC58(float *); void func_0018F520(float *);
// MATCH func_0018FB78
void FUN_0018fb78(float ang) { volatile float m[16]; float c = func_0015FB58(1, ang); float s = func_0015FB58(0, ang); func_0018EC58((float *)m); m[0] = c; m[1] = s; m[4] = -s; m[5] = c; func_0018F520((float *)m); }

typedef struct { char p[60]; int w60; volatile unsigned w64; } Pp_002D04C0;
typedef struct { int w0; int w4; int w8; int w12; } Qq_002D04C0;
void *func_002CFF38(void); Qq_002D04C0 *func_002CFFC0(int, unsigned);
// MATCH func_002D04C0
int SndVoiceSetParam(int a, int b, int c, int d) { Pp_002D04C0 *p = func_002CFF38(); Qq_002D04C0 *q = func_002CFFC0(p->w60, p->w64); if (p->w64 >= 255) return -1; q->w0 = a; q->w4 = b; q->w8 = c; q->w12 = d; p->w64++; return p->w64; }
