/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p[496]; int w; } O_0029F850;
// MATCH func_0029F850
void clas_min_0029f850(int a, O_0029F850 *o) { o->w &= -8193; }

extern int D_00425510_002A1958[] __asm__("D_00425510"); extern char D_00343028_002A1958[] __asm__("D_00343028"); void func_0010E820(void *, int);
// MATCH func_002A1958
void clas_min_002a1958(void) { if ((D_00425510_002A1958[0] & 0x10000000) == 0) func_0010E820(D_00343028_002A1958, 102); }

extern int D_004A69FC_002A2158 __asm__("D_004A69FC"); typedef struct { char p[12]; int w; } O_002A2158;
// MATCH func_002A2158
void clas_min_002a2158(O_002A2158 *o, int v) { D_004A69FC_002A2158 |= 0x40; o->w = v; }

extern int D_004A69FC_002A3148 __asm__("D_004A69FC"); typedef struct { char p[28]; int w; } O_002A3148; void func_00126B20(void);
// MATCH func_002A3148
void clas_min_002a3148(O_002A3148 *o, int v) { o->w = v; if ((D_004A69FC_002A3148 & 0x20) == 0) { D_004A69FC_002A3148 |= 0xa0; func_00126B20(); } }

typedef struct { char p[44]; int w; } O_002A3908;
extern char D_00621320[]; void func_00131160(void *, int);
// MATCH func_002A3908
void clas_min_002a3908(O_002A3908 *o) { if (o->w != 0) func_00131160(D_00621320, o->w); }

extern int D_004A697C;
// MATCH func_0029C3F0
void clas_min_0029c3f0(int *o, int v) { int t = D_004A697C; *o = v; D_004A697C = t + 1; }

extern unsigned D_00425510_002A4518[] __asm__("D_00425510");
// MATCH func_002A4518
void clas_min_002a4518(void) { D_00425510_002A4518[1] &= 0xffffdfff; D_00425510_002A4518[1] &= 0xffffbfff; }

typedef struct { char p[16]; int *q; } O_0029CF98;
// MATCH func_0029CF98
int clas_min_0029cf98(O_0029CF98 *o) { if (o->q == 0) return 0; return o->q[1] != 0; }

typedef struct { char p[16]; int a; char p2[16]; int b; char p3[16]; int c; } O_0029EF38;
// MATCH func_0029EF38
int clas_min_0029ef38(O_0029EF38 *o) { if (o->a != 0) return 1; if (o->b != 0) return 1; return o->c != 0; }

typedef struct { char p[256]; int a, b, c; } O_002A1A70;
void func_002DD4CC(void *, void *);
// MATCH func_002A1A70
O_002A1A70 *clas_min_002a1a70(O_002A1A70 *o, int x, void *y, int z) { o->b = x; o->a = 0; o->c = z; func_002DD4CC(o, y); return o; }

typedef struct { char p[76]; unsigned w; } T_0029EDC0;
typedef struct { char p[476]; T_0029EDC0 *t; } O_0029EDC0;
void func_0029D010(void *, int);
// MATCH func_0029EDC0
void clas_min_0029edc0(char *a, O_0029EDC0 *o) { func_0029D010(a + 0, 0); if (o->t != 0) o->t->w |= 0x2000; }

typedef struct { char p[76]; unsigned w; } T_0029EE00;
typedef struct { char p[476]; T_0029EE00 *t; } O_0029EE00;
void func_0029D010(void *, int);
// MATCH func_0029EE00
void clas_min_0029ee00(char *a, O_0029EE00 *o) { func_0029D010(a + 20, 0); if (o->t != 0) o->t->w |= 0x2000; }

typedef struct { char p[76]; unsigned w; } T_0029EE40;
typedef struct { char p[476]; T_0029EE40 *t; } O_0029EE40;
void func_0029D010(void *, int);
// MATCH func_0029EE40
void clas_min_0029ee40(char *a, O_0029EE40 *o) { func_0029D010(a + 40, 0); if (o->t != 0) o->t->w |= 0x2000; }

