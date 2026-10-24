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
