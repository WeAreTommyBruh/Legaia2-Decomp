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
