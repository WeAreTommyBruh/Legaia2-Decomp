/* Small functions matched by hand. */
#include "common.h"

extern int D_004A11F0;
// MATCH func_00109620
int FUN_00109620(void) { return D_004A11F0 != 0; }

extern int D_004A6B90, D_004A6B94;
// MATCH func_001118A8
int FUN_001118a8(void) { return D_004A6B94 == D_004A6B90 - 1; }

extern volatile int D_004A6BB8;
// MATCH func_001118E8
int FUN_001118e8(void) { return D_004A6BB8; }

extern int D_004A1660;
// MATCH func_00127EE8
void battle_00127ee8(int a) { if (a != 0) D_004A1660 = 0; else D_004A1660 = 1; }

extern int D_004A1320;
// MATCH func_00110080
void FUN_00110080(int a) { if (a < 0) D_004A1320 = 6; else D_004A1320 = a; }

// MATCH func_001330C0
float rouge_001330c0(float x) { if (x < 0.0f) return -x; return x; }

typedef struct { char pad[48]; float v; } S_001625C8;
// MATCH func_001625C8
void FUN_001625c8(S_001625C8 *s, float x) { if (x > 0.0f) s->v = x; else s->v = 0.0f; }

typedef struct { char pad[52]; float v; } S_001625E8;
// MATCH func_001625E8
void FUN_001625e8(S_001625E8 *s, float x) { if (x > 0.0f) s->v = x; else s->v = 1.0f; }

// MATCH func_00163068
int FUN_00163068(int *p) { if (p == 0) return 0; return *p; }

typedef struct { char pad[40]; int v; } S_0015ADE8;
// MATCH func_0015ADE8
int FUN_0015ade8(S_0015ADE8 **p) { S_0015ADE8 *q = *p; if (q == 0) return 0; return q->v; }

typedef struct { char pad[44]; int v; } S_0015AE08;
// MATCH func_0015AE08
int FUN_0015ae08(S_0015AE08 **p) { S_0015AE08 *q = *p; if (q == 0) return 0; return q->v; }

typedef struct { char pad[24]; int a; int b; } S_00164A20;
// MATCH func_00164A20
int pachislot_00164a20(S_00164A20 *s) { return !(s->a < s->b); }

typedef struct { char pad[72]; int a; char pad2[8]; int b; } S_001911F0;
// MATCH func_001911F0
int FUN_001911f0(S_001911F0 *s) { return !(s->b < s->a); }

typedef struct { int a, b; } T_00190E88;
// MATCH func_00190E88
int FUN_00190e88(char *s, int x) { T_00190E88 *t = (T_00190E88 *)(s + 0x50000); int n = t->b; int m = (n < x) ? n : x; t->b = n - m; return m; }

extern int D_00343028[];
// MATCH func_0010A250
int FUN_0010a250(void) { int r = D_00343028[0] & 8; return r == 0; }

typedef struct { int a, b, c; } T_00190DA8;
// MATCH func_00190DA8
void FUN_00190da8(char *s) { T_00190DA8 *t = (T_00190DA8 *)(s + 0x50000); t->c = 0x50000; t->a = 0; t->b = 0; }

typedef struct { char pad[8]; int a; char p2[4]; int b; char p3[4]; int c; } S_00164808;
// MATCH func_00164808
void FUN_00164808(S_00164808 *s, int x){ s->b = x; s->c = x; s->a = x << 4; }

typedef struct { char pad[4]; int a; char p2[4]; int b; char p3[4]; int c; } S_00164820;
// MATCH func_00164820
void FUN_00164820(S_00164820 *s, int x){ s->b = x; s->c = x; s->a = x << 4; }

typedef struct { char pad[4]; int a, b, c, d, e, f; } S_001647E0;
// MATCH func_001647E0
void FUN_001647e0(S_001647E0 *s, int x, int y){ s->a = x << 4; s->e = x; s->c = x; s->b = y << 4; s->f = y; s->d = y; }

