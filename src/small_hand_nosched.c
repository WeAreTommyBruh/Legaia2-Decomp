/* Small functions matched by hand. */
// cflags: -fno-schedule-insns
#include "common.h"

typedef struct { char pad[32]; int a[4]; } O_0015EBE8;
// MATCH func_0015EBE8
void flare_0015ebe8(O_0015EBE8 *o, int a, int b, int c) { int *q; o->a[0] = a; q = o->a; q[3] = 128; q[1] = b; q[2] = c; }

typedef struct { char p[68]; float f; char p2[8]; int n; } O_001E2588;
// MATCH func_001E2588
int akari_001e2588(O_001E2588 *o) { return (int)o->f >= o->n; }

// MATCH func_0022D080
float FUN_0022d080(float a, float b, float c) { return __builtin_fabsf(a - b) / __builtin_fabsf(b - c); }

typedef struct { char p[56]; unsigned char a, b, c, d; char p2[8]; float f1; float f2; } O_00201CE0;
// MATCH func_00201CE0
void sprite_00201ce0(O_00201CE0 *o) { o->d = 127; o->f2 = 1.0f; o->a = 127; o->b = 127; o->c = 127; o->f1 = 1.0f; }

typedef struct { int a, b, c, d, e; } O_001948A0;
// MATCH func_001948A0
void FUN_001948a0(O_001948A0 *o, int a, char *p, int n) { o->d = 0; o->a = a; o->c = 0; o->b = (int)p; o->e = n; if (n > 0) { do { *(int *)p = 0; p += 0x4ce40; } while (--n != 0); } }

typedef struct { int a, b, c, d; } O_0029C3C8;
extern int D_004A6980, D_004A6984, D_004A6988;
// MATCH func_0029C3C8
void clas_min_0029c3c8(O_0029C3C8 *o) { o->c = 0; o->d = 1; o->a = 0; o->b = 0; D_004A6980 = 0; D_004A6984 = 0; D_004A6988 = 0; }

typedef struct { char p[516]; float a; char p2[16]; float b; char p3[16]; float c; } O_0029FF38;
// MATCH func_0029FF38
void clas_min_0029ff38(O_0029FF38 *o) { o->c = 128.0f; o->a = 128.0f; o->b = 128.0f; }

typedef struct { char p[112]; int a; long long b; } P_002C2DE8;
typedef struct { char p[64]; P_002C2DE8 *q; } O_002C2DE8;
// MATCH func_002C2DE8
void FUN_002c2de8(O_002C2DE8 *o) { P_002C2DE8 *p = o->q; p->b = 0; p->a = 0; }

typedef struct { char p[148]; int a, b, c; } P_002C2C30;
typedef struct { char p[64]; P_002C2C30 *q; } O_002C2C30;
// MATCH func_002C2C30
void FUN_002c2c30(O_002C2C30 *o, int a, int b, int c) { P_002C2C30 *p = o->q; p->c = c; p->a = a; p->b = b; }

typedef struct { int a, b, c, d, e; } O_002C3720;
// MATCH func_002C3720
int FUN_002c3720(O_002C3720 *o, int x, int y) { o->d = x >> 4; o->e = y >> 4; o->b = x; o->c = y; return 1; }

typedef struct { int a, b, c, d; } N_002DA520;
extern char D_0049E7B0_002DA520[] __asm__("D_0049E7B0");
// MATCH func_002DA520
void FUN_002da520(N_002DA520 *n, int a, int b, int c) { if (n != 0) { n->d = c; n->a = a; n->b = (int)D_0049E7B0_002DA520; n->c = b; } }

typedef struct { int a, b, c, d; } N_002DB0E0;
extern char D_0049E998[];
// MATCH func_002DB0E0
void FUN_002db0e0(N_002DB0E0 *n, int a, int b, int c) { if (n != 0) { n->d = b; n->a = a; n->b = (int)D_0049E998; n->c = c; } }

extern int D_004A1444, D_004A140C; extern float D_003C0F30[3];
// MATCH func_0020CB58
int pchevent_0020cb58(int a) { if (a != 0 && D_004A1444 == 0 && (D_004A140C & 8)) { float z = 0.0f; __asm__("" : "+f"(z)); D_003C0F30[0] = z; D_003C0F30[1] = z; D_003C0F30[2] = z; } return 0; }

