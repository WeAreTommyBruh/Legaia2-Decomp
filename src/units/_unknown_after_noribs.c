/* Functions of this report unit, matched by hand. */
#include "../common.h"
typedef int u128 __attribute__((mode(TI)));

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

typedef struct { char pad[16]; float f; } S_00153CB0;
void func_0018ED30(void *);
void func_001544F0(void *);
// MATCH func_00153CB0
void FUN_00153cb0(S_00153CB0 *s, float x) { s->f = x; func_0018ED30(&s->f); func_001544F0(s); }

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

typedef struct { char pad[208]; float x; } O_001541C8;
void func_00154170(float);
// MATCH func_001541C8
void FUN_001541c8(O_001541C8 *o, float a) { func_00154170(a - o->x); o->x = a; }

void func_0018D048(void *);
void func_0018CDE0(void *);
// MATCH func_00154890
void FUN_00154890(char *a) { func_0018D048(a); func_0018D048(a + 16); func_0018D048(a + 32); func_0018CDE0(a + 64); }

typedef struct { char pad[192]; float v[4]; } O_00154248;
void func_00154550(void *);
// MATCH func_00154248
void FUN_00154248(O_00154248 *o) { float *p = o->v; o->v[0] = 0; p[1] = 0; p[2] = 0; p[3] = 1.0f; func_00154550(o); }

void func_00154428(void *); void func_0018EB98(void *, void *);
// MATCH func_001544B8
void FUN_001544b8(char *a, char *b) { func_00154428(a); func_0018EB98(b, a + 128); }

typedef struct { float x, y, z, w; } V_154038_00154038;
typedef struct { char pad[192]; V_154038_00154038 v; } S_154038_00154038;
void func_00153B38(void *); void func_00154550(void *);
static inline void set_154038_00154038(V_154038_00154038 *v, float x, float y, float z, float w) { v->x = x; v->y = y; v->z = z; v->w = w; }
// MATCH func_00154038
void FUN_00154038(S_154038_00154038 *s, float a, float b, float c, float d) { set_154038_00154038(&s->v, a, b, c, d); func_00153B38(&s->v); func_00154550(s); }

typedef struct { short adj; short p; int pad[0]; } X_155840_00155840;
typedef struct { char pad[32]; short adj; short p2; void (*fn)(void *, float *); } VT_155840_00155840;
typedef struct { char pad[52]; VT_155840_00155840 *vt; } S_155840_00155840;
// MATCH func_00155840
void FUN_00155840(S_155840_00155840 *s, float a, float b, float c) { float v[4]; v[0] = a; v[1] = b; v[2] = c; v[3] = 1.0f; s->vt->fn((char *)s + s->vt->adj, v); }

typedef struct { float x, y, z, w; } V_153c68_00153C68;
typedef struct { char pad[16]; V_153c68_00153C68 v; } S_153c68_00153C68;
void func_0018ED30(void *); void func_001544F0(void *);
static inline void set_153c68_00153C68(V_153c68_00153C68 *v, float x, float y, float z, float w) { v->x = x; v->y = y; v->z = z; v->w = w; }
// MATCH func_00153C68
void FUN_00153c68(S_153c68_00153C68 *s, float a, float b, float c) { set_153c68_00153C68(&s->v, a, b, c, 1.0f); func_0018ED30(&s->v); func_001544F0(s); }

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

typedef struct { char pad[16]; float a[4]; float b[4]; float c[4]; } S_00153BE0;
void func_0018ED08_00153BE0(void *, void *) __asm__("func_0018ED08"); void func_001544F0(void *);
// MATCH func_00153BE0
void FUN_00153be0(S_00153BE0 *s, void *x, void *y) { func_0018ED08_00153BE0(s->a, x); func_0018ED08_00153BE0(s->b, y); *(u128 *)s->c = *(u128 *)s->b; s->c[1] = -s->b[1]; func_001544F0(s); }

void func_0018EE08(void *, void *, void *); void func_0018EC78(void *, void *, void *); void func_00153750(void *, void *);
// MATCH func_001544F0
void FUN_001544f0(char *s) { func_0018EE08(s + 64, s + 48, s + 16); *(u128 *)(s + 96) = *(u128 *)(s + 16); func_0018EC78(s + 80, s + 96, s + 64); func_00153750(s + 192, s + 64); }

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

typedef struct { float x, y, z, w; } V4_001540C0;
static inline void set_001540C0(V4_001540C0 *v, float x, float y, float z) { v->x = x; v->y = y; v->z = z; v->w = 1.0f; }
void func_0018F368_001540C0(V4_001540C0 *, char *, V4_001540C0 *) __asm__("func_0018F368"); void func_0018F068_001540C0(char *, V4_001540C0 *) __asm__("func_0018F068");
// MATCH func_001540C0
void FUN_001540c0(char *o, float a) { V4_001540C0 v; set_001540C0(&v, a, 0.0f, 0.0f); func_0018F368_001540C0(&v, o + 64, &v); func_0018F068_001540C0(o, &v); }

