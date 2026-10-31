/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p[68]; int a[1]; } O_00172388; int func_00171AD0(void *);
// MATCH func_00172388
int roulette_00172388(O_00172388 *o) { int i = func_00171AD0(o); return o->a[i]; }

typedef struct { char c[8]; } V8_00170468;
typedef struct { char p[60]; int w; char p2[72]; V8_00170468 a; V8_00170468 b; } O_00170468; extern V8_00170468 D_004A30C0[2], D_004A30E0[2];
// MATCH func_00170468
int roulette_00170468(O_00170468 *o) { o->w = 0; o->a = D_004A30C0[0]; o->b = D_004A30E0[0]; return 0; }

typedef struct { char c[8]; } V8_001704A8;
typedef struct { char p[136]; V8_001704A8 a; V8_001704A8 b; } O_001704A8; extern V8_001704A8 D_004A30B0[2], D_004A30E8[2]; extern int D_004A3074;
// MATCH func_001704A8
int roulette_001704a8(O_001704A8 *o) { D_004A3074 = 1; o->a = D_004A30B0[0]; o->b = D_004A30E8[0]; return 0; }

typedef struct { char c[8]; } V8_0016FB20;
typedef struct { char p[60]; int w; char p2[72]; V8_0016FB20 a; V8_0016FB20 b; } O_0016FB20;
extern V8_0016FB20 D_004A3080[2], D_004A3088[2]; void func_0016FA70(void *);
// MATCH func_0016FB20
int roulette_0016fb20(O_0016FB20 *o) { o->w = 13107; func_0016FA70(o); o->a = D_004A3080[0]; o->b = D_004A3088[0]; return 0; }

typedef struct { char c[8]; } V8_00171610;
typedef struct { char p[56]; short adj; short pad; void (*fn)(void *); } VT_00171610;
typedef struct { int w; char p[40]; V8_00171610 v; char p2[8]; VT_00171610 *vt; } O_00171610;
extern V8_00171610 D_004A3108[2];
// MATCH func_00171610
int roulette_00171610(O_00171610 *o) { o->w = 13107; o->vt->fn((char *)o + o->vt->adj); o->v = D_004A3108[0]; return 0; }

typedef struct { char c[8]; } V8_0016FB80;
typedef struct { char p[84]; int w; char p2[48]; V8_0016FB80 a; V8_0016FB80 b; } O_0016FB80;
int func_00170940(void *); void func_00170AE0(void *);
// MATCH func_0016FB80
int roulette_0016fb80(O_0016FB80 *o) { int r = func_00170940(o); o->w = o->w - 8; if (o->w < 161) { o->w = 160; if (r != 0) { func_00170AE0(o); o->a = o->b; } } return 0; }

typedef struct { char c[8]; } V8_0016FBE8;
typedef struct { char p[84]; int w; char p2[48]; V8_0016FBE8 a; V8_0016FBE8 b; } O_0016FBE8;
int func_00170940(void *); void func_00170AE0(void *);
// MATCH func_0016FBE8
int roulette_0016fbe8(O_0016FBE8 *o) { int r = func_00170940(o); o->w = o->w + 8; if (o->w >= 640) { o->w = 640; if (r != 0) { func_00170AE0(o); o->a = o->b; } } return 0; }

typedef struct { char pad[10]; short h; } S_171ad0_00171AD0;
// MATCH func_00171AD0
int roulette_00171ad0(S_171ad0_00171AD0 *s) { int v = s->h; if (v != 0) v = 12 - v; return v; }

// MATCH func_00171FF8
void roulette_00171ff8(char *s, int *src) { int i; int *d = (int *)(s + 68); for (i = 0; i < 12; i++) { int v = src[i]; if (v < 1) v = 1; if (v > 23) v = 23; d[i] = v; } }

typedef struct { char pad[104]; char sub[1]; char pad1[23]; int a128; } S_16f9f8_0016F9F8;
extern char D_0043D5B8[];
void func_002971C0(int, int); void func_001621F8(int, void *, int); void func_00164500(void *, int); void func_00108B80_0016F9F8(void *) __asm__("func_00108B80");
// MATCH func_0016F9F8
void roulette_0016f9f8(S_16f9f8_0016F9F8 *s, int fl) { func_002971C0(18, 50); func_001621F8(s->a128, D_0043D5B8, 479); func_00164500(s->sub, 2); if (fl & 1) func_00108B80_0016F9F8(s); }

