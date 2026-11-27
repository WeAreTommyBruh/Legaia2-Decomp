#include "../common.h"
typedef struct { float x, y, z, w; } V4_2059;
typedef struct { V4_2059 q; char pad[192]; float f; } G_2059;
typedef struct { char pad0[24]; int flags; int pad1c; V4_2059 v32; V4_2059 v48; char pad40[16]; V4_2059 v80; char pad60[68]; char *p164; char pada8[8]; float f176; int padb4; int id; short cur, max; int padc0; float a, b; char padcc[7]; char c211; } O_2059;
extern G_2059 D_0041EFB0;
extern int D_00425510[];
extern char D_00425FB0[];
void func_0018F020(void *, void *, void *);
void func_0018F110(void *, void *, void *, float);
void func_0018F080(void *, void *, void *);
void func_0018EB78(void *, void *);
void func_00153C38(void *, void *);
void func_00153D80(void *, float, float, float);
void func_002A8FB0(void *, void *);
// MATCH func_002059B0
void pchjob0_002059b0(O_2059 *o)
{
    V4_2059 a;
    V4_2059 b;
    V4_2059 d;
    int id;
    float t, f, fb, u;
    func_0018F020(&a, o->p164 + 32, &o->v80);
    if (o->max == 0) {
        if (o->c211 != 0) {
            b = D_0041EFB0.q;
            func_0018F110(&a, &a, &b, o->f176);
        }
    }
    id = o->id;
    o->c211 = 1;
    if (id != 0 && (((D_00425510[id / 32] >> id) ^ 1) & 1) != 0) goto L;
    if (o->cur < o->max) {
        o->cur++;
        fb = o->a;
        t = (float)o->cur / (float)o->max;
        { register float v __asm__("$f2") = o->b; u = v * t; }
        f = fb * (1.0f - t) + u;
        func_0018F110(&b, &o->v32, &a, t);
        func_0018F080(&a, &b, &o->v48);
        func_0018EB78(&D_0041EFB0, &b);
        D_0041EFB0.q.w = 1.0f;
        func_00153C38(&D_0041EFB0, &a);
        func_00153D80(&D_0041EFB0, 0.0f, -1.0f, 0.0f);
        D_0041EFB0.f = f;
        func_002A8FB0(D_00425FB0, &D_0041EFB0);
        return;
    }
    if (id != 0) {
        func_0018F080(&b, &a, &o->v48);
        func_0018EB78(&D_0041EFB0, &a);
        D_0041EFB0.q.w = 1.0f;
        func_00153C38(&D_0041EFB0, &b);
        func_00153D80(&D_0041EFB0, 0.0f, -1.0f, 0.0f);
        D_0041EFB0.f = o->b;
        func_002A8FB0(D_00425FB0, &D_0041EFB0);
        return;
    }
L:
    o->flags |= 8;
}