typedef struct { int a; char p[16]; int b; char p2[36]; int c, d, e, f; } O_002A0E70;
extern int D_004249E8[], D_004249F8[];
// MATCH func_002A0E70
O_002A0E70 *clas_min_002a0e70(O_002A0E70 *o) { o->a = 0; D_004249E8[0] = 0; D_004249F8[0] = 0; o->b = -1; o->c = -1; o->d = 0; o->e = 0; o->f = 0; return o; }

// MATCH func_002A1AD0
void clas_min_002a1ad0(char *o) { int i; int *p = (int *)(o + 260); for (i = 0; i < 5; i++) { p[-1] = 0; p[1] = 0; p[0] = -1; p += 68; } }

// MATCH func_0029C398
int clas_min_0029c398(int x, unsigned char *p, int i) { int j = (i / 4) * 4; return p[j] == 44; }

extern unsigned D_004A69FC_002A2118 __asm__("D_004A69FC"); extern char D_00424A98[];
void func_002DD4CC_002A2118(void *) __asm__("func_002DD4CC"); void func_002DD718(void *);
// MATCH func_002A2118
void clas_min_002a2118(void) { D_004A69FC_002A2118 |= 0x40; func_002DD4CC_002A2118(D_00424A98); func_002DD718(D_00424A98); }

extern char D_00424D98[]; extern int D_004A14E0;
void func_002A2240(void); void func_0018B668(void *, int);
// MATCH func_002A3928
void clas_min_002a3928(void) { func_002A2240(); func_0018B668(D_00424D98, D_004A14E0); }

typedef struct { int a0; char pad[20]; int a24; } S_2a4800_002A4800;
void func_002BEB90(int, int);
// MATCH func_002A4800
void clas_min_002a4800(S_2a4800_002A4800 *s) { s->a24 = 0; if (s->a0 != 0) func_002BEB90(s->a0, 3); s->a0 = 0; }

typedef struct { int a0, a4, a8, a12, a16, a20; } S_2a4548_002A4548;
extern S_2a4548_002A4548 D_00314CC8;
// MATCH func_002A4548
void clas_min_002a4548(void) { S_2a4548_002A4548 *p = &D_00314CC8; D_00314CC8.a0 = -1;
p->a4 = -1;
p->a8 = -1;
p->a12 = -1;
p->a16 = -1;
p->a20 = -1;
}

typedef struct { int a0, a4, a8, a12; } S_2a45c8_002A45C8;
extern S_2a45c8_002A45C8 D_00314D08;
// MATCH func_002A45C8
void clas_min_002a45c8(void) { S_2a45c8_002A45C8 *p = &D_00314D08; D_00314D08.a0 = 0;
p->a4 = -1;
p->a8 = -1;
p->a12 = -1;
}

typedef struct { char pad[8]; int a8; } S_29c5c8_0029C5C8;
extern char D_0049A700[];
int func_00162130_0029C5C8(int, void *, int) __asm__("func_00162130"); int func_002A0E70(int);
// MATCH func_0029C5C8
void clas_min_0029c5c8(S_29c5c8_0029C5C8 *s) { if (s->a8 == 0) s->a8 = func_002A0E70(func_00162130_0029C5C8(84, D_0049A700, 633)); }

extern int D_004A69FC_002A20C0 __asm__("D_004A69FC"); extern char D_00424A98_002A20C0[] __asm__("D_00424A98"); void func_002DD4CC_002A20C0(void *) __asm__("func_002DD4CC"); void func_0023C728(void *, int); void func_002DD718(void *);
// MATCH func_002A20C0
void clas_min_002a20c0(int a, int b, int c) { D_004A69FC_002A20C0 |= 0x40; func_002DD4CC_002A20C0(D_00424A98_002A20C0); func_0023C728(D_00424A98_002A20C0, c); func_002DD718(D_00424A98_002A20C0); }