typedef struct { char pad[28]; char sub[1]; char pad1[7]; int a36; char pad2[20]; char *a60; } S_00171548;
extern char D_0043D6A0[], D_0043D5B8[];
void func_002971C0(int, int); void func_001621F8(int, void *, int); void func_00164500(void *, int); void func_00108B80_00171548(void *) __asm__("func_00108B80");
// MATCH func_00171548
void roulette_00171548(S_00171548 *s, int fl) { s->a60 = D_0043D6A0; func_002971C0(18, 50); func_001621F8(s->a36, D_0043D5B8, 1265); func_00164500(s->sub, 2); if (fl & 1) func_00108B80_00171548(s); }

typedef struct { char c[8]; } V8_172148_00172148;
typedef struct { char p[48]; short adj; short pad; int (*fn)(void *); } VT_172148_00172148;
typedef struct { char p[16]; int w; char p2[24]; V8_172148_00172148 a; char p3[8]; VT_172148_00172148 *vt; } O_172148_00172148;
extern V8_172148_00172148 D_004A3128[2]; void func_00171AB8(void *);
// MATCH func_00172148
int roulette_00172148(O_172148_00172148 *o) { int r = o->vt->fn((char *)o + o->vt->adj); o->w = o->w - 8; if (o->w < 161) { o->w = 160; if (r != 0) { func_00171AB8(o); o->a = D_004A3128[0]; } } return 0; }

typedef struct { char c[8]; } V8_171668_00171668;
typedef struct { char p[48]; short adj; short pad; int (*fn)(void *); } VT_171668_00171668;
typedef struct { char p[16]; int w; char p2[24]; V8_171668_00171668 a; char p3[8]; VT_171668_00171668 *vt; } O_171668_00171668;
extern V8_171668_00171668 D_004A3110[2]; void func_00171AB8(void *);
// MATCH func_00171668
int roulette_00171668(O_171668_00171668 *o) { int r = o->vt->fn((char *)o + o->vt->adj); o->w = o->w - 8; if (o->w < 161) { o->w = 160; if (r != 0) { func_00171AB8(o); o->a = D_004A3110[0]; } } return 0; }

typedef struct { char c[8]; } V8_170358_00170358;
typedef struct { char p[80]; int w80; char p2[4]; int w88; char p3[44]; V8_170358_00170358 a; V8_170358_00170358 b; } O_170358_00170358;
extern V8_170358_00170358 D_004A3080_00170358[2] __asm__("D_004A3080"), D_004A30D0[2]; extern int D_004A3070_00170358 __asm__("D_004A3070");
// MATCH func_00170358
int roulette_00170358(O_170358_00170358 *o) { if (D_004A3070_00170358 != 2) { o->w88 = 1; o->w80 = 10; o->a = D_004A3080_00170358[0]; o->b = D_004A30D0[0]; } return 0; }

typedef struct { char c[8]; } V8_1716e8_001716E8;
typedef struct { char p[16]; int w; char p2[24]; V8_1716e8_001716E8 a; } O_1716e8_001716E8;
extern V8_1716e8_001716E8 D_004A3110_001716E8[2] __asm__("D_004A3110"); void func_00171AB8(void *);
// MATCH func_001716E8
int roulette_001716e8(O_1716e8_001716E8 *o) { o->w = o->w + 8; if (o->w >= 640) { o->w = 640; func_00171AB8(o); o->a = D_004A3110_001716E8[0]; } return 0; }

typedef struct { char p[80]; int w80; char p2[4]; int w88; int w92; int w96; char p3[16]; int w116; } O_0016FA70;
void func_0016FAB0(void *);

// MATCH func_0016FA70
void roulette_0016fa70(O_0016FA70 *o) { func_0016FAB0(o); o->w80 = 12; o->w96 = 0; o->w88 = 0; o->w92 = 0; o->w116 = 1; }

typedef struct { char c[8]; } V8_0016FC50;
typedef struct { char p[136]; V8_0016FC50 v; } O_0016FC50;
extern int D_003355F8[]; extern V8_0016FC50 D_004A3088_0016FC50[2] __asm__("D_004A3088"); int func_00170940_0016FC50(O_0016FC50 *) __asm__("func_00170940"); void func_00170AE0_0016FC50(O_0016FC50 *) __asm__("func_00170AE0"); int func_00170B50(O_0016FC50 *);
// MATCH func_0016FC50
int roulette_0016fc50(O_0016FC50 *o) { if (func_00170940_0016FC50(o) != 0) { int k; func_00170AE0_0016FC50(o); k = func_00170B50(o); if ((unsigned)(D_003355F8[k] - 2) >= 2) o->v = D_004A3088_0016FC50[0]; } return 0; }

