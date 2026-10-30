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

// MATCH func_00156B58
void FUN_00156b58(char *o, unsigned c) { float r = (float)(c & 0xff); float g = (float)((c >> 8) & 0xff); float b = (float)((c >> 16) & 0xff); float *p = (float *)(o + 176); 
*(float *)(o + 176) = r;
p[1] = g;
p[2] = b;
p[3] = 128.0f;}

// MATCH func_00156408
void FUN_00156408(char *o, unsigned c, unsigned d) { float r = (float)(c & 0xff); float g = (float)((c >> 8) & 0xff); float b = (float)((c >> 16) & 0xff); float *p = (float *)(o + 64); float r2; float g2; float b2; float *q; *(float *)(o + 64) = r; p[1] = g; p[2] = b; p[3] = 128.0f; r2 = (float)(d & 0xff); g2 = (float)((d >> 8) & 0xff); b2 = (float)((d >> 16) & 0xff); q = (float *)(o + 80); *(float *)(o + 80) = r2; q[1] = g2; q[2] = b2; q[3] = 128.0f; }

extern int D_00426440[]; extern volatile int D_00426394[]; extern volatile int D_00426370[]; extern volatile int D_00426368[]; extern char D_00427510[];
int func_002CBAE8(void); int func_002CB978(int); void func_002E8038(void *, int); void func_002CB108(void); void func_002E58C0(int);
int func_002E8928(void *, int, int, void *, int, int, int, void *, void *);
// MATCH func_002CC6D8
int FUN_002cc6d8(int a) { int *p = D_00426440; if (func_002CBAE8() == 6) return 0; if (func_002CB978(9) == 0) return 0; D_00426440[0] = a; func_002E8038(p, 4); D_00426394[0] = 4; D_00426370[0] = 1; if (func_002E8928(D_00427510, 5, 1, p, 4, 0, 0, (void *)func_002CB108, D_00426394) < 0) { D_00426394[0] = 0; D_00426370[0] = 0; func_002E58C0(D_00426368[0]); return 0; } return 1; }

unsigned func_002CADE8(void);
// MATCH func_002CAE38
int FUN_002cae38(int *o) { unsigned v = *(volatile unsigned *)0x10003840; if (func_002CADE8() >= 2) return 0; o[0] = *(volatile int *)0x10003900; o[1] = *(volatile int *)0x10003910; o[2] = *(volatile int *)0x10003920; o[3] = *(volatile int *)0x10003930; o[4] = *(volatile int *)0x10003940; o[5] = *(volatile int *)0x10003950; o[6] = *(volatile int *)0x10003960; o[7] = *(volatile int *)0x10003970; o[8] = *(volatile int *)0x10003870; o[9] = *(volatile int *)0x10003880; o[10] = *(volatile int *)0x10003800; ((short *)o)[22] = *(volatile int *)0x100038d0; ((short *)o)[23] = *(volatile int *)0x10003890; ((short *)o)[24] = *(volatile int *)0x10003830; ((short *)o)[25] = *(volatile int *)0x10003860; ((char *)o)[52] = *(volatile int *)0x10003820; ((char *)o)[53] = v; ((char *)o)[54] = v >> 8; ((char *)o)[55] = *(volatile int *)0x10003850; return 1; }

int func_002EDC50(void); void func_002EDC98(void); void func_002C2D58(int, int *); void func_002C6E50(char *); void func_002C6E20(char *, int);
// MATCH func_002C3BF0
void FUN_002c3bf0(char *o, int a, unsigned b) { int st[8]; int r; st[0] = 2; func_002C2D58(*(int *)(o + 2136), st); func_002C6E50(o); *(volatile int *)0x10002000 = 0; func_002C6E50(o); r = func_002EDC50(); *(volatile unsigned *)0x1000b410 = b & 0x0fffffff; *(volatile int *)0x1000b420 = 4; *(volatile int *)0x1000b400 = 257; if (r != 0) func_002EDC98(); func_002C6E20(o, a); func_002C6E50(o); st[0] = 3; func_002C2D58(*(int *)(o + 2136), st); }

typedef struct { char c[8]; } V8_00164AD0;
typedef struct { char p[20]; int w20; } P_00164AD0;
typedef struct { P_00164AD0 *p; char pad4[4]; short s8; short s10; int w12; int w16; int w20; int w24; char pad28[4]; int w32; char pad36[4]; V8_00164AD0 v40; } O_00164AD0;
extern V8_00164AD0 D_004A2CD0_00164AD0[3] __asm__("D_004A2CD0");
// MATCH func_00164AD0
void pachislot_00164ad0(O_00164AD0 *o) { int x; if (o->w24 >= 0) { if (o->w12 == o->s10) return; if (o->w16 != o->s10) return; if (o->w20 > 0) { o->w20--; return; } o->s8 = 0; o->w32 = -1; o->w24 = 0; o->v40 = D_004A2CD0_00164AD0[0]; return; } x = o->w16 - 1; if (x < 0) x += o->p->w20; if (o->w12 == o->s10) return; if (x != o->s10) return; if (o->w20 > 0) { o->w20--; return; } o->w32 = -1; o->s10 = (unsigned short)o->w16; o->s8 = 0; o->w24 = 0; o->v40 = D_004A2CD0_00164AD0[0]; }

extern volatile int D_00426394_002CC858[] __asm__("D_00426394"); extern volatile int D_00426370_002CC858[] __asm__("D_00426370"); extern volatile int D_00426368_002CC858[] __asm__("D_00426368"); extern char D_00427510_002CC858[] __asm__("D_00427510");
int func_002CBAE8(void); int func_002CB978(int); int func_002E8928_002CC858(char *, int, int, int, int, int, int, void *, int *) __asm__("func_002E8928"); void func_002E58C0(int); void func_002CB108(void);
// MATCH func_002CC858
int FUN_002cc858(void) { if (func_002CBAE8() == 6) return 0; if (func_002CB978(11) == 0) return 0; D_00426394_002CC858[0] = 6; D_00426370_002CC858[0] = 1; if (func_002E8928_002CC858(D_00427510_002CC858, 7, 1, 0, 0, 0, 0, func_002CB108, D_00426394_002CC858) < 0) { D_00426394_002CC858[0] = 0; D_00426370_002CC858[0] = 0; func_002E58C0(D_00426368_002CC858[0]); return 0; } return 1; }

extern volatile int D_00426394_002CC7A8[] __asm__("D_00426394"); extern volatile int D_00426370_002CC7A8[] __asm__("D_00426370"); extern volatile int D_00426368_002CC7A8[] __asm__("D_00426368"); extern char D_00427510_002CC7A8[] __asm__("D_00427510");
int func_002CBAE8(void); int func_002CB978(int); int func_002E8928_002CC7A8(char *, int, int, int, int, int, int, void *, int *) __asm__("func_002E8928"); void func_002E58C0(int); void func_002CB108(void);
// MATCH func_002CC7A8
int FUN_002cc7a8(void) { if (func_002CBAE8() == 6) return 0; if (func_002CB978(10) == 0) return 0; D_00426394_002CC7A8[0] = 5; D_00426370_002CC7A8[0] = 1; if (func_002E8928_002CC7A8(D_00427510_002CC7A8, 6, 1, 0, 0, 0, 0, func_002CB108, D_00426394_002CC7A8) < 0) { D_00426394_002CC7A8[0] = 0; D_00426370_002CC7A8[0] = 0; func_002E58C0(D_00426368_002CC7A8[0]); return 0; } return 1; }
