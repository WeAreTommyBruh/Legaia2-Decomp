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

typedef struct { char p[68]; int a[1]; } O_00172388; int func_00171AD0(void *);
// MATCH func_00172388
int roulette_00172388(O_00172388 *o) { int i = func_00171AD0(o); return o->a[i]; }

typedef struct { char p[84]; int v; } O_00172C68;
// MATCH func_00172C68
int FUN_00172c68(O_00172C68 *o) { if (o->v == 0 || o->v == 2) return 1; return 0; }

typedef struct { char p[112]; char *q; char p2[216]; void *vt; } O_00173A70; extern char D_0043DFD8[]; void func_00172A60(void *, int);
// MATCH func_00173A70
void FUN_00173a70(O_00173A70 *o, int f) { o->vt = D_0043DFD8; *(float *)(o->q + 200) = 1.0f; func_00172A60(o, f); }

typedef struct { char c[8]; } V8_00174B18; typedef struct { char p[416]; V8_00174B18 v; } O_00174B18; extern V8_00174B18 D_004A31F8[2]; void func_00172B30(void *); void func_00174AB8(void *);
// MATCH func_00174B18
int repetition_00174b18(O_00174B18 *o) { func_00172B30(o); func_00174AB8(o); o->v = D_004A31F8[0]; return 0; }

void func_00172B30(void *); void func_00172C48(void *);
// MATCH func_001769C0
void repetition_001769c0(char *o) { func_00172B30(o); o += 912; func_00172B30(o); func_00172C48(o); }

extern char D_00342CD0[]; extern char D_002F3A00[], D_002F6520[]; void func_00190238(void *, int, void *, int, int);
// MATCH func_0017A388
void FUN_0017a388(void) { func_00190238(D_00342CD0, 0, D_002F3A00, (D_002F6520 - D_002F3A00) >> 4, 0); }

typedef struct { char p[1028]; float f; } O_00188090; extern char D_0033B520[]; void func_00187028(void *); void func_00186F40(void *, void *, int, int);
// MATCH func_00188090
void srivus_00188090(O_00188090 *o) { func_00187028(o); o->f = 384.0f; func_00186F40(o, D_0033B520, 22, 23); }

typedef struct { char p[1028]; float f; } O_00188158; extern char D_0033C348[]; void func_00187028(void *); void func_00186F40(void *, void *, int, int);
// MATCH func_00188158
void srivus_00188158(O_00188158 *o) { func_00187028(o); o->f = 384.0f; func_00186F40(o, D_0033C348, 28, 30); }

typedef struct { char p[1028]; float f; } O_00188220; extern char D_0033D190[]; void func_00187028(void *); void func_00186F40(void *, void *, int, int);
// MATCH func_00188220
void srivus_00188220(O_00188220 *o) { func_00187028(o); o->f = 384.0f; func_00186F40(o, D_0033D190, 30, 32); }

typedef struct { char p[1224]; void *vt; } O_00187F10; extern char D_00339F20[], D_0043EDE0[]; void func_00187028(void *); void func_00186F40(void *, void *, int, int);
// MATCH func_00187F10
void srivus_00187f10(O_00187F10 *o) { func_00187028(o); func_00186F40(o, D_00339F20, 6, 11); o->vt = D_0043EDE0; }

void func_0018D160(void *);
// MATCH func_0018D1B8
void FUN_0018d1b8(char *o) { func_0018D160(o); func_0018D160(o + 16); func_0018D160(o + 32); func_0018D160(o + 48); }

float func_0018EAF8(void);
// MATCH func_00179098
int FUN_00179098(float a, float b) { if (func_0018EAF8() <= a + b) return 1; return 0; }

void func_0018C4C8(void *); void func_0018CA90(void *, void *);
// MATCH func_0018C588
void denlib_0018c588(void *a, void *b) { func_0018C4C8(a); func_0018CA90(a, b); }

void func_00154428(void *); void func_0018EB98(void *, void *);
// MATCH func_001544B8
void FUN_001544b8(char *a, char *b) { func_00154428(a); func_0018EB98(b, a + 128); }

typedef struct { void *p; } O_00184560; int func_00180BB0(void *);
// MATCH func_00184560
int FUN_00184560(O_00184560 *o) { return o->p ? func_00180BB0(o->p) : 0; }

typedef struct { char p[112]; char *q; char p2[216]; void *vt; } O_00172A60; extern char D_0043E020[]; void func_00108B80(void);
// MATCH func_00172A60
void FUN_00172a60(O_00172A60 *o, int f) { o->vt = D_0043E020; *(float *)(o->q + 200) = 1.0f; if (f & 1) func_00108B80(); }

typedef struct { char p[36]; int a[4]; } O_001AF0C0;
// MATCH func_001AF0C0
int nayuwin2_001af0c0(O_001AF0C0 *o, unsigned i) { if (i < 4) return o->a[i]; return 0; }

extern int D_004A3C60; void func_002A6110(void *, int);
// MATCH func_001C7980
void FUN_001c7980(void) { func_002A6110(&D_004A3C60, 2); }

extern int D_004A3C60; void func_002A6100(void *);
// MATCH func_001C7990
void FUN_001c7990(void) { func_002A6100(&D_004A3C60); }

extern char D_004A380A; typedef struct { char p[296]; int v; } O_001E2660;
// MATCH func_001E2660
void akari_001e2660(int a, O_001E2660 *p, int v) { if (D_004A380A != 0) p->v = v; }

extern char D_004A380A; typedef struct { char p[824]; int v; } O_001E42A0;
// MATCH func_001E42A0
void FUN_001e42a0(int a, O_001E42A0 *p, int v) { if (D_004A380A != 0) { if (p != 0) p->v = v; } }

extern char D_004A380A; typedef struct { char p[828]; int v; } O_001E42C0;
// MATCH func_001E42C0
void FUN_001e42c0(int a, O_001E42C0 *p, int v) { if (D_004A380A != 0) { if (p != 0) p->v = v; } }

extern char D_004A380A; typedef struct { char p[832]; int v; } O_001E4308;
// MATCH func_001E4308
void FUN_001e4308(int a, O_001E4308 *p, unsigned v) { if (D_004A380A != 0) { if (p != 0) { if (v < 256) p->v = v; } } }

typedef struct { char p[120]; int v; } O_001E8D08;
// MATCH func_001E8D08
int yue_001e8d08(O_001E8D08 *o, int a) { if (a < 2) return 0; o->v = a; return 1; }

typedef struct { char p[252]; unsigned char *src; int n; } O_001F60F0;
// MATCH func_001F60F0
void FUN_001f60f0(O_001F60F0 *o, unsigned char *dst) { int i; for (i = 0; i < o->n; i++) dst[i] = o->src[i]; }

extern int D_004A3864; void func_001118F8(void *);
// MATCH func_00197E58
void FUN_00197e58(void *a) { if (D_004A3864 & 0x10000) func_001118F8(a); }

extern char *D_0036CE50[];
// MATCH func_0019B6C0
int EfbCommandAllowed(int a, int b, int c) { char *p = D_0036CE50[c]; return p[b - 1] == 0x31 ? 1 : -1; }

void func_00254CE0(int, int); void func_00255008(int, int);
// MATCH func_001B4BE8
void FUN_001b4be8(int x, signed char a, signed char b) { int d = b - a; if (d < 0) func_00255008(x, -d); else func_00254CE0(x, d); }

void func_00254D70(int, int); void func_00255098(int, int);
// MATCH func_001B4C18
void FUN_001b4c18(int x, signed char a, signed char b) { int d = b - a; if (d < 0) func_00255098(x, -d); else func_00254D70(x, d); }

extern char D_004A380A;
// MATCH func_001E42E0
void FUN_001e42e0(unsigned char *o, unsigned char a, unsigned char b, unsigned char c) { if (D_004A380A != 0) { o[0] = a; o[1] = b; o[2] = c; } }

extern char D_004A380A; typedef struct { int p; int a, b; } O_001E4330;
// MATCH func_001E4330
void FUN_001e4330(O_001E4330 *o, int a, int b) { if (D_004A380A != 0) { o->a = a; o->b = b; } }

typedef struct { char p[76]; int n; char p2[280]; char *q; } O_001AF0F8;
// MATCH func_001AF0F8
int nayuwin2_001af0f8(O_001AF0F8 *o, int a, int b) { if (a < 0 || o->n < a) return 0; { char *r = o->q; r += a * 256; r += b * 4; return *(int *)(r + 40); } }

typedef struct { char p[76]; int n; char p2[280]; char *q; } O_001AF7B8;
// MATCH func_001AF7B8
void nayuwin2_001af7b8(O_001AF7B8 *o, int a, int v, int b) { if (a < 0 || o->n < a) return; { char *r = o->q; r += a * 256; r += b * 4; *(int *)(r + 40) = v; } }

typedef struct { char p[76]; int n; char p2[280]; char *q; } O_001AF7F0;
// MATCH func_001AF7F0
void nayuwin2_001af7f0(O_001AF7F0 *o, int a, int v) { if (a < 0 || o->n < a) return; { char *r = o->q + a * 256; *(int *)(r + 32) = v; } }

extern int *D_004A4670; extern char D_004555D8[]; void func_002119E0(void *, void *);
// MATCH func_00211A20
int FUN_00211a20(void) { func_002119E0(&D_004A4670, D_004555D8); if ((unsigned)(int)(D_004A4670) < 2) return 0; return *D_004A4670; }

extern int *D_004A4674; extern char D_004555F8[]; void func_002119E0(void *, void *);
// MATCH func_00211AC8
int FUN_00211ac8(void) { func_002119E0(&D_004A4674, D_004555F8); if ((unsigned)(int)(D_004A4674) < 2) return 0; return *D_004A4674; }

typedef struct { char p[8]; int n; int *q; } O_00211C68;
// MATCH func_00211C68
int FUN_00211c68(O_00211C68 *o, int a) { if (a < 0 || o->n < a) return 0; return o->q[a]; }

extern long long D_004A12D8; typedef struct { char p[8]; int w; } O_00215A28;
// MATCH func_00215A28
int FUN_00215a28(O_00215A28 *o) { if (D_004A12D8 & 0x200840) o->w = 0; return 1; }

extern long long D_004A12D8; typedef struct { char p[4]; int *a; int w; } O_00215A48; extern int D_003C2F80[];
// MATCH func_00215A48
int FUN_00215a48(O_00215A48 *o) { if (D_004A12D8 & 0x800) { int *p = D_003C2F80; o->a = p; o->w = p[1]; } return 1; }

extern int D_004A1510, D_004A12A4, D_004A4ABC; extern char D_004A4AD8[]; void func_002144F0(void); void func_002A43E8(void *, int);
// MATCH func_00216010
void FUN_00216010(void) { func_002144F0(); D_004A1510 = 1; D_004A12A4 = 14; D_004A4ABC = 0; func_002A43E8(D_004A4AD8, 0); }

void func_0029FE00(void *, int, int, float, float, float);
// MATCH func_00218470
void FUN_00218470(void *a, float *v, int c, int d) { func_0029FE00(a, c, d, v[0], v[1], v[2]); }

typedef struct { char p[36]; int w; } O_00219800; int func_00196FF8(void *);
// MATCH func_00219800
int FUN_00219800(O_00219800 *o) { if (func_00196FF8(o)) return 1; return (unsigned)(o->w - 1) < 2; }

typedef struct { char p[4976]; int w; } O_0021AE58; void func_00254990(int);
// MATCH func_0021AE58
void FUN_0021ae58(O_0021AE58 *o) { if (o->w >= 0) func_00254990(o->w); }

typedef struct { char p[4976]; int w; } O_0021AE78; void func_00254E38(int);
// MATCH func_0021AE78
void FUN_0021ae78(O_0021AE78 *o) { if (o->w >= 0) func_00254E38(o->w); }

// MATCH func_00219130
char *FUN_00219130(char *p) { while (*p != 10) p++; return p + 1; }

// MATCH func_00219168
void FUN_00219168(char *p) { while (*p != 10) p++; *p = 0; }

typedef struct { char p[4976]; int w; } O_0021A8F8; void func_00254990(int);
// MATCH func_0021A8F8
void FUN_0021a8f8(O_0021A8F8 *o) { if (o->w >= 0) func_00254990(o->w); o->w = -1; }

typedef struct { char p[4816]; unsigned w; } O_0021AE30;
// MATCH func_0021AE30
int FUN_0021ae30(O_0021AE30 *o, int a) { if (!(o->w & 0x40000000)) return 0; return a < 7; }

extern float D_004A0680; void func_00235138(float);
// MATCH func_00235130
void FUN_00235130(void) { func_00235138(D_004A0680); }

// MATCH func_00241FA8
int *FUN_00241fa8(int *p, int a, long long b) { *p++ = (int)b; *p++ = (int)(b >> 32); *p++ = a; *p++ = 0; return p; }

extern unsigned D_004A71E4;
// MATCH func_00243678
void object_00243678(void) { D_004A71E4 = 0xffffffff; }

extern int D_004A140C; extern char D_00239238[]; void func_002392F0(int, void *);
// MATCH func_002391F0
int FUN_002391f0(int a) { if (a == 0) return 0; if (a & 2) return 0; if ((D_004A140C & 8) == 0) return 0; func_002392F0(1, D_00239238); return 0; }

extern int D_004A1280, D_004A1288, D_004A1294; extern int D_0032965C[];
// MATCH func_0023A238
void FUN_0023a238(void) { D_004A1280 = 16; D_004A1288 = 8; D_004A1294 = D_0032965C[0]; }

extern int D_004A71A8; extern char D_0045CF30[]; void func_00246DB8(int); void func_001118F8(void *);
// MATCH func_002414D0
void FUN_002414d0(void) { if (D_004A71A8 != 0) func_00246DB8(D_004A71A8); D_004A71A8 = 0; func_001118F8(D_0045CF30); }

int func_002CEA48(void *);
// MATCH func_00100680
void FUN_00100680(int *a, void *b) { *a = func_002CEA48(b); }

void func_00108B80(void);
// MATCH func_001006F0
void FUN_001006f0(int a, int b) { if (b & 1) func_00108B80(); }

void func_00108B80(void);
// MATCH func_001098C8
void FUN_001098c8(int a, int b) { if (b & 1) func_00108B80(); }

extern int D_00343028[]; extern int D_004A3850; void func_0010ED80(void *);
// MATCH func_0010F000
void FUN_0010f000(void) { if (((D_00343028[0]) & 8) == 0 && D_004A3850 != 2) func_0010ED80(D_00343028); }

void func_0024AD58(int, int, int, int); void func_00111170(int);
// MATCH func_0010F3B8
void FUN_0010f3b8(int a, int b, int c) { func_0024AD58(a, b, c, 128); func_00111170(0); func_00111170(0); }

extern long long D_00319260[64];
// MATCH func_001100B8
void FUN_001100b8(void) { int i; for (i = 63; i >= 0; i--) D_00319260[i] = 0; }

extern int D_004A140C, D_004A6E1C; void func_001265D0(int);
// MATCH func_00116FF8
int FUN_00116ff8(int a) { if (a == 0) return 0; if ((D_004A140C & 8) == 0) return 0; func_001265D0(D_004A6E1C); return 0; }

// MATCH func_001171B8
void FUN_001171b8(char *p, int v, int n) { signed char c = v; while (n != 0) { *p = c; n--; p++; } }

int func_001128E0(void *); int func_001129A0(void *, int);
// MATCH func_00112A90
int FUN_00112a90(void *o) { int r = func_001128E0(o); if (r >= 0) return func_001129A0(o, r); return 0; }

typedef struct { char c[8]; } V8_00164A80;
typedef struct { int w[4]; } P_00164A80; typedef struct { P_00164A80 *p; char p1[20]; int a; int b; char p2[8]; V8_00164A80 v; } O_00164A80; extern V8_00164A80 D_004A2CE8[2];
// MATCH func_00164A80
void pachislot_00164a80(O_00164A80 *o) { o->a += o->p->w[3]; if (o->a >= o->b) { o->a = o->b; o->v = D_004A2CE8[0]; } }

typedef struct { char c[8]; } V8_0016AD90;
typedef struct { char p[560]; V8_0016AD90 v; } O_0016AD90; extern V8_0016AD90 D_004A2F10[2]; extern long long D_004A12D8;
// MATCH func_0016AD90
int pachislot_0016ad90(O_0016AD90 *o) { if (D_004A12D8 & 0x200040) o->v = D_004A2F10[0]; return 0; }

typedef struct { char c[8]; } V8_0016C8B0;
typedef struct { char p[32]; int a; int b; char p2[16]; V8_0016C8B0 v; } O_0016C8B0; extern V8_0016C8B0 D_004A2F68[2];
// MATCH func_0016C8B0
int FUN_0016c8b0(O_0016C8B0 *o) { int a = o->a - 6; int b = o->b - 6; o->a = a; o->b = b; if (a <= 0) { o->a = 0; o->b = 0; o->v = D_004A2F68[0]; } return 0; }

typedef struct { char c[8]; } V8_001743C0;
typedef struct { char p[372]; int w; char p2[32]; V8_001743C0 a; V8_001743C0 b; } O_001743C0;
// MATCH func_001743C0
int repetition_001743c0(O_001743C0 *o) { o->w = o->w - 1; if (o->w <= 0) { o->w = 0; o->a = o->b; } return 0; }

typedef struct { char c[8]; } V8_00170468;
typedef struct { char p[60]; int w; char p2[72]; V8_00170468 a; V8_00170468 b; } O_00170468; extern V8_00170468 D_004A30C0[2], D_004A30E0[2];
// MATCH func_00170468
int roulette_00170468(O_00170468 *o) { o->w = 0; o->a = D_004A30C0[0]; o->b = D_004A30E0[0]; return 0; }

typedef struct { char c[8]; } V8_001704A8;
typedef struct { char p[136]; V8_001704A8 a; V8_001704A8 b; } O_001704A8; extern V8_001704A8 D_004A30B0[2], D_004A30E8[2]; extern int D_004A3074;
// MATCH func_001704A8
int roulette_001704a8(O_001704A8 *o) { D_004A3074 = 1; o->a = D_004A30B0[0]; o->b = D_004A30E8[0]; return 0; }

void *func_002A4F30(void *);
// MATCH func_00179FD8
void *FUN_00179fd8(void *o) { func_002A4F30(o); return o; }

typedef struct { int a, b, c; } O_001809F8;
// MATCH func_001809F8
int FUN_001809f8(O_001809F8 *o) { if (o->a < o->b) return 0; return !(o->c < o->a); }

void func_00108B80(void);
// MATCH func_00184748
void FUN_00184748(int a, int b) { if (b & 1) func_00108B80(); }

typedef struct { char c[8]; } V8_00164A48;
typedef struct { char p[32]; int w; char p2[4]; V8_00164A48 v; } O_00164A48; extern V8_00164A48 D_004A2CE0[2];
// MATCH func_00164A48
void pachislot_00164a48(O_00164A48 *o) { if (o->w >= 0) { o->w--; if (o->w == -1) o->v = D_004A2CE0[0]; } }

typedef struct { char c[8]; } V8_0016AC30;
typedef struct { char p[464]; int w; char p2[40]; int f; char p3[32]; V8_0016AC30 v; } O_0016AC30; extern V8_0016AC30 D_004A2E50[2];
// MATCH func_0016AC30
int pachislot_0016ac30(O_0016AC30 *o) { o->f = 1; if (o->w-- <= 0) { o->w = 0; o->v = D_004A2E50[0]; o->f = 0; } return 0; }

// MATCH func_0018D908
int FUN_0018d908(void) { int *p = (int *)0x10000800; __asm__("" : "+r"(p)); return *p; }

// MATCH func_0018D918
void FUN_0018d918(void) { int *p = (int *)0x10000810; __asm__("" : "+r"(p)); *p = 0; }

extern char D_003215D0[]; void func_00114358(void); void func_001917D0(void *);
// MATCH func_00192B88
int FUN_00192b88(void) { func_00114358(); func_001917D0(D_003215D0); return 1; }

extern char D_003215D0[]; void func_001919D8(void *);
// MATCH func_00192BE0
int FUN_00192be0(void) { func_001919D8(D_003215D0); return 1; }

typedef struct { char p[4]; int n; char p2[20]; char *q; signed char k; } O_00203290;
// MATCH func_00203290
char *FUN_00203290(O_00203290 *o, int a) { if (o->k != 1 || a < 0 || o->n - 1 < a) return 0; return o->q + a * 16; }

typedef struct { char p[4]; int n; char p2[12]; int *q; char p3[8]; signed char k; } O_00203378;
// MATCH func_00203378
int FUN_00203378(O_00203378 *o, int a) { if (o->k != 1 || a < 0 || o->n - 1 < a) return 0; return o->q[a]; }

typedef struct { int n; int *p[1]; } O_00204CD0; typedef struct { char p[528]; int w; } T_00204CD0;
// MATCH func_00204CD0
void pchjob0_00204cd0(O_00204CD0 *o) { if (o->n > 0) ((T_00204CD0 *)o->p[o->n - 1])->w = 0; }

extern int D_004A48B8;
// MATCH func_0020BD40
void pchevent_0020bd40(int a) { D_004A48B8 = a != 0; }

extern int D_004A1444, D_004A140C, D_004A46B8;
// MATCH func_0020D2B8
void pchevent_0020d2b8(int a) { if (a != 0 && D_004A1444 == 0 && (D_004A140C & 8)) D_004A46B8 = 0; }

extern int D_004A45E4, D_004A4960; void func_0020B978(int, int);
// MATCH func_0020F0E0
int pchevent_0020f0e0(int a) { if (a & 8) { func_0020B978(D_004A45E4, D_004A4960); return -1; } return 0; }

extern char D_003215D0[]; typedef struct { long long a, b, c, d; } T_00192C08; void func_00191CE8(void *, void *);
// MATCH func_00192C08
int FUN_00192c08(int x, char *d) { T_00192C08 t; func_00191CE8(D_003215D0, &t); *(long long *)(d + 8) = t.a; *(long long *)(d + 16) = t.b; return 1; }

typedef struct { char p[12]; volatile int w; } O_00194A48;
// MATCH func_00194A48
void FUN_00194a48(O_00194A48 *o) { if (o->w > 0) o->w = o->w - 1; }

typedef struct { char p[5460]; float r, a, b; } O_0021AF40;
// MATCH func_0021AF40
void FUN_0021af40(O_0021AF40 *o) { float a = o->a; float b = o->b; if (a < b) o->r = b; else o->r = a; }

typedef struct { char p[5460]; float r, a, b; } O_0021B088;
// MATCH func_0021B088
void FUN_0021b088(O_0021B088 *o, float a, float b) { o->a = a; o->b = b; if (a < b) o->r = b; else o->r = a; }

typedef struct { char p[4900]; float f; } O_0021AFF0; float func_0021AF68(void *);
// MATCH func_0021AFF0
void FUN_0021aff0(O_0021AFF0 *o) { o->f = func_0021AF68(o); }

void func_00227F68(float);
// MATCH func_00227E58
void sammon_00227e58(void) { func_00227F68(1.0f); }

typedef struct { char p[1260]; int w; } O_00226B28; typedef struct { char p[124]; float f; char p2[84]; int w; } Q_00226B28; extern float D_004A1508;
// MATCH func_00226B28
void FUN_00226b28(O_00226B28 *o, Q_00226B28 *q) { if (o->w != 0) { q->w = 0; q->f = D_004A1508; } }

extern int D_003CAB30[20]; extern int D_0041EEA8[18];
// MATCH func_00220BC8
void FUN_00220bc8(void) { int i; for (i = 0; i < 18; i++) D_003CAB30[i + 1] = D_0041EEA8[i]; }

typedef struct { char p[604]; int w; } O_002194C0;
// MATCH func_002194C0
int FUN_002194c0(O_002194C0 *o) { int v = o->w; if (v != 0 && v != 10) return 0; return 1; }

typedef struct { char p[304]; int w; char p2[940]; int k; } O_00229800;
extern int D_004A1504; extern volatile float D_004A1508, D_004A05B0;
// MATCH func_00229800
void FUN_00229800(O_00229800 *o) { if (o->k == 1) { D_004A1504 = 0; D_004A1508 = D_004A05B0; o->w = 0; } }

typedef struct { char p[4812]; int w; } O_0021AEC0;
// MATCH func_0021AEC0
int FUN_0021aec0(O_0021AEC0 *o) { int v = o->w; if (v != 100 && (v ^ 0x65) != 0) return 0; return 1; }

extern char D_003D7058[]; void func_002454A8(void *, void *, void *);
// MATCH func_00245578
void FUN_00245578(void *a, void *b) { func_002454A8(D_003D7058, a, b); }

extern float D_005F76C0[3];
// MATCH func_002478E0
void FUN_002478e0(float a, float b, float c) { D_005F76C0[0] = a; D_005F76C0[1] = b; D_005F76C0[2] = c; }

// MATCH func_00249E18
void FUN_00249e18(float *v, float a, float b, float c) { v[0] = a; v[1] = b; v[2] = c; }

void func_00247C98(float, float, float);
// MATCH func_00247E30
void FUN_00247e30(float *v) { func_00247C98(v[0], v[1], v[2]); }

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

typedef struct { int a, b; } O_00244450;
// MATCH func_00244450
int object_00244450(O_00244450 *o) { if ((unsigned)(o->a - 27649) < 10239 && (unsigned)(o->b - 30977) < 3583) return 1; return 0; }

typedef struct { char p[148]; int w[8]; } T_0025DCE0; extern T_0025DCE0 D_003FEBA8;
// MATCH func_0025DCE0
int FUN_0025dce0(int a) { return (D_003FEBA8.w[a / 32] >> (a & 31)) & 1; }

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

extern int D_0041EEA8_00294FA8[] __asm__("D_0041EEA8"); int func_00164CD8(int);
// MATCH func_00294FA8
int battleslot_00294fa8(int a) { return D_0041EEA8_00294FA8[func_00164CD8(a) - 1]; }

typedef struct { char p[124]; int a, b, c, d; } G_0029B6C8;
extern G_0029B6C8 D_00620070;
// MATCH func_0029B6C8
void FUN_0029b6c8(void) { if (D_00620070.a == 28) { D_00620070.c = 1; D_00620070.d = 0; D_00620070.b = 0; D_00620070.a = 11; } }

extern int D_003FEBA8_00294260[] __asm__("D_003FEBA8"); int func_00294220(int);
// MATCH func_00294260
int FUN_00294260(int x) { D_003FEBA8_00294260[1] = 0; func_00294220(x); return D_003FEBA8_00294260[1]; }

typedef struct { char c[8]; } V8_00294BD0;
typedef struct { char p[56]; int w; char p2[16]; V8_00294BD0 a; V8_00294BD0 b; } O_00294BD0;
// MATCH func_00294BD0
int battleslot_00294bd0(O_00294BD0 *o) { if (o->w-- <= 0) { o->w = 0; o->a = o->b; } return -1; }

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

typedef struct { char p[112]; int a; long long b; } P_002C2DD0;
typedef struct { char p[64]; P_002C2DD0 *q; } O_002C2DD0;
// MATCH func_002C2DD0
void FUN_002c2dd0(O_002C2DD0 *o, long long v) { o->q->a = 1; o->q->b = v; }

extern char D_0062F600[];
// MATCH func_002CFFC0
char *FUN_002cffc0(int a, int b) { return D_0062F600 + (a << 12) + (b << 4); }

// MATCH func_002CADD8
int FUN_002cadd8(void) { int *p = (int *)0x10003820; __asm__("" : "+r"(p)); return *p; }

// MATCH func_002CED60
int FUN_002ced60(int a) { int *p = (int *)0x1000e060; __asm__("" : "+r"(p)); { int r = *p; *p = a; return r; } }

// MATCH func_002CE9E8
unsigned FUN_002ce9e8(unsigned a) { unsigned r = a; if ((a >> 28) == 7) { r = a & 0xfffffff; r |= 0x80000000; } return r; }

typedef struct { char p[384]; int w[16]; } P_002D5568;
P_002D5568 *func_002CFFB0(void);
// MATCH func_002D5568
int FUN_002d5568(unsigned a) { int r = 0; if (a < 16) r = func_002CFFB0()->w[a]; return r; }

typedef struct { char c[16]; } V16_0012E500;
typedef struct { char p[0]; V16_0012E500 v; } N_0012E500;
N_0012E500 *func_0012D9D8_0012E500(int, int) __asm__("func_0012D9D8");
// MATCH func_0012E500
int pchsysw_0012e500(int a, int b, V16_0012E500 *d) { N_0012E500 *n = func_0012D9D8_0012E500(a, b); if (n == 0) return 0; *d = n->v; return 1; }

typedef struct { char c[16]; } V16_0012E558;
typedef struct { char p[16]; V16_0012E558 v; } N_0012E558;
N_0012E558 *func_0012D9D8_0012E558(int, int) __asm__("func_0012D9D8");
// MATCH func_0012E558
int pchsysw_0012e558(int a, int b, V16_0012E558 *d) { N_0012E558 *n = func_0012D9D8_0012E558(a, b); if (n == 0) return 0; *d = n->v; return 1; }

typedef struct { char c[16]; } V16_0012E5B0;
typedef struct { char p[32]; V16_0012E5B0 v; } N_0012E5B0;
N_0012E5B0 *func_0012D9D8_0012E5B0(int, int) __asm__("func_0012D9D8");
// MATCH func_0012E5B0
int pchsysw_0012e5b0(int a, int b, V16_0012E5B0 *d) { N_0012E5B0 *n = func_0012D9D8_0012E5B0(a, b); if (n == 0) return 0; *d = n->v; return 1; }

typedef struct { int a, b, c, d; } O_0012EF68;
void func_0012DF68(int, int);
// MATCH func_0012EF68
void pchsysw_0012ef68(O_0012EF68 *o, int x) { func_0012DF68(o->a, x); func_0012DF68(o->b, x); func_0012DF68(o->c, x); func_0012DF68(o->d, x); }

typedef struct { int a, b, c, d; } O_0012F440;
void func_0012E2A8(int, float);
// MATCH func_0012F440
void pchsysw_0012f440(O_0012F440 *o, float f) { func_0012E2A8(o->a, f); func_0012E2A8(o->b, f); func_0012E2A8(o->c, f); func_0012E2A8(o->d, f); }

typedef struct { int a, b, c, d; } O_0012F3D0;
void func_0012E228(int, int, float);
// MATCH func_0012F3D0
void pchsysw_0012f3d0(O_0012F3D0 *o, int x, float f) { func_0012E228(o->a, x, f); func_0012E228(o->b, x, f); func_0012E228(o->c, x, f); func_0012E228(o->d, x, f); }

typedef struct { int a, p; } O_0012F650;
void func_00131588(void *); void func_00108B80_0012F650(void *) __asm__("func_00108B80");
// MATCH func_0012F650
void pchsysw_0012f650(O_0012F650 *o, int f) { if (o->p != 0) func_00131588(o->p); if (f & 1) func_00108B80_0012F650(o); }

typedef struct N_0012D4F0 { char p[24]; struct N_0012D4F0 *next; } N_0012D4F0;
typedef struct { int n; int b; N_0012D4F0 *h; } O_0012D4F0;
// MATCH func_0012D4F0
N_0012D4F0 *FUN_0012d4f0(O_0012D4F0 *o, int a) { N_0012D4F0 *p; if (a < 0 || a >= o->n) return 0; p = o->h; if (a > 0) { do { p = p->next; } while (--a != 0); } return p; }

typedef struct N_0012D9D8 { char p[60]; struct N_0012D9D8 *next; } N_0012D9D8;
typedef struct { int n; int b; N_0012D9D8 *h; } O_0012D9D8;
// MATCH func_0012D9D8
N_0012D9D8 *pchsysw_0012d9d8(O_0012D9D8 *o, int a) { N_0012D9D8 *p; if (a < 0 || a >= o->n) return 0; p = o->h; if (a > 0) { do { p = p->next; } while (--a != 0); } return p; }

void func_0029FDE8(float, float, float, float, float, float);
// MATCH func_002BEE90
void FUN_002bee90(float a, float b, float c) { func_0029FDE8(a, b, c, 0.0f, 0.0f, 0.0f); }

void func_0029FDE8(float, float, float, float, float, float);
// MATCH func_002BEE78
void FUN_002bee78(float a) { func_0029FDE8(a, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f); }

void func_002BEE90(void *, int, int, int, float, float, float);
// MATCH func_002BEE38
void FUN_002bee38(void *s, float a, int b) { func_002BEE90(s, 15, b, 0, 0.0f, a, 0.0f); }

void func_002BEE90(void *, int, int, int, float, float, float);
// MATCH func_002BEE58
void FUN_002bee58(void *s) { func_002BEE90(s, 44, 0, 0, 0.0f, 0.0f, 0.0f); }

extern float D_004A04B4; typedef struct { char p[16]; float a, b, c; } O_002197D0;
// MATCH func_002197D0
void FUN_002197d0(O_002197D0 *o, float x, float y, float z) { float a = x - D_004A04B4; float b = y - D_004A04B4; o->c = z; o->a = a; o->b = b; if (a < 0.0f) o->a = 0.0f; }

typedef struct { char p[16]; int *q; char p2[12]; int i; } O_0016EE38;
extern char D_0041EFB0[]; void func_00153EB8(void *, int); void func_00153D80(void *, float, float, float);
// MATCH func_0016EE38
void darts_0016ee38(O_0016EE38 *o) { func_00153EB8(D_0041EFB0, o->q[o->i] + 32); func_00153D80(D_0041EFB0, 0.0f, -1.0f, 0.0f); }

typedef struct { char p[16]; int *q; char p2[12]; int i; } O_0016EE90;
typedef struct { char p[12]; float f; } G_0016EE90;
extern G_0016EE90 D_0041EFB0_0016EE90 __asm__("D_0041EFB0"); void func_0018EB78(void *, int); void func_00153D80(void *, float, float, float);
// MATCH func_0016EE90
void darts_0016ee90(O_0016EE90 *o) { func_0018EB78(&D_0041EFB0_0016EE90, o->q[o->i] + 32); D_0041EFB0_0016EE90.f = 1.0f; func_00153D80(&D_0041EFB0_0016EE90, 0.0f, -1.0f, 0.0f); }

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

typedef struct { char c[8]; } V8_0016DF68;
typedef struct { char p[32]; int a; char p2[8]; int n; char p3[56]; V8_0016DF68 v; } O_0016DF68;
extern V8_0016DF68 D_004A2FE0[2];
// MATCH func_0016DF68
int darts_0016df68(O_0016DF68 *o) { if (o->n++ < 10) return 0; o->a++; o->v = D_004A2FE0[0]; return 0; }

typedef struct { char c[8]; } V8_0016FB20;
typedef struct { char p[60]; int w; char p2[72]; V8_0016FB20 a; V8_0016FB20 b; } O_0016FB20;
extern V8_0016FB20 D_004A3080[2], D_004A3088[2]; void func_0016FA70(void *);
// MATCH func_0016FB20
int roulette_0016fb20(O_0016FB20 *o) { o->w = 13107; func_0016FA70(o); o->a = D_004A3080[0]; o->b = D_004A3088[0]; return 0; }

typedef struct { char c[8]; } V8_001692B0;
typedef struct { char p[360]; int a, b; char p2[132]; int w; char p3[40]; V8_001692B0 v; } O_001692B0;
extern V8_001692B0 D_004A2E58[2];
// MATCH func_001692B0
int pachislot_001692b0(O_001692B0 *o) { o->w = o->w + 8; if (o->w >= 128) { o->w = 128; o->b = o->b + o->a; o->v = D_004A2E58[0]; } return 0; }

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

typedef struct { char p[44]; int n; char p2[44]; int f; } O_0016E208;
void func_0016E510(void *);
// MATCH func_0016E208
int darts_0016e208(O_0016E208 *o) { func_0016E510(o); if (o->n++ & 0x20) o->f = 0; else o->f = 1; return 1; }

typedef struct { char p[44]; int n; char p2[40]; int f; int g; } O_0016E258;
void func_0016E510(void *);
// MATCH func_0016E258
int darts_0016e258(O_0016E258 *o) { func_0016E510(o); o->g = 0; if (o->n++ & 0x20) o->f = 0; else o->f = 1; return 1; }

extern long long D_004A12D8_00175ED8 __asm__("D_004A12D8"); typedef struct { char p[348]; int w; char p2[16]; short h; } O_00175ED8; int func_00172CC8(void *);
// MATCH func_00175ED8
int repetition_00175ed8(O_00175ED8 *o) { if (func_00172CC8(o) != 0 && (D_004A12D8_00175ED8 & 0x100010)) { o->w = 0; o->h = -2; } return o->h != -1; }

typedef struct { char p[8]; short adj; short pad; void (*fn)(void *); } VT_00180BF8;
typedef struct { char p[12]; VT_00180BF8 *vt; } O_00180BF8;
extern char D_0043E420[]; void *func_00162130(int, void *, int); O_00180BF8 *func_00180C58(void *);
// MATCH func_00180BF8
O_00180BF8 *screfct_00180bf8(void) { O_00180BF8 *p = func_00180C58(func_00162130(896, D_0043E420, 140)); if (p != 0) p->vt->fn((char *)p + p->vt->adj); return p; }