typedef struct { char c[8]; } V8_0016FCC8;
typedef struct { char p[136]; V8_0016FCC8 v; } O_0016FCC8;
extern int D_003355F8_0016FCC8[] __asm__("D_003355F8"); extern V8_0016FCC8 D_004A3088_0016FCC8[2] __asm__("D_004A3088"); int func_00170A40(O_0016FCC8 *); void func_00170AF8(O_0016FCC8 *); int func_00170B50_0016FCC8(O_0016FCC8 *) __asm__("func_00170B50");
// MATCH func_0016FCC8
int roulette_0016fcc8(O_0016FCC8 *o) { if (func_00170A40(o) != 0) { int k; func_00170AF8(o); k = func_00170B50_0016FCC8(o); if ((unsigned)(D_003355F8_0016FCC8[k] - 2) >= 2) o->v = D_004A3088_0016FCC8[0]; } return 0; }

typedef struct { char c[8]; } V8_001708B8;
typedef struct { char p[96]; int w96; char q[36]; V8_001708B8 v; } O_001708B8;
extern unsigned long long D_004A12D8_001708B8 __asm__("D_004A12D8"); extern V8_001708B8 D_004A30B8[2];
// MATCH func_001708B8
int roulette_001708b8(O_001708B8 *o) { if (++o->w96 >= 61 || (D_004A12D8_001708B8 & 0x200040)) { o->v = D_004A30B8[0]; return 1; } return 0; }

typedef struct { char p[88]; int w88; } O_00170548;
extern int D_004A3070_00170548 __asm__("D_004A3070"); extern int D_003355F8_00170548[] __asm__("D_003355F8"); int func_00170B50_00170548(O_00170548 *) __asm__("func_00170B50");
// MATCH func_00170548
int roulette_00170548(O_00170548 *o, int b) { int k = func_00170B50_00170548(o); int r; if (o->w88 != 0) r = D_004A3070_00170548 == D_003355F8_00170548[k]; else r = b == k; return r; }

typedef struct { char p[40]; int w40; char q[16]; char *w60; int w64; char r[52]; int w120; } O_00171EE8;
extern char D_0043D658[]; int func_001714A0(O_00171EE8 *); void func_00171980(O_00171EE8 *, int); void func_00171FF8(O_00171EE8 *, int);
// MATCH func_00171EE8
O_00171EE8 *roulette_00171ee8(O_00171EE8 *o, int x) { func_001714A0(o); o->w60 = D_0043D658; o->w64 = 250; func_00171980(o, 1); func_00171FF8(o, x); o->w40 = 0; o->w120 = 0; return o; }

typedef struct { char p[72]; short h72, h74; int w76; int w80; int w84; int w88; } O_00170B50;
// MATCH func_00170B50
int roulette_00170b50(O_00170B50 *o) { int x = o->h74; if (x != 0) x = o->w80 - x; if (o->w88 != 0) x += (x < o->w80 / 2) ? 1 : 2; return x; }

typedef struct { char c[8]; } V8_00170000;
int func_00170940_00170000(int *) __asm__("func_00170940"); void func_00170AE0_00170000(int *) __asm__("func_00170AE0");
// MATCH func_00170000
int roulette_00170000(int *o) { int r; if (o[17]-- <= 0) { o[17] = 0; o[15] = o[15] - o[16]; } if (o[15] < 2184) o[15] = 2184; r = func_00170940_00170000(o); if (o[15] == 2184) { if (r != 0) { o[16] = 0; func_00170AE0_00170000(o); *(V8_00170000 *)(o + 34) = *(V8_00170000 *)(o + 36); } } return 0; }

