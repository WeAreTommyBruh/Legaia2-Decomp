/* Functions of this report unit, matched by hand. */
#include "../common.h"

// MATCH func_0025E4C0
void FUN_0025e4c0(float *o, float a) { o[0] = a; o[1] = 1.0f; }

int func_00251F88(int);
// MATCH func_00251FE8
int FUN_00251fe8(int a, int b) { return (func_00251F88(b) >> a) & 1; }

int func_00251FA8(int);
// MATCH func_00252018
int FUN_00252018(int a, int b) { return (func_00251FA8(b) >> a) & 1; }

int func_00251FC8(int, int);
// MATCH func_00252048
int FUN_00252048(int a, int b, int c) { return (func_00251FC8(b, c) >> a) & 1; }

int func_00254040(int);
// MATCH func_00254000
int FUN_00254000(int a) { if (func_00254040(a) >= 99) return 0; return 99 - func_00254040(a); }

typedef struct { char p[148]; int w[8]; } T_0025DCE0; extern T_0025DCE0 D_003FEBA8;
// MATCH func_0025DCE0
int FUN_0025dce0(int a) { return (D_003FEBA8.w[a / 32] >> (a & 31)) & 1; }

typedef struct { char pad[372]; unsigned short a[1200]; unsigned char b[1200]; } T_250c00_00250C00;
extern T_250c00_00250C00 D_003FEBA8_00250C00 __asm__("D_003FEBA8");
// MATCH func_00250C00
int FUN_00250c00(int x) { int n; for (n = 0; n < 1200; n++) { if (D_003FEBA8_00250C00.a[n] == x) { if (x >= 301) return D_003FEBA8_00250C00.b[n]; if (D_003FEBA8_00250C00.b[n] != 0) return 1; } } return 0; }

typedef struct { char pad[372]; unsigned short a[1200]; unsigned char b[1200]; } T_250ab0_00250AB0;
extern unsigned short D_004A598E; extern unsigned short D_00401028[]; extern T_250ab0_00250AB0 D_003FEBA8_00250AB0 __asm__("D_003FEBA8");
// MATCH func_00250AB0
unsigned FUN_00250ab0(unsigned i) { if (i < D_004A598E) return D_003FEBA8_00250AB0.a[D_00401028[i]]; return 0; }

typedef struct { char pad[372]; unsigned short a[1200]; unsigned char b[1200]; } T_251e08_00251E08;
extern unsigned short D_004A598E_00251E08 __asm__("D_004A598E"); extern unsigned short D_00401028_00251E08[] __asm__("D_00401028"); extern T_251e08_00251E08 D_003FEBA8_00251E08 __asm__("D_003FEBA8");
int func_00251220(unsigned);
// MATCH func_00251E08
int FUN_00251e08(unsigned i) { if (i < D_004A598E_00251E08) return func_00251220(D_003FEBA8_00251E08.a[D_00401028_00251E08[i]]); return 0; }

typedef struct { char pad[372]; unsigned short a[1200]; unsigned char b[1200]; } T_250a68_00250A68;
extern unsigned short D_004A598E_00250A68 __asm__("D_004A598E"); extern T_250a68_00250A68 D_003FEBA8_00250A68 __asm__("D_003FEBA8");
int func_0024F380(unsigned);
// MATCH func_00250A68
int FUN_00250a68(unsigned i) { unsigned r; if (i < D_004A598E_00250A68) r = D_003FEBA8_00250A68.a[i]; else r = 0; return func_0024F380(r); }

extern int D_0040D610[]; extern char D_0047CC50[];
int func_0025AE60(int);
// MATCH func_0025B1C0
void *FUN_0025b1c0(int a, int b) { if (func_0025AE60(a) >= 0) return (void *)D_0040D610[b - 1]; return D_0047CC50; }

extern int D_0040D8B8[]; extern char D_0047CC50_0025B210[] __asm__("D_0047CC50");
int func_0025AE60(int);
// MATCH func_0025B210
void *FUN_0025b210(int a, int b) { if (func_0025AE60(a) >= 0) return (void *)D_0040D8B8[b - 1]; return D_0047CC50_0025B210; }

extern int D_0040D228[]; extern char D_0047CC50_0025B170[] __asm__("D_0047CC50");
int func_0025AE60(int);
// MATCH func_0025B170
void *FUN_0025b170(int a, int b) { if (func_0025AE60(a) >= 0) return (void *)D_0040D228[b - 1]; return D_0047CC50_0025B170; }

