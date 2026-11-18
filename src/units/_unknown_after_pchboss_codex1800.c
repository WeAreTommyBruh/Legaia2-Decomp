/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern volatile float D_004A04A8_00219240 __asm__("D_004A04A8"), D_004A04AC_00219240 __asm__("D_004A04AC"), D_004A04B0_00219240 __asm__("D_004A04B0"); float func_002D5738_00219240(float, float) __asm__("func_002D5738");
// MATCH func_00219240
float FUN_00219240(float a, float b) {
  float k, r1, r2, d, r, ab;
  ab = __builtin_fabsf(b); k = (6.2831854820251465f); r1 = func_002D5738_00219240(ab, k);
  if (b < 0.0f) r1 = k - r1;
  r2 = func_002D5738_00219240(__builtin_fabsf(a), k);
  if (a < 0.0f) r2 = k - r2;
  d = r2 - r1;
  if (d < 0.0f) d = d + k;
  if ((3.1415927410125732f) < d) r = k - d; else { r = (-3.1415927410125732f); if (d < r) r = d + k; }
  return r;
}

typedef struct { char p0[32]; char m32[96]; float f128; char p132[4]; float f136; } U_21A008;
extern U_21A008 *D_003279A0[]; extern float D_004A04C4;
float func_00126930(void); float func_0022F5A0(float, float); float func_00219FB8(int, int); float func_0015FB58(float, int);
void func_0018F080(float *, char *, float *); void func_0018F020(char *, float *, float *);
// MATCH func_0021A008
void FUN_0021a008(int a, int b) {
  float m[4]; float d, t, ang;
  U_21A008 **p, **q;
  d = func_00126930();
  q = &D_003279A0[b];
  p = &D_003279A0[a];
  d = d * D_004A04C4;
  t = func_0022F5A0((*q)->f128 - (*p)->f128, (*q)->f136 - (*p)->f136);
  ang = func_00219FB8(a, b);
  if (t < d) {
    func_0018F080(m, (*q)->m32, &(*q)->f128);
    (*q)->f128 = (*p)->f128 - func_0015FB58(ang, 0) * d;
    (*q)->f136 = (*p)->f136 - func_0015FB58(ang, 1) * d;
    func_0018F020((*q)->m32, &(*q)->f128, m);
  }
}

typedef struct { char p0[32]; char m32[36]; float f68; char p72[56]; float f128; char p132[4]; float f136; char p140[32]; short h172; } U_21A130;
extern U_21A130 *D_003279A0_21A130[] __asm__("D_003279A0"); extern float D_003C7FA8[];
float func_0022F5A0(float, float); float func_0015FB58(float, int);
void func_0018F080(float *, char *, float *); void func_0018F020(char *, float *, float *);
// MATCH func_0021A130
void FUN_0021a130(unsigned i) {
  float m[4]; float lim, ang; U_21A130 **p;
  if (i >= 5) i = 0;
  p = &D_003279A0_21A130[i];
  if ((*p)->h172 == 1) return;
  ang = (*p)->f68;
  lim = D_003C7FA8[i];
  if (func_0022F5A0((*p)->f128, (*p)->f136) < lim) {
    func_0018F080(m, (*p)->m32, &(*p)->f128);
    (*p)->f128 = func_0015FB58(ang, 0) * lim;
    (*p)->f136 = func_0015FB58(ang, 1) * lim;
    func_0018F020((*p)->m32, &(*p)->f128, m);
  }
  lim = 2000.0f;
  if (lim < func_0022F5A0((*p)->f128, (*p)->f136)) {
    func_0018F080(m, (*p)->m32, &(*p)->f128);
    (*p)->f128 = func_0015FB58(ang, 0) * lim;
    (*p)->f136 = func_0015FB58(ang, 1) * lim;
    func_0018F020((*p)->m32, &(*p)->f128, m);
  }
}
