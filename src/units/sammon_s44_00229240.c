// compiler: 990721-r5900
#include "../common.h"
typedef struct { float x, y, z, w; } V4_9240;
typedef struct { V4_9240 p; char q[208 - 16]; float f208; } C_9240;
extern C_9240 D_0041EFB0; extern char D_00343010[]; extern float D_004A05AC;
void *func_002DC804(void *, int, int); int func_001E43D0(void *, V4_9240 *); int func_001E4568(void *, V4_9240 *); void func_00153F30(float, float, float, C_9240 *); void func_00153D80(float, float, float, C_9240 *);
void func_001544B8(C_9240 *, char *); void func_0018EC58(int); void func_0018F3D8(int, char *, int); void func_0018EB98(int, int); void func_0010FF28(int);
// MATCH func_00229240
int sammon_00229240(void) { V4_9240 a, b; char buf[64]; int r1, r2;
  func_002DC804(&a, 0, 16); func_002DC804(&b, 0, 16);
  r1 = func_001E43D0(D_00343010, &a);
  if (r1) { D_0041EFB0.p.x = a.x; D_0041EFB0.p.y = a.y; D_0041EFB0.p.z = a.z; D_0041EFB0.p.w = 1.0f; }
  r2 = func_001E4568(D_00343010, &b);
  if (r2) func_00153F30(b.x, b.y, b.z, &D_0041EFB0);
  if (!r1 && !r2) return 0;
  func_00153D80(0, -1.0f, 0, &D_0041EFB0);
  D_0041EFB0.f208 = D_004A05AC;
  func_001544B8(&D_0041EFB0, buf);
  func_0018EC58(0x70003f80);
  func_0018F3D8(0x70003f80, buf, 0x70003f80);
  func_0018EB98(0x70003c00, 0x70003f80);
  func_0010FF28(1024);
  return 1; }