typedef struct { char pad[372]; unsigned short a[1200]; unsigned char b[1200]; } T_256298_00256298;
extern unsigned short D_004A598E_00256298 __asm__("D_004A598E"); extern unsigned short D_00401028_00256298[] __asm__("D_00401028"); extern T_256298_00256298 D_003FEBA8_00256298 __asm__("D_003FEBA8");
int func_00256260(unsigned);
// MATCH func_00256298
int FUN_00256298(unsigned i) { if (i < D_004A598E_00256298) return func_00256260(D_003FEBA8_00256298.a[D_00401028_00256298[i]]); return 0; }

typedef struct { char pad[20]; int a20; int a24; } S_0025E448;
extern char D_00343010[];
void func_001E3F20(void *, int); void func_00108B80_0025E448(void *) __asm__("func_00108B80");
// MATCH func_0025E448
void FUN_0025e448(S_0025E448 *s, int fl) { if (s->a20 != 0) func_001E3F20(D_00343010, s->a20); if (s->a24 != 0) func_001E3F20(D_00343010, s->a24); if (fl & 1) func_00108B80_0025E448(s); }

extern int D_003244F0[];
// MATCH func_0024E098
int FUN_0024e098(int a) { if (a == D_003244F0[10] || a == D_003244F0[11]) return 1; return 0; }

typedef struct { char c[8]; } V8_0025E3F8;
typedef struct { int w0; float f4; int w8, w12, w16, w20, w24, w28, w32; V8_0025E3F8 v36; } O_0025E3F8;
extern V8_0025E3F8 D_004A59B0[2];
// MATCH func_0025E3F8
O_0025E3F8 *FUN_0025e3f8(O_0025E3F8 *o) { o->w0 = 0; o->f4 = 1.0f; o->w8 = 0; o->w12 = 0; o->w16 = 0; o->w20 = 0; o->w24 = 0; o->w28 = 0; o->w32 = 0; o->v36 = D_004A59B0[0]; return o; }

extern char *D_004A1A20_0024CFC8 __asm__("D_004A1A20"); int func_0024D4C0(int, int, int, float);
// MATCH func_0024CFC8
int FUN_0024cfc8(void) { int r = 0; int i; for (i = 0; i < 10; i++) { if (func_0024D4C0(i, 0, 2, 1.0f) >= 0) { r = 1; *(unsigned *)(D_004A1A20_0024CFC8 + i * 5472 + 4816) |= 0x80; } } return r; }

typedef struct { char p[20]; int w20, w24, w28, w32; } O_0025E510;
extern char D_00343010_0025E510[] __asm__("D_00343010"); void func_001E3380_0025E510(char *, int, int) __asm__("func_001E3380");
// MATCH func_0025E510
void FUN_0025e510(O_0025E510 *o, int b, int c, int d) { o->w24 = c; o->w28 = d; o->w20 = b; o->w32 = 0; func_001E3380_0025E510(D_00343010_0025E510, b, 0); func_001E3380_0025E510(D_00343010_0025E510, c, 0); }

typedef struct { unsigned short h0, h2, h4, h6, h8, h10; } E_00254708;
extern E_00254708 D_003E3BC0[];
// MATCH func_00254708
int FUN_00254708(unsigned a) { E_00254708 *e = D_003E3BC0; E_00254708 *end = e + 29; do { unsigned w = e->h10 - e->h8 + 1; if (a < w) return e->h8 + a; a -= w; e++; } while (e < end); return 0; }

typedef struct { unsigned short h0, h2, h4, h6, h8, h10; } E_00254750;
extern E_00254750 D_003E3BC0_00254750[] __asm__("D_003E3BC0");
extern unsigned short D_004A5994;
// MATCH func_00254750
unsigned FUN_00254750(void) { E_00254750 *e = D_003E3BC0_00254750; E_00254750 *end = e + 29; D_004A5994 = 0; do { D_004A5994 += e->h10 - e->h8 + 1; e++; } while (e < end); return D_004A5994; }

typedef struct { unsigned short h0, h2, h4, h6, h8, h10; } E_00254938;
extern E_00254938 D_003E3BC0_00254938[] __asm__("D_003E3BC0");
// MATCH func_00254938
int FUN_00254938(unsigned a) { unsigned i = 0; E_00254938 *e = D_003E3BC0_00254938; a &= 0xffff; do { i++; if (a >= e->h8 && a <= e->h10) return 1; e++; } while (i < 29); if (i == 29) return 0; }

typedef struct { int w0, w4, w8; char p[68]; } E_0025A3B0;
extern E_0025A3B0 D_003EC550[];
// MATCH func_0025A3B0
int FUN_0025a3b0(int a) { unsigned i, c = 0; for (i = 0; i < 861; i++) if (D_003EC550[i].w8 == a) c++; return c; }

