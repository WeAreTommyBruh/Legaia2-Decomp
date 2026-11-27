#include "../common.h"
typedef struct { char p[12]; void *vt; char q[48]; } M;
typedef struct { char p0[12]; void *vt; char p16[128]; M m[9]; float f[8]; M a, b; short w, h; int n; } O;
extern char D_0043E4D0[], D_0043E520[];
void func_00180B28(O *);
void func_001809B8(M *, int, int);
void func_00180A20(M *, float, float, float);
void func_00180A38(M *, float, float, float);
void func_00180A50(M *, float);
// MATCH func_00180C58
O *screfct_00180c58(O *o)
{
    M *p0 = p0, *p1 = p1, *p2 = p2, *p3 = p3, *p4 = p4, *p5 = p5, *p6 = p6, *p7 = p7, *p8 = p8, *pa = pa, *pb = &o->b;
    func_00180B28(o);
    p0 = &o->m[0]; p1 = &o->m[1]; p2 = &o->m[2]; p3 = &o->m[3]; p4 = &o->m[4]; p5 = &o->m[5]; p6 = &o->m[6]; p7 = &o->m[7]; p8 = &o->m[8]; pa = &o->a; pb = &o->b;
    o->vt = D_0043E4D0;
    p0->vt = D_0043E520;
    p1->vt = D_0043E520;
    p2->vt = D_0043E520;
    p3->vt = D_0043E520;
    p4->vt = D_0043E520;
    p5->vt = D_0043E520;
    p6->vt = D_0043E520;
    p7->vt = D_0043E520;
    p8->vt = D_0043E520;
    pa->vt = D_0043E520;
    pb->vt = D_0043E520;
    o->w = 320;
    o->h = 112;
    o->n = 2;
    func_001809B8(pa, 0, 120); func_00180A20(pa, 20.0f, 0.0f, 255.0f); func_00180A38(pa, 0.0f, -255.0f, 255.0f); func_00180A50(pa, 0.0f);
    func_001809B8(pb, 0, 120); func_00180A20(pb, 16.0f, 0.0f, 255.0f); func_00180A38(pb, 0.0f, -255.0f, 255.0f); func_00180A50(pb, 0.0f);
    func_001809B8(p0, 0, 120); func_00180A20(p0, 8.0f, -360.0f, 360.0f); func_00180A38(p0, 0.0f, -360.0f, 360.0f); func_00180A50(p0, 0.0f);
    func_001809B8(p1, 0, 120); func_00180A20(p1, 0.0f, -1000.0f, 1000.0f); func_00180A38(p1, 1.0f, -1000.0f, 1000.0f); func_00180A50(p1, 0.0f);
    func_001809B8(p2, 0, 120); func_00180A20(p2, 640.0f, -1000.0f, 1000.0f); func_00180A38(p2, -1.0f, -1000.0f, 1000.0f); func_00180A50(p2, 0.0f);
    func_001809B8(p3, 0, 120); func_00180A20(p3, 0.0f, -1000.0f, 1000.0f); func_00180A38(p3, 1.0f, -1000.0f, 1000.0f); func_00180A50(p3, 0.0f);
    func_001809B8(p4, 0, 120); func_00180A20(p4, 640.0f, -1000.0f, 1000.0f); func_00180A38(p4, -1.0f, -1000.0f, 1000.0f); func_00180A50(p4, 0.0f);
    func_001809B8(p5, 0, 120); func_00180A20(p5, 0.0f, -1000.0f, 1000.0f); func_00180A38(p5, 1.0f, -1000.0f, 1000.0f); func_00180A50(p5, 0.0f);
    func_001809B8(p6, 0, 120); func_00180A20(p6, 0.0f, -1000.0f, 1000.0f); func_00180A38(p6, 1.0f, -1000.0f, 1000.0f); func_00180A50(p6, 0.0f);
    func_001809B8(p7, 0, 120); func_00180A20(p7, 224.0f, -1000.0f, 1000.0f); func_00180A38(p7, -1.0f, -1000.0f, 1000.0f); func_00180A50(p7, 0.0f);
    func_001809B8(p8, 0, 120); func_00180A20(p8, 224.0f, -1000.0f, 1000.0f); func_00180A38(p8, -1.0f, -1000.0f, 1000.0f); func_00180A50(p8, 0.0f);
    o->f[1] = 512.0f;
    o->f[0] = 0.0f;
    o->f[6] = 256.0f;
    o->f[7] = 256.0f;
    o->f[3] = 512.0f;
    o->f[2] = 0.0f;
    o->f[4] = 0.0f;
    o->f[5] = 0.0f;
    return o;
}
