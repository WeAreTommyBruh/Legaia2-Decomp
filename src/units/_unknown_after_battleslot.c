/* Functions of this report unit, matched by hand. */
#include "../common.h"
#include "../ghidra.h"

typedef struct { char p[200]; int w; } G_0029B720;
extern G_0029B720 D_00425710_0029B720 __asm__("D_00425710");
// MATCH func_0029B720
void FUN_0029b720(int a, int b) { D_00425710_0029B720.w += b; if (D_00425710_0029B720.w < 0) D_00425710_0029B720.w = 0; if (D_00425710_0029B720.w > 100) D_00425710_0029B720.w = 100; }

typedef struct { char p[128]; int w; } G_0029B850;
extern G_0029B850 D_00425710_0029B850 __asm__("D_00425710");
// MATCH func_0029B850
void FUN_0029b850(int a, int b) { D_00425710_0029B850.w += b; if (D_00425710_0029B850.w < 0) D_00425710_0029B850.w = 0; if (D_00425710_0029B850.w > 99999) D_00425710_0029B850.w = 99999; }

typedef struct { char p[468]; int w; } O_002978C8;
// MATCH func_002978C8
int FUN_002978c8(O_002978C8 *o) { if (o == 0) return 0; return o->w != 0; }

typedef struct { char p[124]; int a, b, c, d; } G_0029B6C8;
extern G_0029B6C8 D_00620070;
// MATCH func_0029B6C8
void FUN_0029b6c8(void) { if (D_00620070.a == 28) { D_00620070.c = 1; D_00620070.d = 0; D_00620070.b = 0; D_00620070.a = 11; } }

typedef struct { char pad[22]; short h; int a24[3]; int a36[3]; } S_29b978_0029B978;
// MATCH func_0029B978
void FUN_0029b978(S_29b978_0029B978 *s, int a, int b) { int i = s->h; int n = (unsigned short)s->h + 1; s->a36[i] = a; s->a24[i] = b; s->h = n; if ((short)n >= 3) s->h = 0; }

typedef struct { int a0, a4, a8, a12, a16, a20; } S_29b5c0_0029B5C0;
extern S_29b5c0_0029B5C0 D_00620058; extern int D_00425518[];
// MATCH func_0029B5C0
void FUN_0029b5c0(int x, int b) { S_29b5c0_0029B5C0 *s = &D_00620058; if (s->a4 != 0 || (D_00425518[0] & 0x10)) {
s->a0 = 1;
s->a4 = b;
s->a8 = 0;
s->a20 = 0;
s->a16 = 0;
s->a12 = 0;
} }

extern int D_004257DC[], D_00425510[];
// MATCH func_0029B670
void FUN_0029b670(int a, int b) { D_004257DC[0] = b; D_00425510[2] |= 8; }

typedef struct { int a0, a4, a8, a12, a16, a20; } S_29b598_0029B598;
extern S_29b598_0029B598 D_00620058_0029B598 __asm__("D_00620058");
// MATCH func_0029B598
void FUN_0029b598(int a, int b) { S_29b598_0029B598 *p = &D_00620058_0029B598; D_00620058_0029B598.a0 = 1; p->a4 = b;p->a8 = 0;p->a20 = 0;p->a16 = 0;p->a12 = 0; }

typedef struct { int w0; int w4; } O_0029BB50;
int func_0029B9F0(O_0029BB50 *);
// MATCH func_0029BB50
int FUN_0029bb50(O_0029BB50 *o) { int r = func_0029B9F0(o); int v = o->w4 & 1; if (v != 0) { if (r == 1) return 1; } return 0; }

typedef struct { char p[12]; short h12, h14; } T_002982D8;
extern T_002982D8 D_003D6EE0; extern int D_004A140C_002982D8 __asm__("D_004A140C");
// MATCH func_002982D8
int FUN_002982d8(int a) { if (a == 0) return 0; if (a & 2) return 0; if (D_004A140C_002982D8 & 8) { D_003D6EE0.h12 = 12; D_003D6EE0.h14 = 48; } return 0; }