typedef struct { char p[8]; short adj; short pad; void (*fn)(void *); } VT_00183BB8;
typedef struct { char p[12]; VT_00183BB8 *vt; } O_00183BB8;
extern char D_0043E420_00183BB8[] __asm__("D_0043E420"); void *func_00162130(int, void *, int); O_00183BB8 *func_00183C18(void *);
// MATCH func_00183BB8
O_00183BB8 *screfct_00183bb8(void) { O_00183BB8 *p = func_00183C18(func_00162130(176, D_0043E420_00183BB8, 891)); if (p != 0) p->vt->fn((char *)p + p->vt->adj); return p; }

typedef struct { char p[1224]; void *vt; char p2[552]; int w; } O_00188FA0;
extern char D_0033FD18[], D_0043F620[]; void func_00187028(void *); void func_00186F40(void *, void *, int, int);
// MATCH func_00188FA0
void srivus_00188fa0(O_00188FA0 *o) { func_00187028(o); func_00186F40(o, D_0033FD18, 37, 40); if (o->w == 39) o->vt = D_0043F620; }

typedef struct { char p[1224]; void *vt; char p2[552]; int w; } O_001892E8;
extern char D_00342860[], D_0043FBA0[]; void func_00187028(void *); void func_00186F40(void *, void *, int, int);
// MATCH func_001892E8
void FUN_001892e8(O_001892E8 *o) { func_00187028(o); func_00186F40(o, D_00342860, 43, 46); if (o->w == 45) o->vt = D_0043FBA0; }

typedef struct { char p[12]; void *vt; char p2[128]; int w; } O_001832D8;
extern char D_0043E4A8[]; void func_00131588_001832D8(int) __asm__("func_00131588"); void func_00185168(void *, int);
// MATCH func_001832D8
void screfct_001832d8(O_001832D8 *o, int f) { o->vt = D_0043E4A8; if (o->w != 0) func_00131588_001832D8(o->w); func_00185168(o, f); }

typedef struct { char *a, *b, *c, *d, *e, *f; } O_00192D80;
extern char D_002F0900[], D_002F1200[], D_002F2D00[], D_002F2D80[], D_002F1B00[], D_002F2400[];
// MATCH func_00192D80
void FUN_00192d80(O_00192D80 *o) { o->a = D_002F0900; o->b = D_002F1200; o->c = D_002F2D00; o->d = D_002F2D80; o->e = D_002F1B00; o->f = D_002F2400; }

typedef struct { int a, b; } O_0018C4C8;
void func_00131588_0018C4C8(int) __asm__("func_00131588");
// MATCH func_0018C4C8
void denlib_0018c4c8(O_0018C4C8 *o) { if (o->a != 0) { func_00131588_0018C4C8(o->a); } o->a = 0; if (o->b != 0) { func_00131588_0018C4C8(o->b); } o->b = 0; }

typedef struct { float x, y, z, w; } V4_001262D0;
typedef struct { char p[64]; V4_001262D0 v1; V4_001262D0 v2; char p2[16]; int i; char pa[4]; int j, k; } O_001262D0;
static inline void set_001262D0(V4_001262D0 *v, float x, float y, float z) { v->x = x; v->y = y; v->z = z; v->w = 1.0f; }
// MATCH func_001262D0
void battle_001262d0(O_001262D0 *o, float a, float b, float c, int i, int j, int k, float d, float e, float f) { o->i = i; o->j = j; o->k = k; set_001262D0(&o->v1, a, b, c); set_001262D0(&o->v2, d, e, f); }

typedef struct { float x, y, z, w; } V4_00126288;
typedef struct { char p[64]; V4_00126288 v1; V4_00126288 v2; char p2[16]; int i; char pa[4]; int j, k; char pb[4]; float g; int m; } O_00126288;
static inline void set_00126288(V4_00126288 *v, float x, float y, float z) { v->x = x; v->y = y; v->z = z; v->w = 1.0f; }
// MATCH func_00126288
void battle_00126288(O_00126288 *o, float a, float b, float c, int i, int j, int k, float d, float e, float f, float g, int m) { set_00126288(&o->v1, a, b, c); set_00126288(&o->v2, d, e, f); o->i = i; o->j = j; o->k = k; o->m = m; o->g = g; }

typedef int u128 __attribute__((mode(TI)));
// MATCH func_0018EB78
void FUN_0018eb78(u128 *d, u128 *s) { *d = *s; }

void func_00192928(void *, void *, void *, void *, void *);
// MATCH func_001929C0
int FUN_001929c0(void *s) { int v[4]; func_00192928(s, v, v + 1, v + 2, v + 3); return v[1] + v[3]; }

typedef struct { char p[64]; int col; char p2[12]; unsigned fl; } O_0016F828;
extern long long D_004A12D8_0016F828 __asm__("D_004A12D8");
// MATCH func_0016F828
int FUN_0016f828(O_0016F828 *o) { int r; if (o->fl & 0x10) o->col = 0x808080; else o->col = 0xffffff; r = 1; if ((D_004A12D8_0016F828 & 0xa000) == 0) r = 0; return r; }

typedef struct { char p[64]; int col; char p2[12]; unsigned fl; } O_0016F860;
extern long long D_004A12D8_0016F860 __asm__("D_004A12D8");
// MATCH func_0016F860
int FUN_0016f860(O_0016F860 *o) { int r; if (o->fl & 0x10) o->col = 0xffffff; else o->col = 0x808080; r = 1; if ((D_004A12D8_0016F860 & 0xa000) == 0) r = 0; return r; }

// MATCH func_002191A0
void FUN_002191a0(char *d, char *s) { if (s != 0) { while (*s != 10 && *s != 0) { *d++ = *s++; } } *d = 0; }

typedef struct { int n; int tbl[1]; } T_0021B5B8;
typedef struct { char p[152]; T_0021B5B8 *t; char p2[32]; short i; } O_0021B5B8;
// MATCH func_0021B5B8
unsigned FUN_0021b5b8(O_0021B5B8 *o) { T_0021B5B8 *p = o->t; int i; if (p == 0) return 0; i = o->i; if (i < 0) return 0; if ((unsigned)(p->n - 1) < (unsigned)i) return 0; return *(unsigned short *)((char *)p + *(int *)((char *)p + i * 4 + 4) + 2); }

extern int D_004A1A54; extern int *D_004A6FBC;
// MATCH func_0021DD18
int FUN_0021dd18(void) { int *p; if (D_004A1A54 != 0) return 0; p = D_004A6FBC; return (p[-4] & 0x10000000) > 0; }

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

typedef struct { int n; int a; void *p; } O_0024CEA8;
extern char D_0045E008[]; void *func_00162130(int, void *, int);
// MATCH func_0024CEA8
void pstack_0024cea8(O_0024CEA8 *o, int n) { o->n = n; o->p = func_00162130(n * 4, D_0045E008, 35); }

typedef struct { int a; char p[16]; int b; char p2[36]; int c, d, e, f; } O_002A0E70;
extern int D_004249E8[], D_004249F8[];
// MATCH func_002A0E70
O_002A0E70 *clas_min_002a0e70(O_002A0E70 *o) { o->a = 0; D_004249E8[0] = 0; D_004249F8[0] = 0; o->b = -1; o->c = -1; o->d = 0; o->e = 0; o->f = 0; return o; }

// MATCH func_002A1AD0
void clas_min_002a1ad0(char *o) { int i; int *p = (int *)(o + 260); for (i = 0; i < 5; i++) { p[-1] = 0; p[1] = 0; p[0] = -1; p += 68; } }

// MATCH func_0029C398
int clas_min_0029c398(int x, unsigned char *p, int i) { int j = (i / 4) * 4; return p[j] == 44; }

typedef struct { long long *p; } W_002CF410;
// MATCH func_002CF410
void FUN_002cf410(W_002CF410 *w, unsigned a, long long b) { long long *p = w->p; *p = b; p++; *p = (long long)a; p++; w->p = p; }

extern int D_00426300[]; extern unsigned char D_0049DF50[]; void func_002DD4CC_002C9D00(void *, int) __asm__("func_002DD4CC");
// MATCH func_002C9D00
void FUN_002c9d00(unsigned i, unsigned char *d) { if (i < 8) func_002DD4CC_002C9D00(d, D_00426300[i]); else *d = D_0049DF50[0]; }

extern int D_00426320[]; extern unsigned char D_0049DF50_002C9DF0[] __asm__("D_0049DF50"); void func_002DD4CC_002C9DF0(void *, int) __asm__("func_002DD4CC");
// MATCH func_002C9DF0
void FUN_002c9df0(unsigned i, unsigned char *d) { if (i < 4) func_002DD4CC_002C9DF0(d, D_00426320[i]); else *d = D_0049DF50_002C9DF0[0]; }

// MATCH func_00163080
char *FUN_00163080(int *p, int i) { if (p == 0) return 0; if (i < 0) return 0; if (i >= p[0]) return 0; return (char *)p + p[i + 1]; }

typedef struct { char pad[80]; short adj; short p2; void (*fn)(void *); } VT_1760f8_001760F8;
typedef struct { char pad[896]; VT_1760f8_001760F8 *vt; } O_1760f8_001760F8;
extern O_1760f8_001760F8 *D_004A6F50;
// MATCH func_001760F8
void repetition_001760f8(void) { O_1760f8_001760F8 *o = D_004A6F50; o->vt->fn((char *)o + o->vt->adj); }

typedef struct { char pad[40]; int v; } S_15ad98_0015AD98;
// MATCH func_0015AD98
int FUN_0015ad98(S_15ad98_0015AD98 **p) { S_15ad98_0015AD98 *q = *p; if (q == 0 || q->v == 0) return 0; return 1; }

typedef struct { char pad[44]; int v; } S_15adc0_0015ADC0;
// MATCH func_0015ADC0
int FUN_0015adc0(S_15adc0_0015ADC0 **p) { S_15adc0_0015ADC0 *q = *p; if (q == 0 || q->v == 0) return 0; return 1; }

typedef struct { int n; char *e; } L_12fbe8_0012FBE8;
// MATCH func_0012FBE8
int FUN_0012fbe8(L_12fbe8_0012FBE8 *l, int i) { int n = l->n; if (i >= n || *(int *)(l->e + i * 64 + 16) == 0) return n * 2; return *(int *)(l->e + i * 64 + 52); }

typedef struct { char pad[24]; int a; int b; } S_16f508_0016F508;
// MATCH func_0016F508
void darts_0016f508(S_16f508_0016F508 *s, int n) { s->a += n; if (s->a > 99999999) s->a = 99999999; if (s->a > s->b) s->b = s->a; }

typedef struct { int n; char *e; } L_1301e0_001301E0;
// MATCH func_001301E0
int FUN_001301e0(L_1301e0_001301E0 *l, int i) { if (i >= l->n || *(int *)(l->e + i * 64 + 16) == 0) return 0; return *(int *)(l->e + i * 64 + 16); }

void *func_002056A8(int, int, int);
// MATCH func_00205778
void pchjob0_00205778(int a, int b, int c, int d) { int *p = func_002056A8(a, b, c); if (p != 0) *p = d; }

void *func_002056A8(int, int, int);
// MATCH func_002057A8
void pchjob0_002057a8(int a, int b, int c, int d) { int *p = func_002056A8(a, b, c); if (p != 0) p[1] = d; }

// MATCH func_0020BCC0
char *pchevent_0020bcc0(char *s) { char *p = s; while (*p != 0) { unsigned char c = *p; if ((unsigned char)(c - 97) < 26) *p = c - 32; p++; } return s; }

extern unsigned D_004A69FC_002A2118 __asm__("D_004A69FC"); extern char D_00424A98[];
void func_002DD4CC_002A2118(void *) __asm__("func_002DD4CC"); void func_002DD718(void *);
// MATCH func_002A2118
void clas_min_002a2118(void) { D_004A69FC_002A2118 |= 0x40; func_002DD4CC_002A2118(D_00424A98); func_002DD718(D_00424A98); }

extern char D_00424D98[]; extern int D_004A14E0;
void func_002A2240(void); void func_0018B668(void *, int);
// MATCH func_002A3928
void clas_min_002a3928(void) { func_002A2240(); func_0018B668(D_00424D98, D_004A14E0); }

// MATCH func_0022D750
int FUN_0022d750(int *b, int i) { unsigned char *e = (unsigned char *)b + b[i + 1]; int v = *(unsigned short *)(e + 2); if (((e[1] ^ 1) & 1) != 0) return v; return (v >> 1) + 1; }

typedef struct { int a0; char pad[20]; int a24; } S_2a4800_002A4800;
void func_002BEB90(int, int);
// MATCH func_002A4800
void clas_min_002a4800(S_2a4800_002A4800 *s) { s->a24 = 0; if (s->a0 != 0) func_002BEB90(s->a0, 3); s->a0 = 0; }

typedef struct { char pad[48]; int a48; int pad1; int a56; int pad2; int a64; int pad3; int a72; } S_2a64d0_002A64D0;
void func_0029D010_002A64D0(void *, int, float) __asm__("func_0029D010");
// MATCH func_002A64D0
void FUN_002a64d0(S_2a64d0_002A64D0 *s, int a, int b, int c) { s->a72 = c; s->a56 = 0; s->a64 = 0; s->a48 = 0; func_0029D010_002A64D0(s, 0, (float)a); }

typedef struct { char pad[20]; char sub[1]; char pad1[31]; int a52; int pad2; int a60; int pad3; int a68; int a72; } S_2a64f8_002A64F8;
void func_0029D010_002A64F8(void *, int, float) __asm__("func_0029D010");
// MATCH func_002A64F8
void FUN_002a64f8(S_2a64f8_002A64F8 *s, int a, int b, int c) { s->a72 = c; s->a60 = 0; s->a68 = 0; s->a52 = 0; func_0029D010_002A64F8(s->sub, 0, (float)a); }

typedef struct { char pad[240]; char a240[64]; char a304[1]; char pad2[1583]; int k; } S_2a7aa0_002A7AA0;
// MATCH func_002A7AA0
char *FUN_002a7aa0(S_2a7aa0_002A7AA0 *s) { int k = s->k; if (k == 1) return s->a304; if (k == 2) return s->a240; if (k == 4) return s->a304; return 0; }

extern char D_00425E22[]; extern char D_0049B968[];
int func_002DD36C(void *, void *);
// MATCH func_002AF418
char *FUN_002af418(void) { if (func_002DD36C(D_00425E22, D_0049B968) == 0) return D_00425E22 - 148; return D_00425E22; }

// MATCH func_002BC8F8
float FUN_002bc8f8(float a, float b) { if (a > 0.0f) { if (a > b) a = b; } else { b = -b; if (a < b) a = b; } return a; }

typedef struct { char pad[12]; float a, b, c; } S_2bec78_002BEC78;
void func_002A74F8(void *); void func_002A71F8(void *);
// MATCH func_002BEC78
void FUN_002bec78(S_2bec78_002BEC78 *s, float x, float y, float z) { s->a = x; s->b = y; s->c = z; func_002A74F8(s); func_002A71F8(s); }

typedef struct { char pad[64]; int a64; } S_2c2b28_002C2B28;
void func_002C3620(int, int, int);
// MATCH func_002C2B28
void FUN_002c2b28(S_2c2b28_002C2B28 *s, int a, int n) { func_002C3620(s->a64, a, ((n + 19) / 16) * 16); }

// MATCH func_002C5C38
void FUN_002c5c38(int a) { unsigned *p = (unsigned *)0x10002010; *p = (*p & 0xff7fffff) | (a << 23); }

extern unsigned D_00426280[];
typedef struct { char pad[2072]; unsigned v; } S_2c6e20_002C6E20;
// MATCH func_002C6E20
void FUN_002c6e20(S_2c6e20_002C6E20 *s, unsigned b) { *(volatile unsigned *)0x10002000 = b; s->v = D_00426280[b >> 28]; }

typedef struct { char pad[30]; unsigned short h; } S_2d46b0_002D46B0;
void *func_002CFF20(unsigned);
// MATCH func_002D46B0
int FUN_002d46b0(unsigned n) { int r = -1; if (n < 48) r = ((S_2d46b0_002D46B0 *)func_002CFF20(n))->h; return r; }

typedef struct { char pad[81]; unsigned char b; } S_2d4fe0_002D4FE0;
void *func_002CFF08(unsigned);
// MATCH func_002D4FE0
int FUN_002d4fe0(unsigned n) { if (n < 48) { S_2d4fe0_002D4FE0 *p = (S_2d4fe0_002D4FE0 *)func_002CFF08(n); if (p->b == 3) p->b = 0; } return -1; }

void func_002D04C0(int, int, int, int);
// MATCH func_002D5448
int FUN_002d5448(long a) { if ((a & 0xff000000) == 0) func_002D04C0(75, (int)a, 0, 0); return 0; }

void func_002D04C0(int, int, int, int);
// MATCH func_002D5488
int FUN_002d5488(long a) { if ((a & 0xff000000) == 0) func_002D04C0(76, (int)a, 0, 0); return 0; }

int func_002DA4E0(int, int, int);
// MATCH func_002DA588
int FUN_002da588(int a, int b, int c, int d) { if (func_002DA4E0(a, b, c) == 0) d = 0; return d; }

long func_002DDD90(char *, char **, int);
// MATCH func_002DB920
int FUN_002db920(char *a) { return func_002DDD90(a, 0, 10); }

int func_002E5CB0(int); void func_002E5D20(void);
// MATCH func_002EDB08
int FUN_002edb08(void) { if (func_002E5CB0(4) & 0x40000) { func_002E5D20(); return 1; } return 0; }

void func_002EE200(int); void func_002E54C0(int);
// MATCH func_002EE2C0
void FUN_002ee2c0(int a) { func_002EE200(a); func_002E54C0(a); }

void func_002E5CD0(int, void *);
// MATCH func_002E6970
void FUN_002e6970(int a, signed char b) { struct { int a, b; } t; t.a = a; t.b = b; func_002E5CD0(3, &t); }

void func_002E5CD0(int, void *);
// MATCH func_002E69C8
void FUN_002e69c8(int a, int b, unsigned short c) { struct { int a, b, c; } t; t.a = a; t.b = b; t.c = c; func_002E5CD0(-5, &t); }

void func_002E5CD0(int, void *);
// MATCH func_002E6A00
void FUN_002e6a00(int a, int b, unsigned short c) { struct { int a, b, c; } t; t.a = a; t.b = b; t.c = c; func_002E5CD0(-6, &t); }

void func_002E5CD0(int, void *);
// MATCH func_002E6A38
void FUN_002e6a38(int a, signed char b) { struct { int a, b; } t; t.a = a; t.b = b; func_002E5CD0(-7, &t); }

extern int D_00427DC8[];
int func_002CD428(int, int, int, int);
// MATCH func_002CD560
int FUN_002cd560(int a, int b, int c) { int r = func_002CD428(a, b, c, 64); if (r == 0) D_00427DC8[0] = 11; return r; }

extern void (*D_00427EF4[])(void);
// MATCH func_002D62C8
void FUN_002d62c8(void) { D_00427EF4[0](); }

extern void (*D_00427EF8[])(void); void func_002D63F8(void);
// MATCH func_002D63D0
void FUN_002d63d0(void) { (D_00427EF8[0] = func_002D63F8)(); }

extern int D_004A7418[]; extern char D_0049E6B8[];
void func_002DA568(void *, void *);
// MATCH func_002D8860
int *FUN_002d8860(void) { if (D_004A7418[0] == 0) func_002DA568(D_004A7418, D_0049E6B8); return D_004A7418; }

extern int D_004A7420[]; extern char D_0049E8A0[];
void func_002DA568(void *, void *);
// MATCH func_002DAB40
int *FUN_002dab40(void) { if (D_004A7420[0] == 0) func_002DA568(D_004A7420, D_0049E8A0); return D_004A7420; }

int func_002E5CB0(int);
// MATCH func_002EDAE0
int FUN_002edae0(void) { return (func_002E5CB0(4) & 0x10000) > 0; }

typedef struct { int a0, a4, a8, a12, tail; } S_2e6ae0_002E6AE0;
extern S_2e6ae0_002E6AE0 D_00632340;
// MATCH func_002E6AE0
S_2e6ae0_002E6AE0 *FUN_002e6ae0(int a) { S_2e6ae0_002E6AE0 *s = &D_00632340; int *t = &s->tail;
s->a4 = 0;
s->a12 = (int)t;
s->a8 = (int)t;
s->a0 = a;
return s; }

extern void (*D_0062B644[])(int); extern int D_0062B648[], D_00426364[];
// MATCH func_002CB588
void FUN_002cb588(void) { void (*cb)(int) = D_0062B644[0]; if (cb != 0 && D_00426364[0] == 0) cb(D_0062B648[0]); }

int func_002EE6B0(int);
// MATCH func_002EE6C0
int FUN_002ee6c0(int a) { if ((unsigned)(a - 13) >= 35) return -1; return func_002EE6B0(a); }

// MATCH func_00126208
int battle_00126208(int x) { if (x & 0x11000) return 0; if (x & 0x24000) return 3; if (x & 0x48000) return 1; return (x & 0x82000) ? 2 : -1; }

int func_0010B1A8(int, int, int, int, int, int);
// MATCH func_0010B188
int rsound_0010b188(int a, int b, int c, int d, int e) { return func_0010B1A8(a, b, c, d, e, -1); }

typedef struct { char pad[10]; short h; } S_171ad0_00171AD0;
// MATCH func_00171AD0
int roulette_00171ad0(S_171ad0_00171AD0 *s) { int v = s->h; if (v != 0) v = 12 - v; return v; }

extern int D_004A1AA8;
void func_0021E950(int, int, int);
// MATCH func_0012ACA0
void battle_0012aca0(int a, int b) { func_0021E950(D_004A1AA8, b, a); }

extern int D_004A14B8;
void func_0018EB98_002492E8(void *, int) __asm__("func_0018EB98"); void func_0018DF68(void *, int);
// MATCH func_002492E8
void FUN_002492e8(void *a) { if (D_004A14B8 != 0) func_0018EB98_002492E8(a, 0x70003d80); else func_0018DF68(a, 0x70003f80); }

typedef struct { int x, y, z, w; } V_15ec08_0015EC08;
typedef struct { char pad[16]; V_15ec08_0015EC08 v; } S_15ec08_0015EC08;
static inline void set_15ec08_0015EC08(V_15ec08_0015EC08 *v, int x, int y, int z, int w) {
v->x = x;
v->y = y;
v->z = z;
v->w = w;
}
// MATCH func_0015EC08
void flare_0015ec08(S_15ec08_0015EC08 *s, int x, int y, int z) { set_15ec08_0015EC08(&s->v, x, y, z, 128); }

typedef struct { char pad[24]; short adj; short p2; void (*fn)(void *, int); } VT_184518_00184518;
typedef struct { char pad[12]; VT_184518_00184518 *vt; } O_184518_00184518;
typedef struct { O_184518_00184518 *o; } S_184518_00184518;
// MATCH func_00184518
void FUN_00184518(S_184518_00184518 *s) { O_184518_00184518 *p = s->o; if (p != 0) p->vt->fn((char *)p + p->vt->adj, 3); s->o = 0; }

typedef struct { float x, y, z, w; } V_154038_00154038;
typedef struct { char pad[192]; V_154038_00154038 v; } S_154038_00154038;
void func_00153B38(void *); void func_00154550(void *);
static inline void set_154038_00154038(V_154038_00154038 *v, float x, float y, float z, float w) { v->x = x; v->y = y; v->z = z; v->w = w; }
// MATCH func_00154038
void FUN_00154038(S_154038_00154038 *s, float a, float b, float c, float d) { set_154038_00154038(&s->v, a, b, c, d); func_00153B38(&s->v); func_00154550(s); }

typedef struct { float x, y, z, w; } V_156570_00156570;
typedef struct { char pad[96]; V_156570_00156570 v; float f112; } S_156570_00156570;
static inline void set_156570_00156570(V_156570_00156570 *v, float x, float y, float z, float w) { v->x = x; v->y = y; v->z = z; v->w = w; }
// MATCH func_00156570
void FUN_00156570(S_156570_00156570 *s, float f, int a, int b, int c) { s->f112 = f; set_156570_00156570(&s->v, (float)a, (float)b, (float)c, 1.0f); }

typedef struct { float x, y, z, w; } V_156b20_00156B20;
typedef struct { char pad[176]; V_156b20_00156B20 v; } S_156b20_00156B20;
static inline void set_156b20_00156B20(V_156b20_00156B20 *v, float x, float y, float z, float w) { v->x = x; v->y = y; v->z = z; v->w = w; }
// MATCH func_00156B20
void FUN_00156b20(S_156b20_00156B20 *s, int a, int b, int c) { set_156b20_00156B20(&s->v, (float)a, (float)b, (float)c, 128.0f); }

typedef struct { float x, y, z, w; } V_156cf8_00156CF8;
typedef struct { char pad[192]; V_156cf8_00156CF8 v; float f208; } S_156cf8_00156CF8;
static inline void set_156cf8_00156CF8(V_156cf8_00156CF8 *v, float x, float y, float z, float w) { v->x = x; v->y = y; v->z = z; v->w = w; }
// MATCH func_00156CF8
void FUN_00156cf8(S_156cf8_00156CF8 *s, float f, int a, int b, int c) { s->f208 = f; set_156cf8_00156CF8(&s->v, (float)a, (float)b, (float)c, 1.0f); }

int func_001114B0(void);
extern int D_004A14F8;
// MATCH func_00128030
int battle_00128030(void) { if (func_001114B0()) return 1; return D_004A14F8; }

typedef struct { char pad[360]; char *a360; } G_108b20_00108B20;
extern G_108b20_00108B20 *D_0036CB78[];
// MATCH func_00108B20
void FUN_00108b20(void) { short m = -2; char *p = D_0036CB78[0]->a360; int i; for (i = 11; i >= 0; i--) { *(short *)(p + 250) = m; *(short *)(p + 3322) = m; p += 256; } }

typedef struct { char pad[32]; short adj; short p2; int (*fn)(void *); } VT_1844d8_001844D8;
typedef struct { char pad[12]; VT_1844d8_001844D8 *vt; } O_1844d8_001844D8;
typedef struct { O_1844d8_001844D8 *o; } S_1844d8_001844D8;
// MATCH func_001844D8
int FUN_001844d8(S_1844d8_001844D8 *s) { O_1844d8_001844D8 *p = s->o; return p ? p->vt->fn((char *)p + p->vt->adj) : 0; }

typedef struct { int a0, a4, a8, a12, a16, a20, a24, a28, a32; } E_1f75c8_001F75C8;
typedef struct { char pad[32]; E_1f75c8_001F75C8 e0, e1; } S_1f75c8_001F75C8;
// MATCH func_001F75C8
void ikumin_001f75c8(S_1f75c8_001F75C8 *s, int a, int b) { E_1f75c8_001F75C8 *x = &s->e0; E_1f75c8_001F75C8 *y = &s->e1;
x->a0 = 0;
x->a12 = 0;
x->a4 = a;
x->a8 = a;
x->a16 = 0;
x->a20 = 0;
x->a28 = 0;
x->a32 = 1;
x->a0 = a;
y->a0 = 0;
y->a12 = 0;
y->a32 = 1;
x->a24 = 0;
y->a4 = b;
y->a8 = b;
y->a16 = 0;
y->a20 = 0;
y->a28 = 0;
y->a0 = b;
y->a24 = 0;
}

typedef struct { int a0, a4, a8, a12, a16, a20, a24, a28, a32; } E_1f7628_001F7628;
typedef struct { char pad[104]; E_1f7628_001F7628 e0, e1; } S_1f7628_001F7628;
// MATCH func_001F7628
void ikumin_001f7628(S_1f7628_001F7628 *s, int a, int b) { E_1f7628_001F7628 *x = &s->e0; E_1f7628_001F7628 *y = &s->e1;
x->a0 = 0;
x->a12 = 0;
x->a4 = a;
x->a8 = a;
x->a16 = 0;
x->a20 = 0;
x->a28 = 0;
x->a32 = 1;
x->a0 = a;
y->a0 = 0;
y->a12 = 0;
y->a32 = 1;
x->a24 = 0;
y->a4 = b;
y->a8 = b;
y->a16 = 0;
y->a20 = 0;
y->a28 = 0;
y->a0 = b;
y->a24 = 0;
}

typedef struct { int a0, a4, a8, a12, a16, a20, a24, a28, a32; } E_1f6d80_001F6D80;
typedef struct { char pad[176]; E_1f6d80_001F6D80 e0, e1; } S_1f6d80_001F6D80;
// MATCH func_001F6D80
void FUN_001f6d80(S_1f6d80_001F6D80 *s, int a, int b) { E_1f6d80_001F6D80 *x = &s->e0; E_1f6d80_001F6D80 *y = &s->e1;
x->a0 = 0;
x->a12 = 0;
x->a4 = a;
x->a8 = a;
x->a16 = 0;
x->a20 = 0;
x->a28 = 0;
x->a32 = 1;
x->a0 = a;
y->a0 = 0;
y->a12 = 0;
y->a32 = 1;
x->a24 = 0;
y->a4 = b;
y->a8 = b;
y->a16 = 0;
y->a20 = 0;
y->a28 = 0;
y->a0 = b;
y->a24 = 0;
}

typedef struct { int a0, a4, a8, a12, a16, a20, a24, a28, a32; } E_1f7220_001F7220;
typedef struct { char pad[104]; E_1f7220_001F7220 e[4]; } S_1f7220_001F7220;
// MATCH func_001F7220
void ikumin_001f7220(S_1f7220_001F7220 *s) { E_1f7220_001F7220 *e0 = &s->e[0], *e1 = &s->e[1], *e2 = &s->e[2], *e3 = &s->e[3];
*(int *)((char *)s + 20) = 0;
e0->a32 = 1;
e0->a12 = 0;
e0->a0 = e0->a4;
e1->a32 = 1;
e1->a12 = 0;
e1->a0 = e1->a4;
e2->a32 = 1;
e2->a12 = 0;
e2->a0 = e2->a4;
e3->a12 = 0;
e3->a32 = 1;
e3->a0 = e3->a4;
}

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

typedef struct { char pad[8]; int a8; char pad1[132]; int a144; char pad2[192]; int a340; char pad3[50]; char b394; char pad4[17]; int a412; } S_245e10_00245E10;
extern int D_004A7204;
void func_002461E0(void *);
// MATCH func_00245E10
S_245e10_00245E10 *FUN_00245e10(S_245e10_00245E10 *s) { int n = D_004A7204; s->a144 = 0; n++; s->a412 = 0; s->a8 = 0; s->a340 = 0; D_004A7204 = n; func_002461E0(s); s->b394 = 0; return s; }

typedef struct { char pad[372]; unsigned short a[1200]; unsigned char b[1200]; } T_250a68_00250A68;
extern unsigned short D_004A598E_00250A68 __asm__("D_004A598E"); extern T_250a68_00250A68 D_003FEBA8_00250A68 __asm__("D_003FEBA8");
int func_0024F380(unsigned);
// MATCH func_00250A68
int FUN_00250a68(unsigned i) { unsigned r; if (i < D_004A598E_00250A68) r = D_003FEBA8_00250A68.a[i]; else r = 0; return func_0024F380(r); }

typedef struct { char pad[4816]; unsigned a4816; char pad2[412]; long l5232; } S_21a938_0021A938;
// MATCH func_0021A938
int FUN_0021a938(S_21a938_0021A938 *s) { if ((s->a4816 & 0x20800) || (s->l5232 & 0x0010171c00000000L)) return 0; return 1; }

typedef struct { char pad[22]; short h; int a24[3]; int a36[3]; } S_29b978_0029B978;
// MATCH func_0029B978
void FUN_0029b978(S_29b978_0029B978 *s, int a, int b) { int i = s->h; int n = (unsigned short)s->h + 1; s->a36[i] = a; s->a24[i] = b; s->h = n; if ((short)n >= 3) s->h = 0; }

typedef struct { char pad[68]; int a68; } P_2d38a0_002D38A0;
extern char D_00631A80[];
void *func_002CFF38(void); int func_002E8B18(void *);
// MATCH func_002D38A0
int FUN_002d38a0(void) { int r = 0; if (((P_2d38a0_002D38A0 *)func_002CFF38())->a68 != 0) r = func_002E8B18(D_00631A80); return r; }

extern int D_0040D610[]; extern char D_0047CC50[];
int func_0025AE60(int);
// MATCH func_0025B1C0
void *FUN_0025b1c0(int a, int b) { if (func_0025AE60(a) >= 0) return (void *)D_0040D610[b - 1]; return D_0047CC50; }

extern int D_0040D8B8[]; extern char D_0047CC50_0025B210[] __asm__("D_0047CC50");
int func_0025AE60(int);
// MATCH func_0025B210
void *FUN_0025b210(int a, int b) { if (func_0025AE60(a) >= 0) return (void *)D_0040D8B8[b - 1]; return D_0047CC50_0025B210; }

typedef struct { char pad[8]; short adj; short p2; void (*fn)(void *, int); } VT_2a63e8_002A63E8;
typedef struct { char pad[56]; VT_2a63e8_002A63E8 *vt; } O_2a63e8_002A63E8;
typedef struct { O_2a63e8_002A63E8 *o; int a4; } S_2a63e8_002A63E8;
// MATCH func_002A63E8
void FUN_002a63e8(S_2a63e8_002A63E8 *s) { O_2a63e8_002A63E8 *p; s->a4 = 0; p = s->o; if (p != 0) { p->vt->fn((char *)p + p->vt->adj, 3); s->o = 0; } }

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

extern char D_0044BCF8[];
// MATCH func_001E23B8
void *akari_001e23b8(void *s) {
(*(int *)((char *)s + 100)) = (int)D_0044BCF8;
(*(float *)((char *)s + 72)) = 1.0f;
(*(unsigned char *)((char *)s + 78)) = 1;
(*(int *)((char *)s + 68)) = 0;
(*(unsigned char *)((char *)s + 76)) = 0;
(*(unsigned char *)((char *)s + 77)) = 0;
(*(unsigned char *)((char *)s + 79)) = 0;
(*(int *)((char *)s + 80)) = 0;
(*(int *)((char *)s + 84)) = 0;
(*(int *)((char *)s + 88)) = 0;
(*(unsigned char *)((char *)s + 0)) = 0;
return s; }

typedef struct { int a0, a4, a8; char *a12; } R_2e6b08_002E6B08;
// MATCH func_002E6B08
void FUN_002e6b08(R_2e6b08_002E6B08 *s) { char *p; s->a4 = s->a4 + 1; p = s->a12 + 1; s->a12 = p; if (p == (char *)s + (s->a0 + 16)) s->a12 = (char *)s + 16; }

typedef struct { int a0, a4; char *a8; } R_2e6b48_002E6B48;
// MATCH func_002E6B48
void FUN_002e6b48(R_2e6b48_002E6B48 *s) { char *p; s->a4 = s->a4 - 1; p = s->a8 + 1; s->a8 = p; if (p == (char *)s + (s->a0 + 16)) s->a8 = (char *)s + 16; }

typedef struct { short adj; short p; int pad[0]; } X_155840_00155840;
typedef struct { char pad[32]; short adj; short p2; void (*fn)(void *, float *); } VT_155840_00155840;
typedef struct { char pad[52]; VT_155840_00155840 *vt; } S_155840_00155840;
// MATCH func_00155840
void FUN_00155840(S_155840_00155840 *s, float a, float b, float c) { float v[4]; v[0] = a; v[1] = b; v[2] = c; v[3] = 1.0f; s->vt->fn((char *)s + s->vt->adj, v); }

typedef struct { char pad[8]; short adj; short p; void (*fn)(void *, int); } VT_164500_00164500;
typedef struct { char pad[104]; VT_164500_00164500 *vt; } O_164500_00164500;
typedef struct { O_164500_00164500 *o; void *vt; } S_164500_00164500;
extern char D_0043C7D8[];
void func_001645A0(void *); void func_00108B80_00164500(void *) __asm__("func_00108B80");
// MATCH func_00164500
void FUN_00164500(S_164500_00164500 *s, int fl) { O_164500_00164500 *p; s->vt = D_0043C7D8; func_001645A0(s); p = s->o; if (p != 0) p->vt->fn((char *)p + p->vt->adj, 3); if (fl & 1) func_00108B80_00164500(s); }

// MATCH func_00171FF8
void roulette_00171ff8(char *s, int *src) { int i; int *d = (int *)(s + 68); for (i = 0; i < 12; i++) { int v = src[i]; if (v < 1) v = 1; if (v > 23) v = 23; d[i] = v; } }

typedef struct { int a0, a4, a8, a12, a16, a20, a24, a28, a32; } E_1f6d18_001F6D18;
typedef struct { char pad[104]; E_1f6d18_001F6D18 e0, e1; } S_1f6d18_001F6D18;
// MATCH func_001F6D18
void FUN_001f6d18(S_1f6d18_001F6D18 *s, int a, int b) { E_1f6d18_001F6D18 *x = &s->e0; E_1f6d18_001F6D18 *y = &s->e1;
x->a0 = 0;
x->a4 = a;
x->a28 = 0;
x->a8 = a;
x->a16 = 0;
x->a20 = 0;
x->a32 = 1;
x->a12 = 0;
y->a0 = 0;
x->a0 = a;
y->a4 = b;
y->a8 = b;
y->a16 = 0;
y->a20 = 0;
y->a12 = 0;
y->a28 = 0;
y->a32 = 1;
y->a0 = b;
x->a24 = 0;
x->a28 = 0;
y->a24 = 0;
y->a28 = 0;
}

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

