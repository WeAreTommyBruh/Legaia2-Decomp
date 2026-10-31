/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p[252]; unsigned char *src; int n; } O_001F60F0;
// MATCH func_001F60F0
void FUN_001f60f0(O_001F60F0 *o, unsigned char *dst) { int i; for (i = 0; i < o->n; i++) dst[i] = o->src[i]; }

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
