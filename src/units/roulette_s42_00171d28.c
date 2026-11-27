#include "../common.h"
typedef struct { char p0[16]; long *q, *r, *u; } Pk;
extern Pk D_00314C20;
typedef struct { char p[12]; } T12;
extern T12 D_00335118[];
typedef struct { char p[64]; short adj; short pad; void (*fn)(void *); } VT;
typedef struct { char p0[16]; int r; int p20; unsigned fl; char sub[8]; int i36; char p40[20]; VT *vt; } O;
void func_0024BC98(int, int, int, int, Pk *);
void func_00190328(Pk *); void func_00190420(Pk *);
float func_0015FB58(float, int);
void func_00163780(int, int, T12 *);
void func_00164668(void *);
void func_0012CF78(void);
// MATCH func_00171D28
void roulette_00171d28(O *o)
{
    long *q, *r, *u;
    int k;
    func_0024BC98(o->i36, 0x3140, 0x3c00, 0, &D_00314C20);
    func_00190328(&D_00314C20);
    q = D_00314C20.q;
    D_00314C20.q = q + 6;
    q[0] = 0x44;
    q[1] = 0x42;
    q[2] = 0x3f80000080808080L;
    q[3] = 1;
    q[4] = 0x156;
    q[5] = 0;
    o->vt->fn((char *)o + o->vt->adj);
    r = D_00314C20.q;
    r[0] = 0x3f80000080808080L;
    r[1] = 1;
    D_00314C20.q = r + 4;
    k = 4;
    if (o->fl & 4) k = 3;
    r[2] = 0x156;
    r[3] = 0;
    func_00163780((int)(func_0015FB58(0.0f, 1) * (float)o->r) + 320, (int)(func_0015FB58(0.0f, 0) * (float)o->r * 224.0f / 480.0f) + 100, &D_00335118[k]);
    u = D_00314C20.q;
    u[0] = 0x44;
    u[1] = 0x42;
    D_00314C20.q = u + 2;
    func_00190420(&D_00314C20);
    func_00164668((char *)o + 28);
    func_0012CF78();
}