typedef struct { int w0; int w4; } O_0029BB90;
int func_0029B9F0_0029BB90(O_0029BB90 *) __asm__("func_0029B9F0");
// MATCH func_0029BB90
int FUN_0029bb90(O_0029BB90 *o) { int r = func_0029B9F0_0029BB90(o); int v = o->w4 & 2; if (v != 0) { if (r == 1) return 1; } return 0; }

typedef struct { char p[124]; int a, b, c, d; } G_0029B690;
extern G_0029B690 D_00620070_0029B690 __asm__("D_00620070");
// MATCH func_0029B690
void FUN_0029b690(void) { if (D_00620070_0029B690.a == 11) { int vc = 76; int va = 28; int vb = 1; D_00620070_0029B690.a = va; D_00620070_0029B690.b = vb; D_00620070_0029B690.c = vc; D_00620070_0029B690.d = 0; } }

extern int D_00425510_0029B758[] __asm__("D_00425510"); extern int D_00425710_0029B758[] __asm__("D_00425710");
// MATCH func_0029B758
void FUN_0029b758(int a, int b) { D_00425510_0029B758[2] |= 0x80; D_00425710_0029B758[49] += b; if (D_00425710_0029B758[49] < 0) D_00425710_0029B758[49] = 0; }

extern int D_004A6930;
int func_0015AD98(char *); int func_0015ADE8(char *, int); int func_00156610(int); void func_001565E8(int, int);
extern char D_0041EF80_00298700[] __asm__("D_0041EF80");
// MATCH func_00298700
int FUN_00298700(void) { int r; if (func_0015AD98(D_0041EF80_00298700) > 0) { r = func_0015ADE8(D_0041EF80_00298700, 0); if (D_004A6930 < 0) D_004A6930 = 0; if (func_00156610(r) - 1 < D_004A6930) D_004A6930 = func_00156610(r) - 1; func_001565E8(r, D_004A6930); } else D_004A6930 = -1; return 0; }

extern int D_004A6934;
int func_0015ADC0(char *); int func_0015AE08(char *, int); int func_00156D98(int); void func_00156D70(int, int);
extern char D_0041EF80_00298798[] __asm__("D_0041EF80");
// MATCH func_00298798
int FUN_00298798(void) { int r; if (func_0015ADC0(D_0041EF80_00298798) > 0) { r = func_0015AE08(D_0041EF80_00298798, 0); if (D_004A6934 < -1) D_004A6934 = -1; if (func_00156D98(r) - 1 < D_004A6934) D_004A6934 = func_00156D98(r) - 1; func_00156D70(r, D_004A6934); } else D_004A6934 = -1; return 0; }

extern int D_004A6938; extern int D_004A6934_00298838 __asm__("D_004A6934");
int func_0015ADC0(char *); char *func_0015AE08_00298838(char *, int) __asm__("func_0015AE08");
extern char D_0041EF80_00298838[] __asm__("D_0041EF80");
// MATCH func_00298838
int FUN_00298838(void) { if (D_004A6938 != 0) { if (func_0015ADC0(D_0041EF80_00298838) > 0) { *(float *)(func_0015AE08_00298838(D_0041EF80_00298838, 0) + 144) = 2415919104.0f; D_004A6938 = 0; } } else D_004A6934_00298838 = -1; return 0; }

extern int D_004A68A0;
extern char D_0061FF78[], D_0061FF60[];
void func_0029D010_00298318(float, void *, int, int) __asm__("func_0029D010");
// MATCH func_00298318
int FUN_00298318(void)
{
    float f = (float)D_004A68A0;
    func_0029D010_00298318(f, D_0061FF78, 0, 0);
    func_0029D010_00298318(f, D_0061FF60, 0, 0);
    return 0;
}