typedef struct { char c[8]; } V8_00172288;
extern V8_00172288 D_004A3120[3]; extern char D_00343028_00172288[] __asm__("D_00343028"); extern int D_00335640[1];
typedef struct { char p[48]; short adj48; short pad48; int (*fn52)(void *); } VT_172288_00172288;
typedef struct { int w0; int w4; char p[36]; V8_00172288 v44; int pad52[2]; VT_172288_00172288 *vt; char p2[4]; int a68[1]; } O_172288_00172288;
void func_00171AB8(void *); int func_00171AD0(void *); void func_0010C2B0_00172288(char *, int, int, int, int, int, int) __asm__("func_0010C2B0");
// MATCH func_00172288
int roulette_00172288(O_172288_00172288 *o) { int r; int k; o->w0 = o->w0 - o->w4; if (o->w0 < 2184) o->w0 = 2184; r = o->vt->fn52((char *)o + o->vt->adj48); if (o->w0 == 2184 && r != 0) { o->w4 = 0; func_00171AB8(o); o->v44 = D_004A3120[0]; k = func_00171AD0(o); if (o->a68[k] == 23) func_0010C2B0_00172288(D_00343028_00172288, 161, 12, 0, 2, 0, 0); else func_0010C2B0_00172288(D_00343028_00172288, 161, 12, 0, 3, 1, 0); } return 0; }

typedef struct { char c[8]; } V8_00171820;
extern V8_00171820 D_004A3120_00171820[3] __asm__("D_004A3120"); extern char D_00343028_00171820[] __asm__("D_00343028"); extern int D_00335640_00171820[3] __asm__("D_00335640");
typedef struct { char p[48]; short adj48; short pad48; int (*fn52)(void *); } VT_171820_00171820;
typedef struct { int w0; int w4; char p[36]; V8_00171820 v44; int pad52[2]; VT_171820_00171820 *vt; char p2[4]; int a68[1]; } O_171820_00171820;
void func_00171AB8(void *); int func_00171AD0(void *); void func_0010C2B0(char *, int, int, int, int, int, int);
// MATCH func_00171820
int roulette_00171820(O_171820_00171820 *o) { int r; int k; o->w0 = o->w0 - o->w4; if (o->w0 < 2184) o->w0 = 2184; r = o->vt->fn52((char *)o + o->vt->adj48); if (o->w0 == 2184 && r != 0) { o->w4 = 0; func_00171AB8(o); o->v44 = D_004A3120_00171820[0]; k = func_00171AD0(o); switch (D_00335640_00171820[k]) { default: func_0010C2B0(D_00343028_00171820, 140, 6, 0, 2, 0, 0); break; case 11: func_0010C2B0(D_00343028_00171820, 140, 6, 0, 3, 0, 0); break; case 12: func_0010C2B0(D_00343028_00171820, 140, 6, 0, 4, 0, 0); break; } } return 0; }

typedef struct { char c[8]; } V8_001721C8;
extern V8_001721C8 D_004A3118[3]; extern char D_00343028_001721C8[] __asm__("D_00343028"); extern long D_004A12D8_001721C8 __asm__("D_004A12D8");
typedef struct { char p[48]; short adj48; short pad48; int (*fn52)(void *); } VT_1721c8_001721C8;
typedef struct { int w0; int w4; char p[36]; V8_001721C8 v44; int pad52[2]; VT_1721c8_001721C8 *vt; int w64; char p2[48]; int w116; } O_1721c8_001721C8;
int func_0010C2B0_001721C8(void *, int, int, int, int, int, int) __asm__("func_0010C2B0");
// MATCH func_001721C8
int roulette_001721c8(O_1721c8_001721C8 *o) { o->w0 = 16384; o->vt->fn52((char *)o + o->vt->adj48); o->w64 = o->w64 - 1; o->w116 = 1; if (D_004A12D8_001721C8 & 0x200040) o->w64 = -1; if (o->w64 <= 0) { func_0010C2B0_001721C8(D_00343028_001721C8, 161, 12, 0, 1, 0, 0); o->w4 = 64; o->v44 = D_004A3118[0]; } return 0; }

typedef struct { char p[136]; short adj; short pad; int (*fn)(void *); } O_00170B98;
int func_00196FF8_00170B98(void) __asm__("func_00196FF8");
void func_00164608_00170B98(void *) __asm__("func_00164608");
void func_001710D0(void *);
// MATCH func_00170B98
int roulette_00170b98(char *o) {
    int r;
    if (*(int *)(o + 132) == 0) {
        if (func_00196FF8_00170B98() != 0) return 0;
        *(int *)(o + 132) = 1;
    }
    *(int *)(o + 100) = *(int *)(o + 100) + 1;
    if (*(int *)(o + 116) != 0) {
        if (*(int *)(o + 112) > 0) *(int *)(o + 112) = *(int *)(o + 112) - 1;
    } else {
        if (*(int *)(o + 112) < 24) *(int *)(o + 112) = *(int *)(o + 112) + 1;
    }
    if (*(int *)(o + 124) != 0) {
        if (*(int *)(o + 120) > 0) *(int *)(o + 120) = *(int *)(o + 120) - 4;
    } else {
        if (*(int *)(o + 120) < 116) *(int *)(o + 120) = *(int *)(o + 120) + 4;
    }
    r = ((O_00170B98 *)o)->fn((char *)o + ((O_00170B98 *)o)->adj);
    func_00164608_00170B98(o + 104);
    func_001710D0(o);
    return r;
}