extern int D_004A72F4, D_004A72F0; extern char D_00621320_002A2020[] __asm__("D_00621320"), D_0062AB20[], D_0041EF80[]; void func_0015A570(char *, int);
// MATCH func_002A2020
void clas_min_002a2020(void) { unsigned i; D_004A72F4 = 0; D_004A72F0 = 0; for (i = 0; i < 512; i++) D_00621320_002A2020[i] = 0; for (i = 0; i < 16; i++) D_0062AB20[i] = 0; func_0015A570(D_0041EF80, 0); }

// MATCH func_002A1B08
void clas_min_002a1b08(char *b, int x) { int i; int *p = (int *)(b + 264); for (i = 0; i < 5; i++) { if (*p == x) { p[-2] = 0; *p = 0; p[-1] = -1; } p += 68; } }

typedef struct { char p[104]; float a104, a108, a112, a116; } O_0029F9B8;
extern float D_004A0D7C, D_004A0D80, D_004A0D84;
// MATCH func_0029F9B8
void clas_min_0029f9b8(O_0029F9B8 *o, float s) { o->a108 = s * D_004A0D7C; o->a104 = s * D_004A0D80; o->a116 = s * D_004A0D84; o->a112 = s * 0.0f; }

typedef struct { char p[76]; int w76; char q[56]; int w136; } O_0029FCC0;
extern float D_004A0D88; void func_0029F948(O_0029FCC0 *); void func_0029F9B8(O_0029FCC0 *, float);
// MATCH func_0029FCC0
void clas_min_0029fcc0(O_0029FCC0 *o) { func_0029F948(o); o->w136 = 12000; func_0029F9B8(o, D_004A0D88); o->w76 = (o->w76 & ~4) | 0x800; }

typedef struct { char p[76]; int w76; char q[56]; int w136; } O_0029FD10;
void func_0029F9B8_0029FD10(O_0029FD10 *, float) __asm__("func_0029F9B8");
// MATCH func_0029FD10
void clas_min_0029fd10(O_0029FD10 *o) { if (o->w76 & 0x800) { o->w136 = 0; func_0029F9B8_0029FD10(o, 1.0f); o->w76 &= ~0x800; o->w76 &= ~0x80; o->w76 |= 4; } }

extern char D_0049A700_002A3950[] __asm__("D_0049A700"); void *func_00162130_002A3950(int, char *, int) __asm__("func_00162130");
// MATCH func_002A3950
void *PacChunkCopy(int *src, unsigned n) { int *dst = func_00162130_002A3950(n, D_0049A700_002A3950, 3668); unsigned i; unsigned cnt = n >> 2; for (i = 0; i < cnt; i++) dst[i] = src[i]; return dst; }

typedef struct { char p[144]; char *t; } Q29_0029EDA0;
typedef struct { char p[60]; int i; } P29_0029EDA0;
void func_002BD8F8(void);
// 6 words differ
// WIP func_0029EDA0
// MATCH func_0029EDA0
void clas_min_0029eda0(P29_0029EDA0 *p, Q29_0029EDA0 *q, int i)
{
  char *new_var;
  p->i = i;
  new_var = q->t + (i * 4);
  *((void **) (new_var + 1024)) = (void *) func_002BD8F8;
}

extern char D_0049B368[], D_005F9610[], D_004A6A10[]; int func_002DCE40_002A43E8(char *, char *, ...) __asm__("func_002DCE40"); void func_002A2118(char *, char *); void func_002BEA90(char *, char *); void func_002A2158(char *, int);
// MATCH func_002A43E8
void clas_min_002a43e8(char *name, int a) { char buf[128]; func_002DCE40_002A43E8(buf, D_0049B368, name); func_002A2118(D_005F9610, buf); func_002BEA90(D_005F9610, D_004A6A10); func_002A2158(D_005F9610, a); }

