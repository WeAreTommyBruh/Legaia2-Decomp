#include "../common.h"
typedef struct { char p0[32]; float f32, f36, f40; char p44[24]; float f68; } X_20F818;
typedef struct { X_20F818 *x; char p4[492]; unsigned fl; int w500; } P_20F818;
extern int D_004A45E8, D_004A45E4, D_004A4960; extern char **D_004A6F78, **D_004A4668; extern volatile float D_004A045C; extern float D_004A0460; extern char D_0041EF80[], D_00455220[];
P_20F818 *func_0020BBD8(int); float func_0015A9A8(float, char *, float *); int func_002DCE40(char *, char *, ...); int func_0020B858(int, char *);
// MATCH func_0020F818
int pchevent_0020f818(int f) {
  char buf[512]; P_20F818 *p; float k;
  if ((f & 8) && D_004A45E8 >= 0 && (p = func_0020BBD8(D_004A45E8)) != 0) {
    k = D_004A045C;
    if (p->fl & 4) k = 600.0f;
    p->x->f36 = func_0015A9A8(k, D_0041EF80, &p->x->f32);
    func_002DCE40(buf, D_00455220, D_004A4668[p->w500 + 1], (double)p->x->f32, (double)p->x->f36, (double)p->x->f40, (double)(p->x->f68 * 180.0f / D_004A0460), D_004A6F78[D_004A45E8]);
    func_0020B858(D_004A45E4, buf);
    D_004A4960++;
  }
  return 0;
}