typedef struct { int a0, a4, a8, a12, a16; float f20, f24; int a28, a32, a36, a40, a44, a48, a52; unsigned char b56, b57, b58, b59; int a60, a64; float f68, f72; int a76; } S_201b08_00201B08;
extern char D_00454088[];
// MATCH func_00201B08
S_201b08_00201B08 *FUN_00201b08(S_201b08_00201B08 *s) {
s->a0 = 0;
s->a4 = 0;
s->a8 = 0;
s->a12 = 0;
s->a16 = 0;
s->a76 = (int)D_00454088;
s->f20 = 1.0f;
s->f24 = 1.0f;
s->a28 = 0;
s->a32 = 0;
s->a44 = 0;
s->a48 = 0;
s->a52 = 0;
s->b56 = 127;
s->b57 = 127;
s->b58 = 127;
s->a60 = 0;
s->a64 = 0;
s->b59 = 127;
s->f68 = 1.0f;
s->f72 = 1.0f;
return s; }

extern int D_004257DC[], D_00425510[];
// MATCH func_0029B670
void FUN_0029b670(int a, int b) { D_004257DC[0] = b; D_00425510[2] |= 8; }

typedef struct { int n; int a[1]; } S_204f30_00204F30;
void func_002044D8(int, int, int, int, int, int, void *); void func_00204A78(void);
// MATCH func_00204F30
void pchjob0_00204f30(S_204f30_00204F30 *s, int a, int b, int c, int d, int e) { if (s->n > 0) func_002044D8(s->a[s->n - 1], a, b, c, d, e, func_00204A78); }

void func_002ECE08(int, int, int, void *);
// MATCH func_002ED3D8
void FUN_002ed3d8(int a, int b, int c) { int x[4]; func_002ECE08(a, b, c, x); }

extern int D_0040D228[]; extern char D_0047CC50_0025B170[] __asm__("D_0047CC50");
int func_0025AE60(int);
// MATCH func_0025B170
void *FUN_0025b170(int a, int b) { if (func_0025AE60(a) >= 0) return (void *)D_0040D228[b - 1]; return D_0047CC50_0025B170; }

void func_00231F28(void *);
// MATCH func_00249618
void FUN_00249618(float x, float y, float z) { ((float *)0x70003e40)[0] = x; ((float *)0x70003e40)[1] = y; ((float *)0x70003e40)[2] = z; ((float *)0x70003e40)[3] = 1.0f; func_00231F28((void *)0x70003e40); }

typedef struct { char pad[372]; unsigned short a[1200]; unsigned char b[1200]; } T_256298_00256298;
extern unsigned short D_004A598E_00256298 __asm__("D_004A598E"); extern unsigned short D_00401028_00256298[] __asm__("D_00401028"); extern T_256298_00256298 D_003FEBA8_00256298 __asm__("D_003FEBA8");
int func_00256260(unsigned);
// MATCH func_00256298
int FUN_00256298(unsigned i) { if (i < D_004A598E_00256298) return func_00256260(D_003FEBA8_00256298.a[D_00401028_00256298[i]]); return 0; }

extern int D_004A14B8_00249650 __asm__("D_004A14B8");
void func_0018EC58(void *); void func_0018F620(void *, int); void func_0018F3D8(void *, void *, void *); void func_0018DF68_00249650(void *, void *) __asm__("func_0018DF68");
// MATCH func_00249650
void FUN_00249650(int p) { func_0018EC58((void *)0x70003f00); func_0018F620((void *)0x70003f00, p); func_0018F3D8((void *)0x70003f80, (void *)0x70003f80, (void *)0x70003f00); if (D_004A14B8_00249650 != 0) { func_0018DF68_00249650((void *)0x70003f40, (void *)0x70003f00); func_0018F3D8((void *)0x70003d80, (void *)0x70003f40, (void *)0x70003d80); return; } return; }

extern int D_004A7428[];
int func_002E5E68(int, int, int);
// MATCH func_002E0328
int FUN_002e0328(int *e, int p0, int p1, int p2) { int r; D_004A7428[0] = 0; r = func_002E5E68(p0, p1, p2); if (r == -1 && D_004A7428[0] != 0) *e = D_004A7428[0]; return r; }

extern int D_004A7428_002E4E90[] __asm__("D_004A7428");
int func_002E6058(int, int);
// MATCH func_002E4E90
int FUN_002e4e90(int *e, int p0, int p1) { int r; D_004A7428_002E4E90[0] = 0; r = func_002E6058(p0, p1); if (r == -1 && D_004A7428_002E4E90[0] != 0) *e = D_004A7428_002E4E90[0]; return r; }

extern int D_004A7428_002DCD58[] __asm__("D_004A7428");
int func_002E6078(int, int);
// MATCH func_002DCD58
int FUN_002dcd58(int *e, int p0, int p1) { int r; D_004A7428_002DCD58[0] = 0; r = func_002E6078(p0, p1); if (r == -1 && D_004A7428_002DCD58[0] != 0) *e = D_004A7428_002DCD58[0]; return r; }

extern int D_004A7428_002DC9A8[] __asm__("D_004A7428");
unsigned func_002E5FA0(int);
// MATCH func_002DC9A8
unsigned FUN_002dc9a8(int *e, int p0) { unsigned r; D_004A7428_002DC9A8[0] = 0; r = func_002E5FA0(p0); if (r == 0xffffffff && D_004A7428_002DC9A8[0] != 0) *e = D_004A7428_002DC9A8[0]; return r; }

void func_002E5640(void);
// MATCH func_002E6520
void FUN_002e6520(void) { func_002E5640(); __asm__ volatile("sync"); }

void func_002E5650(void);
// MATCH func_002E6540
void FUN_002e6540(void) { func_002E5650(); __asm__ volatile("sync"); }

void func_002E5660(void);
// MATCH func_002E6560
void FUN_002e6560(void) { func_002E5660(); __asm__ volatile("sync"); }

void func_002E5670(void);
// MATCH func_002E6580
void FUN_002e6580(void) { func_002E5670(); __asm__ volatile("sync"); }

void func_002ED418(int, int, int, void *, int);
// MATCH func_002ED640
void FUN_002ed640(int a, int b, int c) { int x[4]; func_002ED418(a, b, c, x, 0); }

int func_0015ECB0(void *); float func_0015EC50(void *);
// MATCH func_002A8738
void FUN_002a8738(char *s, int *q, float *r) { *q = func_0015ECB0(s + 432); *r = func_0015EC50(s + 432); }

void func_00131588_0015AB58(int) __asm__("func_00131588"); void func_00108B80_0015AB58(void *) __asm__("func_00108B80");
// MATCH func_0015AB58
void FUN_0015ab58(int *s, int fl) { if (*s != 0) func_00131588_0015AB58(*s); *s = 0; if (fl & 1) func_00108B80_0015AB58(s); }

typedef struct { char pad[10284]; int a; } S_22cff8_0022CFF8;
extern char D_0045BFC0[];
void func_001621F8(int, void *, int); void func_00108B80_0022CFF8(void *) __asm__("func_00108B80");
// MATCH func_0022CFF8
void th_tex_0022cff8(S_22cff8_0022CFF8 *s, int fl) { if (s->a != 0) func_001621F8(s->a, D_0045BFC0, 335); if (fl & 1) func_00108B80_0022CFF8(s); }

typedef struct { char pad[8]; int a8; } S_29c5c8_0029C5C8;
extern char D_0049A700[];
int func_00162130_0029C5C8(int, void *, int) __asm__("func_00162130"); int func_002A0E70(int);
// MATCH func_0029C5C8
void clas_min_0029c5c8(S_29c5c8_0029C5C8 *s) { if (s->a8 == 0) s->a8 = func_002A0E70(func_00162130_0029C5C8(84, D_0049A700, 633)); }

typedef struct { char pad[4]; int a4; char pad1[40]; void *a48; } S_164928_00164928;
extern char D_0043D2F0[];
void func_00131588_00164928(int) __asm__("func_00131588"); void func_00108B80_00164928(void *) __asm__("func_00108B80");
// MATCH func_00164928
void pachislot_00164928(S_164928_00164928 *s, int fl) { s->a48 = D_0043D2F0; if (s->a4 != 0) func_00131588_00164928(s->a4); if (fl & 1) func_00108B80_00164928(s); }

typedef struct { float x, y, z, w; } V_153c68_00153C68;
typedef struct { char pad[16]; V_153c68_00153C68 v; } S_153c68_00153C68;
void func_0018ED30(void *); void func_001544F0(void *);
static inline void set_153c68_00153C68(V_153c68_00153C68 *v, float x, float y, float z, float w) { v->x = x; v->y = y; v->z = z; v->w = w; }
// MATCH func_00153C68
void FUN_00153c68(S_153c68_00153C68 *s, float a, float b, float c) { set_153c68_00153C68(&s->v, a, b, c, 1.0f); func_0018ED30(&s->v); func_001544F0(s); }

typedef struct { char pad[104]; char sub[1]; char pad1[23]; int a128; } S_16f9f8_0016F9F8;
extern char D_0043D5B8[];
void func_002971C0(int, int); void func_001621F8(int, void *, int); void func_00164500(void *, int); void func_00108B80_0016F9F8(void *) __asm__("func_00108B80");
// MATCH func_0016F9F8
void roulette_0016f9f8(S_16f9f8_0016F9F8 *s, int fl) { func_002971C0(18, 50); func_001621F8(s->a128, D_0043D5B8, 479); func_00164500(s->sub, 2); if (fl & 1) func_00108B80_0016F9F8(s); }

typedef struct { char pad[52]; char sub[1]; char pad1[43]; int a96; } S_16ce98_0016CE98;
extern char D_0043D470[];
void func_002971C0(int, int); void func_001621F8(int, void *, int); void func_00164500(void *, int); void func_00108B80_0016CE98(void *) __asm__("func_00108B80");
// MATCH func_0016CE98
void darts_0016ce98(S_16ce98_0016CE98 *s, int fl) { func_002971C0(18, 50); func_001621F8(s->a96, D_0043D470, 234); func_00164500(s->sub, 2); if (fl & 1) func_00108B80_0016CE98(s); }

typedef struct { char pad[60]; char sub[1]; char pad1[7]; int a68; } S_00294B20;
extern char D_00499648[];
void func_002971C0(int, int); void func_001621F8(int, void *, int); void func_00164500(void *, int); void func_00295078(void *, int); void func_00108B80_00294B20(void *) __asm__("func_00108B80");
// MATCH func_00294B20
void battleslot_00294b20(S_00294B20 *s, int fl) { func_002971C0(18, 50); func_001621F8(s->a68, D_00499648, 270); func_00164500(s->sub, 2); func_00295078(s, 2); if (fl & 1) func_00108B80_00294B20(s); }

typedef struct { char pad[28]; char sub[1]; char pad1[7]; int a36; char pad2[20]; char *a60; } S_00171548;
extern char D_0043D6A0[], D_0043D5B8[];
void func_002971C0(int, int); void func_001621F8(int, void *, int); void func_00164500(void *, int); void func_00108B80_00171548(void *) __asm__("func_00108B80");
// MATCH func_00171548
void roulette_00171548(S_00171548 *s, int fl) { s->a60 = D_0043D6A0; func_002971C0(18, 50); func_001621F8(s->a36, D_0043D5B8, 1265); func_00164500(s->sub, 2); if (fl & 1) func_00108B80_00171548(s); }

typedef struct { char pad[4]; int a4; int a8; char *a12; } S_002168B8;
extern char D_00455A48[], D_00455A38[];
void func_002163C0(int, int); void func_001621F8(int, void *, int); void func_00108B80_002168B8(void *) __asm__("func_00108B80");
// MATCH func_002168B8
void pchspplate_002168b8(S_002168B8 *s, int fl) { s->a12 = D_00455A48; if (s->a8 != 0) func_002163C0(s->a8, 3); if (s->a4 != 0) func_001621F8(s->a4, D_00455A38, 204); if (fl & 1) func_00108B80_002168B8(s); }

typedef struct { char pad[16]; int a16; char pad1[56]; char *a76; } S_00201B78;
extern char D_00454088_00201B78[] __asm__("D_00454088"), D_00454010[];
void func_00133528(int, void *, int); void func_00108B80_00201B78(void *) __asm__("func_00108B80");
// MATCH func_00201B78
void sprite_00201b78(S_00201B78 *s, int fl) { s->a76 = D_00454088_00201B78; if (s->a16 != 0) func_00133528(s->a16, D_00454010, 47); s->a16 = 0; if (fl & 1) func_00108B80_00201B78(s); }

typedef struct { char pad[84]; int a84; int a88; char pad1[8]; char *a100; } S_001E2400;
extern char D_0044BCF8_001E2400[] __asm__("D_0044BCF8"), D_0044B740[];
void func_00133528(int, void *, int); void func_00108B80_001E2400(void *) __asm__("func_00108B80");
// MATCH func_001E2400
void akari_001e2400(S_001E2400 *s, int fl) { s->a100 = D_0044BCF8_001E2400; if (s->a88 != 0) func_00133528(s->a88, D_0044B740, 241); s->a84 = 0; s->a88 = 0; if (fl & 1) func_00108B80_001E2400(s); }

float func_0015EC48(void *); float func_0015EC40(void *);
// MATCH func_002A87C8
void FUN_002a87c8(char *s, float *q, float *r) { *q = func_0015EC48(s + 432); *r = func_0015EC40(s + 432); }

typedef struct { char pad[8]; int a8; char pad1[12]; int a24; } S_00189B28;
extern int D_004A6F64;
void func_002C1188(int); void func_00131588_00189B28(int) __asm__("func_00131588"); void func_00108B80_00189B28(void *) __asm__("func_00108B80");
// MATCH func_00189B28
void file_00189b28(S_00189B28 *s, int fl) { func_002C1188(D_004A6F64); if (s->a8 != 0) func_00131588_00189B28(s->a8); if (s->a24 != 0) func_00131588_00189B28(s->a24); if (fl & 1) func_00108B80_00189B28(s); }

typedef struct { int a0; char pad[356]; int a360; } S_001AD790;
extern char D_00444670[];
void func_00133528(int, void *, int); void func_00131588_001AD790(int) __asm__("func_00131588"); void func_00108B80_001AD790(void *) __asm__("func_00108B80");
// MATCH func_001AD790
void nayuwin2_001ad790(S_001AD790 *s, int fl) { if (s->a0 != 0) func_00133528(s->a0, D_00444670, 968); s->a0 = 0; if (s->a360 != 0) func_00131588_001AD790(s->a360); s->a360 = 0; if (fl & 1) func_00108B80_001AD790(s); }

typedef struct { char pad[20]; int a20; int a24; } S_0025E448;
extern char D_00343010[];
void func_001E3F20(void *, int); void func_00108B80_0025E448(void *) __asm__("func_00108B80");
// MATCH func_0025E448
void FUN_0025e448(S_0025E448 *s, int fl) { if (s->a20 != 0) func_001E3F20(D_00343010, s->a20); if (s->a24 != 0) func_001E3F20(D_00343010, s->a24); if (fl & 1) func_00108B80_0025E448(s); }

typedef struct { char pad[376]; char sub[1]; char pad1[7]; int a384; int a388; char pad2[504]; char *a896; } S_00174300;
extern char D_0043DF80[], D_0043D818[], D_00343010[];
void func_002971C0(int, int); void func_001621F8(int, void *, int); void func_001E3F20(void *, int); void func_00164500(void *, int); void func_00172A60(void *, int); void func_00108B80_00174300(void *) __asm__("func_00108B80");
// MATCH func_00174300
void repetition_00174300(S_00174300 *s, int fl) { s->a896 = D_0043DF80; func_002971C0(18, 50); func_001621F8(s->a384, D_0043D818, 1251); func_001E3F20(D_00343010, s->a388); func_00164500(s->sub, 2); func_00172A60(s, 2); if (fl & 1) func_00108B80_00174300(s); }

typedef struct { char pad[16]; int a16; int a20; char pad1[9]; char b33; } S_00202878;
extern int D_004A4490, D_004A44A0; extern char D_004541A0[];
void func_00133528(int, void *, int); void func_00108B80_00202878(void *) __asm__("func_00108B80");
// MATCH func_00202878
void eftpack_00202878(S_00202878 *s, int fl) { if (s->a16 != 0) { if (s->b33 == 0) { if (D_004A4490 != 0) func_00133528(D_004A4490, D_004541A0, 40); D_004A44A0 = 2; D_004A4490 = s->a16; } } if (s->a20 != 0) func_00133528(s->a20, D_004541A0, 45); s->a16 = 0; s->a20 = 0; if (fl & 1) func_00108B80_00202878(s); }

void func_002D7580(void *, void *); void *func_002D7620(void *, void *, void *); long func_002D7450(void *);
// MATCH func_002D7860
long __adddf3(long a, long b) { int x[8]; int y[8]; int r[8]; func_002D7580(&a, x); func_002D7580(&b, y); return func_002D7450(func_002D7620(x, y, r)); }

void func_002D7580(void *, void *); void *func_002D7620(void *, void *, void *); long func_002D7450(void *);
// MATCH func_002D78B8
long __subdf3(long a, long b) { int x[8]; int y[8]; int r[8]; func_002D7580(&a, x); func_002D7580(&b, y); y[1] ^= 1; return func_002D7450(func_002D7620(x, y, r)); }

void func_002D89B0(void *, void *); int func_002D9090(void *, void *);
// MATCH func_002D91A8
int FUN_002d91a8(float a, float b) { int x[4]; int y[4]; func_002D89B0(&a, x); func_002D89B0(&b, y); return func_002D9090(x, y); }

void func_002D89B0(void *, void *); void *func_002D8A40(void *, void *, void *); float func_002D88A0(void *);
// MATCH func_002D8C78
float FUN_002d8c78(float a, float b) { int x[4]; int y[4]; int r[4]; func_002D89B0(&a, x); func_002D89B0(&b, y); return func_002D88A0(func_002D8A40(x, y, r)); }

void func_002D89B0(void *, void *); void *func_002D8A40(void *, void *, void *); float func_002D88A0(void *);
// MATCH func_002D8CD0
float FUN_002d8cd0(float a, float b) { int x[4]; int y[4]; int r[4]; func_002D89B0(&a, x); func_002D89B0(&b, y); y[1] ^= 1; return func_002D88A0(func_002D8A40(x, y, r)); }

typedef struct { char pad[16]; int a16; int a20; char pad1[40]; int a64; } S_192300_00192300;
int func_002E58E0(int); int func_002E58C0(int);
// MATCH func_00192300
int FUN_00192300(S_192300_00192300 *s) { int x; func_002E58E0(s->a64); x = (s->a16 << 11) + s->a20; func_002E58C0(s->a64); return x; }

int func_001929A0(void *); int func_002C2C78(void *);
// MATCH func_00192AC8
int FUN_00192ac8(void *s) { int r = 0; if (func_001929A0(s) == 0) r = func_002C2C78(s) != 0; return r; }

extern char D_0042F2A0[];
int func_00162130_00113928(int, void *, int) __asm__("func_00162130"); void func_002DC804_00113928(int, int, int) __asm__("func_002DC804");
// MATCH func_00113928
int movieplay_00113928(int a) { int r = func_00162130_00113928(a, D_0042F2A0, 187); func_002DC804_00113928(r, 0, a); return r; }

extern char D_004A3658[];
void *func_002DD1DC(void *, int); void func_002DCE40(void *, void *, void *);
// MATCH func_0018BAE8
void FUN_0018bae8(char *a, char *b) { char *r = func_002DD1DC(b, 58); if (r == 0) r = b; else r++; func_002DCE40(a, D_004A3658, r); }

int func_002D3B98(void *, int); void func_002D39B0(int, int, int);
// MATCH func_002D3B28
int FUN_002d3b28(int a, int *b, int c) { int r = func_002D3B98(b, c); if (r != -1) func_002D39B0(a, c, b[1]); return r; }

int func_002E5790(void); void func_002E5620(int, void *, int); void func_002E57C0(void); void func_002CDA58(void);
// MATCH func_002CDA80
void FUN_002cda80(unsigned a) { func_002E5620(a & 0xffff, func_002CDA58, func_002E5790()); func_002E57C0(); }

extern int D_00314D08_002786A0[] __asm__("D_00314D08"); extern char D_00419D18[];
// MATCH func_002786A0
int FUN_002786a0(int a) { char *b = D_00419D18; int *p = D_00314D08_002786A0; char *q; int i = 0; q = b + 56; do { i++; if (*p == a) return *(int *)q; q += 176; p++; } while (i < 3); return 1; }

extern int D_00314D08_00278600[] __asm__("D_00314D08"); extern int D_004A66D0;
// MATCH func_00278600
int FUN_00278600(int a) { int i = 0; int *p = D_00314D08_00278600; do { if (*p == a) { if (D_004A66D0 == i) return 1; return 0; } i++; p++; } while (i < 3); return -1; }

void func_002D7580(void *, void *); long func_002D7450_002D8088(void *) __asm__("func_002D7450");
// MATCH func_002D8088
long FUN_002d8088(long a) { int x[8]; func_002D7580(&a, x); x[1] = x[1] == 0; return func_002D7450_002D8088(x); }

void func_002D89B0(void *, void *); float func_002D88A0_002D93D8(void *) __asm__("func_002D88A0");
// MATCH func_002D93D8
float FUN_002d93d8(float a) { int x[4]; func_002D89B0(&a, x); x[1] = x[1] == 0; return func_002D88A0_002D93D8(x); }

long func_002D7450_002D80C0(void *) __asm__("func_002D7450");
// MATCH func_002D80C0
long __make_dp(int cls, int sign, int exp, long frac) { struct { int c, s, e, p; long f; } x; x.c = cls; x.s = sign; x.e = exp; x.f = frac; return func_002D7450_002D80C0(&x); }

float func_002D88A0_002D9410(void *) __asm__("func_002D88A0");
// MATCH func_002D9410
float FUN_002d9410(int cls, int sign, int exp, int frac) { int x[4]; x[0] = cls; x[1] = sign; x[2] = exp; x[3] = frac; return func_002D88A0_002D9410(x); }

// MATCH func_002D94C8
unsigned char *FUN_002d94c8(unsigned char *p, int *val) { unsigned shift = 0; unsigned char byte; int result = 0; do { byte = *p++; result |= (int)(byte & 0x7f) << shift; shift += 7; } while (byte & 0x80); if (shift < 32 && (byte & 0x40) != 0) result |= -(1 << shift); *val = result; return p; }

void func_002D89B0(void *, void *); long func_002D80C0(int, int, int, long);
// MATCH func_002D9440
long __extendsfdf2(float a) { int x[4]; func_002D89B0(&a, x); return func_002D80C0(x[0], x[1], x[2], (unsigned long)(unsigned)x[3] << 30); }

// MATCH func_002D9480
unsigned char *FUN_002d9480(unsigned char *p, unsigned *val) { unsigned shift = 0; unsigned char byte; unsigned result; byte = *p++; result = byte & 0x7f; while (byte & 0x80) { byte = *p++; shift += 7; result |= (unsigned)(byte & 0x7f) << shift; } *val = result; return p; }

typedef struct { float f0; float f4, f8; float f12; float f16; float f20, f24, f28, f32, f36; float f40; } F_108b98_00108B98;
void func_00108C80(void *); void func_00108C20(void *);
// MATCH func_00108B98
void FUN_00108b98(F_108b98_00108B98 *s, float a, float b, float c, float d, float e) {
s->f0 = 0.0f;
s->f4 = a;
s->f8 = b;
s->f16 = d;
s->f40 = 1.0f;
s->f12 = 0.0f;
s->f24 = 0.0f;
s->f28 = 0.0f;
s->f32 = 0.0f;
s->f36 = 0.0f;
s->f20 = 0.0f;
if (s->f0 <= c) s->f12 = c;
if (s->f0 <= e) { s->f24 = e; s->f28 = e; }
func_00108C80(s); func_00108C20(s);
}

typedef struct { float f0; float f4, f8; float f12; float f16; float f20, f24, f28, f32, f36; float f40; } F_10f050_0010F050;
void func_00108C80(void *); void func_00108C20(void *);
// MATCH func_0010F050
void FUN_0010f050(F_10f050_0010F050 *s, float a, float b, float c, float d, float e) {
s->f0 = 0.0f;
s->f4 = a;
s->f8 = b;
s->f16 = d;
s->f40 = 1.0f;
s->f12 = 0.0f;
s->f24 = 0.0f;
s->f28 = 0.0f;
s->f32 = 0.0f;
s->f36 = 0.0f;
s->f20 = 0.0f;
if (s->f0 <= c) s->f12 = c;
if (s->f0 <= e) { s->f24 = e; s->f28 = e; }
func_00108C80(s); func_00108C20(s);
}

typedef struct { float f0; float f4, f8; float f12; float f16; float f20, f24, f28, f32, f36; float f40; } F_1b79b0_001B79B0;
void func_00108C80(void *); void func_00108C20(void *);
// MATCH func_001B79B0
void FUN_001b79b0(F_1b79b0_001B79B0 *s, float a, float b, float c, float d, float e) {
s->f0 = 0.0f;
s->f4 = a;
s->f8 = b;
s->f16 = d;
s->f40 = 1.0f;
s->f12 = 0.0f;
s->f24 = 0.0f;
s->f28 = 0.0f;
s->f32 = 0.0f;
s->f36 = 0.0f;
s->f20 = 0.0f;
if (s->f0 <= c) s->f12 = c;
if (s->f0 <= e) { s->f24 = e; s->f28 = e; }
func_00108C80(s); func_00108C20(s);
}

typedef struct { float f0; float f4, f8; float f12; float f16; float f20, f24, f28, f32, f36; float f40; } F_1c79e8_001C79E8;
void func_00108C80(void *); void func_00108C20(void *);
// MATCH func_001C79E8
void FUN_001c79e8(F_1c79e8_001C79E8 *s, float a, float b, float c, float d, float e) {
s->f0 = 0.0f;
s->f4 = a;
s->f8 = b;
s->f16 = d;
s->f40 = 1.0f;
s->f12 = 0.0f;
s->f24 = 0.0f;
s->f28 = 0.0f;
s->f32 = 0.0f;
s->f36 = 0.0f;
s->f20 = 0.0f;
if (s->f0 <= c) s->f12 = c;
if (s->f0 <= e) { s->f24 = e; s->f28 = e; }
func_00108C80(s); func_00108C20(s);
}

typedef struct { float f0; float f4, f8; float f12; float f16; float f20, f24, f28, f32, f36; float f40; } F_1f4e30_001F4E30;
void func_00108C80(void *); void func_00108C20(void *);
// MATCH func_001F4E30
void FUN_001f4e30(F_1f4e30_001F4E30 *s, float a, float b, float c, float d, float e) {
s->f0 = 0.0f;
s->f4 = a;
s->f8 = b;
s->f16 = d;
s->f40 = 1.0f;
s->f12 = 0.0f;
s->f24 = 0.0f;
s->f28 = 0.0f;
s->f32 = 0.0f;
s->f36 = 0.0f;
s->f20 = 0.0f;
if (s->f0 <= c) s->f12 = c;
if (s->f0 <= e) { s->f24 = e; s->f28 = e; }
func_00108C80(s); func_00108C20(s);
}

typedef struct { char pad[224]; char a[1]; char pad1[19]; char b[1]; char pad2[19]; char c[1]; } S_0015DF40;
void func_0029D010_0015DF40(void *, int, int, float) __asm__("func_0029D010");
// MATCH func_0015DF40
void FUN_0015df40(S_0015DF40 *s, float *v) { func_0029D010_0015DF40(s->a, 0, 0, v[0]); func_0029D010_0015DF40(s->b, 0, 0, v[1]); func_0029D010_0015DF40(s->c, 0, 0, v[2]); }

typedef struct { char pad[224]; char a[1]; char pad1[19]; char b[1]; char pad2[19]; char c[1]; } S_002184B0;
void func_0029D010_002184B0(void *, int, int, float) __asm__("func_0029D010");
// MATCH func_002184B0
void FUN_002184b0(S_002184B0 *s, float *v) { func_0029D010_002184B0(s->a, 0, 0, v[0]); func_0029D010_002184B0(s->b, 0, 0, v[1]); func_0029D010_002184B0(s->c, 0, 0, v[2]); }

typedef struct { char pad[224]; char a[1]; char pad1[19]; char b[1]; char pad2[19]; char c[1]; } S_0022BF30;
void func_0029D010_0022BF30(void *, int, int, float) __asm__("func_0029D010");
// MATCH func_0022BF30
void FUN_0022bf30(S_0022BF30 *s, float *v) { func_0029D010_0022BF30(s->a, 0, 0, v[0]); func_0029D010_0022BF30(s->b, 0, 0, v[1]); func_0029D010_0022BF30(s->c, 0, 0, v[2]); }

extern int D_0042992C[]; extern int D_00635640[]; extern char D_00635600[];
int func_002E8928(void *, int, int, int, int, void *, int, int, int);
// MATCH func_002EC9F0
unsigned FUN_002ec9f0(void) { int r; if (D_0042992C[0] < 0) return 0; r = func_002E8928(D_00635600, 5, 0, 0, 0, D_00635640, 4, 0, 0); if (r < 0) return 0xffffffff; return D_00635640[0]; }

extern int D_0042992C_002ECA60[] __asm__("D_0042992C"); extern int D_00635640_002ECA60[] __asm__("D_00635640"); extern char D_00635600_002ECA60[] __asm__("D_00635600");
int func_002E8928(void *, int, int, int, int, void *, int, int, int);
// MATCH func_002ECA60
unsigned FUN_002eca60(void) { int r; if (D_0042992C_002ECA60[0] < 0) return 0; r = func_002E8928(D_00635600_002ECA60, 6, 0, 0, 0, D_00635640_002ECA60, 4, 0, 0); if (r < 0) return 0xffffffff; return D_00635640_002ECA60[0]; }

extern int D_0042992C_002ECAD0[] __asm__("D_0042992C"); extern int D_00635640_002ECAD0[] __asm__("D_00635640"); extern char D_00635600_002ECAD0[] __asm__("D_00635600");
int func_002E8928(void *, int, int, int, int, void *, int, int, int);
// MATCH func_002ECAD0
unsigned FUN_002ecad0(void) { int r; if (D_0042992C_002ECAD0[0] < 0) return 0; r = func_002E8928(D_00635600_002ECAD0, 7, 0, 0, 0, D_00635640_002ECAD0, 4, 0, 0); if (r < 0) return 0xffffffff; return D_00635640_002ECAD0[0]; }

typedef struct { char pad[32]; float f32, f36, f40, f44; float g48, g52, g56, g60; } S_00153DE0;
void func_0018ED30(void *); void func_0018ED08(void *); void func_001544F0(void *);
// MATCH func_00153DE0
void FUN_00153de0(S_00153DE0 *s, float x) { s->f32 = x; func_0018ED30(&s->f32); *(u128 *)&s->g48 = *(u128 *)&s->f32; s->g52 = -s->f36; func_001544F0(s); }

typedef struct { char pad[32]; float f32, f36, f40, f44; float g48, g52, g56, g60; } S_00153E28;
void func_0018ED30(void *); void func_0018ED08(void *); void func_001544F0(void *);
// MATCH func_00153E28
void FUN_00153e28(S_00153E28 *s, float x) { s->f36 = x; func_0018ED30(&s->f32); *(u128 *)&s->g48 = *(u128 *)&s->f32; s->g52 = -s->f36; func_001544F0(s); }

typedef struct { char pad[32]; float f32, f36, f40, f44; float g48, g52, g56, g60; } S_00153E70;
void func_0018ED30(void *); void func_0018ED08(void *); void func_001544F0(void *);
// MATCH func_00153E70
void FUN_00153e70(S_00153E70 *s, float x) { s->f40 = x; func_0018ED30(&s->f32); *(u128 *)&s->g48 = *(u128 *)&s->f32; s->g52 = -s->f36; func_001544F0(s); }

typedef struct { char pad[32]; float f32, f36, f40, f44; float g48, g52, g56, g60; } S_00153D40;
void func_0018ED30(void *); void func_0018ED08(void *); void func_001544F0(void *);
// MATCH func_00153D40
void FUN_00153d40(S_00153D40 *s) { func_0018ED08(&s->f32); *(u128 *)&s->g48 = *(u128 *)&s->f32; s->g52 = -s->f36; func_001544F0(s); }

typedef struct { float x, y, z, w; } V4_00153D80;
typedef struct { char pad[32]; V4_00153D80 a; V4_00153D80 b; } S_00153D80;
void func_0018ED30(void *); void func_001544F0(void *);
static inline void set_153d80_00153D80(V4_00153D80 *v, float x, float y, float z, float w) { v->x = x; v->y = y; v->z = z; v->w = w; }
// MATCH func_00153D80
void FUN_00153d80(S_00153D80 *s, float x, float y, float z) { set_153d80_00153D80(&s->a, x, y, z, 1.0f); func_0018ED30(&s->a); *(u128 *)&s->b = *(u128 *)&s->a; s->b.y = -s->a.y; func_001544F0(s); }

// MATCH func_0018EBC0
u128 *FUN_0018ebc0(u128 *d, u128 *s, unsigned n) { while (n--) *d++ = *s++; return d; }

typedef struct { char pad[16]; float a[4]; float b[4]; float c[4]; } S_00153BE0;
void func_0018ED08_00153BE0(void *, void *) __asm__("func_0018ED08"); void func_001544F0(void *);
// MATCH func_00153BE0
void FUN_00153be0(S_00153BE0 *s, void *x, void *y) { func_0018ED08_00153BE0(s->a, x); func_0018ED08_00153BE0(s->b, y); *(u128 *)s->c = *(u128 *)s->b; s->c[1] = -s->b[1]; func_001544F0(s); }

void func_0018EE08(void *, void *, void *); void func_0018EC78(void *, void *, void *); void func_00153750(void *, void *);
// MATCH func_001544F0
void FUN_001544f0(char *s) { func_0018EE08(s + 64, s + 48, s + 16); *(u128 *)(s + 96) = *(u128 *)(s + 16); func_0018EC78(s + 80, s + 96, s + 64); func_00153750(s + 192, s + 64); }