extern int D_004A6A2C; extern char D_0061F870[], D_0049A700_002A4100[] __asm__("D_0049A700"); void func_002A1B08(char *, int); void *func_00162130_002A4100(int, char *, int) __asm__("func_00162130"); void *func_002A2090(void *); void func_002A3928(void *); void func_00108B80_002A4100(void *) __asm__("func_00108B80");
// MATCH func_002A4100
void clas_min_002a4100(void) { func_002A1B08(D_0061F870, 0x69400); D_004A6A2C = (int)func_002A2090(func_00162130_002A4100(48, D_0049A700_002A4100, 3847)); func_002A3928((void *)D_004A6A2C); func_00108B80_002A4100((void *)D_004A6A2C); D_004A6A2C = 0; }

extern char D_0061F640[]; int func_0029C4F8(char *, int); char *func_0029C738(void); char *func_0029C770(void);
// MATCH func_0029C810
int clas_min_0029c810(int a) { int i; char *p; char *q; i = func_0029C4F8(D_0061F640, a); if (i == -1) return 0; p = func_0029C738(); q = func_0029C770(); { int *w = (int *)(q + 24); int v = w[i]; *(short *)(p + 188) = v; } return 1; }

extern int *D_004A6A04; extern int D_004A69F4; extern char D_0049A700_002A2C30[] __asm__("D_0049A700");
void *func_00162130_002A2C30(int, char *, int) __asm__("func_00162130"); int func_00190640(void *, int, int *, int); void func_00190740(int, int); void func_001621F8_002A2C30(int *, char *, int) __asm__("func_001621F8"); void func_00190710(int, int); int func_00196FF8_002A2C30(void) __asm__("func_00196FF8");
// MATCH func_002A2C30
void clas_min_002a2c30(int *o) { while (func_00196FF8_002A2C30() != 0); D_004A69F4 = func_00190640(func_00162130_002A2C30(32, D_0049A700_002A2C30, 3305), o[4], D_004A6A04, *D_004A6A04); func_00190740(D_004A69F4, -1); func_001621F8_002A2C30(D_004A6A04, D_0049A700_002A2C30, 3307); D_004A6A04 = 0; if (D_004A69F4 != 0) func_00190710(D_004A69F4, 3); D_004A69F4 = 0; }

extern char D_0049D320[], D_00342CD0_002A4F30[] __asm__("D_00342CD0");
// MATCH func_002A4F30
int *clas_min_002a4f30(int *o) { o[6] = (int)D_0049D320; o[9] = 0; o[10] = 27648; o[11] = 30976; o[12] = 10240; o[13] = 3584; o[14] = 0; o[15] = 0; o[16] = 0; o[17] = 10240; o[18] = 3584; o[19] = -8; o[20] = 9; o[21] = 12608; o[22] = 0; o[23] = 0; o[24] = 0; o[25] = 128; o[26] = 0; o[27] = 2; o[28] = 1; o[30] = (int)D_00342CD0_002A4F30; return o; }

extern int D_004A69A8; extern char D_005F9640[]; int func_002A0020(void);
// MATCH func_002A0098
char *clas_min_002a0098(void) { int x; x = func_002A0020(); if (x < D_004A69A8) return D_005F9640 + x * 608; return 0; }

extern int D_004A69A8_002A00E0 __asm__("D_004A69A8"); extern char D_005F9640_002A00E0[] __asm__("D_005F9640"); int func_002A0020(void); int func_0029C878(int, int);
// MATCH func_002A00E0
char *clas_min_002a00e0(void) { int x; x = func_0029C878(func_002A0020(), 0); if (x < D_004A69A8_002A00E0) return D_005F9640_002A00E0 + x * 608; return 0; }

void func_0029D010_0029FEC0(void *, float, int, int) __asm__("func_0029D010");
// MATCH func_0029FEC0
void clas_min_0029fec0(char *o, int b, float x, float y, float z) { func_0029D010_0029FEC0(o + 516, x, 0, b); func_0029D010_0029FEC0(o + 536, y, 0, b); func_0029D010_0029FEC0(o + 556, z, 0, b); }

void func_0029D010_0029FF50(void *, float, int, int) __asm__("func_0029D010");
// MATCH func_0029FF50
void clas_min_0029ff50(char *o, int i, int c, int d, float f) { func_0029D010_0029FF50(o + (i * 20 + 304), f, c, d); }