extern char D_0042E820[];
extern int D_004A1214;
int DbgPrintf(char *, ...);
// MATCH func_0010F1E0
void SetDrawNowLoading(void) { DbgPrintf(D_0042E820); D_004A1214 = 1; }

extern char D_0042E838[];
extern int D_004A1214;
int DbgPrintf(char *, ...);
// MATCH func_0010F208
void ReleaseDrawNowLoading(void) { DbgPrintf(D_0042E838); D_004A1214 = 0; }

typedef struct { char pad[128]; int n; char p[8]; int v; } S_001565E8;
void func_001562F8(void *);
// MATCH func_001565E8
void FUN_001565e8(S_001565E8 *s, int i) { if (i < 0) i = 0; if (i >= s->n) i = s->n - 1; s->v = i; func_001562F8(s); }

typedef struct { char pad[222]; short n; char p[8]; int v; } S_00156D70;
void func_00156A78(void *);
// MATCH func_00156D70
void FUN_00156d70(S_00156D70 *s, int i) { if (i < 0) i = 0; if (i >= s->n) i = s->n - 1; s->v = i; func_00156A78(s); }

int func_00163080(void);
extern int D_004A2C94;
// MATCH func_001630B8
int FUN_001630b8(void) { int r = func_00163080(); if (r == 0) return D_004A2C94; return r + 4; }

typedef struct { float a, b, c, d; } V_00154950;
// MATCH func_00154950
void FUN_00154950(V_00154950 *v, float x, float y, float z){ v->a = x; v->b = y; v->c = z; v->d = 1.0f; }

typedef struct { float a, b, c, d; } V_00154C10;
// MATCH func_00154C10
void FUN_00154c10(V_00154C10 *v, float x, float y, float z){ v->a = x; v->b = y; v->c = z; v->d = 1.0f; }

typedef struct { float a, b, c, d; } V_00154970;
typedef struct { char pad[16]; V_00154970 v; } S_00154970;
inline void Set1(V_00154970 *v, float x, float y, float z) { v->a = x; v->b = y; v->c = z; v->d = 1.0f; }
// MATCH func_00154970
void FUN_00154970(S_00154970 *s, float x, float y, float z) { Set1(&s->v, x, y, z); }

typedef struct { float a, b, c, d; } V_001556C8;
typedef struct { char pad[32]; V_001556C8 v; } S_001556C8;
inline void Set2(V_001556C8 *v, float x, float y, float z) { v->a = x; v->b = y; v->c = z; v->d = 1.0f; }
// MATCH func_001556C8
void FUN_001556c8(S_001556C8 *s, float x, float y, float z) { Set2(&s->v, x, y, z); }

typedef struct { char pad[48]; float v; } S_0012E608;
void *func_0012D9D8(void);
// MATCH func_0012E608
float pchsysw_0012e608(void) { S_0012E608 *s = func_0012D9D8(); if (s == 0) return 0.0f; return s->v; }

typedef struct { char pad[52]; float v; } S_0012E630;
void *func_0012D9D8(void);
// MATCH func_0012E630
float pchsysw_0012e630(void) { S_0012E630 *s = func_0012D9D8(); if (s == 0) return 0.0f; return s->v; }

void func_0012E658(int, void *);
typedef struct { char pad[12]; int a; } S_0012F4D0;
// MATCH func_0012F4D0
float pchsysw_0012f4d0(S_0012F4D0 *s) { float v[4]; func_0012E658(s->a, v); return v[0]; }

extern int D_004A140C, D_004A253C;
// MATCH func_0013D5D8
void FUN_0013d5d8(int a) { if (a != 0 && (D_004A140C & 0x200) != 0) D_004A253C++; }

typedef struct { float a, b, c; } V_0015DF00;
void func_0029C980(void *, float, float, float, int, int);
// MATCH func_0015DF00
void FUN_0015df00(char *s, V_0015DF00 *v) { func_0029C980(s + 176, v->a, v->b, v->c, 0, 0); }