typedef struct { char p[16]; float v[4]; } O_00153EB8;
void func_0018F0B0_00153EB8(float *, int, O_00153EB8 *) __asm__("func_0018F0B0"); void func_0018ED08_00153EB8(float *, float *) __asm__("func_0018ED08"); void func_001544F0_00153EB8(O_00153EB8 *) __asm__("func_001544F0");
// MATCH func_00153EB8
void FUN_00153eb8(O_00153EB8 *o, int b) { float v[3]; func_0018F0B0_00153EB8(v, b, o); if (v[0] != 0.0f || v[1] != 0.0f || v[2] != 0.0f) { func_0018ED08_00153EB8(o->v, v); func_001544F0_00153EB8(o); } }

typedef struct { float x, y, z, w; float v[4]; } O_00153F30;
void func_0018ED08_00153F30(float *, float *) __asm__("func_0018ED08"); void func_001544F0_00153F30(O_00153F30 *) __asm__("func_001544F0");
// MATCH func_00153F30
void FUN_00153f30(O_00153F30 *o, float x, float y, float z) { float v[3]; v[0] = x - o->x; v[1] = y - o->y; v[2] = z - o->z; if (v[0] != 0.0f || v[1] != 0.0f || v[2] != 0.0f) { func_0018ED08_00153F30(o->v, v); func_001544F0_00153F30(o); } }

void func_0018EEC0(float *, float *, float); void func_0018EC78_001535B8(float *, float *, float *) __asm__("func_0018EC78"); void func_0018F0E0(float *, float *, float *); void func_0018F020(float *, float *, float *); void func_00153B38_001535B8(float *) __asm__("func_00153B38");
// MATCH func_001535B8
void FUN_001535b8(float *a, float *b, float *c) { float t0[4]; float t1[4]; float t2[4]; float t3[4]; func_0018EEC0(t1, c, b[3]); func_0018EEC0(t0, b, c[3]); func_0018EC78_001535B8(t2, b, c); func_0018F0E0(t3, b, c); func_0018F020(t0, t0, t1); func_0018F020(a, t0, t2); a[3] = t3[3] - (t3[0] + t3[1] + t3[2]); func_00153B38_001535B8(a); }

void func_0018F368_00154428(float *, char *, float *) __asm__("func_0018F368"); void func_0018F5F0(char *, char *, char *); void func_0018F620_00154428(char *, float *) __asm__("func_0018F620"); void func_0018DF68_00154428(char *, char *) __asm__("func_0018DF68");
// MATCH func_00154428
void FUN_00154428(char *o) { float v[4]; v[3] = 1.0f; v[2] = -*(float *)(o + 208); v[0] = 0; v[1] = 0; func_0018F368_00154428(v, o + 64, v); func_0018F5F0(o + 128, o + 64, o); func_0018F620_00154428(o + 128, v); func_0018DF68_00154428(o + 128, o + 128); }

void func_00153A10(char *, char *, char *, float); void func_0018F138(char *, char *, char *, float); void func_00154550_001545A8(char *) __asm__("func_00154550");
// MATCH func_001545A8
void FUN_001545a8(char *a, char *b, char *c, float t) { func_00153A10(a + 192, b + 192, c + 192, t); func_0018F138(a, b, c, t); *(float *)(a + 208) = *(float *)(b + 208) * (1.0f - t) + *(float *)(c + 208) * t; func_00154550_001545A8(a); }

void func_00155660(void); void func_001557E0(void); void func_0015ECC8(char *, char *, char *);
void *func_002DB188(int, void *, int, void *, void *, void *);
// MATCH func_001555A0
void FUN_001555a0(char *o, char *a) { int i; for (i = 0; i < *(int *)(o + 332); i++) { char *p = ((char **)(o + 196))[i]; char *r; if (p == 0) r = 0; else r = func_002DB188(*(int *)(*(char **)(p + 52) + 4), (void *)func_00155660, 1, p + **(short **)(p + 52), (void *)func_001557E0, p); if (r != 0) func_0015ECC8(r + 128, a, r + 32); } }

float func_0015FB58(int, float); void func_0018EEC0(float *, float *, float);
// MATCH func_00153520
void FUN_00153520(float *o, float *p, float s) { if (s == 0.0f) { 
o[3] = 1.0f;
o[0] = 0.0f;
o[1] = 0.0f;
o[2] = 0.0f;} else { float r; s = s * 0.5f; r = func_0015FB58(0, s); func_0018EEC0(o, p, r); o[3] = func_0015FB58(1, s); } }

extern char D_00342D00_00155490[] __asm__("D_00342D00"); void *func_00155510(void *); void *func_00155518(void *); void *func_00154C38(void *); void func_0018EB98_00155490(char *, void *) __asm__("func_0018EB98");
// MATCH func_00155490
void FUN_00155490(int u, char *a, char *b, u128 *out) { func_0018EB98_00155490(a, func_00155510(D_00342D00_00155490)); func_0018EB98_00155490(b, func_00155518(D_00342D00_00155490)); *out = *(u128 *)func_00154C38(D_00342D00_00155490); }
