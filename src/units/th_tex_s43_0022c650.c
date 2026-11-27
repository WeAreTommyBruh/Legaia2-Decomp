// cflags: -fno-gcse
#include "../common.h"
typedef struct { int p0[4]; int x, y, z, p28; int bx, by, life; float age; int p48, p52; int color; float ang, scale; int p68[3]; } E;
typedef struct { E e[128]; int p10240[4]; int ox, oy, oz, ou, ov; char p10276[2080]; int mode; int p12360[2]; float fade; int p12372[2]; int n; } T;
extern float D_004A05FC, D_004A0600;
void func_002478A8(void *);
extern char D_00342CD0[];
int func_00235C48(float *, int *, int *, E *, float, float);
float func_0022F3C8(float, float);
void th_tex_0022c350(float, float, T *, long, int, int, int, int, int, int, int, int);
// MATCH func_0022C650
void th_tex_0022c650(T *o)
{
    int i, alpha, a, b, ty, tx, k;
    int pad;
    long col;
    int v[3];
    float d, fx, fy, sc, ang;
    E *e, *p;
    a = 0;
    b = 0;
    func_002478A8(D_00342CD0);
    col = (long)o->n << 37 | 0x20000006a5323140LL;
    for (i = 0; i < 128; i++) {
        e = &o->e[i];
        if (e->life != 0) {
            alpha = (int)((float)e->life * o->fade);
            if (func_00235C48(&d, &pad, v, e, 1000.0f, 1000.0f) > 0) {
                fx = (float)(v[0] / 16 + (tx = e->bx - 1728));
                fy = (float)(v[1] / 16 + (ty = e->by - 1936));
                p = &o->e[(i - 1) & 127];
                sc = d / 1000.0f;
                e->y = (int)fy;
                e->z = v[2];
                e->x = (int)fx;
                e->scale = sc;
                ang = -func_0022F3C8((float)p->x - fx, (float)p->y - fy) - D_004A05FC;
                e->ang = ang;
                switch (o->mode) {
                case 0:
                    a = 0;
                    b = e->color * 32 + 128;
                    break;
                case 1:
                    b = 0;
                    a = e->color << 5;
                    break;
                }
                k = a + 1;
                th_tex_0022c350(sc * D_004A0600, e->ang, o, col, (int)(fx + (float)o->ox), (int)(fy + (float)o->oy), v[2] + o->oz, b + o->ou + 1, o->ov + k, 31, 30, alpha * 2);
            }
        }
        e->age += 0.03125f;
        e->life -= 2;
    }
}