extern int D_004A3660, D_004A3664, D_004A3668;
int func_002DD5E0();
// MATCH func_0018A630
void file_0018a630(int a, int b) { D_004A3664 = b; D_004A3660 = a; D_004A3668 = func_002DD5E0(a); }

void func_0015D788(int, int, int, int, int);
// MATCH func_0015A8E8
void FUN_0015a8e8(int *p, int a, int b, int c) { int v[2]; func_0015D788(*p, a, b, c, (int)v); }

void func_0015D8B0(int, int, int, int, int, int);
// MATCH func_0015A948
void FUN_0015a948(int *p, int a, int b, int c, int d) { int v[4]; func_0015D8B0(*p, a, b, c, d, (int)v); }

// MATCH func_0010A268
int FUN_0010a268(int *p, int v) { int o = *p; if (o & 8) return o; *p = v; return v; }

extern int D_00343028[];
void func_002D4058(int);
// MATCH func_0010A288
void FUN_0010a288(int a, int b) { if ((D_00343028[0] & 8) == 0) func_002D4058(b); }

extern int D_004A1610;
extern char D_00321640[];
int func_001911F0(void *);
// MATCH func_00114360
int FUN_00114360(void) { if (D_004A1610 != 0) return func_001911F0(D_00321640); return 1; }

extern float D_0049FCE8;
// MATCH func_0011BC60
int battle_0011bc60(float a, float b) { if (__builtin_fabsf(a - b) > D_0049FCE8) return 1; return 0; }

extern char D_004308F8[];
int DbgPrintf(char *, ...);
void func_0011D588(int, int);
// MATCH func_001230E0
void SetCard(int a) { DbgPrintf(D_004308F8); func_0011D588(a, -1); }

typedef struct { int pad; int a; char pad2[1180]; int b; } P_00127450;
extern P_00127450 *D_004A1A3C;
// MATCH func_00127450
int battle_00127450(void) { P_00127450 *p = D_004A1A3C; if (p == 0) return 0; if (p->b != 0) return 0; return !(p->a < 100); }

extern int D_0034366C[];
void func_001297A0(int, int, int, int, int, int);
// MATCH func_0012D038
void FUN_0012d038(void) { if (D_0034366C[0] != 0) func_001297A0(0, 2, 0, 1, 0, 0); else func_001297A0(0, 2, 0, 0, 0, 0); }

typedef struct { char pad[16]; float f; } S_00153CB0;
void func_0018ED30(void *);
void func_001544F0(void *);
// MATCH func_00153CB0
void FUN_00153cb0(S_00153CB0 *s, float x) { s->f = x; func_0018ED30(&s->f); func_001544F0(s); }

extern char D_0053F980[], D_0053FD30[];
void func_00181128(void *, int);
void func_002A39F8(void *, int);
// MATCH func_0012D2E0
void FUN_0012d2e0(void) { func_00181128(D_0053F980, 2); func_002A39F8(D_0053FD30, 2); }

typedef struct { char pad[16]; float f; float g; } S_00153CE0;
void func_0018ED30(void *);
void func_001544F0(void *);
// MATCH func_00153CE0
void FUN_00153ce0(S_00153CE0 *s, float x) { s->g = x; func_0018ED30(&s->f); func_001544F0(s); }

typedef struct { char pad[16]; float f; float g; float h; } S_00153D10;
void func_0018ED30(void *);
void func_001544F0(void *);
// MATCH func_00153D10
void FUN_00153d10(S_00153D10 *s, float x) { s->h = x; func_0018ED30(&s->f); func_001544F0(s); }

typedef struct { char pad[16]; int p; char p2[36]; int v; char p3[4]; } It_00130150;
typedef struct { int n; It_00130150 *a; } S_00130150;
// MATCH func_00130150
int FUN_00130150(S_00130150 *s, int i) { if (i >= s->n) return 0; if (s->a[i].p == 0) return 0; return s->a[i].v; }

