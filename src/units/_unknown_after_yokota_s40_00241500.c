#include "../common.h"
typedef struct { char p0[2308]; int w2308; } X_241500;
typedef struct { char p0[24]; unsigned w24; char p28[4]; int w32, w36, w40; char p44[100]; X_241500 *w144; char p148[24]; short h172; char p174[14]; short h188; } W_241500;
typedef struct { char p0[20]; float f20; char p24[28]; float f52; } F_241500;
extern int D_004A71A8; extern char D_004A5558[], D_0045CF40[], D_003D6B60[]; extern int D_002F9804[]; extern unsigned short D_0603AAA0[]; extern char D_0603AD80[]; extern F_241500 D_0603AB00[];
volatile char func_001118F8(char *, ...); W_241500 *func_00246D88(char *, int); void func_00246188(W_241500 *, unsigned short *, int, int);
void func_00245EA0(W_241500 *); void func_00245E58(W_241500 *); void func_0023FE68(W_241500 *, int); int func_00246A80(W_241500 *, char *);
// MATCH func_00241500
void FUN_00241500(void) {
  W_241500 *w; float f;
  if (D_004A71A8 != 0) return;
  func_001118F8(D_004A5558);
  w = func_00246D88(D_003D6B60, D_002F9804[0]);
  { register X_241500 *x __asm__("$3") = w->w144; x->w2308 = 1; }
  w->w32 = 0;
  w->w36 = 0;
  w->w40 = 0;
  w->h172 = D_0603AAA0[0];
  w->w24 |= 0x100;
  w->h188 = 0;
  func_00246188(w, D_0603AAA0, 0, 0);
  func_00245EA0(w);
  func_00245E58(w);
  func_001118F8(D_0045CF40);
  func_0023FE68(w, 0);
  D_004A71A8 = (int)w;
  f = func_00246A80(w, D_0603AD80) - 1;
  D_0603AB00[0].f20 = f;
  D_0603AB00[0].f52 = f;
}