extern int D_00425710_0029B1A0[] __asm__("D_00425710");
int func_00250B68(int);
// MATCH func_0029B1A0
void FUN_0029b1a0(int a, int d) { if (func_00250B68(0x3b6) != 0) { D_00425710_0029B1A0[32] = D_00425710_0029B1A0[32] + d / 20; if (D_00425710_0029B1A0[32] < 0) D_00425710_0029B1A0[32] = 0; if (D_00425710_0029B1A0[32] > 99999) D_00425710_0029B1A0[32] = 99999; } }

extern int D_004A1434_002988A0 __asm__("D_004A1434"); extern unsigned D_004A148C_002988A0 __asm__("D_004A148C"); extern int D_004A1430_002988A0 __asm__("D_004A1430"); extern unsigned D_004A5430;
void func_002BEC58(float, float, float, void *);
void func_0023B8A0(unsigned, int, int, int, int, unsigned);
// MATCH func_002988A0
void FUN_002988a0(float *v, int *a, int *b) { float c[10]; int x; int y; int w; unsigned col; unsigned k; int p, q, r; c[0] = 0; c[1] = 0; c[2] = 0; c[3] = 0; c[4] = 0; c[5] = 0; c[6] = 0; c[7] = 0; c[8] = 0; c[9] = 0; func_002BEC58(v[0], 1.0f, 1.0f, c); col = ((int)(c[3] * 15.0f) << 20) | ((int)(c[4] * 15.0f) << 12) | ((int)(c[5] * 15.0f) << 4); a[8] = col; a[7] = col; func_002BEC58(v[0], 1.0f, v[2], c); b[7] = 0xf0f0f0; x = D_004A1430_002988A0 + (118 >> D_004A148C_002988A0); w = 24 >> D_004A148C_002988A0; b[8] = ((int)(c[3] * 15.0f) << 20) | ((int)(c[4] * 15.0f) << 12) | ((int)(c[5] * 15.0f) << 4); y = D_004A1434_002988A0; func_002BEC58(v[0], v[1], v[2], c); q = (int)(c[4] * 255.0f); p = (int)(c[3] * 255.0f); r = (int)(c[5] * 255.0f); k = r | (q << 8) | (p << 16); func_0023B8A0(D_004A5430, x, y, w, w, 0); func_0023B8A0(D_004A5430, x + 4, y + 4, w - 8, w - 8, k); }

void *func_0029C738_297040(void) __asm__("func_0029C738"); void func_002970D8_297040(int) __asm__("func_002970D8");
// MATCH func_00297040
void FUN_00297040(void) { char *p = func_0029C738_297040(); float d[3]; d[0] = *(float *)(p + 32) - *(float *)(p + 48); d[1] = *(float *)(p + 36) - *(float *)(p + 52); d[2] = *(float *)(p + 40) - *(float *)(p + 56); if (1.0f < __builtin_fabsf(d[0]) || 1.0f < __builtin_fabsf(d[1]) || 1.0f < __builtin_fabsf(d[2])) func_002970D8_297040(0); else func_002970D8_297040(1); }

extern float D_004A7324_2990A0 __asm__("D_004A7324"), D_004A7328_2990A0 __asm__("D_004A7328"), D_004A0D10_2990A0 __asm__("D_004A0D10"); extern char D_0062B0A0_2990A0[] __asm__("D_0062B0A0"), D_0062B0E0_2990A0[] __asm__("D_0062B0E0"); void func_00298B10_2990A0(float *, char *, char *) __asm__("func_00298B10");
// MATCH func_002990A0
void FUN_002990a0(void) { float v[3]; v[0] = D_004A7324_2990A0 / 360.0f * 2.0f * D_004A0D10_2990A0; v[1] = D_004A7328_2990A0 / 360.0f * 2.0f * D_004A0D10_2990A0; v[2] = 0; func_00298B10_2990A0(v, D_0062B0A0_2990A0, D_0062B0E0_2990A0); }

