/* Functions of this report unit, matched by hand. */
#include "../common.h"

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

typedef struct { char p[176]; void *w176; } O_001F7410;
int func_001F6080(void *); void *func_001F60A8(void *);
// MATCH func_001F7410
void *ikumin_001f7410(O_001F7410 *o, int b) { void *p = o->w176; while (func_001F6080(p) != b) { p = func_001F60A8(p); if (p == 0) return 0; } return p; }

typedef struct { int a, b, c, d, e, f, g, pad, h; } E_001F7970;
typedef struct { char p[32]; E_001F7970 s[4]; } O_001F7970;
static inline void in_001F7970(O_001F7970 *o, int i) { E_001F7970 *e = &o->s[i]; e->h = 1; e->d = 0; o->s[i].a = e->b; }
// MATCH func_001F7970
void ikumin_001f7970(O_001F7970 *o) { in_001F7970(o, 0); in_001F7970(o, 1); in_001F7970(o, 2); in_001F7970(o, 3); }