extern char D_00343028_0025DFB8[] __asm__("D_00343028"); void func_0010C2B0(char *, int, int, int, int, int, int);
// MATCH func_0025DFB8
int FUN_0025dfb8(int *o) { if (o[11] == 0 && o[10] != 0) { o[11] = 1; func_0010C2B0(D_00343028_0025DFB8, 163, 12, 0, 0, 0, 0); } if (o[10] == 0) o[11] = 0; return 0; }

extern char D_003FD260[]; void func_0025AF78(int, int);
// MATCH func_0025B108
void FUN_0025b108(int a) { char *p = D_003FD260 + a * 2; int i; for (i = 0; i < 30; i++) func_0025AF78(a, p[0] + i); }

extern char D_003E9DF0[];
// MATCH func_0025A488
int FUN_0025a488(void)
{
    int buf[64];
    unsigned i; int n;
    char *p, *q;
    for (i = 63; (int)i >= 0; i--) buf[i] = 0;
    n = 0;
    q = D_003E9DF0;
    p = q + 8;
    for (i = 0; i < 60; i++) {
        int idx = *(int *)p;
        if (buf[idx] == 0) {
            buf[idx] = 1;
            n++;
        }
        p += 168;
    }
    return n;
}

typedef struct { char c[8]; } V8_0025E5A8;
typedef struct { char p[8]; int w8; char q[8]; int w20, w24; char r[8]; V8_0025E5A8 v36; } O__0025E5A8;
extern V8_0025E5A8 D_004A59B8[3];
void func_001E3380_0025E5A8(void *, int, int) __asm__("func_001E3380");
extern char D_00343010_0025E5A8[] __asm__("D_00343010");
// MATCH func_0025E5A8
int FUN_0025e5a8(O__0025E5A8 *o)
{
    int n = o->w8 - 1;
    o->w8 = n;
    if (n > 0) return 1;
    if (o->w20 != 0) func_001E3380_0025E5A8(D_00343010_0025E5A8, o->w20, 1);
    if (o->w24 != 0) func_001E3380_0025E5A8(D_00343010_0025E5A8, o->w24, 0);
    o->v36 = D_004A59B8[0];
    return 1;
}

typedef struct { char c[8]; } V8_0025E678_0025E678;
typedef struct { char p[4]; float f4; int w8; char q[8]; int w20, w24; char r[8]; V8_0025E678_0025E678 v36; } O__0025E678_0025E678;
extern V8_0025E678_0025E678 D_004A59C0[3];
extern float D_004A0980;
extern char D_00343010_0025E678[] __asm__("D_00343010");
void func_001E3380_0025E678(void *, int, int) __asm__("func_001E3380");
// MATCH func_0025E678
int FUN_0025e678(O__0025E678_0025E678 *o)
{
    float f = o->f4 - D_004A0980;
    int n;
    o->f4 = f;
    if (f < D_004A0980) {
        o->f4 = D_004A0980;
        n = o->w8 - 1;
        o->w8 = n;
        if (n == 0) {
            o->w8 = 0;
            if (o->w20 != 0) func_001E3380_0025E678(D_00343010_0025E678, o->w20, 1);
            if (o->w24 != 0) func_001E3380_0025E678(D_00343010_0025E678, o->w24, 0);
            o->v36 = D_004A59C0[0];
        }
    }
    return 1;
}

typedef struct { short a, b, v; } E_0025BA90;
extern E_0025BA90 D_003FD930[];
// MATCH func_0025BA90
int FUN_0025ba90(int a, int b, int c) { int i, lo, hi; if (a < b) { lo = a; hi = b; } else { lo = b; hi = a; } i = 0; while (D_003FD930[i].a != -1) { if (lo == D_003FD930[i].a && hi == D_003FD930[i].b) return D_003FD930[i].v; i++; } return c; }

typedef struct { char p[6680]; unsigned short a, b, c, d; } E9_002530C8;
extern char D_003FEBA8_002530C8[] __asm__("D_003FEBA8");
void func_00255278(int); int func_00254990_002530C8(int) __asm__("func_00254990"); int func_00254F48(int); int func_00254E38_S6(int) __asm__("func_00254E38"); int func_00250AB0(int);
// MATCH func_002530C8
int FUN_002530c8(int p1, int idx) { E9_002530C8 *e; int r; func_00255278(7); e = (E9_002530C8 *)(D_003FEBA8_002530C8 + idx * 472); r = func_00254990_002530C8(e->a); if (r == 0) { r = func_00254F48(p1); if (r == 0) { e->a = func_00250AB0(p1); func_00255278(8); return 1; } func_00254E38_S6(e->a); } func_00255278(8); return 0; }