int func_0015AD98(char *); int func_0015ADC0(char *); char *func_0015ADE8(char *, int); char *func_0015AE08(char *, int);
void func_001563A0(char *, int, int, int, int, int, int); void func_00156B20(char *, int, int, int);
void func_0029D010_002A0D88(void *, float, int, int) __asm__("func_0029D010");
// MATCH func_002A0D88
void clas_min_002a0d88(int *o, int x, int y, int z, int e, char *h) { if (func_0015AD98(h) > 0) func_001563A0(func_0015ADE8(h, 0), o[6], o[7], o[8], o[6], o[7], o[8]); if (func_0015ADC0(h) > 0) func_00156B20(func_0015AE08(h, 0), o[6], o[7], o[8]); o[6] = x; o[7] = y; o[8] = z; o[0] = 0; func_0029D010_002A0D88((char *)o, 1.0f, 0, e); }

extern int D_004A69FC_2A3068 __asm__("D_004A69FC"), D_004A14E0_2A3068 __asm__("D_004A14E0"); extern char D_0049ACD0_2A3068[] __asm__("D_0049ACD0"), D_0049AFC0_2A3068[] __asm__("D_0049AFC0"), D_0049AFD0_2A3068[] __asm__("D_0049AFD0"), D_00424B18_2A3068[] __asm__("D_00424B18"), D_005F9610_2A3068[] __asm__("D_005F9610");
int func_002DD36C_2A3068(char *, char *) __asm__("func_002DD36C"); void func_002A2118_2A3068(char *, char *) __asm__("func_002A2118"); void func_002A2240_2A3068(char *) __asm__("func_002A2240"); int func_0018B2A8_2A3068(char *) __asm__("func_0018B2A8"); void func_0018B668_2A3068(char *, int) __asm__("func_0018B668"); void func_001118F8_2A3068(char *, ...) __asm__("func_001118F8");
// MATCH func_002A3068
int clas_min_002a3068(char *o, int b, char *name) { int sz; if ((D_004A69FC_2A3068 & 0x20) != 0) return 0; if (func_002DD36C_2A3068(name, D_0049ACD0_2A3068) == 0) return 0; if (func_002DD36C_2A3068(name, D_0049AFC0_2A3068) == 0) return 0; D_004A69FC_2A3068 = D_004A69FC_2A3068 | 0x20; *(int *)(o + 28) = b; func_002A2118_2A3068(o, name); func_002A2240_2A3068(o); sz = func_0018B2A8_2A3068(D_00424B18_2A3068); if (sz > 0x3fffff) { func_001118F8_2A3068(D_0049AFD0_2A3068); return 0; } D_004A69FC_2A3068 = D_004A69FC_2A3068 | 0x400; func_0018B668_2A3068(D_00424B18_2A3068, D_004A14E0_2A3068); return 1; }

void func_00249108_29FA18(void) __asm__("func_00249108"); void func_0029FB60_29FA18(int) __asm__("func_0029FB60"); void func_00249100_29FA18(float, float, float) __asm__("func_00249100"); void func_00248CF8_29FA18(int, float) __asm__("func_00248CF8"); void func_002489F0_29FA18(void) __asm__("func_002489F0");
void func_0021B600_29FA18(char *) __asm__("func_0021B600"); void func_002464A8_29FA18(char *) __asm__("func_002464A8"); void func_0018F3D8_29FA18(char *, unsigned, unsigned) __asm__("func_0018F3D8"); void func_0022D470_29FA18(char *, char *, unsigned) __asm__("func_0022D470"); void func_002491D8_29FA18(void) __asm__("func_002491D8");
// MATCH func_0029FA18
void clas_min_0029fa18(int a, int *o) { char *e = (char *)o[0]; char buf[64]; func_00249108_29FA18(); if (o[119] != 0) { if ((*(unsigned *)(o[119] + 76) & 0x20) != 0) func_0029FB60_29FA18(o[119]); } func_00249100_29FA18(*(float *)(e + 32), *(float *)(e + 36), *(float *)(e + 40)); func_00248CF8_29FA18(2, *(float *)(e + 72)); func_00248CF8_29FA18(1, *(float *)(e + 68)); func_00248CF8_29FA18(0, *(float *)(e + 64)); func_002489F0_29FA18(); func_0021B600_29FA18(e); func_002464A8_29FA18(e); func_0018F3D8_29FA18(buf, 0x70003c00, 0x70003f80); func_0022D470_29FA18(e + 80, buf, 0x70003e00); func_002491D8_29FA18(); }

