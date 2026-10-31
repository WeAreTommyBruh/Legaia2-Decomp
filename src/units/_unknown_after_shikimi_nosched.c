/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns
#include "../common.h"

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

typedef int u128 __attribute__((mode(TI)));
typedef struct { u128 *cur; char p[8]; u128 *last; } W_002CF350;
// MATCH func_002CF350
void FUN_002cf350(W_002CF350 *w, u128 v) { u128 *p = w->cur; *p = v; w->cur = p + 1; w->last = p; }

typedef struct { u128 *cur; char p[16]; u128 *last; } W_002CF6F0;
// MATCH func_002CF6F0
void FUN_002cf6f0(W_002CF6F0 *w, u128 v) { u128 *p = w->cur; *p = v; w->cur = p + 1; w->last = p; }

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

// MATCH func_002C2D30
int FUN_002c2d30(char *o, int i, int a, int b) { char *base = *(char **)(o + 64); char *b12 = base + 12; int off = i * 8; char *e = base + off; char *q = b12 + off; int old; *(int *)(e + 16) = b; old = *(int *)q; *(int *)q = a; return old; }

extern char D_0049F288[], D_0049F278[];
int func_002DD36C(void *, void *);
// MATCH func_002E2388
char *FUN_002e2388(int *o, int a, char *s) { if (s != 0) { if (func_002DD36C(s, D_0049F288) != 0 && func_002DD36C(s, D_0049F278) != 0) return 0; o[13] = (int)s; o[12] = a; } return D_0049F288; }