typedef struct { char p[6680]; unsigned short a, b, c, d; } E9_00253160;
extern char D_003FEBA8_00253160[] __asm__("D_003FEBA8");
void func_00255278(int); int func_00254990_00253160(int) __asm__("func_00254990"); int func_00254F48(int); int func_00254E38_S6(int) __asm__("func_00254E38"); int func_00250AB0(int);
// MATCH func_00253160
int FUN_00253160(int p1, int idx) { E9_00253160 *e; int r; func_00255278(7); e = (E9_00253160 *)(D_003FEBA8_00253160 + idx * 472); r = func_00254990_00253160(e->b); if (r == 0) { r = func_00254F48(p1); if (r == 0) { e->b = func_00250AB0(p1); func_00255278(8); return 1; } func_00254E38_S6(e->b); } func_00255278(8); return 0; }

typedef struct { char p[6680]; unsigned short a, b, c, d; } E9_002531F8;
extern char D_003FEBA8_002531F8[] __asm__("D_003FEBA8");
void func_00255278(int); int func_00254990_002531F8(int) __asm__("func_00254990"); int func_00254F48(int); int func_00254E38_S6(int) __asm__("func_00254E38"); int func_00250AB0(int);
// MATCH func_002531F8
int FUN_002531f8(int p1, int idx) { E9_002531F8 *e; int r; func_00255278(7); e = (E9_002531F8 *)(D_003FEBA8_002531F8 + idx * 472); r = func_00254990_002531F8(e->c); if (r == 0) { r = func_00254F48(p1); if (r == 0) { e->c = func_00250AB0(p1); func_00255278(8); return 1; } func_00254E38_S6(e->c); } func_00255278(8); return 0; }

typedef struct { char p[6680]; unsigned short a, b, c, d; } E9_00253290;
extern char D_003FEBA8_00253290[] __asm__("D_003FEBA8");
void func_00255278(int); int func_00254990_00253290(int) __asm__("func_00254990"); int func_00254F48(int); int func_00254E38_S6(int) __asm__("func_00254E38"); int func_00250AB0(int);
// MATCH func_00253290
int FUN_00253290(int p1, int idx) { E9_00253290 *e; int r; func_00255278(7); e = (E9_00253290 *)(D_003FEBA8_00253290 + idx * 472); r = func_00254990_00253290(e->d); if (r == 0) { r = func_00254F48(p1); if (r == 0) { e->d = func_00250AB0(p1); func_00255278(8); return 1; } func_00254E38_S6(e->d); } func_00255278(8); return 0; }

typedef struct { char p[12]; signed char f; char q[7]; } E11_00255E18;
extern E11_00255E18 D_003E3D20[];
void *func_00255C68(void);
// MATCH func_00255E18
char FUN_00255e18(int a, int idx) { char *p = func_00255C68(); E11_00255E18 *e = &D_003E3D20[p[idx * 2]]; return e->f; }

typedef struct { char p[6777]; unsigned char f; } E10_0025B7F0;
extern char D_003FEBA8_0025B7F0[] __asm__("D_003FEBA8");
// MATCH func_0025B7F0
int FUN_0025b7f0(unsigned n) { int v; if (9 < n) return -1; if ((int)n < 5) return ((E10_0025B7F0 *)(D_003FEBA8_0025B7F0 + (int)n * 472))->f; v = 2; if (n != 5) v = 0; return v; }

extern char D_003FEBA8_002547F0[] __asm__("D_003FEBA8");
// MATCH func_002547F0
int FUN_002547f0(int idx) { int n, k; char *q; unsigned short *p; unsigned short v; n = 0; k = 15; q = D_003FEBA8_002547F0; q += 6680; p = (unsigned short *)(q + idx * 472); do { v = *p; p++; k--; if (v != 0) n++; } while (k >= 0); return n; }

typedef struct { char p[158]; unsigned char f; char q[17]; } E12_00255988;
extern E12_00255988 D_00419D18_00255988[] __asm__("D_00419D18");
// MATCH func_00255988
int FUN_00255988(unsigned n) { unsigned char new_var; E12_00255988 *e; if (0x14 < n) { return -1; } new_var = 8; e = &D_00419D18_00255988[n]; return new_var < e->f; }