extern int D_004A14E0_2A1D28 __asm__("D_004A14E0"); extern char D_00343028_2A1D28[] __asm__("D_00343028"), D_0049ACE0_2A1D28[] __asm__("D_0049ACE0");
int func_0010B1A8_2A1D28(char *, int, char *, int, int, int) __asm__("func_0010B1A8"); volatile short func_001118F8_2A1D28(char *, ...) __asm__("func_001118F8"); volatile int func_002BEB38_2A1D28(char *, int) __asm__("func_002BEB38");
// MATCH func_002A1D28
void clas_min_002a1d28(char *o) { char *p = *(char **)(o + 1616); int r; if (p != 0) { if ((*(unsigned *)(o + 1632) & 2) != 0) r = func_0010B1A8_2A1D28(D_00343028_2A1D28, *(int *)(p + 260), p, *(int *)(p + 264), D_004A14E0_2A1D28, 1); else r = func_0010B1A8_2A1D28(D_00343028_2A1D28, *(int *)(p + 260), p, *(int *)(p + 264), 0, 1); if (r > 0) { func_001118F8_2A1D28(D_0049ACE0_2A1D28, *(int *)(p + 260), p, *(int *)(p + 264), r); *(int *)(o + 1616) = *(int *)(p + 256); *(int *)(p + 256) = 0; if (p != 0) func_002BEB38_2A1D28(p, 3); } } }

extern char D_0049A700_2A1BE0[] __asm__("D_0049A700"), D_0049AD08_2A1BE0[] __asm__("D_0049AD08"), D_0049AD30_2A1BE0[] __asm__("D_0049AD30");
int func_002A1E88_2A1BE0(char *, int, int, int) __asm__("func_002A1E88"); char *func_00162130_2A1BE0(int, char *, int) __asm__("func_00162130"); int func_002A1A70_2A1BE0(char *, int, int, int) __asm__("func_002A1A70");
void func_001118F8_2A1BE0(char *, ...) __asm__("func_001118F8"); void func_002D7228_2A1BE0(int) __asm__("func_002D7228");
// MATCH func_002A1BE0
void clas_min_002a1be0(char *o, int a, int b, int c) { char *t = o + 0x550; int nx; char *n; int r; nx = *(int *)(t + 256); while (nx != 0) { t = *(char * volatile *)(t + 256); nx = *(int *)(t + 256); } if (func_002A1E88_2A1BE0(o, a, b, c) != 0) { n = func_00162130_2A1BE0(0x110, D_0049A700_2A1BE0, 2895); r = func_002A1A70_2A1BE0(n, a, b, c); *(int *)(t + 256) = r; if (r == 0) { func_001118F8_2A1BE0(D_0049AD08_2A1BE0); func_001118F8_2A1BE0(D_0049AD30_2A1BE0); func_002D7228_2A1BE0(0); return; } } }

typedef struct { float f0; int w4; int w8; int w12; int w16; } S_29d378_0029D378;
void func_002BF2C0_29D378(void *, int) __asm__("func_002BF2C0");
// MATCH func_0029D378
void clas_min_0029d378(char *a, float *b) { S_29d378_0029D378 *c = *(S_29d378_0029D378 **)(a + 16); int n; *b = *(float *)a; n = c->w4 + 1; c->w4 = n; if (c->w8 < n) { *b = c->f0; *(int *)(a + 16) = c->w16; *(float *)a = c->f0; func_002BF2C0_29D378(c, 3); } }
