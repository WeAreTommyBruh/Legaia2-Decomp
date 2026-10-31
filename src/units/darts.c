/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p[44]; int a; char p2[40]; int b, c; } O_0016E1D0;
void func_0016E510(void *);
// MATCH func_0016E1D0
int darts_0016e1d0(O_0016E1D0 *o) { func_0016E510(o); o->b = 0; o->c = 0; o->a = 0; return 1; }

typedef struct { char p[16]; int *q; char p2[12]; int i; } O_0016EE38;
extern char D_0041EFB0[]; void func_00153EB8(void *, int); void func_00153D80(void *, float, float, float);
// MATCH func_0016EE38
void darts_0016ee38(O_0016EE38 *o) { func_00153EB8(D_0041EFB0, o->q[o->i] + 32); func_00153D80(D_0041EFB0, 0.0f, -1.0f, 0.0f); }

typedef struct { char p[16]; int *q; char p2[12]; int i; } O_0016EE90;
typedef struct { char p[12]; float f; } G_0016EE90;
extern G_0016EE90 D_0041EFB0_0016EE90 __asm__("D_0041EFB0"); void func_0018EB78(void *, int); void func_00153D80(void *, float, float, float);
// MATCH func_0016EE90
void darts_0016ee90(O_0016EE90 *o) { func_0018EB78(&D_0041EFB0_0016EE90, o->q[o->i] + 32); D_0041EFB0_0016EE90.f = 1.0f; func_00153D80(&D_0041EFB0_0016EE90, 0.0f, -1.0f, 0.0f); }

typedef struct { char c[8]; } V8_0016DF68;
typedef struct { char p[32]; int a; char p2[8]; int n; char p3[56]; V8_0016DF68 v; } O_0016DF68;
extern V8_0016DF68 D_004A2FE0[2];
// MATCH func_0016DF68
int darts_0016df68(O_0016DF68 *o) { if (o->n++ < 10) return 0; o->a++; o->v = D_004A2FE0[0]; return 0; }

typedef struct { char p[44]; int n; char p2[44]; int f; } O_0016E208;
void func_0016E510(void *);
// MATCH func_0016E208
int darts_0016e208(O_0016E208 *o) { func_0016E510(o); if (o->n++ & 0x20) o->f = 0; else o->f = 1; return 1; }

typedef struct { char p[44]; int n; char p2[40]; int f; int g; } O_0016E258;
void func_0016E510(void *);
// MATCH func_0016E258
int darts_0016e258(O_0016E258 *o) { func_0016E510(o); o->g = 0; if (o->n++ & 0x20) o->f = 0; else o->f = 1; return 1; }

typedef struct { char pad[24]; int a; int b; } S_16f508_0016F508;
// MATCH func_0016F508
void darts_0016f508(S_16f508_0016F508 *s, int n) { s->a += n; if (s->a > 99999999) s->a = 99999999; if (s->a > s->b) s->b = s->a; }

typedef struct { char pad[52]; char sub[1]; char pad1[43]; int a96; } S_16ce98_0016CE98;
extern char D_0043D470[];
void func_002971C0(int, int); void func_001621F8(int, void *, int); void func_00164500(void *, int); void func_00108B80_0016CE98(void *) __asm__("func_00108B80");
// MATCH func_0016CE98
void darts_0016ce98(S_16ce98_0016CE98 *s, int fl) { func_002971C0(18, 50); func_001621F8(s->a96, D_0043D470, 234); func_00164500(s->sub, 2); if (fl & 1) func_00108B80_0016CE98(s); }

typedef struct { char c[8]; } V8_16e190_0016E190;
typedef struct { char pad[104]; V8_16e190_0016E190 v; } S_16e190_0016E190;
extern V8_16e190_0016E190 D_004A3030[2];
int func_0016CF10(void *);
// MATCH func_0016E190
int darts_0016e190(S_16e190_0016E190 *s) { func_0016CF10(s); s->v = D_004A3030[0]; return 1; }

typedef struct { char p[104]; void *vt; int b; int c; } O_16f560_0016F560;
extern char D_0043D4C0[]; int func_00163D88(void *, int, int);
// MATCH func_0016F560
void *darts_0016f560(O_16f560_0016F560 *o, int b, int c, int d, int e) { func_00163D88(o, d, e); o->b = b; o->vt = D_0043D4C0; o->c = c; return o; }

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

typedef struct { char c[8]; } V8_0016CFB8;
typedef struct { char p[104]; V8_0016CFB8 v, v2; char q[456]; float f576, f580; } O_0016CFB8;
extern char D_0041EFB0_0016CFB8[] __asm__("D_0041EFB0"); void func_0016E510_0016CFB8(O_0016CFB8 *) __asm__("func_0016E510"); void func_001545A8(char *, char *, char *, float);
// MATCH func_0016CFB8
int darts_0016cfb8(O_0016CFB8 *o) { func_0016E510_0016CFB8(o); o->f576 += o->f580; if (o->f576 >= 1.0f) { o->f576 = 1.0f; o->v = o->v2; } func_001545A8(D_0041EFB0_0016CFB8, (char *)o + 128, (char *)o + 352, o->f576); return 0; }