typedef struct { int w0, w4, w8, w12, w16; } E18_002558F8;
extern E18_002558F8 D_003E3D20_002558F8[] __asm__("D_003E3D20"); extern char D_0047B0E0[];
// MATCH func_002558F8
int FUN_002558f8(unsigned a, int b) { if (a >= 10 || b < 0 || (unsigned)b >= 94) return (int)D_0047B0E0; return D_003E3D20_002558F8[b].w0; }

typedef struct { int w0, w4, w8, w12, w16; } E18_00255940;
extern E18_00255940 D_003E3D20_00255940[] __asm__("D_003E3D20"); extern char D_0047B0F0[];
// MATCH func_00255940
int FUN_00255940(unsigned a, int b) { if (a >= 10 || b < 0 || (unsigned)b >= 94) return (int)D_0047B0F0; return D_003E3D20_00255940[b].w4; }

typedef struct { int w0, w4, w8, w12, w16; } E18_00255C08;
extern E18_00255C08 D_003E3D20_00255C08[] __asm__("D_003E3D20");
// MATCH func_00255C08
int FUN_00255c08(unsigned a, int b) { if (a >= 10 || b < 0 || (unsigned)b >= 94) return -1; return D_003E3D20_00255C08[b].w16; }

extern char D_003FEBA8_002533E8[] __asm__("D_003FEBA8");
void func_00255278(int); int func_00254F48(int); short func_00250AB0_002533E8(int) __asm__("func_00250AB0"); void func_00254CB8(int);
// MATCH func_002533E8
int FUN_002533e8(int a, int idx) { int i; unsigned short *p; char *q; func_00255278(7); if (func_00254F48(a) == 0) { i = 4; q = D_003FEBA8_002533E8; p = (unsigned short *)(q + idx * 472 + 6688); do { i++; if (*p == 0) { *p = func_00250AB0_002533E8(a); func_00255278(8); return 1; } p++; } while (i < 16); func_00254CB8(a); } func_00255278(8); return 0; }

extern char D_003FEBA8_0025D4B0[] __asm__("D_003FEBA8");
int func_0025D128(int, int);
// MATCH func_0025D4B0
int FUN_0025d4b0(int a, int b) { char **new_var2; unsigned char *p; int i; int n; int r; char *new_var; char *q; if (b < 0) { q = D_003FEBA8_0025D4B0; *((short *) ((q + (a * 472)) + 6676)) = 0; return 1; } p = (unsigned char *)func_0025D128(a, 5); n = 0; i = 99; new_var = D_003FEBA8_0025D4B0 + (a * 472); q = new_var; do { i--; new_var2 = &q; if ((*p) == b) { *((short *) ((*new_var2) + 6676)) = b; n++; } p += 2; } while (i >= 0); r = -1; if (n != 0) { r = 0; } return r; }

extern char D_003FEBA8_0025D550[] __asm__("D_003FEBA8");
int func_0025D128(int, int);
// MATCH func_0025D550
int FUN_0025d550(int a, int b) { char **new_var2; unsigned char *p; int i; int n; int r; char *new_var; char *q; if (b < 0) { q = D_003FEBA8_0025D550; *((short *) ((q + (a * 472)) + 6678)) = 0; return 1; } p = (unsigned char *)func_0025D128(a, 9); n = 0; i = 99; new_var = D_003FEBA8_0025D550 + (a * 472); q = new_var; do { i--; new_var2 = &q; if ((*p) == b) { *((short *) ((*new_var2) + 6678)) = b; n++; } p += 2; } while (i >= 0); r = -1; if (n != 0) { r = 0; } return r; }

extern unsigned short D_003FDFA0_24EFF8[] __asm__("D_003FDFA0");
// MATCH func_0024EFF8
unsigned short FUN_0024eff8(unsigned i) { unsigned short *p; if (i < 5) { p = D_003FDFA0_24EFF8 + i * 36; return p[16]; } return 0; }

extern int D_003279A0_24D618[] __asm__("D_003279A0"); float func_0022F5A0_24D618(float, float) __asm__("func_0022F5A0"); float func_0024E158_24D618(int, int) __asm__("func_0024E158");
// MATCH func_0024D618
int FUN_0024d618(int a, int b) { int p, q; float x, y; p = D_003279A0_24D618[a]; if (p == 0 || (q = D_003279A0_24D618[b]) == 0) return 0; x = func_0022F5A0_24D618(*(float *)(q + 0x80) - *(float *)(p + 0x80), *(float *)(q + 0x88) - *(float *)(p + 0x88)); y = func_0024E158_24D618(a, b); if (x < y) return 1; return 0; }