typedef struct { char p[32]; int a; char p2[76]; int b; } T_00222A80;
extern T_00222A80 D_00326F90;
// MATCH func_00222A80
int FUN_00222a80(void) { int a = D_00326F90.a; int b = D_00326F90.b; if (b - 1 == a) return 2; return b - 2 == a; }

typedef int u128 __attribute__((mode(TI)));
typedef struct { u128 *cur; char p[8]; u128 *last; } W_002CF350;
// MATCH func_002CF350
void FUN_002cf350(W_002CF350 *w, u128 v) { u128 *p = w->cur; *p = v; w->cur = p + 1; w->last = p; }

typedef struct { u128 *cur; char p[16]; u128 *last; } W_002CF6F0;
// MATCH func_002CF6F0
void FUN_002cf6f0(W_002CF6F0 *w, u128 v) { u128 *p = w->cur; *p = v; w->cur = p + 1; w->last = p; }

typedef struct { char pad[28]; int a28; int a32; int a36; } S_2a4990_002A4990;
extern int D_004A6598, D_004A659C;
typedef struct { int a, b, c, d; } V_2a4990_002A4990;
V_2a4990_002A4990 func_002A4570(int);
// MATCH func_002A4990
void clas_min_002a4990(S_2a4990_002A4990 *s) { V_2a4990_002A4990 t = func_002A4570(s->a28); D_004A659C = s->a36; D_004A6598 = s->a32; }

typedef struct { char pad[20]; char sub[20]; int a40; int a44; } S_2a6498_002A6498;
void func_0029CFB8(void *);
// MATCH func_002A6498
void FUN_002a6498(S_2a6498_002A6498 *s) { func_0029CFB8(s); func_0029CFB8(s->sub); s->a40 = 0; s->a44 = 0; }

// MATCH func_00203520
void FUN_00203520(float *v) { float z = 0.0f; __asm__("" : "+f"(z)); v[0] = z; v[3] = 1.0f; v[2] = z; v[1] = z; }

typedef struct { int a0, a4, a8, a12, a16, a20; } S_29b608_0029B608;
extern S_29b608_0029B608 D_00620058; extern int D_00425518[];
// MATCH func_0029B608
void FUN_0029b608(int x, int b) { S_29b608_0029B608 *s = &D_00620058; if (s->a4 != 0 || (D_00425518[0] & 0x10)) { s->a0 = 0; s->a4 = b; s->a12 = 0; s->a8 = 0; s->a20 = 0; s->a16 = 0; } }

typedef struct { int a0, a4, a8, a12, a16; } G_2e7ce8_002E7CE8;
extern G_2e7ce8_002E7CE8 D_00632858;
// MATCH func_002E7CE8
int FUN_002e7ce8(int a, int b) { int o = D_00632858.a12; D_00632858.a16 = b; D_00632858.a12 = a; return o; }

typedef struct { int a0, a4, a8, a12, a16, a20, a24; } G_2e7cd0_002E7CD0;
extern G_2e7cd0_002E7CD0 D_00632858_002E7CD0 __asm__("D_00632858");
// MATCH func_002E7CD0
int FUN_002e7cd0(int a, int b) { int o = D_00632858_002E7CD0.a20; D_00632858_002E7CD0.a24 = b; D_00632858_002E7CD0.a20 = a; return o; }

typedef struct { char pad[4]; int a4; int a8; } F_t_002DDDC8;
int func_002E1FB0(int, void *);
// MATCH func_002DDDC8
int FUN_002dddc8(int x, F_t_002DDDC8 *fp) { int r; if (fp->a8 == 0) { fp->a4 = 0; return 0; } r = func_002E1FB0(x, fp); fp->a4 = 0; fp->a8 = 0; return r; }

typedef struct { char p[112]; float f112, f116, f120; } R_0020C138;
typedef struct { R_0020C138 *w0; } Q_0020C138;
extern int D_004A45E8; extern float D_004A45FC; Q_0020C138 *func_0020BBD8(int);
// MATCH func_0020C138
int pchevent_0020c138(void) { if (D_004A45E8 >= 0) { Q_0020C138 *p = func_0020BBD8(D_004A45E8); if (p != 0) { R_0020C138 *q = p->w0; if (q != 0) { q->f112 = D_004A45FC; q->f120 = D_004A45FC; q->f116 = D_004A45FC; } } } return 0; }