int func_00196FF8_00171AE8(void) __asm__("func_00196FF8");
void func_00164608_00171AE8(void *) __asm__("func_00164608");
void func_00171D28(void *);
// MATCH func_00171AE8
int roulette_00171ae8(char *o) {
    int idx, d, dl, r;
    long e;
    int (*fn)(void *);
    if (*(int *)(o + 40) == 0) {
        if (func_00196FF8_00171AE8() == 0) *(int *)(o + 40) = 1;
        return 0;
    }
    *(int *)(o + 24) = *(int *)(o + 24) + 1;
    idx = *(short *)(o + 46);
    if (idx > 0) {
        long *vt = *(long **)(o + *(short *)(o + 48));
        e = vt[idx - 1];
        fn = (int (*)(void *))(e >> 32);
    } else fn = *(int (**)(void *))(o + 48);
    dl = *(short *)(o + 44);
    d = idx > 0 ? (short)e + dl : dl;
    r = fn(o + d);
    func_00164608_00171AE8(o + 28);
    func_00171D28(o);
    return r;
}

extern char D_00343028_001723E8[] __asm__("D_00343028"), D_004A3130[], D_0043D648[];
int func_00196FF8_001723E8(void) __asm__("func_00196FF8");
int func_0010B168(void *, int, void *, int);
void func_00164608_001723E8(void *) __asm__("func_00164608");
void func_00171D28(void *);
int func_001118F8_001723E8(void *, ...) __asm__("func_001118F8");
void func_002708F8(void);
// MATCH func_001723E8
int roulette_001723e8(char *o) {
    int idx, d, dl, r, st;
    long e;
    int (*fn)(void *);
    st = *(int *)(o + 40);
    switch (st) {
    case 0:
        if (func_00196FF8_001723E8() == 0) *(int *)(o + 40) = 1;
        return 0;
    case 1:
        if (func_0010B168(D_00343028_001723E8, 161, D_004A3130, 0x179c00) > 0) *(int *)(o + 40) = 2;
        return 0;
    }
    *(int *)(o + 24) = *(int *)(o + 24) + 1;
    idx = *(short *)(o + 46);
    if (idx > 0) {
        long *vt = *(long **)(o + *(short *)(o + 48));
        e = vt[idx - 1];
        fn = (int (*)(void *))(e >> 32);
    } else fn = *(int (**)(void *))(o + 48);
    dl = *(short *)(o + 44);
    d = idx > 0 ? (short)e + dl : dl;
    r = fn(o + d);
    func_00164608_001723E8(o + 28);
    func_00171D28(o);
    *(int *)(o + 120) = *(int *)(o + 120) + 1;
    if (*(int *)(o + 120) == 121) {
        func_001118F8_001723E8(D_0043D648);
        func_002708F8();
    }
    return r;
}

typedef struct { char c[8]; } V8_001714A0;
typedef struct { int w0, w4, w8, w12, w16, w20, w24; char p[4]; int w32; int w36; int w40; V8_001714A0 v; char p2[8]; int w60; } O5_001714A0;
extern V8_001714A0 D_004A3100[3]; extern char D_0043D6A0_001714A0[] __asm__("D_0043D6A0"), D_0043D580_001714A0[] __asm__("D_0043D580"), D_0043D598_001714A0[] __asm__("D_0043D598");
int func_001644A0(void *); void func_002971C0(int, int); int func_0018B3A8(char *, int); void func_001118F8_001714A0(char *) __asm__("func_001118F8");
// MATCH func_001714A0
O5_001714A0 *roulette_001714a0(O5_001714A0 *o) { o->w0 = 0; o->w4 = 0; o->w8 = 0; o->w12 = 0; o->w20 = 0; o->w24 = 0; o->w60 = (int)D_0043D6A0_001714A0; o->w16 = 640; func_001644A0((char *)o + 28); o->v = D_004A3100[0]; func_002971C0(0, 0); o->w40 = 0; o->w36 = func_0018B3A8(D_0043D580_001714A0, 0); if (o->w36 == 0) func_001118F8_001714A0(D_0043D598_001714A0); return o; }