extern char D_00499780_295098[] __asm__("D_00499780"), D_0063701C_295098[] __asm__("D_0063701C"), D_00020000_295098[] __asm__("D_00020000");
void func_002DC918_295098(void *, void *, int) __asm__("func_002DC918");
int func_002DBC48_295098(int) __asm__("func_002DBC48");
void func_002DBC70_295098(int) __asm__("func_002DBC70");
// MATCH func_00295098
int FUN_00295098(void) { int n = (int)D_00020000_295098; char *q = D_0063701C_295098; int r; func_002DC918_295098(D_00499780_295098, q, n); r = 0x1ffeff0 - (int)(q + (n + 4096)); func_002DBC70_295098(func_002DBC48_295098(r)); return r; }


extern char D_0049A618[], D_0049A660[], D_0049A6B8[];
int sprintf(char *, const char *, ...);

// MATCH func_0029AE78
int FUN_0029ae78(float *p, int index, char *out)
{
    return sprintf(out, D_0049A618, index, p[482], p[483], p[484],
                   p[480], p[481], p[485], p[486], p[487]);
}

// MATCH func_0029AF70
int FUN_0029af70(float *p, int index, char *out)
{
    return sprintf(out, D_0049A660, index, p[482], p[483], p[484], p[485],
                   p[486], p[487], p[476], p[477], p[478], p[479] * 100.0f);
}

void func_002A8738(void *, int *, float *);
void func_002A87C8(void *, float *, float *);
void func_002A8820(void *, int *);
void func_002A8890(void *, int *, int *);
void func_002A88E8(void *, int *, int *, int *);

// MATCH func_0029B088
int FUN_0029b088(void *p, int index, char *out)
{
    int enabled;
    float scale, x, y;
    int mode, width, height, red, green, blue;

    func_002A8738(p, &enabled, &scale);
    func_002A87C8(p, &x, &y);
    func_002A8820(p, &mode);
    func_002A8890(p, &width, &height);
    func_002A88E8(p, &red, &green, &blue);
    return sprintf(out, D_0049A6B8, index, enabled, scale, x, y, mode,
                   width, height, red, green, blue);
}

void func_002478D0(int);
void func_002478B8(int);
void func_00247970(int);
void func_00247A70(int,int,int);
void func_00247C98(float,float,float);
void func_002479F0(void);

// MATCH func_00298D20
void FUN_00298d20(float *p,float *q,float *c,float *d)
{
    func_002478D0(8);
    func_002478B8(16);
    func_00247970(4);
    func_00247A70((int)(c[0]*255.0f), (int)(c[1]*255.0f), (int)(c[2]*255.0f));
    func_00247C98(p[0]-128.0f, q[1], p[2]-128.0f);
    func_00247C98(p[0]+128.0f, q[1], p[2]-128.0f);
    func_00247A70((int)(d[0]*127.0f), (int)(d[1]*127.0f), (int)(d[2]*127.0f));
    func_00247C98(q[0], p[1], q[2]);
    func_002479F0();

    func_00247970(4);
    func_00247A70((int)(c[0]*255.0f), (int)(c[1]*255.0f), (int)(c[2]*255.0f));
    func_00247C98(p[0]-128.0f, q[1], p[2]+128.0f);
    func_00247C98(p[0]+128.0f, q[1], p[2]+128.0f);
    func_00247A70((int)(d[0]*127.0f), (int)(d[1]*127.0f), (int)(d[2]*127.0f));
    func_00247C98(q[0], p[1], q[2]);
    func_002479F0();

    func_00247970(4);
    func_00247A70((int)(c[0]*255.0f), (int)(c[1]*255.0f), (int)(c[2]*255.0f));
    func_00247C98(p[0]-128.0f, q[1], p[2]-128.0f);
    func_00247C98(p[0]-128.0f, q[1], p[2]+128.0f);
    func_00247A70((int)(d[0]*127.0f), (int)(d[1]*127.0f), (int)(d[2]*127.0f));
    func_00247C98(q[0], p[1], q[2]);
    func_002479F0();

    func_00247970(4);
    func_00247A70((int)(c[0]*255.0f), (int)(c[1]*255.0f), (int)(c[2]*255.0f));
    func_00247C98(p[0]+128.0f, q[1], p[2]-128.0f);
    func_00247C98(p[0]+128.0f, q[1], p[2]+128.0f);
    func_00247A70((int)(d[0]*127.0f), (int)(d[1]*127.0f), (int)(d[2]*127.0f));
    func_00247C98(q[0], p[1], q[2]);
    func_002479F0();
}