typedef struct { float x, y, z; char pad[4]; int p; char p2[44]; } It_0012F708;
typedef struct { int n; It_0012F708 *a; } S_0012F708;
// MATCH func_0012F708
void pchsysw_0012f708(S_0012F708 *s, int i, float x, float y, float z) { if (i >= s->n) return; if (s->a[i].p == 0) return; s->a[i].x = x; s->a[i].y = y; s->a[i].z = z; }

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

extern int D_004A12B0; extern int D_004A13E0[2]; extern int D_00314C28[];
// MATCH func_001113D8
int FUN_001113d8(void) { return D_00314C28[0] - D_004A13E0[D_004A12B0 & 1]; }

extern int D_004A6E38; extern int *D_003279A0[]; extern float D_0055B3A0[3];
typedef struct { char pad[112]; float x, y, z; } O_0012D078;
// MATCH func_0012D078
void FUN_0012d078(void) { if (D_004A6E38 >= 0) { O_0012D078 *o = ((O_0012D078 **)D_003279A0)[D_004A6E38]; o->x = D_0055B3A0[0]; o->y = D_0055B3A0[1]; o->z = D_0055B3A0[2]; } }

extern int D_004A1214; extern char D_00315E00[], D_00342CD0[];
void func_00100420(void *,void *,int,int,int,int);
// MATCH func_0010F230
void FUN_0010f230(void) { if (D_004A1214 != 0) func_00100420(D_00315E00, D_00342CD0, 0, 0, 0, 128); }

typedef struct { char pad[4816]; unsigned f; char p2[652]; } P_001296B0; extern P_001296B0 *D_004A1A20;
// MATCH func_001296B0
void battle_001296b0(void) { P_001296B0 *p = D_004A1A20; int i; for (i = 0; i < 20; i++) { p->f &= 0xfeffffff; p++; } }

// MATCH func_001296E8
void battle_001296e8(void) { char *p = (char *)D_004A1A20; int i; for (i = 0; i < 20; i++) { *(int *)(p+4816) &= -33; *(int*)(p+4984)=0; *(int*)(p+5408)=0; *(int*)(p+5396)=0; *(int*)(p+5392)=0; *(int*)(p+5388)=0; p += 5472; } }

typedef struct { char pad[208]; float x; } O_001541C8;
void func_00154170(float);
// MATCH func_001541C8
void FUN_001541c8(O_001541C8 *o, float a) { func_00154170(a - o->x); o->x = a; }

void func_0018D048(void *);
void func_0018CDE0(void *);
// MATCH func_00154890
void FUN_00154890(char *a) { func_0018D048(a); func_0018D048(a + 16); func_0018D048(a + 32); func_0018CDE0(a + 64); }

typedef struct { void *p; } O_0015AE28;
int func_0015D430(void *, int, int);
// MATCH func_0015AE28
int FUN_0015ae28(O_0015AE28 *o, int b) { void *p = o->p; int r = 0; if (p) r = func_0015D430(p, b, 0); return r; }

typedef struct { void *p; } O_0015AE50;
int func_0015D430(void *, int, int);
// MATCH func_0015AE50
int FUN_0015ae50(O_0015AE50 *o, int b) { void *p = o->p; int r = 0; if (p) r = func_0015D430(p, b, 1); return r; }

typedef struct { void *p; } O_0015AE78;
int func_0015D530(void *);
// MATCH func_0015AE78
int FUN_0015ae78(O_0015AE78 *o) { void *p = o->p; int r = 0; if (p) r = func_0015D530(p); return r; }

void func_0029C980_b(void *, int, int, float, float, float) __asm__("func_0029C980");
// MATCH func_0015DF20
void FUN_0015df20(char *a, float *v) { func_0029C980_b(a + 128, 0, 0, v[0], v[1], v[2]); }