extern int D_0062B5C0[]; extern char D_0062B380[];
int func_002E8928_002CA738(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CA738
int FUN_002ca738(void) { int r; D_0062B5C0[0] = 12; r = func_002E8928_002CA738(D_0062B380, 1, 0, D_0062B5C0, 128, D_0062B5C0, 128, 0, 0); if (r < 0) return 0; return D_0062B5C0[3]; }

extern int D_0062B5C0_002CA808[] __asm__("D_0062B5C0"); extern char D_0062B380_002CA808[] __asm__("D_0062B380");
int func_002E8928_002CA808(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CA808
int FUN_002ca808(void) { int r; D_0062B5C0_002CA808[0] = 18; r = func_002E8928_002CA808(D_0062B380_002CA808, 1, 0, D_0062B5C0_002CA808, 128, D_0062B5C0_002CA808, 128, 0, 0); if (r < 0) return 0; return D_0062B5C0_002CA808[3]; }

extern int D_0062B5C0_002CA7A0[] __asm__("D_0062B5C0"); extern char D_0062B380_002CA7A0[] __asm__("D_0062B380");
int func_002E8928_002CA7A0(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CA7A0
int FUN_002ca7a0(int x) { int r; D_0062B5C0_002CA7A0[1] = x; D_0062B5C0_002CA7A0[0] = 13; r = func_002E8928_002CA7A0(D_0062B380_002CA7A0, 1, 0, D_0062B5C0_002CA7A0, 128, D_0062B5C0_002CA7A0, 128, 0, 0); if (r < 0) return 0; return D_0062B5C0_002CA7A0[3]; }

extern int D_0062B5C0_002CA870[] __asm__("D_0062B5C0"); extern char D_0062B380_002CA870[] __asm__("D_0062B380");
int func_002E8928_002CA870(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CA870
int FUN_002ca870(int x) { int r; D_0062B5C0_002CA870[1] = x; D_0062B5C0_002CA870[0] = 20; r = func_002E8928_002CA870(D_0062B380_002CA870, 1, 0, D_0062B5C0_002CA870, 128, D_0062B5C0_002CA870, 128, 0, 0); if (r < 0) return 0; return D_0062B5C0_002CA870[2]; }

extern int D_0042992C_002EC868[] __asm__("D_0042992C"); extern int D_00635680[]; extern int D_00635640_002EC868[] __asm__("D_00635640"); extern char D_00635600_002EC868[] __asm__("D_00635600");
int func_002E8928_002EC868(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002EC868
int FUN_002ec868(int x) { int r; if (D_0042992C_002EC868[0] < 0) return 0; D_00635680[0] = x; r = func_002E8928_002EC868(D_00635600_002EC868, 2, 0, D_00635680, 4, D_00635640_002EC868, 4, 0, 0); if (r < 0) return -1; return D_00635640_002EC868[0]; }

extern int D_0042992C_002ECB40[] __asm__("D_0042992C"); extern int D_00635680_002ECB40[] __asm__("D_00635680"); extern int D_00635640_002ECB40[] __asm__("D_00635640"); extern char D_00635600_002ECB40[] __asm__("D_00635600");
int func_002E8928_002ECB40(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002ECB40
unsigned FUN_002ecb40(int x) { int r; if (D_0042992C_002ECB40[0] < 0) return 0; D_00635680_002ECB40[0] = x; r = func_002E8928_002ECB40(D_00635600_002ECB40, 8, 0, D_00635680_002ECB40, 4, D_00635640_002ECB40, 4, 0, 0); if (r < 0) return 0xffffffff; return D_00635640_002ECB40[0]; }

extern int D_0042992C_002ECBC0[] __asm__("D_0042992C"); extern int D_00635680_002ECBC0[] __asm__("D_00635680"); extern int D_00635640_002ECBC0[] __asm__("D_00635640"); extern char D_00635600_002ECBC0[] __asm__("D_00635600");
int func_002E8928_002ECBC0(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002ECBC0
unsigned FUN_002ecbc0(int x) { int r; if (D_0042992C_002ECBC0[0] < 0) return 0; D_00635680_002ECBC0[0] = x; r = func_002E8928_002ECBC0(D_00635600_002ECBC0, 9, 0, D_00635680_002ECBC0, 4, D_00635640_002ECBC0, 4, 0, 0); if (r < 0) return 0xffffffff; return D_00635640_002ECBC0[0]; }

extern int D_0042992C_002EC7E8[] __asm__("D_0042992C"); extern int D_00635680_002EC7E8[] __asm__("D_00635680"); extern int D_00635640_002EC7E8[] __asm__("D_00635640"); extern char D_00635600_002EC7E8[] __asm__("D_00635600");
int func_002E8928_002EC7E8(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002EC7E8
int FUN_002ec7e8(int x, int y, int z) { int r; if (D_0042992C_002EC7E8[0] < 0) return 0; D_00635680_002EC7E8[0] = y; D_00635680_002EC7E8[1] = x; D_00635680_002EC7E8[2] = z; r = func_002E8928_002EC7E8(D_00635600_002EC7E8, 4, 0, D_00635680_002EC7E8, 12, D_00635640_002EC7E8, 4, 0, 0); if (r < 0) return 0; return D_00635640_002EC7E8[0]; }

extern int D_0042992C_002EC778[] __asm__("D_0042992C"); extern int D_00635680_002EC778[] __asm__("D_00635680"); extern int D_00635640_002EC778[] __asm__("D_00635640"); extern char D_00635600_002EC778[] __asm__("D_00635600");
int func_002E8928_002EC778(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002EC778
int FUN_002ec778(int x) { int r; if (D_0042992C_002EC778[0] >= 0) { D_00635680_002EC778[0] = x; r = func_002E8928_002EC778(D_00635600_002EC778, 1, 0, D_00635680_002EC778, 4, D_00635640_002EC778, 4, 0, 0); if (r >= 0) return D_00635640_002EC778[0]; } return 0; }

extern int D_0062B5C0_002C9838[] __asm__("D_0062B5C0"); extern char D_0062B380_002C9838[] __asm__("D_0062B380"); extern int D_004262F8[];
int func_002E8928_002C9838(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002C9838
int FUN_002c9838(void) { int r; int v; D_0062B5C0_002C9838[0] = 15; r = func_002E8928_002C9838(D_0062B380_002C9838, 1, 0, D_0062B5C0_002C9838, 128, D_0062B5C0_002C9838, 128, 0, 0); if (r < 0) return 0; v = D_0062B5C0_002C9838[3]; if (v == 1) D_004262F8[0] = 0; return v; }

extern char D_00427D88[]; extern int D_00427540[]; extern int D_0042636C[];
int func_002CBC90(int); int func_002E8928(void *, int, int, int, int, void *, int, int, int); void func_002E58C0_002CC908(int) __asm__("func_002E58C0");
// MATCH func_002CC908
int FUN_002cc908(void) { int r; int v; if (func_002CBC90(1) == 0) return 0; r = func_002E8928(D_00427D88, 3, 0, 0, 0, D_00427540, 4, 0, 0); if (r < 0) { func_002E58C0_002CC908(D_0042636C[0]); return 0; } v = *(int *)((unsigned)D_00427540 | 0x20000000); func_002E58C0_002CC908(D_0042636C[0]); return v; }

extern char D_00427D88_002CC9A0[] __asm__("D_00427D88"); extern int D_00427540_002CC9A0[] __asm__("D_00427540"); extern int D_0042636C_002CC9A0[] __asm__("D_0042636C");
int func_002CBC90(int); int func_002E8928(void *, int, int, int, int, void *, int, int, int); void func_002E58C0_002CC9A0(int) __asm__("func_002E58C0");
// MATCH func_002CC9A0
int FUN_002cc9a0(void) { int r; int v; if (func_002CBC90(3) == 0) return -1; r = func_002E8928(D_00427D88_002CC9A0, 4, 0, 0, 0, D_00427540_002CC9A0, 4, 0, 0); if (r < 0) { func_002E58C0_002CC9A0(D_0042636C_002CC9A0[0]); return -1; } v = *(int *)((unsigned)D_00427540_002CC9A0 | 0x20000000); func_002E58C0_002CC9A0(D_0042636C_002CC9A0[0]); return v; }

extern char D_00427510[]; extern int D_004263C0[]; extern int D_00426368[];
int func_002CB978(int); int func_002E8928(void *, int, int, int, int, void *, int, int, int); void func_002E58C0_002CBAE8(int) __asm__("func_002E58C0");
// MATCH func_002CBAE8
int FUN_002cbae8(void) { int r; int v; if (func_002CB978(2) == 0) return 0; r = func_002E8928(D_00427510, 14, 0, 0, 0, D_004263C0, 4, 0, 0); if (r < 0) { func_002E58C0_002CBAE8(D_00426368[0]); return 0; } v = *(int *)((unsigned)D_004263C0 | 0x20000000); func_002E58C0_002CBAE8(D_00426368[0]); return v; }

extern int D_0062B5C0_002CA1A0[] __asm__("D_0062B5C0"); extern char D_0062B380_002CA1A0[] __asm__("D_0062B380");
int func_002E8928_002CA1A0(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002C9D38(int, int, int);
// MATCH func_002CA1A0
int FUN_002ca1a0(int a, int b, int c, int d) { int r; int v; D_0062B5C0_002CA1A0[3] = c; D_0062B5C0_002CA1A0[4] = d; D_0062B5C0_002CA1A0[0] = 6; D_0062B5C0_002CA1A0[1] = a; D_0062B5C0_002CA1A0[2] = b; r = func_002E8928_002CA1A0(D_0062B380_002CA1A0, 1, 0, D_0062B5C0_002CA1A0, 128, D_0062B5C0_002CA1A0, 128, 0, 0); if (r < 0) return 0; v = D_0062B5C0_002CA1A0[5]; if (v == 1) func_002C9D38(a, b, 2); return D_0062B5C0_002CA1A0[5]; }

extern int D_0062B5C0_002CA4A8[] __asm__("D_0062B5C0"); extern char D_0062B380_002CA4A8[] __asm__("D_0062B380");
int func_002E8928_002CA4A8(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002C9D38(int, int, int);
// MATCH func_002CA4A8
int FUN_002ca4a8(int a, int b, int c) { int r; int v; D_0062B5C0_002CA4A8[3] = c; D_0062B5C0_002CA4A8[0] = 10; D_0062B5C0_002CA4A8[1] = a; D_0062B5C0_002CA4A8[2] = b; r = func_002E8928_002CA4A8(D_0062B380_002CA4A8, 1, 0, D_0062B5C0_002CA4A8, 128, D_0062B5C0_002CA4A8, 128, 0, 0); if (r < 0) return 0; v = D_0062B5C0_002CA4A8[4]; if (v == 1) func_002C9D38(a, b, 2); return D_0062B5C0_002CA4A8[4]; }

extern char D_00427D88_002CCA38[] __asm__("D_00427D88"); extern int D_00427540_002CCA38[] __asm__("D_00427540"); extern int D_0042636C_002CCA38[] __asm__("D_0042636C"); extern int D_00426350[]; extern char D_0049E190[]; extern int D_00426394[];
int func_002CBC90(int); int func_002E8928(void *, int, int, int, int, void *, int, int, int); void func_002E58C0_002CCA38(int) __asm__("func_002E58C0"); void func_002E7940(void *);
// MATCH func_002CCA38
int FUN_002cca38(void) { int r; int v; if (func_002CBC90(2) == 0) return -1; r = func_002E8928(D_00427D88_002CCA38, 12, 0, 0, 0, D_00427540_002CCA38, 4, 0, 0); if (r < 0) { func_002E58C0_002CCA38(D_0042636C_002CCA38[0]); return -1; } v = *(int *)((unsigned)D_00427540_002CCA38 | 0x20000000); func_002E58C0_002CCA38(D_0042636C_002CCA38[0]); if (D_00426350[0] >= 2) func_002E7940(D_0049E190); return v; }

extern char D_0062B900[], D_0062B980[]; extern int D_0062CEC0[]; extern char D_0049E328[];
int func_002E8928_002CDD88(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002E7940(void *);
// MATCH func_002CDD88
int sceMcUdCheckNewCard(void) { if (func_002E8928_002CDD88(D_0062B900, 53, 0, D_0062B980, 48, D_0062CEC0, 4, 0, 0) != 0) { func_002E7940(D_0049E328); return -1; } return D_0062CEC0[0]; }

typedef struct { int v; int pad; char name[252]; } T_002ED2A8;
extern T_002ED2A8 D_006357C0; extern char D_006359C0[];
int func_002ECC40(void); int func_002ECD40(void); void *func_002DD928(void *, void *, int);
int func_002E8928_002ED2A8(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002ED2A8
int FUN_002ed2a8(char *name) { int r; if (func_002ECC40() < 0) return -65536; if (func_002ECD40() != 0) return -65540; func_002DD928(D_006357C0.name, name, 252); D_006357C0.name[251] = 0; r = func_002E8928_002ED2A8(D_006359C0, 9, 0, &D_006357C0, 512, &D_006357C0, 4, 0, 0); if (r < 0) return -65537; return D_006357C0.v; }

extern char D_006357C0_002ED7D0[] __asm__("D_006357C0"); extern char D_006359C0_002ED7D0[] __asm__("D_006359C0");
int func_002ECC40(void);
int func_002E8928_002ED7D0(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002ED7D0
int FUN_002ed7d0(int a, unsigned char *dst, unsigned size) { int r; if (func_002ECC40() < 0) return -65536; if (size >= 3) return -65538; *(int *)D_006357C0_002ED7D0 = a; *(int *)(D_006357C0_002ED7D0 + 4) = size; r = func_002E8928_002ED7D0(D_006359C0_002ED7D0, 3, 0, D_006357C0_002ED7D0, 32, D_006357C0_002ED7D0, 32, 0, 0); if (r < 0) return -65537; if (size == 0) *dst = *(unsigned char *)D_006357C0_002ED7D0; else if (size == 1) *(unsigned short *)dst = *(unsigned short *)D_006357C0_002ED7D0; else if (size == 2) *(int *)dst = *(int *)D_006357C0_002ED7D0; else return -65538; return 0; }

extern char D_006357C0_002ED8C0[] __asm__("D_006357C0"); extern char D_006359C0_002ED8C0[] __asm__("D_006359C0");
int func_002ECC40(void);
int func_002E8928_002ED8C0(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002ED8C0
int FUN_002ed8c0(int a, unsigned char *src, int size) { int r; if (func_002ECC40() < 0) return -65536; *(int *)D_006357C0_002ED8C0 = a; *(int *)(D_006357C0_002ED8C0 + 4) = size; if (size == 0) *(unsigned char *)(D_006357C0_002ED8C0 + 8) = *src; else if (size == 1) *(unsigned short *)(D_006357C0_002ED8C0 + 8) = *(unsigned short *)src; else if (size == 2) *(int *)(D_006357C0_002ED8C0 + 8) = *(int *)src; else return -65538; r = func_002E8928_002ED8C0(D_006359C0_002ED8C0, 2, 0, D_006357C0_002ED8C0, 32, D_006357C0_002ED8C0, 16, 0, 0); if (r < 0) return -65537; return 0; }

// MATCH func_002EDD40
int *FUN_002edd40(int *p, int *end, int v) { while (*p != v && p < end) p++; return p < end ? p : 0; }

extern int D_0042ABF8[]; void func_002E5550(int, void *); void func_002EE9C0(void);
// MATCH func_002EE478
int FUN_002ee478(int x) { D_0042ABF8[0] = x; func_002E5550(1, func_002EE9C0); func_002E5550(2, func_002EE9C0); func_002E5550(3, func_002EE9C0); return x; }

extern char D_0049F740[]; extern int D_0042AC40[];
void func_002EE0E8(void *, int, int); void func_002EE200_002EE2E8(void) __asm__("func_002EE200"); void func_002E5CC0(int, int);
// MATCH func_002EE2E8
void FUN_002ee2e8(int s, int c) { func_002EE0E8(D_0049F740, s, c); func_002EE200_002EE2E8(); func_002E5CC0(s, D_0042AC40[0] + 4); }

extern int D_0042AC00[];
void func_002E5550(int, void *); void func_002E5560(int, void *); void func_002EEC00(void);
// MATCH func_002EE4D8
unsigned FUN_002ee4d8(int n, int h) { int old; if ((unsigned)(n - 1) >= 13) return 0xffffffff; old = D_0042AC00[n]; D_0042AC00[n] = h; if ((unsigned)(n - 1) < 3) func_002E5550(n, func_002EEC00); else func_002E5560(n, func_002EEC00); return old; }

extern char D_006359E8[]; extern char D_00429874[]; extern char *D_00429934[];
int func_002F06D8(void *, void *, int);
// MATCH func_002ECD40
int FUN_002ecd40(void) { int r = 0; char *b = D_00429874; char *a = D_006359E8; if (func_002F06D8(a, b, 4) != 0) { if (func_002F06D8(a, D_00429934[0], 4) != 0) r = func_002F06D8(b, D_00429934[0], 4) != 0; } return r; }

extern int D_00427DCC[]; extern int D_00427DC8_002CD2B0[] __asm__("D_00427DC8"); extern int D_0062B900_002CD2B0[] __asm__("D_0062B900"); extern int D_0062B980_002CD2B0[] __asm__("D_0062B980"); extern int D_0062CEC0_002CD2B0[] __asm__("D_0062CEC0");
int func_002E58F0(int); void func_002E58C0_002CD2B0(int) __asm__("func_002E58C0"); int func_002E8928_002CD2B0(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CD2B0
int FUN_002cd2b0(int x) { int r; if (func_002E58F0(D_00427DCC[0]) < 0) return -200; if (D_0062B900_002CD2B0[9] == 0) { func_002E58C0_002CD2B0(D_00427DCC[0]); return -100; } D_0062B980_002CD2B0[5] = x; r = func_002E8928_002CD2B0(D_0062B900_002CD2B0, 20, 1, D_0062B980_002CD2B0, 48, D_0062CEC0_002CD2B0, 4, 0, 0); if (r == 0) D_00427DC8_002CD2B0[0] = 20; else func_002E58C0_002CD2B0(D_00427DCC[0]); return r; }

extern int D_00427DCC_002CD598[] __asm__("D_00427DCC"); extern int D_00427DC8_002CD598[] __asm__("D_00427DC8"); extern int D_0062B900_002CD598[] __asm__("D_0062B900"); extern int D_0062B980_002CD598[] __asm__("D_0062B980"); extern int D_0062CEC0_002CD598[] __asm__("D_0062CEC0");
int func_002E58F0(int); void func_002E58C0_002CD598(int) __asm__("func_002E58C0"); int func_002E8928_002CD598(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CD598
int FUN_002cd598(int x) { int r; if (func_002E58F0(D_00427DCC_002CD598[0]) < 0) return -200; if (D_0062B900_002CD598[9] == 0) { func_002E58C0_002CD598(D_00427DCC_002CD598[0]); return -100; } D_0062B980_002CD598[0] = x; r = func_002E8928_002CD598(D_0062B900_002CD598, 3, 1, D_0062B980_002CD598, 48, D_0062CEC0_002CD598, 4, 0, 0); if (r == 0) D_00427DC8_002CD598[0] = 3; else func_002E58C0_002CD598(D_00427DCC_002CD598[0]); return r; }

extern int D_00427DCC_002CE318[] __asm__("D_00427DCC"); extern int D_00427DC8_002CE318[] __asm__("D_00427DC8"); extern int D_0062B900_002CE318[] __asm__("D_0062B900"); extern int D_0062B980_002CE318[] __asm__("D_0062B980"); extern int D_0062CEC0_002CE318[] __asm__("D_0062CEC0");
int func_002E58F0(int); void func_002E58C0_002CE318(int) __asm__("func_002E58C0"); int func_002E8928_002CE318(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CE318
int FUN_002ce318(int x) { int r; if (func_002E58F0(D_00427DCC_002CE318[0]) < 0) return -200; if (D_0062B900_002CE318[9] == 0) { func_002E58C0_002CE318(D_00427DCC_002CE318[0]); return -100; } D_0062B980_002CE318[0] = x; r = func_002E8928_002CE318(D_0062B900_002CE318, 10, 1, D_0062B980_002CE318, 48, D_0062CEC0_002CE318, 4, 0, 0); if (r == 0) D_00427DC8_002CE318[0] = 10; else func_002E58C0_002CE318(D_00427DCC_002CE318[0]); return r; }

extern int D_00427DCC_002CD650[] __asm__("D_00427DCC"); extern int D_00427DC8_002CD650[] __asm__("D_00427DC8"); extern int D_0062B900_002CD650[] __asm__("D_0062B900"); extern int D_0062B980_002CD650[] __asm__("D_0062B980"); extern int D_0062CEC0_002CD650[] __asm__("D_0062CEC0");
int func_002E58F0(int); void func_002E58C0_002CD650(int) __asm__("func_002E58C0"); int func_002E8928_002CD650(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CD650
int FUN_002cd650(int a, int b, int c) { int r; if (func_002E58F0(D_00427DCC_002CD650[0]) < 0) return -200; if (D_0062B900_002CD650[9] == 0) { func_002E58C0_002CD650(D_00427DCC_002CD650[0]); return -100; } D_0062B980_002CD650[0] = a; D_0062B980_002CD650[4] = b; D_0062B980_002CD650[5] = c; r = func_002E8928_002CD650(D_0062B900_002CD650, 4, 1, D_0062B980_002CD650, 48, D_0062CEC0_002CD650, 4, 0, 0); if (r == 0) D_00427DC8_002CD650[0] = 4; else func_002E58C0_002CD650(D_00427DCC_002CD650[0]); return r; }

extern int D_00427DCC_002CE128[] __asm__("D_00427DCC"); extern int D_00427DC8_002CE128[] __asm__("D_00427DC8"); extern int D_0062B900_002CE128[] __asm__("D_0062B900"); extern int D_0062B980_002CE128[] __asm__("D_0062B980"); extern int D_0062CEC0_002CE128[] __asm__("D_0062CEC0");
int func_002E58F0(int); void func_002E58C0_002CE128(int) __asm__("func_002E58C0"); int func_002E8928_002CE128(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CE128
int FUN_002ce128(int a, int b) { int r; if (func_002E58F0(D_00427DCC_002CE128[0]) < 0) return -200; if (D_0062B900_002CE128[9] == 0) { func_002E58C0_002CE128(D_00427DCC_002CE128[0]); return -100; } D_0062B980_002CE128[2] = b; D_0062B980_002CE128[1] = a; r = func_002E8928_002CE128(D_0062B900_002CE128, 16, 1, D_0062B980_002CE128, 48, D_0062CEC0_002CE128, 4, 0, 0); if (r == 0) D_00427DC8_002CE128[0] = 16; else func_002E58C0_002CE128(D_00427DCC_002CE128[0]); return r; }

extern int D_00427DCC_002CE710[] __asm__("D_00427DCC"); extern int D_00427DC8_002CE710[] __asm__("D_00427DC8"); extern int D_0062B900_002CE710[] __asm__("D_0062B900"); extern int D_0062B980_002CE710[] __asm__("D_0062B980"); extern int D_0062CEC0_002CE710[] __asm__("D_0062CEC0");
int func_002E58F0(int); void func_002E58C0_002CE710(int) __asm__("func_002E58C0"); int func_002E8928_002CE710(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CE710
int FUN_002ce710(int a, int b) { int r; if (func_002E58F0(D_00427DCC_002CE710[0]) < 0) return -200; if (D_0062B900_002CE710[9] == 0) { func_002E58C0_002CE710(D_00427DCC_002CE710[0]); return -100; } D_0062B980_002CE710[2] = b; D_0062B980_002CE710[1] = a; r = func_002E8928_002CE710(D_0062B900_002CE710, 17, 1, D_0062B980_002CE710, 48, D_0062CEC0_002CE710, 4, 0, 0); if (r == 0) D_00427DC8_002CE710[0] = 17; else func_002E58C0_002CE710(D_00427DCC_002CE710[0]); return r; }

extern int D_00427DCC_002CD368[] __asm__("D_00427DCC"); extern int D_0062B900_002CD368[] __asm__("D_0062B900"); extern int D_0062B980_002CD368[] __asm__("D_0062B980"); extern int D_0062CEC0_002CD368[] __asm__("D_0062CEC0");
int func_002E58F0(int); void func_002E58C0_002CD368(int) __asm__("func_002E58C0"); int func_002E8928_002CD368(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CD368
int FUN_002cd368(int a) { int r; if (func_002E58F0(D_00427DCC_002CD368[0]) < 0) return -200; if (D_0062B900_002CD368[9] == 0) { func_002E58C0_002CD368(D_00427DCC_002CD368[0]); return -100; } D_0062B980_002CD368[1] = a; r = func_002E8928_002CD368(D_0062B900_002CD368, 21, 0, D_0062B980_002CD368, 48, D_0062CEC0_002CD368, 4, 0, 0); if (r != 0) { func_002E58C0_002CD368(D_00427DCC_002CD368[0]); return r; } func_002E58C0_002CD368(D_00427DCC_002CD368[0]); return D_0062CEC0_002CD368[0]; }

typedef struct { int a0, a4, a8, a12, a16; char name[1024]; } T_002CE7D8;
extern T_002CE7D8 D_0062B9B0_002CE7D8 __asm__("D_0062B9B0"); extern int D_00427DCC_002CE7D8[] __asm__("D_00427DCC"); extern int D_00427DC8_002CE7D8[] __asm__("D_00427DC8"); extern int D_0062B900_002CE7D8[] __asm__("D_0062B900"); extern int D_0062CEC0_002CE7D8[] __asm__("D_0062CEC0");
int func_002E58F0(int); void *func_002DD928(void *, void *, int);
int func_002E8928_002CE7D8(int *, int, int, void *, int, int *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CE7D8
int FUN_002ce7d8(int a, int b, char *name) { int r; if (func_002E58F0(D_00427DCC_002CE7D8[0]) < 0) return -200; if (D_0062B900_002CE7D8[9] == 0) { func_002E58C0(D_00427DCC_002CE7D8[0]); return -100; } if (name == 0 || *name == 0) { func_002E58C0(D_00427DCC_002CE7D8[0]); return -210; } D_0062B9B0_002CE7D8.a0 = a; D_0062B9B0_002CE7D8.a4 = b; func_002DD928(D_0062B9B0_002CE7D8.name, name, 1023); D_0062B9B0_002CE7D8.name[1023] = 0; r = func_002E8928_002CE7D8(D_0062B900_002CE7D8, 18, 1, &D_0062B9B0_002CE7D8, 1044, D_0062CEC0_002CE7D8, 4, 0, 0); if (r == 0) D_00427DC8_002CE7D8[0] = 18; else func_002E58C0(D_00427DCC_002CE7D8[0]); return r; }

typedef struct { int a0, a4, a8, a12, a16; char name[1024]; } T_002CE1F0;
extern T_002CE1F0 D_0062B9B0_002CE1F0 __asm__("D_0062B9B0"); extern int D_00427DCC_002CE1F0[] __asm__("D_00427DCC"); extern int D_00427DC8_002CE1F0[] __asm__("D_00427DC8"); extern int D_0062B900_002CE1F0[] __asm__("D_0062B900"); extern int D_0062CEC0_002CE1F0[] __asm__("D_0062CEC0");
int func_002E58F0(int); void *func_002DD928(void *, void *, int);
int func_002E8928_002CE1F0(int *, int, int, void *, int, int *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CE1F0
int FUN_002ce1f0(int a, int b, char *name) { int r; if (func_002E58F0(D_00427DCC_002CE1F0[0]) < 0) return -200; if (D_0062B900_002CE1F0[9] == 0) { func_002E58C0(D_00427DCC_002CE1F0[0]); return -100; } if (name == 0 || *name == 0) { func_002E58C0(D_00427DCC_002CE1F0[0]); return -210; } func_002DD928(D_0062B9B0_002CE1F0.name, name, 1023); D_0062B9B0_002CE1F0.a0 = a; D_0062B9B0_002CE1F0.a4 = b; D_0062B9B0_002CE1F0.name[1023] = 0; D_0062B9B0_002CE1F0.a8 = 0; r = func_002E8928_002CE1F0(D_0062B900_002CE1F0, 15, 1, &D_0062B9B0_002CE1F0, 1044, D_0062CEC0_002CE1F0, 4, 0, 0); if (r == 0) D_00427DC8_002CE1F0[0] = 15; else func_002E58C0(D_00427DCC_002CE1F0[0]); return r; }
typedef struct { int a0, a4, a8, a12, a16; char name[1024]; } T_002CDDF8;
extern T_002CDDF8 D_0062B9B0_002CDDF8 __asm__("D_0062B9B0"); extern int D_00427DCC_002CDDF8[] __asm__("D_00427DCC"); extern int D_00427DC8_002CDDF8[] __asm__("D_00427DC8"); extern int D_0062B900_002CDDF8[] __asm__("D_0062B900"); extern int D_0062CEC0_002CDDF8[] __asm__("D_0062CEC0"); extern char D_0062BD40[];
int func_002E58F0(int); void *func_002DD928(void *, void *, int); void func_002E8038(void *, int); void func_002CDF58(void);
int func_002E8928_002CDDF8(void *, int, int, void *, int, void *, int, void *, int) __asm__("func_002E8928");
// MATCH func_002CDDF8
int FUN_002cddf8(int a, int b, char *name, int c, int d, char *buf) { int r; if (func_002E58F0(D_00427DCC_002CDDF8[0]) < 0) return -200; if (D_0062B900_002CDDF8[9] == 0) { func_002E58C0(D_00427DCC_002CDDF8[0]); return -100; } if (name == 0 || *name == 0) { func_002E58C0(D_00427DCC_002CDDF8[0]); return -210; } D_0062B9B0_002CDDF8.a0 = a; D_0062B9B0_002CDDF8.a4 = b; D_0062B9B0_002CDDF8.a8 = c; D_0062B9B0_002CDDF8.a12 = d; D_0062B9B0_002CDDF8.a16 = (int)buf; func_002DD928(D_0062B9B0_002CDDF8.name, name, 1023); D_0062B9B0_002CDDF8.name[1023] = 0; if (d >= 0) func_002E8038(buf, d << 6); r = func_002E8928_002CDDF8(D_0062B900_002CDDF8, 13, 1, &D_0062B9B0_002CDDF8, 1044, D_0062CEC0_002CDDF8, 4, 0, 0); if (r == 0) D_00427DC8_002CDDF8[0] = 13; else func_002E58C0(D_00427DCC_002CDDF8[0]); return r; }

typedef struct { int a0, a4, a8, a12, a16; char name[1024]; } T_002CDFD8;
extern T_002CDFD8 D_0062B9B0_002CDFD8 __asm__("D_0062B9B0"); extern int D_00427DCC_002CDFD8[] __asm__("D_00427DCC"); extern int D_00427DC8_002CDFD8[] __asm__("D_00427DC8"); extern int D_0062B900_002CDFD8[] __asm__("D_0062B900"); extern int D_0062CEC0_002CDFD8[] __asm__("D_0062CEC0"); extern char D_0062BEC0[];
int func_002E58F0(int); int func_002E58C0_002CDFD8(int) __asm__("func_002E58C0"); void *func_002DD928(void *, void *, int); void func_002E8038(void *, int); void func_002CDF50(void);
int func_002E8928_002CDFD8(void *, int, int, void *, int, void *, int, void *, int) __asm__("func_002E8928");
// MATCH func_002CDFD8
int FUN_002cdfd8(int a, int b, char *name, int c) { int r; if (func_002E58F0(D_00427DCC_002CDFD8[0]) < 0) return -200; if (D_0062B900_002CDFD8[9] == 0) { func_002E58C0_002CDFD8(D_00427DCC_002CDFD8[0]); return -100; } if (name == 0 || *name == 0) { func_002E58C0_002CDFD8(D_00427DCC_002CDFD8[0]); return -210; } D_0062B9B0_002CDFD8.a0 = a; D_0062B9B0_002CDFD8.a16 = (int)D_0062BEC0; D_0062B9B0_002CDFD8.a4 = b; func_002DD928(D_0062B9B0_002CDFD8.name, name, 1023); D_0062B9B0_002CDFD8.name[1023] = 0; func_002E8038(D_0062BEC0, 1024); r = func_002E8928_002CDFD8(D_0062B900_002CDFD8, 12, 1, &D_0062B9B0_002CDFD8, 1044, D_0062CEC0_002CDFD8, 4, func_002CDF50, c); if (r == 0) D_00427DC8_002CDFD8[0] = 12; else func_002E58C0_002CDFD8(D_00427DCC_002CDFD8[0]); return r; }

typedef struct { int a0, a4, a8, a12, a16; char name[1024]; } T_002CD428;
extern T_002CD428 D_0062B9B0_002CD428 __asm__("D_0062B9B0"); extern int D_00427DCC_002CD428[] __asm__("D_00427DCC"); extern int D_00427DC8_002CD428[] __asm__("D_00427DC8"); extern int D_0062B900_002CD428[] __asm__("D_0062B900"); extern int D_0062CEC0_002CD428[] __asm__("D_0062CEC0");
int func_002E58F0(int); int func_002E58C0_002CD428(int) __asm__("func_002E58C0"); void *func_002DD928(void *, void *, int);
int func_002E8928_002CD428(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928");
// MATCH func_002CD428
int FUN_002cd428(int a, int b, char *name, int c) { int r; if (func_002E58F0(D_00427DCC_002CD428[0]) < 0) return -200; if (D_0062B900_002CD428[9] == 0) { func_002E58C0_002CD428(D_00427DCC_002CD428[0]); return -100; } if (name == 0 || *name == 0) { func_002E58C0_002CD428(D_00427DCC_002CD428[0]); return -210; } func_002DD928(D_0062B9B0_002CD428.name, name, 1023); D_0062B9B0_002CD428.a0 = a; D_0062B9B0_002CD428.a8 = c; D_0062B9B0_002CD428.a4 = b; D_0062B9B0_002CD428.name[1023] = 0; r = func_002E8928_002CD428(D_0062B900_002CD428, 2, 1, &D_0062B9B0_002CD428, 1044, D_0062CEC0_002CD428, 4, 0, 0); if (r == 0) D_00427DC8_002CD428[0] = 2; else func_002E58C0_002CD428(D_00427DCC_002CD428[0]); return r; }

extern char D_00635568[]; extern char D_00429874_002E9888[] __asm__("D_00429874"); extern char *D_00429928[];
int func_002F06D8(void *, void *, int);
// MATCH func_002E9888
int FUN_002e9888(void) { int r = 0; char *b = D_00429874_002E9888; char *a = D_00635568; if (func_002F06D8(a, b, 4) != 0) { if (func_002F06D8(a, D_00429928[0], 4) != 0) r = func_002F06D8(b, D_00429928[0], 4) != 0; } return r; }

extern int D_0042991C[];
int func_002E58A0(void *);
// MATCH func_002E9560
void FUN_002e9560(void) { int t[6]; if (D_0042991C[0] == -1) { t[5] = 0; t[2] = 1; t[1] = 1; D_0042991C[0] = func_002E58A0(t); } }

extern int D_00429920[]; extern int D_00429924[];
int func_002E58A0(void *);
// MATCH func_002E9048
void FUN_002e9048(void) { int t[6]; if (D_00429920[0] == -1) { t[5] = 0; t[2] = 1; t[1] = 1; D_00429920[0] = func_002E58A0(t); D_00429924[0] = func_002E58A0(t); } }

extern int D_00429950[]; extern int D_00429954[];
int func_002E58A0(void *);
// MATCH func_002EDCB0
void FUN_002edcb0(void) { int t[16];
t[1] = 1;
t[2] = 1;
t[9] = 1;
t[10] = 1;
D_00429950[0] = func_002E58A0(t); D_00429954[0] = func_002E58A0(t + 8); }

typedef struct { int a0, a4, a8, a12; } E_002E9130;
extern E_002E9130 D_00635340[]; extern int D_00429920_002E9130[] __asm__("D_00429920");
void func_002E9048(void); int func_002E58E0(int); int func_002E58C0(int);
// MATCH func_002E9130
E_002E9130 *FUN_002e9130(unsigned i) { E_002E9130 *r; func_002E9048(); func_002E58E0(D_00429920_002E9130[0]); if (i >= 32) { func_002E58C0(D_00429920_002E9130[0]); return 0; } r = &D_00635340[i]; func_002E58C0(D_00429920_002E9130[0]); return r; }

typedef struct { int a0, a4, a8, a12; } E_002E90A8;
extern E_002E90A8 D_00635340_002E90A8[] __asm__("D_00635340"); extern int D_00429920_002E90A8[] __asm__("D_00429920");
void func_002E9048(void); int func_002E58E0(int); int func_002E58C0(int);
// MATCH func_002E90A8
E_002E90A8 *FUN_002e90a8(void) { E_002E90A8 *p; func_002E9048(); func_002E58E0(D_00429920_002E90A8[0]); for (p = D_00635340_002E90A8; p < D_00635340_002E90A8 + 32; p++) { if (p->a4 == 0) { p->a4 = 0x10000000; func_002E58C0(D_00429920_002E90A8[0]); return p; } } func_002E58C0(D_00429920_002E90A8[0]); return 0; }

extern int D_006355C0[]; extern int D_00429918[];
void func_002E95B0(int); void func_002E96B8(void); int func_002EDC50(void); void func_002EDC98(void); void func_002E95E0(void);
// MATCH func_002E95F0
int FUN_002e95f0(int a, int b) { int old; int r; int *p = D_006355C0; func_002E95B0(27); if (D_00429918[0] == 0) func_002E96B8(); r = func_002EDC50(); old = D_006355C0[0]; p[1] = b; D_006355C0[0] = a; if (r != 0) func_002EDC98(); func_002E95E0(); return old; }

int func_002EDC50(void); int func_002EDC98_002E6380(void) __asm__("func_002EDC98"); int func_002E55F0(int);
// MATCH func_002E6380
int FUN_002e6380(int x) { int st; int r; __asm__ volatile("mfc0 %0, $12" : "=r"(st)); st &= 0x10000; if (st) func_002EDC50(); r = func_002E55F0(x); __asm__ volatile("sync"); if (st) func_002EDC98_002E6380(); return r; }

typedef char *va_list;
void func_002396B8(int, va_list);
// MATCH func_00239568
void FUN_00239568(int a, ...) { va_list ap; ap = (va_list)__builtin_next_arg(a) - 56; func_002396B8(a, ap); }

void func_002E7318(int, va_list);
// MATCH func_002E7908
void FUN_002e7908(int a, ...) { va_list ap; ap = (va_list)__builtin_next_arg(a) - 56; func_002E7318(a, ap); }

int func_002EDC50(void); int func_002EDC98_002E63E8(void) __asm__("func_002EDC98"); int func_002E55E0(int);
// MATCH func_002E63E8
int FUN_002e63e8(int x) { int st; int r; __asm__ volatile("mfc0 %0, $12" : "=r"(st)); st &= 0x10000; if (st) func_002EDC50(); r = func_002E55E0(x); __asm__ volatile("sync"); if (st) func_002EDC98_002E63E8(); return r; }

int func_002EDC50(void); int func_002EDC98_002E6450(void) __asm__("func_002EDC98"); int func_002E5610(int);
// MATCH func_002E6450
int FUN_002e6450(int x) { int st; int r; __asm__ volatile("mfc0 %0, $12" : "=r"(st)); st &= 0x10000; if (st) func_002EDC50(); r = func_002E5610(x); __asm__ volatile("sync"); if (st) func_002EDC98_002E6450(); return r; }

int func_002EDC50(void); int func_002EDC98_002E64B8(void) __asm__("func_002EDC98"); int func_002E5600(int);
// MATCH func_002E64B8
int FUN_002e64b8(int x) { int st; int r; __asm__ volatile("mfc0 %0, $12" : "=r"(st)); st &= 0x10000; if (st) func_002EDC50(); r = func_002E5600(x); __asm__ volatile("sync"); if (st) func_002EDC98_002E64B8(); return r; }

extern int D_004A13E8;
void func_002396B8(int, va_list);
// MATCH func_002393E0
void FUN_002393e0(int a, int b, ...) { va_list ap; D_004A13E8 = a; ap = (va_list)__builtin_next_arg(b) - 48; func_002396B8(b, ap); D_004A13E8 = 0; }

typedef struct { char pad[8]; int a8; } S_2dc8d8_002DC8D8;
void func_002DDF40(void *, int, int, va_list);
// MATCH func_002DC8D8
void FUN_002dc8d8(S_2dc8d8_002DC8D8 *s, int b, ...) { va_list ap; ap = (va_list)__builtin_next_arg(b) - 48; func_002DDF40(s, s->a8, b, ap); }

struct Q_2dc918_002DC918; typedef struct R_2dc918_002DC918 { char pad[8]; struct Q_2dc918_002DC918 *p; } R_2dc918_002DC918; typedef struct Q_2dc918_002DC918 { char pad[84]; R_2dc918_002DC918 *r; } Q_2dc918_002DC918;
extern R_2dc918_002DC918 *D_004293F4[];
void func_002DDEC8(void *, void *, va_list);
// MATCH func_002DC918
void printf(char *fmt, ...) { va_list ap; R_2dc918_002DC918 *r; ap = (va_list)__builtin_next_arg(fmt) - 56; r = D_004293F4[0]; r->p->r = r; func_002DDEC8(r->p, fmt, ap); }

extern int D_00429888[];
void func_002E7318_002E7940(char *, va_list) __asm__("func_002E7318"); void func_002E7038(void);
// MATCH func_002E7940
void FUN_002e7940(char *fmt, ...) { va_list ap; int old; ap = (va_list)__builtin_next_arg(fmt) - 56; old = D_00429888[0]; D_00429888[0] = (int)func_002E7038; func_002E7318_002E7940(fmt, ap); D_00429888[0] = old; }

int func_001114B0(void); int func_002E02F8(char *, va_list);
// MATCH func_001118F8
int DbgPrintf(char *fmt, ...) { va_list ap; if (func_001114B0() != 0) return 0; ap = (va_list)__builtin_next_arg(fmt) - 56; return func_002E02F8(fmt, ap); }

typedef struct { char *p; int r; int w; short flags; short file; char *base; int size; int lbfsize; char pad[56]; void *data; } FILE_t_002DCE40;
extern void *D_004293F4_002DCE40[] __asm__("D_004293F4");
int func_002DDEC8_002DCE40(void *, void *, va_list) __asm__("func_002DDEC8");
// MATCH func_002DCE40
int sprintf(char *s, char *fmt, ...) { FILE_t_002DCE40 f; va_list ap; int r; ap = (va_list)__builtin_next_arg(fmt) - 48; f.flags = 520; f.base = f.p = s; f.size = f.w = 0x7fffffff; f.data = D_004293F4_002DCE40[0]; r = func_002DDEC8_002DCE40(&f, fmt, ap); *f.p = 0; return r; }

typedef struct { char *p; int r; int w; short flags; short file; char *base; int size; int lbfsize; char pad[56]; void *data; } FILE_t_002DCDD8;
int func_002DDEC8_002DCDD8(void *, void *, va_list) __asm__("func_002DDEC8");
// MATCH func_002DCDD8
int FUN_002dcdd8(void *reent, char *s, char *fmt, ...) { FILE_t_002DCDD8 f; va_list ap; int r; ap = (va_list)__builtin_next_arg(fmt) - 40; f.flags = 520; f.base = f.p = s; f.size = f.w = 0x7fffffff; f.data = reent; r = func_002DDEC8_002DCDD8(&f, fmt, ap); *f.p = 0; return r; }

extern int D_004A1280_002394D0 __asm__("D_004A1280"), D_004A1288, D_004A1298, D_004A7138;
void func_00249818(int *, int); void func_002396B8(int, va_list);
// MATCH func_002394D0
void FUN_002394d0(int a, int b, ...) { int pt[2]; int o1 = D_004A1280_002394D0; int o2 = D_004A1288; va_list ap; func_00249818(pt, a); D_004A1280_002394D0 = ((pt[0] >> 4) - 1728) >> 1; D_004A1288 = (pt[1] >> 4) - 1936; ap = (va_list)__builtin_next_arg(b) - 48; func_002396B8(b, ap); D_004A1280_002394D0 = o1; D_004A1288 = o2; }

// MATCH func_002DDAE8
char *strstr(char *searchee, char *lookfor) { if (*searchee == 0) { if (*lookfor) return 0; return searchee; } while (*searchee) { int i = 0; while (1) { if (lookfor[i] == 0) return searchee; if (lookfor[i] != searchee[i]) break; i++; } searchee++; } return 0; }

extern unsigned char D_0049EA61[];
// MATCH func_002DD718
char *strlwr(char *s) { char *p = s; while (*p) { int c = *p; if (D_0049EA61[c] & 1) *p = c + 32; p++; } return s; }

typedef struct { char pad[468]; int *a468; } R_t_002DCA08;
void *func_002DBED8(void *, int);
// MATCH func_002DCA08
int FUN_002dca08(R_t_002DCA08 *r) { int i; if (r->a468 == 0) { r->a468 = func_002DBED8(r, 128); if (r->a468 == 0) return -1; for (i = 31; i >= 0; i--) r->a468[i] = 0; } return 0; }

typedef struct { int errno_; char pad[464]; int *a468; } R_t_002DCA78;
int func_002DCA08(void *);
// MATCH func_002DCA78
unsigned FUN_002dca78(R_t_002DCA78 *r, unsigned n, int fn) { unsigned old; if (n >= 32) { r->errno_ = 22; return 0xffffffff; } if (r->a468 == 0) { if (func_002DCA08(r) != 0) return 0xffffffff; } old = r->a468[n]; r->a468[n] = fn; return old; }

typedef struct R_t R_t; typedef struct { char pad[12]; unsigned short flags; short file; char pad2[64]; int a80; R_t *data; } F_t_002DD028;
long func_002E2478(R_t *, int, int, int);
// MATCH func_002DD028
long FUN_002dd028(F_t_002DD028 *fp, int a, int b) { long r = func_002E2478(fp->data, fp->file, a, b); if (r == -1) fp->flags &= 0xefff; else { fp->a80 = r; fp->flags |= 0x1000; } return r; }

typedef struct F_t_002DDE10 { char *p; int r; int w; unsigned short flags; short file; char *base; int size; int lbfsize; int a28; int pad1; int a36; char pad[44]; void *data; } F_t_002DDE10;
int func_002DDEC8_002DDE10(F_t_002DDE10 *, char *, char *) __asm__("func_002DDEC8"); int func_002E18F8(F_t_002DDE10 *);
// MATCH func_002DDE10
int FUN_002dde10(F_t_002DDE10 *fp, char *fmt, char *ap) { F_t_002DDE10 t; char buf[1024]; int r;
t.data = fp->data;
t.flags = fp->flags & 0xfffd;
t.file = fp->file;
t.a28 = fp->a28;
t.a36 = fp->a36;
t.base = t.p = buf;
t.size = t.w = 1024;
t.lbfsize = 0;
r = func_002DDEC8_002DDE10(&t, fmt, ap); if (r >= 0) { if (func_002E18F8(&t) != 0) r = -1; } if (t.flags & 0x40) fp->flags |= 0x40; return r; }

typedef struct { char c[8]; } V8_294d50_00294D50;
typedef struct { char pad[76]; V8_294d50_00294D50 v; } S_294d50_00294D50;
extern V8_294d50_00294D50 D_004A6790[2];
int func_00164A00(void *);
// MATCH func_00294D50
int battleslot_00294d50(S_294d50_00294D50 *s) { if (func_00164A00(s) != 0) s->v = D_004A6790[0]; return -1; }

typedef struct { char c[8]; } V8_294c68_00294C68;
typedef struct { char pad[76]; V8_294c68_00294C68 v; } S_294c68_00294C68;
extern V8_294c68_00294C68 D_004A6780[2];
int func_00164A20(void *);
// MATCH func_00294C68
int battleslot_00294c68(S_294c68_00294C68 *s) { if (func_00164A20(s) != 0) s->v = D_004A6780[0]; return -1; }

typedef struct { char c[8]; } V8_16e190_0016E190;
typedef struct { char pad[104]; V8_16e190_0016E190 v; } S_16e190_0016E190;
extern V8_16e190_0016E190 D_004A3030[2];
int func_0016CF10(void *);
// MATCH func_0016E190
int darts_0016e190(S_16e190_0016E190 *s) { func_0016CF10(s); s->v = D_004A3030[0]; return 1; }

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

typedef struct { char c[8]; } V8_174460_00174460;
typedef struct { char p[64]; short adj; short pad; int (*fn)(void *); } VT_174460_00174460;
typedef struct { char p[408]; V8_174460_00174460 d; V8_174460_00174460 s; char p2[472]; VT_174460_00174460 *vt; } O_174460_00174460;
// MATCH func_00174460
int repetition_00174460(O_174460_00174460 *o) { if (o->vt->fn((char *)o + o->vt->adj)) o->d = o->s; return 0; }

typedef struct { char c[8]; } V8_172e00_00172E00;
typedef struct { char p[316]; V8_172e00_00172E00 d; V8_172e00_00172E00 s; } O_172e00_00172E00;
int func_00172C18(void *, int);
// MATCH func_00172E00
int FUN_00172e00(O_172e00_00172E00 *o) { if (func_00172C18(o, 32)) o->d = o->s; return 0; }

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

typedef struct { char c[8]; } V8_169f70_00169F70;
typedef struct { char p[544]; V8_169f70_00169F70 d; V8_169f70_00169F70 s; } O_169f70_00169F70;
int func_00166638(void *);
// MATCH func_00169F70
int pachislot_00169f70(O_169f70_00169F70 *o) { if (func_00166638((char *)o + 284)) o->d = o->s; return 0; }

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

typedef struct { char c[8]; } V8_174558_00174558;
typedef struct { char p[72]; short adj; short pad; void (*fn)(void *); } VT_174558_00174558;
typedef struct { char p[368]; short w; char p2[38]; V8_174558_00174558 b; char p3[472]; V8_174558_00174558 a; VT_174558_00174558 *vt; } O_174558_00174558;
extern V8_174558_00174558 D_004A31A8[2], D_004A31B0[2];
// MATCH func_00174558
int repetition_00174558(O_174558_00174558 *o) { o->w = 0; o->vt->fn((char *)o + o->vt->adj); o->a = D_004A31A8[0]; o->b = D_004A31B0[0]; return 0; }

typedef struct { char c[8]; } V8_172e40_00172E40;
typedef struct { char p[56]; short adj; short pad; void (*fn)(void *, int); } VT_172e40_00172E40;
typedef struct { char p[124]; int w; char p2[188]; V8_172e40_00172E40 x; V8_172e40_00172E40 y; VT_172e40_00172E40 *vt; } O_172e40_00172E40;
extern V8_172e40_00172E40 D_004A3150[2], D_004A3148[2]; void func_00172BE8(void *, int);
// MATCH func_00172E40
void FUN_00172e40(O_172e40_00172E40 *o) { o->w = 0; o->vt->fn((char *)o + o->vt->adj, 4); func_00172BE8(o, 4); o->x = D_004A3150[0]; o->y = D_004A3148[0]; }

int func_002C7318(void *, int); void func_002C7728(void *);
// MATCH func_002C7B00
void FUN_002c7b00(char *s) { *(int *)(s + 232) = 0; *(int *)(s + 2132) = 1; *(int *)(s + 2124) = *(int *)(s + 2128) + 1; func_002C7318(s, 1); func_002C7318(s, 5); func_002C7318(s, 6); func_002C7318(s, 1); func_002C7318(s, 6); func_002C7318(s, 6); *(int *)(s + 420) = func_002C7318(s, 1); *(int *)(s + 424) = func_002C7318(s, 1); func_002C7728(s); }

extern char D_0042EEC8[]; extern int D_00342CE8[]; extern char D_00342D00[], D_00342E60[]; void func_00154B78(void *); void func_00153B40(void *);
// MATCH func_0018DE00
void FUN_0018de00(void) { D_00342CE8[0] = (int)D_0042EEC8; func_00154B78(D_00342D00); func_00153B40(D_00342E60); }

typedef struct { char c[16]; int x; } V20_2ced28_002CED28;
extern V20_2ced28_002CED28 D_0062CF00[2];
// MATCH func_002CED28
V20_2ced28_002CED28 *FUN_002ced28(V20_2ced28_002CED28 *d) { *d = D_0062CF00[0]; return d; }

void func_0018D810(int, int, int, int, int, int, int);
// MATCH func_0018D8B8
void FUN_0018d8b8(int a, int b, int c, int d, int e, int f) { int t = *(volatile int *)0x10000000; func_0018D810(a, t, b, c, d, e, f); }

extern int D_004A14EC; extern char D_0043C570[]; void func_001118F8(void *); void func_00162238(int);
// MATCH func_001621F8
void MemFreeDbg(int a) { if (D_004A14EC != 0) func_001118F8(D_0043C570); func_00162238(a); }

extern int D_004A69FC_002A20C0 __asm__("D_004A69FC"); extern char D_00424A98_002A20C0[] __asm__("D_00424A98"); void func_002DD4CC_002A20C0(void *) __asm__("func_002DD4CC"); void func_0023C728(void *, int); void func_002DD718(void *);
// MATCH func_002A20C0
void clas_min_002a20c0(int a, int b, int c) { D_004A69FC_002A20C0 |= 0x40; func_002DD4CC_002A20C0(D_00424A98_002A20C0); func_0023C728(D_00424A98_002A20C0, c); func_002DD718(D_00424A98_002A20C0); }

typedef struct { char p[12]; int w12; int w16; } S_201d08_00201D08;
extern char D_00454010_00201D08[] __asm__("D_00454010"); void func_00133528(int, void *, int); int func_0018B508(int, void *);
// MATCH func_00201D08
void sprite_00201d08(S_201d08_00201D08 *s, int a) { if (s->w16 != 0) func_00133528(s->w16, D_00454010_00201D08, 105); s->w16 = func_0018B508(a, &s->w12); }

extern char D_00454D80[]; extern int D_004A45E4_002105E8 __asm__("D_004A45E4"), D_004A46A8, D_004A46AC, D_004A6B14, D_004A4648, D_004A4660, D_004A4614, D_004A4664, D_004A4668, D_004A466C, D_004A4624, D_004A4628, D_004A4670_2105E8 __asm__("D_004A4670"), D_004A4674_2105E8 __asm__("D_004A4674"), D_004A4678; void *func_00162130(int, void *, int); int func_0020B508(void *, int);
// MATCH func_002105E8
void pchevent_002105e8(void) { D_004A45E4_002105E8 = func_0020B508(func_00162130(20, D_00454D80, 2687), 8); D_004A46A8 = 0; D_004A46AC = 0; D_004A6B14 = 0; D_004A4648 = 0; D_004A4660 = 0; D_004A4614 = 0; D_004A4664 = 0; D_004A4668 = 0; D_004A466C = 0; D_004A4624 = 0; D_004A4628 = 0; D_004A4670_2105E8 = 0; D_004A4674_2105E8 = 0; D_004A4678 = 0; }

typedef struct { char c[8]; } V8_00169278;
typedef struct { char pad[500]; int n; char pad2[40]; V8_00169278 a; } Q_00169278;
extern V8_00169278 D_004A2E50_00169278[2] __asm__("D_004A2E50");
// MATCH func_00169278
int pachislot_00169278(Q_00169278 *o) { o->n -= 8; if (o->n < 0) { o->n = 0; o->a = D_004A2E50_00169278[0]; } return 0; }

typedef struct { int a0, a4, a8, a12, a16, a20; } S_29b598_0029B598;
extern S_29b598_0029B598 D_00620058_0029B598 __asm__("D_00620058");
// MATCH func_0029B598
void FUN_0029b598(int a, int b) { S_29b598_0029B598 *p = &D_00620058_0029B598; D_00620058_0029B598.a0 = 1; p->a4 = b;p->a8 = 0;p->a20 = 0;p->a16 = 0;p->a12 = 0; }

void func_00127000(int, int, int, int, int, int, int, int, int);
// MATCH func_00126FA8
void battle_00126fa8(int a, int b, int c, int d, int e, int f) { func_00127000(0, a, b, c, d, e, f, 0, 0x808080); }

typedef struct { char p[104]; void *vt; int b; int c; } O_16f560_0016F560;
extern char D_0043D4C0[]; int func_00163D88(void *, int, int);
// MATCH func_0016F560
void *darts_0016f560(O_16f560_0016F560 *o, int b, int c, int d, int e) { func_00163D88(o, d, e); o->b = b; o->vt = D_0043D4C0; o->c = c; return o; }

typedef void __attribute__((noreturn)) (*F_2d8148)(void); extern F_2d8148 D_00427EF4_002D8148[] __asm__("D_00427EF4");
// MATCH func_002D8148
void FUN_002d8148(void) { D_00427EF4_002D8148[0](); }


void func_002E7000(int);
// MATCH func_002E70E8
void FUN_002e70e8(int c) { if (c == 10) { func_002E7000(13); func_002E7000(10); } else func_002E7000(c); }

extern char D_0045BE60[]; void *func_00162130(int, void *, int); int func_0022A198(void *);
// MATCH func_0022BDE0
int srenia_0022bde0(void) { return func_0022A198(func_00162130(0x92380, D_0045BE60, 1089)); }

int func_002DD36C_002DA4E0(int, int) __asm__("func_002DD36C");
// MATCH func_002DA4E0
int FUN_002da4e0(int *a, int *b) { int r = 0; if (b == a || func_002DD36C_002DA4E0(*a, *b) == 0) r = 1; return r; }

extern int D_00427DCC_002CD240[] __asm__("D_00427DCC"); int func_002E58B0(int);
// MATCH func_002CD240
int FUN_002cd240(void) { if (D_00427DCC_002CD240[0] >= 0) { func_002E58B0(D_00427DCC_002CD240[0]); D_00427DCC_002CD240[0] = -1; } return 1; }

extern int D_00632854[]; extern int D_0042988C[]; int func_002E6450(int); int func_002E55D0(int, int);
// MATCH func_002E7C98
void FUN_002e7c98(void) { func_002E6450(5); func_002E55D0(5, D_00632854[0]); D_0042988C[0] = 0; }

typedef struct { int w0; int p[7]; int w32; } Q_002CEED0;
void func_002CE8F0(void *);
// MATCH func_002CEED0
void FUN_002ceed0(Q_002CEED0 *o) { int v; func_002CE8F0(o); v = o->w0; o->w32 = 0; v &= ~0xc; v |= 4; v &= ~1; v |= 0x100; o->w0 = v; }

typedef struct { int w0; int p[7]; int w32; int p2[3]; unsigned w48; } Q_002CED78;
int func_002CE9E8(int); void func_002CE8F0_002CED78(Q_002CED78 *) __asm__("func_002CE8F0");
// MATCH func_002CED78
void FUN_002ced78(Q_002CED78 *o, int a) { int r = func_002CE9E8(a); func_002CE8F0_002CED78(o); if (o->w48 != 0xffffffff) o->w48 = r; o->w32 = 0; o->w0 = (o->w0 & ~0xc) | 0x105; }

void func_002D04C0(int, int, int, int);
// MATCH func_002D5220
int FUN_002d5220(unsigned long long a) { int r = -1; if ((a & 0xff000000) == 0) { func_002D04C0(66, (int)(a & 0xffffff), (int)((a >> 24) & 0xffffff), 0); r = 0; } return r; }

void func_002D04C0(int, int, int, int);
// MATCH func_002D5280
int FUN_002d5280(unsigned long long a) { int r = -1; if ((a & 0xff000000) == 0) { func_002D04C0(67, (int)(a & 0xffffff), (int)((a >> 24) & 0xffffff), 0); r = 0; } return r; }

void func_002D04C0(int, int, int, int);
// MATCH func_002D5380
int FUN_002d5380(int *a) { int r = -1; if ((unsigned)a[2] <= 0x1fffff && (unsigned)a[3] <= 0x1fffff && a[0] >= 0 && a[0] < 16) { func_002D04C0(72, (a[0] << 24) | a[1], a[2], a[3]); r = 0; } return r; }

void func_002D04C0(int, int, int, int);
// MATCH func_002D55B0
int FUN_002d55b0(unsigned a, unsigned long long b, int c) { int r = -1; if (a < 2 && (unsigned)c <= 0x1fffff && (b & 0xff000000) == 0) { func_002D04C0(79, (int)b, c, a); r = 0; } return r; }

void func_002D04C0(int, int, int, int);
// MATCH func_002D5518
void FUN_002d5518(unsigned long long a, int b, int c) { if ((unsigned)b > 32767) return; if (c < 0) return; if (c > 32767) return; if (a & 0xff000000) return; func_002D04C0(74, (int)a, b, c); }

void func_002D04C0(int, int, int, int);
// MATCH func_002D5120
int FUN_002d5120(unsigned long long a, unsigned b, int c) { int r = -1; if (b < 16384 && c >= 0 && c < 16384 && (a & 0xff000000) == 0) { func_002D04C0(64, (int)(a & 0xffffff), (int)((a >> 24) & 0xffffff), (b << 16) | c); r = 0; } return r; }

void func_002D04C0(int, int, int, int);
// MATCH func_002D51A8
int FUN_002d51a8(unsigned long long a, int b) { int r = -1; if ((a & 0xff000000) == 0 && b >= 0 && b <= 192000) { func_002D04C0(65, (int)(a & 0xffffff), (int)((a >> 24) & 0xffffff), b); r = 0; } return r; }

void func_002D04C0(int, int, int, int);
// MATCH func_002D1F48
int SndVoiceSetPitch(int x, int a1, int a2, int a3, int a4, int a5, int a6) { int hi = (a1 << 24) | a4; int lo = ((a3 & 0xff) << 8) | (a2 << 16); func_002D04C0(4, x, hi | lo, (a5 << 24) | a6); return 0; }

typedef struct { volatile unsigned w0; char p[60]; int w64; int w68; int w72; } Ch_002D4D98;
void *func_002CFF20_002D4D98(int) __asm__("func_002CFF20");
// MATCH func_002D4D98
void FUN_002d4d98(unsigned ch, int v) { if (ch < 48 && v >= 0 && v < 16384) { Ch_002D4D98 *p = func_002CFF20_002D4D98(ch); p->w0 |= 0x2000; p->w64 = v; p->w0 |= 0x400; p->w0 &= ~0x2000; } }

typedef struct { volatile unsigned w0; char p[60]; int w64; int w68; int w72; } Ch_002D4CF8;
void *func_002CFF20_002D4CF8(int) __asm__("func_002CFF20");
// MATCH func_002D4CF8
void FUN_002d4cf8(unsigned ch, int v, int w) { if (ch < 48 && v >= -4096 && v <= 4096 && w >= -4096 && w <= 4096) { Ch_002D4CF8 *p = func_002CFF20_002D4CF8(ch); p->w0 |= 0x2000; p->w68 = v; p->w72 = w; p->w0 |= 0x800; p->w0 &= ~0x2000; } }

typedef struct { volatile unsigned w0; char w4[80]; } Ch_002D3F58;
void *func_002CFF20_002D3F58(int) __asm__("func_002CFF20"); void func_002DC804(void *, int, int);
// MATCH func_002D3F58
int FUN_002d3f58(unsigned ch) { int r = -1; if (ch < 48) { Ch_002D3F58 *p = func_002CFF20_002D3F58(ch); p->w0 |= 0x2000; if ((p->w0 & 3) == 1) { func_002DC804(p->w4, 0, 80); r = 0; p->w0 = 0; } p->w0 &= ~0x2000; } return r; }

typedef struct { volatile unsigned w0; char p[44]; int w48; int w52; int w56; int w60; } Ch_002D41C0;
void *func_002CFF20_002D41C0(int) __asm__("func_002CFF20");
// MATCH func_002D41C0
int FUN_002d41c0(unsigned ch, int v, unsigned w) { int r = -1; if (ch < 48 && v >= 0 && v < 128) { Ch_002D41C0 *p = func_002CFF20_002D41C0(ch); p->w0 |= 0x2000; if (w == 0xffff) { r = p->w52; p->w48 = w; p->w52 = v; } else { p->w56 = w; r = 0; p->w60 = v; } p->w0 |= 0x200; p->w0 &= ~0x2000; } return r; }

typedef struct { volatile unsigned w0; } Ch_002D46E0;
void *func_002CFF20_002D46E0(int) __asm__("func_002CFF20");
// MATCH func_002D46E0
int FUN_002d46e0(unsigned ch) { int r = -1; if (ch < 48) { Ch_002D46E0 *p = func_002CFF20_002D46E0(ch); p->w0 |= 0x2000; if (p->w0 & 1) { r = ((int)p->w0 >> 1) & 1; if (p->w0 & 0x20) r |= 2; } p->w0 &= ~0x2000; } return r; }

typedef struct { int w0; int w4; char p[70]; unsigned short h78; } O_002D2320;
typedef struct { char p[8]; unsigned char *w8; char p2[4]; unsigned char *w16; } Pp_002D2320;
void *func_002CFFA0(void);
// MATCH func_002D2320
void FUN_002d2320(O_002D2320 *o) { if (o->w0 & 2) { Pp_002D2320 *p = func_002CFFA0(); *(p->w8 + (o->h78 << 4) + 18) = p->w16[1]; *(p->w8 + (o->h78 << 4) + 26) = 64; *(p->w8 + (o->h78 << 4) + 27) = 64; } o->w4 += 2; }

typedef struct { int w0; unsigned char *w4; } Pp_002D1EC0;
void *func_002CFFA0(void);
// MATCH func_002D1EC0
int FUN_002d1ec0(int a, int idx, int c) { Pp_002D1EC0 *p = func_002CFFA0(); unsigned char *q; if (a == 255) a = 1; else { int t; q = p->w4 + idx * 16; p->w4 = q; if (c < q[0]) a = 0; else { t = q[1] < c; a = t ^ 1; } p->w4 = q - idx * 16; } return a; }

typedef struct { int w0; int p[3]; unsigned w16; int p2[3]; int w32; } Q_002CEDE0;
int func_002CE9E8(int); void func_002CE8F0_002CEDE0(Q_002CEDE0 *) __asm__("func_002CE8F0");
// MATCH func_002CEDE0
void FUN_002cede0(Q_002CEDE0 *o, int a, int b) { int r = func_002CE9E8(a); func_002CE8F0_002CEDE0(o); if (o->w16 != 0xffffffff) o->w16 = r; o->w32 = b; o->w0 = (o->w0 & ~0xc) | 0x101; }

typedef struct { int w0; int p[3]; unsigned w16; int p2[3]; int w32; } Q_002CEE58;
int func_002CE9E8(int); void func_002CE8F0_002CEE58(Q_002CEE58 *) __asm__("func_002CE8F0");
// MATCH func_002CEE58
void FUN_002cee58(Q_002CEE58 *o, int a, int b) { int r = func_002CE9E8(a); func_002CE8F0_002CEE58(o); if (o->w16 != 0xffffffff) o->w16 = r; o->w32 = b; o->w0 = (o->w0 & ~0xc) | 0x109; }

typedef struct { int w0; int p[3]; unsigned w16; int p2[3]; int w32; } Q_002CEF98;
int func_002CE9E8(int); void func_002CE8F0_002CEF98(Q_002CEF98 *) __asm__("func_002CE8F0");
// MATCH func_002CEF98
void FUN_002cef98(Q_002CEF98 *o, int a, int b) { int r = func_002CE9E8(a); func_002CE8F0_002CEF98(o); if (o->w16 != 0xffffffff) o->w16 = r; o->w32 = b; o->w0 = (((o->w0 & ~0xc) | 8) & ~1) | 0x100; }

typedef struct { volatile unsigned w0; } Q_002CE8F0;
extern char D_0049E348[]; void func_002E7940_002CE8F0(char *) __asm__("func_002E7940"); void func_002CF088(Q_002CE8F0 *);
// MATCH func_002CE8F0
void FUN_002ce8f0(Q_002CE8F0 *o) { int n = 0x1000000; while (o->w0 & 0x100) { n--; if (n < 0) { func_002E7940_002CE8F0(D_0049E348); func_002CF088(o); } } }

typedef struct { int p[4]; volatile unsigned w16; } Q_002CE960;
extern char D_0049E348_002CE960[] __asm__("D_0049E348"); void func_002E7940_002CE960(char *) __asm__("func_002E7940"); void func_002CF088_002CE960(Q_002CE960 *) __asm__("func_002CF088");
// MATCH func_002CE960
void FUN_002ce960(Q_002CE960 *o, unsigned b, int c) { int n = c ? c : 0x1000000; while (o->w16 < b) { n--; if (n < 0) { func_002E7940_002CE960(D_0049E348_002CE960); func_002CF088_002CE960(o); } } }

typedef struct { int cls; int sign; int exp; unsigned long long ll; } FP_002D7F50;
static inline int isnan__002D7F50(FP_002D7F50 *x) { return x->cls == 0 || x->cls == 1; }
static inline int isinf__002D7F50(FP_002D7F50 *x) { return x->cls == 4; }
static inline int iszero__002D7F50(FP_002D7F50 *x) { return x->cls == 2; }
void func_002D7580(void *, void *);
// MATCH func_002D7F50
int __fixdfsi(double arg) { FP_002D7F50 a; unsigned long long tmp; func_002D7580(&arg, &a); if (iszero__002D7F50(&a)) return 0; if (isnan__002D7F50(&a)) return 0; if (isinf__002D7F50(&a)) return a.sign ? 0x80000000 : 0x7fffffff; if (a.exp < 0) return 0; if (a.exp > 30) return a.sign ? 0x80000000 : 0x7fffffff; tmp = a.ll >> (60 - a.exp); return a.sign ? -(int)tmp : (int)tmp; }

typedef struct { int cls; int sign; int exp; unsigned ll; } FP_002D92B0;
static inline int isnan__002D92B0(FP_002D92B0 *x) { return x->cls == 0 || x->cls == 1; }
static inline int isinf__002D92B0(FP_002D92B0 *x) { return x->cls == 4; }
static inline int iszero__002D92B0(FP_002D92B0 *x) { return x->cls == 2; }
void func_002D89B0(void *, void *);
// MATCH func_002D92B0
int FUN_002d92b0(float arg) { FP_002D92B0 a; unsigned tmp; func_002D89B0(&arg, &a); if (iszero__002D92B0(&a)) return 0; if (isnan__002D92B0(&a)) return 0; if (isinf__002D92B0(&a)) return a.sign ? 0x80000000 : 0x7fffffff; if (a.exp < 0) return 0; if (a.exp > 30) return a.sign ? 0x80000000 : 0x7fffffff; tmp = a.ll >> (30 - a.exp); return a.sign ? -(int)tmp : (int)tmp; }

typedef struct { int cls; int sign; int exp; unsigned ll; } FP_002D9340;
static inline int isnan__002D9340(FP_002D9340 *x) { return x->cls == 0 || x->cls == 1; }
static inline int isinf__002D9340(FP_002D9340 *x) { return x->cls == 4; }
static inline int iszero__002D9340(FP_002D9340 *x) { return x->cls == 2; }
void func_002D89B0(void *, void *);
// MATCH func_002D9340
unsigned FUN_002d9340(float arg) { FP_002D9340 a; unsigned tmp; func_002D89B0(&arg, &a); if (iszero__002D9340(&a)) return 0; if (isnan__002D9340(&a)) return 0; if (a.sign) return 0; if (isinf__002D9340(&a)) return 0xffffffff; if (a.exp < 0) return 0; if (a.exp > 31) return 0xffffffff; if (a.exp > 30) tmp = a.ll << (a.exp - 30); else tmp = a.ll >> (30 - a.exp); return tmp; }

typedef struct { char c[12]; } V12_002CA668;
extern int D_0062B5C0_002CA668[] __asm__("D_0062B5C0"); extern char D_0062B380_002CA668[] __asm__("D_0062B380"); int func_002E8928_002CA668(void *, int, int, void *, int, void *, int, int, int) __asm__("func_002E8928"); void func_002C9D38(int, int, int);
// MATCH func_002CA668
int FUN_002ca668(int a, int b, V12_002CA668 *c) { int r; int v; D_0062B5C0_002CA668[0] = 11; D_0062B5C0_002CA668[1] = a; D_0062B5C0_002CA668[2] = b; *(V12_002CA668 *)&D_0062B5C0_002CA668[3] = *c; r = func_002E8928_002CA668(D_0062B380_002CA668, 1, 0, D_0062B5C0_002CA668, 128, D_0062B5C0_002CA668, 128, 0, 0); if (r < 0) return 0; v = D_0062B5C0_002CA668[7]; if (v == 1) func_002C9D38(a, b, 2); return D_0062B5C0_002CA668[7]; }

void func_0012F2D8(); void func_0012F2E0(int, int, char *); void func_0012F2E8(int, int, char *); void func_0012F2F0(int, int, float);
// MATCH func_0012F270
void pchsysw_0012f270(int a, int b, char *c) { func_0012F2D8(); func_0012F2E0(a, b, c + 16); func_0012F2E8(a, b, c + 32); func_0012F2F0(a, b, *(float *)(c + 208)); }

extern int D_004A45E4_0020FE28 __asm__("D_004A45E4"), D_004A4960_0020FE28 __asm__("D_004A4960"); extern char D_00455318[]; int func_002DCE40_0020FE28(char *, char *, ...) __asm__("func_002DCE40"); int func_0020B858(int, char *);
// MATCH func_0020FE28
int pchevent_0020fe28(int f) { char buf[512]; if (f & 8) { func_002DCE40_0020FE28(buf, D_00455318); func_0020B858(D_004A45E4_0020FE28, buf); D_004A4960_0020FE28++; } return 0; }

extern int D_004A45E4_0020FCE8 __asm__("D_004A45E4"), D_004A4960_0020FCE8 __asm__("D_004A4960"), D_004A4690, D_004A4694; extern char D_004552D8[]; int func_002DCE40_0020FCE8(char *, char *, ...) __asm__("func_002DCE40"); int func_0020B858(int, char *);
// MATCH func_0020FCE8
int pchevent_0020fce8(int f) { char buf[512]; if (f & 8) { func_002DCE40_0020FCE8(buf, D_004552D8, D_004A4690, D_004A4694); func_0020B858(D_004A45E4_0020FCE8, buf); D_004A4960_0020FCE8++; } return 0; }

extern int D_004A45E4_0020FD38 __asm__("D_004A45E4"), D_004A4960_0020FD38 __asm__("D_004A4960"), D_004A4698, D_004A469C; extern char D_004552F0[]; int func_002DCE40_0020FD38(char *, char *, ...) __asm__("func_002DCE40"); int func_0020B858(int, char *);
// MATCH func_0020FD38
int pchevent_0020fd38(int f) { char buf[512]; if (f & 8) { func_002DCE40_0020FD38(buf, D_004552F0, D_004A4698, D_004A469C); func_0020B858(D_004A45E4_0020FD38, buf); D_004A4960_0020FD38++; } return 0; }

extern int D_004A45E4_0020FFD0 __asm__("D_004A45E4"), D_004A4960_0020FFD0 __asm__("D_004A4960"), D_004A46AC_0020FFD0 __asm__("D_004A46AC"); extern char D_00455358[]; int func_002DCE40_0020FFD0(char *, char *, ...) __asm__("func_002DCE40"); int func_0020B858(int, char *);
// MATCH func_0020FFD0
int pchevent_0020ffd0(int f) { char buf[512]; if (f & 8) { if (D_004A46AC_0020FFD0 != 0) { func_002DCE40_0020FFD0(buf, D_00455358); func_0020B858(D_004A45E4_0020FFD0, buf); D_004A4960_0020FFD0++; } } return 0; }

extern int D_004A45E4_0020FE70 __asm__("D_004A45E4"), D_004A4960_0020FE70 __asm__("D_004A4960"); int func_002DCE40_0020FE70(char *, char *, ...) __asm__("func_002DCE40"); int func_0020B858(int, char *);
extern int D_004A46AC_0020FE70 __asm__("D_004A46AC"), D_004A46BC, D_004A46C0; extern char D_00455328[]; int func_002129C8(int, int *, int *, int, int);
// MATCH func_0020FE70
int pchevent_0020fe70(int f) { char buf[512]; int x, y; if (f & 8) { if (D_004A46AC_0020FE70 != 0 && D_004A46BC >= 0 && D_004A46C0 >= 0) { if (func_002129C8(D_004A46AC_0020FE70, &x, &y, D_004A46BC, D_004A46C0) != 0) { func_002DCE40_0020FE70(buf, D_00455328, x); func_0020B858(D_004A45E4_0020FE70, buf); D_004A4960_0020FE70++; } } } return 0; }

extern int D_004A45E4_0020FEE8 __asm__("D_004A45E4"), D_004A4960_0020FEE8 __asm__("D_004A4960"); int func_002DCE40_0020FEE8(char *, char *, ...) __asm__("func_002DCE40"); int func_0020B858(int, char *);
extern int D_004A46AC_0020FEE8 __asm__("D_004A46AC"), D_004A46BC_0020FEE8 __asm__("D_004A46BC"), D_004A46C0_0020FEE8 __asm__("D_004A46C0"); extern char D_00455338[]; int func_002129C8(int, int *, int *, int, int);
// MATCH func_0020FEE8
int pchevent_0020fee8(int f) { char buf[512]; int x, y; if (f & 8) { if (D_004A46AC_0020FEE8 != 0 && D_004A46BC_0020FEE8 >= 0 && D_004A46C0_0020FEE8 >= 0) { if (func_002129C8(D_004A46AC_0020FEE8, &x, &y, D_004A46BC_0020FEE8, D_004A46C0_0020FEE8) != 0) { func_002DCE40_0020FEE8(buf, D_00455338, x); func_0020B858(D_004A45E4_0020FEE8, buf); D_004A4960_0020FEE8++; } } } return 0; }

extern int D_004A45E4_0020FF60 __asm__("D_004A45E4"), D_004A4960_0020FF60 __asm__("D_004A4960"); int func_002DCE40_0020FF60(char *, char *, ...) __asm__("func_002DCE40"); int func_0020B858(int, char *);
extern int D_004A46AC_0020FF60 __asm__("D_004A46AC"), D_004A46C4; extern char D_00455348[]; int func_00212A48(int, int *, int *, int);
// MATCH func_0020FF60
int pchevent_0020ff60(int f) { char buf[512]; int x, y; if (f & 8) { if (D_004A46AC_0020FF60 != 0 && D_004A46C4 >= 0) { if (func_00212A48(D_004A46AC_0020FF60, &x, &y, D_004A46C4) != 0) { func_002DCE40_0020FF60(buf, D_00455348, x); func_0020B858(D_004A45E4_0020FF60, buf); D_004A4960_0020FF60++; } } } return 0; }

extern int D_004A45E4_0020FC68 __asm__("D_004A45E4"), D_004A4960_0020FC68 __asm__("D_004A4960"); int func_002DCE40_0020FC68(char *, char *, ...) __asm__("func_002DCE40"); int func_0020B858(int, char *);
extern int D_004A4614_0020FC68 __asm__("D_004A4614"), D_004A4618, D_004A4658; extern char D_004552C8[], D_004A48D8[], D_004A4790[]; char *func_00160C70(int, char *, int);
// MATCH func_0020FC68
int pchevent_0020fc68(int f) { char buf[512]; char *s; if (f & 8) { if (D_004A4614_0020FC68 > 0 && D_004A4618 >= 0) s = func_00160C70(D_004A4658, D_004A48D8, D_004A4618); else s = D_004A4790; func_002DCE40_0020FC68(buf, D_004552C8, s); func_0020B858(D_004A45E4_0020FC68, buf); D_004A4960_0020FC68++; } return 0; }

extern int D_004A45E4_0020F370 __asm__("D_004A45E4"), D_004A4960_0020F370 __asm__("D_004A4960"); int func_002DCE40_0020F370(char *, char *, ...) __asm__("func_002DCE40"); int func_0020B858(int, char *);
extern int D_004A45E8; extern int *D_004A6F78, *D_004A4668_0020F370 __asm__("D_004A4668"); extern char D_00455188[];
typedef struct { char p[500]; int w500; } Q_0020F370;
Q_0020F370 *func_0020BBD8(int);
// MATCH func_0020F370
int pchevent_0020f370(int f) { char buf[512]; if (f & 8) { if (D_004A45E8 >= 0) { Q_0020F370 *p = func_0020BBD8(D_004A45E8); if (p != 0) { func_002DCE40_0020F370(buf, D_00455188, D_004A6F78[D_004A45E8], D_004A4668_0020F370[p->w500 + 1]); func_0020B858(D_004A45E4_0020F370, buf); D_004A4960_0020F370++; } } } return 0; }

extern int D_004A45E4_0020F588 __asm__("D_004A45E4"), D_004A4960_0020F588 __asm__("D_004A4960"); int func_002DCE40_0020F588(char *, char *, ...) __asm__("func_002DCE40"); int func_0020B858(int, char *);
extern int D_004A45E8_0020F588 __asm__("D_004A45E8"); extern int *D_004A6F78_0020F588 __asm__("D_004A6F78"); extern float D_004A0450; extern char D_004551B8[];
typedef struct { char p[68]; float f68; } R_0020F588;
typedef struct { R_0020F588 *w0; } Q_0020F588;
Q_0020F588 *func_0020BBD8_0020F588(int) __asm__("func_0020BBD8");
// MATCH func_0020F588
int pchevent_0020f588(int f) { char buf[512]; Q_0020F588 *p; if (f & 8) { if (D_004A45E8_0020F588 >= 0) { p = func_0020BBD8_0020F588(D_004A45E8_0020F588); if (p != 0) { func_002DCE40_0020F588(buf, D_004551B8, D_004A6F78_0020F588[D_004A45E8_0020F588], (double)(p->w0->f68 * 180.0f / D_004A0450)); func_0020B858(D_004A45E4_0020F588, buf); D_004A4960_0020F588++; } } } return 0; }

typedef struct { char p[8]; int w8; } M_0020C3C0;
extern M_0020C3C0 *D_004A45E4_0020C3C0 __asm__("D_004A45E4"); extern int D_004A1444_0020C3C0 __asm__("D_004A1444"), D_004A140C_0020C3C0 __asm__("D_004A140C"); int func_0020B660(M_0020C3C0 *);
// MATCH func_0020C3C0
int pchevent_0020c3c0(int on) { if (on) { if (D_004A1444_0020C3C0 == 0) { if (D_004A140C_0020C3C0 & 8) { if (D_004A45E4_0020C3C0 != 0) { if (D_004A45E4_0020C3C0->w8 > 0) func_0020B660(D_004A45E4_0020C3C0); } } } } return 0; }

typedef struct { char p[8]; int w8; } M_0020C330;
extern M_0020C330 *D_004A45E4_0020C330 __asm__("D_004A45E4"); extern int D_004A1444_0020C330 __asm__("D_004A1444"), D_004A140C_0020C330 __asm__("D_004A140C"), D_004A1430, D_004A1434, D_004A4604; extern char D_00454FF8[], D_00455008[]; int func_00239568(char *, int, int, int); int func_0020BA70(M_0020C330 *, char *);
// MATCH func_0020C330
int pchevent_0020c330(int on) { if (D_004A45E4_0020C330 != 0) func_00239568(D_00454FF8, D_004A1430 + 16, D_004A1434 + 6, D_004A45E4_0020C330->w8); if (on) { if (D_004A1444_0020C330 == 0 && (D_004A140C_0020C330 & 8) && D_004A45E4_0020C330 != 0 && D_004A45E4_0020C330->w8 > 0) { func_0020BA70(D_004A45E4_0020C330, D_00455008); D_004A4604 = 0; } } return 0; }

extern int D_004A4624_0020C5C8 __asm__("D_004A4624"), D_004A1444_0020C5C8 __asm__("D_004A1444"), D_004A140C_0020C5C8 __asm__("D_004A140C"); extern char D_0041EFB0_0020C5C8[] __asm__("D_0041EFB0"); int func_0012EE30(int, char *, float, float);
// MATCH func_0020C5C8
int pchevent_0020c5c8(int on) { if (on && D_004A1444_0020C5C8 == 0 && (D_004A140C_0020C5C8 & 8) && D_004A4624_0020C5C8 != 0) func_0012EE30(D_004A4624_0020C5C8, D_0041EFB0_0020C5C8, 120.0f, 1.0f); return 0; }

typedef struct { char p[24]; unsigned w24; } R_0020C2A8;
typedef struct { R_0020C2A8 *w0; } Q_0020C2A8;
extern int D_004A1444_0020C2A8 __asm__("D_004A1444"), D_004A140C_0020C2A8 __asm__("D_004A140C"), D_004A45E8_0020C2A8 __asm__("D_004A45E8"), D_004A45F4; Q_0020C2A8 *func_0020BBD8_0020C2A8(int) __asm__("func_0020BBD8");
// MATCH func_0020C2A8
int pchevent_0020c2a8(int on) { Q_0020C2A8 *p; R_0020C2A8 *q; if (on) { if (D_004A1444_0020C2A8 == 0 && (D_004A140C_0020C2A8 & 8)) { if (D_004A45E8_0020C2A8 >= 0) { p = func_0020BBD8_0020C2A8(D_004A45E8_0020C2A8); if (p != 0) { q = p->w0; if (q != 0) { if (D_004A45F4 != 0) q->w24 |= 0x10000000; else q->w24 &= ~0x10000000; } } } } } return 0; }

typedef struct { char p[209]; char b209; } R_0020C180;
typedef struct { R_0020C180 *w0; } Q_0020C180;
extern int D_004A45E8_0020C180 __asm__("D_004A45E8"); extern float D_004A4600; Q_0020C180 *func_0020BBD8_0020C180(int) __asm__("func_0020BBD8");
// MATCH func_0020C180
int pchevent_0020c180(void) { if (D_004A45E8_0020C180 >= 0) { Q_0020C180 *p = func_0020BBD8_0020C180(D_004A45E8_0020C180); if (p != 0) { R_0020C180 *q = p->w0; if (q != 0) q->b209 = (int)(D_004A4600 * 128.0f); } } return 0; }

typedef struct { char p[64]; float f64, f68, f72; } R_0020C048;
typedef struct { R_0020C048 *w0; } Q_0020C048;
extern int D_004A45E8_0020C048 __asm__("D_004A45E8"); extern float D_004A0410; extern float D_003C0F10[]; Q_0020C048 *func_0020BBD8_0020C048(int) __asm__("func_0020BBD8");
// MATCH func_0020C048
int pchevent_0020c048(void) { if (D_004A45E8_0020C048 >= 0) { Q_0020C048 *p = func_0020BBD8_0020C048(D_004A45E8_0020C048); if (p != 0) { R_0020C048 *q = p->w0; q->f64 = D_003C0F10[0] * D_004A0410 / 180.0f; q->f68 = D_003C0F10[1] * D_004A0410 / 180.0f; q->f72 = D_003C0F10[2] * D_004A0410 / 180.0f; } } return 0; }

typedef struct { char p[12]; float f12; } R_0020C0D8;
typedef struct { char p[464]; R_0020C0D8 *w464; } Q_0020C0D8;
extern int D_004A45E8_0020C0D8 __asm__("D_004A45E8"); extern float D_004A45F8, D_004A0414; Q_0020C0D8 *func_0020BBD8_0020C0D8(int) __asm__("func_0020BBD8");
// MATCH func_0020C0D8
int pchevent_0020c0d8(void) { if (D_004A45E8_0020C0D8 >= 0) { Q_0020C0D8 *p = func_0020BBD8_0020C0D8(D_004A45E8_0020C0D8); if (p != 0) { R_0020C0D8 *q = p->w464; if (q != 0) q->f12 = D_004A45F8 * D_004A0414 / 180.0f; } } return 0; }

extern volatile int D_004A1444_0020D2E0 __asm__("D_004A1444"), D_004A140C_0020D2E0 __asm__("D_004A140C"); extern int D_004A46AC_0020D2E0 __asm__("D_004A46AC"), D_004A45E8_x; extern int D_004A46BC_0020D2E0 __asm__("D_004A46BC"); int func_002128C8(int, int); int func_00212C18(int, int, int);
// MATCH func_0020D2E0
void pchevent_0020d2e0(int on) { int i, n; if (on) { if (D_004A1444_0020D2E0 == 0 && (D_004A140C_0020D2E0 & 8) && D_004A46AC_0020D2E0 != 0 && D_004A46BC_0020D2E0 >= 0) { n = func_002128C8(D_004A46AC_0020D2E0, D_004A46BC_0020D2E0); for (i = 0; i < n; i++) func_00212C18(D_004A46AC_0020D2E0, D_004A46BC_0020D2E0, i); } } }

extern int D_004A45E4_0020F970 __asm__("D_004A45E4"), D_004A4960_0020F970 __asm__("D_004A4960"); int func_002DCE40_0020F970(char *, char *, ...) __asm__("func_002DCE40"); int func_0020B858(int, char *);
extern int D_004A4614_0020F970 __asm__("D_004A4614"), D_004A4618_0020F970 __asm__("D_004A4618"), D_004A4658_0020F970 __asm__("D_004A4658"); extern char D_00455260[], D_004A48D8_0020F970[] __asm__("D_004A48D8"), D_004A4790_0020F970[] __asm__("D_004A4790"); extern float D_003C0F20[]; char *func_00160C70(int, char *, int);
// MATCH func_0020F970
int pchevent_0020f970(int f) { char buf[512]; char *s; if (f & 8) { if (D_004A4614_0020F970 > 0 && D_004A4618_0020F970 >= 0) s = func_00160C70(D_004A4658_0020F970, D_004A48D8_0020F970, D_004A4618_0020F970); else s = D_004A4790_0020F970; func_002DCE40_0020F970(buf, D_00455260, s, (double)D_003C0F20[0], (double)D_003C0F20[1], (double)D_003C0F20[2]); func_0020B858(D_004A45E4_0020F970, buf); D_004A4960_0020F970++; } return 0; }

extern int D_004A45E4_0020FB88 __asm__("D_004A45E4"), D_004A4960_0020FB88 __asm__("D_004A4960"); int func_002DCE40_0020FB88(char *, char *, ...) __asm__("func_002DCE40"); int func_0020B858(int, char *);
extern int D_004A4614_0020FB88 __asm__("D_004A4614"), D_004A4618_0020FB88 __asm__("D_004A4618"), D_004A4658_0020FB88 __asm__("D_004A4658"); extern char D_004552A8[], D_004A48D8_0020FB88[] __asm__("D_004A48D8"), D_004A4790_0020FB88[] __asm__("D_004A4790"); extern float D_003C0F30[]; char *func_00160C70(int, char *, int);
// MATCH func_0020FB88
int pchevent_0020fb88(int f) { char buf[512]; char *s; if (f & 8) { if (D_004A4614_0020FB88 > 0 && D_004A4618_0020FB88 >= 0) s = func_00160C70(D_004A4658_0020FB88, D_004A48D8_0020FB88, D_004A4618_0020FB88); else s = D_004A4790_0020FB88; func_002DCE40_0020FB88(buf, D_004552A8, s, (double)D_003C0F30[0], (double)D_003C0F30[1], (double)D_003C0F30[2]); func_0020B858(D_004A45E4_0020FB88, buf); D_004A4960_0020FB88++; } return 0; }

extern int D_004A1444_00210188 __asm__("D_004A1444"); extern int D_004A49DC, D_004A49D8, D_004A49E0, D_004A49D0; extern int D_00329640[];
// MATCH func_00210188
void pchevent_00210188(int on) { if (on && D_004A1444_00210188 == 0) D_00329640[D_004A49D0] = D_004A49D8 | (D_004A49DC << 8) | (D_004A49E0 << 16); }

extern int D_003244F0[];
// MATCH func_0024E098
int FUN_0024e098(int a) { if (a == D_003244F0[10] || a == D_003244F0[11]) return 1; return 0; }

typedef struct { unsigned w0, w4, w8; } O_00191698;
// MATCH func_00191698
unsigned FUN_00191698(O_00191698 *o, unsigned a) { unsigned v = ((o->w8 << 4) + o->w4 + 16) & 0xfffffff; if (a == v) return 0; return (a - o->w0) >> 11; }

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

typedef struct { char p[72]; int w72; } O_00192960;
typedef struct { long long a, b; int c, d; } Q_00192960;
extern char D_003215D0_00192960[] __asm__("D_003215D0"); void func_00192500(char *, Q_00192960 *);
// MATCH func_00192960
void FUN_00192960(O_00192960 *o, long long a, long long b, int c, int d) { Q_00192960 q; q.a = a; q.b = b; q.c = c - o->w72; q.d = d; func_00192500(D_003215D0_00192960, &q); }

typedef struct { int w0, w4, w8; int *w12; char *vt; } O_0020B508;
extern char D_00455618[], D_00454D80_0020B508[] __asm__("D_00454D80"); int *func_00162130_0020B508(int, char *, int) __asm__("func_00162130");
// MATCH func_0020B508
O_0020B508 *pchevent_0020b508(O_0020B508 *o, int n) { int *p, *q; int i; o->vt = D_00455618; o->w4 = n; o->w0 = n; o->w8 = 0; if (n == 0) o->w12 = 0; else { p = func_00162130_0020B508(n * 4, D_00454D80_0020B508, 105); o->w12 = p; if (p != 0) { q = p; i = o->w4; q = p; if (i > 0) { do { *q++ = 0; i--; } while (i != 0); } } } return o; }

typedef struct { char c[8]; } V8_0025E3F8;
typedef struct { int w0; float f4; int w8, w12, w16, w20, w24, w28, w32; V8_0025E3F8 v36; } O_0025E3F8;
extern V8_0025E3F8 D_004A59B0[2];
// MATCH func_0025E3F8
O_0025E3F8 *FUN_0025e3f8(O_0025E3F8 *o) { o->w0 = 0; o->f4 = 1.0f; o->w8 = 0; o->w12 = 0; o->w16 = 0; o->w20 = 0; o->w24 = 0; o->w28 = 0; o->w32 = 0; o->v36 = D_004A59B0[0]; return o; }

void func_0015EC38(char *, float); void func_0015EB40(char *, float);
// MATCH func_002A86F0
void FUN_002a86f0(char *o, float x) { func_0015EC38(o + 432, -0.25f); func_0015EB40(o + 432, x); }

void func_0015EB38(char *); void func_0015EB30(char *, float);
// MATCH func_002A8788
void FUN_002a8788(char *o, float a, float b) { func_0015EB38(o + 432); func_0015EB30(o + 432, b); }

extern char **D_004A6F44; extern char D_004A2C28[], D_004A2C30[]; int func_00161E58(char *, char *);
// MATCH func_001620A8
int FUN_001620a8(void) { int r = func_00161E58(*D_004A6F44 + 128, D_004A2C28); if (r) return r; return func_00161E58(*D_004A6F44, D_004A2C30); }

extern float D_0049FE18; extern char D_0053FD00[]; int func_0012C1E8(void *); float func_0015A9A8(char *, float, void *);
// MATCH func_00127498
float battle_00127498(void *o) { float r = 0.0f; if (func_0012C1E8(o)) r = func_0015A9A8(D_0053FD00, D_0049FE18, o); return r; }

extern int D_00343028_0010EF68[] __asm__("D_00343028"); extern int D_004A3850_0010EF68 __asm__("D_004A3850"); int func_0010AF68(int, int, int, int);
// MATCH func_0010EF68
int FUN_0010ef68(int a, int b, int c) { if ((D_00343028_0010EF68[0] & 8) || D_004A3850_0010EF68 == 2) return 1; return func_0010AF68(a, 901, b, c); }

extern int D_00343028_0010EFB0[] __asm__("D_00343028"); extern int D_004A3850_0010EFB0 __asm__("D_004A3850"); int func_0010C2D0(int, int, int, int, int);
// MATCH func_0010EFB0
int FUN_0010efb0(int a, int b, int c, int d) { if ((D_00343028_0010EFB0[0] & 8) || D_004A3850_0010EFB0 == 2) return 0; return func_0010C2D0(a, 901, b, c, d); }

int func_00161200(int, unsigned char *);
// MATCH func_00161230
unsigned char *FUN_00161230(int a, unsigned char *p) { int fl = p[3] & 1; p += 8; if (fl) p += func_00161200(a, p) * 4 + 4; return p; }

typedef struct { float x, y, z, w; } V4_00154268;
static inline void set_00154268(V4_00154268 *v, float x, float y, float z) { v->x = x; v->y = y; v->z = z; v->w = 1.0f; }
void func_00153520(V4_00154268 *, V4_00154268 *); void func_001535B8(char *, char *, V4_00154268 *); void func_00154550_00154268(char *) __asm__("func_00154550");
// MATCH func_00154268
void FUN_00154268(char *o) { V4_00154268 m; V4_00154268 v; set_00154268(&v, 1.0f, 0.0f, 0.0f); func_00153520(&m, &v); func_001535B8(o + 192, o + 192, &m); func_00154550_00154268(o); }

typedef struct { float x, y, z, w; } V4_001542C8;
static inline void set_001542C8(V4_001542C8 *v, float x, float y, float z) { v->x = x; v->y = y; v->z = z; v->w = 1.0f; }
void func_00153520_001542C8(V4_001542C8 *, V4_001542C8 *) __asm__("func_00153520"); void func_001535B8_001542C8(char *, char *, V4_001542C8 *) __asm__("func_001535B8"); void func_00154550_001542C8(char *) __asm__("func_00154550");
// MATCH func_001542C8
void FUN_001542c8(char *o) { V4_001542C8 m; V4_001542C8 v; set_001542C8(&v, 0.0f, 1.0f, 0.0f); func_00153520_001542C8(&m, &v); func_001535B8_001542C8(o + 192, o + 192, &m); func_00154550_001542C8(o); }

typedef struct { float x, y, z, w; } V4_00154328;
static inline void set_00154328(V4_00154328 *v, float x, float y, float z) { v->x = x; v->y = y; v->z = z; v->w = 1.0f; }
void func_00153520_00154328(V4_00154328 *, V4_00154328 *) __asm__("func_00153520"); void func_001535B8_00154328(char *, char *, V4_00154328 *) __asm__("func_001535B8"); void func_00154550_00154328(char *) __asm__("func_00154550");
// MATCH func_00154328
void FUN_00154328(char *o) { V4_00154328 m; V4_00154328 v; set_00154328(&v, 0.0f, 0.0f, 1.0f); func_00153520_00154328(&m, &v); func_001535B8_00154328(o + 192, o + 192, &m); func_00154550_00154328(o); }

// MATCH func_00249DB8
void FUN_00249db8(short *d, float *s) { d[0] = (int)(s[0] * 4096.0f); d[1] = (int)(s[1] * 4096.0f); d[2] = (int)(s[2] * 4096.0f); d[3] = (int)(s[3] * 4096.0f); }

typedef struct { float x, y, z, w; } V4_001563A0;
typedef struct { char p[64]; V4_001563A0 v1; V4_001563A0 v2; } O_001563A0;
static inline void set_001563A0(V4_001563A0 *v, int x, int y, int z) { v->x = x; v->y = y; v->z = z; v->w = 128.0f; }
// MATCH func_001563A0
void FUN_001563a0(O_001563A0 *o, int a, int b, int c, int d, int e, int f) { set_001563A0(&o->v1, a, b, c); set_001563A0(&o->v2, d, e, f); }

typedef struct { char p[4]; int w4; char p1[8]; int w16; int *w20; int *w24; char p2[4]; signed char b32; } O_002034A0;
// MATCH func_002034A0
int FUN_002034a0(O_002034A0 *o, int idx, int *out) { if (o->b32 != 1 || idx < 0 || o->w4 - 1 < idx) return 0; if (out != 0) *out = o->w20[idx]; return o->w16 + o->w24[idx]; }

typedef struct { char p[48]; void *vt; char p2[12]; int a; int b; char p3[4]; int c; } O_1658f8_001658F8;
extern char D_0043D1A0[]; int func_00164D30(void *);
// MATCH func_001658F8
void *pachislot_001658f8(O_1658f8_001658F8 *o) { func_00164D30(o); o->c = -1; o->vt = D_0043D1A0; o->a = 0; o->b = 0; return o; }

extern int D_00631AB0[]; extern int D_00631AC0[]; extern int D_00631AC8[]; int func_002DC804_002D63F8(void *, int, int) __asm__("func_002DC804");
// MATCH func_002D63F8
int *FUN_002d63f8(void) { if (D_00631AC0[0] == 0) { D_00631AC0[0] = 1; func_002DC804_002D63F8(D_00631AB0, 0, 16); D_00631AB0[1] = (int)D_00631AC8; } return D_00631AB0; }

typedef struct { char p[48]; void *vt; int a; int b; int c; } O_164d30_00164D30;
extern char D_0043D280[]; int func_00164890(void *);
// MATCH func_00164D30
void *pachislot_00164d30(O_164d30_00164D30 *o) { func_00164890(o); o->c = -1; o->vt = D_0043D280; o->a = 0; o->b = 0; return o; }

extern int D_004A72F4, D_004A72F0; extern char D_00621320_002A2020[] __asm__("D_00621320"), D_0062AB20[], D_0041EF80[]; void func_0015A570(char *, int);
// MATCH func_002A2020
void clas_min_002a2020(void) { unsigned i; D_004A72F4 = 0; D_004A72F0 = 0; for (i = 0; i < 512; i++) D_00621320_002A2020[i] = 0; for (i = 0; i < 16; i++) D_0062AB20[i] = 0; func_0015A570(D_0041EF80, 0); }

typedef struct { char p[168]; struct { char p[28]; unsigned w28; } *w168; } R; typedef struct { char p[4800]; R *w4800; char p2[12]; unsigned w4816; char p3[648]; } E_0027C3E0; extern E_0027C3E0 *D_004A1A20_0027C3E0 __asm__("D_004A1A20"); extern int D_004A6634;
// MATCH func_0027C3E0
void FUN_0027c3e0(void) { int i; E_0027C3E0 *e = D_004A1A20_0027C3E0; for (i = 0; i < 4; i++) { if (e->w4816 & 0x60000000) e->w4800->w168->w28 |= 0x100; e = (E_0027C3E0 *)((char *)e + 5472); } D_004A6634 = 1; }

typedef struct { char p[40]; int w40, w44; char p2[4]; int w52, w56, w60; } E_00186AC0;
typedef struct { E_00186AC0 e[64]; int w4096; float f4100, f4104; int w4108, w4112, w4116, w4120, w4124, w4128, w4132; } O_00186AC0;
// MATCH func_00186AC0
void FUN_00186ac0(O_00186AC0 *o) { int i; E_00186AC0 *e; o->w4108 = 0; o->f4100 = 32.0f; o->f4104 = 32.0f; o->w4112 = 0; o->w4116 = 0; o->w4120 = 0; o->w4124 = 0; o->w4128 = 0; o->w4132 = 0; o->w4096 = 0; e = o->e; for (i = 63; i >= 0; i--) { e->w40 = 0; e->w52 = 0; e->w44 = 0; e->w56 = 0; e->w60 = 0; e++; } }

// MATCH func_002A1B08
void clas_min_002a1b08(char *b, int x) { int i; int *p = (int *)(b + 264); for (i = 0; i < 5; i++) { if (*p == x) { p[-2] = 0; *p = 0; p[-1] = -1; } p += 68; } }

// MATCH func_00101148
void memo2_00101148(char *o) { int i; char *a = o; char *b = o + 2440; for (i = 0; i < 12; i++) { *(int *)(b - 4) = -2; *(int *)b = 0; *(unsigned short *)(a + 1364) |= 0x80; a += 64; b += 128; } o[1340] = 0; o[4502] = -1; o[4503] = -1; }

// MATCH func_0018DA70
void FUN_0018da70(unsigned char *d, unsigned char *a, unsigned char *b, float t) { int i; for (i = 255; i >= 0; i--) { d[3] = a[3]; d[0] = a[0] + (int)((b[0] - a[0]) * t); d[1] = a[1] + (int)((b[1] - a[1]) * t); d[2] = a[2] + (int)((b[2] - a[2]) * t); a += 4; b += 4; d += 4; } }

// MATCH func_0018D9A8
void FUN_0018d9a8(unsigned char *d, unsigned char *a, unsigned char *b, float t) { int i; float u = 1.0f - t; for (i = 255; i >= 0; i--) { d[3] = a[3]; d[0] = (int)(a[0] * u + b[0] * t); d[1] = (int)(a[1] * u + b[1] * t); d[2] = (int)(a[2] * u + b[2] * t); a += 4; b += 4; d += 4; } }

typedef struct { char p[80]; int w80; char p2[4]; int w88; int w92; int w96; char p3[16]; int w116; } O_0016FA70;
void func_0016FAB0(void *);

// MATCH func_0016FA70
void roulette_0016fa70(O_0016FA70 *o) { func_0016FAB0(o); o->w80 = 12; o->w96 = 0; o->w88 = 0; o->w92 = 0; o->w116 = 1; }

typedef struct { char p[124]; int a, b, c, d; } G_0029B690;
extern G_0029B690 D_00620070_0029B690 __asm__("D_00620070");
// MATCH func_0029B690
void FUN_0029b690(void) { if (D_00620070_0029B690.a == 11) { int vc = 76; int va = 28; int vb = 1; D_00620070_0029B690.a = va; D_00620070_0029B690.b = vb; D_00620070_0029B690.c = vc; D_00620070_0029B690.d = 0; } }

extern int D_00425510_0029B758[] __asm__("D_00425510"); extern int D_00425710_0029B758[] __asm__("D_00425710");
// MATCH func_0029B758
void FUN_0029b758(int a, int b) { D_00425510_0029B758[2] |= 0x80; D_00425710_0029B758[49] += b; if (D_00425710_0029B758[49] < 0) D_00425710_0029B758[49] = 0; }

typedef struct { float x, y, z, w; } V4_00154170;
static inline void set_00154170(V4_00154170 *v, float x, float y, float z) { v->x = x; v->y = y; v->z = z; v->w = 1.0f; }
void func_0018F368(V4_00154170 *, char *, V4_00154170 *); void func_0018F068(char *, V4_00154170 *);
// MATCH func_00154170
void FUN_00154170(char *o, float a) { V4_00154170 v; set_00154170(&v, 0.0f, 0.0f, a); func_0018F368(&v, o + 64, &v); func_0018F068(o, &v); }

typedef struct { float x, y, z, w; } V4_00154118;
static inline void set_00154118(V4_00154118 *v, float x, float y, float z) { v->x = x; v->y = y; v->z = z; v->w = 1.0f; }
void func_0018F368_00154118(V4_00154118 *, char *, V4_00154118 *) __asm__("func_0018F368"); void func_0018F068_00154118(char *, V4_00154118 *) __asm__("func_0018F068");
// MATCH func_00154118
void FUN_00154118(char *o, float a) { V4_00154118 v; set_00154118(&v, 0.0f, a, 0.0f); func_0018F368_00154118(&v, o + 64, &v); func_0018F068_00154118(o, &v); }

typedef struct N_0012D980 { char p[60]; struct N_0012D980 *nx; } N_0012D980;
typedef struct { char p[8]; N_0012D980 *h; int c; } O_0012D980;
void func_00108B80_0012D980(N_0012D980 *) __asm__("func_00108B80");
// MATCH func_0012D980
void pchsysw_0012d980(O_0012D980 *o) { N_0012D980 *n = o->h; if (n) { do { N_0012D980 *t = n->nx; func_00108B80_0012D980(n); n = t; } while (n); } o->c = 0; o->h = 0; }

typedef struct N_0012D498 { char p[24]; struct N_0012D498 *nx; } N_0012D498;
typedef struct { char p[8]; N_0012D498 *h; int c; } O_0012D498;
void func_00108B80_0012D498(N_0012D498 *) __asm__("func_00108B80");
// MATCH func_0012D498
void FUN_0012d498(O_0012D498 *o) { N_0012D498 *n = o->h; if (n) { do { N_0012D498 *t = n->nx; func_00108B80_0012D498(n); n = t; } while (n); } o->c = 0; o->h = 0; }

typedef struct { float x, y, z, w; } V4_001540C0;
static inline void set_001540C0(V4_001540C0 *v, float x, float y, float z) { v->x = x; v->y = y; v->z = z; v->w = 1.0f; }
void func_0018F368_001540C0(V4_001540C0 *, char *, V4_001540C0 *) __asm__("func_0018F368"); void func_0018F068_001540C0(char *, V4_001540C0 *) __asm__("func_0018F068");
// MATCH func_001540C0
void FUN_001540c0(char *o, float a) { V4_001540C0 v; set_001540C0(&v, a, 0.0f, 0.0f); func_0018F368_001540C0(&v, o + 64, &v); func_0018F068_001540C0(o, &v); }

typedef struct { char p[104]; float a104, a108, a112, a116; } O_0029F9B8;
extern float D_004A0D7C, D_004A0D80, D_004A0D84;
// MATCH func_0029F9B8
void clas_min_0029f9b8(O_0029F9B8 *o, float s) { o->a108 = s * D_004A0D7C; o->a104 = s * D_004A0D80; o->a116 = s * D_004A0D84; o->a112 = s * 0.0f; }

typedef struct { float x, y, z, w; } V4_00203540;
static inline void set_00203540(V4_00203540 *v, float x, float y, float z) { v->x = x; v->y = y; v->z = z; v->w = 1.0f; }
extern float D_004A0394; void func_0018F080(V4_00203540 *, int, V4_00203540 *); void func_0018EC78_00203540(char *, V4_00203540 *, V4_00203540 *) __asm__("func_0018EC78");
// MATCH func_00203540
void FUN_00203540(char *o, int b) { V4_00203540 v; V4_00203540 m; set_00203540(&v, 0.0f, D_004A0394, 0.0f); func_0018F080(&m, b, &v); func_0018EC78_00203540(o, &v, &m); }

typedef struct { char c[8]; } V8_0016C6C0;
typedef struct { int a; char p0[4]; int b; char p[12]; int w24, w28; char p2[24]; V8_0016C6C0 v; } O_0016C6C0;
extern V8_0016C6C0 D_004A2F38[2];
// MATCH func_0016C6C0
int FUN_0016c6c0(O_0016C6C0 *o) { int a = o->a - 3; int b = o->b + 3; o->a = a; o->b = b; if (a <= 200) { o->a = 200; o->b = 440; o->w24 = 0; o->w28 = 0; o->v = D_004A2F38[0]; } return 0; }

extern char D_0045D448[]; extern int D_004A1478, D_004A1498; int func_001118F8_00245DB8(char *) __asm__("func_001118F8"); void func_00245578(int, int);
// MATCH func_00245DB8
void FUN_00245db8(int a, int b, int c) { func_001118F8_00245DB8(D_0045D448); D_004A1478 = c; D_004A1498 = 1; func_00245578(a, b); }

extern char D_0045C658[]; extern int D_004A1498_002392F0 __asm__("D_004A1498"), D_004A1478_002392F0 __asm__("D_004A1478"), D_004A1474; int func_001118F8_002392F0(char *) __asm__("func_001118F8");
// MATCH func_002392F0
void FUN_002392f0(int a, int b) { char buf[128]; func_001118F8_002392F0(D_0045C658); D_004A1498_002392F0 = a; D_004A1478_002392F0 = b; D_004A1474 = 1; }

typedef struct { int w0; char p[516]; int w520; char q[4]; int w528; } O_00204968;
int func_001AD6B0(int);
// MATCH func_00204968
void pchjob0_00204968(O_00204968 *o) { if (o->w0 != 0) { func_001AD6B0(o->w0); o->w0 = 0; o->w528 = 0; o->w520 = -1; } }

extern int D_004A140C_0013D320 __asm__("D_004A140C"), D_004A2534; extern int D_00419D18_0013D320[] __asm__("D_00419D18");
// MATCH func_0013D320
int FUN_0013d320(int a) { if (a != 0 && (D_004A140C_0013D320 & 0x200)) {
D_00419D18_0013D320[26] = 255;
D_00419D18_0013D320[70] = 255;
D_00419D18_0013D320[114] = 255;
D_004A2534 = D_004A2534 + 1;
} }

int func_002CADE8(void);
// MATCH func_002CAD78
int FUN_002cad78(void) { if (func_002CADE8() != 1) return 0; *(volatile int *)0x10003810 = 8; return 1; }

typedef struct { int x, y, z; float w; } V_00189768;
typedef struct { char p[48]; V_00189768 v; } O_00189768;
void func_0018EB98_00189768(O_00189768 *, int) __asm__("func_0018EB98"); void func_0018F3D8_00189768(O_00189768 *, int, O_00189768 *) __asm__("func_0018F3D8");
static inline void set_00189768(V_00189768 *v) { v->x = 0; v->y = 0; v->z = 0; v->w = 1.0f; }
// MATCH func_00189768
void FUN_00189768(O_00189768 *o, int b, int c) { func_0018EB98_00189768(o, c); set_00189768(&o->v); func_0018F3D8_00189768(o, b, o); }

typedef struct { int x, y, z; float w; } V_0015DFD8;
typedef struct { char p[48]; V_0015DFD8 v; } O_0015DFD8;
void func_0018EB98_0015DFD8(O_0015DFD8 *, int) __asm__("func_0018EB98"); void func_0018F3D8_0015DFD8(O_0015DFD8 *, int, O_0015DFD8 *) __asm__("func_0018F3D8");
static inline void set_0015DFD8(V_0015DFD8 *v) { v->x = 0; v->y = 0; v->z = 0; v->w = 1.0f; }
// MATCH func_0015DFD8
void FUN_0015dfd8(O_0015DFD8 *o, int b, int c) { func_0018EB98_0015DFD8(o, c); set_0015DFD8(&o->v); func_0018F3D8_0015DFD8(o, b, o); }

typedef struct { char c[8]; } V8_00174BF0;
typedef struct { char p[340]; int w340; char q[64]; V8_00174BF0 v; } O_00174BF0;
extern unsigned long long D_004A12D8_00174BF0 __asm__("D_004A12D8"); extern char D_00336450[]; extern V8_00174BF0 D_004A3208[2];
void func_001749D8(O_00174BF0 *, char *); void func_00172C48_00174BF0(O_00174BF0 *) __asm__("func_00172C48");
// MATCH func_00174BF0
int repetition_00174bf0(O_00174BF0 *o) { func_001749D8(o, D_00336450); func_00172C48_00174BF0(o); o->w340 = 2; if (D_004A12D8_00174BF0 & 0x200040) o->v = D_004A3208[0]; return 0; }

typedef struct { char c[8]; } V8_00174EC8;
typedef struct { char p[340]; int w340, w344; char p2[24]; int w372; char q[32]; V8_00174EC8 v; } O_00174EC8;
extern unsigned long long D_004A12D8_00174EC8 __asm__("D_004A12D8");
extern char D_00336478[]; extern V8_00174EC8 D_004A3230[2]; void func_001749D8_00174EC8(O_00174EC8 *, char *) __asm__("func_001749D8"); void func_00172C58(O_00174EC8 *);
// MATCH func_00174EC8
int repetition_00174ec8(O_00174EC8 *o) { func_001749D8_00174EC8(o, D_00336478); func_00172C58(o);  if (D_004A12D8_00174EC8 & 0x200040) { o->v = D_004A3230[0];  } return 0; }

typedef struct { char c[8]; } V8_00175190;
typedef struct { char p[340]; int w340, w344; char p2[24]; int w372; char q[32]; V8_00175190 v; } O_00175190;
extern unsigned long long D_004A12D8_00175190 __asm__("D_004A12D8");
extern char D_003364A0[]; extern V8_00175190 D_004A3258[2]; void func_001749D8_00175190(O_00175190 *, char *) __asm__("func_001749D8"); void func_00172C48_00175190(O_00175190 *) __asm__("func_00172C48");
// MATCH func_00175190
int repetition_00175190(O_00175190 *o) { func_001749D8_00175190(o, D_003364A0); func_00172C48_00175190(o); o->w344 = 1; if (D_004A12D8_00175190 & 0x200040) { o->v = D_004A3258[0];  } return 0; }

typedef struct { char c[8]; } V8_00175640;
typedef struct { char p[340]; int w340, w344; char p2[24]; int w372; char q[32]; V8_00175640 v; } O_00175640;
extern unsigned long long D_004A12D8_00175640 __asm__("D_004A12D8");
extern char D_003364D8[]; extern V8_00175640 D_004A3290[2]; void func_001749D8_00175640(O_00175640 *, char *) __asm__("func_001749D8"); void func_00172C58_00175640(O_00175640 *) __asm__("func_00172C58");
// MATCH func_00175640
int repetition_00175640(O_00175640 *o) { func_001749D8_00175640(o, D_003364D8); func_00172C58_00175640(o);  if (D_004A12D8_00175640 & 0x200040) { o->v = D_004A3290[0];  } return 0; }

typedef struct { char c[8]; } V8_00175A98;
typedef struct { char p[340]; int w340, w344; char p2[24]; int w372; char q[32]; V8_00175A98 v; } O_00175A98;
extern unsigned long long D_004A12D8_00175A98 __asm__("D_004A12D8");
extern char D_00336510[]; extern V8_00175A98 D_004A32C8[2]; void func_001749D8_00175A98(O_00175A98 *, char *) __asm__("func_001749D8"); 
// MATCH func_00175A98
int repetition_00175a98(O_00175A98 *o) { func_001749D8_00175A98(o, D_00336510);  if (D_004A12D8_00175A98 & 0x200040) { o->v = D_004A32C8[0]; o->w372 = 0; } return 0; }

typedef struct { char c[8]; } V8_00174C60;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_00174C60 v; } O_00174C60;
extern unsigned long long D_004A12D8_00174C60 __asm__("D_004A12D8");
extern char D_00336458[]; extern V8_00174C60 D_004A3210[2]; void func_001749D8_00174C60(O_00174C60 *, char *) __asm__("func_001749D8");
// MATCH func_00174C60
int repetition_00174c60(O_00174C60 *o) { func_001749D8_00174C60(o, D_00336458); o->w356 = 4; o->w360 = 2; if (o->w372++ & 0x20) o->w352 = 32; else o->w352 = 33; if (D_004A12D8_00174C60 & 0x200040) o->v = D_004A3210[0]; return 0; }

typedef struct { char c[8]; } V8_00174CF0;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_00174CF0 v; } O_00174CF0;
extern unsigned long long D_004A12D8_00174CF0 __asm__("D_004A12D8");
extern char D_00336460[]; extern V8_00174CF0 D_004A3218[2]; void func_001749D8_00174CF0(O_00174CF0 *, char *) __asm__("func_001749D8");
// MATCH func_00174CF0
int repetition_00174cf0(O_00174CF0 *o) { func_001749D8_00174CF0(o, D_00336460); o->w356 = 4; o->w360 = 4; if (o->w372++ & 0x20) o->w352 = 512; else o->w352 = 514; if (D_004A12D8_00174CF0 & 0x200040) o->v = D_004A3218[0]; return 0; }

typedef struct { char c[8]; } V8_00174D80;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_00174D80 v; } O_00174D80;
extern unsigned long long D_004A12D8_00174D80 __asm__("D_004A12D8");
extern char D_00336468[]; extern V8_00174D80 D_004A3220[2]; void func_001749D8_00174D80(O_00174D80 *, char *) __asm__("func_001749D8");
// MATCH func_00174D80
int repetition_00174d80(O_00174D80 *o) { func_001749D8_00174D80(o, D_00336468); o->w356 = 2; o->w360 = 4; if (o->w372++ & 0x20) o->w352 = 16; else o->w352 = 17; if (D_004A12D8_00174D80 & 0x200040) o->v = D_004A3220[0]; return 0; }

typedef struct { char c[8]; } V8_00174F30;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_00174F30 v; } O_00174F30;
extern unsigned long long D_004A12D8_00174F30 __asm__("D_004A12D8");
extern char D_00336480[]; extern V8_00174F30 D_004A3238[2]; void func_001749D8_00174F30(O_00174F30 *, char *) __asm__("func_001749D8");
// MATCH func_00174F30
int repetition_00174f30(O_00174F30 *o) { func_001749D8_00174F30(o, D_00336480); o->w356 = 2; o->w360 = 0; if (o->w372++ & 0x20) o->w352 = 128; else o->w352 = 130; if (D_004A12D8_00174F30 & 0x200040) o->v = D_004A3238[0]; return 0; }

typedef struct { char c[8]; } V8_00174FC0;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_00174FC0 v; } O_00174FC0;
extern unsigned long long D_004A12D8_00174FC0 __asm__("D_004A12D8");
extern char D_00336488[]; extern V8_00174FC0 D_004A3240[2]; void func_001749D8_00174FC0(O_00174FC0 *, char *) __asm__("func_001749D8");
// MATCH func_00174FC0
int repetition_00174fc0(O_00174FC0 *o) { func_001749D8_00174FC0(o, D_00336488); o->w356 = 0; o->w360 = 0; if (o->w372++ & 0x20) o->w352 = 8; else o->w352 = 9; if (D_004A12D8_00174FC0 & 0x200040) o->v = D_004A3240[0]; return 0; }

typedef struct { char c[8]; } V8_00175048;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_00175048 v; } O_00175048;
extern unsigned long long D_004A12D8_00175048 __asm__("D_004A12D8");
extern char D_00336490[]; extern V8_00175048 D_004A3248[2]; void func_001749D8_00175048(O_00175048 *, char *) __asm__("func_001749D8");
// MATCH func_00175048
int repetition_00175048(O_00175048 *o) { func_001749D8_00175048(o, D_00336490); o->w356 = 0; o->w360 = 2; if (o->w372++ & 0x20) o->w352 = 64; else o->w352 = 66; if (D_004A12D8_00175048 & 0x200040) o->v = D_004A3248[0]; return 0; }

typedef struct { char c[8]; } V8_00175200;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_00175200 v; } O_00175200;
extern unsigned long long D_004A12D8_00175200 __asm__("D_004A12D8");
extern char D_003364A8[]; extern V8_00175200 D_004A3260[2]; void func_001749D8_00175200(O_00175200 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void);
// MATCH func_00175200
int repetition_00175200(O_00175200 *o) { func_001749D8_00175200(o, D_003364A8); o->w356 = 4; o->w360 = 2; if (o->w372++ & 0x20) o->w352 = 32; else o->w352 = 33; if (func_00172958() == 4 && func_00172978() == 2) o->v = D_004A3260[0]; return 0; }

typedef struct { char c[8]; } V8_00175370;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_00175370 v; } O_00175370;
extern unsigned long long D_004A12D8_00175370 __asm__("D_004A12D8");
extern char D_003364B8[]; extern V8_00175370 D_004A3260_00175370[2] __asm__("D_004A3260"); void func_001749D8_00175370(O_00175370 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void);
// MATCH func_00175370
int repetition_00175370(O_00175370 *o) { func_001749D8_00175370(o, D_003364B8); o->w356 = 4; o->w360 = 2; if (o->w372++ & 0x20) o->w352 = 32; else o->w352 = 33; if (func_00172958() == 4 && func_00172978() == 2) o->v = D_004A3260_00175370[0]; return 0; }

typedef struct { char c[8]; } V8_001754D8;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_001754D8 v; } O_001754D8;
extern unsigned long long D_004A12D8_001754D8 __asm__("D_004A12D8");
extern char D_003364C8[]; extern V8_001754D8 D_004A3270[2]; void func_001749D8_001754D8(O_001754D8 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void);
// MATCH func_001754D8
int repetition_001754d8(O_001754D8 *o) { func_001749D8_001754D8(o, D_003364C8); o->w356 = 4; o->w360 = 4; if (o->w372++ & 0x20) o->w352 = 512; else o->w352 = 514; { int r = func_00172958(); if (r == 4 && func_00172978() == r) o->v = D_004A3270[0]; } return 0; }

typedef struct { char c[8]; } V8_001756A8;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_001756A8 v; } O_001756A8;
extern unsigned long long D_004A12D8_001756A8 __asm__("D_004A12D8");
extern char D_003364E0[]; extern V8_001756A8 D_004A3298[2]; void func_001749D8_001756A8(O_001756A8 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void);
// MATCH func_001756A8
int repetition_001756a8(O_001756A8 *o) { func_001749D8_001756A8(o, D_003364E0); o->w356 = 2; o->w360 = 0; if (o->w372++ & 0x20) o->w352 = 128; else o->w352 = 130; if (func_00172958() == 2 && func_00172978() == 0) o->v = D_004A3298[0]; return 0; }

typedef struct { char c[8]; } V8_001757F0;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_001757F0 v; } O_001757F0;
extern unsigned long long D_004A12D8_001757F0 __asm__("D_004A12D8");
extern char D_003364F0[]; extern V8_001757F0 D_004A3298_001757F0[2] __asm__("D_004A3298"); void func_001749D8_001757F0(O_001757F0 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void);
// MATCH func_001757F0
int repetition_001757f0(O_001757F0 *o) { func_001749D8_001757F0(o, D_003364F0); o->w356 = 2; o->w360 = 0; if (o->w372++ & 0x20) o->w352 = 128; else o->w352 = 130; if (func_00172958() == 2 && func_00172978() == 0) o->v = D_004A3298_001757F0[0]; return 0; }

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

typedef struct { char c[8]; } V8_0016D750;
typedef struct { char p[584]; short adj; short pad; void (*fn)(void *); } VT_0016D750;
typedef struct { char p[44]; int w44; char q[56]; V8_0016D750 v; char r[472]; short adj; short pad; void (*fn)(void *); } O_0016D750;
extern V8_0016D750 D_004A2FF8[2]; void func_0016E9B8(O_0016D750 *); void func_0016ED20(O_0016D750 *, int);
// MATCH func_0016D750
int darts_0016d750(O_0016D750 *o) { int n = o->w44 + 1; o->w44 = n; if (n == 1) return 10; if (n < 4) return 0; func_0016E9B8(o); func_0016ED20(o, 1); o->fn((char *)o + o->adj); o->v = D_004A2FF8[0]; return 0; }

typedef struct { char c[8]; } V8_0016D7D8;
typedef struct { char p[584]; short adj; short pad; void (*fn)(void *); } VT_0016D7D8;
typedef struct { char p[44]; int w44; char q[56]; V8_0016D7D8 v; char r[472]; short adj; short pad; void (*fn)(void *); } O_0016D7D8;
extern V8_0016D7D8 D_004A3000[2]; void func_0016E9B8_0016D7D8(O_0016D7D8 *) __asm__("func_0016E9B8"); void func_0016ED20_0016D7D8(O_0016D7D8 *, int) __asm__("func_0016ED20");
// MATCH func_0016D7D8
int darts_0016d7d8(O_0016D7D8 *o) { int n = o->w44 + 1; o->w44 = n; if (n == 1) return 10; if (n < 4) return 0; func_0016E9B8_0016D7D8(o); func_0016ED20_0016D7D8(o, 2); o->fn((char *)o + o->adj); o->v = D_004A3000[0]; return 0; }

typedef struct { char c[8]; } V8_0016D860;
typedef struct { char p[584]; short adj; short pad; void (*fn)(void *); } VT_0016D860;
typedef struct { char p[44]; int w44; char q[56]; V8_0016D860 v; char r[472]; short adj; short pad; void (*fn)(void *); } O_0016D860;
extern V8_0016D860 D_004A3008[2]; void func_0016E9B8_0016D860(O_0016D860 *) __asm__("func_0016E9B8"); void func_0016ED20_0016D860(O_0016D860 *, int) __asm__("func_0016ED20");
// MATCH func_0016D860
int darts_0016d860(O_0016D860 *o) { int n = o->w44 + 1; o->w44 = n; if (n == 1) return 10; if (n < 4) return 0; func_0016E9B8_0016D860(o); func_0016ED20_0016D860(o, 3); o->fn((char *)o + o->adj); o->v = D_004A3008[0]; return 0; }

extern int D_004A129C; extern char D_00440638[]; int func_002DCE40_0018CF98(char *, char *, ...) __asm__("func_002DCE40"); void func_00239568_0018CF98(char *) __asm__("func_00239568");
// MATCH func_0018CF98
void FUN_0018cf98(float *o) { char buf[128]; int s = D_004A129C; D_004A129C = 1; func_002DCE40_0018CF98(buf, D_00440638, (double)o[0], (double)o[1], (double)o[2], (double)o[3]); func_00239568_0018CF98(buf); D_004A129C = s; }

extern int D_004A129C_0018D0A8 __asm__("D_004A129C"); extern char D_00440658[]; int func_002DCE40_0018D0A8(char *, char *, ...) __asm__("func_002DCE40"); void func_00239568_0018D0A8(char *) __asm__("func_00239568");
// MATCH func_0018D0A8
void FUN_0018d0a8(float *o) { char buf[128]; int s = D_004A129C_0018D0A8; D_004A129C_0018D0A8 = 1; func_002DCE40_0018D0A8(buf, D_00440658, o, (double)o[0], (double)o[1], (double)o[2], (double)o[3]); func_00239568_0018D0A8(buf); D_004A129C_0018D0A8 = s; }

extern int D_004A129C_0023A258 __asm__("D_004A129C"); extern char D_0045C740[]; void func_00239568_0023A258(char *, ...) __asm__("func_00239568");
// MATCH func_0023A258
void FUN_0023a258(float *o) { int s = D_004A129C_0023A258; D_004A129C_0023A258 = 1; func_00239568_0023A258(D_0045C740, (double)o[0], (double)o[1], (double)o[2], (double)o[3]); D_004A129C_0023A258 = s; }

extern float D_004A0670; extern int D_004A14B8_00231E30 __asm__("D_004A14B8"); void func_0018E860(float *, float, float, float); void func_0018F3D8_00231E30(float *, float *, float *) __asm__("func_0018F3D8"); void func_0018DF68_00231E30(float *, float *) __asm__("func_0018DF68");
// MATCH func_00231E30
void FUN_00231e30(int a, int b, int c) { func_0018E860((float *)0x70003f00, a * D_004A0670, b * D_004A0670, c * D_004A0670); func_0018F3D8_00231E30((float *)0x70003f80, (float *)0x70003f80, (float *)0x70003f00); func_0018F3D8_00231E30((float *)0x70003c80, (float *)0x70003c80, (float *)0x70003f00); if (D_004A14B8_00231E30 != 0) { func_0018DF68_00231E30((float *)0x70003f40, (float *)0x70003f00); func_0018F3D8_00231E30((float *)0x70003d80, (float *)0x70003f40, (float *)0x70003d80); } }

extern float D_004A0820; extern int D_004A14B8_00248F38 __asm__("D_004A14B8"); void func_0018E680(float *, float, float, float); void func_0018F3D8_00248F38(float *, float *, float *) __asm__("func_0018F3D8"); void func_0018DF68_00248F38(float *, float *) __asm__("func_0018DF68");
// MATCH func_00248F38
void FUN_00248f38(int a, int b, int c) { func_0018E680((float *)0x70003f00, a * D_004A0820, b * D_004A0820, c * D_004A0820); func_0018F3D8_00248F38((float *)0x70003f80, (float *)0x70003f80, (float *)0x70003f00); func_0018F3D8_00248F38((float *)0x70003c80, (float *)0x70003c80, (float *)0x70003f00); if (D_004A14B8_00248F38 != 0) { func_0018DF68_00248F38((float *)0x70003f40, (float *)0x70003f00); func_0018F3D8_00248F38((float *)0x70003d80, (float *)0x70003f40, (float *)0x70003d80); } }

extern float D_004A0824; extern int D_004A14B8_00249558 __asm__("D_004A14B8"); void func_0018E860(float *, float, float, float); void func_0018F3D8_00249558(float *, float *, float *) __asm__("func_0018F3D8"); void func_0018DF68_00249558(float *, float *) __asm__("func_0018DF68");
// MATCH func_00249558
void FUN_00249558(int a, int b, int c) { func_0018E860((float *)0x70003f00, a * D_004A0824, b * D_004A0824, c * D_004A0824); func_0018F3D8_00249558((float *)0x70003f80, (float *)0x70003f80, (float *)0x70003f00); func_0018F3D8_00249558((float *)0x70003c80, (float *)0x70003c80, (float *)0x70003f00); if (D_004A14B8_00249558 != 0) { func_0018DF68_00249558((float *)0x70003f40, (float *)0x70003f00); func_0018F3D8_00249558((float *)0x70003d80, (float *)0x70003f40, (float *)0x70003d80); } }

typedef struct { char c[8]; } V8_00175940;
typedef struct { char p[336]; int w336, w340, w344; char p3[4]; int w352, w356, w360; char p2[8]; int w372; char p4[32]; V8_00175940 v; char pp[0]; } O_00175940;
extern unsigned long long D_004A12D8_00175940 __asm__("D_004A12D8");
extern char D_00336500[]; extern V8_00175940 D_004A32A8[2];  void func_001749D8_00175940(O_00175940 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void);
// MATCH func_00175940
int repetition_00175940(O_00175940 *o) { func_001749D8_00175940(o, D_00336500); o->w356 = 0; o->w360 = 0; if (o->w372++ & 0x20) o->w352 = 8; else o->w352 = 9; if (func_00172958() == 0 && func_00172978() == 0) o->v = D_004A32A8[0]; return 0; }

typedef struct { char c[8]; } V8_00175888;
typedef struct { char p[336]; int w336, w340, w344; char p3[4]; int w352, w356, w360; char p2[8]; int w372; char p4[32]; V8_00175888 v; char pp[0]; } O_00175888;
extern unsigned long long D_004A12D8_00175888 __asm__("D_004A12D8");
extern char D_003364F8[]; extern V8_00175888 D_004A32B0[2]; extern V8_00175888 D_004A32B8[2];  void func_001749D8_00175888(O_00175888 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void);
// MATCH func_00175888
int repetition_00175888(O_00175888 *o) { func_001749D8_00175888(o, D_003364F8); o->w356 = 0; o->w360 = 2; if (o->w372++ & 0x20) o->w352 = 64; else o->w352 = 66; if (func_00172958() != 0) o->v = D_004A32B0[0]; if (func_00172958() == 0 && func_00172978() == 2) o->v = D_004A32B8[0]; return 0; }

typedef struct { char c[8]; } V8_00175740;
typedef struct { char p[336]; int w336, w340, w344; char p3[4]; int w352, w356, w360; char p2[8]; int w372; char p4[32]; V8_00175740 v; char pp[0]; } O_00175740;
extern unsigned long long D_004A12D8_00175740 __asm__("D_004A12D8");
extern char D_003364E8[]; extern V8_00175740 D_004A32A0[2]; extern V8_00175740 D_004A32A8_00175740[2] __asm__("D_004A32A8");  void func_001749D8_00175740(O_00175740 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void);
// MATCH func_00175740
int repetition_00175740(O_00175740 *o) { func_001749D8_00175740(o, D_003364E8); o->w356 = 0; o->w360 = 0; if (o->w372++ & 0x20) o->w352 = 8; else o->w352 = 9; if (func_00172978() != 0) o->v = D_004A32A0[0]; if (func_00172958() == 0 && func_00172978() == 0) o->v = D_004A32A8_00175740[0]; return 0; }

typedef struct { char c[8]; } V8_00174B60;
typedef struct { char p[336]; int w336, w340, w344; char p3[4]; int w352, w356, w360; char p2[8]; int w372; char p4[32]; V8_00174B60 v; char pp[0]; } O_00174B60;
extern unsigned long long D_004A12D8_00174B60 __asm__("D_004A12D8");
extern char D_00336448[]; extern V8_00174B60 D_004A3200[2];  void func_001749D8_00174B60(O_00174B60 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void);
// MATCH func_00174B60
int repetition_00174b60(O_00174B60 *o) { func_001749D8_00174B60(o, D_00336448); if (o->w372++ & 0x20) o->w336 = 0; else o->w336 = 1; if (D_004A12D8_00174B60 & 0x200040) { o->w336 = 0; o->w340 = 2; o->w344 = 0; o->v = D_004A3200[0]; } return 0; }

typedef struct { char c[8]; } V8_001665C0;
typedef struct { char p[48]; short adj; short pad; void (*fn)(void *, int); } VT_001665C0;
typedef struct { char p0[24]; int w24; int w28; char p1[16]; VT_001665C0 *vt; int w52; int w56; int w60; char q[4]; V8_001665C0 v; } O_001665C0;
extern V8_001665C0 D_004A2D78[2]; void func_00164D10_001665C0(O_001665C0 *) __asm__("func_00164D10");
// MATCH func_001665C0
void pachislot_001665c0(O_001665C0 *o) { if (o->w60 == 0) { o->vt->fn((char *)o + o->vt->adj, 0); o->w24 = -o->w28; o->v = D_004A2D78[0]; func_00164D10_001665C0(o); } }

typedef struct { char c[8]; } V8_0016C720;
typedef struct { char p0[8]; int w8, w12, w16, w20, w24, w28; char p1[12]; int w44; char p2[8]; V8_0016C720 v; } O_0016C720;
extern V8_0016C720 D_004A2F60[2];
// MATCH func_0016C720
int FUN_0016c720(O_0016C720 *o) { o->w24++; o->w28++; o->w16 = 8 + ((o->w24 & 0x20) >> 5); o->w20 = 14; o->w8 += 6; o->w12 -= 6; if (--o->w44 <= 0) o->v = D_004A2F60[0]; return 0; }

typedef struct { char c[8]; } V8_0016C7A0;
typedef struct { int w0, w4, w8, w12, w16, w20, w24, w28; char p1[12]; int w44; char p2[8]; V8_0016C7A0 v; } O_0016C7A0;
extern V8_0016C7A0 D_004A2F60_0016C7A0[2] __asm__("D_004A2F60");
// MATCH func_0016C7A0
int FUN_0016c7a0(O_0016C7A0 *o) { o->w28++; o->w24++; o->w16 = 7; o->w20 = 15 + ((o->w28 & 0x20) >> 5); o->w0 -= 6; o->w4 -= 6; if (--o->w44 <= 0) o->v = D_004A2F60_0016C7A0[0]; return 0; }

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

int func_00167730(void *, void *, int);
// MATCH func_00168110
int pachislot_00168110(char *o, int b) { int r = 0; int i = 0; for (; i < 3; i++) { r = func_00167730(o, o + 124, i + b); if (r) break; } return r; }

int func_00167730(void *, void *, int);
// MATCH func_001681C8
int pachislot_001681c8(char *o, int b) { int r = 0; int i = 0; for (; i < 3; i++) { r = func_00167730(o, o + 204, i + b); if (r) break; } return r; }

extern float D_00419A70[][8];
// MATCH func_00285908
int FUN_00285908(char a, char b, int c) { return (int)(D_00419A70[(signed char)a][(signed char)b] * (float)c); }

extern float D_00419B70[][8];
// MATCH func_00285948
int FUN_00285948(char a, char b, int c) { return (int)(D_00419B70[(signed char)a][(signed char)b] * (float)c); }

extern char D_004A380A_001E40A8 __asm__("D_004A380A"); int func_001E3CD8(int); void func_001E3E38(int, int, int); void func_001E3380(int, int, int);
// MATCH func_001E40A8
int FUN_001e40a8(int a, int b, int c) { int r; if (D_004A380A_001E40A8 == 0) return 0; r = func_001E3CD8(a); if (r == 0) return 0; func_001E3E38(a, r, c); func_001E3380(a, r, 0); return r; }

extern char D_004A380A_001E4120 __asm__("D_004A380A"); int func_001E3D98(int); void func_001E3E38(int, int, int); void func_001E3380(int, int, int);
// MATCH func_001E4120
int FUN_001e4120(int a, int b, int x, int c) { int r; if (D_004A380A_001E4120 == 0) return 0; r = func_001E3D98(a); if (r == 0) return 0; func_001E3E38(a, r, c); func_001E3380(a, r, 0); return r; }

extern void *D_004A445C; void *func_001F7308(void *); int func_001F7318(void *); int func_001F7410(void *, int);
// MATCH func_001FDBE0
int eftedit_001fdbe0(int a, int b) { void *p = D_004A445C; while (func_001F7318(p) != a) { p = func_001F7308(p); if (p == 0) return 0; } return func_001F7410(p, b); }

extern void *D_004A445C_001FDB68 __asm__("D_004A445C"); void *func_001F7308(void *); int func_001F7318(void *); float func_001F7358(void *, int);
// MATCH func_001FDB68
float eftedit_001fdb68(int a, int b) { void *p = D_004A445C_001FDB68; while (func_001F7318(p) != a) { p = func_001F7308(p); if (p == 0) return 0.0f; } return func_001F7358(p, b); }

typedef struct { char p[176]; void *w176; } O_001F7410;
int func_001F6080(void *); void *func_001F60A8(void *);
// MATCH func_001F7410
void *ikumin_001f7410(O_001F7410 *o, int b) { void *p = o->w176; while (func_001F6080(p) != b) { p = func_001F60A8(p); if (p == 0) return 0; } return p; }

typedef struct { char c[8]; } V8_00174E10;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_00174E10 v, v2; } O_00174E10;
extern unsigned long long D_004A12D8_00174E10 __asm__("D_004A12D8");
extern char D_00336470[]; extern V8_00174E10 D_004A31C8[2]; extern V8_00174E10 D_004A3228[2];  void func_001749D8_00174E10(O_00174E10 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void); void func_00172D98(O_00174E10 *);
// MATCH func_00174E10
int repetition_00174e10(O_00174E10 *o) { func_001749D8_00174E10(o, D_00336470); o->w356 = 2; o->w360 = 2; if (o->w372++ & 0x20) o->w352 = 256; else o->w352 = 258; if (D_004A12D8_00174E10 & 0x200040) { func_00172D98(o); o->v = D_004A31C8[0]; o->v2 = D_004A3228[0]; o->w352 = 0; } return 0; }

typedef struct { char c[8]; } V8_001750D8;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_001750D8 v, v2; } O_001750D8;
extern unsigned long long D_004A12D8_001750D8 __asm__("D_004A12D8");
extern char D_00336498[]; extern V8_001750D8 D_004A31C8_001750D8[2] __asm__("D_004A31C8"); extern V8_001750D8 D_004A3250[2];  void func_001749D8_001750D8(O_001750D8 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void); void func_00172D98_001750D8(O_001750D8 *) __asm__("func_00172D98");
// MATCH func_001750D8
int repetition_001750d8(O_001750D8 *o) { func_001749D8_001750D8(o, D_00336498); o->w356 = 2; o->w360 = 2; if (o->w372++ & 0x20) o->w352 = 4; else o->w352 = 5; if (D_004A12D8_001750D8 & 0x200040) { func_00172D98_001750D8(o); o->v = D_004A31C8_001750D8[0]; o->v2 = D_004A3250[0]; o->w352 = 0; } return 0; }

typedef struct { char c[8]; } V8_00175578;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_00175578 v, v2; } O_00175578;
extern unsigned long long D_004A12D8_00175578 __asm__("D_004A12D8");
extern char D_003364D0[]; extern V8_00175578 D_004A31C8_00175578[2] __asm__("D_004A31C8"); extern V8_00175578 D_004A3288[2];  void func_001749D8_00175578(O_00175578 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void); void func_00172D98_00175578(O_00175578 *) __asm__("func_00172D98");
// MATCH func_00175578
int repetition_00175578(O_00175578 *o) { func_001749D8_00175578(o, D_003364D0); o->w356 = 2; o->w360 = 2; if (o->w372++ & 0x20) o->w352 = 256; else o->w352 = 258; { int r = func_00172958(); if (r == 2 && func_00172978() == r) { func_00172D98_00175578(o); o->v = D_004A31C8_00175578[0]; o->v2 = D_004A3288[0]; o->w352 = 0; } } return 0; }

typedef struct { char c[8]; } V8_001759D0;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_001759D0 v, v2; } O_001759D0;
extern unsigned long long D_004A12D8_001759D0 __asm__("D_004A12D8");
extern char D_00336508[]; extern V8_001759D0 D_004A31C8_001759D0[2] __asm__("D_004A31C8"); extern V8_001759D0 D_004A32C0[2];  void func_001749D8_001759D0(O_001759D0 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void); void func_00172D98_001759D0(O_001759D0 *) __asm__("func_00172D98");
// MATCH func_001759D0
int repetition_001759d0(O_001759D0 *o) { func_001749D8_001759D0(o, D_00336508); o->w356 = 2; o->w360 = 2; if (o->w372++ & 0x20) o->w352 = 4; else o->w352 = 5; { int r = func_00172958(); if (r == 2 && func_00172978() == r) { func_00172D98_001759D0(o); o->v = D_004A31C8_001759D0[0]; o->v2 = D_004A32C0[0]; o->w352 = 0; } } return 0; }

typedef struct { char c[8]; } V8_001752A0;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_001752A0 v, v2; } O_001752A0;
extern unsigned long long D_004A12D8_001752A0 __asm__("D_004A12D8");
extern char D_003364B0[]; extern V8_001752A0 D_004A3268[2]; extern V8_001752A0 D_004A3270_001752A0[2] __asm__("D_004A3270");  void func_001749D8_001752A0(O_001752A0 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void); void func_00172D98_001752A0(O_001752A0 *) __asm__("func_00172D98");
// MATCH func_001752A0
int repetition_001752a0(O_001752A0 *o) { func_001749D8_001752A0(o, D_003364B0); o->w356 = 4; o->w360 = 4; if (o->w372++ & 0x20) o->w352 = 512; else o->w352 = 514; if (func_00172958() != 4) o->v = D_004A3268[0]; { int r = func_00172958(); if (r == 4 && func_00172978() == r) o->v = D_004A3270_001752A0[0]; } return 0; }

typedef struct { char c[8]; } V8_00175410;
typedef struct { char p[352]; int w352, w356, w360; char p2[8]; int w372; char q[32]; V8_00175410 v, v2; } O_00175410;
extern unsigned long long D_004A12D8_00175410 __asm__("D_004A12D8");
extern char D_003364C0[]; extern V8_00175410 D_004A3278[2]; extern V8_00175410 D_004A3280[2];  void func_001749D8_00175410(O_00175410 *, char *) __asm__("func_001749D8"); int func_00172958(void); int func_00172978(void); void func_00172D98_00175410(O_00175410 *) __asm__("func_00172D98");
// MATCH func_00175410
int repetition_00175410(O_00175410 *o) { func_001749D8_00175410(o, D_003364C0); o->w356 = 2; o->w360 = 4; if (o->w372++ & 0x20) o->w352 = 16; else o->w352 = 17; if (func_00172978() != 4) o->v = D_004A3278[0]; if (func_00172958() == 2 && func_00172978() == 4) o->v = D_004A3280[0]; return 0; }

typedef struct { char c[8]; } V8_001743F0;
typedef struct { char p[64]; short adj; short pad; int (*fn)(void *); } VT_001743F0;
typedef struct { char p[408]; V8_001743F0 v, v2; char q[456]; float f880, f884; char r[8]; VT_001743F0 *vt; } O_001743F0;
extern char D_0041EFB0_001743F0[] __asm__("D_0041EFB0"); void func_001545A8(char *, char *, char *, float);
// MATCH func_001743F0
int repetition_001743f0(O_001743F0 *o) { o->f880 += o->f884; if (o->f880 >= 1.0f) { o->f880 = 1.0f; o->v = o->v2; } func_001545A8(D_0041EFB0_001743F0, (char *)o + 432, (char *)o + 656, o->f880); return 0; }

typedef struct { char c[8]; } V8_001744B0;
typedef struct { char p[64]; short adj; short pad; int (*fn)(void *); } VT_001744B0;
typedef struct { char p[408]; V8_001744B0 v, v2; char q[456]; float f880, f884; char r[8]; VT_001744B0 *vt; } O_001744B0;
extern char D_0041EFB0_001744B0[] __asm__("D_0041EFB0"); void func_001545A8(char *, char *, char *, float);
// MATCH func_001744B0
int repetition_001744b0(O_001744B0 *o) { o->f880 += o->f884; if (o->f880 >= 1.0f) o->f880 = 1.0f; if (o->f880 == 1.0f) { if (o->vt->fn((char *)o + o->vt->adj)) o->v = o->v2; } func_001545A8(D_0041EFB0_001744B0, (char *)o + 432, (char *)o + 656, o->f880); return 0; }

extern int D_004A3850_0018B3A8 __asm__("D_004A3850"); extern char D_00440230[]; extern char D_00440248[]; extern char D_00440260[]; extern char D_00440280[]; extern char D_004402A0[]; void func_001118F8_0018B3A8(char *, char *) __asm__("func_001118F8"); void func_0018A658(char *, char *); int func_0018ABF0(char *, int); int func_0018AF40(char *, int); int func_0018A918(char *, int);
// MATCH func_0018B3A8
int MallocLoadFileNB(char *name, int b) { char buf[256]; int r = 0; switch (D_004A3850_0018B3A8) { case 0: func_001118F8_0018B3A8(D_00440230, name); r = func_0018A918(name, b); break; case 1: func_001118F8_0018B3A8(D_00440248, name); func_0018A658(name, buf); r = func_0018ABF0(buf, b); break; case 2: func_001118F8_0018B3A8(D_00440260, name); func_0018A658(name, buf); r = func_0018AF40(buf, b); break; case 3: func_001118F8_0018B3A8(D_00440248, name); func_0018A658(name, buf); r = func_0018ABF0(buf, b); if (r == 0) r = func_0018A918(buf, b); break; default: func_001118F8_0018B3A8(D_00440280, name); break; } if (r == 0) func_001118F8_0018B3A8(D_004402A0, name); return r; }

extern int D_004A3850_0018B508 __asm__("D_004A3850"); extern char D_004402C0[]; extern char D_004402D8[]; extern char D_00440300[]; extern char D_00440318[]; extern char D_00440330[]; extern char D_00440350[]; void func_001118F8_0018B508(char *, char *) __asm__("func_001118F8"); void func_0018A658(char *, char *); int func_0018AAF0(char *, int); int func_0018AE28(char *, int); int func_0018A828(char *, int);
// MATCH func_0018B508
int FUN_0018b508(char *name, int b) { char buf[256]; int r = 0; switch (D_004A3850_0018B508) { case 0: func_001118F8_0018B508(D_004402C0, name); r = func_0018A828(name, b); break; case 1: func_001118F8_0018B508(D_004402D8, name); func_0018A658(name, buf); r = func_0018AAF0(buf, b); break; case 2: func_001118F8_0018B508(D_00440300, name); func_0018A658(name, buf); r = func_0018AE28(buf, b); break; case 3: func_001118F8_0018B508(D_00440318, name); func_0018A658(name, buf); r = func_0018AAF0(buf, b); if (r == 0) r = func_0018A828(buf, b); break; default: func_001118F8_0018B508(D_00440330, name); break; } if (r == 0) func_001118F8_0018B508(D_00440350, name); return r; }

extern int D_004A3850_0018B668 __asm__("D_004A3850"); extern char D_00440370[]; extern char D_00440388[]; extern char D_004403A0[]; extern char D_004403B8[]; extern char D_004403D0[]; void func_001118F8_0018B668(char *, char *) __asm__("func_001118F8"); void func_0018A658(char *, char *); int func_0018AD80(char *, int); int func_0018B0F0(char *, int); int func_0018AAB0(char *, int);
// MATCH func_0018B668
int FUN_0018b668(char *name, int b) { char buf[256]; int r = -1; switch (D_004A3850_0018B668) { case 0: func_001118F8_0018B668(D_00440370, name); r = func_0018AAB0(name, b); break; case 1: func_001118F8_0018B668(D_00440388, name); func_0018A658(name, buf); r = func_0018AD80(buf, b); break; case 2: func_001118F8_0018B668(D_004403A0, name); func_0018A658(name, buf); r = func_0018B0F0(buf, b); break; case 3: func_001118F8_0018B668(D_00440388, name); func_0018A658(name, buf); r = func_0018AD80(buf, b); if (r < 0) r = func_0018AAB0(buf, b); break; default: func_001118F8_0018B668(D_004403B8, name); break; } if (r < 0) func_001118F8_0018B668(D_004403D0, name); return r; }

extern int D_004A3850_0018B7C8 __asm__("D_004A3850"); extern char D_004403E8[]; extern char D_004403F8[]; extern char D_00440420[]; extern char D_00440438[]; extern char D_00440448[]; extern char D_00440460[]; void func_001118F8_0018B7C8(char *, char *) __asm__("func_001118F8"); void func_0018A658(char *, char *); int func_0018ACF0(char *, int); int func_0018B020(char *, int); int func_0018AA00(char *, int);
// MATCH func_0018B7C8
int LoadFile(char *name, int b) { char buf[256]; int r = -1; switch (D_004A3850_0018B7C8) { case 0: func_001118F8_0018B7C8(D_004403E8, name); r = func_0018AA00(name, b); break; case 1: func_001118F8_0018B7C8(D_004403F8, name); func_0018A658(name, buf); r = func_0018ACF0(buf, b); break; case 2: func_001118F8_0018B7C8(D_00440420, name); func_0018A658(name, buf); r = func_0018B020(buf, b); break; case 3: func_001118F8_0018B7C8(D_00440438, name); func_0018A658(name, buf); r = func_0018ACF0(buf, b); if (r < 0) r = func_0018AA00(buf, b); break; default: func_001118F8_0018B7C8(D_00440448, name); break; } if (r < 0) func_001118F8_0018B7C8(D_00440460, name); return r; }

int func_00167940(char *, int, int, int); int func_00167DD0(char *, int);
// MATCH func_00167FC0
int pachislot_00167fc0(char *o, int b) { int r = 0; int a = func_00167940(o, b, 0, 0); int s = func_00167DD0(o, b); if (a == 1 || s == 1) r = 1; else if (a == 3 || s == 3) r = 3; else if (a == 2 || s == 2) r = 2; return r; }

int func_00167B88(char *, int, int, int); int func_00167DD0(char *, int);
// MATCH func_00168068
int pachislot_00168068(char *o, int b) { int r = 0; int a = func_00167B88(o, b, 0, 0); int s = func_00167DD0(o, b); if (a == 1 || s == 1) r = 1; else if (a == 3 || s == 3) r = 3; else if (a == 2 || s == 2) r = 2; return r; }

typedef struct { char c[8]; } V8_0016CFB8;
typedef struct { char p[104]; V8_0016CFB8 v, v2; char q[456]; float f576, f580; } O_0016CFB8;
extern char D_0041EFB0_0016CFB8[] __asm__("D_0041EFB0"); void func_0016E510_0016CFB8(O_0016CFB8 *) __asm__("func_0016E510"); void func_001545A8(char *, char *, char *, float);
// MATCH func_0016CFB8
int darts_0016cfb8(O_0016CFB8 *o) { func_0016E510_0016CFB8(o); o->f576 += o->f580; if (o->f576 >= 1.0f) { o->f576 = 1.0f; o->v = o->v2; } func_001545A8(D_0041EFB0_0016CFB8, (char *)o + 128, (char *)o + 352, o->f576); return 0; }

typedef struct { char c[8]; } V8_0016C820;
typedef struct { int w0, w4, w8, w12, w16, w20, w24, w28; char p1[24]; V8_0016C820 v; } O_0016C820;
extern V8_0016C820 D_004A2F68_0016C820[2] __asm__("D_004A2F68");
// MATCH func_0016C820
int FUN_0016c820(O_0016C820 *o) { o->w24++; o->w28++; o->w16 = 7; o->w20 = 14; o->w0 -= 6; o->w4 -= 6; o->w8 += 6; o->w12 -= 6; if (o->w0 < -48 || o->w4 < -24) o->v = D_004A2F68_0016C820[0]; return 0; }

typedef struct { char c[8]; } V8_00175C48;
typedef struct { char p[340]; int w340, w344, w348; char p2[56]; V8_00175C48 v; V8_00175C48 v2; char q[464]; V8_00175C48 v3; } O_00175C48;
extern unsigned long long D_004A12D8_00175C48 __asm__("D_004A12D8"); extern char D_00336520[]; extern V8_00175C48 D_004A32D8[2], D_004A31C8_00175C48[2] __asm__("D_004A31C8"), D_004A32E0[2]; void func_001749D8_00175C48(O_00175C48 *, char *) __asm__("func_001749D8"); void func_00172C30(O_00175C48 *); void func_00172CA0(O_00175C48 *);
// MATCH func_00175C48
int repetition_00175c48(O_00175C48 *o) { func_001749D8_00175C48(o, D_00336520); if (D_004A12D8_00175C48 & 0x200040) { o->w348 = 1; o->w340 = 0; o->w344 = 0; func_00172C30(o); func_00172CA0(o); o->v3 = D_004A32D8[0]; o->v = D_004A31C8_00175C48[0]; o->v2 = D_004A32E0[0]; } return 0; }

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

typedef struct { char p[332]; char *w332; int w336; char q[8]; int w348, w352, w356, w360; } O_001739F8;
extern char D_0043DFD8_001739F8[] __asm__("D_0043DFD8"); void func_00172998(O_001739F8 *, int, int); void func_00173AC0(O_001739F8 *);
// MATCH func_001739F8
O_001739F8 *FUN_001739f8(O_001739F8 *o, int x, int c, int d) { func_00172998(o, x, 0); o->w332 = D_0043DFD8_001739F8; o->w336 = d; o->w348 = c != 5 ? 5 : 0; o->w352 = 0; o->w356 = 0; o->w360 = 0; func_00173AC0(o); return o; }

typedef struct { char c[8]; } V8_0016C1D8;
typedef struct { int w0, w4, w8, w12, w16, w20, w24, w28; char p[24]; V8_0016C1D8 v; } O_0016C1D8;
extern V8_0016C1D8 D_004A2F38_0016C1D8[2] __asm__("D_004A2F38");
// MATCH func_0016C1D8
int pachislot_0016c1d8(O_0016C1D8 *o) { o->w4 += 3; o->w12 += 3; o->w16 = 3; o->w20 = 10; if (o->w4 >= 144) { o->w24 = 0; o->w4 = 144; o->w12 = 144; o->w28 = 0; o->v = D_004A2F38_0016C1D8[0]; } return 0; }

typedef struct { char c[8]; } V8_001708B8;
typedef struct { char p[96]; int w96; char q[36]; V8_001708B8 v; } O_001708B8;
extern unsigned long long D_004A12D8_001708B8 __asm__("D_004A12D8"); extern V8_001708B8 D_004A30B8[2];
// MATCH func_001708B8
int roulette_001708b8(O_001708B8 *o) { if (++o->w96 >= 61 || (D_004A12D8_001708B8 & 0x200040)) { o->v = D_004A30B8[0]; return 1; } return 0; }

typedef struct { char c[8]; } V8_0016E118;
typedef struct { char p[44]; int w44; char q[56]; V8_0016E118 v; } O_0016E118;
extern unsigned long long D_004A12D8_0016E118 __asm__("D_004A12D8"); extern V8_0016E118 D_004A3028[2]; int func_001646E8(char *);
// MATCH func_0016E118
int darts_0016e118(O_0016E118 *o) { if (func_001646E8((char *)o + 52) != 0) return 0; if (++o->w44 >= 51 || (D_004A12D8_0016E118 & 0x200040)) { o->v = D_004A3028[0]; return 1; } return 0; }

typedef struct { char p[88]; int w88; } O_00170548;
extern int D_004A3070_00170548 __asm__("D_004A3070"); extern int D_003355F8_00170548[] __asm__("D_003355F8"); int func_00170B50_00170548(O_00170548 *) __asm__("func_00170B50");
// MATCH func_00170548
int roulette_00170548(O_00170548 *o, int b) { int k = func_00170B50_00170548(o); int r; if (o->w88 != 0) r = D_004A3070_00170548 == D_003355F8_00170548[k]; else r = b == k; return r; }

typedef struct { char c[8]; } V8_00169308;
typedef struct { char p[468]; int w468; char q[8]; int w480; char q2[4]; int w488; char q3[4]; int w496; char q4[44]; V8_00169308 v; } O_00169308;
extern V8_00169308 D_004A2E60[2]; void func_00168AB8_00169308(O_00169308 *) __asm__("func_00168AB8"); void func_001649C8(char *);
// MATCH func_00169308
int pachislot_00169308(O_00169308 *o) { func_00168AB8_00169308(o); func_001649C8((char *)o + 44); func_001649C8((char *)o + 124); func_001649C8((char *)o + 204); o->w468 = 0; o->w496 = -1; o->w480 = 0; o->w488 = 0; o->v = D_004A2E60[0]; return 0; }

typedef struct { char p[40]; int w40; char q[16]; char *w60; int w64; char r[52]; int w120; } O_00171EE8;
extern char D_0043D658[]; int func_001714A0(O_00171EE8 *); void func_00171980(O_00171EE8 *, int); void func_00171FF8(O_00171EE8 *, int);
// MATCH func_00171EE8
O_00171EE8 *roulette_00171ee8(O_00171EE8 *o, int x) { func_001714A0(o); o->w60 = D_0043D658; o->w64 = 250; func_00171980(o, 1); func_00171FF8(o, x); o->w40 = 0; o->w120 = 0; return o; }

typedef struct { char p[16]; unsigned long long *w16; } S_00164BB0;
extern S_00164BB0 D_00342CD0_00164BB0 __asm__("D_00342CD0"); extern unsigned long long D_00318680[]; void func_00190328(S_00164BB0 *); void func_00190420(S_00164BB0 *);
// MATCH func_00164BB0
void pachislot_00164bb0(void) { unsigned long long *p; func_00190328(&D_00342CD0_00164BB0); p = D_00342CD0_00164BB0.w16; p[0] = 5; p[1] = 8; D_00342CD0_00164BB0.w16 = p + 4; p[2] = D_00318680[0]; p[3] = 66; func_00190420(&D_00342CD0_00164BB0); }

typedef struct { char p[16]; unsigned long long *w16; } S_0015A6D0;
extern S_0015A6D0 D_00342CD0_0015A6D0 __asm__("D_00342CD0"); typedef struct { int w0; } O_0015A6D0; void func_00190328_0015A6D0(S_0015A6D0 *) __asm__("func_00190328"); void func_00190420_0015A6D0(S_0015A6D0 *) __asm__("func_00190420"); void func_001588F8(int);
// MATCH func_0015A6D0
void FUN_0015a6d0(O_0015A6D0 *o) { unsigned long long *p; func_00190328_0015A6D0(&D_00342CD0_0015A6D0); p = D_00342CD0_0015A6D0.w16; p[0] = 5; p[1] = 8; D_00342CD0_0015A6D0.w16 = p + 2; func_00190420_0015A6D0(&D_00342CD0_0015A6D0); func_001588F8(o->w0); }

typedef struct { char p[16]; unsigned long long *w16; } S_0024C568;
void func_0024BF60(int, int, int, int, S_0024C568 *, int); void func_00190328_0024C568(S_0024C568 *) __asm__("func_00190328"); void func_00190420_0024C568(S_0024C568 *) __asm__("func_00190420");
// MATCH func_0024C568
int init_0024c568(int a, int b, int c, int d, S_0024C568 *s) { unsigned long long *p; func_0024BF60(a, b, c, d, s, 0); func_00190328_0024C568(s); p = s->w16; p[0] = 0; p[1] = 63; s->w16 = p + 2; func_00190420_0024C568(s); return 0; }

typedef struct { char p[16]; unsigned long long *w16; } S_00243A68;
extern unsigned long long D_00318680_00243A68[] __asm__("D_00318680"); void func_00190328_00243A68(S_00243A68 *) __asm__("func_00190328"); void func_00190420_00243A68(S_00243A68 *) __asm__("func_00190420");
// MATCH func_00243A68
void object_00243a68(int i, S_00243A68 *s) { unsigned long long *p; func_00190328_00243A68(s); p = s->w16; p[0] = D_00318680_00243A68[i]; p[1] = 66; s->w16 = p + 2; func_00190420_00243A68(s); }

typedef struct { char p[16]; unsigned long long *w16; } S_00243688;
extern S_00243688 D_00314C20; extern unsigned D_004A71E4_00243688 __asm__("D_004A71E4"); void func_00190328_00243688(S_00243688 *) __asm__("func_00190328"); void func_00190420_00243688(S_00243688 *) __asm__("func_00190420");
// MATCH func_00243688
void object_00243688(void) { unsigned long long *p; func_00190328_00243688(&D_00314C20); p = D_00314C20.w16; p[0] = 0x2007ff8621343140ULL; p[1] = 6; D_00314C20.w16 = p + 2; D_004A71E4_00243688 = 0xffffffff; func_00190420_00243688(&D_00314C20); }

typedef struct { char pad[16]; short adj; short p; int (*fn)(void *); } VT_00164608;
typedef struct N_00164608 { char pad[92]; struct N_00164608 *next; char pad2[8]; VT_00164608 *vt; } N_00164608;
typedef struct { N_00164608 *head; } S_00164608;
// MATCH func_00164608
void FUN_00164608(S_00164608 *s) { N_00164608 *n = s->head->next; while (n != s->head) { N_00164608 *nx; nx = n->next; n->vt->fn((char *)n + n->vt->adj); n = nx; } }

typedef struct { char p[8]; short adj; short pad; void (*fn)(void *, int *); } VT_0010F310;
typedef struct { char p0[8]; int *w8; char p1[12]; VT_0010F310 *vt; } O_0010F310;
// MATCH func_0010F310
void FUN_0010f310(O_0010F310 *o) { int *p = o->w8; p[0] = 0x10000000; p[3] = 0x13000000; p[1] = 0; p[2] = 0; o->w8 = p + 4; o->vt->fn((char *)o + o->vt->adj, p + 4); }

extern char D_003D7058_00245590[] __asm__("D_003D7058"), D_005F75B8[]; extern void (*D_004A1478_00245590)(int) __asm__("D_004A1478"); int func_00245518(char *, char *);
// MATCH func_00245590
int FUN_00245590(void) { int r = func_00245518(D_003D7058_00245590, D_005F75B8); if (r == 1) D_004A1478_00245590(4); if (r == 2) D_004A1478_00245590(2); return r; }

typedef struct { char p[56]; short adj; short pad; void (*fn)(void *, void *, int, int); } VT_00219EE8;
typedef struct { char p[2116]; VT_00219EE8 *vt; } G_00219EE8;
typedef struct { char p[172]; short h172; } O_00219EE8;
extern G_00219EE8 *D_004A1A3C_00219EE8 __asm__("D_004A1A3C"); int func_00127430(void); void func_00226B28(G_00219EE8 *, O_00219EE8 *, int, int);
// MATCH func_00219EE8
void FUN_00219ee8(O_00219EE8 *o, int x) { if (func_00127430() != 0) { G_00219EE8 *g = D_004A1A3C_00219EE8; g->vt->fn((char *)g + g->vt->adj, o, o->h172, x); func_00226B28(D_004A1A3C_00219EE8, o, o->h172, x); } }

typedef struct { char p[8]; short adj; short pad; void (*fn)(void *, int); } VT_002479F0;
typedef struct { char p[8]; int w8; char q[12]; VT_002479F0 *vt; } G_002479F0;
extern G_002479F0 *D_004A1524; extern int D_004A1540; extern int D_004A152C; void func_00190420_002479F0(G_002479F0 *) __asm__("func_00190420");
// MATCH func_002479F0
void FUN_002479f0(void) { func_00190420_002479F0(D_004A1524); if (D_004A1540 == 0) { G_002479F0 *g = D_004A1524; int v = D_004A152C; g->w8 = v; g->vt->fn((char *)g + g->vt->adj, v); } }

typedef struct { char p[16]; int a; int b; } R_x_002E2BC8;
void *func_002E2748(int, int);
// MATCH func_002E2BC8
void * FUN_002e2bc8(int a, int b) { R_x_002E2BC8 *r = (R_x_002E2BC8 *)func_002E2748(a, 1); r->b = b; r->a = 1; return r; }

typedef struct { char c[8]; } V8_00169CE8;
typedef struct { char p[464]; int w464; char q[76]; V8_00169CE8 v; V8_00169CE8 v2; } O_00169CE8;
extern V8_00169CE8 D_004A2EB0[2]; int func_00166638_00169CE8(char *) __asm__("func_00166638"); int func_00167070(char *);
// MATCH func_00169CE8
int pachislot_00169ce8(O_00169CE8 *o) { if (func_00166638_00169CE8((char *)o + 284)) { if (func_00167070((char *)o + 8) == -1) o->v = o->v2; else { o->w464 = 30; o->v = D_004A2EB0[0]; } } return 0; }

typedef struct { char p[72]; short h72, h74; int w76; int w80; int w84; int w88; } O_00170B50;
// MATCH func_00170B50
int roulette_00170b50(O_00170B50 *o) { int x = o->h74; if (x != 0) x = o->w80 - x; if (o->w88 != 0) x += (x < o->w80 / 2) ? 1 : 2; return x; }

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

extern char D_0045DCF8[]; int func_001618C8(void); int func_001118F8_0024ABE0(char *, char *, int) __asm__("func_001118F8");
// MATCH func_0024ABE0
int DbgPrintFreeMem(char *name) { int r = func_001618C8(); func_001118F8_0024ABE0(D_0045DCF8, name, r / 1024); return r; }

extern char D_00455908[]; void *func_00162130_00214200(int, char *, int) __asm__("func_00162130"); void *func_00214160(void *); int func_00214278(void *, void *); void func_002141B0(void *, int);
// MATCH func_00214200
void *titlemode_00214200(void *a) { void *r = func_00214160(func_00162130_00214200(52, D_00455908, 472)); if (r != 0) { if (func_00214278(r, a) == 0) { func_002141B0(r, 3); r = 0; } } return r; }

extern void *D_004A445C_001FDC50 __asm__("D_004A445C"); void *func_001F7308(void *); int func_001F7318(void *); void func_001F74A0(void *, int, float);
// MATCH func_001FDC50
void eftedit_001fdc50(int a, int b, float c) { void *p = D_004A445C_001FDC50; while (func_001F7318(p) != a) { p = func_001F7308(p); if (p == 0) return; } func_001F74A0(p, b, c); }

void func_0018C4C8_0018C518(int, int) __asm__("func_0018C4C8"); int func_0018B508_0018C518(int, char *) __asm__("func_0018B508"); void func_0018CA90_0018C518(int, int) __asm__("func_0018CA90"); void func_001621F8_0018C518(int, char *, int) __asm__("func_001621F8");
extern char D_00440540[];
// MATCH func_0018C518
int denlib_0018c518(int a, int b) { char buf[16]; int r; func_0018C4C8_0018C518(a, b); r = func_0018B508_0018C518(b, buf); if (r == 0) return 0; func_0018CA90_0018C518(a, r); func_001621F8_0018C518(r, D_00440540, 947); return 1; }

typedef struct { char c[8]; } V8_001662C0;
typedef struct { char p[24]; int w24; char q[40]; V8_001662C0 v; } O_001662C0;
extern V8_001662C0 D_004A2CF8_001662C0[2] __asm__("D_004A2CF8"); int func_00164A00_001662C0(void) __asm__("func_00164A00");
// MATCH func_001662C0
void pachislot_001662c0(O_001662C0 *o) { if (func_00164A00_001662C0() != 0) { o->w24 = 0; o->v = D_004A2CF8_001662C0[0]; } else { o->w24 -= 32; if (o->w24 < 1024) o->w24 = 1024; } }

typedef struct { char c[8]; } V8_00174780;
typedef struct { char p[32]; short adj; short pad; void (*fn)(void *); } VT_00174780;
typedef struct { char p[408]; V8_00174780 v; char q[480]; VT_00174780 *vt; } O_00174780;
extern V8_00174780 D_004A31C8_00174780[2] __asm__("D_004A31C8"); extern char D_00343028_00174780[] __asm__("D_00343028"); void func_00172CA0_00174780(O_00174780 *) __asm__("func_00172CA0"); void func_0010C2B0(char *, int, int, int, int, int, int);
// MATCH func_00174780
int repetition_00174780(O_00174780 *o) { func_00172CA0_00174780(o); o->v = D_004A31C8_00174780[0]; o->vt->fn((char *)o + o->vt->adj); func_0010C2B0(D_00343028_00174780, 142, 6, 0, 6, 0, 0); return 2; }

extern int D_004A3850_0018B2F8 __asm__("D_004A3850"); int func_0018B250(int);
// MATCH func_0018B2F8
int FUN_0018b2f8(int a) { int r = -1; if (D_004A3850_0018B2F8 != 0) { if (D_004A3850_0018B2F8 >= 0) { if (D_004A3850_0018B2F8 < 4) r = func_0018B250(a); } } return r; }

typedef struct { char c[8]; } V8_00176A48;
typedef struct { char p[32]; short adj; short pad; void (*fn)(void *); } VT_00176A48;
typedef struct { char p[408]; V8_00176A48 v; char q[480]; VT_00176A48 *vt; } O_00176A48;
extern V8_00176A48 D_004A31C8_00176A48[2] __asm__("D_004A31C8"); extern char D_00343028_00176A48[] __asm__("D_00343028"); void func_00172CA0_00176A48(void *) __asm__("func_00172CA0"); void func_0010C2B0(char *, int, int, int, int, int, int);
// MATCH func_00176A48
int repetition_00176a48(O_00176A48 *o) { func_00172CA0_00176A48(o); func_00172CA0_00176A48((char *)o + 912); o->v = D_004A31C8_00176A48[0]; o->vt->fn((char *)o + o->vt->adj); func_0010C2B0(D_00343028_00176A48, 142, 6, 0, 6, 0, 0); return 2; }

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

typedef struct { char p[100]; void *w100; } Q_001DFA00;
typedef struct { char p[16]; short adj; short pad; void (*fn)(void *); } VT_001DFA00;
typedef struct { char p[100]; VT_001DFA00 *vt; } P_001DFA00;
typedef struct { char p[304]; P_001DFA00 *w304; char q[252]; int w560; } S_001DFA00;
extern S_001DFA00 D_003B0BD0; void func_001E2530(P_001DFA00 *); void func_001E06C0(P_001DFA00 *, int);
// MATCH func_001DFA00
int FUN_001dfa00(int a) { S_001DFA00 *s = &D_003B0BD0; P_001DFA00 *p; if (s->w560 != 2) return -1; p = s->w304; func_001E2530(p); func_001E06C0(p, a); p->vt->fn((char *)p + p->vt->adj); return 1; }

typedef struct { char p[32]; float f32, f36, f40; char q[20]; float f64, f68, f72; } E_0021B550;
typedef struct { char p[4800]; E_0021B550 *w4800; } O_0021B550;
void func_00249108(O_0021B550 *); void func_00249390(void); void func_00249100(float, float, float); void func_00248E00(float, float, float); void func_002489F0(void); void func_002464A8(E_0021B550 *); void func_002491D8(void);
// MATCH func_0021B550
void FUN_0021b550(O_0021B550 *o) { func_00249108(o); func_00249390(); func_00249100(o->w4800->f32, o->w4800->f36, o->w4800->f40); func_00248E00(o->w4800->f64, o->w4800->f68, o->w4800->f72); func_002489F0(); func_002464A8(o->w4800); func_002491D8(); }

extern char D_004A380A_001E3F20 __asm__("D_004A380A"); extern int D_004A3864_001E3F20 __asm__("D_004A3864"); extern char D_0044B978[]; void func_001118F8_001E3F20(char *) __asm__("func_001118F8"); void func_001322C0(void *, int, int);
// MATCH func_001E3F20
void FUN_001e3f20(int a, void *p) { if (D_004A380A_001E3F20 != 0) { if (D_004A3864_001E3F20 & 0x200) func_001118F8_001E3F20(D_0044B978); if (p != 0) func_001322C0(p, -1, 1); } }

typedef struct { int w0; char p[16]; float f20, f24; int w28, w32; char q[40]; char *w76; int w80; } O_002021C0;
extern char D_00454020[], D_00314C20_002021C0[] __asm__("D_00314C20"); void func_00201B08(O_002021C0 *);
// MATCH func_002021C0
O_002021C0 *sprite_002021c0(O_002021C0 *o) { func_00201B08(o); o->w76 = D_00454020; o->f20 = 255.0f; o->w80 = -1; o->w0 = (int)D_00314C20_002021C0; o->f24 = 255.0f; o->w28 = 8; o->w32 = 8; return o; }

extern int D_004A6CA0; extern char *D_004A1A20_00127100 __asm__("D_004A1A20"); extern char D_004312A0[]; int func_001118F8_00127100(char *) __asm__("func_001118F8"); void func_0021A650(char *, int);
// MATCH func_00127100
void battle_00127100(void) { int i; int off = 0; func_001118F8_00127100(D_004312A0); D_004A6CA0 = 1; for (i = 0; i < 20; i++) { func_0021A650(D_004A1A20_00127100 + off, i); off += 5472; } }

extern int D_0062B640[]; int func_002CBB80(int); int func_002EDC50(void); void func_002EDC98(void);
// MATCH func_002CB0A8
int FUN_002cb0a8(int a) { int r, old; if (func_002CBB80(1)) return 0; r = func_002EDC50(); old = D_0062B640[0]; D_0062B640[0] = a; if (r != 0) func_002EDC98(); return old; }

typedef struct { char p[76]; int w76; char q[56]; int w136; } O_0029FCC0;
extern float D_004A0D88; void func_0029F948(O_0029FCC0 *); void func_0029F9B8(O_0029FCC0 *, float);
// MATCH func_0029FCC0
void clas_min_0029fcc0(O_0029FCC0 *o) { func_0029F948(o); o->w136 = 12000; func_0029F9B8(o, D_004A0D88); o->w76 = (o->w76 & ~4) | 0x800; }

extern char *D_004A1A20_0024CFC8 __asm__("D_004A1A20"); int func_0024D4C0(int, int, int, float);
// MATCH func_0024CFC8
int FUN_0024cfc8(void) { int r = 0; int i; for (i = 0; i < 10; i++) { if (func_0024D4C0(i, 0, 2, 1.0f) >= 0) { r = 1; *(unsigned *)(D_004A1A20_0024CFC8 + i * 5472 + 4816) |= 0x80; } } return r; }

typedef struct { char p[20]; int w20, w24, w28, w32; } O_0025E510;
extern char D_00343010_0025E510[] __asm__("D_00343010"); void func_001E3380_0025E510(char *, int, int) __asm__("func_001E3380");
// MATCH func_0025E510
void FUN_0025e510(O_0025E510 *o, int b, int c, int d) { o->w24 = c; o->w28 = d; o->w20 = b; o->w32 = 0; func_001E3380_0025E510(D_00343010_0025E510, b, 0); func_001E3380_0025E510(D_00343010_0025E510, c, 0); }

typedef struct { char p[12]; char *w12; char q[136]; void *w152, *w156, *w160; } O_00183C50;
extern char D_0043E480[]; void func_00131588(void *); void func_00185168_00183C50(O_00183C50 *, int) __asm__("func_00185168");
// MATCH func_00183C50
void screfct_00183c50(O_00183C50 *o, int a) { o->w12 = D_0043E480; if (o->w152) func_00131588(o->w152); if (o->w156) func_00131588(o->w156); if (o->w160) func_00131588(o->w160); func_00185168_00183C50(o, a); }

extern char D_004406A8[]; void func_001118F8_0018D2B0(char *, ...) __asm__("func_001118F8");
// MATCH func_0018D2B0
void FUN_0018d2b0(char *a, int *p) { if (a != 0) func_001118F8_0018D2B0(a); if (p != 0) func_001118F8_0018D2B0(D_004406A8, p, p[0], p[1], p[2], p[3]); }

extern char D_00440A48[]; void *func_00162130_001909F8(int, char *, int) __asm__("func_00162130"); void func_001908F0(void *, int *, int);
// MATCH func_001909F8
void *LzssDecodeAlloc(int *p) { int n = p[0]; void *buf = func_00162130_001909F8((n + 2047) & -2048, D_00440A48, 191); func_001908F0(buf, p, n); return buf; }

typedef struct { int w0, w4, w8, w12, w16, w20; } S_002CB040;
extern char D_002CB018[]; int func_002E58A0_002CB040(S_002CB040 *) __asm__("func_002E58A0"); void func_002E5620_002CB040(int, char *, int) __asm__("func_002E5620"); void func_002E58E0_002CB040(int) __asm__("func_002E58E0"); void func_002E58B0_002CB040(int) __asm__("func_002E58B0");
// MATCH func_002CB040
void FUN_002cb040(unsigned short a) { S_002CB040 s; int r; s.w4 = 1; s.w8 = 0; s.w20 = 0; r = func_002E58A0_002CB040(&s); func_002E5620_002CB040(a, D_002CB018, r); func_002E58E0_002CB040(r); func_002E58B0_002CB040(r); }


typedef struct { char p[324]; int w324, w328, w332; } O_002C3E00;
int func_002C7318_002C3E00(O_002C3E00 *, int) __asm__("func_002C7318");
// MATCH func_002C3E00
void FUN_002c3e00(O_002C3E00 *o) { func_002C7318_002C3E00(o, 3); if (func_002C7318_002C3E00(o, 1) != 0) { func_002C7318_002C3E00(o, 8); func_002C7318_002C3E00(o, 8); o->w324 = func_002C7318_002C3E00(o, 8); } o->w328 = func_002C7318_002C3E00(o, 14); func_002C7318_002C3E00(o, 1); o->w332 = func_002C7318_002C3E00(o, 14); }

typedef struct { char p[436]; int w436; } O_002C74E8;
int func_002C7318_002C74E8(O_002C74E8 *, int) __asm__("func_002C7318"); void func_002C7228(O_002C74E8 *, int); void func_002C7A40(O_002C74E8 *);
// MATCH func_002C74E8
int FUN_002c74e8(O_002C74E8 *o) { o->w436 = func_002C7318_002C74E8(o, 5); if (func_002C7318_002C74E8(o, 1) != 0) { func_002C7318_002C74E8(o, 1); func_002C7228(o, 7); func_002C7A40(o); } return 0; }

extern char D_0062BEC0_002CDF50[] __asm__("D_0062BEC0"); unsigned func_002DD5E0_002CDF50(char *) __asm__("func_002DD5E0"); int func_002DC650(char *, char *, int);
// MATCH func_002CDF50
void FUN_002cdf50(char *d) { if (d != 0) { unsigned n; if (func_002DD5E0_002CDF50((char *)((unsigned)D_0062BEC0_002CDF50 | 0x20000000)) < 1024) n = func_002DD5E0_002CDF50((char *)((unsigned)D_0062BEC0_002CDF50 | 0x20000000)); else n = 1023; func_002DC650(d, (char *)((unsigned)D_0062BEC0_002CDF50 | 0x20000000), n); d[n] = 0; } }

int func_002C9420(void *, int); int func_002C9368(void *, int);
// MATCH func_002C2250
int FUN_002c2250(void *o) { func_002C9420(o, 56); func_002C9420(o, 40); while (func_002C9368(o, 1) == 1) func_002C9420(o, 24); return 1; }

typedef struct { long long q0; int w8, w12, w16; long long q24; int w32, w36, w40; } O_002C9330;
void func_002C9388(O_002C9330 *, int);
// MATCH func_002C9330
void FUN_002c9330(O_002C9330 *o, int b, int c, int d) { o->w40 = d; o->w8 = b; o->q0 = 0; o->w16 = 0; o->w12 = b; o->q24 = 0; o->w32 = c; o->w36 = c + d; func_002C9388(o, 0); }

typedef struct { char p[144]; void *w144; } O_001E0218;
extern char D_0044B4A0[]; void *func_001334D0(int, char *, int); void func_00133528_001E0218(void *, char *, int) __asm__("func_00133528");
// MATCH func_001E0218
int mizuki_001e0218(O_001E0218 *o, int n) { void *p; if (n <= 0) return 0; p = func_001334D0(n, D_0044B4A0, 320); if (p == 0) return -1; if (o->w144 != 0) func_00133528_001E0218(o->w144, D_0044B4A0, 322); o->w144 = p; return 1; }

typedef struct { char p[88]; void *w88; } O_001E25A8;
extern char D_0044B740_001E25A8[] __asm__("D_0044B740"); void *func_001334D0(int, char *, int); void func_00133528_001E25A8(void *, char *, int) __asm__("func_00133528");
// MATCH func_001E25A8
int akari_001e25a8(O_001E25A8 *o, int n) { void *p; if (n <= 0) return 0; p = func_001334D0(n << 4, D_0044B740_001E25A8, 285); if (p == 0) return -1; if (o->w88 != 0) func_00133528_001E25A8(o->w88, D_0044B740_001E25A8, 287); o->w88 = p; return 1; }

typedef struct { int w0; char p[524]; int w528; char q[8]; unsigned short h540[64]; } O_002049B0;
void func_001AD960(int, int, int, int);
// MATCH func_002049B0
void pchjob0_002049b0(O_002049B0 *o, int b) { int i; if (o->w0 != 0) { for (i = 0; i < o->w528; i++) { if (o->h540[i] == b) { func_001AD960(o->w0, i, o->w528, b); break; } } } }

typedef struct { char p[100]; char *w100; char q[744]; void *w848; int w852, w856, w860, w864, w868, w872; } O_001E7F28;
extern char D_0044CAE8[]; void func_00131588(void *); void func_001E2400(O_001E7F28 *, int);
// MATCH func_001E7F28
void yue_001e7f28(O_001E7F28 *o, int a) { o->w100 = D_0044CAE8; if (o->w848) func_00131588(o->w848); o->w848 = 0; o->w852 = 0; o->w856 = 0; o->w860 = 0; o->w864 = 0; o->w868 = 0; o->w872 = 0; func_001E2400(o, a); }

typedef struct { char p[16]; char *w16; } P_00247A48;
extern P_00247A48 *D_004A1524_00247A48 __asm__("D_004A1524");
// MATCH func_00247A48
void FUN_00247a48(unsigned a, unsigned long long b) { P_00247A48 *p = D_004A1524_00247A48; char *q = p->w16; *(unsigned long long *)q = b; *(unsigned long long *)(q + 8) = a; p->w16 = q + 16; }

void func_002E5950(unsigned *); void func_002E5940(unsigned *);
// MATCH func_002EDF80
int FUN_002edf80(void) { unsigned a[2]; func_002E5950(a); a[1] = (a[0] & 0xffff1fff) | 0x2000; func_002E5940(&a[1]); func_002E5950(&a[1]); func_002E5940(a); return ((a[1] >> 13) & 7) == 0; }

typedef struct { char p[20]; int w20; char q[4]; int w28, w32, w36, w40; } O_002E84A0;
typedef struct { char p[20]; int w20; char q[4]; int w28, w32; } P_002E84A0;
P_002E84A0 *func_002E8378(int); void func_002E7ED0(unsigned, P_002E84A0 *, int, int, int, int);
// MATCH func_002E84A0
void FUN_002e84a0(O_002E84A0 *o, int b) { P_002E84A0 *p = func_002E8378(b); int x = o->w20, y = o->w28; p->w20 = x; p->w28 = y; p->w32 = 0x8000000c; func_002E7ED0(0x80000008, p, 64, o->w32, o->w36, o->w40); }

int func_002D7E48(int, int); int func_002D78B8(int, int); long long func_002EF470(int);
// MATCH func_002EF410
long long FUN_002ef410(int a) { int z = 0; __asm__("" : "+r"(z)); if (func_002D7E48(a, z) < 0) return -func_002EF470(func_002D78B8(z, a)); return func_002EF470(a); }

typedef struct { int n0, n1; unsigned char *d0, *d1; unsigned char s0[64]; unsigned char s1[64]; } P_002CD728;
// MATCH func_002CD728
void FUN_002cd728(unsigned p) { P_002CD728 *q = (P_002CD728 *)((unsigned)p | 0x20000000); int i; if (q->n0 != 0) { unsigned char *d = q->d0; for (i = 0; i < q->n0; i++) *d++ = q->s0[i]; } if (q->n1 != 0) { unsigned char *d = q->d1; for (i = 0; i < q->n1; i++) *d++ = q->s1[i]; } }

extern int D_0042637C[]; extern int D_0062B644_002CB510[] __asm__("D_0062B644"), D_0062B648_002CB510[] __asm__("D_0062B648"); void func_002CB5C8(void); int func_002EDC50(void); void func_002EDC98(void);
// MATCH func_002CB510
int FUN_002cb510(int a, int b) { int r, old; if (D_0042637C[0] < 0) func_002CB5C8(); r = func_002EDC50(); old = D_0062B644_002CB510[0]; D_0062B648_002CB510[0] = b; D_0062B644_002CB510[0] = a; if (r != 0) func_002EDC98(); return old; }
