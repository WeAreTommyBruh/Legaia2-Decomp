#include "../common.h"
extern int D_004A13E8;
void func_002478D0(int); void func_00247970(int); void func_002479F0(void); void func_00247A48(int, int);
void func_00247B40(int, int); void func_00247EF8(int, int); void func_00247A40(int, int, int, int);
// MATCH func_00232618
void FUN_00232618(int a, int x, int y, int w, int h, int u, int v, int uw, int vh, int col)
{
  int x0, y0, x1, y1, u0, v0, u1, v1;
  func_002478D0(0x10);
  func_002478D0(0x100);
  D_004A13E8 = -2;
  func_00247970(4);
  func_00247A48(6, a);
  func_00247A40(0x80, 0x80, 0x80, col);
  v0 = v * 16 + 8;
  func_00247B40(u << 4, v0);
  x0 = (x + 0x6c0) * 16;
  y0 = (y + 0x790) * 16;
  func_00247EF8(x0, y0);
  u1 = (u + uw) * 16;
  func_00247B40(u1, v0);
  { int t = w + 0x6c0; x1 = (x + t) * 16; }
  func_00247EF8(x1, y0);
  v1 = (v + vh) * 16 + 8;
  func_00247B40(u << 4, v1);
  { int t2 = h / 2 + 0x790; y1 = (y + t2) * 16; }
  func_00247EF8(x0, y1);
  func_00247B40(u1, v1);
  func_00247EF8(x1, y1);
  func_002479F0();
  D_004A13E8 = -1;
}
