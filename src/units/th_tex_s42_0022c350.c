#include "../common.h"
typedef struct { char p[12340]; int a, b, c; } T;
float func_0015FB58(float, int);
void func_00247970(int);
void func_00247A48(int, long);
void func_00247A40(int, int, int, int);
void func_00247B40(int, int);
void func_00247FB0(int, int, int);
void func_002479F0(void);
// MATCH func_0022C350
void th_tex_0022c350(float s, float ang, T *o, long col, int x, int y, int z, int u, int v, int w, int h, int alpha)
{
    float a, b, c;
    int i5, i6, i7, i8, u1, v1, t, k;
    a = (float)w * s;
    a = a * 0.5f;
    c = (float)h * s;
    b = c * 0.5f;
    c = -c;
    c = c * 0.5f;
    i5 = (int)(a * func_0015FB58(ang, 1) - b * func_0015FB58(ang, 0));
    i6 = (int)((b * func_0015FB58(ang, 1) + a * func_0015FB58(ang, 0)) * 0.5f);
    i7 = (int)(a * func_0015FB58(ang, 1) - c * func_0015FB58(ang, 0));
    i8 = (int)((c * func_0015FB58(ang, 1) + a * func_0015FB58(ang, 0)) * 0.5f);
    x -= (int)((float)(-i5 - i7) * 0.45f);
    y -= (int)((float)(-i6 - i8) * 0.45f);
    func_00247970(4);
    func_00247A48(6, col);
    func_00247A40(o->a, o->b, o->c, alpha);
    func_00247B40(u << 4, v << 4);
    { int t = i5 - 0x6c0; int k = i6 - 0x790; func_00247FB0((x - t) * 16, (y - k) * 16, z); }
    u1 = (u + w) * 16;
    func_00247B40(u1, v << 4);
    { int t = i7 + 0x6c0; int k = i8 + 0x790; func_00247FB0((x + t) * 16, (y + k) * 16, z); }
    v1 = (v + h) * 16;
    func_00247B40(u << 4, v1);
    { int t = i7 - 0x6c0; int k = i8 - 0x790; func_00247FB0((x - t) * 16, (y - k) * 16, z); }
    func_00247B40(u1, v1);
    { int t = i5 + 0x6c0; int k = i6 + 0x790; func_00247FB0((x + t) * 16, (y + k) * 16, z); }
    func_002479F0();
}
