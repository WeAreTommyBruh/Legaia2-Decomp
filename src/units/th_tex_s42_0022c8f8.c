#include "../common.h"
typedef struct { char p[12340]; int a, b, c; } T;
float func_0015FB58(float, int);
void func_00247A40(int, int, int, long);
void func_00247B40(int, int);
void func_00247FB0(int, int, int);
// MATCH func_0022C8F8
void th_tex_0022c8f8(float s, float ang, T *o, long col, int x, int y, int z, int u, int v, long alpha)
{
    float a, b;
    int i5, i6, i7, i8, t, k;
    a = s * 64.0f;
    a = a * 0.5f;
    b = s * 32.0f * 0.5f;
    i5 = (int)(a * func_0015FB58(ang, 1) - b * func_0015FB58(ang, 0));
    i6 = (int)((b * func_0015FB58(ang, 1) + a * func_0015FB58(ang, 0)) * 0.5f);
    i7 = (int)(a * func_0015FB58(ang, 1) - (-(s * 32.0f) * 0.5f) * func_0015FB58(ang, 0));
    i8 = (int)(((-(s * 32.0f) * 0.5f) * func_0015FB58(ang, 1) + a * func_0015FB58(ang, 0)) * 0.5f);
    x -= (int)((float)(-i5 - i7) * 0.45f);
    y -= (int)((float)(-i6 - i8) * 0.45f);
    func_00247A40(o->a, o->b, o->c, alpha);
    func_00247B40(u << 4, v << 4);
    { int t = i7 + 0x6c0; int k = i8 + 0x790; func_00247FB0((x + t) * 16, (y + k) * 16, z); }
    func_00247B40(u << 4, (v + 30) * 16);
    { int t = i7 - 0x6c0; int k = i8 - 0x790; func_00247FB0((x - t) * 16, (y - k) * 16, z); }
}