// MATCH func_0022D420
void FUN_0022d420(float *d, float *s) { int i, j; for (i = 0; i < 4; i++) for (j = 0; j < 4; j++) d[i * 4 + j] = s[i * 4 + j]; }

extern int D_00402930[]; extern char D_0040E070[]; int func_002A4F30(void *); int func_00202840(void *);
// MATCH func_002943B0
void FUN_002943b0(void) { int *p = D_00402930; func_002A4F30(D_00402930); p[32] = 1; p[39] = 70; p[40] = 0; p[31] = 0; p[33] = 0; p[34] = 0; p[35] = 0; p[36] = 0; p[37] = 0; p[38] = 0; func_00202840(D_0040E070); }

extern volatile int D_004A3790; extern volatile int D_004A1634; extern int D_004A3794; int func_002C02A0(int);
// MATCH func_00195248
void FUN_00195248(int a) { while (func_002C02A0(0) == a); D_004A3790 = 1; D_004A1634 = 0; D_004A3794 = 0; }

typedef struct { char p[24]; int w24; char q[156]; int w184; int pad; int w192; } O_00207728;
extern int D_00425510[]; extern int D_00425710[]; extern int D_004A4550;
int func_0016EEF8(int);
// MATCH func_00207728
void pchjob0_00207728(O_00207728 *o) { int i = o->w184; if (((D_00425510[i / 32] >> i) ^ 1) & 1) o->w24 |= 8; else *(int *)((char *)D_00425710 + (o->w192 << 2)) = func_0016EEF8(D_004A4550); }

typedef struct { char p[24]; int w24; char q[156]; int w184; int pad; int w192; } O_002077B8;
extern int D_00425510_002077B8[] __asm__("D_00425510"); extern int D_00425710_002077B8[] __asm__("D_00425710"); extern int D_004A4550_002077B8 __asm__("D_004A4550");
int func_00171AE8(int);
// MATCH func_002077B8
void pchjob0_002077b8(O_002077B8 *o) { int i = o->w184; if (((D_00425510_002077B8[i / 32] >> i) ^ 1) & 1) o->w24 |= 8; else *(int *)((char *)D_00425710_002077B8 + (o->w192 << 2)) = func_00171AE8(D_004A4550_002077B8); }

typedef struct { char p[16]; short adj; short pad; int (*fn)(void *); } VT_00207848;
typedef struct { char p[896]; VT_00207848 *vt; } G_00207848;
typedef struct { char p[24]; int w24; char q[156]; int w184; int pad; int w192; } O_00207848;
extern int D_00425510_00207848[] __asm__("D_00425510"); extern int D_00425710_00207848[] __asm__("D_00425710"); extern G_00207848 *D_004A4550_00207848 __asm__("D_004A4550");
// MATCH func_00207848
void pchjob0_00207848(O_00207848 *o) { int i = o->w184; if (((D_00425510_00207848[i / 32] >> i) ^ 1) & 1) o->w24 |= 8; else { G_00207848 *g = D_004A4550_00207848; int r = g->vt->fn((char *)g + g->vt->adj); { int *d = D_00425710_00207848 + o->w192; *d = r; } } }

typedef struct { char p0[4]; int w4, w8, w12, w16, w20, w24, w28; char b32, b33; } O_00202BC8;
extern int D_004A3864, D_004A384C; extern char D_00454238[]; void func_001118F8(char *);
// MATCH func_00202BC8
void eftpack_00202bc8(O_00202BC8 *o) { if (D_004A3864 & 0x400) func_001118F8(D_00454238); o->b33 = 0; o->b32 = 1; o->w28 = 0; o->w4 = 0; o->w8 = 0; o->w12 = 0; o->w16 = 0; o->w20 = 0; o->w24 = 0; D_004A384C = 0; }

typedef struct { char p[52]; void *vt; char q[56]; float f112; int w116, w120; float f124; char r[4]; } O_00154B10;
extern float D_0049FF68; extern char D_0043B3B8[]; void func_0015EA80(void *, int, int, int, int);
// MATCH func_00154B10
O_00154B10 *FUN_00154b10(O_00154B10 *o) { o->w116 = 0; o->w120 = 0; o->f112 = 1.0f; o->f124 = D_0049FF68; o->vt = D_0043B3B8; func_0015EA80((char *)o + 128, 0, 3, 14, 6); return o; }