typedef struct { int a, b, c, d, e, f; } S_29B450;
typedef struct { char p0[8]; unsigned w8; } F_29B450;
typedef struct { char p0[20]; int w20; } M_29B450;
extern F_29B450 D_00425510_29B450[] __asm__("D_00425510"); extern S_29B450 D_00620058_29B450[] __asm__("D_00620058"); extern float D_00421490[]; extern float D_004A6968, D_004A696C, D_004A6970, D_004A6974; extern int D_004A6978;
extern M_29B450 D_005F9610[]; extern char D_00424968[], D_00424B18[], D_004248E8[];
void func_002A2118(M_29B450 *, char *); void func_002A2240(M_29B450 *); int func_0018B2A8(char *); void func_002A2EF0(M_29B450 *, int, char *);
void func_002A2158(M_29B450 *, int); void func_002A3068(M_29B450 *, int, char *); void func_002A2170(M_29B450 *, char *);
// MATCH func_0029B450
void FUN_0029b450(void) {
  D_00425510_29B450[0].w8 &= ~0x10;
  D_00425510_29B450[0].w8 &= ~0x40;
  D_00421490[1] = D_004A6968;
  D_00421490[2] = D_004A696C;
  D_00421490[3] = D_004A6970;
  D_00421490[4] = D_004A6974;
  D_00620058_29B450[0].a = 3;
  D_00620058_29B450[0].d = 0;
  D_00620058_29B450[0].e = 0;
  D_00620058_29B450[0].f = 0;
  D_00620058_29B450[0].b = 46;
  D_00620058_29B450[0].c = 0;
  func_002A2118(D_005F9610, D_00424968);
  func_002A2240(D_005F9610);
  if (func_0018B2A8(D_00424B18) > 0x3fffff) {
    D_005F9610[0].w20 = 46;
    func_002A2EF0(D_005F9610, 14, D_004248E8);
    func_002A2158(D_005F9610, D_004A6978);
    return;
  }
  D_005F9610[0].w20 = 46;
  func_002A3068(D_005F9610, 28, D_00424968);
  func_002A2170(D_005F9610, D_004248E8);
  func_002A2158(D_005F9610, D_004A6978);
}

typedef struct { char p0[8]; short adj; short pad; void (*fn)(void *, int); } VT_295A30;
typedef struct O_295A30 { char p0[4]; int w4, w8; char p12[12]; VT_295A30 *vt; char p28[8]; struct O_295A30 *w36; int w40, w44, w48, w52; char p56[4]; int w60, w64, w68, w72; char p76[8]; int w84, w88; char p92[8]; int w100; char p104[4]; int w108; char p112[4]; int w116; void *w120; } O_295A30;
extern O_295A30 D_00342CD0[]; extern int D_004A12B0;
void func_002A53B0(O_295A30 *, int, int, int); void func_002A5EC0(O_295A30 *); void func_0018FD98(O_295A30 *, int, int, int, int);
// MATCH func_00295A30
void FUN_00295a30(O_295A30 *o) {
  int v, t; O_295A30 *q;
  if (o->w108 == 2) {
    int u = D_00342CD0[0].w8 + 16;
    o->w4 = u;
    o->w8 = u;
    o->vt->fn((char *)o + o->vt->adj, u);
    o->w36 = D_00342CD0;
    o->w120 = o;
    o->w108 = 0;
  }
  v = 2240;
  if (D_004A12B0 & 1) v = 0;
  o->w116 = 0;
  o->w84 = v;
  o->w88 = 10816;
  o->w100 = 128;
  o->w60 = 0;
  o->w64 = 0;
  o->w68 = 10240;
  o->w40 = 27648;
  o->w44 = 30976;
  o->w48 = 5120;
  o->w72 = 3584;
  o->w52 = 3584;
  func_002A53B0(o, 128, 128, 128);
  func_002A5EC0(o);
  if (o->w108 != 0) return;
  func_0018FD98(o, o->w8, 96, 0, 0);
  t = o->w8 + 16;
  q = o->w36;
  o->w8 = t;
  if (q != 0) {
    func_0018FD98(q, q->w8, 32, t, 0);
    q->w8 = t;
  }
  o->w108 = 1;
  o->w120 = D_00342CD0;
}