typedef struct { char pad[32]; unsigned char lo, hi; } O_001630E0;
void *func_00163080_p(void) __asm__("func_00163080");
// MATCH func_001630E0
int FUN_001630e0(void) { O_001630E0 *o = func_00163080_p(); if (o == 0) return 0; return o->lo | (o->hi << 8); }

typedef struct { char pad[34]; unsigned char lo, hi; } O_00163118;
void *func_00163080_p(void) __asm__("func_00163080");
// MATCH func_00163118
int FUN_00163118(void) { O_00163118 *o = func_00163080_p(); if (o == 0) return 0; return o->lo | (o->hi << 8); }

typedef struct { char pad[192]; float v[4]; } O_00154248;
void func_00154550(void *);
// MATCH func_00154248
void FUN_00154248(O_00154248 *o) { float *p = o->v; o->v[0] = 0; p[1] = 0; p[2] = 0; p[3] = 1.0f; func_00154550(o); }

// MATCH func_00161200
int FUN_00161200(void *a, unsigned char *p) { int r = p[0]; r += p[1] << 8; r += p[2] << 16; r += p[3] << 24; return r; }

typedef struct { char p0[4]; int a4, a8, a12, a16; char p1[8]; float f28, f32, f36, f40; char p2[8]; int a52, a56; } O_00163F70;
// MATCH func_00163F70
int FUN_00163f70(O_00163F70 *o) { o->a12 = o->a4 >> 4; o->a16 = o->a8 >> 4; o->f36 = o->f28; o->f40 = o->f32; o->a56 = o->a52; return 0; }

typedef struct { char pad[36]; float a, b; } O_00164058;
// MATCH func_00164058
int FUN_00164058(O_00164058 *o, int **pp) { int *q = *pp; float x, y; x = (float)q[0]; q++; y = (float)q[0]; q++; *pp = q; o->a = x * 0.000244140625f; o->b = y * 0.000244140625f; return 0; }

typedef struct { char pad[44]; float a, b; } O_00164098;
// MATCH func_00164098
int FUN_00164098(O_00164098 *o, int **pp) { int *q = *pp; float x, y; x = (float)q[0]; q++; y = (float)q[0]; q++; *pp = q; o->a = x * 0.000244140625f; o->b = y * 0.000244140625f; return 0; }

extern long long D_004A12D8; extern int D_004A3070;
// MATCH func_0016F7F0
int FUN_0016f7f0(void) { if (D_004A12D8 & 0x8000) { D_004A3070 = 0; return 1; } if (D_004A12D8 & 0x2000) { D_004A3070 = 1; return 1; } return 0; }

extern long long D_004A12D8; void func_002DC804(void *, int, int);
// MATCH func_0016ADC8
int pachislot_0016adc8(char *s) { if (D_004A12D8 & 0x200040) func_002DC804(s + 560, 0, 8); return 0; }

typedef struct { char p[44]; int a; char p2[40]; int b, c; } O_0016E1D0;
void func_0016E510(void *);
// MATCH func_0016E1D0
int darts_0016e1d0(O_0016E1D0 *o) { func_0016E510(o); o->b = 0; o->c = 0; o->a = 0; return 1; }

typedef struct { char pad[20]; int a, b; char p2[16]; int c, d; } O_0016F898;
extern long long D_004A12D8;
// MATCH func_0016F898
int FUN_0016f898(O_0016F898 *o) { if (D_004A12D8 & 0x8000) { o->a = 213; o->b = 112; return 1; } if (D_004A12D8 & 0x2000) { o->c = 0; o->d = 0; return 1; } return 0; }

typedef struct { char pad[20]; int a, b; char p2[16]; int c, d; } O_0016F8E0;
extern long long D_004A12D8;
// MATCH func_0016F8E0
int FUN_0016f8e0(O_0016F8E0 *o) { if (D_004A12D8 & 0x8000) { o->c = 0; o->d = 0; return 1; } if (D_004A12D8 & 0x2000) { o->a = 213; o->b = 112; return 1; } return 0; }
