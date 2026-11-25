#include "../common.h"
typedef struct { char p0[8]; int w8; char p12[16]; int w28; char p32[224]; } E_1AD2D0;
typedef struct { char p0[272]; char a272[44]; char a316[44]; E_1AD2D0 *w360; } W_1AD2D0;
extern char D_004A3BD0[];
W_1AD2D0 *func_001AD458(int); void func_001AD8C0(W_1AD2D0 *, int); void func_001AD8D0(W_1AD2D0 *, int); void func_001AD8E8(W_1AD2D0 *, int); void func_001AD8F0(W_1AD2D0 *, int); void func_001AD900(W_1AD2D0 *, int);
void func_00108B98(char *, float, float, float, float, float); void func_001AF7A0(W_1AD2D0 *, int, int, int, int); void func_001AF570(W_1AD2D0 *, int, int, int, int, int, int);
void func_001AD8D8(W_1AD2D0 *, int); void func_001AF938(W_1AD2D0 *, char *, int, int); void func_001B4B40(W_1AD2D0 *);
// MATCH func_001AD2D0
W_1AD2D0 *nayuwin2_001ad2d0(int t) {
  W_1AD2D0 *w; int i, y;
  w = func_001AD458(16);
  if (w == 0) return 0;
  func_001AD8C0(w, 10);
  func_001AD8D0(w, 2);
  func_001AD8E8(w, t);
  func_001AD8F0(w, t);
  func_001AD900(w, 5);
  func_00108B98(w->a272, 0.0f, 64.0f, 10.0f, 0.5f, 0.0f);
  func_001AF7A0(w, 56, 96, 40, 56);
  func_001AF570(w, 32, 32, 0, 240, 64, 128);
  func_00108B98(w->a316, 104.0f, 104.0f, 0.0f, 0.0f, 0.0f);
  func_001AD8D8(w, 0x787878);
  for (i = 0; i < 16; i++) {
    w->w360[i].w8 = i * 13 + 8;
    w->w360[i].w28 = 0x707070;
    func_001AF938(w, D_004A3BD0, i, 0);
  }
  func_001B4B40(w);
  return w;
}