typedef struct { char c[8]; } V8_0016E118;
typedef struct { char p[44]; int w44; char q[56]; V8_0016E118 v; } O_0016E118;
extern unsigned long long D_004A12D8_0016E118 __asm__("D_004A12D8"); extern V8_0016E118 D_004A3028[2]; int func_001646E8(char *);
// MATCH func_0016E118
int darts_0016e118(O_0016E118 *o) { if (func_001646E8((char *)o + 52) != 0) return 0; if (++o->w44 >= 51 || (D_004A12D8_0016E118 & 0x200040)) { o->v = D_004A3028[0]; return 1; } return 0; }

extern int D_004A1274; extern int D_004A1278; extern char D_00425FB0[]; extern char D_0041EFB0_0016EEF8[] __asm__("D_0041EFB0"); int func_00196FF8_0016EEF8(void) __asm__("func_00196FF8"); void func_00164608(char *); void func_002A8FB0(char *, char *); void func_0016EFB0(char *);
// MATCH func_0016EEF8
int darts_0016eef8(char *o) { int a; int b; int r; char *s; int (*fn)(char *); if (*(int *)(o + 100) == 0) { if (func_00196FF8_0016EEF8() != 0) return 0; *(int *)(o + 100) = 1; } s = o + *(short *)(o + 104);
a = D_004A1274;
b = D_004A1278;
fn = (int (*)(char *))*(int *)(o + 108);
D_004A1274 = 10;
D_004A1278 = 10;r = fn(s); func_00164608(o + 52); func_002A8FB0(D_00425FB0, D_0041EFB0_0016EEF8); func_0016EFB0(o); D_004A1274 = a; D_004A1278 = b; return r; }

typedef struct { char c[8]; } V8_0016D8E8;
extern V8_0016D8E8 D_004A2FE8[3]; extern V8_0016D8E8 D_004A3010[3]; extern char D_00343028_0016D8E8[] __asm__("D_00343028");
typedef struct { char p[32]; float x; float y; float z; } E_16d8e8_0016D8E8;
typedef struct { char p0[4]; float f4; char p1[8]; E_16d8e8_0016D8E8 **arr; char p2[12]; int w32; char p3[8]; int w44; char p4[56]; V8_0016D8E8 v104; V8_0016D8E8 v112; char p5[464]; short adj584; short pad584; void (*fn588)(void *); } O_16d8e8_0016D8E8;
void func_0018EF80(float *, void *, float); void func_0016E510(void *); int func_0016EB78(void *, float *); int func_0010C2B0_0016D8E8(char *, int, int, int, int, int, int) __asm__("func_0010C2B0"); int func_002D9440(float); int func_001E48E0_0016D8E8() __asm__("func_001E48E0");
// MATCH func_0016D8E8
int darts_0016d8e8(O_16d8e8_0016D8E8 *o) { int x; int y; int z; func_0018EF80(&o->arr[o->w32]->x, o, 0.5f); o->f4 = o->f4 + 0.0f; func_0016E510(o); o->fn588((char *)o + o->adj584); if (func_0016EB78(o, &o->arr[o->w32]->x) != 0) { func_0010C2B0_0016D8E8(D_00343028_0016D8E8, 83, 6, 0, 2, 0, 0); x = func_002D9440(o->arr[o->w32]->x); y = func_002D9440(o->arr[o->w32]->y); z = func_002D9440(o->arr[o->w32]->z); func_001E48E0_0016D8E8(2, 0, x, y, z); func_001E48E0_0016D8E8(1, 0); o->w44 = 10; o->v104 = D_004A2FE8[0]; o->v112 = D_004A3010[0]; } return 0; }

typedef struct { char c[8]; } V8_0016E2A8;
extern V8_0016E2A8 D_004A3038[3]; extern char D_00343028_0016E2A8[] __asm__("D_00343028");
int func_0010C2B0_0016E2A8(char *, int, int, int, int, int, int) __asm__("func_0010C2B0"); void func_0016E9B8_0016E2A8(int *) __asm__("func_0016E9B8"); void func_0016ED20_0016E2A8(int *, int) __asm__("func_0016ED20"); void func_0016E6D0(int *);
// MATCH func_0016E2A8
int darts_0016e2a8(int *o) { int a; int b; o[22] = 0; a = o[15] - 5000; b = o[16] - 5000; if ((a < 0 ? -a : a) < 501 && (b < 0 ? -b : b) < 501) { func_0010C2B0_0016E2A8(D_00343028_0016E2A8, 83, 6, 0, 0, 0, 0); o[8] = o[8] - 1; func_0016E9B8_0016E2A8(o); func_0016ED20_0016E2A8(o, 0); o[11] = 0; *(V8_0016E2A8 *)(o + 26) = D_004A3038[0]; return 1; } o[15] = o[17]; o[16] = o[18]; func_0016E6D0(o); return 0; }