typedef struct { char p0[8]; short adj; short pad; void (*fn)(void *, int); } VT_295B88;
typedef struct O_295B88 { char p0[4]; int w4, w8; char p12[12]; VT_295B88 *vt; char p28[8]; struct O_295B88 *w36; int w40, w44, w48, w52; char p56[4]; int w60, w64, w68, w72; char p76[8]; int w84, w88; char p92[8]; int w100; char p104[4]; int w108; char p112[4]; int w116; void *w120; } O_295B88;
extern O_295B88 D_00342CD0_295B88[] __asm__("D_00342CD0"); extern int D_004A12B0;
void func_002A53B0_295B88(O_295B88 *, int, int, int) __asm__("func_002A53B0"); void func_002A5470(O_295B88 *, int, int, int); void func_002A5EC0_295B88(O_295B88 *) __asm__("func_002A5EC0"); void func_0018FD98_295B88(O_295B88 *, int, int, int, int) __asm__("func_0018FD98");
// MATCH func_00295B88
void FUN_00295b88(O_295B88 *o) {
  int v, t; O_295B88 *q;
  if (o->w108 == 2) {
    int u = D_00342CD0_295B88[0].w8 + 16;
    o->w4 = u;
    o->w8 = u;
    o->vt->fn((char *)o + o->vt->adj, u);
    o->w36 = D_00342CD0_295B88;
    o->w120 = o;
    o->w108 = 0;
  }
  v = 2240;
  if (D_004A12B0 & 1) v = 0;
  o->w116 = 0;
  o->w88 = 12608;
  o->w60 = 0;
  o->w64 = 0;
  o->w72 = 3584;
  o->w40 = 27648;
  o->w44 = 30976;
  o->w48 = 5120;
  o->w52 = 3584;
  o->w84 = v;
  o->w100 = 128;
  o->w68 = 10240;
  func_002A53B0_295B88(o, 128, 128, 128);
  o->w72 = 3584;
  o->w84 = 12608;
  o->w116 = 0;
  o->w88 = 12608;
  o->w60 = 0;
  o->w64 = 0;
  o->w68 = 5120;
  o->w44 = 30976;
  o->w48 = 2560;
  o->w52 = 1792;
  o->w40 = 0x8000;
  func_002A53B0_295B88(o, 128, 128, 128);
  o->w84 = 12608;
  o->w60 = 5120;
  o->w68 = 2560;
  o->w72 = 1792;
  o->w40 = 27648;
  o->w44 = 30976;
  o->w116 = 0;
  o->w64 = 0;
  o->w88 = 10816;
  o->w48 = 1280;
  o->w52 = 1024;
  func_002A5470(o, 128, 128, 128);
  func_002A5EC0_295B88(o);
  if (o->w108 != 0) return;
  func_0018FD98_295B88(o, o->w8, 96, 0, 0);
  t = o->w8 + 16;
  q = o->w36;
  o->w8 = t;
  if (q != 0) {
    func_0018FD98_295B88(q, q->w8, 32, t, 0);
    q->w8 = t;
  }
  o->w108 = 1;
  o->w120 = D_00342CD0_295B88;
}

// MATCH func_0029B8B8
int FUN_0029b8b8(int *p, int a, int b, int c, int d, int e) { int r = p[0]; if (r == 0) return 0; if (p[1] != a) return 0; if (p[2] != b) return 0; if (p[3] != c) return 0; if (p[4] != d) return 0; return p[5] == e ? r : 0; }
