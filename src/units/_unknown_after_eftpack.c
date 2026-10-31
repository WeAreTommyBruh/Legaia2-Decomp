/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p[4]; int n; char p2[20]; char *q; signed char k; } O_00203290;
// MATCH func_00203290
char *FUN_00203290(O_00203290 *o, int a) { if (o->k != 1 || a < 0 || o->n - 1 < a) return 0; return o->q + a * 16; }

typedef struct { char p[4]; int n; char p2[12]; int *q; char p3[8]; signed char k; } O_00203378;
// MATCH func_00203378
int FUN_00203378(O_00203378 *o, int a) { if (o->k != 1 || a < 0 || o->n - 1 < a) return 0; return o->q[a]; }

typedef struct { char p[4]; int w4; char p1[8]; int w16; int *w20; int *w24; char p2[4]; signed char b32; } O_002034A0;
// MATCH func_002034A0
int FUN_002034a0(O_002034A0 *o, int idx, int *out) { if (o->b32 != 1 || idx < 0 || o->w4 - 1 < idx) return 0; if (out != 0) *out = o->w20[idx]; return o->w16 + o->w24[idx]; }

typedef struct { float x, y, z, w; } V4_00203540;
static inline void set_00203540(V4_00203540 *v, float x, float y, float z) { v->x = x; v->y = y; v->z = z; v->w = 1.0f; }
extern float D_004A0394; void func_0018F080(V4_00203540 *, int, V4_00203540 *); void func_0018EC78_00203540(char *, V4_00203540 *, V4_00203540 *) __asm__("func_0018EC78");
// MATCH func_00203540
void FUN_00203540(char *o, int b) { V4_00203540 v; V4_00203540 m; set_00203540(&v, 0.0f, D_004A0394, 0.0f); func_0018F080(&m, b, &v); func_0018EC78_00203540(o, &v, &m); }

typedef struct { int a, x, y; int pad[7]; int w40; char pad2[212]; } R__00203E30;
typedef struct { char p[360]; R__00203E30 *w360; } X__00203E30;
typedef struct O__00203E30 { X__00203E30 *w0; int q[64]; int p[64]; int pad; int w520, w524, w528, w532, w536; unsigned short sh[64]; char b[64]; char t[64]; } O__00203E30;
int func_0025D5F0(int, int);
// MATCH func_00203E30
void FUN_00203e30(O__00203E30 *o, int a, int b, int c, int d)
{
    int r;
    if (o->w528 < 64) {
        o->t[o->w528] = 104;
        o->sh[o->w528] = a;
        o->b[o->w528] = b;
        r = func_0025D5F0(c, d);
        { int i = o->w528; o->p[i] = d; o->q[i] = r; }
        o->w528++;
    }
}
