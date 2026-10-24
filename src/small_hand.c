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