typedef struct { char c[8]; } V8_0016DA70;
extern V8_0016DA70 D_004A2FE8_0016DA70[3] __asm__("D_004A2FE8"); extern V8_0016DA70 D_004A3018[3]; extern char D_00343028_0016DA70[] __asm__("D_00343028");
typedef struct { char p[32]; float x; float y; float z; } E_16da70_0016DA70;
typedef struct { char p0[4]; float f4; char p1[8]; E_16da70_0016DA70 **arr; char p2[12]; int w32; char p3[8]; int w44; char p4[56]; V8_0016DA70 v104; V8_0016DA70 v112; char p5[464]; short adj584; short pad584; void (*fn588)(void *); } O_16da70_0016DA70;
void func_0018EF80(float *, void *, float); void func_0016E510(void *); int func_0016EB78(void *, float *); int func_0010C2B0_0016DA70(char *, int, int, int, int, int, int) __asm__("func_0010C2B0"); int func_002D9440(float); int func_001E48E0_0016DA70() __asm__("func_001E48E0");
// MATCH func_0016DA70
int darts_0016da70(O_16da70_0016DA70 *o) { int x; int y; int z; func_0018EF80(&o->arr[o->w32]->x, o, 0.5f); o->f4 = o->f4 + 0.0f; func_0016E510(o); o->fn588((char *)o + o->adj584); if (func_0016EB78(o, &o->arr[o->w32]->x) != 0) { func_0010C2B0_0016DA70(D_00343028_0016DA70, 83, 6, 0, 2, 0, 0); x = func_002D9440(o->arr[o->w32]->x); y = func_002D9440(o->arr[o->w32]->y); z = func_002D9440(o->arr[o->w32]->z); func_001E48E0_0016DA70(2, 0, x, y, z); func_001E48E0_0016DA70(1, 0); o->w44 = 10; o->v104 = D_004A2FE8_0016DA70[0]; o->v112 = D_004A3018[0]; } return 0; }

typedef struct { char c[8]; } V8_0016D2E8;
extern char D_00343028_0016D2E8[] __asm__("D_00343028"), D_004A2FD0[]; int func_0010C2B0_0016D2E8(char *, int, int, int, int, int, int) __asm__("func_0010C2B0"); void func_0016E9B8_0016D2E8(char *) __asm__("func_0016E9B8"); void func_0016ED20_0016D2E8(char *, int) __asm__("func_0016ED20");
// MATCH func_0016D2E8
int darts_0016d2e8(char *o) { int *w = (int *)o; int c = w[11] + 1; w[11] = c; if (c == 1) return 10; if (c < 4) return 0; func_0010C2B0_0016D2E8(D_00343028_0016D2E8, 83, 6, 0, 0, 0, 0); w[8] = w[8] - 1; func_0016E9B8_0016D2E8(o); func_0016ED20_0016D2E8(o, 0); w[11] = 0; *(V8_0016D2E8 *)(o + 104) = *(V8_0016D2E8 *)D_004A2FD0; return 0; }

typedef struct { char c[8]; } V8_0016E388;
extern V8_0016E388 D_004A3028_0016E388[3] __asm__("D_004A3028"); extern char D_00343028_0016E388[] __asm__("D_00343028");
typedef struct { char p[32]; float x; float y; float z; } E_0016E388;
typedef struct { char p0[4]; float f4; char p1[8]; E_0016E388 **arr; char p2[12]; int w32; char p3[8]; int w44; char p4[56]; V8_0016E388 v104; V8_0016E388 v112; char p5[464]; short adj584; short pad584; void (*fn588)(void *); } O_0016E388;
void func_0018F068_0016E388(float *, void *) __asm__("func_0018F068"); int func_0016EB78(void *, float *); int func_0010C2B0_0016E388(char *, int, int, int, int, int, int) __asm__("func_0010C2B0"); int func_002D9440(float); int func_001E48E0_0016E388() __asm__("func_001E48E0");
// MATCH func_0016E388
int darts_0016e388(O_0016E388 *o) { int x; int y; int z; func_0018F068_0016E388(&o->arr[o->w32]->x, o); o->f4 = o->f4 + 0.0f; o->fn588((char *)o + o->adj584); if (func_0016EB78(o, &o->arr[o->w32]->x) != 0) { x = func_002D9440(o->arr[o->w32]->x); y = func_002D9440(o->arr[o->w32]->y); z = func_002D9440(o->arr[o->w32]->z); func_001E48E0_0016E388(2, 0, x, y, z); func_001E48E0_0016E388(1, 0); func_0010C2B0_0016E388(D_00343028_0016E388, 83, 6, 0, 2, 0, 0); o->v104 = D_004A3028_0016E388[0]; return 1; } return 0; }
